#!/usr/bin/perl

package IRCaD::Log;

# Declare base pragmas
use strict;
use warnings;

# Declare required IRCaD modules.
use IRCaD::Configuration;

use POSIX qw( strftime );

# Export required variables and subroutines.
use Exporter;
use vars qw( @ISA @EXPORT );
@ISA = qw( Exporter );
@EXPORT = qw( debug error );

sub writelog {
    my $logtype = shift;
    my $logmsg = strftime( $cfg{log}{timestamp}, localtime ) 
               . ' >>> ' . uc($logtype) . ' >>> ' 
               . join( ' - Line ', ( caller(1) )[0, 2] ) 
               . ' - ' . ( my $msg = shift ) . "\n";

    my @filehandles = ();
    push( @filehandles, \*STDOUT ) if $cfg{ $logtype.'_std' } == 0;
    push( @filehandles, \*STDERR ) if $cfg{ $logtype.'_std' } == 1;
    push( @filehandles, ( \*STDOUT, \*STDERR ) ) if $cfg{ $logtype.'_std' } == 2;

    # my ( $day, $month, $year ) = ( localtime( time ) )[3 .. 5];

    if( $cfg{ $logtype.'_logs' } ) {
        open( my $fh, '>>', $cfg{log}{logdir} . '/' 
            . ( $cfg{log}{sepdirs} ? $logtype.'/' : '' ) 
            . strftime( $cfg{log}{nameformat}, localtime )
            . ( $cfg{log}{extswitch} ? '.'.$logtype : '' )
        ) || die( $! );
        push( @filehandles, $fh );
    }
    
    foreach my $handle ( @filehandles ) {
        print $handle $logmsg;
    }

    foreach my $open ( @filehandles ) {
        close( $open ) unless *{ $open } =~ /\*main::STD.*/;
    }
}

sub debug {
    return unless $cfg{debug_mode};
    my $logtype = 'debug';
    unshift ( @_, $logtype );
    writelog( @_ );
}

sub error {
    return unless $cfg{error_mode};
    my $logtype = 'error';
    unshift ( @_, $logtype );
    writelog( @_ );
}
1;
