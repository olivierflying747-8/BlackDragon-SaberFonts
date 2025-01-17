// ===================== POST OFF STYLES =======================

// Emitter cool off.
using PostOff_EmitterCoolOff = TrConcat<
	TrInstant,
	AlphaL<
		POSTOFFCOLOR,
		Bump<
			Int<0>,
			EMITTER_SIZE
		>
	>,
	TrFadeX<
		Mult<
			Scale<
				IsLessThan<
					WavLen<EFFECT_POSTOFF>,
					Int<200>
				>,
				WavLen<EFFECT_POSTOFF>,
				Int<4000>
			>,
			Int<10923>
		>
	>,
	AlphaL<
		Orange,
		Bump<
			Int<0>,
			EMITTER_SIZE
		>
	>,
	TrFadeX<
		Mult<	
			Scale<
				IsLessThan<
					WavLen<EFFECT_POSTOFF>,
					Int<200>
				>,
				WavLen<EFFECT_POSTOFF>,
				Int<4000>
			>,
			Int<10923>
		>
	>,
	AlphaL<
		Red,
		Bump<
			Int<0>,
			EMITTER_SIZE
		>
	>,
	TrFadeX<
		Mult<
			Scale<
				IsLessThan<
					WavLen<EFFECT_POSTOFF>,
					Int<200>
				>,
				WavLen<EFFECT_POSTOFF>,
				Int<4000>
			>,
			Int<10923>
		>
	>
>;

// Emitter Spark
using PostOff_Emitter_Spark = TrConcat<
	TrInstant,
	AlphaL<
		BrownNoiseFlickerL<
			POSTOFFCOLOR,
			Int<30>
		>,
		Bump<
			Int<0>,
			Scale<
				SlowNoise<Int<2000>>,
				EMITTER_SIZE,
				Percentage<EMITTER_SIZE, 150>
			>
		>
	>,
	TrSmoothFadeX< //TrDelayX<
		Scale<
			IsLessThan<
				WavLen<EFFECT_POSTOFF>,
				Int<200>
			>,
			WavLen<EFFECT_POSTOFF>,
			Int<4000>
		>
	>
>;

// Emitter Glow
using PostOff_Emitter_Glow = TrConcat<
	TrInstant,
	TRANSPARENT,
	TrJoin<
		TrDelay<1000>,
		TrInstant
	>,
	AlphaL<
		POSTOFFCOLOR,
		Bump<
			Int<0>,
			EMITTER_SIZE
		>
	>,
	TrSmoothFadeX<
		Scale<
			IsLessThan<
				WavLen<EFFECT_POSTOFF>,
				Int<200>
			>,
			WavLen<EFFECT_POSTOFF>,
			Int<4000>
		>
	>
>;