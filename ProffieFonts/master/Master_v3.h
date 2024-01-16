// Include common "using" layer styles from another file
#include "Common_Colors.h" // Color / color blend defines
#include "Common_Misc.h" // Misc common code and effects

#include "Common_Blade.h" // Blade effects, for STYLE_OPTION_ARG
#include "Common_Blade2.h" // Blade effects, for STYLE_OPTION2_ARG
//#include "Common_Blade3.h" // Blade effects, for STYLE_OPTION3_ARG
#include "Common_Swing.h" // Swing effects for SWING_OPTION_ARG
#include "Common_Blast.h" // Blaster effects
#include "Common_Lockup.h" // Lockup effects
#include "Common_Clash.h" // Clash effects
#include "Common_Stab.h" // Stab effects
#include "Common_Drag.h" // Drag effects
#include "Common_Melt.h" // Melt effects
#include "Common_Lightning.h" // Lightning Block effects
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
8: Thunderstorm blade (Base Color, Alt Color)
9: Fett263 Smoke Blade style. (Base Color)
10: Glitchy / Broken blade. (Base Color)
11: DarkSaber (Base Color, Alt Color)
12: Electro Staff Blade (Base Color)
13: Ghost Buster Blade (Base Color, Alt Color, Alt Color 2)
14: Smash Blade (Custom Colors)
15: Fire Blade (Base Color)
16: Coda blade style w/ swing effects. (Base Color, Alt Color, Alt Color 2)
17: Fire Pulse Blade (Interactive)
18: Static Electricty
19: Lava Lamp
20: Party Blade (Custom Colors, Rainbow)

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
14: Emitter Breathing (Emitter Color)
15: Emitter Pulse (Alt Color 3)
16: Blade Spark (Interactive, Alt Color 3)

Ignition Effect Options (Ignition Color):
0: Instant
1: Standard Ignition
2: Dual Mode Wipe (Up = Fast)
3: SparkTip Ignition
4: Center Wipe
5: Wipe In
6: Color Cycle
7: Glitch On
8: Gravity Ignition
9: Lightning Strike
10: Flash
11: Metal Forge Heatup

PowerUp Effect Options (Ignition Color):
0: Disabled
1: Glitch On (Power Flash)
2: Power Surge
3: Flash Fade
4: Power Burst Forward
5: Unstable Power Up Forward
6: Unstable Bright
7: Stabalize

Retraction Effect Options (Retraction Color):
0: Instant
1: Standard Retraction
2: Dual Mode Wipe In (Up = Fast)
3: SparkTip Retraction
4: Center Wipe
5: Wipe Out
6: Color Cycle
7: Glitch off
8: Gravity Retraction
9: Metal Forge Cooldown

CoolDown Effect Options (Retraction Color):
0: Disabled
1: Glitch Off (Flash)
2: Power Burst Reverse
3: Unstable Cool Down Reverse
4: Bright Humpflicker
5: Smoke Blade Retraction
6: Emitter Cooldown (for fonts with no PostOff .wav files) (PostOff Color)

