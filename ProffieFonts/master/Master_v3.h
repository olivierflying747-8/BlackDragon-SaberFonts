// Include common "using" layer styles from another file
#include "Common_Colors.h" // Color / color blend defines
#include "Common_Misc.h" // Misc common code and effects

#include "Common_Blade.h" // Blade effects, for STYLE_OPTION_ARG
#include "Common_Blade2.h" // Blade effects, for STYLE_OPTION2_ARG
#include "Common_Blade3.h" // Blade effects, for STYLE_OPTION3_ARG
#include "Common_Swing.h" // Swing effects for SWING_OPTION_ARG
#include "Common_Blast.h" // Blaster Effects
#include "Common_Lockup.h" // Lockup, Clash, Drag, Stab, Melt
#include "Common_PreOn.h" // PreOn effects for PREON_OPTION_ARG
#include "Common_Ignition.h" // Effects for IGNITION_OPTION_ARG
#include "Common_Retraction.h" // effects for RETRACTION_OPTION_ARG
#include "Common_PowerUp.h" // Effects for IGNITION_POWER_UP_ARG
#include "Common_PowerDown.h" // Effects for RETRACTION_COOL_DOWN_ARG
#include "Common_PostOff.h" // Effects for OFF_OPTION_ARG (They should really add a POSTOFF_OPTION_ARG...)
#include "Common_Specials.h" // Special Effects (for use one each for EFFECT_USER1 - EFFECT_USER8)

