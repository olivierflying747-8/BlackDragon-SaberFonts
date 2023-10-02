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

// Include common "using" layer styles from another file
#include "master/Common_Colors.h" // Color / color blend defines
#include "master/Common_Misc.h" // Misc common code and effects

#include "master/Common_Blade.h" // Blade effects, for STYLE_OPTION_ARG
#include "master/Common_Blade2.h" // Blade effects, for STYLE_OPTION2_ARG
#include "master/Common_Blade3.h" // Blade effects, for STYLE_OPTION3_ARG
#include "master/Common_Swing.h" // Swing effects for SWING_OPTION_ARG
#include "master/Common_Blast.h" // Blaster Effects
#include "master/Common_Lockup.h" // Lockup, Clash, Drag, Stab, Melt
#include "master/Common_PreOn.h" // PreOn effects for PREON_OPTION_ARG
#include "master/Common_Ignition.h" // Effects for IGNITION_OPTION_ARG
#include "master/Common_Retraction.h" // effects for RETRACTION_OPTION_ARG
#include "master/Common_PowerUp.h" // Effects for IGNITION_POWER_UP_ARG
#include "master/Common_PowerDown.h" // Effects for RETRACTION_COOL_DOWN_ARG
#include "master/Common_PostOff.h" // Effects for OFF_OPTION_ARG (They should really add a POSTOFF_OPTION_ARG...)

/* Based on Fett263 Static/Flicker (Primary Blade) OS6 Style, heavily modified (Added more options)
https://fett263.s3.us-east-2.amazonaws.com/fett263-proffieOS6-style-library.html#Static/Flicker
OS6.5 v1.0
This Style Contains ???? (originally 1296, before i added styles) Unique Combinations
Style Options:
0: AudioFlicker (Single Color (50%))
1: AudioFlicker (Two Color)
2: AudioFlicker (Two Color, 50%)
3: RandomFlicker (Single Color (50%))
4: RandomFlicker (Two Color)
5: Stripes blade
6: Fire Blade
7: Light smoke blade (AudioFlicker, 2 color, with waves of color)
8: Thunderstorm blade
9: Fett263 Smoke Blade style. (2 color, base color and alt swing color)
10: Flickery / Broken blade.
11: Coda blade style w/ swing effects. (3 color, 4th swing color)

--Effects Included--
STYLE_OPTION2_ARG options: // Secondary Blade Effects while on
0: Disabled
1: Emitter Flare
2: Emitter Flare (pulsing)
3: Fett263 FireBlade (ALTCOLOR)

STYLE_OPTION3_ARG options: // Tirtiary Blade Effects while on

Swing Effect Options:
0: Disabled
1: Force Slow
2: Fett263's Swing Effect
3: Unstable Swing effect

Preon Effect Options: 
0: Disabled
1: Overload (PreOn Color)
2: Sparking (PreOn Color)
3: Broken Ignition
4: Emitter Warm up
5: Blade Pre-Light up

PostOff Effect Options:
0: Disabled
1: Emitter Cooldown (PostOff Color)

Ignition Effect Options: 
0: Standard Ignition 
1: SparkTip Ignition 
2: Dual Mode Wipe (Up = Fast)
3: Center Wipe
4: Color Cycle

Retraction Effect Options:
0: Standard Retraction
1: SparkTip Retraction
2: Dual Mode Wipe In (Up = Fast)
3: Center Wipe
4: Color Cycle
5: Glitch off

PowerUp Effect Options:
0: Disabled
1: Glitch on
2: Unstable Power Up Forward
3: Power Burst Forward
4: Unstable Bright
5: Stabalize

CoolDown Effect Options:
0: Disabled
1: Unstable Cool Down Reverse
2: Power Burst Reverse
3: Bright Humpflicker
4: Smokeblade + Emitter Cooldown

Lockup Effect: Intensity Lockup V1

LightningBlock Effect: Responsive Lightning Block

Drag Effect: Intensity Sparking Drag

Melt Effect: Intensity Melt

Blast Effect (Randomly Selected): Blast Wave (Random), Blast Ripple Fade, Blast Wave (Sound Based), Blast Ripple, Blast Fade (Sound Based)

Clash Effect: Real Clash V1

Battery Level: Hilt Location (Green to Red) on Boot/FontChange/BatteryLevel
*/

using MasterStyle = Layers<
	ColorSelect<
		IntArg<STYLE_OPTION_ARG, 0>, 
		TrInstant, 
		// Option 0: Audioflicker (2 Color)
		Style1_AudioFilter,
		// Option 1: AudioFlicker (Rotatecolors, 2 color)
		Style1_AudioFilter_Rotate,
		// Option 2: Random Flicker (2 color)
		Style1_RandomFlicker,
		// Option 3: Pulsing Blade (2 color)
		Style1_Pulsing_Rotate,
		// Option 4: Stripes (single color)
		Style1_Stripes_Rotate,
		// Option 5: Unstable Stripes
		Style1_Stripes_RandomPerLEDFlicker,
		// Option 6: Stripes SlowNoise
		Style1_StripesX_SlowNoise,
		// Option 7: Fire blade
		Style1_FireBlade,
		// Option 8: BrownNoise
		Style1_BrownNoiseFlicker,
		// Option 9 : BrownNoise (2 color)
		Style1_BrownNoiseFlicker_2Color,
		// Option 10: Thunderstorm
		Style1_ThunderstormBlade,
		// Option 11: Base Fett263 Smoke Blade style
		Style1_SmokeBlade,
		// Option 12: Flickery / Broken blade
		Style1_FlickerBlade,
		// Option 13: Coda
		CodaBladeStyle,
		// Option 14: Darksaber blade
		DarkSaberStyle,
		// Option 15: Fireblade Interactive Pulse
		Style1_FirePulseInteractive
			
	>,

	// Secondary blade Styles
	ColorSelect<
		IntArg<STYLE_OPTION2_ARG, 0>,
		TrInstant,
		// Option 0 Off
		TRANSPARENT,

		// Option 5: Lightning flash?
		Style2_LightningFlash,

		// Option 1: AudiFlicker ALTCOLOR3
		Style2_AudioFilter,
		// Option 2: AudioFlicker using Rotate
		Style2_AudioFilter_Rotate,
		// Option 3: RandomFlicker ALTCOLOR3
		Style2_RandomFlicker,
		// Option 4: Pusling
		Style2_Pulsing_Rotate,
		// Option 5: Random LED Flicker (2 Color)
		Style2_RandomPerLEDFlicker,
		// Option 2: StripesX Slownoise
		Style2_StripesX_SlowNoise,
		// Option 6: Hump Waves (2 color)
		Style2_HumpWave,
		// Option 7: BrownNoise Stripes (ALT COLOR)
		Style2_BrownNoiseFlicker,
		// Option 8: Sparkles (ALTCOLOR3)
		Style2_Sparkle,
		// Option 9: Underlying Fett263 Smoke Blade Fire layer (Alt color)
		Style2_FireBlade,
		// Option 10: Fire
		Style2_Fire,
		// Option 11: Cylon
		Style2_Cylon
	>,

	// Tirtiary blade Styles
	ColorSelect<
		IntArg<STYLE_OPTION3_ARG, 0>,
		TrInstant,
		// Option 0 Off
		TRANSPARENT,
	
		// Option 1: AudiFlicker ALTCOLOR3
		Style3_AudioFilter,
		// Option 2: AudioFlicker using Rotate
		Style3_AudioFilter_Rotate,
		// Option 3: RandomFlicker ALTCOLOR3
		Style3_RandomFlicker,
		// Option 4: Pusling
		Style3_Pulsing_Rotate,
		// Option 5: Random LED Flicker (2 Color)
		Style3_RandomPerLEDFlicker,
		// Option 2: StripesX Slownoise
		Style3_StripesX_SlowNoise,
		// Option 6: Hump Waves (2 color)
		Style3_HumpWave,
		// Option 7: BrownNoise Stripes (ALT COLOR)
		Style3_BrownNoiseFlicker,
		// Option 8: Sparkles (ALTCOLOR3)
		Style3_Sparkle,
		// Option 9: Underlying Fett263 Smoke Blade Fire layer (Alt color)
		Style3_FireBlade,
		// Option 10: Fire
		Style3_Fire,
		// Option 11: Cylon
		Style3_Cylon,
		// Option 12: Emitter Flare
		Style3_EmitterFlare,
		// Option 13: Timed "breathing" emitter flare 
		Style3_EmitterBreathe,
		// Option 14: Emitter Pulse
		Style3_Emitter_Pulse
	>,
	
	// Swing Options/Force Effect options
	ColorSelect<
		IntArg<SWING_OPTION_ARG, 0>, 
		TrInstant, 
		// Option 0: Disabled
		TRANSPARENT,
		// Option 1: Force Slow?
		Swing_ForceSlow,
		// Option 2: Fett263's Swing Effect
		Layers <
			//Fett263 Ripple swing effect
			Swing_FettRipple,

			//Fett263 Bright hard swing effect
			Swing_FettHard
		>,
		// Option 3: Unstable Swing
		Layers <
			//Unstable swing
			Swing_Unstable,
			//Unstable ripple swing
			Swing_UnstableRippple
		>
	>,
	
	// Multi blast effect
	// Blast_MultiRandom,

	MultiTransitionEffectL<
		TrRandom<
			// Option 1: Blast Wave (Random)
			/*
			Blast_Wave_Random,
			// Option 3: Blast Wave (Sound Based)
			Blast_Wave_Sound,
			// Option 4: Blast Ripple
			Blast_Ripple,
			// Option 2: Blast Ripple Fade
			Blast_Ripple_Fade,
			// Option 5: Blast Fade (Sound Based)
			Blast_Fade_Sound,
			// Option 6, Responsive Blast
			Blast_Responsive,
			// Option 7: Localized clash
			Blast_LocalClash,
			// Option 8: Responsive Wave
			Blast_Responsive_Wave,
			// Option 9: BlastL
			Blast_BlastL,
			// Option 10: Responsive Blast Fade
			Blast_Responsive_Fade,
			// Option 11: Responsive Blast (Swing based)
			Blast_Responsive_Swing
			// */
			Blast_Ripple
		>, 
		EFFECT_BLAST
	>, 
	
	// TODO: Try using ResponsiveClashL < COLOR, TR1, TR2, TOP, BOTTOM, SIZE >
	// Clash effect
	Mix<
		IsLessThan<
			ClashImpactF<>, 
			Int<26000>
		>,
		// Mix A
		Clash_EffectA,
		// Mix B
		Clash_EffectB
	>,

	// Bright flash ripple on CLASH_UPDATE?
	TransitionEffectL<
		TrConcat<
			TrInstant,
			Clash_Update
		>,
		EFFECT_CLASH_UPDATE
	>,
	
	// Lockup
	LockupTrL<
		EffectSequence<
			EFFECT_LOCKUP_BEGIN,
			Lockup_Color_Style,
			Lockup_Color_Style2
		>,
		Lockup_Start, // EFFECT_LOCKUP_BEGIN
		Lockup_End, // EFFECT_LOCKUP_END
		SaberBase::LOCKUP_NORMAL
	>,
	
	// Lightning Block
	ResponsiveLightningBlockL<
		LB_Color_Style,
		LB_Start,
		LB_End
	>,
	
	// Drag
	LockupTrL<
		Drag_Color_Style,
		Drag_Start, // EFFECT_DRAG_BEGIN
		Drag_End, // EFFECT_DRAG_END
		SaberBase::LOCKUP_DRAG
	>,

	// Stab
	ResponsiveStabL<
		Stab_Color_Style,
		Stab_Start,
		Stab_End,
		IntArg<MELT_SIZE_ARG, 28000>,
		Sum <
			IntArg<MELT_SIZE_ARG, 28000>,
			Int<2000>
		>	
	>,

	/* // Non Responsive Stab Effect
	TransitionEffectL<
		TrConcat<
			TrJoin<
				TrDelayX<WavLen<>>,
				TrWipeIn<200>
			>,
			AlphaL<
				AudioFlickerL<
					STABCOLOR
				>,
				SmoothStep<
					IntArg<MELT_SIZE_ARG,28000>,
					Int<2000>
				>
			>,
			TrWipe<200>
		>,
		EFFECT_STAB
	>,
	*/
	
	// Melt
	LockupTrL<
		Melt_Color_Style, 
		Melt_Start, 
		Melt_End, 
		SaberBase::LOCKUP_MELT
	>,
	
	// In/Out
	InOutTrL<
		// Ignition Options
		TrSelect<
			IntArg<IGNITION_OPTION_ARG, 0>, 
			// Option 0: Standard
			Ignition_Standard,
			// Option 1: Dual Mode wip (up = fast)
			Ignition_DualMode,
			// Option 2: Spark Tip
			Ignition_SparkTip, 
			// Option 3: Center Wipe
			Ignition_CenterWipe,
			// Option 4: Color Cycle
			Ignition_ColorCycle,
			// Option 5: Lightning Strike
			Ignition_LightningStrike
		>, 
		// Retraction Options
		TrSelect<
			IntArg<RETRACTION_OPTION_ARG, 0>, 
			// Option 0: Standard
			Retraction_Standard,
			// Option 1: Dual Mode
			Retraction_DualMode,
			// Option 2: Spark tip.
			Retraction_SparkTip,
			// Option 3: Center Wipe
			Retraction_CenterWipe,
			// Option 4, Color cycle
			Retraction_ColorCycle,
			// Option 5, Glitch off
			Retraction_Glitch_Off
		>, 
		Black
	>,

	// Pre On
	TransitionEffectL<
		TrSelect<
			IntArg<PREON_OPTION_ARG, 0>, 
			// Option 0: None
			TrInstant, 
			// Option 1:  Overload
			PreOn_Overload,
			// Option 2: Sparking
			PreOn_Sparking,
			// Option 3: Broken Ignition
			PreOn_Broken_Ignition,
			// Option 4: Emitter warm up
			PreOn_Emitter_Warmup,
			// Option 5: Dim Pre-Blade Extension
			PreOn_Dim_Blade
		>, 
		EFFECT_PREON
	>,

	// TODO: add IGNITION_OPTION2_ARG / RETRACTION_OPTION2_ARG options
	// Ignition Effect
	TransitionEffectL<
		TrSelect<
			IntArg<IGNITION_POWER_UP_ARG, 0>,
			// Option 0: None
			TrInstant, 
			// Option 1: Power Flash
			Powerup_Flash,
			// Option 2: Power Surge (Stable)
			Powerup_Surge,
			// Option 3: Flash on
			Powerup_Flash_Fade,
			// Option 4: Power Burst Forward
			Powerup_Burst_Forward,
			// Option 5: Unstable Power Up Forward
			Powerup_Unstable_Forward,
			// Option 6: //Fett263 Unstable bright ignition effect
			Powerup_Unstable_Bright_Forward,
			// Option 7: Stabilize ignition
			Powerup_Stabalize
		>,
		EFFECT_IGNITION
	>,

	// Ignition Effect
	TransitionEffectL<
		TrSelect<
			IntArg<IGNITION_OPTION2_ARG, 0>,
			// Option 0: None
			TrInstant, 
			// Option 1: Power Flash
			Powerup_Flash,
			// Option 2: Power Surge (Stable)
			Powerup_Surge,
			// Option 3: Flash on
			Powerup_Flash_Fade,
			// Option 4: Power Burst Forward
			Powerup_Burst_Forward,
			// Option 5: Unstable Power Up Forward
			Powerup_Unstable_Forward,
			// Option 6: //Fett263 Unstable bright ignition effect
			Powerup_Unstable_Bright_Forward,
			// Option 7: Stabilize ignition
			Powerup_Stabalize
		>,
		EFFECT_IGNITION
	>,

	// Retraction effect
	TransitionEffectL<
		TrSelect<
			IntArg<RETRACTION_COOL_DOWN_ARG, 0>,
			// Option 0: None
			TrInstant, 
			// Option 1: Power Flash
			PowerDown_Flash,
			// Option 2: Unstable Cool Down Reverse
			PowerDown_Burst_Reverse,
			// Option 3: Power Burst Reverse
			PowerDown_Unstable_Reverse,
			// Option 4: //Fett263 Bright Humpflicker retraction effect
			PowerDown_Bright_Hump,
			// Option 5: Smoke Blade Retraction, Emitter Cooldown
			PowerDown_Smoke_Reverse
		>,
		EFFECT_RETRACTION
	>,

	// Post Off
	TransitionEffectL<
		TrSelect<
			IntArg<OFF_OPTION_ARG, 0>,
			// Option 0 // None
			TrInstant, 
			// Option 1: Emitter cooldown
			PostOff_EmitterCoolOff
		>,
		EFFECT_POSTOFF
	>,
	
	// Battery Monitor on Boot
	BatteryLevelOnBoot,

	// Battery level on font change
	BatteryLevelOnFontChange,

	// Battery level
	BatteryLevelOnDemand
