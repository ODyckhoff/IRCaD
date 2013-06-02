#!/usr/bin/perl
use strict;
use warnings;

my $class = shift || 'IRCaD';
my $debugMode = shift || 0;

my @params = @ARGV;
print join( ', ', @params ) . "\n";

( my $requirement = $class . '.pm' ) =~ s{::}{/}g;
require $requirement;

my $debug = $class . '::debug';
my $debugref = \$debug; 
   $$debugref = 1 if $debugMode;

# print "$class\n";
# print ${ $class . '::debug' } . "\n";

# $class =~ s/.*::([^:]+)(::)?$/$1/;

my $object = $class->new ( @params );
$object->initEngine;
