// ================================ SPECIAL ABILITY EFFECTS ===========================

// Special Ability Visual Signals
template<BladeEffectType EFFECTTYPE, class COLOR>
using Special_ToggleFlash = TransitionEffectL<
	TrConcat<
		TrFade<100>, 
		COLOR,
		TrFade<100>
	>, 
	EFFECTTYPE
>;

// Specials Audio
template<BladeEffectType EFFECTTYPE>
using Special_ToggleAudio = TransitionEffectL<
	TrDoEffectAlwaysX<
		TrInstant,
		EFFECT_TRANSITION_SOUND,
		Int<0>, // tr.wav
		Int<-1>
	>,
	EFFECTTYPE
>;

// Special Ability 1: Next Phase
template<BladeEffectType EFFECTTYPE>
using Special_Phase_Next = TransitionEffectL<
	TrDoEffectAlwaysX<
		TrInstant,
		EFFECT_ALT_SOUND,
		ModF<
			Sum<
				AltF,
				Int<1>
			>,
			Int<9>
		>,
		Int<-1>
	>,
	EFFECTTYPE
>;
	
// Special Ability 2: Previous Phase
template<BladeEffectType EFFECTTYPE>
using Special_Phase_Previous = TransitionEffectL<
	TrDoEffectAlwaysX<
		TrInstant,
		EFFECT_ALT_SOUND,
		ModF<
			Sum<
				AltF,
				Int<-1>
			>,
			Int<9>
		>,
		Int<-1>
	>,
	EFFECTTYPE
>;
	
// Special Ability 3: Random Phase
template<BladeEffectType EFFECTTYPE>
using Special_Phase_Random = TransitionEffectL<
	TrDoEffectAlwaysX<
		TrInstant,
		EFFECT_ALT_SOUND,
		ModF<
			Sum<
				AltF,
				Scale<
					RandomF,
					Int<1>,
					Int<8>
				>
			>,
			Int<9>
		>,
		Int<-1>
	>,
	EFFECTTYPE
>;
	
// Special Ability 4: Swing Phase Random
template<BladeEffectType EFFECTTYPE>
using Special_Phase_Swing = Layers <
	TransitionPulseL<
		TrSelect<
			IncrementModuloF<
				EffectPulseF<EFFECT_USER4>,
				Int<2>
			>,
			TrInstant,
			TrDoEffectX<
				TrInstant,
				EFFECT_ALT_SOUND,
				ModF<
					Sum<
						AltF,
						Scale<
							RandomF,
							Int<1>,
							Int<8>
						>
					>,
					Int<9>
				>,
				Int<-1>
			>
		>,
		ThresholdPulseF<
			SwingSpeed<320>,
			Int<31000>
		>
	>,
	TransitionEffectL<
		TrDoEffectX<
			TrInstant,
			EFFECT_TRANSITION_SOUND,
			Int<0>,
			Int<-1>
		>,
		EFFECTTYPE
	>
>;

// Force Pulse
template<BladeEffectType EFFECTTYPE>
using Special_Rain = Layers<
	ColorSelect<
		EffectIncrementF<
			EFFECTTYPE,
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
		EFFECTTYPE
	>
>;
