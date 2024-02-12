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

// Special Ability Audio Signals
template<BladeEffectType EFFECTTYPE>
using Special_ToggleAudio = TransitionEffectL<
	TrDoEffectAlwaysX<
		TrInstant,
		EFFECT_TRANSITION_SOUND,
		Int<0>, // tr00.wav
		Int<-1>
	>,
	EFFECTTYPE
>;

// Next Phase
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
	
// Previous Phase
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
	
// Random Phase
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
	
// Swing Phase Random
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

// Rain
template<BladeEffectType EFFECTTYPE>
using Special_Rain = Layers<
	ColorSelect<
		EffectIncrementF<
			EFFECTTYPE,
			Int<2>
		>,
		TrFade<100>,
		TRANSPARENT, // Off
		AlphaL< // On
			OFFCOLOR,
			SparkleF<300, 800>
		>
	>,
	// USER 4 SOUND EFFECT
	TransitionEffectL<
		TrDoEffect<
			TrInstant,
			EFFECT_SOUND_LOOP,
			0 // trloop00.wav
		>,
		EFFECTTYPE
	>
>;

// TODO: Make this toggle on/off with Special Abilities.
// Fireflies
template<BladeEffectType EFFECTTYPE>
using Special_Fireflies = Layers<
	ColorSelect<
		EffectIncrementF<
			EFFECTTYPE,
			Int<2>
		>,
		TrInstant,
		TRANSPARENT, // Off
		TransitionLoopL< // On
			TrDoEffect<
				TrDelay<500>,
				EFFECT_USER8
			>
		>
	>,
	
	MultiTransitionEffectL<
		TrConcat<
			TrFade<3000>,
			AlphaL<
				Yellow,
				Bump<
					EffectPosition<>,
					Int<1000>
				>
			>,
			TrFade<3000>
		>,
		EFFECT_USER8,
		12
	>
>;