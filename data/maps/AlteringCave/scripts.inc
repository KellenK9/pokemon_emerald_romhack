AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AlteringCave_EventScript_Brock::
	trainerbattle_single TRAINER_BROCK, AlteringCave_Text_BrockIntro, AlteringCave_Text_BrockDefeated
	msgbox AlteringCave_Text_BrockPostBattle, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM52
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox AlteringCave_Text_BrockExplainSteelixite, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_STEELIXITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

AlteringCave_Text_BrockPostBattle:
	.string "Here's the TM for my favorite rock\n"
	.string "type move.$"

AlteringCave_Text_BrockExplainSteelixite:
	.string "And this is an item I found\n"
	.string "here in Hoenn.\p"
	.string "It could help you out\n"
	.string "in the future.$"