Swing Effect Options (Swing Color):
0: Disabled
1: Audio Flicker
2: Sparkle
3: Pulsing
4: Fire
5: Ripple (Fett263's)
6: Unstable
7: Bright Edge (Responsive)
8: Pixilate
9: Lightning
10: Clash Buildup, Lockup Release
11: Interactive Power Buildup (Force Toggle)
12: Interactive Fireball (Force Toggle)
13: Force Pulse
14: Force Aura
15: Force Flicker Swing
16: Force Heat
17: Interactive Flamethrower (Force Toggle)
18: Force Rage Unstable
19: Force Rage Lightning
20: Interactive Ice Blade
21: Static Electricty Swing

Preon Effect Options (PreOn Color): 
0: Disabled
1: Overload
2: Sparking
3: Broken Ignition
4: Emitter Warm up
5: Faulty Ignition
6: Blade Pre-Light up

PostOff Effect Options (PostOff Color):
0: Disabled
1: Emitter Cooldown
2: Emitter Spark
3: Emitter Glow

Special Abilities:
USER1: Clash/Lockup Shield Toggle (DUNE Shield)
USER2: Dual Lockup Toggle (Two Independent Lockup Humps)
USER3: Force Lightning Toggle (Replaces Lightning Block)
USER4: Rain Toggle (Off Color)

Lockup Effects (Sequential): 
- Intensity Lockup
- Localized AudioFlicker
- Full Blade AudioFlicker
- Cylon (Oldschool) Lockup

Lockup Start Transitions (Random):
- Real Clash (Intensity)
- Localized Flicker
- Localized Flash/Fade
- Full blade Flash/Fade

Lockup End Transitions (Random):
- Real Clash (Intensity)
- Power Burst Wave
- Localized Absorb Flash
- Full Blade Flash

LightningBlock Effect: 
- Responsive Lightning Block

Drag Effect (Sequential):
- Intensity Sparking
- Fire Spark

Melt Effect (Sequential): 
- Responsive Melt
- Intensity Melt

Blast Effect (Randomly Selected) (Blast Color): 
- Blast Fade (Random)
- Blast Fade (Sound Based)
- Blast Wave (Random)
- Blast Wave (Sound Based)
- Blast Ripple Fade,
- Responsive Blast Fade (BladeAngle, Random), 
- Responsive Blast Fade (BladeAngle, Sound Based), 
- Responsive Blast Wave (BladeAngle, Random), 
- Responsive Blast Wave (BladeAngle, Sound Based), 
- Responsive Blast Ripple Fade (BladeAngle)
- Responsive Blast Fade (SwingSpeed, Random),
- Responsive Blast Fade (SwingSpeed, Sound Based),
- Responsive Blast Wave (SwingSpeed, Random),
- Responsive Blast Wave (SwingSpeed, Sound Based),
- Responsive Blast Ripple Fade (SwingSpeed)
- Responsive Blast Fade (TwistAngle, Random),
- Responsive Blast Fade (TwistAngle, Sound Based),
- Responsive Blast Wave (TwistAngle, Random),
- Responsive Blast Wave (TwistAngle, Sound Based),
- Responsive Blast Ripple Fade (TwistAngle)

Clash Effect (Sequential): 
- Real Clash V1
- Responsive Wave
- Responsive Ripple
- Random Clash

Battery Level: Hilt Location (Green to Red) on Boot/FontChange/BatteryLevel

Volume Level: Blade Light (White)

Power Save: 10% Increment
*/

using MasterStyle = Layers<
	ColorSelect<
		IntArg<STYLE_OPTION_ARG, 0>, 
		TrInstant, 
	
		// Option 12: Fire Blade with Swing Speed and Fire Tip (BASECOLOR)
		BaseStyle_FireTipBlade,
		// Option 13: blablabla
		BaseStyle_FireTipBase,
		// Option 14: Water Blade
		BaseStyle_WaterBlade,


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
		// Option 8: Thunderstorm (BASECOLOR, ALTCOLOR)
		BaseStyle_ThunderstormBlade,
		// Option 9: Base Fett263 Smoke Blade style (BASECOLOR)
		BaseStyle_SmokeBlade,
		// Option 10: Flickery / Broken Blade (BASECOLOR)
		BaseStyle_FlickerBlade,
		// Option 11: Darksaber Blade (BASECOLOR, ALTCOLOR)
		BaseStyle_DarkSaber,
		// Option 12: ElectroStaff (BASECOLOR)
		BaseStyle_StaffBlade,
		// Option 13: Ghostbuster (BASECOLOR, ALTCOLOR, ALTCOLOR2)
		BaseStyle_GhostBusterBlade,
		// Option 14: Smash Blade (Special Colors)
		BaseStyle_SmashBlade,

		// Option 15: Fire blade (BASECOLOR)
		BaseStyle_FireBlade,
		// Option 16: Coda (BASECOLOR, ALTCOLOR, ALTCOLOR2)
		BaseStyle_CodaBlade,
		// Option 17: Fireblade Interactive Pulse
		BaseStyle_FirePulseInteractive,
		// Option 18: Static Electricty
		BaseStyle_StaticElectricity,
		// Option 19: Lava Lamp
		BaseStyle_LavaLamp,

		// Option 20: Party Blade (special colors)
		BaseStyle_PartyBlade
	>,

	// Secondary blade Styles
	ColorSelect<
		IntArg<STYLE_OPTION2_ARG, 0>,
		TrInstant,
		// Option 0 Off
		TRANSPARENT,
		
		AltStyle_FireTEST<ALTCOLOR2>,
		AltStyle_Fire<ALTCOLOR, ALTCOLOR2>,

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

		Swing_Force_Heat,

		// Option 0: Disabled
		TRANSPARENT,
		// Option 1: AudioFlicker
		Swing_AudioFlicker,
		// Option 2: Sparkle
		Swing_Sparkle,
		// Option 3: Pusling
		Swing_Pulsing,
		// Option 4: Fire
		Swing_Fire,
		// Option 5: Fett263's Swing Effect
		Layers <
			//Fett263 Ripple swing effect
			Swing_FettRipple,

			//Fett263 Bright hard swing effect
			Swing_FettHard
		>,
		// Option 6: Unstable Swing
		Layers <
			//Unstable swing
			Swing_Unstable,
			//Unstable ripple swing
			Swing_UnstableRippple
		>,
		// Option 7: Bright Edge (Responsive)
		Swing_Bright_Edge,
		// Option 8: Pixilate
		Swing_Pixilate,
		// Option 9: Lightning
		Swing_Lightning,
		// Option 10: Clash Buildup
		Swing_Clash_BuildUp,
		// Option 11: Interactive Power Buildup (Force Toggle)
		Swing_Interactive_Power_Buildup,
		// Option 12: Interactive Fireball (Force Toggle)
		Swing_Interactive_Fireball,
		// Option 13: Force Pulse
		Swing_Force_Pulse,
		// Option 14: Force Aura
		Swing_Force_Aura,
		// Option 15: Force Flicker Swing
		Swing_Force_Flicker,
		// Option 16: Force Heat
		Swing_Force_Heat,
		// Option 17: Interactive Flamethrower (Force Toggle)
		Swing_Interactive_Flamethrower,
		// Option 18: Force Rage Unstable
		Swing_Force_Rage_Unstable,
		// Option 19: Force Rage Lightning
		Swing_Force_Rage_Lightning,
		// Option 20: Interactive Ice Blade
		Swing_Interactive_IceBlade,
		// Option 21: Static Electricty Swing
		Swing_Static_Electricity
	>,

	// Powerup Effect
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

	// Cooldown effect
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

	// Special Abiltiies
	Special4_Rain,
	
	// Multi blast effect
	MultiTransitionEffectL<
		TrRandom<

		// /*
		// Random Positions based on EffectPosition
			// Blast Fade Random
			Blast_Fade<BLASTPOS_SCALE<>, BLASTFADE_SIZE<>>,
			// Blast Fade Sound
			Blast_Fade<BLASTPOS_SCALE<>, BLASTFADE_SIZE<WavLen<EFFECT_BLAST>>>,

			// Blast Wave Random
			Blast_Wave<BLASTWAVE_SCALE<>, BLASTWAVE_SCALE<SlowNoise<Int<3000>>>, BLASTWAVE_SCALE<>, BLASTPOS_SCALE<>>,
			// Blast Wave Sound
			Blast_Wave<BLASTWAVE_SCALE<WavLen<EFFECT_BLAST>>, BLASTWAVE_SCALE<SlowNoise<Int<3000>>>, BLASTWAVE_SCALE<WavLen<EFFECT_BLAST>>, BLASTPOS_SCALE<>>,

			// Blast Ripple Fade
			Blast_Ripple_Fade<BLASTRIPPLE_POS<>, Int<6000>, Int<320000>>,
		// */

		// /*
		// Responsive based on BladeAngle<>
			// Responsive Blast Fade Random
			Blast_Fade<BLASTPOS_SCALE<BladeAngle<>>, BLASTFADE_SIZE<>>,
			// Responsive Blast Fade Sound
			Blast_Fade<BLASTPOS_SCALE<BladeAngle<>>, WavLen<EFFECT_BLAST>>,

			// Responsive Blast Wave Random
			Blast_Wave<BLASTWAVE_SCALE<>, BLASTWAVE_SCALE<SlowNoise<Int<3000>>>, BLASTWAVE_SCALE<>, BLASTPOS_SCALE<BladeAngle<>>>,
			// Responsive Blast Wave Sound
			Blast_Wave<BLASTWAVE_SCALE<WavLen<EFFECT_BLAST>>, BLASTWAVE_SCALE<SlowNoise<Int<3000>>>, BLASTWAVE_SCALE<WavLen<EFFECT_BLAST>>, BLASTPOS_SCALE<BladeAngle<>>>,

			// Responsive Blast Ripple Fade
			Blast_Ripple_Fade<BLASTRIPPLE_POS<BladeAngle<>>, Int<6000>, Int<320000>>,
		// */

		// /*
		// Responsive based on SwingSpeed<>
			// Responsive Blast Fade Random
			Blast_Fade<BLASTPOS_SCALE<SwingSpeed<200>>, BLASTFADE_SIZE<>>,
			// Responsive Blast Fade Sound
			Blast_Fade<BLASTPOS_SCALE<SwingSpeed<200>>, WavLen<EFFECT_BLAST>>,

			// Responsive Blast Wave Random
			Blast_Wave<BLASTWAVE_SCALE<>, BLASTWAVE_SCALE<SlowNoise<Int<3000>>>, BLASTWAVE_SCALE<>, BLASTPOS_SCALE<SwingSpeed<200>>>,
			// Responsive Blast Wave Sound
			Blast_Wave<BLASTWAVE_SCALE<WavLen<EFFECT_BLAST>>, BLASTWAVE_SCALE<SlowNoise<Int<3000>>>, BLASTWAVE_SCALE<WavLen<EFFECT_BLAST>>, BLASTPOS_SCALE<SwingSpeed<200>>>,

			// Responsive Blast Ripple Fade
			Blast_Ripple_Fade<BLASTRIPPLE_POS<SwingSpeed<200>>, Int<6000>, Int<320000>>,
		// */

		// /*
		// Responsive based on TwistAngle<>
			// Responsive Blast Fade Random
			Blast_Fade<BLASTPOS_SCALE<TwistAngle<>>, BLASTFADE_SIZE<>>,
			// Responsive Blast Fade Sound
			Blast_Fade<BLASTPOS_SCALE<TwistAngle<>>, WavLen<EFFECT_BLAST>>,

			// Responsive Blast Wave Random
			Blast_Wave<BLASTWAVE_SCALE<>, BLASTWAVE_SCALE<SlowNoise<Int<3000>>>, BLASTWAVE_SCALE<>, BLASTPOS_SCALE<TwistAngle<>>>,
			// Responsive Blast Wave Sound
			Blast_Wave<BLASTWAVE_SCALE<WavLen<EFFECT_BLAST>>, BLASTWAVE_SCALE<SlowNoise<Int<3000>>>, BLASTWAVE_SCALE<WavLen<EFFECT_BLAST>>, BLASTPOS_SCALE<TwistAngle<>>>,

			// Responsive Blast Ripple Fade
			Blast_Ripple_Fade<BLASTRIPPLE_POS<TwistAngle<>>, Int<6000>, Int<320000>>
		// */




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
	ColorSelect<
		EffectIncrementF<
			EFFECT_USER1,
			Int<2>
		>,
		TrInstant,
		// Normal Clash
		EffectSequence <
			EFFECT_CLASH,
			// Real Clash V1
			Mix<
				IsLessThan<
					ClashImpactF<>, 
					Int<26000>
				>,
				// Mix A
				Clash_RealV1_Base,
				// Mix B
				Clash_RealV1_Wave
			>,
			// Responsive Wave
			Clash_RealV1_Wave,
			// Responsive Ripple
			Clash_Responsive_Ripple,
			// Random Clash
			Clash_Random
		>,
		// DUNE Shield
		Clash_Dune_Shield
	>,

	// Bright flash ripple on CLASH_UPDATE? TEST ME!
	TransitionEffectL<
		TrConcat<
			TrInstant,
			TrWaveX<
				//CLASHCOLOR,
				Rgb<255, 0, 255>, // TEST ME
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
				LOCKUPPOSITIONSCALE
			>
		>,
		EFFECT_CLASH_UPDATE
	>,
	
	// Lockup
	LockupTrL<
		// Lockup Effect
		ColorSelect<
			EffectIncrementF<
				EFFECT_USER2,
				Int<2>
			>,
			TrInstant,
			// Else look for DUNE Shield using USER1 Special Ability
			ColorSelect<
				EffectIncrementF<
					EFFECT_USER1,
					Int<2>
				>,
				TrInstant,
				// Normal Lockup, pick a random effect
				EffectSequence<
					EFFECT_LOCKUP_BEGIN,
					// Intensity Lockup
					Lockup_Color_Intensity,
					// Localized AudioFlicker
					Lockup_Color_Localized_Flicker,
					// Full Blade AudioFlicker
					Lockup_Color_Full_Flicker,
					// Original old Lockup, moves on it's own...
					Lockup_Color_Cylon
				>,
				// Dune Shield Lockup
				Lockup_Color_Shield
			>,
			// Dial Mode Lockup using USER2 Special Ability
			Lockup_Color_Dual
		>,
		// EFFECT_LOCKUP_BEGIN
		TrSelect<
			// look for DUNE Shield using USER1 Special Ability
			EffectIncrementF<
				EFFECT_USER1,
				Int<2>
			>,
			// Normal Lockup, pick a random effect
			TrRandom< //TrSequence<
				// Real Clash v1
				Lockup_Start_RealClash,
				// Localized Flicker
				Lockup_Start_Localized,
				// Localized Flash/Fade
				Lockup_Start_Localized_Flash,
				// Full blade Flash/Fade
				Lockup_Start_Full_Flash
			>,
			// Dune Shield Lockup
			Lockup_Start_Shield
		>,
		// EFFECT_LOCKUP_END
		TrSelect<
			// look for DUNE Shield using USER1 Special Ability
			EffectIncrementF<
				EFFECT_USER1,
				Int<2>
			>,
			// Normal Lockup, pick a random effect
			TrRandom< //TrSequence<
				// Real Clash Intensity
				Lockup_End_Intensity,
				// Power Burst Wave release
				Lockup_End_Power_Burst,
				// Localized Absorb Flash
				Lockup_End_Localized_Absorb,
				// Full blade flash
				Lockup_End_Full_Absorb
			>,
			// Dune Shield Lockup
			Lockup_End_Shield
		>,
		SaberBase::LOCKUP_NORMAL
	>,
	
	// Lightning Block
	LockupTrL<
		// Color
		ColorSelect<
			EffectIncrementF<
				EFFECT_USER3,
				Int<2>
			>,
			TrInstant,
			// Normal Lightning Block
			AlphaL<
				LB_Color_Style,
				// LB Positions
				LIGHTNINGBLOCK_RESPONSIVE_POSITION
			>,
			// Force Lightning
			Lockup_Force_Lightning
		>,
		// Start Transition
		TrSelect<
			// look for Force Lightning using USER3 Special Ability
			EffectIncrementF<
				EFFECT_USER3,
				Int<2>
			>,
			// Normal Lightning Start
			LB_Start,
			// Force Lightning Start
			Lockup_Force_Lightning_StartEnd
		>,
		// End Transition
		TrSelect<
			// look for Force Lightning using USER3 Special Ability
			EffectIncrementF<
				EFFECT_USER3,
				Int<2>
			>,
			// Normal Lightning End
			LB_End,
			// Force Lightning End
			Lockup_Force_Lightning_StartEnd
		>,
		SaberBase::LOCKUP_LIGHTNING_BLOCK
	>,
	/* // Old, kinda hard to do options in.
	ResponsiveLightningBlockL<
		LB_Color_Style,
		LB_Start,
		LB_End
	>
	*/
	
	// Drag
	LockupTrL<
		EffectSequence<
			EFFECT_DRAG_BEGIN,
			Drag_Color_Sparking,
			Drag_Color_Fire
		>,
		TrSequence<
			Drag_Start_Sparking,
			Drag_Start_Fire
		>,
		Drag_End, // EFFECT_DRAG_END
		SaberBase::LOCKUP_DRAG
	>,

	// Stab
	ResponsiveStabL<
		EffectSequence<
			EFFECT_STAB,
			Stab_Color_Normal,
			Stab_Color_AudioFlicker,
			Stab_Color_Style3
		>,
		Stab_Start,
		Stab_End,

		MELT_SIZE,
		Sum<
			MELT_SIZE,
			Int<2000>
		>	
	>,
	/* // Non Responsive Stab Effect
	TransitionEffectL<
		TrConcat<
			Stab_Start,
			EffectSequence<
				EFFECT_STAB,
				Stab_Color_Normal,
				Stab_Color_AudioFlicker,
				Stab_Color_Style3
			>,
			Stab_End,
		>,
		EFFECT_STAB
	>,
	*/
	
	// Melt
	LockupTrL<
		EffectSequence<
			EFFECT_LOCKUP_BEGIN,
			// Responsive Melt
			Melt_Color_Responsive, 
			// Intensity Melt
			Melt_Color_Intensity
		>,
		TrSequence<
			// Standard Start
			Melt_Start, 
			// Intensity Start
			Melt_Start_Intensity
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
			// Option 5: Wipe In
			Ignition_WipeIn,
			// Option 6: Color Cycle
			Ignition_ColorCycle,
			// Option 7: Glitch On
			Ignition_Glitch_On,
			// Option 8: Gravity based
			Ignition_Gravity,
			// Option 9: Lightning Strike
			Ignition_LightningStrike,
			// Option 10: Flash On
			Ignition_Flash,
			// Option 11: Metal Forge Heatup
			Ignition_Metal_Forge_Heatup
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
			// Option 5: Wipe Out
			Retraction_WipeOut,
			// Option 6, Color cycle
			Retraction_ColorCycle,
			// Option 7, Glitch off
			Retraction_Glitch_Off,
			// Option 8: Gravity based
			Retraction_Gravity,
			// Option 9: Metal Forge Cooldown
			Retraction_Metal_Forge_Cooldown
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

	// Post Off
	TransitionEffectL<
		TrSelect<
			IntArg<OFF_OPTION_ARG, 0>,
			// Option 0 // None
			TrInstant, 
			// Option 1: Emitter Cooldown
			PostOff_EmitterCoolOff,
			// Option 2: Emitter Spark
			PostOff_Emitter_Spark,
			// Option 3: Emitter Glow
			PostOff_Emitter_Glow
		>,
		EFFECT_POSTOFF
	>,
	
	// Battery Monitor on Boot
	BatteryLevelOnBoot,

	// Battery level on font change
	BatteryLevelOnFontChange,

	// Battery level
	BatteryLevelOnDemand,

	// Power Saver
	Battery_Power_Save
>;