>;


			
/*
// Basic blade style, default color White.
using BasicBladeStyle = Layers <

	// On Effect
	BasicBladeFlicker,

	// Lockup Effect
	LockupTrL <
		Layers <
			AlphaL<
				AudioFlickerL<White>,
				Bump<
					Scale<
						BladeAngle<>,
						Scale<
							BladeAngle<0, 16000>,
							Int<4000>,
							Int<26000>
						>,
						Int<6000>
					>,
					Scale<
						SwingSpeed<100>,
						Int<14000>,
						Int<18000>
					>
				>
			>,
			AlphaL<
				White,
				Bump<
					Scale<
						BladeAngle<>,
						Scale<
							BladeAngle<0, 16000>,
							Int<4000>,
							Int<26000>
						>,
						Int<6000>
					>,
					Int<10000>
				>
			>
		> ,
		TrConcat<
			TrInstant,
			White,
			TrFade<400>
		>,
		TrConcat<
			TrInstant,
			White,
			TrFade<400>
		>,
		SaberBase::LOCKUP_NORMAL
	> ,

	// Lightning Block
	ResponsiveLightningBlockL <
		Strobe<
			White,
			AudioFlicker<White, Blue>,
			50,
			1
		>,
		TrConcat<
			TrInstant,
			AlphaL<
				White,
				Bump<
					Int<12000>,
					Int<18000>
				>
			>,
			TrFade<200>
		>,
		TrConcat<
			TrInstant,
			HumpFlickerL<
				AlphaL<
					White,
					Int<16000>
				>,
				30
			>,
			TrSmoothFade<600>
		>
	>,

	// Stab
	ResponsiveStabL<
		Red,
		TrWipeIn<600>,
		TrWipe<600>
	>,

	// Blaster
	ResponsiveBlastFadeL<
		White,
		Scale<
			SwingSpeed<200>,
			Int<8000>,
			Int<16000>
		>,
		Int<400>
	>,

	// Clash
	ResponsiveClashL<
		White,
		TrInstant,
		TrFade<400>,
		Scale<
			BladeAngle<0, 16000>,
			Int<4000>,
			Int<26000>
		>,
		Int<6000>,
		Int<20000>
	>,

	// Drag
	LockupTrL<
		AlphaL<
			BrownNoiseFlickerL<
				White,
				Int<300>
			>,
			SmoothStep<
				Int<30000>,
				Int<5000>
			>
		>,
		TrWipeIn<400>,
		TrFade<300>,
		SaberBase::LOCKUP_DRAG
	>,

	// Melt
	LockupTrL<
		AlphaL<
			Mix<
				TwistAngle<>,
				Red,
				Orange
			>,
			SmoothStep<
				Int<28000>,
				Int<5000>
			>
		>,
		TrWipeIn<600>,
		TrFade<300>,
		SaberBase::LOCKUP_MELT
	>,

	// In/Out
	InOutTrL<
		TrWipe<300>,
		TrWipeInX<RetractionTime<0>>,
		Black
	>,

	// Battery Monitor on Boot
	BatteryLevelOnBoot,

	// Battery level on font change
	BatteryLevelOnFontChange,

	// Battery level
	BatteryLevelOnDemand
>;
*/

