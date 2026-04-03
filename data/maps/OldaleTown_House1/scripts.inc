OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Woman::
	msgbox OldaleTown_House1_Text_TakesATogepi, MSGBOX_DEFAULT
	givemon SPECIES_TOGEPI, 1, ITEM_NONE
	end

OldaleTown_House1_Text_TakesATogepi:
	.string "Oh, hello there!\n"
	.string "You look like you're just starting\l"
	.string "your POKéMON adventure.\p"
	.string "I have a feeling you and this little\n"
	.string "Togepi will get along wonderfully.\p"
	.string "Please take it with you!$"

