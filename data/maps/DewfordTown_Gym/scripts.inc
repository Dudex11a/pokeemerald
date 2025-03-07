DewfordTown_Gym_MapScripts:: @ 81FC63C
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition: @ 81FC642
	call DewfordTown_Gym_EventScript_SetFlashRadius
	end

DewfordTown_Gym_EventScript_SetFlashRadius:: @ 81FC648
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	compare VAR_0x8000, 0
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius7
	compare VAR_0x8000, 1
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius6
	compare VAR_0x8000, 2
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius5
	compare VAR_0x8000, 3
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius4
	compare VAR_0x8000, 4
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius3
	compare VAR_0x8000, 5
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius2
	goto DewfordTown_Gym_EventScript_SetFlashRadius1

DewfordTown_Gym_EventScript_SetLightsOn:: @ 81FC6A2
	setflashradius 0
	return

DewfordTown_Gym_EventScript_SetFlashRadius1:: @ 81FC6A6
	setflashradius 1
	return

DewfordTown_Gym_EventScript_SetFlashRadius2:: @ 81FC6AA
	setflashradius 2
	return

DewfordTown_Gym_EventScript_SetFlashRadius3:: @ 81FC6AE
	setflashradius 3
	return

DewfordTown_Gym_EventScript_SetFlashRadius4:: @ 81FC6B2
	setflashradius 4
	return

DewfordTown_Gym_EventScript_SetFlashRadius5:: @ 81FC6B6
	setflashradius 5
	return

DewfordTown_Gym_EventScript_SetFlashRadius6:: @ 81FC6BA
	setflashradius 6
	return

DewfordTown_Gym_EventScript_SetFlashRadius7:: @ 81FC6BE
	setflashradius 7
	return

DewfordTown_Gym_EventScript_BrightenRoom:: @ 81FC6C2
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	compare VAR_0x8000, VAR_0x8001
	goto_if_eq DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	compare VAR_0x8000, 1
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	compare VAR_0x8000, 2
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	compare VAR_0x8000, 3
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	compare VAR_0x8000, 4
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	compare VAR_0x8000, 5
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	compare VAR_0x8000, 6
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange:: @ 81FC71A
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer:: @ 81FC71B
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers:: @ 81FC726
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers:: @ 81FC731
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers:: @ 81FC73C
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers:: @ 81FC747
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers:: @ 81FC752
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness:: @ 81FC75D
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated:: @ 81FC768
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn:: @ 81FC77B
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura:: @ 81FC789
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden:: @ 81FC797
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian:: @ 81FC7A5
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith:: @ 81FC7B3
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers:: @ 81FC7C1
	return

DewfordTown_Gym_EventScript_Brawly:: @ 81FC7C2
	goto_if_set FLAG_DAILY_REMATCH_BRAWLY, DewfordTown_Gym_EventScript_AlreadyRematched
	goto_if_set FLAG_SYS_GAME_CLEAR, DewfordTown_Gym_EventScript_BrawlyRematch
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_TM08, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated:: @ 81FC7F7
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	addvar VAR_PETALBURG_GYM_STATE, 1
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp:: @ 81FC855
	giveitem ITEM_TM08_BULK_UP
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	return

DewfordTown_Gym_EventScript_GiveBulkUp2: @ 81FC878
	giveitem ITEM_TM08_BULK_UP
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	message DewfordTown_Gym_Text_BrawlyChooseFormat
	waitmessage
	multichoice 17, 6, MULTI_REMATCH_BATTLE_MODE, 0
	switch VAR_RESULT
	case 0, DewfordTown_Gym_EventScript_SetSingles
	case 1, DewfordTown_Gym_EventScript_SetDoubles
	case 2, DewfordTown_Gym_EventScript_Exit
	case 127, DewfordTown_Gym_EventScript_Exit
	releaseall
	end

DewfordTown_Gym_EventScript_SetSingles::
	msgbox DewfordTown_Gym_Text_BrawlyAllowLegends, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DewfordTown_Gym_EventScript_BrawlySinglesRematch
	trainerbattle_single TRAINER_BRAWLY_3, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_EventScript_AlreadyRematched, NO_MUSIC
	releaseall
	end

