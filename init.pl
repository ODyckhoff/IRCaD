#!/usr/bin/perl

 use strict;
 use warnings;
 use POE qw(Component::IRC);

 my $nickname = 'DM'; #. $$;
 my $username = 'DM';
 my $ircname  = 'The Dungeon Master of #DnD';
 my $server   = 'irc.aberwiki.org';

 my @channels = ('#DnD', '#DnDev');

 # We create a new PoCo-IRC object
 my $irc = POE::Component::IRC->spawn(
    nick => $nickname,
    username => $username,
    ircname => $ircname,
    server  => $server,
 ) or die "Oh noooo! $!";

 POE::Session->create(
     package_states => [
         main => [ qw(_default _start irc_001 irc_public) ],
     ],
     heap => { irc => $irc },
 );

 $poe_kernel->run();

 sub _start {
     my $heap = $_[HEAP];

     # retrieve our component's object from the heap where we stashed it
     my $irc = $heap->{irc};

     $irc->yield( register => 'all' );
     $irc->yield( connect => { } );
     return;
 }

 sub irc_001 {
     my $sender = $_[SENDER];

     # Since this is an irc_* event, we can get the component's object by
     # accessing the heap of the sender. Then we register and connect to the
     # specified server.
     my $irc = $sender->get_heap();

     print "Connected to ", $irc->server_name(), "\n";

     # we join our channels
     $irc->yield( join => $_ ) for @channels;
     return;
 }

 sub irc_public {
     my ($sender, $who, $where, $what) = @_[SENDER, ARG0 .. ARG2];
     my $nick = ( split /!/, $who )[0];
     my $channel = $where->[0];
     if($what =~ /^$nickname: (hallo|hi|sup|hello|hey)/) {
         $irc->yield(privmsg => $channel => $nick . ": hi");
     }
     
     if($what =~ /^&(\d+)?[dD]\d+/) {
         use Game::Dice;
         roll($irc, $channel, $nick, $what);
     }
     return;
 }

 # We registered for all events, this will produce some debug info.
 sub _default {
     my ($event, $args) = @_[ARG0 .. $#_];
     my @output = ( "$event: " );

     for my $arg (@$args) {
         if ( ref $arg eq 'ARRAY' ) {
             push( @output, '[' . join(', ', @$arg ) . ']' );
         }
         else {
             push ( @output, "'$arg'" );
         }
     }
     print join ' ', @output, "\n";
     return;
 }
