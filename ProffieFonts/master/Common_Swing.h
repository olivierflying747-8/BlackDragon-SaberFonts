// ================================ SWING EFFECTS ===========================

// Force Slow?
using Swing_ForceSlow = TransitionEffectL<
	TrConcat<
		TrExtend<
			30000, 
			TrFade<300>
		>, 
		Pulsing<
			SWINGCOLOR, 
			Mix<
				Int<16384>, 
				Black, 
				SWINGCOLOR
			>, 
			3000
		>, 
		TrFade<300>
	>, 
	EFFECT_FORCE
>;

//Fett263 Ripple swing effect
using Swing_FettRipple = AlphaL<
	Stripes<
		2500,
		-3000,
		RotateColorsX<
			Variation, 
			SWINGCOLOR
		>,
		RotateColorsX<
			Variation,
			//Rgb<44,42,0> // SWING_COLOR_ARG / 5.1
			Mix<
				Int<6425>,
				Black,
				SWINGCOLOR
			>
		>,
		Pulsing<
			RotateColorsX<
				Variation,
				//Rgb<22,20,0> // SWING_COLOR_ARG / 12.75
				Mix<
					Int<2570>,
					Black,
					SWINGCOLOR
				>
			>,
			Black,
			800
		>
	>,
	SwingSpeed<375>
>;

//Unstable ripple swing
using Swing_UnstableRippple = AlphaL<
	Stripes<
		1000, 
		-2000, 
		RandomPerLEDFlicker<
			RotateColorsX<
				Variation, 
				SWINGCOLOR //DeepSkyBlue
			>, 
			Black
		>, 
		Black, 
		RotateColorsX<
			Variation, 
			SWINGCOLOR //DeepSkyBlue
		>, 
		Black
	>, 
	SwingSpeed<525>
>;

//Fett263 Bright hard swing effect
using Swing_FettHard = AlphaL<
	RotateColorsX<
		Variation,
		//LemonChiffon //255, 244, 157 // MIX ALT_COLOR_ARG, WHITE, 75% White
		Mix<
			Int<24576>, //75% white
			SWINGCOLOR,
			Rgb<255, 255, 255>
		>
	>,
	Scale<
		IsLessThan<
			SwingSpeed<675>,
			Int<13600>
		>,
		Scale<
			SwingSpeed<750>,
			Int<-17300>,
			Int<32768>
		>,
		Int<0>
	>
>;

//Unstable swing
using Swing_Unstable = AlphaL<
	BrownNoiseFlicker<
		RotateColorsX<
			Variation, 
			SWINGCOLOR //DeepSkyBlue
		>, 
		Black, 
		300
	>, 
	SwingSpeed<400>
>;
