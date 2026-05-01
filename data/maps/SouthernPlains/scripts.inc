SouthernPlains_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernPlains_OnTransition
	.byte 0

SouthernPlains_OnTransition::
	goto_if_set FLAG_BIRCH_INTRO_COMPLETE, SouthernPlains_EventScript_BirchIntroComplete
	SouthernPlains_EventScript_Birch
	end

SouthernPlains_EventScript_BirchIntroComplete::
	end

SouthernPlains_EventScript_Birch::
	lockall
	applymovement LOCALID_BIRCH, SouthernPlains_Movement_BirchWalkRight
	waitmovement 0
	applymovement LOCALID_BIRCH, SouthernPlains_Movement_BirchFaceUp
	waitmovement 0
	delay 30
	
	msgbox SouthernPlains_Text_BirchIntroduction, MSGBOX_DEFAULT
	
	msgbox SouthernPlains_Text_BirchPokedex, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKEDEX_GET
	
	msgbox SouthernPlains_Text_BirchFoundationKit, MSGBOX_DEFAULT
	
	checkitemspace ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, FALSE, SouthernPlains_EventScript_NeedSpaceForItems
	additem ITEM_TOWN_MAP
	
	giveitem ITEM_POKE_BALL, 50
	goto_if_eq VAR_RESULT, FALSE, SouthernPlains_EventScript_NeedSpaceForItems
	
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox SouthernPlains_Text_BirchHereIsEevee, MSGBOX_DEFAULT
	givemon SPECIES_EEVEE, 10
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SouthernPlains_EventScript_EeveeToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SouthernPlains_EventScript_EeveeToPc
	goto SouthernPlains_EventScript_NeedSpaceForItems
	
SouthernPlains_EventScript_EeveeToParty::
	msgbox SouthernPlains_Text_BirchEeveeJoinedParty, MSGBOX_DEFAULT
	goto SouthernPlains_EventScript_ContinueAfterEevee
	
SouthernPlains_EventScript_EeveeToPc::
	msgbox SouthernPlains_Text_BirchEeveeToPC, MSGBOX_DEFAULT
	goto SouthernPlains_EventScript_ContinueAfterEevee
	
SouthernPlains_EventScript_ContinueAfterEevee::
	msgbox SouthernPlains_Text_BirchWishesLuck, MSGBOX_DEFAULT
	msgbox SouthernPlains_Text_BirchHealing, MSGBOX_DEFAULT
	
	applymovement LOCALID_BIRCH, SouthernPlains_Movement_BirchFaceLeft
	waitmovement 0
	applymovement LOCALID_BIRCH, SouthernPlains_Movement_BirchWalkLeft
	waitmovement 0
	applymovement LOCALID_BIRCH, SouthernPlains_Movement_BirchFaceDown
	waitmovement 0
	
	setflag FLAG_BIRCH_INTRO_COMPLETE
	releaseall
	end

SouthernPlains_EventScript_NeedSpaceForItems::
	msgbox SouthernPlains_Text_BirchInventoryFull, MSGBOX_DEFAULT
	releaseall
	end

SouthernPlains_Movement_BirchWalkRight:
	walk_right
	walk_right
	walk_right
	step_end

SouthernPlains_Movement_BirchFaceUp:
	face_up
	step_end

SouthernPlains_Movement_BirchFaceLeft:
	face_left
	step_end

SouthernPlains_Movement_BirchWalkLeft:
	walk_left
	walk_left
	walk_left
	step_end

SouthernPlains_Movement_BirchFaceDown:
	face_down
	step_end

SouthernPlains_Text_BirchIntroduction::
	.string "Welcome to Ark 42!\p"
	.string "I'm Professor Birch, and I'll be\n"
	.string "guiding your expedition throughout\l"
	.string "this vast region.\p"
	.string "As you explore, you must catch\n"
	.string "different species of wild POKéMON.\p"
	.string "This will be crucial to understanding\n"
	.string "the diverse ecosystem around us.$"

SouthernPlains_Text_BirchPokedex::
	.string "Here, take this POKéDEX!\p"
	.string "With it, you can record data on all\n"
	.string "the POKéMON you encounter and catch.$"

SouthernPlains_Text_BirchFoundationKit::
	.string "I've also prepared some items from\n"
	.string "the Foundation's exploration kit\l"
	.string "to help you on your journey.$"

SouthernPlains_Text_BirchHereIsEevee::
	.string "This {STR_VAR_1} will be your\n"
	.string "partner on your expedition.\p"
	.string "Take good care of it!$"

SouthernPlains_Text_BirchEeveeJoinedParty::
	.string "{STR_VAR_1} joined your party!$"

SouthernPlains_Text_BirchEeveeToPC::
	.string "{STR_VAR_1} was sent to\n"
	.string "the PC!$"

SouthernPlains_Text_BirchWishesLuck::
	.string "I wish you the best of luck out\n"
	.string "there!\p"
	.string "Remember, every species you catch\n"
	.string "brings us closer to understanding\l"
	.string "this world's wonders.$"

SouthernPlains_Text_BirchHealing::
	.string "Oh, and one more thing—whenever you\n"
	.string "need to heal your POKéMON, just\l"
	.string "come find me.\p"
	.string "I'll take good care of them and\n"
	.string "have them back in top form!$"

SouthernPlains_Text_BirchInventoryFull::
	.string "It looks like your bag is too full\n"
	.string "to carry all these items.\p"
	.string "Come back when you have space.$"
