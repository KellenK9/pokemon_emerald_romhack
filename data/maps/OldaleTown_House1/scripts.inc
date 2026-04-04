OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GIVEN_TOGEPI, OldaleTown_House1_EventScript_AlreadyReceivedTogepi
	msgbox OldaleTown_House1_Text_TakesATogepi, MSGBOX_DEFAULT
	setflag FLAG_GIVEN_TOGEPI
	bufferspeciesname STR_VAR_1, SPECIES_TOGEPI
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOGEPI
	givemon SPECIES_TOGEPI, 1, ITEM_NONE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, OldaleTown_House1_EventScript_SendTogepiToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, OldaleTown_House1_EventScript_SendTogepiToPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

OldaleTown_House1_EventScript_SendTogepiToParty::
	call OldaleTown_House1_EventScript_ReceivedTogepi
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_House1_EventScript_ReceivedTogepiEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto OldaleTown_House1_EventScript_ReceivedTogepiEnd
	end

OldaleTown_House1_EventScript_SendTogepiToPC::
	call OldaleTown_House1_EventScript_ReceivedTogepi
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_House1_EventScript_TogepiTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto OldaleTown_House1_EventScript_TogepiTransferredToPC
	end

OldaleTown_House1_EventScript_TogepiTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto OldaleTown_House1_EventScript_ReceivedTogepiEnd
	end

OldaleTown_House1_EventScript_ReceivedTogepi::
	playfanfare MUS_OBTAIN_ITEM
	message OldaleTown_House1_Text_ReceivedTogepi
	waitmessage
	waitfanfare
	return

OldaleTown_House1_EventScript_ReceivedTogepiEnd::
	release
	end

OldaleTown_House1_EventScript_AlreadyReceivedTogepi::
	msgbox OldaleTown_House1_Text_AllowYouToHaveTogepi, MSGBOX_DEFAULT
	release
	end

OldaleTown_House1_Text_TakesATogepi:
	.string "Oh, hello there!\n"
	.string "You look like you're just starting\l"
	.string "your POKéMON adventure.\p"
	.string "I have a feeling you and this little\n"
	.string "Togepi will get along wonderfully.\p"
	.string "Please take it with you!$"

OldaleTown_House1_Text_ReceivedTogepi:
	.string "{PLAYER} received the {STR_VAR_1}!$"

OldaleTown_House1_Text_AllowYouToHaveTogepi:
	.string "I hope that Togepi is doing well\n"
	.string "traveling with you!$"

