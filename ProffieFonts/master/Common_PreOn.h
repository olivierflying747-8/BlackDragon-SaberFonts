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
			PREON_SIZE, 
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
				PREON_SIZE
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
				PREON_SIZE
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
				PREON_SIZE, 
				Sum<
					PREON_SIZE, 
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
		RandomPerLEDFlickerL<PREONCOLOR>, 
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
			PREON_SIZE
		>
		*/
		SmoothStep<
			PREON_SIZE,
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
				PREON_SIZE
			>
		>
		*/
		SmoothStep<
			PREON_SIZE,
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
				PREON_SIZE
			>
		>
		*/
		SmoothStep<
			PREON_SIZE,
			Int<-4000>
		>
	>,
	TrBoing<1000,3>
>;

// Emitter Heat Up
using PreOn_Emitter_Heatup = TrConcat<
	TrExtendX<
		WavLen<EFFECT_PREON>,
		TrFade<100>
	>,
	AlphaL<
		HumpFlickerL<
			Mix<
				Trigger<
					EFFECT_PREON,
					Mult<
						WavLen<EFFECT_PREON>,
						Int<24000>
					>,
					WavLen<EFFECT_PREON>,
					Int<500>
				>,
				PREONCOLOR,
				White
			>,
			20
		>,
		SmoothStep<
			PREON_SIZE,
			Int<-3000>
		>
	>,
	TrFade<200>
>;

// Faulty Ignition
using PreOn_Faulty_Ignition = TrConcat<
	TrInstant,
	AlphaL<
		Mix<
			Trigger<
				EFFECT_PREON,
				Mult<
					Int<16384>,
					WavLen<EFFECT_PREON>
				>,
				Mult<
					Int<10922>,
					WavLen<EFFECT_PREON>
				>,
				Mult<
					Int<5462>,
					WavLen<EFFECT_PREON>
				>
			>,
			BrownNoiseFlicker<
				Black,
				PREONCOLOR,
				100
			>,
			RandomPerLEDFlicker<
				PREONCOLOR,
				Rgb<50,50,50>
			>,
			BrownNoiseFlicker<
				Mix<
					NoisySoundLevel,
					PREONCOLOR,
					RotateColorsX<
						Int<4000>,
						PREONCOLOR
					>
				>,
				White,
				50
			>
		>,
		SmoothStep<
			Scale<
				NoisySoundLevel,
				Int<-10000>,
				Int<36000>
			>,
			Int<-4000>
		>
	>,
	TrDelayX<
		WavLen<EFFECT_PREON>
	>
>;

// Faulty Fire Ignition
using PreOn_Faulty_Fire_Ignition = TrConcat<
	TrExtendX<
		WavLen<EFFECT_PREON>,
		TrWipe<100>
	>,
	AlphaL<
		StripesX<
			Int<3000>,
			Sin<
				Int<60>,
				Int<-1600>,
				Int<-4000>
			>,
			PREONCOLOR,
			COLOR_MIX<Int<10772>, PREONCOLOR>,
			COLOR_MIX<Int<24000>, PREONCOLOR>
		>,
		SmoothStep<
			NoisySoundLevel,
			Int<-3000>
		>
	>,
	TrFade<100>
>;

// Erratic (Apocalypse Version)
using PreOn_Erratic = TrConcat<
	TrExtendX<
		Mult<
			WavLen<EFFECT_PREON>,
			Int<16384>
		>,
		TrInstant
	>,
	Layers<
		AlphaL<
			Mix<
				Trigger<
					EFFECT_PREON, 
					Int<3000>,
					Int<2000>,
					Int<1000>
				>,
				BrownNoiseFlicker<
					Black,
					PREONCOLOR,
					100
				>,
				RandomPerLEDFlicker<
					PREONCOLOR,
					COLOR_MIX<Int<8192>, PREONCOLOR>
				>,
				BrownNoiseFlicker<
					Mix<
						NoisySoundLevel,
						PREONCOLOR,
						RotateColorsX<
							Int<4000>,
							PREONCOLOR
						>
					>,
					RotateColorsX<
						Int<1200>,
						PREONCOLOR
					>,
					50
				>
			>,
			SmoothStep<
				Scale<
					NoisySoundLevel,
					Int<-1000>,
					Int<25000>
				>,
				Int<-4000>
			>
		>,
		AlphaL<
			HumpFlickerL<
				AlphaL<
					White,
					Trigger<
						EFFECT_PREON,
						Mult<
							WavLen<EFFECT_PREON>,
							Int<8176>
						>,
						WavLen<EFFECT_PREON>,
						Mult<
							WavLen<EFFECT_PREON>,
							Int<16384>
						>
					>
				>,
				40
			>,
			SmoothStep<
				PREON_SIZE,
				Int<-4000>
			>
		>
	>,
	TrLoopN<
		10,
		TrWaveX<
			PREONCOLOR,
			Int<200>,
			Int<200>,
			Scale<
				Trigger<
					EFFECT_PREON,
					Int<0>,
					Mult<
						WavLen<EFFECT_PREON>,
						Int<24576>
					>,
					Mult<
						WavLen<EFFECT_PREON>,
						Int<8192>
					>
				>,
				Int<400>,
				Int<100>
			>,
			Int<0>
		>
	>
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
		COLOR_MIX_P<12, PREONCOLOR>, //Rgb<0, 31, 0>, // PREON COLOR / 8.226
		AlphaL<
			AudioFlicker<
				RotateColorsX<Variation, COLOR_MIX_P<12, PREONCOLOR>>, //Rgb<0,31,0>
				RotateColorsX<Variation, COLOR_MIX_P<12, PREONCOLOR>> //Rgb<0,15,0>
			>,
			Int<100>
		>
	>,
	TrInstant
>;