// ===================== BLADE STYLES 3 =======================
// Using ALTCOLOR3 and ALTCOLOR2

// AudioFlicker
using Style3_AudioFilter = AudioFlicker<
	TRANSPARENT,
	ALTCOLOR3
>;

// Random Flicker, BASE / ALT color
using Style3_RandomFlicker = RandomFlicker<
	TRANSPARENT,
	ALTCOLOR3
>;

// AudioFlicker with RotateColors (2 color)
using Style3_AudioFilter_Rotate = AudioFlicker<
	TRANSPARENT,
	RotateColorsX<Variation, ALTCOLOR3>
>;

// Pusling Blade
using Style3_Pulsing_Rotate = Pulsing<
	TRANSPARENT,
	RotateColorsX<Variation, ALTCOLOR3>,
	1200
>;

// RandomPerLEDFlicker (2 Color)
using Style3_RandomPerLEDFlicker = AlphaL<
	RandomPerLEDFlicker<
		Black,
		Mix<
			Int<3855>,
			Black,
			ALTCOLOR3
		>
	>,
	Int<16384>
>;

// Hump Waves (2 Color)
using Style3_HumpWave = Layers <
	TransitionLoopL<
		TrWaveX<
			HumpFlickerL<RotateColorsX<Variation, ALTCOLOR2>, 40>,
			Int<250>,
			Int<100>,
			Int<200>,
			Int<0>
		>
	>,
	TransitionLoopL<
		TrWaveX<
			HumpFlickerL<RotateColorsX<Variation, ALTCOLOR3>, 40>,
			Int<350>,
			Int<100>,
			Int<300>,
			Int<0>
		>
	>
>;

// Sparkle
using Style3_Sparkle = SparkleL<
	ALTCOLOR3
>;

// Brown Noise with Stripes, ALTCOLOR3
using Style3_BrownNoiseFlicker = BrownNoiseFlicker<
	TRANSPARENT,
	Stripes<
		3500, 
		-2500, 
		//Rgb<50, 50, 75>, // ALT COLOR / 3.4
		Mix<
			Int<9638>,
			Black, 
			ALTCOLOR3
		>,
		//Rgb<100, 100, 150>, // ALT COLOR / 1.7
		Mix<
			Int<19275>,
			Black, 
			ALTCOLOR3
		>,
		//Rgb<10, 10, 15>, // ALT COLOR / 17
		Mix<
			Int<1928>,
			Black, 
			ALTCOLOR3
		>,
		//Rgb<150, 150, 225> // ALT COLOR
		ALTCOLOR3
	>, 
	200
>;

// StripesX Slownoise
using Style3_StripesX_SlowNoise = AlphaL<
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
			RotateColorsX<Variation, ALTCOLOR3>
		>,
		Black,
		Mix<
			Int<2570>,
			Black,
			RotateColorsX<Variation, ALTCOLOR3>
		>,
		Black
	>,
	Int<16384>
>;

// Fett263 Smoke Blade Fire layer, ALT Color
using Style3_FireBlade = AlphaL <
	StyleFire<
		RotateColorsX<Variation, ALTCOLOR3>,
		RotateColorsX<
			Variation,
			//Rgb<2,2,0> // ALT / 127.5
			Mix<
				Int<257>,
				Black,
				ALTCOLOR3
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
using Style3_Fire = AlphaL< 
	StyleFire<
		ALTCOLOR2,
		ALTCOLOR3,
		0,
		2
	>,
	Int<16384>
>;

// Cylon
using Style3_Cylon = AlphaL<
	Cylon<
		ALTCOLOR3,
		5,
		20
	>,
	Int<16384>
>;

// Emitter Flare
using Style3_EmitterFlare = AlphaL<
	AudioFlickerL<
		EMITTERCOLOR
	>, 
	SmoothStep<
		IntArg<EMITTER_SIZE_ARG, 2000>, 
		Int<-6000>
	>
>;

// Timed "breathing" emitter flare 
//- NOTE: Due to the way Proffie works, this isn't always "lined up" and might be slightly ahead or slightly behind the hum's breathing. To fix you can turn the saber off and back on until it's lined up. The timing is right, but the code runs in the background even after turning the saber off so it doesn't always start "on time."
using Style3_EmitterBreathe = Mix<
	Sin<Int<8>>,
	AlphaL<
		RotateColorsX<
			Variation,
			EMITTERCOLOR
		>,
		Bump<
			Int<0>,
			//Int<6000>
			Mult<
				Int<8937>, //33%
				IntArg<EMITTER_SIZE_ARG, 2000>
			>
		>
	>,
	AlphaL<
		RotateColorsX<
			Variation,
			EMITTERCOLOR
		>,
		Bump<
			Int<0>,
			//Int<22000>
			IntArg<EMITTER_SIZE_ARG, 2000>
		>
	>
>;

// Emitter Pulse
using Style3_Emitter_Pulse = TransitionLoopL<
	TrConcat<
		TrDelayX<
			Scale<
				SlowNoise<Int<1000>>,
				Int<300>,
				Int<3000>
			>
		>,
		AlphaL<
			EMITTERCOLOR,
			Int<0>
		>,
		TrSparkX<
			EMITTERCOLOR,
			Scale<
				NoisySoundLevel,
				Int<200>,
				Int<600>
			>,
			Int<250>,
			Int<0>
		>
	>
>;