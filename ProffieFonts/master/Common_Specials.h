// ================================ SPECIAL ABILITY EFFECTS ===========================

// Force Pulse
using Special1_Rain = Layers<
	// USER 3 RAIN EFFECT??
	ColorSelect<
		EffectIncrementF<
			EFFECT_USER1,
			Int<2>
		>,
		TrFade<100>,
		TRANSPARENT,
		AlphaL<
			OFFCOLOR,
			SparkleF<300, 800>
		>
	>,
	// USER 3 SOUND EFFECT
	TransitionEffectL<
		TrDoEffect<
			TrInstant,
			EFFECT_SOUND_LOOP,
			0
		>,
		EFFECT_USER1
	>
>;
