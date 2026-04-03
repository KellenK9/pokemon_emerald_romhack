OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GIVEN_TOGEPI, OldaleTown_House1_EventScript_AlreadyReceivedTogepi
	msgbox OldaleTown_House1_Text_TakesATogepi, MSGBOX_DEFAULT
	setflag FLAG_GIVEN_TOGEPI
	givemon SPECIES_TOGEPI, 1, ITEM_NONE
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

OldaleTown_House1_Text_AllowYouToHaveTogepi:
	.string "I hope that Togepi is doing well\n"
	.string "traveling with you!$"

