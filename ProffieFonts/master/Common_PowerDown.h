// ===================== POWER DOWN STYLES =======================

// Flash
using PowerDown_Flash = TrConcat<
	TrJoin<
		TrDelayX<RetractionTime<0>>,
		TrDelayX<IntArg<RETRACTION_DELAY_ARG, 0>> //TrInstant
	>,
	RETRACTIONCOLOR,
	TrFade<1000>
>;

// Power Burst Reverse
using PowerDown_Burst_Reverse = TrConcat<
	TrExtendX<
		RetractionTime<0>, 
		TrDelayX<IntArg<RETRACTION_DELAY_ARG, 0>> //TrInstant
	>, 
	StripesX<
		//Int<5000>, 
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<5000>, Int<2500>, Int<500>, Int<4000>>,
		//Int<2500>, 
		BLADE_ANGLE_SCLAE<Int<2500>, Int<1500>, Int<500>, Int<4000>>,

		RETRACTIONCOLOR, 
		COLOR_MIX<Int<7710>, RETRACTIONCOLOR>, 
		COLOR_MIX<Int<3855>, RETRACTIONCOLOR>
	>, 
	TrFade<800>
>;

// Unstable Cooldown Reverse
using PowerDown_Unstable_Reverse = TrConcat<
	TrExtendX<
		RetractionTime<0>, 
		TrDelayX<IntArg<RETRACTION_DELAY_ARG, 0>> //TrInstant
	>, 
	StripesX<
		//Int<3000>, 
		SWING_SPEED_SCLAE<SWING_SPEED_DEFAULT, Int<3000>, Int<1500>, Int<500>, Int<4000>>,
		//Int<3500>, 
		BLADE_ANGLE_SCLAE<Int<3500>, Int<2000>, Int<500>, Int<4000>>,

		RETRACTIONCOLOR, 
		RandomPerLEDFlicker<
			COLOR_MIX<Int<7710>, RETRACTIONCOLOR>, 
			Black
		>, 
		BrownNoiseFlicker<
			RETRACTIONCOLOR, 
			COLOR_MIX<Int<3855>, RETRACTIONCOLOR>,
			200
		>, 
		RandomPerLEDFlicker<
			COLOR_MIX<Int<3137>, RETRACTIONCOLOR>,
			COLOR_MIX<Int<3855>, RETRACTIONCOLOR>
		>
	>, 
	TrFade<800>
>;

// Bright Humpflicker
using PowerDown_Bright_Hump = TrConcat<
	TrDelayX<IntArg<RETRACTION_DELAY_ARG, 0>>, //TrInstant,
	HumpFlickerL<RETRACTIONCOLOR, 40>, 
	TrFadeX<
		Percentage<WavLen<>, 125>
	>
>;

// Smoke Blade Fade
using PowerDown_Smoke_Reverse = TrConcat <
	TrDelayX<IntArg<RETRACTION_DELAY_ARG, 0>>, //TrInstant,
	TrWipeInX<RetractionTime<0>>,
	// Is this color even needed? does it even work?
//	/*
	AlphaL<
		BaseStyle_SmokeBlade, //Green,
		Bump<
			Int<0>,
			Int<16000>
		>
	>,
//	*/
	TrFade<2000>
	/* // Emitter Cooldown, moved to POST OFF.
	AlphaL<
		//Rgb<0, 63, 0>,
		Mix<
			Int<7710>,
			Black, 
			RETRACTIONCOLOR
		>,
		Bump<
			Int<0>,
			//Int<14000>
			Sum<
				Int<4000>,
				IntArg<EMITTER_SIZE_ARG, 2000>
			>
		>
	>,
	TrFade<1500>,
	AlphaL<
		Orange,
		Bump<
			Int<0>,
			//Int<8000>
			Sum<
				Int<2000>,
				IntArg<EMITTER_SIZE_ARG, 2000>
			>
		>
	>,
	TrFade<1000>,
	AlphaL<
		Red,
		Bump<
			Int<0>,
			//Int<6000>
			IntArg<EMITTER_SIZE_ARG, 2000>
		>
	>,
	TrFade<500>
	*/
>;