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
			Int<16284>
		>, 
		30
	>, 
	TrSmoothFade<600>
>;


// Force Lightning
using Lockup_Force_Lightning = Stripes<
	3000,
	-2000,
	RandomBlink<
		30000,
		Strobe<
			Rgb<125,125,225>,
			RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,
			50,
			1
		>,
		Rgb<75,75,150>
	>,
	RandomPerLEDFlicker<
		Rgb<20,20,100>,
		Rgb<100,100,150>
	>
>;
using Lockup_Force_Lightning_StartEnd = TrWipe<200>;

