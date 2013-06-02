#!/usr/bin/perl

package MaDAME::Tools::ClassTester;

use strict;
use warnings;

use Cwd 'abs_path';
my $path = abs_path( $0 ) . "\n";
chomp($path);
$path =~ s{lib/.*}{lib};

push ( @INC, $path );

my $class = shift || 'MaDAME';
my $methodWant = shift || 'init';
my $debugMode = shift || 0;

my @params = @ARGV;
# print join( ', ', @params ) . "\n";

( my $requirement = $path . '/' . $class . '.pm' ) =~ s{::}{/}g;
require $requirement;

my $debugref = $class . '::debug';
my $debug = \$debugref;
   $$debug = 1 if $debugMode;

#my $object = $class->new ( @params );
#$object->$methodWant;

# perl Tools/ClassTester.pl MaDAME::Engine::MusDat::CalcHandler::Chord