/* Based on Fett263 Static/Flicker (Primary Blade) OS6 Style, heavily modified (Added more options)
https://fett263.s3.us-east-2.amazonaws.com/fett263-proffieOS6-style-library.html#Static/Flicker
OS6.5 v1.0
This Style Contains ???? (alot) Unique Combinations
Style Options:
0: Static Color (Base Color)
1: AudioFlicker (Base Color, Alt Color)
2: RandomFlicker (Base Color, Alt Color)
3: Pulsing (Base Color, Alt Color)
4: Stripes blade (Base Color)
5: Stripes Slownoise (Base Color, Alt Color)
6: Unstable Blade (Base Color)
7: Fire Blade (Base Color)
8: Flicker Blade (Base Color)
9: Thunderstorm blade (Base Color, Alt Color)
10: Fett263 Smoke Blade style. (Base Color)
11: Glitchy / Broken blade. (Base Color)
12: Coda blade style w/ swing effects. (Base Color, Alt Color, Alt Color 2)
13: DarkSaber (Base Color, Alt Color)
14: Fire Pulse Blade (Interactive)
15: Smash blade
16: Staff blade
17: Ghostboster blade
18: Party Blade (No Colors, Rainbow)

--Effects Included--
STYLE_OPTION2_ARG options: // Secondary Blade Effects while on
0: Disabled
1: AudioFlicker (Alt Color 2)
2: RandomFlicker (Alt Color 2)
3: Pulsing (Alt Color 2)
4: BrownNoise Stripes (Alt Color 2)
5: HumpFlicker Random (Alt Color 2)
6: Waves (Alt Color, Alt Color 2)
7: Sparkles (Alt Color 2)
8: Fett263 FireBlade (Alt Color 2)
9: Fire (Alt Color, Alt Color 2)
10: Cylon (Alt Color 2)
11: Lightning flash (Alt Color 2)
12: Emitter Tip Flame (Alt Color 2)

STYLE_OPTION3_ARG options: // Tirtiary Blade Effects while on
0: Disabled
1: AudioFlicker (Alt Color 3)
2: RandomFlicker (Alt Color 3)
3: Pulsing (Alt Color 3)
4: BrownNoise Stripes (Alt Color 3)
5: HumpFlicker Random (Alt Color 3)
6: Waves (Alt Color2, Alt Color 3)
7: Sparkles (Alt Color 3)
8: Fett263 FireBlade (Alt Color 3)
9: Fire (Alt Color 2, Alt Color 3)
10: Cylon (Alt Color 3)
11: Lightning Flash (Alt Color 3)
12: Emitter Flare (Emiter Color)
13: Emitter Flare (Breathing) (Emitter Color)
14: Emitter Pulse (Alt Color 3)
15: Blade Spark (Interactive, Alt Color 3)

Swing Effect Options:
0: Disabled
1: Force Pulse
2: Force Aura
3: AudioFlicker
4: Sparkle
5: Fire
6: Fett263's Swing Effect
7: Unstable Swing effect
8: Power Buildup
9: Fireball
10: Lightning

Preon Effect Options: 
0: Disabled
1: Overload (PreOn Color)
2: Sparking (PreOn Color)
3: Broken Ignition
4: Emitter Warm up
5: Faulty Ignition
6: Blade Pre-Light up

PostOff Effect Options:
0: Disabled
1: Emitter Cooldown (PostOff Color)

Ignition Effect Options: 
0: None
1: Standard Ignition 
2: Dual Mode Wipe (Up = Fast)
3: SparkTip Ignition
4: Center Wipe
5: Color Cycle
6: Lightning Strike

Retraction Effect Options:
0: None
1: Standard Retraction
2: Dual Mode Wipe In (Up = Fast)
3: SparkTip Retraction
4: Center Wipe
5: Color Cycle
6: Glitch off

PowerUp Effect Options:
0: Disabled
1: Glitch on / Flash
2: Power Surge
3: Powerup Flash Fade
4: Unstable Power Up Forward
5: Power Burst Forward
6: Unstable Bright
7: Stabalize

CoolDown Effect Options:
0: Disabled
1: Power Flash
2: Power Burst Reverse
3: Unstable Cool Down Reverse
4: Bright Humpflicker
5: Smoke Blade Reverse + Emitter Cooldown
6: Emitter Cooldown (for fonts with no PostOff .wav files)

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
		// Option 0: Static Color (BASECOLOR)
		Style1_Static,
		// Option 1: Audioflicker (BASECOLOR, ALTCOLOR)
		Style1_AudioFilter,
		// Option 2: Random Flicker (BASECOLOR, ALTCOLOR)
		Style1_RandomFlicker,
		// Option 3: Pulsing Blade (BASECOLOR, ALTCOLOR)
		Style1_Pulsing,
		// Option 4: Stripes (BASECOLOR)
		Style1_Stripes,
		// Option 5: Stripes SlowNoise (BASECOLOR, ALTCOLOR)
		Style1_StripesX_SlowNoise,
		// Option 6: Unstable Stripes (BASECOLOR)
		Style1_Stripes_RandomPerLEDFlicker,
		// Option 7: Fire blade (BASECOLOR)
		Style1_FireBlade,
		// Option 8: BrownNoise (BASECOLOR)
		Style1_BrownNoiseFlicker,
		// Option 9: Thunderstorm (BASECOLOR, ALTCOLOR)
		Style1_ThunderstormBlade,
		// Option 10: Base Fett263 Smoke Blade style (BASECOLOR)
		Style1_SmokeBlade,
		// Option 11: Flickery / Broken blade (BASECOLOR)
		Style1_FlickerBlade,
		// Option 12: Fire Blade with Swing Speed and Fire Tip (BASECOLOR)
		Style1_FireTipBlade,
		// Option 13: blablabla
		Style1_FireTipBase,

		// Option 12: Coda (BASECOLOR, ALTCOLOR, ALTCOLOR2)
		CodaBladeStyle,
		// Option 13: Darksaber blade (BASECOLOR, ALTCOLOR)
		DarkSaberStyle,
		// Option 14: Fireblade Interactive Pulse
		Style1_FirePulseInteractive,
		// Option 15: Smash Blade (special colors)
		Style1_SmashBlade,
		// Option 16: ElectroStaff (BASECOLOR)
		Style1_StaffBlade,
		// Option 17: Ghostbuster (BASECOLOR, ALTCOLOR, ALTCOLOR2)
		Style1_GhostBusterBlade, 

		// Option 18: Party Blade (special colors)
		Style1_PartyBlade
	>,

	// Secondary blade Styles
	ColorSelect<
		IntArg<STYLE_OPTION2_ARG, 0>,
		TrInstant,
		// Option 0 Off
		TRANSPARENT,

		// Option 1: AudiFlicker (ALTCOLOR2)
		Style2_AudioFilter,
		// Option 2: RandomFlicker (ALTCOLOR2)
		Style2_RandomFlicker,
		// Option 3: Pusling (ALTCOLOR2)
		Style2_Pulsing,
		// Option 4: BrownNoise Stripes (ALTCOLOR2)
		Style2_BrownNoiseFlicker,
		// Option 5: HumpFlicker Random (ALTCOLOR2)
		Style2_HumpFlicker_Random,
		// Option 6: Hump Waves (ALTCOLOR, ALTCOLOR2)
		Style2_HumpWave,
		// Option 7: Sparkles (ALTCOLOR2)
		Style2_Sparkle,
		// Option 8: Underlying Fett263 Smoke Blade Fire layer (ALTCOLOR)
		Style2_FireBlade,
		// Option 9: Fire (ALTCOLOR, ALTCOLOR2)
		Style2_Fire,
		// Option 10: Cylon (ALTCOLOR2)
		Style2_Cylon,
		// Option 11: Lightning flash (ALTCOLOR2)
		Style2_LightningFlash,
		// Option 12: Emitter tip Flame (ALTCOLOR2)
		Style2_EmitterTipFlame

		// Option 4: Random LED Flicker (ALTCOLOR2)
		//Style2_RandomPerLEDFlicker, // Looks too similar to BownNoiseFlicker.
		// Option 6: StripesX Slownoise (ALTCOLOR2 50%)
		//Style2_StripesX_SlowNoise, // Stripes doesn't support Transparency.
	>,

	// Tirtiary blade Styles
	ColorSelect<
		IntArg<STYLE_OPTION3_ARG, 0>,
		TrInstant,
		// Option 0 Off
		TRANSPARENT,
		// Option 1: AudiFlicker (ALTCOLOR3)
		Style3_AudioFilter,
		// Option 2: RandomFlicker (ALTCOLOR3)
		Style3_RandomFlicker,
		// Option 3: Pusling (ALTCOLOR3)
		Style3_Pulsing,
		// Option 4: BrownNoise Stripes (ALTCOLOR3)
		Style3_BrownNoiseFlicker,
		// Option 5: HumpFlicker Random (ALTCOLOR3)
		Style3_HumpFlicker_Random,
		// Option 6: Hump Waves (ALTCOLOR3)
		Style3_HumpWave,
		// Option 7: Sparkles (ALTCOLOR3)
		Style3_Sparkle,
		// Option 8: Underlying Fett263 Smoke Blade Fire layer (ALTCOLOR3)
		Style3_FireBlade,
		// Option 9: Fire (ALTCOLOR2, ALTCOLOR3)
		Style3_Fire,
		// Option 10: Cylon (ALTCOLOR3)
		Style3_Cylon,
		// Option 11: Lightning Flash (ALTCOLOR3)
		Style3_LightningFlash,
		// Option 12: Emitter Flare (EMITTER COLOR)
		Style3_EmitterFlare,
		// Option 13: Emitter Flicker (EMITTER COLOR)
		Style3_EmitterFlicker,
		// Option 14: Timed "breathing" emitter flare (EMITTER COLOR)
		Style3_EmitterBreathe,
		// Option 15: Emitter Pulse (EMITTER COLOR)
		Style3_Emitter_Pulse,
		// Option 16: Blade Angle Flare (ALTCOLOR3)
		Style3_Spark_BladeAngle

		// Option 4: Random LED Flicker (ALTCOLOR3)
		//Style3_RandomPerLEDFlicker, // Looks too similar to BrownNoiseFlicker
		// Option 6: StripesX Slownoise
		//Style3_StripesX_SlowNoise, // Stripes doesn't support Transparency
	>,
	
	// Swing Options/Force Effect options
	ColorSelect<
		IntArg<SWING_OPTION_ARG, 0>, 
		TrInstant, 
		// Option 0: Disabled
		TRANSPARENT,
		// Option 1: Force Pulse
		Swing_Force_Pulse,
		// Option 2: Force Aura
		Swing_Force_Aura,
		// Option 3: AudioFlicker
		Swing_AudioFlicker,
		// Option 4: Sparkle
		Swing_Sparkle,
		// Option 5: Fire
		Swing_Fire,
		// Option 6: Fett263's Swing Effect
		Layers <
			//Fett263 Ripple swing effect
			Swing_FettRipple,

			//Fett263 Bright hard swing effect
			Swing_FettHard
		>,
		// Option 7: Unstable Swing
		Layers <
			//Unstable swing
			Swing_Unstable,
			//Unstable ripple swing
			Swing_UnstableRippple
		>,
		// Option 8: Interactive Power Buildup
		Swing_Interactive_Power_Buildup,
		// Option 9: Fireball
		Swing_Fireball,
		// Option 10: Lightning
		Swing_Lightning
	>,

	// Special Abiltiies
	Special1_Rain,
	
	// Multi blast effect
	// Blast_MultiRandom,

	MultiTransitionEffectL<
		TrRandom<
		//	/*
			// Option 1: Blast Wave (Random)
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
		//	Blast_Responsive_Wave
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
		Lockup_Color_Style4,
		/*
		EffectSequence<
			EFFECT_LOCKUP_BEGIN,
			Lockup_Color_Style,
			Lockup_Color_Style2,
			Lockup_Color_Style3,
			Lockup_Color_Style4
		>,
		*/
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
		EffectSequence<
			EFFECT_DRAG_BEGIN,
			Drag_Color_Style,
			Drag_Color_Style2
		>,
		TrRandom<
			Drag_Start,
			Drag_Start2
		>,
		Drag_End, // EFFECT_DRAG_END
		SaberBase::LOCKUP_DRAG
	>,

	// Stab
	ResponsiveStabL<
		EffectSequence<
			EFFECT_STAB,
			Stab_Color_Style,
			Stab_Color_Style2,
			Stab_Color_Style3
		>,
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
		EffectSequence<
			EFFECT_LOCKUP_BEGIN,
			Melt_Color_Style, 
			Melt_Color_Style2
		>,
		TrRandom<
			Melt_Start, 
			Melt_Start2
		>,
		Melt_End, 
		SaberBase::LOCKUP_MELT
	>,
	
	// In/Out
	InOutTrL<
		// Ignition Options
		TrSelect<
			IntArg<IGNITION_OPTION_ARG, 0>, 
			// Option 0: Instant, for letting the PreOn do the work
			TrInstant,
			// Option 1: Standard
			Ignition_Standard,
			// Option 2: Dual Mode wip (up = fast)
			Ignition_DualMode,
			// Option 3: Spark Tip
			Ignition_SparkTip, 
			// Option 4: Center Wipe
			Ignition_CenterWipe,
			// Option 5: Color Cycle
			Ignition_ColorCycle,
			// Option 6: Lightning Strike
			Ignition_LightningStrike,
			// Option 7: Flash On
			Ignition_Flash

		>, 
		// Retraction Options
		TrSelect<
			IntArg<RETRACTION_OPTION_ARG, 0>, 
			// Option 0: Instant, for letting PostOff do the work
			TrInstant, 
			// Option 1: Standard
			Retraction_Standard,
			// Option 2: Dual Mode
			Retraction_DualMode,
			// Option 3: Spark tip.
			Retraction_SparkTip,
			// Option 4: Center Wipe
			Retraction_CenterWipe,
			// Option 5, Color cycle
			Retraction_ColorCycle,
			// Option 6, Glitch off
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
			// Option 5: Faulty Ignition
			PreOn_Faulty_Ignition,
			// Option 6: Dim Pre-Blade Extension
			PreOn_Dim_Blade
		>, 
		EFFECT_PREON
	>,

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
			PowerDown_Smoke_Reverse,
			// Option 6: Postoff Cooldown, for fonts with no PostOff#.wav files
			PostOff_EmitterCoolOff
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