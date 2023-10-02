// ===================== PREON STYLES =======================

// Overload
using PreOn_Overload = TrConcat<
	TrFadeX<
		Mult<
			Int<8192>, 
			WavLen<EFFECT_PREON>
		>
	>, 
	AlphaL<
		HumpFlickerL<PREONCOLOR, 10>, 
		SmoothStep<
			IntArg<PREON_SIZE_ARG, 2000>, 
			Int<-4000>
		>
	>, 
	TrFadeX<
		Mult<
			Int<8192>, 
			WavLen<EFFECT_PREON>
		>
	>, 
	AlphaL<
		HumpFlickerL<PREONCOLOR, 15>, 
		SmoothStep<
			Sum<
				Int<2000>, 
				IntArg<PREON_SIZE_ARG, 2000>
			>, 
			Int<-4000>
		>
	>, 
	TrFadeX<
		Mult<
			Int<8192>, 
			WavLen<EFFECT_PREON>
		>
	>, 
	AlphaL<
		HumpFlickerL<PREONCOLOR, 20>, 
		SmoothStep<
			Sum<
				Int<4000>, 
				IntArg<PREON_SIZE_ARG, 2000>
			>, 
			Int<-4000>
		>
	>, 
	TrBoingX<
		Mult<
			Int<8192>, 
			WavLen<EFFECT_PREON>
		>, 
		3
	>
>;

// Sparking
using PreOn_Sparking = TrConcat<
	TrInstant, 
	AlphaL<
		BrownNoiseFlickerL<
			PREONCOLOR,
			Int<30>
		>, 
		SmoothStep<
			Scale<
				SlowNoise<Int<2000>>, 
				IntArg<PREON_SIZE_ARG, 2000>, 
				Sum<
					IntArg<PREON_SIZE_ARG, 2000>, 
					Int<4000>
				>
			>, 
			Int<-2000>
		>
	>, 
	TrDelayX<WavLen<EFFECT_PREON>>
>;

// Broken Ignition
using PreOn_Broken_Ignition = TrConcat<
	TrInstant, 
	AlphaL<
		RandomPerLEDFlicker<
			PREONCOLOR,
			Black
		>, 
		SmoothStep<
			Scale<
				NoisySoundLevel, 
				Int<-10000>, 
				Int<36000> // Extend as far as tip?
			>, 
			Int<-4000> // Start at base of blade.
		>
	>, 
	TrDelayX<
		WavLen<EFFECT_PREON>
	>
>;

// Emitter Warmup
using PreOn_Emitter_Warmup = TrConcat<
	TrFadeX<
		Mult<
			Int<10923>,
			WavLen<EFFECT_PREON>
		>
	>,
	AlphaL<
		HumpFlickerL<Red, 10>,
		/*
		Bump<
			Int<0>,
			IntArg<PREON_SIZE_ARG, 2000>
		>
		*/
		SmoothStep<
			IntArg<PREON_SIZE_ARG, 2000>,
			Int<-2000>
		>
	>,
	//TrFade<2950>,
	TrFadeX<
		Mult<
			Int<10923>,
			WavLen<EFFECT_PREON>
		>
	>,
	AlphaL<
		HumpFlickerL<Orange, 15>,
		/*
		Bump<
			Int<0>, 
			//Int<10000>
			Sum<
				Int<2000>,
				IntArg<PREON_SIZE_ARG, 2000>
			>
		>
		*/
		SmoothStep<
			IntArg<PREON_SIZE_ARG, 2000>,
			Int<-3000>
		>
	>,
	//TrFade<3000>,
	TrFadeX<
		Mult<
			Int<10923>,
			WavLen<EFFECT_PREON>
		>
	>,
	AlphaL<
		HumpFlickerL<PREONCOLOR, 20>,
		/*
		Bump<
			Int<0>, 
			//Int<20000>
			Sum<
				Int<4000>,
				IntArg<PREON_SIZE_ARG, 2000>
			>
		>
		*/
		SmoothStep<
			IntArg<PREON_SIZE_ARG, 2000>,
			Int<-4000>
		>
	>,
	TrBoing<1000,3>
>;

// Dim Pre-Blade ignition
using PreOn_Dim_Blade = TrConcat<
	TrInstant,
	Black,
	TrWipeX<
		WavLen<EFFECT_PREON>
	>,
	Mix<
		NoisySoundLevel,
		//Rgb<0, 31, 0>, // PREON COLOR / 8.226
		Mix<
			Int<3983>,
			Black, 
			PREONCOLOR
		>,
		AlphaL <
			AudioFlicker<
				RotateColorsX<
					Variation, 
					//Rgb<0,31,0>
					Mix<
						Int<3983>,
						Black, 
						PREONCOLOR
					>
				>,
				RotateColorsX<
					Variation, 
					//Rgb<0,15,0>
					Mix<
						Int<3983>,
						Black, 
						PREONCOLOR
					>
				>
			>,
			Int<100>
		>
	>,
	TrInstant
>;