// ================================ SWING EFFECTS ===========================

// Force Pulse
using Swing_Force_Pulse = TransitionEffectL<
	TrConcat<
		TrExtendX<
			Int<30000>, 
			TrFade<300>
		>, 
		Pulsing<
			SWINGCOLOR, 
			COLOR_MIX_P<50, SWINGCOLOR>, 
			3000
		>, 
		TrFade<300>
	>, 
	EFFECT_FORCE
>;

// Force Aura
using Swing_Force_Aura = TransitionEffectL<
	TrConcat<
		TrJoin<
			TrDelay<30000>,
			TrFade<300>
		>,
		AudioFlickerL<SWINGCOLOR>,
		TrFade<300>
	>,
	EFFECT_FORCE
>;

// Force Heating
using Swing_Force_Heat = EffectSequence<
	EFFECT_FORCE,
	AlphaL<
		Mix<
			Scale<
				IsLessThan<
					SwingSpeed<600>,
					Int<13600>
				>,
				Scale<
					SwingSpeed<600>,
					Int<-19300>,
					Int<32768>
				>,
				Int<0>
			>,
			Red,
			Orange,
			White
		>,
		Scale<
			Scale<
				IsLessThan<
					SwingSpeed<600>,
					Int<13600>
				>,
				Scale<
					SwingSpeed<600>,
					Int<-19300>,
					Int<32768>
				>,
				Int<0>
			>,
			Int<0>,
			Int<32768>
		>
	>,
	TRANSPARENT
>;

// AudioFlicker Swing
using Swing_AudioFlicker = AlphaL<
	AudioFlickerL<SWINGCOLOR>,
	SWING_SPEED_SCLAE<600>
>;

// Sparkle Swing
using Swing_Sparkle = AlphaL<
	SparkleL<SWINGCOLOR>,
	SWING_SPEED_SCLAE<600>
>;

// Fire Swing
using Swing_Fire = AlphaL<
	StripesX<
		//Int<2800>,
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<2800>, Int<1800>, Int<500>, Int<4000>>,
		//Int<-3000>,
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<-2000>, Int<-3000>, Int<500>, Int<4000>>,

		SWINGCOLOR,
		COLOR_MIX<Int<2096>, SWINGCOLOR>,
		COLOR_MIX_P<50, SWINGCOLOR>
	>,
	SWING_SPEED_SCLAE<600>
>;

//Fett263 Ripple swing effect
using Swing_FettRipple = AlphaL<
	StripesX<
		//Int<2500>,
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<2500>, Int<1500>, Int<500>, Int<4000>>,
		//Int<-3000>,
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<-2000>, Int<-3000>, Int<500>, Int<4000>>,

		RotateColorsX<Variation, SWINGCOLOR>,
		RotateColorsX<
			Variation,
			COLOR_MIX<Int<6425>, SWINGCOLOR> //Rgb<44,42,0> // SWING_COLOR_ARG / 5.1
		>,
		Pulsing<
			RotateColorsX<
				Variation,
				COLOR_MIX<Int<2570>, SWINGCOLOR> //Rgb<22,20,0> // SWING_COLOR_ARG / 12.75
			>,
			Black,
			800
		>
	>,
	SwingSpeed<375>
>;

//Unstable ripple swing
using Swing_UnstableRippple = AlphaL<
	StripesX<
		//Int<1000>, 
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<1500>, Int<1000>, Int<500>, Int<4000>>,
		//Int<-2000>, 
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<-1000>, Int<-2000>, Int<500>, Int<4000>>,

		RandomPerLEDFlicker<
			RotateColorsX<Variation, SWINGCOLOR>, //DeepSkyBlue
			Black
		>, 
		Black, 
		RotateColorsX<Variation, SWINGCOLOR>, //DeepSkyBlue
		Black
	>, 
	SwingSpeed<525>
>;

//Fett263 Bright hard swing effect
using Swing_FettHard = AlphaL<
	RotateColorsX<Variation, COLOR_MIX_P<75, SWINGCOLOR, White>>, //LemonChiffon //255, 244, 157 // MIX ALT_COLOR_ARG, WHITE, 75% White
	SWING_SPEED_SCLAE<675, Int<13600>, Int<-17300>>
>;

//Unstable swing
using Swing_Unstable = AlphaL<
	BrownNoiseFlickerL<
		RotateColorsX<Variation, SWINGCOLOR>, //DeepSkyBlue
		//Black, 
		Int<300>
	>, 
	SwingSpeed<400>
>;

