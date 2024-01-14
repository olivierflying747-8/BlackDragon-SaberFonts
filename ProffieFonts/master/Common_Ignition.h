// ===================== IGNITION STYLES =======================

// Standard
using Ignition_Standard = TrWipeX<
	BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
>;

// Dual Mode Wipe (up = fast)
using Ignition_DualMode = TrWipeX<
	Scale<
		IsLessThan<
			BladeAngle<>, 
			PERCENTAGE_S<50> //Int<16384>
		>, 
		Mult<
			IGNITION_TIME, 
			PERCENTAGE_S<50> //Int<16384>
		>, 
		IGNITION_TIME
	>
>;

// Spark Tip
using Ignition_SparkTip = TrWipeSparkTipX<
	IGNITIONCOLOR,
	BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
>;

// Center Wipe
using Ignition_CenterWipe = TrCenterWipeInX<
	BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>,
	PERCENTAGE_S<50> //Int<16384>
>;

// Wipe In (Reverse)
using Ignition_WipeIn = TrWipeInX<
	BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
>;

// Color Cycle
using Ignition_ColorCycle = TrColorCycleX<
	BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>, //Percentage<IGNITION_TIME, 1000>, //3000,
	3000,
	0
>;

// Glitch On
using Ignition_Glitch_On = TrConcat<
	TrJoin<
		TrDelayX<
			Mult<
				IGNITION_TIME,
				PERCENTAGE_S<50> //Int<16384>
			>
		>,
		TrWipeX<
			Mult<
				IGNITION_TIME,
				PERCENTAGE_S<50> //Int<16384>
			>
		>
	>,
	COLOR_MIX<
		SmoothStep<
			NoisySoundLevel,
			Int<-1>
		>,
		IGNITIONCOLOR
	>,
	TrWipeX<
		Mult<
			IGNITION_TIME,
			PERCENTAGE_S<50> //Int<16384>
		>
	>
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
				PERCENTAGE_S<50> //Int<16384>
			>,
			Int<0>,
			Int<2>
		>,
		Int<1>
	>,
	TrWipeInX<
		BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
	>,
	TrWipeX<
		BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
	>,
	TrWipe<100>
>;

// Lighting Strike
using Ignition_LightningStrike = TrConcat<
	TrWipeInX<
		Percentage<IGNITION_TIME, 66>
	>, //200>
	RandomBlinkX<
		Percentage<IGNITION_TIME, 10000>, //30000,
		RotateColorsX<Variation, IGNITIONCOLOR>
	>,
	TrWipeInX<
		Percentage<IGNITION_TIME, 66>
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
		Percentage<IGNITION_TIME, 130>
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
		Percentage<IGNITION_TIME, 58>
	> //175>
>;

// Metal Forge Heatup
using Ignition_Metal_Forge_Heatup = TrConcat<
	TrFadeX<
		BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
	>,
	Red,
	TrFadeX<
		BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
	>,
	DarkOrange,
	TrFadeX<
		BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
	>,
	White,
	TrFadeX<
		BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>
	>
>;

// Flash On
using Ignition_Flash = TrConcat<
	TrWipeX<BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>>,
	StrobeL<IGNITIONCOLOR, Int<100>, IGNITION_TIME>,
	TrFadeX<BEND_TIME<IGNITION_TIME, IGNITION_OPTION2>>
>;
