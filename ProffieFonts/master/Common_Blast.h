// ================================ BLAST EFFECTS ===========================

// Blast Wave
using Blast_Wave_Random = TrWaveX<
	BLASTCOLOR,
	Scale<
		EffectRandomF<EFFECT_BLAST>, 
		Int<100>, 
		Int<400>
	>, 
	Int<100>, 
	Scale<
		EffectRandomF<EFFECT_BLAST>, 
		Int<100>, 
		Int<400>
	>, 
	Scale<
		EffectRandomF<EFFECT_BLAST>, 
		Int<28000>, 
		Int<8000>
	>
>;

// Blast Wave (sound based)
using Blast_Wave_Sound = TrWaveX<
	BLASTCOLOR, 
	Scale<
		WavLen<>, 
		Int<100>, 
		Int<400>
	>, 
	Int<100>, 
	Scale<
		WavLen<>, 
		Int<100>, 
		Int<400>
	>, 
	Scale<
		EffectRandomF<EFFECT_BLAST>, 
		Int<28000>, 
		Int<8000>
	>
>;

// Blade Fade (sound based)
using Blast_Fade_Sound = TrConcat<
	TrInstant, 
	AlphaMixL<
		Bump<
			EffectPosition<>, 
			Scale<
				WavLen<>, 
				Int<9000>, 
				Int<12000>
			>
		>, 
		BLASTCOLOR, 
		Mix<
			Int<16384>, 
			Black, 
			BLASTCOLOR
		>
	>, 
	TrFade<300>
>;

// Blast Ripple
using Blast_Ripple = TrConcat<
	TrInstant, 
	AlphaL<
		BLASTCOLOR, 
		Bump<
			Int<16384>, 
			Int<6000>
		>
	>, 
	TrFade<50>, 
	AlphaL<
		BLASTCOLOR, 
		Int<0>
	>, 
	TrSparkX<
		Remap<
			CenterDistF<EffectPosition<>>, 
			Stripes<
				2000, 
				-2000, 
				BLASTCOLOR, 
				Mix<
					Int<2096>, 
					Black, 
					BLASTCOLOR
				>
			>
		>, 
		Int<100>, 
		Int<300>, 
		EffectPosition<>
	>
>;

// Blast Ripple Fade
using Blast_Ripple_Fade = TrConcat<
	TrInstant, 
	AlphaL<
		BLASTCOLOR, 
		Bump<
			Int<16384>, 
			Int<6000>
		>
	>, 
	TrFade<50>, 
	AlphaL<
		BLASTCOLOR, 
		Int<0>
	>, 
	TrWaveX<
		Remap<
			CenterDistF<EffectPosition<>>, 
			Stripes<
				1500, 
				-2000, 
				BLASTCOLOR,
				Mix<
					Int<2096>, 
					Black, 
					BLASTCOLOR
				>
			>
		>, 
		Int<160>, 
		Int<100>, 
		Int<300>, 
		EffectPosition<>
	>
>;

// Blast Responsive
using Blast_Responsive = TrConcat <
	TrInstant,
	ResponsiveBlastL<
		BLASTCOLOR,
		Int<400>,
		Scale<
			SwingSpeed<200>,
			Int<100>,
			Int<400>
		>,
		Int<400>
	>,
	TrFade<300>
>;

// Blast Responsive Swing
using Blast_Responsive_Swing = TrConcat <
	TrInstant,
	ResponsiveBlastL<
		BLASTCOLOR,
		Scale<
			SwingSpeed<400>,
			Int<400>,
			Int<100>
		>,
		Scale<
			SwingSpeed<400>,
			Int<200>,
			Int<100>
		>,
		Scale<
			SwingSpeed<400>,
			Int<400>,
			Int<200>
		>
	>,
	TrFade<300>
>;

// Blast Localized Clash
using Blast_LocalClash = TrConcat <
	TrInstant,
	LocalizedClashL<
		BLASTCOLOR,
		80,
		30,
		EFFECT_BLAST
	>,
	TrFade<300>
>;

// Blast Responsive Wave
using Blast_Responsive_Wave = TrConcat <
	TrInstant,
	ResponsiveBlastWaveL<
		BLASTCOLOR,
		Scale<
			SwingSpeed<400>,
			Int<500>,
			Int<200>
		>,
		Scale<
			SwingSpeed<400>,
			Int<100>,
			Int<400>
		>
	>,
	TrFade<300>
>;

// Blast L
using Blast_BlastL = TrConcat <
	TrInstant,
	BlastL<
		BLASTCOLOR,
		200,
		200
	>,
	TrFade<300>
>;

// Blast Responsive Fade
using Blast_Responsive_Fade = TrConcat <
	TrInstant,
	ResponsiveBlastFadeL<
		BLASTCOLOR,
		Scale<
			SwingSpeed<400>,
			Int<6000>,
			Int<12000>
		>,
		Scale<
			SwingSpeed<400>,
			Int<400>,
			Int<100>
		>
	>,
	TrFade<300>
>;



// TODO: Merge with above code and stuff

// Responsive Blast Effect Sequence
using ResponsiveEffectBlastStyle = EffectSequence<
	EFFECT_BLAST,
	ResponsiveBlastL<
		BASECOLOR_BLASTCOLOR_50,
		Int<400>,
		Scale<
			SwingSpeed<200>,
			Int<100>,
			Int<400>
		>,
		Int<400>
	>,
	LocalizedClashL<
		BASECOLOR_BLASTCOLOR_50,
		80,
		30,
		EFFECT_BLAST
	>,
	ResponsiveBlastWaveL<
		BASECOLOR_BLASTCOLOR_50,
		Scale<
			SwingSpeed<400>,
			Int<500>,
			Int<200>
		>,
		Scale<
			SwingSpeed<400>,
			Int<100>,
			Int<400>
		>
	>,
	BlastL<
		BASECOLOR_BLASTCOLOR_50,
		200,
		200
	>,
	ResponsiveBlastFadeL<
		BASECOLOR_BLASTCOLOR_50,
		Scale<
			SwingSpeed<400>,
			Int<6000>,
			Int<12000>
		>,
		Scale<
			SwingSpeed<400>,
			Int<400>,
			Int<100>
		>
	>,
	ResponsiveBlastL<
		BASECOLOR_BLASTCOLOR_50,
		Scale<
			SwingSpeed<400>,
			Int<400>,
			Int<100>
		>,
		Scale<
			SwingSpeed<400>,
			Int<200>,
			Int<100>
		>,
		Scale<
			SwingSpeed<400>,
			Int<400>,
			Int<200>
		>
	>
>;




// Single hook function
using Blast_MultiRandom = MultiTransitionEffectL<
	TrRandom<
		// Option 1: Blast Wave (Random)
		Blast_Wave_Random,
		// Option 3: Blast Wave (Sound Based)
		Blast_Wave_Sound,
		// Option 4: Blast Ripple
		Blast_Ripple,
		// Option 2: Blast Ripple Fade
		Blast_Ripple_Fade,
		// Option 5: Blast Fade (Sound Based)
		Blast_Fade_Sound,
		// Option 6, Responsive Blast
		Blast_Responsive,
		// Option 7: Localized clash
		Blast_LocalClash,
		// Option 8: Responsive Wave
		Blast_Responsive_Wave,
		// Option 9: BlastL
		Blast_BlastL,
		// Option 10: Responsive Blast Fade
		Blast_Responsive_Fade,
		// Option 11: Responsive Blast (Swing based)
		Blast_Responsive_Swing
	>, 
	EFFECT_BLAST
>;