//Interactive Power Build-up
using Swing_Interactive_Power_Buildup = AlphaL<
	StripesX<
		//Int<10000>,
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<10000>, Int<6000>, Int<500>, Int<4000>>,
		Scale<
			IncrementWithReset<
				ThresholdPulseF<
					Ifon<
						StrobeF<
							Int<12>,
							Int<1>
						>,
						Int<0>
					>,
					Int<32000>
				>,
				ThresholdPulseF<
					Ifon<
						InvertF<
							HoldPeakF<
								SwingSpeed<400>,
								Int<100>,
								Int<33000>
							>
						>,
						Int<0>
					>,
					Int<24000>
				>,
				Int<10000>,
				Int<100>
			>,
			Int<-50>,
			Int<-8000>
		>,
		COLOR_MIX<Int<10000>, SWINGCOLOR>,
		COLOR_MIX<Int<20000>, SWINGCOLOR>,
		SWINGCOLOR
	>,
	SmoothStep<
		Sum<
			IncrementWithReset<
				ThresholdPulseF<
					StrobeF<
						Int<10>,
						Int<1>
					>,
					Int<30000>
				>,
				ThresholdPulseF<
					Ifon<
						InvertF<
							HoldPeakF<
								SwingSpeed<400>,
								Int<100>,
								Int<38000>
							>
						>,
						Int<0>
					>,
					Int<16000>
				>,
				Int<4000>,
				Int<100>
			>,
			IncrementWithReset<
				ThresholdPulseF<
					Ifon<
						HoldPeakF<
							SwingSpeed<400>,
							Int<100>,
							Int<33000>
						>,
						Int<0>
					>,
					Int<16000>
				>,
				ThresholdPulseF<
					Ifon<
						InvertF<
							HoldPeakF<
								SwingSpeed<400>,
								Int<100>,
								Int<38000>
							>
						>,
						Int<0>
					>,
					Int<16000>
				>,
				Int<38000>,
				Int<38000>
			>
		>,
		Int<-2000>
	>
>;
		
// Fireball Swing
using Swing_Fireball = AlphaL<
	AlphaMixL<
		SmoothStep<
			IncrementWithReset<
				Scale<
					IsGreaterThan<
						HoldPeakF<
							Ifon<
								SwingSpeed<400>,
								Int<0>
							>,
							Int<150>,
							Int<32000>
						>,
						Int<18000>
					>,
					Int<0>,
					ThresholdPulseF<
						StrobeF<
							Scale<
								HoldPeakF<
									Ifon<
										SwingAcceleration<>,
										Int<0>
									>,
									Int<150>,
									Int<32000>
								>,
								Int<40>,
								Int<400>
							>,
							Int<1>
						>,
						Int<32000>
					>
				>,
				ThresholdPulseF<
					IsLessThan<
						HoldPeakF<
							Ifon<
								SwingSpeed<400>,
								Int<0>
							>,
							Int<150>,
							Int<32000>
						>,
						Int<8000>
					>,
					Int<32000>
				>,
				Int<42000>,
				Int<1500>
			>,
			Scale<
				HoldPeakF<
					Ifon<
						SwingSpeed<400>,
						Int<0>
					>,
					Int<150>,
					Int<32000>
				>,
				Int<3000>,
				Int<10000>
			>
		>,
		HumpFlicker<
			RotateColorsX<Int<1400>, SWINGCOLOR>,
			RotateColorsX<Int<3200>, SWINGCOLOR>,
			20
		>,
		HumpFlicker<
			RotateColorsX<Int<1000>, SWINGCOLOR>,
			RotateColorsX<Int<400>, SWINGCOLOR>,
			60
		>,
		RandomFlicker<
			COLOR_MIX_P<50, SWINGCOLOR>,
			SWINGCOLOR
		>
	>,
	LinearSectionF<
		IncrementWithReset<
			Scale<
				IsGreaterThan<
					HoldPeakF<
						Ifon<
							SwingSpeed<400>,
							Int<0>
						>,
						Int<150>,
						Int<32000>
					>,
					Int<18000>
				>,
				Int<0>,
				ThresholdPulseF<
					StrobeF<
						Scale<
							HoldPeakF<
								Ifon<
									SwingAcceleration<>,
									Int<0>
								>,
								Int<150>,
								Int<32000>
							>,
							Int<40>,
							Int<400>
						>,
						Int<1>
					>,
					Int<32000>
				>
			>,
			ThresholdPulseF<
				IsLessThan<
					HoldPeakF<
						Ifon<
							SwingSpeed<400>,
							Int<0>
						>,
						Int<150>,
						Int<32000>
					>,
					Int<8000>
				>,
				Int<32000>
			>,
			Int<42000>,
			Int<1500>
		>,
		Scale<
			HoldPeakF<
				Ifon<
					SwingSpeed<400>,
					Int<0>
				>,
				Int<150>,
				Int<32000>
			>,
			Int<3000>,
			Int<10000>
		>
	>
>;
		
