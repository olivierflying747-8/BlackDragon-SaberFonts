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
#define NO_COLOR_SWING
#define NO_SAVED_PRESET
#define NO_LOCKUP_HOLD
//#define SAVE_STATE //#define SAVE_PRESET
#define COLOR_CHANGE_DIRECT
   // this enables "click to change"
#define DISABLE_DIAGNOSTIC_COMMANDS
   // this disables some diagnostic commands to save memory
#define FEMALE_TALKIE_VOICE
#define NO_REPEAT_RANDOM
#define KILL_OLD_PLAYERS
//#define DISABLE_TALKIE
#define FETT263_TWIST_ON
#define FETT263_TWIST_ON_NO_BM
#define FETT263_TWIST_OFF
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

// Style1_Stripes (Red)
{ "Second;common", "tracks/JFO19.wav",
	StylePtr <MasterStyle>
	()
},

// Style1_FireBlade (DeepSkyBlue)
{ "Mag-Cyl;common", "tracks/",
	StylePtr <MasterStyle>
	()
},

// Style1_AudioFilter (Purple, DeepPurple?)
{ "Warp;common", "tracks/",
	StylePtr <MasterStyle>
	()
},

// Style1_SmokeBlade (Green, Green), Style2_FireBlade (Green, Green)
{ "Mother;common", "tracks/",
	StylePtr <MasterStyle>
	()
},

// Style1_BrownNoiseFlicker (AliceBlue), Style2_BrownNoiseFlicker (AliceBlue), Powerup_Unstable_Forward, Lockup_Color_Style2, Melt_Color_Style2, Drag_Color_Style, Drag_Start, 
{ "Baton;common", "tracks/TFA.wav",
	StylePtr <MasterStyle>
	()
},

// Style1_Thunderstorm (DeepSkyBlue, DodgerBlue)
{ "Thor;common", "tracks/Ragnorok.wav",
	StylePtr <MasterStyle>
	()
},

// Style1_StaffBlade (COLOR_PURPLE, ???? ALT COLOR)
{ "Staff;common", "tracks/fates",
	StylePtr <MasterStyle>
	()
},

// Smash Blade
{ "Smash;common", "tracks/Bro.wav",
	StylePtr <MasterStyle>
	()
},

// AudioFlicker (Blue, Blue 50% dim)
{ "Metamorphose;common", "tracks/Arrival.wav",
	StylePtr <MasterStyle>
	()
},

// GhostBuster_Blade (TODO, convert me! twistAngle speed fireBlade!)
{ "Proton_Pack;common", "tracks/ReyParkerJr.wav",
	StylePtr <MasterStyle>
	()
},

// Style1_PartyBlade
{ "party;common", "tracks/meco.wav",
	StylePtr <MasterStyle>
	()
},

};
BladeConfig blades[] = {
 { 0, WS2811BladePtr<132, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
  };
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
#endif