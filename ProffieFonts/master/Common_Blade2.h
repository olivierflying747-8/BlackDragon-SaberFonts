// ===================== BLADE STYLES 2 =======================
// Using ALTCOLOR and ALTCOLOR2

// AudioFlicker
using Style2_AudioFilter = AudioFlicker<
	TRANSPARENT,
	RotateColorsX<Variation, ALTCOLOR2>
>;

// Random Flicker, BASE / ALT color
using Style2_RandomFlicker = RandomFlicker<
	TRANSPARENT,
	ALTCOLOR2
>;

// Pusling Blade
using Style2_Pulsing = Pulsing<
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

// Hump Flicker L (AltColor2, Random Position)
using Style2_HumpFlicker_Random = AlphaL<
	HumpFlickerL<ALTCOLOR2, 10>,
	Bump<
		RandomF,
		Int<20000>
	>
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
			Int<10280>, //33%
			Black,
			RotateColorsX<Variation, ALTCOLOR2>
		>,
		Black,
		Mix<
			Int<2570>,
			Black,
			RotateColorsX<Variation, ALTCOLOR2>
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

// Lightning Flash
using Style2_LightningFlash = TransitionLoop<
	AlphaL< // Invisible color
		ALTCOLOR2,
		Int<0>
	>,
	TrConcat<
		TrBoing<500, 3>,
		TrConcat<
			TrFade<100>,
			AlphaL<
				HumpFlickerL<ALTCOLOR2, 10>,
				Bump<
					RandomF,
					Int<20000>
				>
			>,
			TrFade<100>
		>,
		TrDelayX< // Random Timer
			Scale<
				SlowNoise<Int<3000>>,
				Int<100>,
				Int<2000>
			>
		>
	>
>;