/*--------------------------------- Basic Blade Style -------------------------
copyright Fett263 Simple (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#Simple
OS6.7 v4.021
Single Style
Base Style: AudioFlicker (Single Color (75%))


--Effects Included--
Ignition Effect: Standard Ignition
Retraction Effect: Standard Retraction
PostOff Effect: Emitter Cool Off (Emitter Size)
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Responsive Melt
Stab Effect: AudioFlicker Stab
Clash Effect: Responsive Clash with Wave
Battery Level: Blade Location (Green to Red)
*/
/*
using BasicBladeStyle2 = Layers<

	// On effect
	BasicBladeFlicker,
	
	// Stab
	TransitionEffectL<
		TrConcat<
			TrJoin<
				TrDelayX<WavLen<>>,
				TrWipeIn<200>
			>,
			AlphaL<
				AudioFlickerL<
					STABCOLOR
				>,
				SmoothStep<
					IntArg<MELT_SIZE_ARG,28000>,
					Int<2000>
				>
			>,
			TrWipe<200>
		>,
		EFFECT_STAB
	>,
	
	// Clash
	TransitionEffectL<
		TrWaveX<
			RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,
			Scale<
				ClashImpactF<>,
				Int<100>,
				Int<400>
			>,
			Int<100>,
			Scale<
				ClashImpactF<>,
				Int<100>,
				Int<400>
			>,
			LockupScale
		>,
		EFFECT_CLASH
	>,
	
	// Lockup
	LockupTrL<
		AlphaMixL<
			Bump<
				Scale<
					BladeAngle<>,
					Scale<
						BladeAngle<0,16000>,
						Sum<
							IntArg<LOCKUP_POSITION_ARG,16000>,
							Int<-12000>
						>,
						Sum<
							IntArg<LOCKUP_POSITION_ARG,16000>,
							Int<10000>
						>
					>,
					Scale<
						SwingSpeed<100>,
						Int<14000>,
						Int<18000>
					>
				>
			>,
			AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,
			BrownNoiseFlickerL<
				RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,
				Int<200>
			>
		>,
		TrConcat<
			TrInstant,
			RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,
			TrFade<400>
		>,
		TrConcat<
			TrInstant,
			RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,
			TrFade<400>
		>,
		SaberBase::LOCKUP_NORMAL
	>,
	
	// Lightning block
	ResponsiveLightningBlockL<
		Strobe<
			RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
			AudioFlicker<
				RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
				Blue
			>,
			50,
			1
		>,
		TrConcat<
			TrInstant,
			AlphaL<
				RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
				Bump<
					Int<12000>,
					Int<18000>
				>
			>,
			TrFade<200>
		>,
		TrConcat<
			TrInstant,
			HumpFlickerL<
				AlphaL<
					RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
					Int<16000>
				>,
				30
			>,
			TrSmoothFade<600>
		>
	>,
	
	// Drag
	LockupTrL<
		AlphaL<
			RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,14,0>>>,
			SmoothStep<
				IntArg<DRAG_SIZE_ARG,28000>,
				Int<3000>
			>
		>,
		TrConcat<
			TrJoin<
				TrDelay<4000>,
				TrWipeIn<200>
			>,
			AlphaL<
				BrownNoiseFlickerL<
					RgbArg<DRAG_COLOR_ARG,Rgb<255,14,0>>,
					Int<300>
				>,
				SmoothStep<
					IntArg<DRAG_SIZE_ARG,28000>,
					Int<3000>
				>
			>,
			TrFade<4000>
		>,
		TrFade<300>,
		SaberBase::LOCKUP_DRAG
	>,

	ResponsiveEffectBlastStyle,
	
	// Melt
	LockupTrL<
		AlphaL<
			Mix<
				TwistAngle<>,
				RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,
				RotateColorsX<
					Int<3000>,
					RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>
				>
			>,
			SmoothStep<
				IntArg<MELT_SIZE_ARG,28000>,
				Int<4000>
			>
		>,
		TrConcat<
			TrWipeIn<100>,
			AlphaL<
				RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,
				SmoothStep<
					IntArg<MELT_SIZE_ARG,28000>,
					Int<4000>
				>
			>,
			TrFade<300>
		>,
		TrWipe<200>,
		SaberBase::LOCKUP_MELT
	>,
	
	// In/Out
	InOutTrL<
		TrWipeX<IgnitionTime<300>>,
		TrWipeInX<RetractionTime<0>>,
		Black
	>,
	
	// Post Off
	TransitionEffectL<
		EmitterCoolOffStyle,
		EFFECT_POSTOFF
	>,
	
	// Battery Monitor on Boot
	BatteryLevelOnBoot,

	// Battery level on font change
	BatteryLevelOnFontChange,

	// Battery level
	BatteryLevelOnDemand
>;
/*
Add to preset as StylePtr<MainAudioFlickerSingleColor75%OrangeRed>()
--------------------------------------------------------------------------*/

/*
//
// Thunderstorm style (blue with flashing lightning)
//
using ThunderStorm = Layers<

	// On effect
	TransitionLoop<
		RotateColorsX<
			Variation,
			DeepSkyBlue
		>,
		TrConcat<
			TrBoing<500,3>,
			Layers<
				Stripes<
					10000,
					100,
					RotateColorsX<
						Variation,
						Rgb<0,40,128>
					>,
					RotateColorsX<
						Variation,
						Rgb<0,8,30>
					>,
					RotateColorsX<
						Variation,
						Rgb<0,63,200>
					>
				>,
				AlphaL<
					Stripes<
						8000,
						-200,
						RotateColorsX<
							Variation,
							DeepSkyBlue
						>,
						RotateColorsX<
							Variation,
							Rgb<0,19,60>
						>
					>,
					Int<16384>
				>
			>,
			TrDelayX<
				Scale<
					SlowNoise<Int<3000>>,
					Int<100>,
					Int<2000>
				>
			>
		>
	>,
		
	// Lockup
	LockupTrL<
		Layers<
			AlphaL<
				AudioFlickerL<White>,
				Bump<
					Scale<
						BladeAngle<>,
						Scale<
							BladeAngle<0, 16000>,
							Int<4000>,
							Int<26000>
						>,
						Int<6000>
					>,
					Scale<
						SwingSpeed<100>,
						Int<14000>,
						Int<18000>
					>
				>
			>,
			AlphaL<
				White,
				Bump<
					Scale<
						BladeAngle<>,
						Scale<
							BladeAngle<0, 16000>,
							Int<4000>,
							Int<26000>
						>,
						Int<6000>
					>,
					Int<10000>
				>
			>
		>,
		TrConcat<
			TrInstant,
			White,
			TrFade<400>
		>,
		TrConcat<
			TrInstant,
			White,
			TrFade<400>
		>,
		SaberBase::LOCKUP_NORMAL
	>,
		
	// Lightning block
	ResponsiveLightningBlockL<
		Strobe<
			White,
			AudioFlicker<
				White,
				Blue
			>,
			50,
			1
		>,
		TrConcat<
			TrInstant,
			AlphaL<
				White,
				Bump<
					Int<12000>,
					Int<18000>
				>
			>,
			TrFade<200>
		>,
		TrConcat<
			TrInstant,
			HumpFlickerL<
				AlphaL<
					White,
					Int<16000>
				>,
				30
			>,
			TrSmoothFade<600>
		>
	>,
		
	// Stab effect
	ResponsiveStabL<
		Red,
		TrWipeIn<600>,
		TrWipe<600>
	>,
	
	ResponsiveEffectBlastStyle,
		
	// Clash effect
	ResponsiveClashL<
		White,
		TrInstant,
		TrFade<400>,
		Scale<
			BladeAngle<0, 16000>,
			Int<4000>,
			Int<26000>
		>,
		Int<6000>,
		Int<20000>
	>,
		
	// Drag effect
	LockupTrL<
		AlphaL<
			BrownNoiseFlickerL<
				White,
				Int<300>
			>,
			SmoothStep<
				Int<30000>,
				Int<5000>
			>
		>,
		TrWipeIn<400>,
		TrFade<300>,
		SaberBase::LOCKUP_DRAG
	>,
		
	// Melt effect
	LockupTrL<
		AlphaL<
			Mix<
				TwistAngle<>,
				Red,
				Orange
			>,
			SmoothStep<
				Int<28000>,
				Int<5000>
			>
		>,
		TrWipeIn<600>,
		TrFade<300>,
		SaberBase::LOCKUP_MELT
	>,
		
	// In/Out effect
	InOutTrL<
		TrWipe<300>,
		TrWipeIn<500>,
		Black
	>,

	// Battery Monitor on Boot
	BatteryLevelOnBoot,

	// Battery level on font change
	BatteryLevelOnFontChange,

	// Battery level
	BatteryLevelOnDemand
>;
// */

