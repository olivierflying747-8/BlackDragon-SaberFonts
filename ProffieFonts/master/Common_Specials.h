// ================================ SPECIAL ABILITY EFFECTS ===========================

// Special Ability Visual Signals
using Specials_Flashes = Layers<

	TransitionEffectL<
		TrConcat<
			TrFade<100>, 
			Green, 
			TrFade<100>
		>, 
		EFFECT_USER1
	>,

	TransitionEffectL<
		TrConcat<
			TrFade<100>, 
			Green, 
			TrFade<100>
		>, 
		EFFECT_USER2
	>,

	TransitionEffectL<
		TrConcat<
			TrFade<100>, 
			Green, 
			TrFade<100>
		>, 
		EFFECT_USER3
	>,

	TransitionEffectL<
		TrConcat<
			TrFade<100>, 
			Green, 
			TrFade<100>
		>, 
		EFFECT_USER4
	>,

	TransitionEffectL<
		TrConcat<
			TrFade<100>, 
			Green, 
			TrFade<100>
		>, 
		EFFECT_USER5
	>,

	TransitionEffectL<
		TrConcat<
			TrFade<100>, 
			Green, 
			TrFade<100>
		>, 
		EFFECT_USER6
	>,

	TransitionEffectL<
		TrConcat<
			TrFade<100>, 
			Green, 
			TrFade<100>
		>, 
		EFFECT_USER7
	>,

	TransitionEffectL<
		TrConcat<
			TrFade<100>, 
			Green, 
			TrFade<100>
		>, 
		EFFECT_USER8
	>
>;

// Force Pulse
using Special4_Rain = Layers<
	// USER 4 RAIN EFFECT??
	ColorSelect<
		EffectIncrementF<
			EFFECT_USER4,
			Int<2>
		>,
		TrFade<100>,
		TRANSPARENT,
		AlphaL<
			OFFCOLOR,
			SparkleF<300, 800>
		>
	>,
	// USER 4 SOUND EFFECT
	TransitionEffectL<
		TrDoEffect<
			TrInstant,
			EFFECT_SOUND_LOOP,
			0 // trloop.wav
		>,
		EFFECT_USER4
	>
>;
