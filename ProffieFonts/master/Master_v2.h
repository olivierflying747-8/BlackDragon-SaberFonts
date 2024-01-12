// Include common "using" layer styles from another file
#include "Common_Colors.h" // Color / color blend defines
#include "Common_Misc.h" // Misc common code and effects

#include "Common_Blade.h" // Blade effects, for STYLE_OPTION_ARG
#include "Common_Blade2.h" // Blade effects, for STYLE_OPTION2_ARG
//#include "Common_Blade3.h" // Blade effects, for STYLE_OPTION3_ARG
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
This Style Contains ???? (a lot) Unique Combinations
Style Options:
0: Static Color (Base Color)
1: Audio Flicker (Base Color, Alt Color)
2: Random Flicker (Base Color, Alt Color)
3: BrownNoise Flicker Blade (Base Color)
4: Pulsing (Base Color, Alt Color)
5: Stripes (Base Color)
6: Stripes SlowNoise (Base Color, Alt Color)
7: Stripes Unstable (Base Color)
8: Fire Blade (Base Color)
9: Thunderstorm blade (Base Color, Alt Color)
10: Fett263 Smoke Blade style. (Base Color)
11: Glitchy / Broken blade. (Base Color)
12: DarkSaber (Base Color, Alt Color)
13: Electro Staff Blade (Base Color)
14: Ghost Buster Blade (Base Color, Alt Color, Alt Color 2)
15: Smash Blade
16: Party Blade (No Colors, Rainbow)

--Effects Included--
STYLE_OPTION2_ARG options: // Secondary Blade Effects while on
0: Disabled
1: Audio Flicker (Alt Color 2)
2: Random Flicker (Alt Color 2)
3: Blinking (Alt Color 2)
4: Pulsing (Alt Color 2)
5: BrownNoise Stripes (Alt Color 2)
6: HumpFlicker Random (Alt Color 2)
7: Waves (Alt Color, Alt Color 2)
8: Sparkles (Alt Color 2)
9: Fett263 FireBlade (Alt Color 2)
10: Fire (Alt Color, Alt Color 2)
11: Cylon (Alt Color 2)
12: Lightning flash (Alt Color 2)
13: Emitter Tip Flame (Alt Color 2)

STYLE_OPTION3_ARG options: // Tirtiary Blade Effects while on
0: Disabled
1: Audio Flicker (Alt Color 3)
2: Random Flicker (Alt Color 3)
3: Blinking (Alt Color 2)
4: Pulsing (Alt Color 3)
5: BrownNoise Stripes (Alt Color 3)
6: HumpFlicker Random (Alt Color 3)
7: Waves (Alt Color2, Alt Color 3)
8: Sparkles (Alt Color 3)
9: Fett263 FireBlade (Alt Color 3)
10: Fire (Alt Color 2, Alt Color 3)
11: Cylon (Alt Color 3)
12: Lightning Flash (Alt Color 3)
13: Emitter Flare (Emiter Color)
14: Emitter Flare (Breathing) (Emitter Color)
15: Emitter Pulse (Alt Color 3)
16: Blade Spark (Interactive, Alt Color 3)