DewfordTown_Gym_EventScript_SetDoubles::
	msgbox DewfordTown_Gym_Text_BrawlyAllowLegends, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DewfordTown_Gym_EventScript_BrawlyDoublesRematch
	trainerbattle_double TRAINER_BRAWLY_5, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons, DewfordTown_Gym_EventScript_AlreadyRematched, NO_MUSIC
	releaseall
	end

DewfordTown_Gym_EventScript_BrawlySinglesRematch::
	trainerbattle_single TRAINER_BRAWLY_2, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_EventScript_AlreadyRematched, NO_MUSIC
	releaseall
	end

DewfordTown_Gym_EventScript_BrawlyDoublesRematch::
	trainerbattle_double TRAINER_BRAWLY_4, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons, DewfordTown_Gym_EventScript_AlreadyRematched, NO_MUSIC
	releaseall
	end

DewfordTown_Gym_EventScript_AlreadyRematched::
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	setflag FLAG_DAILY_REMATCH_BRAWLY
	releaseall
	end

DewfordTown_Gym_EventScript_Exit::
	releaseall
	end

DewfordTown_Gym_EventScript_Takao:: @ 81FC8B7
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom:: @ 81FC8D2
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn:: @ 81FC8D9
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom:: @ 81FC8F4
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura:: @ 81FC8FB
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom:: @ 81FC916
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden:: @ 81FC91D
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom:: @ 81FC938
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian:: @ 81FC93F
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom:: @ 81FC95A
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith:: @ 81FC961
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom:: @ 81FC97C
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide:: 
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	goto_if_set FLAG_DEWFORD_GYM_FRESHWATER, DewfordTown_Gym_Guide2
	msgbox DewfordTown_Gym_Text_Guide1, MSGBOX_DEFAULT
	giveitem ITEM_FRESH_WATER, 10
	setflag FLAG_DEWFORD_GYM_FRESHWATER
	msgbox DewfordTown_Gym_Text_Guide2, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_Guide2::
	msgbox DewfordTown_Gym_Text_Guide2, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory:: @ 81FC998
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue:: @ 81FC9A2
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue:: @ 81FC9B2
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified:: @ 81FC9C2
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue:: @ 81FC9CC
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_Guide1::
	.string "Hey, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Please, take this Fresh Water to\n"
	.string "help with your challenge!$"

DewfordTown_Gym_Text_Guide2::
	.string "Dewford's Gym Leader Brawly commands\n"
	.string "Fighting-type Pokémon.\p"
	.string "His strongest Pokémon is his Hariyama,\n"
	.string "and the rest of his team are no joke!\p"
	.string "Bringing a Ghost-type Pokémon\n"
	.string "could give you an advantage.\p"
	.string "You can find some in Granite Cave,\n"
	.string "Petalburg Woods or Dewford Manor.\p"
	.string "Also, the Gym is as dark as the\n"
	.string "ocean floor.\p"
	.string "But it will get brighter after defeating\n"
	.string "the Trainers in your way.\p"
	.string "Hey, okay, go for it!$"

DewfordTown_Gym_Text_GymGuidePostVictory: @ 81FCB5C
	.string "Whoah! It's turned too bright in here!\p"
	.string "Your future is bright, too!$"

DewfordTown_Gym_Text_TakaoIntro: @ 81FCB9F
	.string "Might is right!\n"
	.string "Come on!$"

DewfordTown_Gym_Text_TakaoDefeat: @ 81FCBB8
	.string "Not enough power…$"

DewfordTown_Gym_Text_TakaoPostBattle: @ 81FCBCA
	.string "Your skill overcame my strength!\n"
	.string "Your technique is commendable!$"

DewfordTown_Gym_Text_JocelynIntro: @ 81FCC0A
	.string "There's no need for Brawly to be\n"
	.string "involved!\p"
	.string "I'll crush you!$"

DewfordTown_Gym_Text_JocelynDefeat: @ 81FCC45
	.string "But… How?\n"
	.string "How could I lose so easily?$"

DewfordTown_Gym_Text_JocelynPostBattle: @ 81FCC6B
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a Gym Leader…\p"
	.string "No, I'll become the Pokémon League\n"
	.string "Champion!$"