/*--------------------------------- BrokenBladeDragon -------------------------
copyright Fett263 CustomBlade (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#CustomBlade
OS6.7 v4.021
This Style Contains 2 Unique Combinations
Rotoscope (Erratic)


--Effects Included--
Preon Effect: Faulty Ignition (Base Color)
Ignition Effect: SparkTip Ignition
PowerUp Effect: Power Burst Emitter
Retraction Effect Options: Default (0): Glitch Off, 1: SparkTip Retraction
CoolDown Effect: Power Burst Center Out
PostOff Effect: Emitter Cool Off (Emitter Size)
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Responsive Melt
Stab Effect: AudioFlicker Stab
Blast Effect: Blast Wave (Random)
Clash Effect: Responsive Clash with Wave
Emitter Effect: Flickering Flare
Battery Level: Blade Location (Green to Red)
*/
/*
using BrokenBladeDragon = Layers<
	// On Effect
	Mix<
		Scale<
			IsLessThan<
				SlowNoise<
					Int<2000>
				>, 
				Int<18000>
			>, 
			Int<0>, 
			Int<32768>
		>, 
		Gradient<
			RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>, 
			Mix<
				Int<9921>, 
				Black, 
				RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>
			>
		>, 
		Stripes<
			12000, 
			-800, 
			Gradient<
				RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>, 
				Mix<
					Int<9921>, 
					Black, 
					RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>
				>
			>, 
			Gradient<
				RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>, 
				Mix<
					Int<9921>, 
					Black, 
					RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>
				>
			>, 
			Mix<
				Int<7710>, 
				Black, 
				Gradient<
					RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>, 
					Mix<
						Int<9921>, 
						Black, 
						RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>
					>
				>
			>, 
			Gradient<
				RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>, 
				Mix<
					Int<9921>, 
					Black, 
					RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>
				>
			>, 
			Mix<
				Int<16448>, 
				Black, 
				Gradient<
					RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>, 
					Mix<
						Int<9921>, 
						Black, 
						RgbArg<BASE_COLOR_ARG, Rgb<61, 200, 255>>
					>
				>
			>
		>
	>, 
	// Emitter Flare when On
	AlphaL<
		AudioFlickerL<
			RgbArg<EMITTER_COLOR_ARG, Rgb<80, 50, 210>>
		>, 
		SmoothStep<
			IntArg<EMITTER_SIZE_ARG, 2000>, 
			Int<-6000>
		>
	>, 
	
	// Ignition Effect
	TransitionEffectL<
		TrConcat<
			TrJoin<
				TrDelayX<
					IgnitionTime<300>
				>, 
				TrInstant
			>, 
			AlphaL<
				Stripes<
					5000, 
					-2500, 
					IGNITIONCOLOR, 
					Mix<
						Int<7710>, 
						Black, 
						IGNITIONCOLOR
					>, 
					Mix<
						Int<3855>, 
						Black, 
						IGNITIONCOLOR
					>
				>, 
				SmoothStep<
					IntArg<EMITTER_SIZE_ARG, 2000>, 
					Int<-500>
				>
			>, 
			TrFade<500>
		>, 
		EFFECT_IGNITION
	>, 
	
	// Retraction Effect
	TransitionEffectL<
		TrConcat<
			TrJoin<
				TrDelayX<
					RetractionTime<0>
				>, 
				TrInstant
			>, 
			Remap<
				CenterDistF<>, 
				Stripes<
					5000, 
					-2500, 
					RgbArg<RETRACTION_COLOR_ARG, Rgb<100, 200, 250>>, 
					Mix<
						Int<7710>, 
						Black, 
						RgbArg<RETRACTION_COLOR_ARG, Rgb<100, 200, 250>>
					>, 
					Mix<
						Int<3855>, 
						Black, 
						RgbArg<RETRACTION_COLOR_ARG, Rgb<100, 200, 250>>
					>
				>
			>, 
			TrFade<800>
		>, 
		EFFECT_RETRACTION
	>, 
	
	// Stab effect
	TransitionEffectL<
		TrConcat<
			TrJoin<
				TrDelayX<WavLen<>>, 
				TrWipeIn<200>
			>, 
			AlphaL<
				AudioFlickerL<
					STABCOLOR
				>, 
				SmoothStep<
					IntArg<MELT_SIZE_ARG, 28000>, 
					Int<2000>
				>
			>, 
			TrWipe<200>
		>, 
		EFFECT_STAB
	>, 
	
	ResponsiveEffectBlastStyle,
	
	// Clash effect
	TransitionEffectL<
		TrWaveX<
			CLASHCOLOR, 
			Scale<
				ClashImpactF<>, 
				Int<100>, 
				Int<400>
			>, 
			Int<100>, 
			Scale<
				ClashImpactF<>, 
				Int<100>, 
				Int<400>
			>, 
			LockupScale
		>, 
		EFFECT_CLASH
	>, 
	
	// Lockup effect
	ResponsiveLockupL <
	//LockupTrL<
		AlphaMixL<
			Bump<
				Scale<
					BladeAngle<>, 
					Scale<
						BladeAngle<0, 16000>, 
						Sum<
							IntArg<LOCKUP_POSITION_ARG, 16000>, 
							Int<-12000>
						>, 
						Sum<
							IntArg<LOCKUP_POSITION_ARG, 16000>, 
							Int<10000>
						>
					>, 
					Scale<
						SwingSpeed<100>, 
						Int<14000>, 
						Int<18000>
					>
				>
			>, 
			AudioFlickerL<
				LOCKUPCOLOR
			>, 
			BrownNoiseFlickerL<
				LOCKUPCOLOR, 
				Int<200>
			>
		>, 
		TrConcat<
			TrInstant, 
			LOCKUPCOLOR, 
			TrFade<400>
		>, 
		TrConcat<
			TrInstant, 
			LOCKUPCOLOR, 
			TrFade<400>
		> 
		//SaberBase::LOCKUP_NORMAL
	>, 
	
	// Lightning block
	ResponsiveLightningBlockL<
		Strobe<
			LBCOLOR, 
			AudioFlicker<
				LBCOLOR, 
				Blue
			>, 
			50, 
			1
		>, 
		TrConcat<
			TrInstant, 
			AlphaL<
				LBCOLOR, 
				Bump<
					Int<12000>, 
					Int<18000>
				>
			>, 
			TrFade<200>
		>, 
		TrConcat<
			TrInstant, 
			HumpFlickerL<
				AlphaL<
					LBCOLOR, 
					Int<16000>
				>, 
				30
			>, 
			TrSmoothFade<600>
		>
	>, 
	
	// Drag effect
	ResponsiveDragL <
	//LockupTrL<
		AlphaL<
			RandomPerLEDFlickerL<
				RgbArg<DRAG_COLOR_ARG, Rgb<255, 14, 0>>
			>, 
			SmoothStep<
				IntArg<DRAG_SIZE_ARG, 28000>, 
				Int<3000>
			>
		>, 
		TrConcat<
			TrJoin<
				TrDelay<4000>, 
				TrWipeIn<200>
			>, 
			AlphaL<
				BrownNoiseFlickerL<
					RgbArg<DRAG_COLOR_ARG, Rgb<255, 14, 0>>, 
					Int<300>
				>, 
				SmoothStep<
					IntArg<DRAG_SIZE_ARG, 28000>, 
					Int<3000>
				>
			>, 
			TrFade<4000>
		>, 
		TrFade<300>
		//SaberBase::LOCKUP_DRAG
	>, 
	
	// Melt effect
	ResponsiveMeltL <
	//LockupTrL<
		AlphaL<
			Mix<
				TwistAngle<>, 
				STABCOLOR, 
				RotateColorsX<
					Int<3000>, 
					STABCOLOR
				>
			>, 
			SmoothStep<
				IntArg<MELT_SIZE_ARG, 28000>, 
				Int<4000>
			>
		>, 
		TrConcat<
			TrWipeIn<100>, 
			AlphaL<
				STABCOLOR, 
				SmoothStep<
					IntArg<MELT_SIZE_ARG, 28000>, 
					Int<4000>
				>
			>, 
			TrFade<300>
		>, 
		TrWipe<200> 
		//SaberBase::LOCKUP_MELT
	>, 
	
	// In/Out Effect
	InOutTrL<
		TrWipeSparkTipX<
			RgbArg<IGNITION_COLOR_ARG, Rgb<200, 255, 255>>, 
			IgnitionTime<300>
		>, 
		TrSelect<
			IntArg<RETRACTION_OPTION_ARG, 0>, 
			TrConcat<
				TrJoin<
					TrDelayX<
						Mult<
							RetractionTime<0>, 
							Int<16384>
						>
					>, 
					TrWipeInX<
						Mult<
							RetractionTime<0>, 
							Int<16384>
						>
					>
				>, 
				Mix<
					SmoothStep<
						NoisySoundLevel, 
						Int<-1>
					>,
					Black, 
					RETRACTIONCOLOR
				>, 
				TrWipeInX<
					Mult<
						RetractionTime<0>, 
						Int<16384>
					>
				>
			>, 
			TrWipeInSparkTipX<
				RETRACTIONCOLOR, 
				RetractionTime<0>
			>
		>, 
		Black
	>, 
	
	// Pre on Effect
	TransitionEffectL<
		TrConcat<
			TrInstant, 
			AlphaL<
				RandomPerLEDFlicker<
					RgbArg<BASE_COLOR_ARG, Rgb<0, 200, 255>>, 
					Black
				>, 
				SmoothStep<
					Scale<
						NoisySoundLevel, 
						Int<-10000>, 
						Int<36000>
					>, 
					Int<-4000>
				>
			>, 
			TrDelayX<
				WavLen<EFFECT_PREON>
			>
		>, 
		EFFECT_PREON
	>, 

	TransitionEffectL<
		EmitterCoolOffStyle,
		EFFECT_POSTOFF
	>,
	
	// Battery Monitor on Boot
	BatteryLevelOnBoot,

	// Battery level on font change
	BatteryLevelOnFontChange,

	// Battery level
	BatteryLevelOnDemand
>;

/*
Add to preset as StylePtr<BrokenBladeDragon>()
--------------------------------------------------------------------------*/


/*--------------------------------- RedBaylinSkull -------------------------
copyright Fett263 Simple (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#Simple
OS6.7 v4.021
Single Style
Base Style: AudioFlicker (Single Color (75%))


--Effects Included--
Ignition Effect: Standard Ignition
Retraction Effect: Standard Retraction
PostOff Effect: Emitter Cool Off (Emitter Size)
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Responsive Melt
Stab Effect: AudioFlicker Stab
Clash Effect: Responsive Clash with Wave
Emitter Effect: Unstable Flare with Random Pulse
Battery Level: Blade Location (Green to Red)
*/
/*
using RedBaylinSkull = Layers<
	// Main blade
	AudioFlicker<
		RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,
		Mix<
			Int<24576>,
			Black,
			RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>
		>
	>,
	TransitionLoopL<
		TrConcat<
			TrDelayX<
				Scale<
					SlowNoise<Int<1000>>,
					Int<300>,
					Int<3000>
				>
			>,
			AlphaL<
				RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>,
				Int<0>
			>,
			TrSparkX<
				RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>,
				Scale<
					NoisySoundLevel,
					Int<200>,
					Int<600>
				>,
				Int<250>,
				Int<0>
			>
		>
	>,
	AlphaL<
		RandomPerLEDFlickerL<
			RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>
		>,
		SmoothStep<
			Scale<
				NoisySoundLevel,
				IntArg<EMITTER_SIZE_ARG,2000>,
				Sum<
					IntArg<EMITTER_SIZE_ARG,2000>,
					Int<6000>
				>
			>,
			Int<-6000>
		>
	>,
	
	// Stab
	TransitionEffectL<
		TrConcat<
			TrJoin<
				TrDelayX<WavLen<>>,
				TrWipeIn<200>
			>,
			AlphaL<
				AudioFlickerL<STABCOLOR>,
				SmoothStep<
					IntArg<MELT_SIZE_ARG,28000>,
					Int<2000>
				>
			>,
			TrWipe<200>
		>,
		EFFECT_STAB
	>,
	
	// Clash
	TransitionEffectL<
		TrWaveX<
			RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,
			Scale<
				ClashImpactF<>,
				Int<100>,
				Int<400>
			>,
			Int<100>,
			Scale<
				ClashImpactF<>,
				Int<100>,
				Int<400>
			>,
			LockupScale
		>,
		EFFECT_CLASH
	>,
	
	// Lockup
	LockupTrL<
		AlphaMixL<
			Bump<
				Scale<
					BladeAngle<>,
					Scale<
						BladeAngle<0,16000>,
						Sum<
							IntArg<LOCKUP_POSITION_ARG,16000>,
							Int<-12000>
						>,
						Sum<
							IntArg<LOCKUP_POSITION_ARG,16000>,
							Int<10000>
						>
					>,
					Scale<
						SwingSpeed<100>,
						Int<14000>,
						Int<18000>
					>
				>
			>,
			AudioFlickerL<
				RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>
			>,
			BrownNoiseFlickerL<
				RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,
				Int<200>
			>
		>,
		TrConcat<
			TrInstant,
			RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,
			TrFade<400>
		>,
		TrConcat<
			TrInstant,
			RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,
			TrFade<400>
		>,
		SaberBase::LOCKUP_NORMAL
	>,
	
	// Lightning block
	ResponsiveLightningBlockL<
		Strobe<
			RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
			AudioFlicker<
				RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
				Blue
			>,
			50,
			1
		>,
		TrConcat<
			TrInstant,
			AlphaL<
				RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
				Bump<
					Int<12000>,
					Int<18000>
				>
			>,
			TrFade<200>
		>,
		TrConcat<
			TrInstant,
			HumpFlickerL<
				AlphaL<
					RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
					Int<16000>
				>,
				30
			>,
			TrSmoothFade<600>
		>
	>,
	
	// Drag
	LockupTrL<
		AlphaL<
			RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,14,0>>>,
			SmoothStep<
				IntArg<DRAG_SIZE_ARG,28000>,
				Int<3000>
			>
		>,
		TrConcat<
			TrJoin<
				TrDelay<4000>,
				TrWipeIn<200>
			>,
			AlphaL<
				BrownNoiseFlickerL<
					RgbArg<DRAG_COLOR_ARG,Rgb<255,14,0>>,
					Int<300>
				>,
				SmoothStep<
					IntArg<DRAG_SIZE_ARG,28000>,
					Int<3000>
				>
			>,
			TrFade<4000>
		>,
		TrFade<300>,
		SaberBase::LOCKUP_DRAG
	>,
	
	// Melt
	LockupTrL<
		AlphaL<
			Mix<
				TwistAngle<>,
				RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,
				RotateColorsX<
					Int<3000>,
					RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>
				>
			>,
			SmoothStep<
				IntArg<MELT_SIZE_ARG,28000>,
				Int<4000>
			>
		>,
		TrConcat<
			TrWipeIn<100>,
			AlphaL<
				RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,
				SmoothStep<
					IntArg<MELT_SIZE_ARG,28000>,
					Int<4000>
				>
			>,
			TrFade<300>
		>,
		TrWipe<200>,
		SaberBase::LOCKUP_MELT
	>,
	
	// In/Out
	InOutTrL<
		TrWipeX<IgnitionTime<300>>,
		TrWipeInX<RetractionTime<0>>,
		Black
	>,
	
	// Post Off
	TransitionEffectL<
		TrConcat<
			TrInstant,
			AlphaL<
				White,
				SmoothStep<
					IntArg<EMITTER_SIZE_ARG,2000>,
					Int<-4000>
				>
			>,
			TrFadeX<
				Mult<
					Scale<
						IsLessThan<
							WavLen<EFFECT_POSTOFF>,
							Int<200>
						>,
						WavLen<EFFECT_POSTOFF>,
						Int<4000>
					>,
					Int<10923>
				>
			>,
			AlphaL<
				Orange,
				SmoothStep<
					IntArg<EMITTER_SIZE_ARG,2000>,
					Int<-4000>
				>
			>,
			TrFadeX<
				Mult<
					Scale<
						IsLessThan<
							WavLen<EFFECT_POSTOFF>,
							Int<200>
						>,
						WavLen<EFFECT_POSTOFF>,
						Int<4000>
					>,
					Int<10923>
				>
			>,
			AlphaL<
				Red,
				SmoothStep<
					IntArg<EMITTER_SIZE_ARG,2000>,
					Int<-2000>
				>
			>,
			TrFadeX<
				Mult<
					Scale<
						IsLessThan<
							WavLen<EFFECT_POSTOFF>,
							Int<200>
						>,
						WavLen<EFFECT_POSTOFF>,
						Int<4000>
					>,
					Int<10923>
				>
			>
		>,
		EFFECT_POSTOFF
	>,

	// Battery Monitor on Boot
	BatteryLevelOnBoot,

	// Battery level on font change
	BatteryLevelOnFontChange,

	// Battery level
	BatteryLevelOnDemand
>;
/*
Add to preset as StylePtr<MainAudioFlickerSingleColor75%OrangeRed>()
--------------------------------------------------------------------------*/

