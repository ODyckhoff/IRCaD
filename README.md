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
        * Terrain {x, y, z, type, items, players, npcs, mobs}
        * Paths {N, S, E, W, U, D}
        * Description (Inputted by dm)
    * Mobs
        * Player Characters
            * Location {x, y, z}
            * Type {type} always humanoid
      	    * Species {type} (e.g. Elf, Dwarf, Hoomin...)
      	    * Gender {gender}
      	    * Class {type} (e.g. Witch/Wizard, Warrior, Rogue...)
      	    * Attributes {strength, dexterity, constitution, intelligence, wisdom, charisma}
      	    * Level
      	    * Modifiers {modifiers} (double dex, +critical%...)
      	    * Health, Mana
      	    * Moves
      	    * Name
      	    * Inventory {items}
      	    * Friends, Foes
      * NPCs
            * Location {x, y, z}
      	    * Type {type} always humanoid
      	    * Species {type} (e.g. Elf, Dwarf, Hoomin...)
      	    * Gender {gender}
      	    * Name
      	    * NPC Type {npc, shop, quest}
      	    * Items allowed
      	    * Items (shop type buy and sell items, quest allows the creation of a dialogue screen)
      	    * Level
      	    * Modifiers
      	    * Health, Mana
      	    * Moves
      	    * Friends, Foes
     	* AngryMobs
        	* Location {x, y, z}
        	* Type {type} (e.g. humanoid, beast, flying, giantflying, giant, small)
        	* Species {type} (e.g. in small: fairy, vole, bat, rat...)
        	* Level (random, between 2 set values per species)
        	* Items alllowed {item}
        	* Modifiers {modifiers} (defence bonus, flanking...)
        	* Health, Mana
        	* Moves
        	* Friends, Foes
  * Items
	* Wearable {type}
		* Place {type} (e.g. Head, Body, Shield...)
		* Rarity/Material {item} (value between 1 and 10, dictates number of enchantments)
		* Enchantments {item} (from a table, rarity increases higher number stat boosts)
		* Size, weight
		* Name ((If rarity=10 use name table, otherwise "size material place enchantments") e.g. large velvet hat of dreams)
	* Potion 
		* Effect
		* Size, weight
		* Name ((size effect potion) e.g. small healing potion)
	* Other
		* Size, weight
		* Name
	
  * Quests
  	* TBA

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