DewfordTown_Gym_Text_LauraIntro: @ 81FCD01
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"

DewfordTown_Gym_Text_LauraDefeat: @ 81FCD3C
	.string "Waaaaaaah!\n"
	.string "I lost!$"

DewfordTown_Gym_Text_LauraPostBattle: @ 81FCD4F
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see Brawly's face…$"

DewfordTown_Gym_Text_LilithIntro: @ 81FCDB8
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"

DewfordTown_Gym_Text_LilithDefeat: @ 81FCDE5
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

DewfordTown_Gym_Text_LilithPostBattle: @ 81FCE08
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"

DewfordTown_Gym_Text_BrendenIntro: @ 81FCE48
	.string "I'll show you the gumption of\n"
	.string "a sailing man!$"

DewfordTown_Gym_Text_BrendenDefeat: @ 81FCE75
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

DewfordTown_Gym_Text_BrendenPostBattle: @ 81FCEAB
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our Gym Leader.$"

DewfordTown_Gym_Text_CristianIntro: @ 81FCEDC
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

DewfordTown_Gym_Text_CristianDefeat: @ 81FCF0A
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

DewfordTown_Gym_Text_CristianPostBattle: @ 81FCF26
	.string "You win!\n"
	.string "Go after that Badge!$"

DewfordTown_Gym_Text_BrawlyIntro: @ 81FCF44
	.string "I'm Brawly!\n"
	.string "Dewford's Gym Leader!\p"
	.string "I've been churned in the rough waves\n"
	.string "of these parts, and I've grown tough\l"
	.string "in the pitch-black cave!\p"
	.string "So you wanted to challenge me?\n"
	.string "Let me see what you're made of!$"

DewfordTown_Gym_Text_BrawlyDefeat: @ 81FD008
	.string "Whoah, wow! You made a much bigger\n"
	.string "splash than I expected!\p"
	.string "You swamped me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this Gym Badge!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge: @ 81FD07D
	.string "{PLAYER} received the Knuckle Badge\n"
	.string "from Brawly.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis: @ 81FD0A8
	.string "The Knuckle Badge makes all Pokémon\n"
	.string "up to Level 40, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "Flash outside of battle.\p"
	.string "Oh, yeah. You don't need to teach a\n"
	.string "Pokémon Flash to use it.\p"
	.string "If your Pokémon can learn Flash, it\n"
	.string "can always use it outside of battle.\p"
	.string "If you'd like, use this Technical\n"
	.string "Machine, too.$"

DewfordTown_Gym_Text_ExplainBulkUp: @ 81FD181
	.string "That TM08 contains Bulk Up.\p"
	.string "It's a move that raises both Attack\n"
	.string "and Defense stats.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly: @ 81FD1E0
	.string "Registered Gym Leader Brawly\n"
	.string "in the PokéNav.$"

DewfordTown_Gym_Text_BrawlyPostBattle: @ 81FD20D
	.string "I can see your talent becoming a giant\n"
	.string "wave to cause a storm of astonishment\l"
	.string "among Trainers one day!$"

DewfordTown_Gym_Text_GymStatue: @ 81FD272
	.string "Dewford Town Pokémon Gym$"

DewfordTown_Gym_Text_GymStatueCertified: @ 81FD28B
	.string "Dewford Town Pokémon Gym\p"
	.string "Brawly's certified Trainers:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch: @ 81FD2C4
	.string "Brawly: Show me how much higher\n"
	.string "you've gone!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat: @ 81FD367
	.string "Wow!\n"
	.string "Swamped again!$"

DewfordTown_Gym_Text_BrawlyPostRematch: @ 81FD37B
	.string "Brawly: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of Hoenn!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons: @ 81FD3DE
	.string "Oh? You only have one Pokémon\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two Pokémon.$"

DewfordTown_Gym_Text_BrawlyChooseFormat:
	.string "Brawly: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "So, you want our rematch to be a\n"
	.string "single battle or a double battle?$"

DewfordTown_Gym_Text_BrawlyAllowLegends:
	.string "Brawly: And how about battling my\n"
	.string "Legendary Pokémon? Think you're up\l"
	.string "to the challenge?$"
