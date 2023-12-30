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
			Int<16000>
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
using Ignition_ColorCycle = TrColorCycle<
	3000,
	3000,
	0
>;

// Lighting Strike
using Ignition_LightningStrike = TrConcat<
	TrWipeIn<200>,
	RandomBlink<
		30000,
		RotateColorsX<
			Variation,
			//Rgb16<65535,13655,65535>
			IGNITIONCOLOR
		>
	>,
	TrWipeIn<200>,
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
		RotateColorsX<
			Variation,
			//Rgb16<65535,13655,65535>
			IGNITIONCOLOR
		>
	>,
	TrDelay<400>,
	Mix<
		SmoothStep<
			Int<4000>,
			Int<-3000>
		>,
		Black,
		White
	>,
	TrWipe<175>
>;

// Flash On
using Ignition_Flash = TrConcat <
	TrWipeX<IgnitionTime<300>>,
	StrobeL<IGNITIONCOLOR, Int<100>, IgnitionTime<300>>,
	TrFadeX<IgnitionTime<300>>
>;