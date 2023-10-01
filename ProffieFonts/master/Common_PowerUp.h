// ===================== POWER UP STYLES =======================

// Flash
using Powerup_Flash = TrConcat<
	TrJoin<
		TrDelayX<IgnitionTime<300>>,
		TrDelayX<IntArg<IGNITION_DELAY_ARG, 0>> //TrInstant
	>,
	IGNITIONCOLOR,
	TrFade<1000>
>;

// Surge
using Powerup_Surge = TrConcat<
	TrDelayX<IntArg<IGNITION_DELAY_ARG, 0>>, //TrInstant
	AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,
	TrFade<1200>
>;

// Flash Fade
using Powerup_Flash_Fade = TrConcat<
	TrDelayX<IntArg<IGNITION_DELAY_ARG, 0>>, //TrInstant
	AlphaL<
		AudioFlicker<
			IGNITIONCOLOR, //Blue,
			Mix<
				Int<16384>,
				Black, 
				IGNITIONCOLOR //SteelBlue
			>
		>,
		Bump<
			Int<0>,
			IntArg<EMITTER_SIZE_ARG, 2000> //Int<8000>
		>
	>,
	TrFade<600>
>;

// Power Burst Forward
using Powerup_Burst_Forward = TrConcat<
	TrExtendX<
		IgnitionTime<300>, 
		TrDelayX<IntArg<IGNITION_DELAY_ARG, 0>> //TrInstant
	>, 
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
	TrFade<800>
>;

// Unstable Powerup Forward
using Powerup_Unstable_Forward = TrConcat<
	TrExtendX<
		IgnitionTime<300>, 
		TrDelayX<IntArg<IGNITION_DELAY_ARG, 0>> //TrInstant
	>, 
	Stripes<
		3000, 
		-3500, 
		IGNITIONCOLOR, 
		RandomPerLEDFlicker<
			Mix<
				Int<7710>, 
				Black, 
				IGNITIONCOLOR
			>, 
			Black
		>, 
		BrownNoiseFlicker<
			IGNITIONCOLOR, 
			Mix<
				Int<3855>, 
				Black, 
				IGNITIONCOLOR
			>,
			200
		>, 
		RandomPerLEDFlicker<
			Mix<
				Int<3137>, 
				Black, 
				IGNITIONCOLOR
			>,
			Mix<
				Int<3855>, 
				Black, 
				IGNITIONCOLOR
			>
		>
	>, 
	TrFade<800>
>;

// Unstable Powerup Bright Forward
using Powerup_Unstable_Bright_Forward = TrConcat<
	TrDelayX<IntArg<IGNITION_DELAY_ARG, 0>>, //TrInstant
	Stripes<
		3000,
		-3500,
		RotateColorsX<
			Variation,
			//Rgb<100,100,150> //IGNITION_COLOR_ARG
			IGNITIONCOLOR
		>,
		RandomPerLEDFlicker<
			RotateColorsX<
				Variation,
				//Rgb<60,60,80> //IGNITION_COLOR_ARG / 2
				Mix<
					Int<16384>,
					Black, 
					IGNITIONCOLOR
				>
			>,
			Black
		>,
		BrownNoiseFlicker<
			RotateColorsX<
				Variation,
				//Rgb<110,115,140>  //IGNITION_COLOR_ARG + 25% white?
				Mix<
					Int<8192>,
					IGNITIONCOLOR,
					White
				>
			>,
			RotateColorsX<
				Variation,
				//Rgb<60,60,80> // IGNITION_COLOR_ARG / 2
				Mix<
					Int<16384>,
					Black, 
					IGNITIONCOLOR
				>
			>,
			200
		>,
		RandomPerLEDFlicker<
			RotateColorsX<
				Variation,
				Rgb<128,128,128> // White flicker
			>,
			RotateColorsX<
				Variation,
				//Rgb<60,60,80> // IGNITION_COLOR_ARG / 2
				Mix<
					Int<16384>,
					Black, 
					IGNITIONCOLOR
				>
			>
		>
	>,
	TrFadeX<
		Percentage<
			WavLen<>,
			65
		>
	>
>;

// Stabalize
using Powerup_Stabalize = TrConcat<
	TrDelayX<IntArg<IGNITION_DELAY_ARG, 0>>, //TrInstant
	Ignition_FlickerStripes,
	TrFade<400>,
	Ignition_FlickerStripes,
	TrFade<450>,
	HumpFlickerL<
		AlphaL<
			RotateColorsX<
				Variation,
				//Rgb<90,180,255> // IGNITION_COLOR_ARG
				IGNITIONCOLOR
			>,
			Int<19000>
		>,
		25
	>,
	TrFade<2875>
>;