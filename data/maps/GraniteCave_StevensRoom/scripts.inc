GraniteCave_StevensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_StevensRoom_OnTransition
	.byte 0

GraniteCave_StevensRoom_OnTransition::
	setflag FLAG_HIDE_ARTICUNO_EMERALD
	setflag FLAG_HIDE_ZAPDOS_EMERALD
	setflag FLAG_HIDE_MOLTRES_EMERALD
	specialvar VAR_RESULT, CheckGorebyss
	goto_if_eq VAR_RESULT, TRUE, GraniteCave_StevensRoom_LureArticuno
	specialvar VAR_RESULT, CheckHuntail
	goto_if_eq VAR_RESULT, TRUE, GraniteCave_StevensRoom_LureMoltres
	specialvar VAR_RESULT, CheckLanturn
	goto_if_eq VAR_RESULT, TRUE, GraniteCave_StevensRoom_LureZapdos
	return

GraniteCave_StevensRoom_HideArticuno::
	setflag FLAG_HIDE_ARTICUNO_EMERALD
	return

GraniteCave_StevensRoom_HideZapdos::
	setflag FLAG_HIDE_ZAPDOS_EMERALD
	return

GraniteCave_StevensRoom_HideMoltres::
	setflag FLAG_HIDE_MOLTRES_EMERALD
	return

GraniteCave_StevensRoom_LureArticuno::
	clearflag FLAG_HIDE_ARTICUNO_EMERALD
	call_if_set FLAG_DEFEATED_ARTICUNO, GraniteCave_StevensRoom_HideArticuno
	call_if_set FLAG_CAUGHT_ARTICUNO, GraniteCave_StevensRoom_HideArticuno
	return

GraniteCave_StevensRoom_LureMoltres::
	clearflag FLAG_HIDE_MOLTRES_EMERALD
	call_if_set FLAG_DEFEATED_MOLTRES, GraniteCave_StevensRoom_HideMoltres
	call_if_set FLAG_CAUGHT_MOLTRES, GraniteCave_StevensRoom_HideMoltres
	return

GraniteCave_StevensRoom_LureZapdos::
	clearflag FLAG_HIDE_ZAPDOS_EMERALD
	call_if_set FLAG_DEFEATED_ZAPDOS, GraniteCave_StevensRoom_HideZapdos
	call_if_set FLAG_CAUGHT_ZAPDOS, GraniteCave_StevensRoom_HideZapdos
	return

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_EventScript_Articuno::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, 45
	special SetArticunoWildMoves
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCave_StevensRoom_EventScript_DefeatedArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GraniteCave_StevensRoom_EventScript_RanFromArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GraniteCave_StevensRoom_EventScript_RanFromArticuno
	setflag FLAG_CAUGHT_ARTICUNO
	release
	end

GraniteCave_StevensRoom_EventScript_Zapdos::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZAPDOS, 45
	special SetZapdosWildMoves
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCave_StevensRoom_EventScript_DefeatedZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GraniteCave_StevensRoom_EventScript_RanFromZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GraniteCave_StevensRoom_EventScript_RanFromZapdos
	setflag FLAG_CAUGHT_ZAPDOS
	release
	end

GraniteCave_StevensRoom_EventScript_Moltres::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 45
	special SetMoltresWildMoves
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, GraniteCave_StevensRoom_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, GraniteCave_StevensRoom_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, GraniteCave_StevensRoom_EventScript_RanFromMoltres
	setflag FLAG_CAUGHT_MOLTRES
	release
	end

GraniteCave_StevensRoom_EventScript_DefeatedArticuno::
	setflag FLAG_DEFEATED_ARTICUNO
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end

GraniteCave_StevensRoom_EventScript_RanFromArticuno::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end

GraniteCave_StevensRoom_EventScript_DefeatedMoltres::
	setflag FLAG_DEFEATED_MOLTRES
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end

GraniteCave_StevensRoom_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end

GraniteCave_StevensRoom_EventScript_DefeatedZapdos::
	setflag FLAG_DEFEATED_ZAPDOS
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

GraniteCave_StevensRoom_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "STEVEN: Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could even\n"
	.string "become the CHAMPION of the POKéMON\l"
	.string "LEAGUE one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our POKéNAVS.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Now, I've got to hurry along.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

