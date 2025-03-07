.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts:: @ 823B181
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven:: @ 823B182
	lock
	goto_if_set FLAG_DAILY_REMATCH_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DAILY_REMATCH_STEVEN
	goto_if_unset FLAG_RECEIVED_AURORA_TICKET, MeteorFalls_StevensCave_EventScript_GiveAuroraTicket
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated:: @ 823B1CD
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_EventScript_GiveAuroraTicket:
	msgbox MeteorFalls_StevensCave_Text_BirthIsland, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_RECEIVED_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst: @ 823B1E1
	.string "Steven: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "Do you, uh… maybe think of me as\n"
	.string "just a rock maniac?\p"
	.string "No, that can't be right.\p"
	.string "We battled alongside each other at\n"
	.string "the Sootopolis Space Center.\p"
	.string "You should have a very good idea\n"
	.string "about how good I am.\p"
	.string "Okay, {PLAYER}{KUN}, if you're going to mount\n"
	.string "a serious challenge, expect the worst!$"

MeteorFalls_StevensCave_Text_StevenDefeat: @ 823B32D
	.string "You…\n"
	.string "I had no idea you'd become so strong…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue: @ 823B358
	.string "Steven: Come to think of it, ever since\n"
	.string "our paths first crossed in Granite\l"
	.string "Cave in Dewford, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become the Champion.\p"
	.string "My predictions usually come true.\p"
	.string "And where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"

MeteorFalls_StevensCave_Text_BirthIsland:
	.string "But… maybe you'd like to\n"
	.string "investigate the strange stone that's\l"
	.string "appeared on Birth Island?\p"
	.string "Here, take this ticket to the harbor\n"
	.string "in Lilycove.\p"
	.string "Perhaps you'll find something useful…$"
