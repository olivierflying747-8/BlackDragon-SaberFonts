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
using STABCOLOR = RgbArg<STAB_COLOR_ARG, Rgb<255, 24, 0>>;
using OFFCOLOR = RgbArg<OFF_COLOR_ARG, Rgb<255, 255, 255>>;
using TRANSPARENT = AlphaL<Black, Int<0>>;

// Base Color 50%
using BASECOLOR_50 = Mix<
	Int<16448>, //50%
	Black,
	BASECOLOR
>;

// Base Color 25%
using BASECOLOR_25 = Mix<
	Int<8192>, //25%
	Black,
	BASECOLOR
>;

// Base Color 20%?
using BASECOLOR_20 = Mix<
	Int<6425>,
	Black,
	BASECOLOR
>;

// Base Color 33%
using BASECOLOR_33 = Mix<
	Int<9921>, //33%
	Black,
	BASECOLOR
>;

// Alt Color 50%
using ALTCOLOR_50 = Mix<
	Int<16448>, //50%
	Black,
	ALTCOLOR
>;

// Alt Color 25%
using ALTCOLOR_25 = Mix<
	Int<8192>, //25%
	Black,
	ALTCOLOR
>;

// Alt Color 50%
using ALTCOLOR2_50 = Mix<
	Int<16448>, //50%
	Black,
	ALTCOLOR2
>;

// Alt Color 25%
using ALTCOLOR2_25 = Mix<
	Int<8192>, //25%
	Black,
	ALTCOLOR2
>;

// Alt Color 50%
using ALTCOLOR3_50 = Mix<
	Int<16448>, //50%
	Black,
	ALTCOLOR3
>;

// Alt Color 25%
using ALTCOLOR3_25 = Mix<
	Int<8192>, //25%
	Black,
	ALTCOLOR3
>;

// Gradiant Base Color 33%
using BASECOLOR_GRADIENT_33 = Gradient<
	BASECOLOR,
	BASECOLOR_33
>;

// White blend
using BladeWhiteBlend = Mix<
	Int<16384>, //50%
	BASECOLOR,
	Rgb<255, 255, 255>
>;

// Blast Color blend
using BladeBlastBlend = Mix<
	Int <16384>, //50%
	BLASTCOLOR,
	BASECOLOR
>;