Preset presets[] = {

// Basic blade style.
{ "WHITE;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	()  //, "white"
},

// Broken ignition / flickery blade style.
{ "Volatile;common", "tracks/",
	StylePtr< MasterStyle>
	(), //"volatile"
},

{ "Battle;common", "tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "battle1"
},

// /*
{ "Battle2;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "battle2"
},

/*
{ "BLUE;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "blue"
},

{ "RED;common","tracks/fates.wav",
	StylePtr <MasterStyle>
	() //, "red"
},
*/

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

// Standard green style, quigon sounds.
{ "Gone;common","tracks/Fates.wav",
//StylePtr<Layers<AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<200>,Int<8000>,Int<16000>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeInX<RetractionTime<0>>,Black>>>
	StylePtr <MasterStyle>
	() //, "ginn"
},

// Assasin blade style.
{ "ASSASSIN;common", "tracks/JFO9.wav",
	StylePtr <MasterStyle>
/*
	StylePtr<Layers<
	HumpFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>,50>,
	AlphaL<Stripes<2500,-2750,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<25,60,0>>,Pulsing<RotateColorsX<Variation,Rgb<0,30,0>>,Black,800>>,SwingSpeed<375>>,
	LockupTrL<Layers<
	AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	AlphaL<RotateColorsX<Variation,Rgb16<21301,65535,0>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3000>>,Int<-4000>>>,
	ResponsiveStabL<Red>,
	EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
	ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
	TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb16<38402,65535,3934>>,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<38402,65535,3934>>,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<500>>,EFFECT_IGNITION>,
	TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb16<54757,65535,0>>>,TrFade<1000>>,EFFECT_RETRACTION>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
	InOutTrL<TrWipeSparkTip<White,250>,TrWipeInSparkTip<White,656>>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>>>
	*/
	() //, "assasin" 
},

// Seethe blade style.
{ "SEETHE;common", "tracks/JFO18.wav",
	StylePtr <MasterStyle>
/*
	StylePtr<Layers<
	AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,
	//Red audioflicker
	TransitionEffectL<TrConcat<TrFade<200>,AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,SwingSpeed<500>>,TrDelay<30000>,AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,SwingSpeed<500>>,TrFade<800>>,EFFECT_FORCE>,
	//Force effect, temporarily allows a swing effect where solid dark orange takes over the blade when swinging
	AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<315>>,
	//Unstable swing
	LockupTrL<Layers<
	AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
	//Responsive lockup
	ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	//Responsive lightning block
	Mix<Sin<Int<8>>,AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Bump<Int<0>,Int<6000>>>,AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Bump<Int<0>,Int<22000>>>>,
	//Timed "breathing" emitter flare - NOTE: Due to the way Proffie works, this isn't always "lined up" and might be slightly ahead or slightly behind the hum's breathing. To fix you can turn the saber off and back on until it's lined up. The timing is right, but the code runs in the background even after turning the saber off so it doesn't always start "on time."
	//AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Bump<Int<0>,Scale<TwistAngle<>,Int<3000>,Int<20000>>>>,
	//Alternate twist responsive "breathing" emitter flare, twist the hilt in time with the breathing in a meditative way, or time it while going through different stances, etc.
	ResponsiveStabL<Orange>,
	//Responsive stab
	EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
	//Multi-blast, blaster reflect cycles through different responsive effects
	ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
	//Responsive clash
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	//Drag
	LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	//Responsive melt
	EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
	//Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
	InOutTrL<TrWipe<2650>,TrWipeIn<1375>>,
	//Wipe out ignition, wipe in retraction
	//TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
	//TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
	//Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
	//On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
	>> */
	() //, "seethe" 
},

/*
// Exalted blade style.
{ "EXALTED;common", "tracks/JFO11.wav",
	StylePtr<Layers<
	Mix<SwingSpeed<400>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb16<65535,8357,0>>,RotateColorsX<Variation,Rgb16<42307,1982,0>>>>,
	//Unstable red with blood orange audioflicker swing effects
	AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,0,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
	//Hard swings cause red to ripple up the blade
	LockupTrL<Layers<
	AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
	//Responsive lockup
	ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	//Responsive lightning block
	AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<2000>,Int<3500>>,Int<-3000>>>,
	//Sparking emitter flare
	ResponsiveStabL<Orange>,
	//Responsive stab
	EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
	//Multi-blast, blaster reflect cycles through different responsive effects
	ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
	//Responsive clash
	TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb16<65535,8357,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<60,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>>,TrFade<1200>>,EFFECT_IGNITION>,
	//Unstable fiery ignition effect
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	//Drag
	LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	//Responsive melt
	EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
	//Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
	InOutTrL<TrWipeSparkTip<White,250>,TrColorCycle<1450>,Black>,
	//Spark tip ignition, cycle down retraction
	//TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
	//TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
	//Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
	//On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
	//,TransitionEffectL<TrConcat<TrFade<100>,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,500>,Bump<Int<0>,Int<6000>>>,TrBoing<600,9>>,EFFECT_PREON>
	//Optional Clickity Preon, I recommend using Analog's preon :) Make sure to leave the comma at the beginning in if you're using the on demand battery level
	>>() //, "exhalted" 
},
// */

/*
// Party blade style.
{ "party;common", "tracks/meco.wav",
   // StylePtr<Layers<StyleFire<Gradient<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Magenta>>,Red,0,3,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrSmoothFade<600>>,EFFECT_LOCKUP_END>,ResponsiveLockupL<Strobe<White,BrownNoiseFlicker<White,Red,300>,50,1>,TrConcat<TrInstant,White,TrFade<400>>,TrFade<100>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Scale<SwingSpeed<100>,Int<10000>,Int<14000>>>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeIn<500>,Black>,TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>>>(),"party"},
	StylePtr<Layers<StyleFire<StripesX<Int<3000>,Scale<TwistAngle<>,Int<-500>,Int<0>>,Red,Orange,Yellow,Green,Blue,Magenta>,StripesX<Int<3000>,Scale<TwistAngle<>,Int<-500>,Int<0>>,Tomato,OrangeRed,Orange,Yellow,SteelBlue,DeepPink>,0,3,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,White>>,TrFade<1200>>,EFFECT_RETRACTION>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,500>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<3000>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<3000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<2000>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>>>
	() //, "party" 
},
*/

// Nightsister blade style.
{ "Mother;common", "tracks/",
	StylePtr <
		Layers <
			// On effects
			StripesX <
				Sin<
					Int<12>,
					Int<3000>,
					Int<7000>
				>,
				Scale<
					SwingSpeed<100>,
					Int<75>,
					Int<125>
				>,
				StripesX <
					Sin<
						Int<10>,
						Int<1000>,
						Int<3000>
					>,
					Scale<
						SwingSpeed<100>,
						Int<75>,
						Int<100>
					>,
					Pulsing<
						RotateColorsX<Variation, Green>,
						RotateColorsX<Variation, Rgb<0,20,0>>,
						1200
					>,
					Mix<
						SwingSpeed<200>,
						RotateColorsX<Variation, Rgb<0,120,0>>,
						Black
					>
				>,
				RotateColorsX<Variation, Rgb<0,60,0>>,
				Pulsing<
					RotateColorsX<Variation, Rgb<0,50,0>>,
					StripesX<
						Sin<
							Int<10>,
							Int<2000>,
							Int<3000>
						>,
						Sin<
							Int<10>,
							Int<75>,
							Int<100>
						>,
						RotateColorsX<Variation, Green>,
						RotateColorsX<Variation, Rgb<0,96,0>>
					>,
					2000
				>,
				Pulsing<
					RotateColorsX<Variation, Rgb<0,128,0>>,
					RotateColorsX<Variation,Rgb<0,5,0>>,
					3000
				>
			>,
			AlphaL<
				StyleFire<
					RotateColorsX<Variation, Green>,
					RotateColorsX<Variation, Rgb<0,2,0>>,
					0,
					1,
					FireConfig<10, 2000, 2>,
					FireConfig<10, 2000, 2>,
					FireConfig<10, 2000, 2>,
					FireConfig<0, 0, 25>
				>,
				Int<10000>
			>,

			// Lockup
			ResponsiveLockupL < 
		//	LockupTrL <
				Layers <
					AlphaL<
						AudioFlickerL<White>,
						Bump<
							Scale<
								BladeAngle<>,
								Scale<
									BladeAngle<0, 16000>,
									Int<4000>,
									Int<26000>
								>,
								Int<6000>
							>,
							Scale<
								SwingSpeed<100>,
								Int<14000>,
								Int<18000>
							>
						>
					>,
					AlphaL<
						White,
						Bump<
							Scale<
								BladeAngle<>,
								Scale<
									BladeAngle<0, 16000>,
									Int<4000>,
									Int<26000>
								>,
								Int<6000>
							>,
							Int<10000>
						>
					>
				>,
				TrConcat<
					TrInstant,
					White,
					TrFade<400>
				>,
				TrConcat<
					TrInstant,
					White,
					TrFade<400>
				>
			//	SaberBase::LOCKUP_NORMAL
			>,

			//Lightning Block
			ResponsiveLightningBlockL <
				Strobe<
					White,
					AudioFlicker<White, Blue>,
					50,
					1
				>,
				TrConcat<
					TrInstant,
					AlphaL<
						White,
						Bump<
							Int<12000>,
							Int<18000>
						>
					>,
					TrFade<200>
				>,
				TrConcat<
					TrInstant,
					HumpFlickerL<
						AlphaL<
							White,
							Int<16000>
						>,
						30
					>,
					TrSmoothFade<600>
				>
			>,

			// Stab
			ResponsiveStabL<
				Red,
				TrWipeIn<600>,
				TrWipe<600>
			>,

			// Blaster bolt
			/*
			ResponsiveBlastFadeL<
				White,
				Scale<
					SwingSpeed<200>,
					Int<8000>,
					Int<16000>
				>,
				Int<400>
			>,
			*/
			EffectSequence<
				EFFECT_BLAST,
				ResponsiveBlastL<
					Rgb<200, 255, 200>,
					Int<400>,
					Scale<
						SwingSpeed<200>,
						Int<100>,
						Int<400>
					>,
					Int<400>
				>,
				LocalizedClashL<
					Rgb<200, 255, 200>,
					80,
					30,
					EFFECT_BLAST
				>,
				ResponsiveBlastWaveL<
					Rgb<200, 255, 200>,
					Scale<
						SwingSpeed<400>,
						Int<500>,
						Int<200>
					>,
					Scale<
						SwingSpeed<400>,
						Int<100>,
						Int<400>
					>
				>,
				BlastL<
					Rgb<200, 255, 200>,
					200,
					200
				>,
				ResponsiveBlastFadeL<
					Rgb<200, 255, 200>,
					Scale<
						SwingSpeed<400>,
						Int<6000>,
						Int<12000>
					>,
					Scale<
						SwingSpeed<400>,
						Int<400>,
						Int<100>
					>
				>,
				ResponsiveBlastL<
					Rgb<200, 255, 200>,
					Scale<
						SwingSpeed<400>,
						Int<400>,
						Int<100>
					>,
					Scale<
						SwingSpeed<400>,
						Int<200>,
						Int<100>
					>,
					Scale<
						SwingSpeed<400>,
						Int<400>,
						Int<200>
					>
				>
			>,

			// Clash
			ResponsiveClashL<
				White,
				TrInstant,
				TrFade<400>,
				Scale<
					BladeAngle<0, 16000>,
					Int<4000>,
					Int<26000>
				>,
				Int<6000>,
				Int<20000>
			>,

			// Lockup Tip Drag
			ResponsiveDragL <
			//LockupTrL<
				AlphaL<
					BrownNoiseFlickerL<
						White,
						Int<300>
					>,
					SmoothStep<
						Int<30000>,
						Int<5000>
					>
				>,
				TrWipeIn<400>,
				TrFade<300>
				//SaberBase::LOCKUP_DRAG
			>,

			// Lockup Melt
			ResponsiveMeltL <
			//LockupTrL<
				AlphaL<
					Mix<
						TwistAngle<>,
						Red,
						Orange
					>,
					SmoothStep<
						Int<28000>,
						Int<5000>
					>
				>,
				TrWipeIn<600>,
				TrFade<300>
				//SaberBase::LOCKUP_MELT
			>,

			// In/Out Effect
			InOutTrL<
				TrWipeSparkTip<
					AlphaL<
						Rgb<127, 200, 127>, 
						BladeAngle<>
					>,
					300
				>,
				TrWipeInSparkTipX<
					AlphaL<
						Rgb<15, 127, 15>, 
						BladeAngle<>
					>,
					RetractionTime<0>
				>,
				Black
			>,

			// PreOn effect
			/*
			TransitionEffectL<
				TrConcat<
				//	TrWipe<300>,
					TrFade<2000>,
					AlphaL<
						HumpFlickerL<Red, 10>,
						Bump<
							Int<0>,
							Int<6000>
						>
					>,
					TrFade<2950>,
					AlphaL<
						HumpFlickerL<Orange, 15>,
						Bump<
							Int<0>, 
							Int<10000>
						>
					>,
					TrFade<3000>,
					AlphaL<
						HumpFlickerL<Green, 20>,
						Bump<
							Int<0>, 
							Int<20000>
						>
					>,
					TrBoing<1000,3>
				>,
				EFFECT_PREON
			>,
			*/

			TransitionEffectL<
				TrConcat<
					TrInstant,
					Black,
					TrWipeX<
						WavLen<EFFECT_PREON>
					>,
					Mix<
						NoisySoundLevel,
						Rgb<0, 31, 0>,
						AlphaL <
							AudioFlicker<
								RotateColorsX<Variation, Rgb<0,31,0>>,
								RotateColorsX<Variation, Rgb<0,15,0>>
							>,
							Int<100>
						>
					>,
					TrInstant
			//		TrDelayX<
			//			WavLen<EFFECT_PREON>
			//		>
			//		AlphaL<
			//			RotateColorsX<Variation, Rgb<0, 63, 0>>,
			//			SmoothStep<
			//				Int<28000>,
			//				Int<5000>
			//			>
			//		>
					/*
					AlphaL<
						HumpFlickerL<
							RotateColorsX<Variation, Green>, 
							10
						>, 
						Bump<
							Int<0>, 
							Int<10000>
						>
					>, 
					TrFade<350>, 
					AlphaL<
						HumpFlickerL<
							RotateColorsX<Variation, Green>, 
							15
						>, 
						Bump<
							Int<0>, 
							Int<6000>
						>
					>, 
					TrFade<450>, 
					AlphaL<
						HumpFlickerL<
							RotateColorsX<Variation, Green>, 
							20
						>, 
						Bump<
							Int<0>, 
							Int<8000>
						>
					>, 
					TrFade<500>, 
					AlphaL<
						HumpFlickerL<
							RotateColorsX<Variation, Green>,
							25
						>, 
						Bump<
							Int<0>, 
							Int<14500>
						>
					>, 
					TrBoing<150, 1>,
					TrDelayX<
						WavLen<EFFECT_PREON>
					>
					*/
				>,
				EFFECT_PREON
			>,

			// Ignition effect
			TransitionEffectL<
				TrConcat<
					TrInstant, 
					AlphaL <
						AudioFlicker<
							RotateColorsX<Variation, Rgb<0, 63, 0>>, 
							RotateColorsX<Variation, Rgb<0, 31, 0>>
						>,
						Int<16384> //50%
					>,
					TrExtendX<
						Int<500>,
						TrWipe<500>
					>,
					AlphaL <
						Stripes<
							3000, 
							-3500, 
							Rgb<63, 200, 63>, 
							RandomPerLEDFlicker<
								Rgb<0, 63, 0>, 
								Black
							>, 
							BrownNoiseFlicker<
								Rgb<63, 255, 63>, 
								Rgb<0, 30, 0>, 
								200
							>, 
							RandomPerLEDFlicker<
								Rgb<31, 80, 31>, 
								Rgb<0, 30, 0>
							>
						>,
						NoisySoundLevel
					>, 
					TrFade<1500>
				>, 
				EFFECT_IGNITION
			>,

			// Retraction effect
			TransitionEffectL <
				TrConcat <
					TrInstant,
					TrWipeInX< RetractionTime<0>>,
					AlphaL<
						Style1_SmokeBlade,	//Green,
						Bump<
							Int<0>,
							Int<16000>
						>
					>,
					TrFade<2000>,
					AlphaL<
						Rgb<0, 63, 0>,
						Bump<
							Int<0>,
							Int<14000>
						>
					>,
					TrFade<1500>,
					AlphaL<
						Orange,
						Bump<
							Int<0>,
							Int<8000>
						>
					>,
					TrFade<1000>,
					AlphaL<
						Red,
						Bump<
							Int<0>,
							Int<6000>
						>
					>,
					TrFade<500>
				> ,
				EFFECT_RETRACTION
			>,

			// Battery Monitor on Boot
			BatteryLevelOnBoot,

			// Battery level on font change
			BatteryLevelOnFontChange,

			// Battery level
			BatteryLevelOnDemand

		>
	>
	() //, "mother"
},

{ "Noble;common", "tracks/Spoiler.wav",
	StylePtr <MasterStyle>
	() //, "noble"
},

{ "Mercenary;common", "common/tracks/venus.wav",
	StylePtr <MasterStyle>
/*
   StylePtr < Layers<

	//Base Fett263 Smoke Blade style
	StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<15,14,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,87,0>>,Black>>,RotateColorsX<Variation,Rgb<40,40,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,33,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<60,58,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,88,0>>,RotateColorsX<Variation,Rgb<5,5,0>>,3000>>,

	//Underlying Fett263 Smoke Blade Fire layer
	AlphaL<StyleFire<RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<2,2,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,

	//Fett263 Ripple swing effect
	AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<44,42,0>>,Pulsing<RotateColorsX<Variation,Rgb<22,20,0>>,Black,800>>,SwingSpeed<375>>,

	//Fett263 Bright hard swing effect
	AlphaL<RotateColorsX<Variation,LemonChiffon>,Scale<IsLessThan<SwingSpeed<675>,Int<13600>>,Scale<SwingSpeed<750>,Int<-17300>,Int<32768>>,Int<0>>>,

	//Fett263 Responsive Intensity Lockup
	LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>,RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>>,
	TrConcat<TrExtend<50,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,White>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrExtend<3000,TrFade<300>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrFade<3000>>,
	TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,White>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,SaberBase::LOCKUP_NORMAL>,

	//Fett263 Responsive Lightning Block
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,

	//Fett263 Sparking Emitter Flare
	AlphaL<RotateColorsX<Variation,LemonChiffon>,SmoothStep<Scale<SlowNoise<Int<2750>>,Int<1750>,Int<3750>>,Int<-4000>>>,

	//Responsive Stab
	ResponsiveStabL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,DeepPink>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,50>>,TrFadeX<Percentage<WavLen<EFFECT_STAB>,50>>>,

	//Fett263 Multi-blast, blaster reflect cycles through different responsive effects
	EffectSequence<EFFECT_BLAST,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<RgbArg<BLAST_COLOR_ARG,White>,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<RgbArg<BLAST_COLOR_ARG,White>,200,200>,ResponsiveBlastFadeL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,

	//Fett263 Real Clash
	Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,White>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,

	//Fett263 Unstable bright ignition effect
	TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<100,100,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,60,80>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<110,115,140>>,RotateColorsX<Variation,Rgb<60,60,80>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,128,128>>,RotateColorsX<Variation,Rgb<60,60,80>>>>,TrFadeX<Percentage<WavLen<>,65>>>,EFFECT_IGNITION>,

	//Fett263 Bright Humpflicker retraction effect
	TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFadeX<Percentage<WavLen<>,125>>>,EFFECT_RETRACTION>,

	//Fett263 Intensity Drag
	LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,27500>,Int<5000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,29250>,Int<5000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,

	//Fett263 Responsive Intensity Melt
	LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<6000>>>,TrConcat<TrWipeIn<100>,AlphaL<Red,SmoothStep<Int<29000>,Int<8000>>>,TrExtend<2000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<29000>,Int<8000>>>,TrFade<3000>>,TrFade<250>,SaberBase::LOCKUP_MELT>,

	//Fett263 Power Save, if using Fett263's prop file hold AUX and click PWR while ON (pointing up) to dim blade in 25% increments.
	EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,

	//Fett263 White Spark Tip ignition and Color Cycle retraction
	InOutTrL<TrJoin<TrWipeX<Percentage<WavLen<EFFECT_IGNITION>,8>>,TrWaveX<White,Percentage<WavLen<EFFECT_IGNITION>,25>,Int<300>,Percentage<WavLen<EFFECT_IGNITION>,8>,Int<0>>>,TrColorCycle<950,7500>>,

	//Fett263 optional/alternate Passive Battery Monitor: on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
	//TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
	//TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,

	//Fett263 On-Demand Battery Level: if using Fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,

	//Absorby charge-up preon
	TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,33>>,TransitionLoopL<TrJoin<TrWipeIn<142>,TrSparkX<RotateColorsX<Variation,LemonChiffon>,Int<425>,Int<142>,Int<32768>>>>,TrDelayX<Percentage<WavLen<>,67>>>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<>,33>,Percentage<WavLen<>,67>,Int<0>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,HotPink>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,LightPink>,RotateColorsX<Variation,LemonChiffon>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,DeepPink>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Yellow>>>,RotateColorsX<Variation,LemonChiffon>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-350>,Int<17500>>,Int<-4000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Sin<Int<10>,Int<16500>,Int<14500>>,Sin<Int<7>,Int<10500>,Int<9500>>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>
	>> */
	() //, "mercenary"
},

/*
{ "Coda;common", "tracks/Runar.wav",
	StylePtr < Layers <
		Mix<Sin<Int<3>>,AudioFlicker<RotateColorsX<Variation,DodgerBlue>,Stripes<5000,-90,RotateColorsX<Variation,Rgb<0,55,165>>,RotateColorsX<Variation,Rgb<0,85,115>>,RotateColorsX<Variation,Rgb<0,65,145>>,RotateColorsX<Variation,Rgb<0,30,185>>>>,AudioFlicker<RotateColorsX<Variation,Rgb<0,155,255>>,Stripes<5000,-90,RotateColorsX<Variation,Rgb<0,95,170>>,RotateColorsX<Variation,Rgb<0,115,215>>,RotateColorsX<Variation,Rgb<0,145,145>>,RotateColorsX<Variation,Rgb<0,65,225>>>>>,
		//Rotates   ^3 times per minute between DodgerBlue and DeepSkyBlue with subtle Cyan/Blue audioflicker
		//AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,95,195>>>,
		//Alternate DeepSkyBlue with very subtle audioflicker
		AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black,300>,SwingSpeed<400>>,
		//Unstable swing
		AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,Black,RotateColorsX<Variation,DeepSkyBlue>,Black>,SwingSpeed<525>>,
		//Unstable ripple swing
		LockupTrL<Layers<
		AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
		AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<875>>,SaberBase::LOCKUP_NORMAL>,
		//Responsive lockup effect with screeching humpflicker endlock
		//LockupTrL<Layers<
		//AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
		//AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<4000>>,SaberBase::LOCKUP_NORMAL>,
		//Alternate standard lockup
		ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
		//Responsive lightning block
		ResponsiveStabL<RotateColorsX<Variation,Yellow>>,
		//Responsive stab
		//ResponsiveStabL<Red>,
		//Alternate responsive stab, no color change
		EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
		//Multi-blast, blaster reflect cycles through different responsive effects
		//ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
		//Alternate responsive blast
		ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
		//Responsive Clash
		//ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
		//Alternate white clash
		TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<90,180,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,26,60>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<90,180,255>>,RotateColorsX<Variation,Rgb<0,26,60>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,42,128>>,RotateColorsX<Variation,Rgb<0,26,60>>>>,TrFade<400>,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<90,180,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,26,60>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<90,180,255>>,RotateColorsX<Variation,Rgb<0,26,60>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,42,128>>,RotateColorsX<Variation,Rgb<0,26,60>>>>,TrFade<450>,HumpFlickerL<AlphaL<RotateColorsX<Variation,Rgb<90,180,255>>,Int<19000>>,25>,TrFade<2875>>,EFFECT_IGNITION>,
		//Stabilize ignition effect
		TransitionEffectL<TrConcat<TrFade<1125>,RotateColorsX<Variation,Rgb<90,180,255>>,TrInstant>,EFFECT_RETRACTION>,
		//Slow brighten retraction effect
		LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
		//Drag
		LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
		//Responsive melt
		EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
		//Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
		InOutTrL<TrWipe<500>,TrWipeIn<1125>>,
		//Standard ignition/retraction
		//TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
		//TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
		//Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
		TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
		//On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
		TransitionEffectL<TrConcat<TrFade<450>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,10>,Bump<Int<0>,Int<3000>>>,TrFade<350>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,15>,Bump<Int<0>,Int<5000>>>,TrFade<450>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,20>,Bump<Int<0>,Int<7000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,25>,Bump<Int<0>,Int<10500>>>,TrBoing<150,1>>,EFFECT_PREON>
		//Overload preon effect
	>> () //, "coda" 
},

/*
{ "Ra;common", "tracks/fates.wav",
	   StylePtr < Layers <
		AudioFlicker<RotateColorsX<Variation,Rgb16<65535,0,38402>>,RotateColorsX<Variation,Rgb<180,0,120>>>,
	   //Magenta audioflicker
	   AlphaL<AudioFlickerL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<230,0,35>>,Black>,Black,RotateColorsX<Variation,Rgb<230,0,35>>,Black>>,SwingSpeed<350>>,
	   //Ripple audioflicker swing
	   //AlphaL<AudioFlickerL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<230,0,35>>,Black,300>>,SwingSpeed<300>>,
	   //Alternate unstable audioflicker swing
	   LockupTrL<Layers<
		 AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
		 AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
	   //Responsive lockup
	   ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	   //Responsive lightning block
	   AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3000>>,Int<-4000>>>,
	   //Sparking emitter flare
	   ResponsiveStabL<Red>,
	   //Responsive stab
	   EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
	   //Multi-blast, blaster reflect cycles through different responsive effects
	   ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
	   //Responsive clash
	   LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	   //Drag
	   LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	   //Responsive melt
	   EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
	   //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
	   InOutTrL<TrColorCycle<3000,3000,0>,TrColorCycle<1250>>,
	   //Color cycle ignition and retraction
	   //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
	   //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
	   //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
	   TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
	   //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
	   >> () //, "ra" 
},

/*
{ "Endure;common", "tracks/",
	StylePtr < Layers <
		Mix<Scale<BladeAngle<19000>,Int<32768>,Int<0>>,Blinking<HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>,RotateColorsX<Variation,Red>,918,900>,HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>>,
		//Heart beat humpflicker - point the blade up to blend in a subtle heart beat - NOTE: Due to the way Proffie works, this isn't always "lined up" and might be slightly ahead or slightly behind the heart beat. Personally, I don't mind this, as it seems like it's just part of the beat. But if you want to fix this you can either change to another preset then change back or turn the saber off and back on until it's lined up.
		//HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,Rgb16<11585,0,0>>,35>,
		//Alternate humpflicker, no heart beat
		TransitionEffectL<TrConcat<TrDelay<1200>,HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>,TrFade<450>,RotateColorsX<Variation,Rgb16<26858,591,0>>,TrFade<300>,RotateColorsX<Variation,Rgb16<65535,11439,0>>,TrFade<50>>,EFFECT_FORCE>,
		//Charge up Force effect. I recommend commenting this out if you'll be using the included Quotes instead of Force sounds (Or wait for Proffie OS6!)
		AlphaL<AudioFlickerL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,Black,RotateColorsX<Variation,Red>,Black>>,SwingSpeed<265>>,
		//Audio responsive unstable/stripey swing effect
		AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<350>>,
		//Unstable swing effect
		AlphaL<AlphaL<Stripes<2000,-3750,RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,0,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<14500>,Int<16000>>>,
		//Bright ripple hard swing effect - swing hard enough to trigger an accent swing and blood orange ripples up the blade
		LockupTrL<Layers<
		AlphaL<AudioFlickerL<Rgb<255,150,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
		AlphaL<Moccasin,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<650>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Black,300>,TrFade<1000>,AudioFlickerL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>>,TrFade<2675>>,SaberBase::LOCKUP_NORMAL>,
		//Responsive lockup effect with growly audio responsive heart beat endlock
		//LockupTrL<Layers<
		//AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
		//AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<4000>>,SaberBase::LOCKUP_NORMAL>,
		//Alternate standard lockup
		ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
		//Responsive lightning block
		AlphaL<Mix<Scale<BladeAngle<19000>,Int<32768>,Int<0>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<1750>,Int<4125>>,Int<-4000>>>,
		//Responsive flame emitter effect, point the blade up to speed up the flame
		//AlphaL<StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<2000>,Int<4000>>,Int<-4000>>>,
		//Alternate non-responsive flame emitter effect
		ResponsiveStabL<Orange>,
		//Responsive stab
		EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
		//Multi-blast, blaster reflect cycles through different responsive effects
		//ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
		//Alternate responsive blast
		ResponsiveClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
		//Responsive Clash
		//ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
		//Alternate white clash
		TransitionEffectL<TrConcat<TrInstant,Stripes<1900,-2350,RotateColorsX<Variation,Rgb16<65535,5115,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,8357,0>>,RotateColorsX<Variation,Orange>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<75,0,0>>>>,TrFade<2350>>,EFFECT_IGNITION>,
		//Unstable ripple ignition effect
		TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb16<65535,1899,0>>,40>,TrFade<1750>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,1899,0>>,Black,300>,TrInstant>,EFFECT_RETRACTION>,
		//Retraction effect, bright humpflicker fades to unstable
		LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
		//Drag
		LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
		//Responsive melt
		EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
		//Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
		InOutTrL<TrJoin<TrWipe<2000>,TrWaveX<White,Int<2150>,Int<400>,Int<2000>,Int<0>>>,TrJoin<TrWipeIn<1750>,TrWaveX<White,Int<1750>,Int<400>,Int<1750>,Int<32768>>>>,
		//Spark tip ignition/retraction
		//InOutTrL<TrWipe<2000>,TrWipeIn<1750>>,
		//Alternate standard ignition/retraction
		TransitionEffectL<TrConcat<TrDelay<1750>,AlphaL<Mix<Trigger<EFFECT_RETRACTION,Int<4250>,Int<6000>,Int<2500>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<14386,0,0>>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<NoisySoundLevel,Int<-1125>,Int<20000>>,Int<-4000>>>,TrDelay<5000>>,EFFECT_RETRACTION>,
		//Audio responsive cooldown retraction effect
		//TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
		//TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
		//Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
		TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
		//On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
		TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<1750>,Int<250>,Int<3000>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<14386,0,0>>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<25000>>,Int<-4000>>>,TrDelay<2000>>,EFFECT_PREON>,
		//Audio responsive charge-up preon effect
		TransitionEffectL<TrConcat<TrDelay<1150>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<125>,Int<350>,Int<315>,Int<0>>>,TrDelay<850>>,EFFECT_PREON>
		//Ripple out preon effect
		>> () //, "endure"
},
*/

/*
{ "Staff;common", "tracks/fates",
	StylePtr<Layers<StyleFire<Strobe<RotateColorsX<Variation,Rgb<95,0,210>>,Strobe<Rgb<100,100,150>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black>,50,1>,100,1>,RotateColorsX<Variation,Rgb<23,0,65>>,0,5,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>,FireConfig<2,1000,5>>,LockupTrL<Layers<AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<200>,Int<8000>,Int<16000>>,Int<400>>,ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipe<300>,TrWipeInX<RetractionTime<0>>,Black>>>
	() //, "staff"
},
*/

{ "Splinter;common", "tracks/",
	StylePtr<MasterStyle>
	() //, "splinter"
},

{ "Second;common", "tracks/JFO19.wav",
	StylePtr<MasterStyle>
	() //, "splinter"
}

/*
{ "Deadlink;common", "tracks/",

	StylePtr<Layers<
	HumpFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<150,0,150>>,50>,
	//Magenta HumpFlicker
	AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb16<12482,0,18076>>,Pulsing<RotateColorsX<Variation,Rgb<10,0,26>>,Black,800>>,SwingSpeed<350>>,
	//Ripple swing effect
	//AlphaL<AudioFlickerL<Stripes<2500,-3000,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb16<12482,0,18076>>,Pulsing<RotateColorsX<Variation,Rgb<10,0,26>>,Black,800>>>,SwingSpeed<300>>,
	//Alternate audioflicker ripple swing effect
	LockupTrL<Layers<
	AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
	//Responsive lockup
	ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	//Responsive lightning block
	AlphaL<RotateColorsX<Variation,Rgb16<33124,0,65535>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3500>>,Int<-4000>>>,
	//Sparking emitter flare
	ResponsiveStabL<Red>,
	//Responsive stab
	EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
	//Multi-blast, blaster reflect cycles through different responsive effects
	ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
	//Responsive clash
	TransitionEffectL<TrConcat<TrDelay<875>,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,0,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,0,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<250>,HumpFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<80,0,80>>,50>,TrFade<400>,Stripes<3000,-3500,RotateColorsX<Variation,DeepPink>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,0,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<1500>>,EFFECT_IGNITION>,
	//Unstable ignition effect
	TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<180,60,255>>,40>,TrFade<2000>>,EFFECT_RETRACTION>,
	//Bright HumpFlicker retraction effect
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	//Drag
	LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	//Responsive melt
	EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
	//Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
	InOutTrL<TrConcat<TrWipeIn<200>,RandomBlink<30000,RotateColorsX<Variation,Rgb16<65535,13655,65535>>>,TrWipeIn<200>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,Int<1000>,Int<6000>>,Int<-3000>>,Black,RotateColorsX<Variation,Rgb16<65535,13655,65535>>>,TrDelay<400>,Mix<SmoothStep<Int<4000>,Int<-3000>>,Black,White>,TrWipe<175>>,TrColorCycle<2000>>,
	//Lightning strike ignition, cycle down retraction
	//TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
	//TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
	//Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
	//On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
	>>() //, "deadlink"
},
*/

/*
{ "Volatile;common", "tracks/",

	StylePtr<Layers<
	Mix<Sin<Int<1>>,AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>>,
	//Rotates   ^ 1 time per minute between blue and green audioflicker
	EffectSequence<EFFECT_FORCE,AlphaL<Mix<Sin<Int<1>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>,AlphaL<Mix<Sin<Int<2>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>>,
	//Force toggleable swing effect - switches betw^een unstable blue and green that cycle twice as fast as the base layer (so the blue and green don't always match up with the base layer, allowing for multiple mixes of blue/green) and unstable blue and green that match the base layer                                                                                                                                                                                                                             ^
	//AlphaL<Mix<Sin<Int<2>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>,
	//AlphaL<Mix<Sin<Int<2>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,300>,SwingSpeed<400>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Green>,Black,300>,SwingSpeed<400>>>,SwingSpeed<400>>,
	//Alternate swing    ^ Rotates 2 times per minute between unstable ripple blue and green, so the blue and green don't always match up with the base layer, allowing for multiple mixes of blue/green
	//AlphaL<Mix<Sin<Int<1>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>,
	//AlphaL<Mix<Sin<Int<1>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,300>,SwingSpeed<400>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Green>,Black,300>,SwingSpeed<400>>>,SwingSpeed<400>>,
	//Alternate swing    ^ Rotates 1 time per minute between unstable ripple blue and green, matching the base layer
	LockupTrL<Layers<
	AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<TransitionEffect<NavajoWhite,Rgb<255,225,0>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
	//Responsive lockup
	ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	//Responsive lightning block
	ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,
	//Responsive stab
	EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
	//Multi-blast, blaster reflect cycles through different responsive effects
	ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
	//Responsive clash
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	//Drag
	LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	//Responsive melt
	EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
	//Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
	InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<2000>>,
	//Spark tip ignition, wipe in retraction
	//TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
	//TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
	//Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	//On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<3000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,778,22863>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Blue>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Cyan>>>,RotateColorsX<Variation,Green>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-2500>,Int<17500>>,Int<-4000>>>,TrDelay<6500>>,EFFECT_PREON>
	//Preon, reacts to sound level
	>>() //, "volatile"
},
*/

/*
// Blank
{ "WHITE", "tracks/",
				
	StylePtr<
		Layers<
			Black,
			LockupTrL<
				Layers<
					AlphaL<
						AudioFlickerL<White>,
						Bump<
							Scale<
								BladeAngle<>,
								Scale<
									BladeAngle<0, 16000>,
									Int<4000>,
									Int<26000>
								>,
								Int<6000>
							>,
							Scale<
								SwingSpeed<100>,
								Int<14000>,
								Int<18000>
							>
						>
					>,
					AlphaL<
						White,
						Bump<
							Scale<
								BladeAngle<>,
								Scale<
									BladeAngle<0, 16000>,
									Int<4000>,
									Int<26000>
								>,
								Int<6000>
							>,
							Int<10000>
						>
					>
				>,
				TrConcat<
					TrInstant,
						White,
						TrFade<400>
					>,
					TrConcat<
						TrInstant,
						White,
						TrFade<400>
					>,
					SaberBase::LOCKUP_NORMAL
				>,
		
				ResponsiveLightningBlockL<
					Strobe<
						White,
						AudioFlicker<
							White,
							Blue
						>,
						50,
						1
					>,
					TrConcat<
						TrInstant,
						AlphaL<
							White,
							Bump<
								Int<12000>,
								Int<18000>
							>
						>,
						TrFade<200>
					>,
					TrConcat<
						TrInstant,
						HumpFlickerL<
							AlphaL<
								White,
								Int<16000>
							>,
							30
						>,
						TrSmoothFade<600>
					>
				>,

				ResponsiveStabL<
					Orange,
					TrWipeIn<600>,
					TrWipe<600>
				>,

				ResponsiveBlastL<
					White,
					Int<400>,
					Scale<
						SwingSpeed<200>,
						Int<100>,
						Int<400>
					>,
					Int<400>
				>,

				ResponsiveClashL<
					White,
					TrInstant,
					TrFade<400>,
					Scale<
						BladeAngle<0, 16000>,
						Int<4000>,
						Int<26000>
					>,
					Int<6000>,
					Int<20000>
				>,

				LockupTrL<
					AlphaL<
						BrownNoiseFlickerL<
							White,
							Int<300>
						>,
						SmoothStep<
							Int<30000>,
							Int<5000>
						>
					>,
					TrWipeIn<400>,
					TrFade<300>,
					SaberBase::LOCKUP_DRAG
				>,

				LockupTrL<
					AlphaL<
						Mix<
							TwistAngle<>,
							Rgb<255,200,0>,
							DarkOrange
						>,
						SmoothStep<
							Int<28000>,
							Int<5000>
						>
					>,
					TrWipeIn<600>,
					TrFade<300>,
					SaberBase::LOCKUP_MELT
				>,

				InOutTrL<
					TrWipe<300>,
					TrWipeIn<500>,
					Black
				>
			>
		>
		()
},
*/

/*
// Battery Level
{ "WHITE;common", "tracks/fates.wav",
	&style_charging, "Battery/nLevel" 
}
*/


};

BladeConfig blades[] = {
 { 0, WS2811BladePtr<132, WS2811_ACTUALLY_800kHz | WS2811_GRB>(), CONFIGARRAY(presets) },
  };
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
/*Button AuxButton(BUTTON_AUX, auxPin, "aux");*/
#endif

