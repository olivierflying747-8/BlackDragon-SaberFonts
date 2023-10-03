#ifdef CONFIG_TOP
#include "proffieboard_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 1
#define VOLUME 1700
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 17.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL
//#define NO_COLOR_SWING
//#define NO_SAVED_PRESET
//#define SAVE_PRESET
//#define SAVE_STATE
//#define NO_LOCKUP_HOLD
#define COLOR_CHANGE_DIRECT
#define DISABLE_DIAGNOSTIC_COMMANDS
//#define COLOR_CHANGE_DIRECT
   // this enables "click to change"
#define DISABLE_DIAGNOSTIC_COMMANDS
   // this disables some diagnostic commands to save memory
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
#define FETT263_MULTI_PHASE
#define FETT263_BATTLE_MODE
#define FETT263_LOCKUP_DELAY 200
#define FETT263_FORCE_PUSH
#define FETT263_SAY_BATTERY_PERCENT
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 10 * 1000
#define NO_REPEAT_RANDOM

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


/* VALID FONT FOlDERS

Analog
Apocalypse
ASSASIN
Battle
Battle2
BLUE
Coda
common
Cripsity
Deadlink
Decay
Endure
EngineGrip
EXALTED
GhostSucker
gone
GREEN
Grey
MagCyl
Magnetic
Masterless
Mercenary
Metamorphose
Mother
Noble
Party
PeaceInOurTime
PURPLE
Ra
RED
Second
SEETHE
ShockBaton
SmashSowrd
Splinter
Staff
ThunderGod
tracks
Volatile
WarpStar
WHITE
YELLOW

*/

#ifdef CONFIG_PRESETS

// Master Font for Edit mode, create /customize your own blade styles using StylePtr<MasterStyle>() and Fett263's Edit Menu.
#include "master/Master.h"

// Font Presets. Just load as many font folders as you want with Master Style.
Preset presets[] = {

// Basic blade style.
{ "WHITE;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	()  //, "white"
},

{ "BLUE;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "blue"
},

{ "RED;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "red"
},

{ "GREEN;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "green"
},

{ "PURPLE;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "purple"
},

{ "YELLOW;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "yellow"
},

{ "Battle;common", "tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "battle1"
},

{ "Battle2;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "battle2"
},

// Broken ignition / flickery blade style.
{ "Volatile;common", "tracks/",
	StylePtr< MasterStyle>
	(), //"volatile"
},

// Standard green style, quigon sounds.
{ "Gone;common","tracks/Fates.wav",
	StylePtr <MasterStyle>
	() //, "ginn"
},

// Assasin blade style.
{ "ASSASSIN;common", "tracks/JFO9.wav",
	StylePtr <MasterStyle>
	() //, "assasin" 
},

// Seethe blade style.
{ "SEETHE;common", "tracks/JFO18.wav",
	StylePtr <MasterStyle>
	() //, "seethe" 
},

// Nightsister blade style.
{ "Mother;common", "tracks/",
	StylePtr <MasterStyle>
	() //, "mother"
},

{ "Noble;common", "tracks/Spoiler.wav",
	StylePtr <MasterStyle>
	() //, "noble"
},

{ "Mercenary;common", "common/tracks/venus.wav",
	StylePtr <MasterStyle>
	() //, "mercenary"
},

{ "Splinter;common", "tracks/",
	StylePtr<MasterStyle>
	() //, "splinter"
},

{ "Second;common", "tracks/JFO19.wav",
	StylePtr<MasterStyle>
	() //, "splinter"
}

};

BladeConfig blades[] = {
 { 0, WS2811BladePtr<132, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
  };
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
/*Button AuxButton(BUTTON_AUX, auxPin, "aux");*/
#endif

