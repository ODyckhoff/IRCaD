#!/usr/bin/perl

package IRCaD::Game::Dice;
# Subroutines associated with di(c)e rolling.

use strict;   # Because I'm a good boy.
use warnings; # Because uninitialised values are a bloody pain.

use IRCaD::Log;

BEGIN {
    require Exporter;

    our $VERSION = 1.00;
    our @ISA = qw(Exporter);
    our @EXPORT = qw(roll);
}

roll(@ARGV);

sub roll {
    # Rolls the requested dice a specified number of times and returns list of values.
    # Format: (N)dT - N = Number of rolls. Optional if single roll.
    #                 T = Type of die to be rolled. (e.g. d20)

    my ($die) = @_;
    if ($die =~ /(\d+)?d(\d+)/) {
        # Congratulations, we have ourselves a correctly formatted dice query!
        my $number = $1 ? $1 : 1; # If there's a number, use it, otherwise use 1.
        if($2) {
            return join(", ", map { int(rand($2) + 1); } (1 .. $number));
        }
        else {
            error( "no die given." );
            return;
        }
    }
    else {
        # Invalid dice query.
        error( "Not a valid query" );
    }
}

1;