Swing Effect Options:
0: Disabled
1: Audio Flicker
2: Sparkle
3: Fire
4: Ripple (Fett263's)
5: Unstable
6: Power Buildup
7: Fireball
8: Lightning
9: Clash Buildup, Lockup Release

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
0: Instant
1: Standard Ignition 
2: Dual Mode Wipe (Up = Fast)
3: SparkTip Ignition
4: Center Wipe
5: Color Cycle
6: Lightning Strike
7: Flash
8: Gravity Ignition

Retraction Effect Options:
0: Instant
1: Standard Retraction
2: Dual Mode Wipe In (Up = Fast)
3: SparkTip Retraction
4: Center Wipe
5: Color Cycle
6: Glitch off
7: Gravity Retraction

PowerUp Effect Options:
0: Disabled
1: Glitch On (Power Flash)
2: Power Surge
3: Flash Fade
4: Power Burst Forward
5: Unstable Power Up Forward
6: Unstable Bright
7: Stabalize

CoolDown Effect Options:
0: Disabled
1: Glitch Off (Flash)
2: Power Burst Reverse
3: Unstable Cool Down Reverse
4: Bright Humpflicker
5: Smoke Blade Retraction
6: Emitter Cooldown (for fonts with no PostOff .wav files)

Special Abilities:
USER1: Rain (Off Color)

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
		BaseStyle_Static,
		// Option 1: Audioflicker (BASECOLOR, ALTCOLOR)
		BaseStyle_AudioFilter,
		// Option 2: Random Flicker (BASECOLOR, ALTCOLOR)
		BaseStyle_RandomFlicker,
		// Option 3: BrownNoise (BASECOLOR)
		BaseStyle_BrownNoiseFlicker,
		// Option 4: Pulsing Blade (BASECOLOR, ALTCOLOR)
		BaseStyle_Pulsing,
		// Option 5: Stripes (BASECOLOR)
		BaseStyle_Stripes,
		// Option 6: Stripes SlowNoise (BASECOLOR, ALTCOLOR)
		BaseStyle_Stripes_2Color,
		// Option 7: Unstable Stripes (BASECOLOR)
		BaseStyle_Stripes_RandomPerLEDFlicker,
		// Option 8: Fire blade (BASECOLOR)
		//BaseStyle_FireBlade, // Looks too similar to BrownNoiseFlicker
		// Option 9: Thunderstorm (BASECOLOR, ALTCOLOR)
		BaseStyle_ThunderstormBlade,
		// Option 10: Base Fett263 Smoke Blade style (BASECOLOR)
		BaseStyle_SmokeBlade,
		// Option 11: Flickery / Broken Blade (BASECOLOR)
		BaseStyle_FlickerBlade,
		// Option 12: Darksaber Blade (BASECOLOR, ALTCOLOR)
		BaseStyle_DarkSaber,
		// Option 13: ElectroStaff (BASECOLOR)
		BaseStyle_StaffBlade,
		// Option 14: Ghostbuster (BASECOLOR, ALTCOLOR, ALTCOLOR2)
		BaseStyle_GhostBusterBlade,
		// Option 15: Smash Blade (Special Colors)
		BaseStyle_SmashBlade,

		// Option 16: Party Blade
		BaseStyle_PartyBlade

		// Option 17: Coda
//		BaseStyle_CodaBlade,
		// Option 18: Fireblade Interactive Pulse
//		BaseStyle_FirePulseInteractive,
	>,

	// Secondary blade Styles
	ColorSelect<
		IntArg<STYLE_OPTION2_ARG, 0>,
		TrInstant,
		// Option 0 Off
		TRANSPARENT,
		// Option 1: AudiFlicker (ALTCOLOR2)
		AltStyle_AudioFilter<ALTCOLOR2>,
		// Option 2: RandomFlicker (ALTCOLOR2)
		AltStyle_RandomFlicker<ALTCOLOR2>,
		// Option 3: Blinking
		AltStyle_Blinking<ALTCOLOR2>,
		// Option 4: Pusling (ALTCOLOR2)
		AltStyle_Pulsing<ALTCOLOR2>,
		// Option 5: BrownNoise Stripes (ALTCOLOR2)
		AltStyle_BrownNoise_Stripes<ALTCOLOR2>,
		// Option 6: HumpFlicker Random (ALTCOLOR2)
		AltStyle_HumpFlicker_Random<ALTCOLOR2>,
		// Option 7: Hump Waves (ALTCOLOR, ALTCOLOR2)
		AltStyle_HumpWave<ALTCOLOR, ALTCOLOR2>,
		// Option 8: Sparkles (ALTCOLOR2)
		AltStyle_Sparkle<ALTCOLOR2>,
		// Option 9: Underlying Fett263 Smoke Blade Fire layer (ALTCOLOR)
		AltStyle_SmokeBlade<ALTCOLOR2, 1>,
		// Option 10: Fire (ALTCOLOR, ALTCOLOR2)
		AltStyle_Fire<ALTCOLOR, ALTCOLOR2>,
		// Option 11: Cylon (ALTCOLOR2)
		AltStyle_Cylon<ALTCOLOR2, 5, 20>,
		// Option 12: Lightning flash (ALTCOLOR2)
		AltStyle_LightningFlash<ALTCOLOR2>,
		// Option 13: Emitter tip Flame (ALTCOLOR2)
		AltStyle_Blade_Tip_Flame<ALTCOLOR2>

		// Option 4: Random LED Flicker (ALTCOLOR2)
		//AltStyle_RandomPerLEDFlicker<ALTCOLOR2>, // Looks too similar to BownNoise_Stripes.
		// Option 6: StripesX Slownoise (ALTCOLOR2 50%)
		//AltStyle_StripesX_SlowNoise<ALTCOLOR2>, // Stripes doesn't support Transparency.
	>,

	// Tirtiary blade Styles
	ColorSelect<
		IntArg<STYLE_OPTION3_ARG, 0>,
		TrInstant,
		// Option 0 Off
		TRANSPARENT,
		// Option 1: AudiFlicker (ALTCOLOR3)
		AltStyle_AudioFilter<ALTCOLOR3>,
		// Option 2: RandomFlicker (ALTCOLOR3)
		AltStyle_RandomFlicker<ALTCOLOR3>,
		// Option 3: Blinking
		AltStyle_Blinking<ALTCOLOR3, 250, Int<750>, Int<500>, Int<1200>>,
		// Option 4: Pusling (ALTCOLOR3)
		AltStyle_Pulsing<ALTCOLOR3, 250, Int<1400>, Int<2000>, Int<500>, Int<4000>>,
		// Option 5: BrownNoise Stripes (ALTCOLOR3)
		AltStyle_BrownNoise_Stripes<ALTCOLOR3, SWING_SPEED_DEFAULT, Int<2500>, Int<3500>, Int<-1500>, Int<-2500>>,
		// Option 6: HumpFlicker Random (ALTCOLOR3)
		AltStyle_HumpFlicker_Random<ALTCOLOR3>,
		// Option 7: Hump Waves (ALTCOLOR3)
		AltStyle_HumpWave<ALTCOLOR2, ALTCOLOR3>,
		// Option 8: Sparkles (ALTCOLOR3)
		AltStyle_Sparkle<ALTCOLOR3>,
		// Option 9: Underlying Fett263 Smoke Blade Fire layer (ALTCOLOR3)
		AltStyle_SmokeBlade<ALTCOLOR3, 1>,
		// Option 10: Fire (ALTCOLOR2, ALTCOLOR3)
		AltStyle_Fire<ALTCOLOR2, ALTCOLOR3>,
		// Option 11: Cylon (ALTCOLOR3)
		AltStyle_Cylon<ALTCOLOR3, 5, -20>,
		// Option 12: Lightning Flash (ALTCOLOR3)
		AltStyle_LightningFlash<ALTCOLOR3>,
		// Option 13: Emitter Flare (EMITTER COLOR)
		AltStyle_Emitter_Flare<EMITTERCOLOR>,
		// Option 14: Timed "breathing" emitter flare (EMITTER COLOR)
		AltStyle_Emitter_Breathe<EMITTERCOLOR>,
		// Option 15: Emitter Pulse (EMITTER COLOR)
		AltStyle_Emitter_Pulse<EMITTERCOLOR>,
		// Option 16: Blade Angle Flare (ALTCOLOR3)
		AltStyle_Spark_BladeAngle<ALTCOLOR3>

		// Option 4: Random LED Flicker (ALTCOLOR3)
		//AltStyle_RandomPerLEDFlicker<ALTCOLOR3>, // Looks too similar to BrownNoise_Stripes
		// Option 6: StripesX Slownoise
		//AltStyle_StripesX_SlowNoise<ALTCOLOR3>, // Stripes doesn't support Transparency
	>,
	
	// Swing Options/Force Effect options
	ColorSelect<
		IntArg<SWING_OPTION_ARG, 0>, 
		TrInstant, 
		// Option 0: Disabled
		TRANSPARENT,
		// Option 1: AudioFlicker
		Swing_AudioFlicker,
		// Option 2: Sparkle
		Swing_Sparkle,
		// Option 3: Fire
		Swing_Fire,
		// Option 4: Fett263's Swing Effect
		Layers <
			//Fett263 Ripple swing effect
			Swing_FettRipple,

			//Fett263 Bright hard swing effect
			Swing_FettHard
		>,
		// Option 5: Unstable Swing
		Layers <
			//Unstable swing
			Swing_Unstable,
			//Unstable ripple swing
			Swing_UnstableRippple
		>,
		// Option 6: Interactive Power Buildup
		Swing_Interactive_Power_Buildup,
		// Option 7: Fireball
		Swing_Fireball,
		// Option 8: Lightning
		Swing_Lightning,
		// Option 9: Clash Buildup
		Swing_Clash_BuildUp
		// Option 10: Force Pulse
	//	Swing_Force_Pulse,
		// Option 11: Force Aura
	//	Swing_Force_Aura,
		// Option 12: Force Heat
	//	Swing_Force_Heat
	>,

	// Special Abiltiies
	Special1_Rain,
	
	// Multi blast effect
	// Blast_MultiRandom,

	MultiTransitionEffectL<
		TrRandom<
			/*
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
			*/
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

	/*
	// Bright flash ripple on CLASH_UPDATE?
	TransitionEffectL<
		TrConcat<
			TrInstant,
			Clash_Update
		>,
		EFFECT_CLASH_UPDATE
	>,
	*/
	
	// Lockup
	LockupTrL<
//		EffectSequence<
//			EFFECT_LOCKUP_BEGIN,
			Lockup_Color_Style,
//			Lockup_Color_Style2,
//			Lockup_Color_Style3,
//			Lockup_Color_Style4
//		>,
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
//		EffectSequence<
//			EFFECT_DRAG_BEGIN,
			Drag_Color_Style,
//			Drag_Color_Style2
//		>,
//		TrRandom<
			Drag_Start,
//			Drag_Start2
//		>,
		Drag_End, // EFFECT_DRAG_END
		SaberBase::LOCKUP_DRAG
	>,

	// Stab
	ResponsiveStabL<
//		EffectSequence<
//			EFFECT_STAB,
			Stab_Color_Style,
//			Stab_Color_Style2,
//			Stab_Color_Style3
//		>,
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
//		EffectSequence<
//			EFFECT_LOCKUP_BEGIN,
			Melt_Color_Style, 
//			Melt_Color_Style2
//		>,
//		TrRandom<
			Melt_Start, 
//			Melt_Start2
//		>,
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
			Ignition_Flash,
			// Option 8: Gravity based
			Ignition_Gravity
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
			Retraction_Glitch_Off,
			// Option 7: Gravity based
			Retraction_Gravity
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
			// Option 6: Fett263 Unstable bright ignition effect
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
			// Option 4: Fett263 Bright Humpflicker retraction effect
			PowerDown_Bright_Hump,
			// Option 5: Smoke Blade Retraction, //Emitter Cooldown
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