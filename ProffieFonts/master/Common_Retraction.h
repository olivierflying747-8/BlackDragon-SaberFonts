// ===================== RETRACTION STYLES =======================

// Standard
using Retraction_Standard = TrWipeInX<
	BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
>;

// Dual Mode Wipe (up = fast)
using Retraction_DualMode = TrWipeInX<
	Scale<
		IsLessThan<
			BladeAngle<>, 
			Int<16000>
		>, 
		Mult<
			RETRACTION_TIME, 
			Int<16384>
		>, 
		RETRACTION_TIME
	>
>;

// Spark Tip
using Retraction_SparkTip = TrWipeInSparkTipX<
	RETRACTIONCOLOR,
	BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
>;

// Center Wipe
using Retraction_CenterWipe = TrCenterWipeX<
	BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>,
	Scale<
		BladeAngle<>, 
		Int<6000>, 
		Int<27000>
	>
>;

// Wipe Out (reverse)
using Retraction_WipeOut = TrWipeX<
	BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
>;

// Fade Off
using Retraction_Fade_Off = TrFadeX<
	BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
>;

// Color Cycle
using Retraction_ColorCycle = TrColorCycleX<
	BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>,
	0,
	6000
>;

// Glitch Off
using Retraction_Glitch_Off = TrConcat<
	TrJoin<
		TrDelayX<
			Mult<
				RETRACTION_TIME, 
				PERCENTAGE_S<50> //Int<16384>
			>
		>, 
		TrWipeInX<
			Mult<
				RETRACTION_TIME, 
				PERCENTAGE_S<50> //Int<16384>
			>
		>
	>, 
	COLOR_MIX<
		SmoothStep<
			NoisySoundLevel, 
			Int<-1>
		>,
		RETRACTIONCOLOR
	>, 
	TrWipeInX<
		Mult<
			RETRACTION_TIME, 
			PERCENTAGE_S<50> //Int<16384>
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
		BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
	>,
	TrWipeX<
		BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
	>
>;

// Metal Forge Cooldown
using Retraction_Metal_Forge_Cooldown = // Metal Forge Cooldown
TrConcat<
	TrFadeX<
		BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
	>,
	White,
	TrFadeX<
		BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
	>,
	DarkOrange,
	TrFadeX<
		BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
	>,
	Red,
	TrFadeX<
		BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
	>
>;

// Blink Off
using Retraction_Blink_Off = TrJoin<
	TrBoingX<
		BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>,
		3
	>,
	TrWipeInX<
		BEND_TIME<RETRACTION_TIME, RETRACTION_OPTION2>
	>
>;

// Disassemble
using Retraction_Disassemble = TrConcat<
	TrSparkX<
		RETRACTIONCOLOR,
		Int<100>,
		Mult<
			RetractionTime<0>,
			Int<6554>
		>,
		Int<0>
	>,
	AlphaL<
		Black,
		SmoothStep<
			Int<26216>,
			Int<0>
		>
	>,
	TrSparkX<
		RETRACTIONCOLOR,
		Int<100>,
		Mult<
			RetractionTime<0>,
			Int<6554>
		>,
		Int<0>
	>,
	AlphaL<
		Black,
		SmoothStep<
			Int<19662>,
			Int<0>
		>
	>,
	TrSparkX<
		RETRACTIONCOLOR,
		Int<100>,
		Mult<
			RetractionTime<0>,
			Int<6554>
		>,
		Int<0>
	>,
	AlphaL<
		Black,
		SmoothStep<
			Int<13108>,
			Int<0>
		>
	>,
	TrSparkX<
		RETRACTIONCOLOR,
		Int<100>,
		Mult<
			RetractionTime<0>,
			Int<6554>
		>,
		Int<0>
	>,
	AlphaL<
		Black,
		SmoothStep<
			Int<6554>,
			Int<0>
		>
	>,
	TrSparkX<
		RETRACTIONCOLOR,
		Int<100>,
		Mult<
			RetractionTime<0>,
			Int<6554>
		>,
		Int<0>
	>
>;