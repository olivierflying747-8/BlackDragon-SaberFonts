// ===================== IGNITION STYLES =======================

// Standard
using Ignition_Standard = TrWipeX<
	IgnitionTime<300>
>;

// Dual Mode Wipe (up = fast)
using Ignition_DualMode = TrWipeX<
	Scale<
		IsLessThan<
			BladeAngle<>, 
			Int<16384>
		>, 
		Mult<
			IgnitionTime<300>, 
			Int<16384>
		>, 
		IgnitionTime<300>
	>
>;

// Spark Tip
using Ignition_SparkTip = TrWipeSparkTipX<
	IGNITIONCOLOR,
	IgnitionTime<300>
>;


// Center Wipe
using Ignition_CenterWipe = TrCenterWipeInX<
	IgnitionTime<300>,
	Int<16384>
>;

// Color Cycle
using Ignition_ColorCycle = TrColorCycleX<
	Percentage<IgnitionTime<300>, 1000>, //3000,
	3000,
	0
>;

// Lighting Strike
using Ignition_LightningStrike = TrConcat<
	TrWipeInX<
		Percentage<IgnitionTime<300>, 66>
	>, //200>
	RandomBlinkX<
		Percentage<IgnitionTime<300>, 10000>, //30000,
		RotateColorsX<Variation, IGNITIONCOLOR>
	>,
	TrWipeInX<
		Percentage<IgnitionTime<300>, 66>
	>, //200>,
	Mix<
		SmoothStep<
			Scale<
				SlowNoise<Int<30000>>,
				Int<1000>,
				Int<6000>
			>,
			Int<-3000>
		>,
		Black,
		RotateColorsX<Variation, IGNITIONCOLOR>
	>,
	TrDelayX<
		Percentage<IgnitionTime<300>, 130>
	>, //400>,
	COLOR_MIX<
		SmoothStep<
			Int<4000>,
			Int<-3000>
		>,
		White
	>,
	TrWipeSparkTipX<
		IGNITIONCOLOR,
		Percentage<IgnitionTime<300>, 58>
	> //175>
>;

// Flash On
using Ignition_Flash = TrConcat <
	TrWipeX<IgnitionTime<300>>,
	StrobeL<IGNITIONCOLOR, Int<100>, IgnitionTime<300>>,
	TrFadeX<IgnitionTime<300>>
>;

// Ignition Gravity
using Ignition_Gravity = TrSelect<
	Scale<
		IsLessThan<
			BladeAngle<>,
			Int<18384>
		>,
		Scale<
			IsGreaterThan<
				SwingAcceleration<>,
				Int<16384>
			>,
			Int<0>,
			Int<2>
		>,
		Int<1>
	>,
	TrWipeInX<
		BendTimePowInvX<
			IgnitionTime<300>,
			Mult<
				IntArg<IGNITION_OPTION2_ARG,10992>,
				Int<98304>
			>
		>
	>,
	TrWipeX<
		BendTimePowInvX<
			IgnitionTime<300>,
			Mult<
				IntArg<IGNITION_OPTION2_ARG,10992>,
				Int<98304>
			>
		>
	>,
	TrWipe<100>
>;