// ================================ CLASH ================================

// Clash Effect A
using Clash_EffectA = TransitionEffectL<
	TrConcat<
		TrInstant, 
		AlphaL<
			CLASHCOLOR, 
			Bump<
				LOCKUPPOSITION, 
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
using Clash_EffectB = TransitionEffectL<
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
		LOCKUPPOSITION
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
	LOCKUPPOSITION
>;

// ================================ LOCKUP ================================

// Lockup Color
using Lockup_Color_Style = AlphaMixL<
	// Mix method
	Bump<
		LOCKUPPOSITION,
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

// Lockup Color 2
using Lockup_Color_Style2 = TransitionEffect<
	Lockup_Color_Style,
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
			LOCKUPPOSITION,
			Int<13000>
		>
	>,
	TrJoin<
		TrDelay<8000>,
		TrInstant
	>,
	TrFade<3000>,
	EFFECT_LOCKUP_BEGIN
>;

// Lockup Color 3
using Lockup_Color_Style3 = Layers<
	AlphaL<
		AudioFlickerL<LOCKUPCOLOR>,
		Bump<
			LOCKUPPOSITION,
			Scale<
				SwingSpeed<100>,
				Int<14000>,
				Int<18000>
			>
		>
	>,
	AlphaL<
		LOCKUPCOLOR,
		Bump<
			LOCKUPPOSITION,
			Int<10000>
		>
	>
>;

// Dual Lockup Style
using Lockup_Color_Style4 = TransitionEffect<
	Layers<
		// Color Hump 1
		AlphaMixL<
			//Mix Method
			Bump<
				// Position (Move up/down with blade, min/max at middle)
				Scale<
					BladeAngle<>,
					Scale<
						BladeAngle<0,16000>,
						Sum<
							IntArg<LOCKUP_POSITION_ARG, 16000>,
							Int<-12000>
						>,
						Sum<
							IntArg<LOCKUP_POSITION_ARG, 16000>,
							Int<10000>
						>
					>,
					Sum<
						IntArg<LOCKUP_POSITION_ARG, 16000>,
						Int<-10000>
					>
				>,
				// Size
				Scale<
					//SwingSpeed<100>,
					TwistAngle<>,
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
		>,
	// Color Hump 2
		AlphaMixL<
			//Mix Method
			Bump<
				// Position
				Scale<
					InvertF<BladeAngle<>>,
					Scale<
						InvertF<BladeAngle<16000, 32000>>,
						Sum<
							IntArg<LOCKUP_POSITION_ARG, 16000>,
							Int<-12000>
						>,
						Sum<
							IntArg<LOCKUP_POSITION_ARG, 16000>,
							Int<10000>
						>
					>,
					Sum<
						IntArg<LOCKUP_POSITION_ARG, 16000>,
						Int<-10000>
					>
				>,
				// Size
				Scale<
					TwistAngle<>, //SwingSpeed<100>,
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
		>
	>,
	// Effect Color
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
			Scale<
				BladeAngle<>,
				Scale<
					BladeAngle<0,16000>,
					Sum<
						IntArg<LOCKUP_POSITION_ARG,16000>,
						Int<-12000>
					>,
					Sum<
						IntArg<LOCKUP_POSITION_ARG,16000>,
						Int<10000>
					>
				>,
				Sum<
					IntArg<LOCKUP_POSITION_ARG,16000>,
					Int<-10000>
				>
			>,
			Int<13000>
		>
	>,
	// Transition 1
	TrJoin<
		TrDelay<8000>,
		TrInstant
	>,
	// Transition 2
	TrFade<3000>,
	EFFECT_LOCKUP_BEGIN
>;

// TODO: Add more styles using TrRandom?
// Lockup Start
using Lockup_Start = TrRandom<
	// Effect A (Localized Clash)
	TrConcat<
		TrExtend<
			50, 
			TrInstant
		>, 
		LOCKUPCLASHCOLOR,
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
				LOCKUPPOSITION,
				Int<13000>
			>
		>, 
		TrFade<3000>
	>,
	// Effect B (Flash)
	TrConcat<
		TrJoin<
			TrDelay<50>,
			TrInstant
		>,
		LOCKUPCLASHCOLOR,
		TrFade<300>
	>
>;

