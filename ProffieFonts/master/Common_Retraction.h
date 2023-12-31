// ===================== RETRACTION STYLES =======================

// Standard
using Retraction_Standard = TrWipeInX<
	RetractionTime<0>
>;

// Dual Mode Wipe (up = fast)
using Retraction_DualMode = TrWipeInX<
	Scale<
		IsLessThan<
			BladeAngle<>, 
			Int<16000>
		>, 
		Mult<
			RetractionTime<0>, 
			Int<16384>
		>, 
		RetractionTime<0>
	>
>;

// Spark Tip
using Retraction_SparkTip = TrWipeInSparkTipX<
	RETRACTIONCOLOR,
	RetractionTime<0>
>;

// Center Wipe
using Retraction_CenterWipe = TrCenterWipeX<
	RetractionTime<0>, 
	Scale<
		BladeAngle<>, 
		Int<6000>, 
		Int<27000>
	>
>;

// Color Cycle
using Retraction_ColorCycle = TrColorCycle<
	1250,
	0,
	6000
>;

// Glitch Off
using Retraction_Glitch_Off = TrConcat<
	TrJoin<
		TrDelayX<
			Mult<
				RetractionTime<0>, 
				Int<16384>
			>
		>, 
		TrWipeInX<
			Mult<
				RetractionTime<0>, 
				Int<16384>
			>
		>
	>, 
	Mix<
		SmoothStep<
			NoisySoundLevel, 
			Int<-1>
		>,
		Black, 
		RETRACTIONCOLOR
	>, 
	TrWipeInX<
		Mult<
			RetractionTime<0>, 
			Int<16384>
		>
	>
>;

// Gravity Retraction
using Retraction_Gravity = TrSelect<
	Scale<
		IsLessThan<
			BladeAngle<>,
			Int<18384>
		>,
		Int<0>,
		Int<1>
	>,
	TrWipeInX<
		BendTimePowInvX<
			RetractionTime<0>,
			Mult<
				IntArg<RETRACTION_OPTION2_ARG,10992>,
				Int<98304>
			>
		>
	>,
	TrWipeX<
		BendTimePowInvX<
			RetractionTime<0>,
			Mult<
				IntArg<RETRACTION_OPTION2_ARG,10992>,
				Int<98304>
			>
		>
	>
>;