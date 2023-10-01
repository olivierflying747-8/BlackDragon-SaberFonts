// ================================ CLASH ================================

// Clash Effect A
using Clash_EffectA = TransitionEffectL<
	TrConcat<
		TrInstant, 
		AlphaL<
			CLASHCOLOR, 
			Bump<
				LockupScale, 
				Scale<
					ClashImpactF<>, 
					Int<12000>, 
					Int<60000>
				>
			>
		>, 
		TrFadeX<
			Scale<
				ClashImpactF<>, 
				Int<200>, 
				Int<400>
			>
		>
	>, 
	EFFECT_CLASH
>;

// Clash Effect B
using Clash_EffectB = // Mix B
TransitionEffectL<
	TrWaveX<
		CLASHCOLOR, 
		Scale<
			ClashImpactF<>, 
			Int<100>, 
			Int<400>
		>, 
		Int<100>, 
		Scale<
			ClashImpactF<>, 
			Int<100>, 
			Int<400>
		>, 
		LockupScale
	>, 
	EFFECT_CLASH
>;

// Clash Update flash
using Clash_Update = TrWaveX<
	CLASHCOLOR,
	Scale<
		ClashImpactF<>,
		Int<100>, 
		Int<400>
	>, 
	Int<100>, 
	Scale<
		ClashImpactF<>,
		Int<100>, 
		Int<400>
	>, 
	LockupScale
>;

// ================================ LOCKUP ================================

// Lockup Color
using Lockup_Color_Style = AlphaMixL<
	// Mix method
	Bump<
		LockupScale,
		Scale<
			SwingSpeed<100>, 
			Int<14000>, 
			Int<18000>
		>
	>, 
	// Color A
	BrownNoiseFlickerL<
		LOCKUPCOLOR, 
		Int<200>
	>, 
	// Color B
	StripesX<
		Int<1800>, 
		Scale<
			NoisySoundLevel, 
			Int<-3500>, 
			Int<-5000>
		>, 
		Mix<
			Int<6425>, 
			Black, 
			LOCKUPCOLOR
		>, 
		LOCKUPCOLOR, 
		Mix<
			Int<12850>, 
			Black, 
			LOCKUPCOLOR
		>
	>
>;

// TODO: Add more styles using TrRandom?
// Lockup Start
using Lockup_Start = TrConcat<
	TrExtend<
		50, 
		TrInstant
	>, 
	Mix<
		IsLessThan<
			ClashImpactF<>, 
			Int<26000>
		>, 
		LOCKUPCOLOR, 
		AlphaL<
			LOCKUPCOLOR, 
			Bump<
				LockupScale,
				Scale<
					ClashImpactF<>, 
					Int<20000>, 
					Int<60000>
				>
			>
		>
	>, 
	TrExtend<
		3000, 
		TrFade<300>
	>, 
	AlphaL<
		AudioFlicker<
			LOCKUPCOLOR, 
			Mix<
				Int<10280>, 
				Black, 
				LOCKUPCOLOR
			>
		>, 
		Bump<
			LockupScale,
			Int<13000>
		>
	>, 
	TrFade<3000>
>;

// TODO: Add more styles via TrRandom?
// Lockup End
using Lockup_End = TrConcat<
	TrInstant, 
	AlphaL<
		LOCKUPCOLOR, 
		Int<0>
	>, 
	TrSelect<
		Scale<
			IsLessThan<
				ClashImpactF<>, 
				Int<20000>
			>, 
			Int<1>, 
			Int<0>
		>, 
		TrWaveX<
			LOCKUPCOLOR, 
			Scale<
				ClashImpactF<>, 
				Int<50>, 
				Int<400>
			>, 
			Int<100>, 
			Scale<
				ClashImpactF<>, 
				Int<500>, 
				Int<300>
			>, 
			LockupScale
		>, 
		TrSparkX<
			Remap<
				CenterDistF<
					LockupScale
				>, 
				Stripes<
					1200, 
					-3600, 
					Mix<
						Int<6425>, 
						Black, 
						LOCKUPCOLOR
					>, 
					LOCKUPCOLOR, 
					Mix<
						Int<12850>, 
						Black, 
						LOCKUPCOLOR
					>
				>
			>, 
			Int<30>, 
			Scale<
				Sum<
					ClashImpactF<>, 
					SwingSpeed<600>
				>, 
				Int<100>, 
				Int<400>
			>, 
			LockupScale
		>
	>
