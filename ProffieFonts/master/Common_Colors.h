// ===================== BASIC COLOR BLENDS ===================
// Base Color
using BASECOLOR = RgbArg<BASE_COLOR_ARG, Rgb<255, 255, 255>>;
// Alt Colors
using ALTCOLOR = RgbArg<ALT_COLOR_ARG, Rgb<255, 255, 255>>;
using ALTCOLOR2 = RgbArg<ALT_COLOR2_ARG, Rgb<255, 255, 255>>;
using ALTCOLOR3 = RgbArg<ALT_COLOR3_ARG, Rgb<255, 255, 255>>;

// Effect Colors
using SWINGCOLOR = RgbArg<SWING_COLOR_ARG, Rgb<255, 255, 255>>;
using BLASTCOLOR = RgbArg<BLAST_COLOR_ARG, Rgb<255, 255, 255>>;
using IGNITIONCOLOR = RgbArg<IGNITION_COLOR_ARG, Rgb<255, 255, 255>>;
using RETRACTIONCOLOR = RgbArg<RETRACTION_COLOR_ARG, Rgb<255, 255, 255>>;
using PREONCOLOR = RgbArg<PREON_COLOR_ARG, Rgb<255, 255, 255>>;
using POSTOFFCOLOR = RgbArg<POSTOFF_COLOR_ARG, Rgb<255, 255, 255>>;
using EMITTERCOLOR = RgbArg<EMITTER_COLOR_ARG, Rgb<255, 255, 255>>;
using CLASHCOLOR = RgbArg<CLASH_COLOR_ARG, Rgb<255, 255, 255>>;
using LOCKUPCOLOR = RgbArg<LOCKUP_COLOR_ARG, Rgb<255, 255, 255>>;
using LBCOLOR = RgbArg<LB_COLOR_ARG, Rgb<255, 255, 255>>;
using DRAGCOLOR = RgbArg<DRAG_COLOR_ARG, Rgb<255, 255, 255>>;
using STABCOLOR = RgbArg<STAB_COLOR_ARG, Rgb<255, 255, 255>>;
using OFFCOLOR = RgbArg<OFF_COLOR_ARG, Rgb<255, 255, 255>>;
using TRANSPARENT = AlphaL<Black, Int<0>>;

// Get a % mix of color A and B, using straight values (32768 = 100%)
template<int MIX, class COLORA, class COLORB = Black>
using COLOR_MIX = Mix<
	Int<MIX>,
	COLORB,
	COLORA
>;

template<int PERCENT, class COLORA, class COLORB = Black>
using COLOR_MIX_P = Mix<
	Percentage<Int<32768>, PERCENT>,
	COLORB,
	COLORA
>;

/*
// Color 50%
template<class COLORA, class COLORB = Black>
using COLOR_50 = Mix<
	COLOR_PERCENT<50>, //Int<16448>, //50%
	COLORA,
	COLORB
>;

// Color 33%
template<class COLORA, class COLORB = Black>
using COLOR_33 = Mix<
	COLOR_PERCENT<33>, //Int<9921>, //33%
	COLORA,
	COLORB
>;

// Color 25%
template<class COLORA, class COLORB = Black>
using COLOR_25 = Mix<
	COLOR_PERCENT<25>, //Int<8192>, //25%
	COLORA,
	COLORB
>;

// Color 20%
template<class COLORA, class COLORB = Black>
using COLOR_20 = Mix<
	COLOR_PERCENT<20>, //Int<6425>, //20%
	COLORA,
	COLORB
>;
*/

// Color Gradiant
template<class COLORA, class COLORB = Black>
using COLOR_GRADIENT = Gradient<
	COLORA,
	COLORB
>;
