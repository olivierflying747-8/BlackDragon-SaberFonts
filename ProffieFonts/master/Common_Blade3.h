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
			//Int<0>,
			//Int<6000>
			Mult<
				Int<8937>, //33%
				IntArg<EMITTER_SIZE_ARG, 2000>
			>,
			Int<-1000>
		>
	>,
	AlphaL<
		RotateColorsX<
			Variation,
			EMITTERCOLOR
		>,
		Bump<
			//Int<0>,
			//Int<22000>
			IntArg<EMITTER_SIZE_ARG, 2000>,
			Int<-1000>
		>
	>
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

// RandomPerLEDFlicker (2 Color)
using Style3_RandomPerLEDFlicker = RandomPerLEDFlicker<
	Mix<
		Int<10280>, 
		Black, 
		ALTCOLOR2
	>, 
	Mix<
		Int<3855>, 
		Black, 
		ALTCOLOR3
	>
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

// Rain Effect
using Style3_Sparkle = SparkleL<
	ALTCOLOR3
>;

// Cylon
using Style3_Cylon = Cylon<
	ALTCOLOR3,
	1000,
	200
>;
