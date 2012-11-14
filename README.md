IRCaD
=====

IRCaD (IRC and Dragons) - An IRC based Dungeons and Dragons robot.

In this project, I am collaborating closely with my girlfriend who is an avid DnD player to bring together my experience in programming with her experience in the game.

The idea is to make the robot as self-sufficient as possible, giving it the ability to generate its own maps, or to accept maps from others; to generate items randomly; to be completely configurable with NPC speech options.

This is likely to be a long project, so please show patience!

Entities in the Game section
============================

* Visible
  * Map
    * Terrain {x, y, type, players, items, npcs, mobs}
      * Paths {N, S, E, W}
      * Description
  * Character
    * Name (Must not be in Names list)
    * Type {type} (e.g. Player, NPC, Mob, Rare)
    * Level
    * Health
    * Mana (Remains at 0 for non-magic classes)
    * Species {type} (e.g. Elf, Half-Giant, Dwarf...)
    * Class {type} (e.g. Rogue, Wizard, Warrior...)
    * Attributes {Strength, Constitution, Dexterity, Intelligence, Wisdom, Charisma}
    * Location {x, y}
    * Inventory
    * Friends
    * Foes
    * Buffs
    * Item
    * Name
    * Type (e.g. dagger, sword, stick}
    * Attributes
    * Level
    * In Possession {=false|name}
    * Buffs
    * Description
    * Location {x, y}
* GameEngine
  * Init
  * Database
    * Account
    * Username
	  * Encrypted Password
    * Names {->[Character]}
	* Items
  * Turn Manager
  * Buff Manager
  * Spawn Manager
  * Database Manager
    * Authentication Unit
  * Configuration
  * WebInterfaceModule