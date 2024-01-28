#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 1
#define VOLUME 2000
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 13.0
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 10 * 1000
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL
//#define NO_COLOR_SWING
//#define NO_SAVED_PRESET
//#define NO_LOCKUP_HOLD
#define SAVE_STATE //#define SAVE_PRESET
//#define COLOR_CHANGE_DIRECT // this enables "click to change"
// this disables some diagnostic commands to save memory
#define DISABLE_DIAGNOSTIC_COMMANDS
//#define DISABLE_TALKIE // Changes talky to simple beeps
//#define FEMALE_TALKIE_VOICE
#define NO_REPEAT_RANDOM
#define KILL_OLD_PLAYERS
//#define FETT263_TWIST_ON
//#define FETT263_TWIST_ON_NO_BM
//#define FETT263_TWIST_OFF
#define FETT263_SWING_ON
#define FETT263_SWING_ON_NO_BM
#define FETT263_SWING_ON_SPEED 600
#define FETT263_THRUST_ON
#define FETT263_THRUST_ON_NO_BM
#define FETT263_STAB_ON
#define FETT263_STAB_ON_NO_BM
#define FETT263_BATTLE_MODE
#define FETT263_LOCKUP_DELAY 200
#define FETT263_FORCE_PUSH
#define FETT263_SAY_BATTERY_PERCENT
#define FETT263_SPECIAL_ABILITIES //#define FETT263_MULTI_PHASE
// Edit Mode
#define FETT263_EDIT_MODE_MENU
#define ENABLE_ALL_EDIT_OPTIONS
#define DISABLE_BASIC_PARSER_STYLES
#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define FETT263_SAY_COLOR_LIST
#define FETT263_SAY_COLOR_LIST_CC
#endif

 
#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS

// Master Font for Edit mode, create /customize your own blade styles using StylePtr<MasterStyle>() and Fett263's Edit Menu.
#include "master/Master_v2.h"

Preset presets[] = {

	// One starter font, use Copy Preset to make more.
	{ "059_RM_Third;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

// XENOPIXEL Original fonts:

	/*
	// Kylo Ren (Unstable V2?)
	{ "001_Kylo_Ren;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// DarkSaber (???)
	{ "003_DarkSaber;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Ben Solo (???)
	{ "007_Ben_Solo;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Ascension KSith Fonts)
	{ "017_Ascension;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Dark Wolf (???)
	{ "022_DarkWolf;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Cyber Terror (???)
	{ "023_Cyber_Terror;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// The Butcher (???)
	{ "024_The_Butcher;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Bumble B (???)
	{ "025_BumbleB;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// The Collector (Bendu Armory)
	{ "026_TheCollector;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Corvus Bounty (???)
	{ "027_Corvus_Bounty;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Protocol (???)
	{ "030_Protocol;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Cybernetic Revolution (???)
	{ "031_Cybernetic_Revolution;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Codex of Light (???)
	{ "033_Codex_Of_Light;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Dark Ages (???)
	{ "034_Dark_Ages;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Hatred (???)
	{ "035_Hatred;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Whispers of Power (???)
	{ "043_Whispers_Of_Power;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Sailor Moon (???)
	{ "045_SailorMoon;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Battlefield V1 by Kyberphonic
	{ "051_Battle;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Apocalypse by Grayscale
	{ "053_Apocalypse;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Assassin by Grayscale
	{ "054_Assassin;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Decay by Grayscale
	{ "055_Decay;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Endure by Grayscale
	{ "056_Endure;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Mercenary by Grayscale
	{ "057_Mercenary;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Noble by Grayscale
	{ "058_Noble;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Rematch Bundle - Third by Kyberphonic
	{ "059_RM_Third;common", "tracks/JFO19.wav",
		StylePtr <MasterStyle>
		()
	},

	// BaseStyle_Stripes (Red)
	{ "060_Second;common", "tracks/JFO19.wav",
		StylePtr <MasterStyle>
		()
	},

	// BaseStyle_SmokeBlade (Green, Green), Style2_FireBlade (Green, Green)
	{ "061_Mother;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// BaseStyle_BrownNoiseFlicker (AliceBlue), Style2_BrownNoiseFlicker (AliceBlue), Powerup_Unstable_Forward, Lockup_Color_Style2, Melt_Color_Style2, Drag_Color_Style, Drag_Start, 
	{ "062_Baton;common", "tracks/TFA.wav",
		StylePtr <MasterStyle>
		()
	},

	// BaseStyle_StaffBlade (COLOR_PURPLE, ???? ALT COLOR)
	{ "063_Staff;common", "tracks/fates.wav",
		StylePtr <MasterStyle>
		()
	},

	// GhostBuster_Blade (TODO, convert me! twistAngle speed fireBlade!) // Proton_Pack
	{ "064_GhostSucker;common", "tracks/ReyParkerJr.wav",
		StylePtr <MasterStyle>
		()
	},

	// BaseStyle_Thunderstorm (DeepSkyBlue, DodgerBlue)
	{ "065_ThunderGod;common", "tracks/Ragnorok.wav",
		StylePtr <MasterStyle>
		()
	},

	// BaseStyle_AudioFilter (Purple, DeepPurple?)
	{ "066_WarpStar;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// BaseStyle_FireBlade (DeepSkyBlue)
	{ "067_MagCyl;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// AudioFlicker (Blue, Blue 50% dim)
	{ "068_Metamorphose;common", "tracks/Arrival.wav",
		StylePtr <MasterStyle>
		()
	},

	// Smash Blade
	{ "069_Smash;common", "tracks/Bro.wav",
		StylePtr <MasterStyle>
		()
	},

	// Transform by SaberFont
	{ "084_Transform;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Strange by Jay Delorian
	{ "085_Strange;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Sebulba by Jay Delorian
	{ "086_Sebulba;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Luigi Mansion by Jay Delorian
	{ "087_L_Mansion;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Kyber Zombie
	{ "088_Kyber_Zombie;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Godzilla
	{ "089_Godzilla;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Electric Mous
	{ "090_ElectricMouse;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Mouth Saber
	{ "091_MouthSaber;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Senate Majority
	{ "092_SenateMajority;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// The Maw
	{ "093_TheMaw;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Tiny Droid
	{ "094_TinyDroid;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Party Foul
	{ "095_PartyFoul;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Lightsaber of the Bells
	{ "096_Lightsaber_Of_The_Bells;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// Lumos
	{ "097_Lumos;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// The Predator
	{ "098_ThePredator;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	// C-137
	{ "099_C-137;common", "tracks/",
		StylePtr <MasterStyle>
		()
	},

	/*
	// BaseStyle_PartyBlade
	{ "party;common", "tracks/meco.wav",
		StylePtr <MasterStyle>
		()
	},
	// */

};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<132, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
  };
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
#endif