// Lightning Swing
using Swing_Lightning = AlphaL<
	BrownNoiseFlickerL<
		StripesX<
			//Int<2600>,
			SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<2600>, Int<2000>, Int<500>, Int<4000>>,
			Scale<
				IncrementWithReset<
					ThresholdPulseF<
						StrobeF<
							Int<6>,
							Int<1>
						>,
						Int<32000>
					>,
					ThresholdPulseF<
						ThresholdPulseF<
							IsLessThan<
								HoldPeakF<
									Ifon<
										SwingSpeed<400>,
										Int<0>
									>,
									Int<150>,
									Int<32000>
								>,
								Int<8000>
							>,
							Int<32000>
						>
					>,
					Int<30000>,
					Int<3000>
				>,
				Int<-1200>,
				Int<-4000>
			>,
			SWINGCOLOR,
			COLOR_MIX_P<50, SWINGCOLOR>,
			COLOR_MIX_P<50, SWINGCOLOR, White>
		>,
		Int<50>
	>,
	SmoothStep<
		IncrementWithReset<
			Scale<
				IsGreaterThan<
					HoldPeakF<
						Ifon<
							SwingSpeed<400>,
							Int<0>
						>,
						Int<150>,
						Int<32000>
					>,
					Int<18000>
				>,
				Int<0>,
				ThresholdPulseF<
					StrobeF<
						Scale<
							HoldPeakF<
								Ifon<
									SwingAcceleration<>,
									Int<0>
								>,
								Int<150>,
								Int<32000>
							>,
							Int<20>,
							Int<200>
						>,
						Int<1>
					>,
					Int<32000>
				>
			>,
			ThresholdPulseF<
				IsLessThan<
					HoldPeakF<
						Ifon<
							SwingSpeed<400>,
							Int<0>
						>,
						Int<150>,
						Int<32000>
					>,
					Int<8000>
				>,
				Int<32000>
			>,
			Int<42000>,
			Int<1500>
		>,
		Int<-8000>
	>
>;

// Clash Responsive Charge Buildup
using Swing_Clash_BuildUp = Layers <
	AlphaL<
		Layers<
			// Stripes one way
			StripesX<
				//Int<6000>,
				SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<6000>, Int<4000>, Int<500>, Int<4000>>,
				Scale<
					IncrementWithReset<
						EffectPulseF<EFFECT_CLASH>,
						EffectPulseF<EFFECT_LOCKUP_BEGIN>,
						Int<32768>,
						Int<4096> // 8 clashes to full strength.
					>,
					Int<-100>, // Min
					Int<-2000> // Max
				>,
				COLOR_MIX<Int<9000>, SWINGCOLOR>,
				SWINGCOLOR,
				COLOR_MIX<Int<18000>, SWINGCOLOR>
			>,
			// 50% Stripes other way
			AlphaL<
				StripesX<
					//Int<6000>,
					SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<6000>, Int<4000>, Int<500>, Int<4000>>,
					Scale<
						IncrementWithReset<
							EffectPulseF<EFFECT_CLASH>,
							EffectPulseF<EFFECT_LOCKUP_BEGIN>,
							Int<32768>,
							Int<4096> // 8 clashes to full strength.
						>,
						Int<100>, // Min
						Int<2000> // Max
					>,
					COLOR_MIX<Int<9000>, SWINGCOLOR>,
					SWINGCOLOR,
					COLOR_MIX<Int<18000>, SWINGCOLOR>
				>,
				Int<16384>
			>,
			// Random LED Flicker
			AlphaL<
				RandomPerLEDFlickerL<Black>,
				IncrementWithReset<
					EffectPulseF<EFFECT_CLASH>,
					EffectPulseF<EFFECT_LOCKUP_BEGIN>,
					Int<16384>, //32768>,
					Int<2048> //4096> // 8 clashes to full strength.
				>
			>,
			// Sparks
			TrSparkX_Random<White, Int<0>>,
			TrSparkX_Random<White, Int<0>>,
			TrSparkX_Random<White, Int<0>>,
			TrSparkX_Random<White, Int<32768>>,
			TrSparkX_Random<White, Int<32768>>,
			TrSparkX_Random<White, Int<32768>>
		>,
		IncrementWithReset<
			EffectPulseF<EFFECT_CLASH>,
			EffectPulseF<EFFECT_LOCKUP_BEGIN>,
			Int<24576>,
			Int<3072> // 8 clashes to full?
		>
	>,

	// Lockup Effect Flash
	Remap<
		CenterDistF<>,
		TransitionEffectL<
			TrConcat<
				TrWipe<300>,
				AlphaL<
					LOCKUPCOLOR, //White,
					/*
					RandomBlinkL<
						Int<300>,
						White
					>,
					*/
					IncrementWithReset<
						EffectPulseF<EFFECT_CLASH>,
						EffectPulseF<EFFECT_LOCKUP_BEGIN>,
						Int<32768>,
						Int<4096> // 8 clashes to full strength.
					>
				>,
				TrFade<300>
			>,
			EFFECT_LOCKUP_BEGIN //EFFECT_BLAST
		>
	>
>;