>;

// ================================ LIGHTNING BLOCK ================================

// Lightning Block Color
using LB_Color_Style = Strobe<
	LBCOLOR, 
	AudioFlicker<
		LBCOLOR, 
		Mix<
			BladeAngle<>,
			LBCOLOR,
			Blue
		>
	>, 
	50, 
	1
>;

// TODO: Add more styles via TrRandom?
// LB Start
using LB_Start = TrConcat<
	TrInstant, 
	AlphaL<
		LBCOLOR, 
		Bump<
			Int<12000>, 
			Int<18000>
		>
	>, 
	TrFade<200>
>;

// TODO: Add more styles via TrRandom?
// LB End
using LB_End = TrConcat<
	TrInstant, 
	HumpFlickerL<
		AlphaL<
			LBCOLOR, 
			Int<16000>
		>, 
		30
	>, 
	TrSmoothFade<600>
>;

// ====================================== DRAG ==================================

// Drag Color Style
using Drag_Color_Style = AlphaL<
	RandomPerLEDFlickerL<DRAGCOLOR>, 
	SmoothStep<
		IntArg<DRAG_SIZE_ARG, 26000>, 
		Int<3000>
	>
>;

// Drag Start
using Drag_Start = TrConcat<
	TrExtend<
		4000, 
		TrWipeIn<200>
	>, 
	AlphaL<
		BrownNoiseFlickerL<
			DRAGCOLOR, 
			Int<300>
		>, 
		SmoothStep<
			IntArg<DRAG_SIZE_ARG, 26000>, 
			Int<3000>
		>
	>, 
	TrFade<4000>
>;

// Drag End
using Drag_End = TrConcat<
	TrInstant,
	TrFade<300>
>;

// ===================================== STAB ==================================

// Stab color Style
using Stab_Color_Style = AudioFlickerL<
	STABCOLOR
>;

// Stab Start
using Stab_Start = TrJoin<
	TrDelayX<WavLen<>>,
	TrWipeIn<200>
>;

// Stab End
using Stab_End = TrConcat <
	TrInstant, 
	TrWipe<200>
>;

// ===================================== Melt ==================================

// Melt color Style
using Melt_Color_Style = AlphaL<
	Remap<
		Scale<
			RampF, 
			Int<65536>, 
			Int<0>
		>, 
		StaticFire<
			Mix<
				TwistAngle<>, 
				STABCOLOR, //OrangeRed, 
				DarkOrange
			>, 
			Mix<
				TwistAngle<>, 
				STABCOLOR, //OrangeRed, 
				Orange
			>, 
			0, 
			3, 
			5, 
			3000, 
			10
		>
	>, 
	SmoothStep<
		IntArg<MELT_SIZE_ARG, 26000>, 
		Int<4000>
	>
>;

// Melt Start
using Melt_Start = TrConcat<
	TrWipeIn<100>, 
	AlphaL<
		Red, 
		SmoothStep<
			IntArg<MELT_SIZE_ARG, 26000>, 
			Int<4000>
		>
	>, 
	TrExtend<
		4000, 
		TrFade<300>
	>, 
	AlphaL<
		Mix<
			TwistAngle<>, 
			Red, 
			Orange
		>, 
		SmoothStep<
			IntArg<MELT_SIZE_ARG, 26000>, 
			Int<4000>
		>
	>, 
	TrFade<4000>
>;

// Melt End
using Melt_End = TrConcat <
	TrInstant,
	TrWipe<200>
>;