#!/usr/bin/perl

package IRCaD::Configuration;

# Declare base pragmas.
use strict;
use warnings;

# use IRCaD::Log;

# Export required variables and/or subroutines.
use Exporter;
use vars qw( @ISA @EXPORT );
@ISA = qw( Exporter );
@EXPORT = qw( %cfg );

our %cfg;

# Get the absolute path of the script to look for.
use Cwd 'abs_path';
my $path = abs_path($0);
chomp $path;
#print "$path\n";

# Trim the path to leave only the location of the root directory of the IRCaD application.
# ( Too much guessing? )
$path =~ s{(?<!IRCaD)(.+?)IRCaD.*}{$1IRCaD};

my $directory = $path . '/config/';
opendir (my $dirhandle, $directory) or die $!;

while (my $file = readdir($dirhandle)) {
    next if ( $file =~ /^\.\.?$/ );
    #print "$file\n";
    if(do $directory . $file) {
    
        # something
    } else {
         print "Error loading configuration: $file\n";
    }
}

closedir($dirhandle);

1;