// TODO: Add more styles via TrRandom?
// Lockup End
using Lockup_End = TrRandom<
	// Effect A
	TrConcat<
		TrInstant, 
		// Transparent
		AlphaL<
			LOCKUPCOLOR, 
			Int<0>
		>, 
		// Selected based on Impact Force
		TrSelect<
			Scale<
				IsLessThan<
					ClashImpactF<>, 
					Int<20000>
				>, 
				Int<1>, 
				Int<0>
			>, 
			// Wave
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
				LOCKUPPOSITION
			>, 
			// Ripple
			TrSparkX<
				Remap<
					CenterDistF<LOCKUPPOSITION>,
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
				LOCKUPPOSITION
			>
		>
	>,
	/*
	// Effect B: Wave (Dissipate)
	TrConcat<
		TrInstant,
		AlphaL<
			LOCKUPCOLOR,
			Int<0>
		>,
		TrWaveX<
			LOCKUPCOLOR,
			Int<300>,
			Int<100>,
			Int<400>,
			LOCKUPPOSITIONSWING
		>
	>,
	// Effect C: Ripple
	TrSparkX<
		Remap<
			CenterDistF<LOCKUPPOSITION>,
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
			Int<50>,
			Int<200>
		>,
		LOCKUPPOSITION
	>*/
	// Power Burst
	TrConcat<
		TrCenterWipeX<
			Int<150>,
			LOCKUPPOSITION
		>,
		LOCKUPCOLOR,
		TrJoin<
			TrCenterWipeX<
				Int<150>,
				LOCKUPPOSITION
			>,
			TrSmoothFade<150>
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

// Drag Color Style (Intensity Sparking Drag)
using Drag_Color_Style = AlphaL<
	RandomPerLEDFlickerL<DRAGCOLOR>, 
	SmoothStep<
		IntArg<DRAG_SIZE_ARG, 26000>, 
		Int<3000>
	>
>;

// Drag Color Style (Fire)
using Drag_Color_Style2 = AlphaL<
	Stripes<
		2000,
		4000,
		DRAGCOLOR,
		Mix<
			Sin<Int<50>>,
			Black,
			DRAGCOLOR
		>,
		Mix<
			Int<4096>,
			Black,
			DRAGCOLOR
		>
	>,
	SmoothStep<
		IntArg<DRAG_SIZE_ARG,28000>,
		Int<3000>
	>
>;

// Drag Start
using Drag_Start = TrConcat<
	/*
	TrExtend<
		4000, 
		TrWipeIn<200>
	>,
	*/
	TrJoin<
		TrDelay<4000>,
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

// Drag Start 2 (Fire)
using Drag_Start2 = TrConcat<
	TrJoin<
		TrDelay<4000>,
		TrWipeIn<200>
	>,
	AlphaL<
		Stripes<
			2000,
			3000,
			DRAGCOLOR,
			Mix<
				Sin<Int<30>>,
				Black,
				DRAGCOLOR
			>,
			Mix<
				Int<8192>,
				Black,
				DRAGCOLOR
			>
		>,
		SmoothStep<
			IntArg<DRAG_SIZE_ARG,28000>,
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

// Stab color Style (Normal)
using Stab_Color_Style = AudioFlickerL<
	STABCOLOR
>;

// Stab Color Style 2 (Audioflicker)
using Stab_Color_Style2 = AlphaL<
	AudioFlickerL<STABCOLOR>,
	SmoothStep<
		IntArg<MELT_SIZE_ARG, 28000>,
		Int<2000>
	>
>;

// Stab Color Style 3 (Sparking)
using Stab_Color_Style3 = AlphaL<
	RandomPerLEDFlickerL<STABCOLOR>,
	SmoothStep<
		IntArg<MELT_SIZE_ARG, 28000>,
		Int<2000>
	>
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

// ===================================== MELT ==================================

// Melt Color Style (Responsive normal)
using Melt_Color_Style = AlphaL<
	Mix<
		TwistAngle<>,
		STABCOLOR,
		RotateColorsX<
			Int<3000>,
			STABCOLOR
		>
	>,
	SmoothStep<
		IntArg<MELT_SIZE_ARG,28000>,
		Int<4000>
	>
>;

// Melt color Style (Responsive Fire)
using Melt_Color_Style2 = AlphaL<
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
		STABCOLOR,
		SmoothStep<
			IntArg<MELT_SIZE_ARG,28000>,
			Int<4000>
		>
	>,
	TrFade<300>
>;

// Melt Start 2
using Melt_Start2 = TrConcat<
	TrWipeIn<100>, 
	AlphaL<
		STABCOLOR, //Red
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
			STABCOLOR,  //Red
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