// ================================ SPECIAL ABILITY EFFECTS ===========================

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
			0
		>,
		EFFECT_USER4
	>
>;
