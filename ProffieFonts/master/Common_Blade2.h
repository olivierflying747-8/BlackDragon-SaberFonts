// ===================== BLADE STYLES 2 =======================
// Using ALTCOLOR and ALTCOLOR2

// AudioFlicker
using Style2_AudioFilter = AudioFlicker<
	TRANSPARENT,
	ALTCOLOR2
>;

// Random Flicker, BASE / ALT color
using Style2_RandomFlicker = RandomFlicker<
	TRANSPARENT,
	ALTCOLOR2
>;

// AudioFlicker with RotateColors (2 color)
using Style2_AudioFilter_Rotate = AudioFlicker<
	TRANSPARENT,
	RotateColorsX<Variation, ALTCOLOR2>
>;

// Pusling Blade
using Style2_Pulsing_Rotate = Pulsing<
	TRANSPARENT,
	RotateColorsX<Variation, ALTCOLOR2>,
	1200
>;

// RandomPerLEDFlicker (2 Color)
using Style2_RandomPerLEDFlicker = AlphaL<
	RandomPerLEDFlicker<
		Black,
		Mix<
			Int<3855>,
			Black,
			ALTCOLOR2
		>
	>,
	Int<16384>
>;

// Hump Waves (2 Color)
using Style2_HumpWave = Layers <
	TransitionLoopL<
		TrWaveX<
			HumpFlickerL<RotateColorsX<Variation, ALTCOLOR>, 40>,
			Int<250>,
			Int<100>,
			Int<200>,
			Int<0>
		>
	>,
	TransitionLoopL<
		TrWaveX<
			HumpFlickerL<RotateColorsX<Variation, ALTCOLOR2>, 40>,
			Int<350>,
			Int<100>,
			Int<300>,
			Int<0>
		>
	>
>;

// Sparkle
using Style2_Sparkle = SparkleL<
	ALTCOLOR2
>;

// Brown Noise with Stripes, ALTCOLOR2
using Style2_BrownNoiseFlicker = BrownNoiseFlicker<
	TRANSPARENT,
	Stripes<
		3000, 
		-4000, 
		//Rgb<50, 50, 75>, // ALT COLOR / 3.4
		Mix<
			Int<9638>,
			Black, 
			ALTCOLOR2
		>,
		//Rgb<100, 100, 150>, // ALT COLOR / 1.7
		Mix<
			Int<19275>,
			Black, 
			ALTCOLOR2
		>,
		//Rgb<10, 10, 15>, // ALT COLOR / 17
		Mix<
			Int<1928>,
			Black, 
			ALTCOLOR2
		>,
		//Rgb<150, 150, 225> // ALT COLOR
		ALTCOLOR2
	>, 
	200
>;

// StripesX Slownoise
using Style2_StripesX_SlowNoise = AlphaL<
	StripesX<
		Int<1500>,
		Scale<
			SlowNoise<Int<2500>>,
			Int<-3000>,
			Int<-5000>
		>,
		Black,
		Mix<
			Int<10280>,
			Black,
			ALTCOLOR2
		>,
		Black,
		Mix<
			Int<2570>,
			Black,
			ALTCOLOR2
		>,
		Black
	>,
	Int<16384>
>;

// Fett263 Smoke Blade Fire layer, ALT Color
using Style2_FireBlade = AlphaL <
	StyleFire<
		RotateColorsX<Variation, ALTCOLOR2>,
		RotateColorsX<
			Variation,
			//Rgb<2,2,0> // ALT / 127.5
			Mix<
				Int<257>,
				Black,
				ALTCOLOR2
			>
		>,
		0,
		1,
		FireConfig<10,2000,2>,
		FireConfig<10,2000,2>,
		FireConfig<10,2000,2>,
		FireConfig<0,0,25>
	>,
	Int<10000>
>;

// Style Fire
using Style2_Fire = AlphaL< 
	StyleFire<
		ALTCOLOR,
		ALTCOLOR2,
		0,
		2
	>,
	Int<16384>
>;

// Cylon
using Style2_Cylon = AlphaL<
	Cylon<
		ALTCOLOR2,
		5,
		20
	>,
	Int<16384>
>;

// Thunderstorm ???
using Style2_LightningFlash = TransitionLoopL<
	//TRANSPARENT,
	TrConcat<
		TrDelayX< // Random Timer
			Scale<
				SlowNoise<Int<3000>>,
				Int<100>,
				Int<2000>
			>
		>,
		AlphaL< // Invisible color
			ALTCOLOR,
			Int<0>
		>,
		TrConcat<
			TrInstant,
			AlphaL<
				HumpFlickerL<Black, 16384>,
				Bump<
					Int<0>,
					Int<32768>
				>
			>,
			TrInstant
		>,

		TrBoing<500, 3>
	
		/*
		TrBoing<500,3>,
		Black,
		Layers<
			Stripes<
				10000,
				100,
				RotateColorsX<Variation, BASECOLOR_50>,
				RotateColorsX<
					Variation,
					Mix<
						Int<4096>, //12.5%
						Black, 
						BASECOLOR
					>
				>,
				RotateColorsX<Variation, ALTCOLOR3>
			>,
			AlphaL<
				Stripes<
					8000,
					-200,
					RotateColorsX<Variation, BASECOLOR>,
					RotateColorsX<Variation, ALTCOLOR_25>
				>,
				Int<16384> //50%
			>
		>,
		TrDelayX< // Random Timer
			Scale<
				SlowNoise<Int<3000>>,
				Int<100>,
				Int<2000>
			>
		>
	//	*/
	>
>;