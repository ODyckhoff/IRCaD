![IRCaD Logo](http://sconesorscones.co.uk/dev/IRCaD/IRCaD.png)

IRCaD
=====

IRCaD (IRC and Dragons) - An IRC based Dungeons and Dragons robot, written in C.

In this project, I am collaborating closely with my girlfriend who is an avid DnD player to bring together my experience in programming with her experience in the game.

The idea is to make the robot as self-sufficient as possible, giving it the ability to generate its own maps, or to accept maps from others; to generate items randomly; to be completely configurable with NPC speech options, and so on and so forth.

This is likely to be a long project, so please show patience!

Detailed design of game mechanics is yet to be completed, although a general structure for the game components has been put in place.

Software Cycles
===============

IRCaD is currently in initial development pre-alpha. When a basic, functional platform is complete upon which a game could reasonably be played, it will be labelled as Alpha and version numbering will start from 0.1. Updates to the code will be incremented as x.y.z+1, feature additions/overhauls will be incremented as x.y+1.z, and significant changes to inner workings and computational methods will be incremented as x+1.y.z.

Why C?
======

Well, why not? I chose C for its speed, robustness, and efficiency. Yes, it can be an arse to debug, but when I'm considering potential for many players to be playing possibly more than one game at once on a single application, non-blocking code and multi-threading needs to be as fast as I can get it, and C gives me the low level control that I need to ensure that memory is handled exactly the way I want it handled.

Also the application was originally being written in Perl, so consider yourselves lucky.

Downloading/Running IRCaD
=========================

I wouldn't recommend this just yet, mainly because there's not an awful lot of substance to the codebase, but if you fancy running it, you're going to have to compile it the hard way as I've not yet created a Makefile.

This is partially because I can't be arsed and partially because I'm currently just developing, testing and debugging small components of the game, and haven't yet needed to be able to compile huge sections of the application all at once.

I intend to have a set of Makefiles available, for compiling and testing smaller components, and then the big daddy Makefile that compiles the whole lot. This latter file probably won't exist until at least after pre-alpha.

Currently, one may run the maptests by using `cd` to navigate to `game/environment/map`, and then running `gcc -o maptest map.c tile.c`, followed by `./maptest`. All it will do is spew out some numbers and show you some partially/fully generated maps, but hey, that's pretty, right?

Design
======

As mentioned previously, the design hasn't yet entered a detailed phase, but you can see an overview of the components and how they'll interact here:

![IRCaD Design Diagram](http://sconesorscones.co.uk/dev/IRCaD/IRCaD_Basic_Design.png)
