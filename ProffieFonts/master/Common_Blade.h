// ===================== BLADE STYLES =======================
/*
// Basic Audio Filter, BASE color, 50% BASE color (breathing)
using Style1_AudioFilter = AudioFlicker<
	BASECOLOR,
	BASECOLOR_50 // 50%
>;*/

using Style1_Static = BASECOLOR;

// Basic Audio Filter, BASE / ALT color.
using Style1_AudioFilter = AudioFlicker<
	RotateColorsX<Variation, BASECOLOR>,
	RotateColorsX<Variation, ALTCOLOR>
>;

// Random Flicker, BASE / ALT color
using Style1_RandomFlicker = RandomFlicker<
	BASECOLOR,
	ALTCOLOR
>;

// Pusling Blade
using Style1_Pulsing = Pulsing<
	RotateColorsX<Variation, BASECOLOR>,
	RotateColorsX<Variation, ALTCOLOR>,
	1200
>;

// Brownnoise BASE color
using Style1_BrownNoiseFlicker = BrownNoiseFlicker<
	RotateColorsX<Variation, BASECOLOR>,
	Black,
	300
>;

// Stripes (single color)
using Style1_Stripes = Stripes<
	10000,
	-1700,
	RotateColorsX<
		Variation,
		BASECOLOR_33
	>,
	RotateColorsX<
		Variation,
		BASECOLOR
	>,
	RotateColorsX<
		Variation,
		BASECOLOR_50
	>,
	RotateColorsX<
		Variation,
		BASECOLOR_20
	>,
	RotateColorsX<
		Variation,
		BASECOLOR
	>
>;

// StripesX Slow Noise (2 color)
using Style1_StripesX_SlowNoise = StripesX<
	Int<1500>,
	Scale<
		SlowNoise<Int<2500>>,
		Int<-3000>,
		Int<-5000>
	>,
	BASECOLOR,
	Mix<
		Int<10280>, //33%
		Black,
		ALTCOLOR
	>,
	BASECOLOR,
	Mix<
		Int<2570>, //8%
		Black,
		ALTCOLOR
	>,
	BASECOLOR
>;

// Unstable Stripes
using Style1_Stripes_RandomPerLEDFlicker = Stripes<
	3000, 
	-3500, 
	BASECOLOR, 
	RandomPerLEDFlicker<
		Mix<
			Int<7710>, 
			Black, 
			BASECOLOR
		>, 
		Black
	>, 
	BrownNoiseFlicker<
		BASECOLOR, 
		Mix<
			Int<3855>, 
			Black, 
			BASECOLOR
		>,
		200
	>, 
	RandomPerLEDFlicker<
		Mix<
			Int<10280>, 
			Black, 
			BASECOLOR
		>, 
		Mix<
			Int<3855>, 
			Black, 
			BASECOLOR
		>
	>
>;

// Kestis style
/* // Too similar to above.
using CalKestisStyle = StripesX<
	Int<6000>,
	Scale<
		SlowNoise<Int<2000>>,
		Int<-1600>,
		Int<-3200>
	>,
	BASECOLOR,
	RandomPerLEDFlicker<
		Mix<
			Int<10280>,
			Black,
			BASECOLOR
		>,
		Mix<
			Int<1285>,
			Black,
			BASECOLOR
		>
	>,
	BrownNoiseFlicker<
		Mix<
			Int<1285>,
			Black,
			BASECOLOR
		>,
		Mix<
			Int<16448>,
			Black,
			BASECOLOR
		>,
		300
	>,
	BASECOLOR,
	RandomPerLEDFlicker<
		Black,
		Mix<
			Int<16448>,
			Black,
			BASECOLOR
		>
	>,
	BASECOLOR
>;
*/

// Thunderstorm
using Style1_ThunderstormBlade = TransitionLoop<
	RotateColorsX<
		Variation,
		BASECOLOR //DeepSkyBlue // 0, 135,255
	>,
	TrConcat<
		TrBoing<500,3>,
		Layers<
			Stripes<
				10000,
				100,
				RotateColorsX<
					Variation,
					//Rgb<0,40,128> // BASECOLOR / 2
					BASECOLOR_50
				>,
				RotateColorsX<
					Variation,
					//Rgb<0,8,30> // Base Color / 8
					Mix<
						Int<4096>, //12.5%
						Black, 
						BASECOLOR
					>
				>,
				RotateColorsX<
					Variation,
					ALTCOLOR //Rgb<0,63,200> // Alt Color? DodgerBlue
				>
			>,
			AlphaL<
				Stripes<
					8000,
					-200,
					RotateColorsX<
						Variation,
						BASECOLOR // Base Color
					>,
					RotateColorsX<
						Variation,
						//Rgb<0,19,60> // Alt color / 4? DodgerBlue
						ALTCOLOR_25
					>
				>,
				Int<16384> //50%
			>
		>,
		TrDelayX< // Is this the lightning flash??
			Scale<
				SlowNoise<Int<3000>>,
				Int<100>,
				Int<2000>
			>
		>
	>
>;

// Fett263 Smoke Blade
using Style1_SmokeBlade = StripesX<
	Sin<
		Int<12>,
		Int<3000>,
		Int<7000>
	>,
	Scale<
		SwingSpeed<100>,
		Int<75>,
		Int<125>
	>,
	StripesX<
		Sin<
			Int<10>,
			Int<1000>,
			Int<3000>
		>,
		Scale<
			SwingSpeed<100>,
			Int<75>,
			Int<100>
		>,
		Pulsing<
			RotateColorsX<Variation, BASECOLOR>,
			RotateColorsX<
				Variation, 
				//Rgb<15,14,0>>, // BASECOLOR / 12.75
				Mix<
					Int<2570>,
					Black, 
					BASECOLOR
				>
			>,
			1200
		>,
		Mix<
			SwingSpeed<200>,
			RotateColorsX<
				Variation,
				//Rgb<90,87,0> // Mix BASECOLOR / 2.125
				Mix<
					Int<15420>,
					Black, 
					BASECOLOR
				>
			>,
			Black
		>
	>,
	RotateColorsX<
		Variation,
		//Rgb<40,40,0> // BASE / 4.25
		Mix<
			Int<7710>,
			Black, 
			BASECOLOR
		>
	>,
	Pulsing<
		RotateColorsX<
			Variation,
			//Rgb<36,33,0> // BASE / 5.1
			BASECOLOR_20
		>,
		StripesX<
			Sin<
				Int<10>,
				Int<2000>,
				Int<3000>
			>,
			Sin<
				Int<10>,
				Int<75>,
				Int<100>
			>,
			RotateColorsX<Variation, BASECOLOR>,
			RotateColorsX<
				Variation,
				//Rgb<60,58,0> // BASE / 2.65625
				Mix<
					Int<12336>,
					Black, 
					BASECOLOR
				>
			>
		>,
		2000
	>,
	Pulsing<
		RotateColorsX<
			Variation,
			//Rgb<90,88,0> // BASE / 2.125
			Mix<
				Int<15420>,
				Black, 
				BASECOLOR
			>
		>,
		RotateColorsX<
			Variation,
			//Rgb<5,5,0> // BASE / 51
			Mix<
				Int<643>,
				Black, 
				BASECOLOR
			>
		>,
		3000
	>
>;

// Fire Blade
using Style1_FireBlade = StyleFire<
	BrownNoiseFlicker<
		RotateColorsX<Variation, BASECOLOR>, //0, 135, 255
		RandomPerLEDFlicker<
			RotateColorsX<
				Variation,
				//Rgb<0,0,25>  // BASE / 10.2
				Mix<
					Int<3213>,
					Black, 
					BASECOLOR
				>
			>,
			RotateColorsX<
				Variation,
				//Rgb<0,0,60> // BASE / 4.25
				Mix<
					Int<7710>,
					Black, 
					BASECOLOR
				>
			>
		>,
		300
	>,
	RotateColorsX<
		Variation,
		//Rgb<0,0,80> // BASE / 3.1875
		Mix<
			Int<10280>,
			Black, 
			BASECOLOR
		>
	>,
	0,
	6,
	FireConfig<10,1000,2>,
	FireConfig<10,1000,2>,
	FireConfig<10,1000,2>,
	FireConfig<10,1000,2>
>;

// Flickery Blade style
using Style1_FlickerBlade = Mix<
	Scale<
		IsLessThan<
			SlowNoise<
				Int<2000>
			>, 
			Int<18000>
		>, 
		Int<0>, 
		Int<32768>
	>, 
	BASECOLOR_GRADIENT_33,
	Stripes<
		12000, 
		-800, 
		BASECOLOR_GRADIENT_33,
		BASECOLOR_GRADIENT_33,
		Mix<
			Int<7710>, 
			Black, 
			BASECOLOR_GRADIENT_33
		>, 
		BASECOLOR_GRADIENT_33,
		Mix<
			Int<16448>, 
			Black, 
			BASECOLOR_GRADIENT_33
		>
	>
>;

// "Coda"
//Rotates   ^3 times per minute between BASE COLOR and ALT COLOR with subtle ALT COLOR / ALT COLOR 2 audioflicker
using CodaBladeStyle = Mix<
	Sin<Int<3>>, 
	AudioFlicker<
		RotateColorsX<
			Variation, 
			//DodgerBlue //2, 72, 255 DodgerBlue // BASE COLOR
			BASECOLOR
		>, 
		Stripes<
			5000, 
			-90, 
			RotateColorsX<
				Variation, 
				//Rgb<0, 55, 165> //0, 135, 255 // DeepSkyBlue //// ALT COLOR / 1.5
				Mix<
					Int<21845>,
					Black,
					ALTCOLOR
				>
			>, 
			RotateColorsX<
				Variation, 
				//Rgb<0, 85, 115> // ALT COLOR / 2.2
				Mix<
					Int<14894>,
					Black,
					ALTCOLOR
				>
			>, 
			RotateColorsX<
				Variation, 
				//Rgb<0, 65, 145> // MIX BASE COLOR / ALT COLOR 50%, ALT COLOR / 1.75
				Mix<
					Int<18725>,
					Black,
					Mix< // 50% Base/alt color blend.
						Int<16384>,
						BASECOLOR,
						ALTCOLOR
					>
				>
			>, 
			RotateColorsX<
				Variation, 
				//Rgb<0, 30, 185> // MIX BASE COLOR / ALT COLOR 50%, ALT COLOR / 1.3
				Mix<
					Int<23206>,
					Black,
					Mix< // 50% Base/alt color blend.
						Int<16384>,
						BASECOLOR,
						ALTCOLOR
					>
				>
			>
		>
	>, 
	AudioFlicker<
		RotateColorsX<
			Variation, 
			//Rgb<0, 155, 255> // ALT_COLOR_ARG
			ALTCOLOR
		>, 
		Stripes<
			5000, 
			-90, 
			RotateColorsX<
				Variation, 
				//Rgb<0, 95, 170> // ALT COLOR / 1.5
				Mix<
					Int<21845>,
					Black,
					ALTCOLOR
				>
			>, 
			RotateColorsX<
				Variation, 
				//Rgb<0, 115, 215> // ALT COLOR / 1.18
				Mix<
					Int<27769>,
					Black,
					ALTCOLOR
				>
			>,
			RotateColorsX<
				Variation, 
				//Rgb<0, 145, 145> //ALT_COLOR2_ARG / 1.75
				Mix<
					Int<18724>,
					Black,
					ALTCOLOR2
				>
			>, 
			RotateColorsX<
				Variation, 
				//Rgb<0, 65, 225> // BASE COLOR / 1.13
				Mix<
					Int<28998>,
					Black,
					BASECOLOR
				>
			>
		>
	>
>;

// DarkSaber style
using DarkSaberStyle = AudioFlicker<
	BrownNoiseFlicker<	
		Mix<
			SwingSpeed<400>, 
			BASECOLOR, 
			Mix<
				Int<6425>, 
				BASECOLOR, 
				ALTCOLOR
			>
		>, 
		Stripes<
			5000, 
			-300, 
			Mix<
				Int<7710>, //23%
				Black, 
				BASECOLOR
			>,
			Mix<
				Int<25700>, //80%
				Black, 
				BASECOLOR
			>, 
			Mix<
				Int<1285>, //4%
				Black, 
				BASECOLOR
			>, 
			Mix<
				Int<16384>, //50%
				Black, 
				BASECOLOR
			>
		>,
		300
	>, 
	Mix<
		Int<6425>, 
		BASECOLOR, 
		ALTCOLOR
	>
>;

// Interactive FirePulse Style
using Style1_FirePulseInteractive = Layers<
	Black,
	ColorSelect<
		IncrementWithReset<
			ThresholdPulseF<
				SwingSpeed<400>,
				Int<18000>
			>,
			Sum<
				EffectPulseF<EFFECT_CLASH>,
				EffectPulseF<EFFECT_LOCKUP_BEGIN>
			>,
			Int<1>
		>,
		TrSelect<
			IncrementWithReset<
				ThresholdPulseF<
					SwingSpeed<400>,
					Int<18000>
				>,
				Sum<
					EffectPulseF<EFFECT_CLASH>,
					EffectPulseF<EFFECT_LOCKUP_BEGIN>
				>,
				Int<1>
			>,
			TrConcat<
				TrInstant,
				BASECOLOR_WHITE_50,
				TrSmoothFade<500>
			>,
			TrSmoothFade<600>
		>,
		AudioFlicker<
			BASECOLOR,
			BASECOLOR_50
		>,
		Layers<
			StripesX<
				Int<6000>,
				Scale<
					IncrementWithReset<
						ThresholdPulseF<
							SwingSpeed<400>,
							Int<18000>
						>,
						Sum<
							EffectPulseF<EFFECT_CLASH>,
							EffectPulseF<EFFECT_LOCKUP_BEGIN>
						>,
						Int<32000>,
						Int<2000>
					>,
					Int<-100>,
					Int<-3000>
				>,
				BASECOLOR_33,
				BASECOLOR,
				BASECOLOR_50
			>,
			AlphaL<
				RandomPerLEDFlickerL<Black>,
				IncrementWithReset<
					ThresholdPulseF<
						SwingSpeed<400>,
						Int<18000>
					>,
					Sum<
						EffectPulseF<EFFECT_CLASH>,
						EffectPulseF<EFFECT_LOCKUP_BEGIN>
					>,
					Int<30000>,
					Int<4000>
				>
			>
		>
	>
>;

// Ghost Buster
using Style1_GhostBusterBlade = StaticFire<
	Mix<
		SmoothStep<
			Int<2000>,
			Int<-2000>
		>,
		Stripes<
			16000,
			-3900,
			BASECOLOR,
			Mix<
				Int<8172>,
				Black,
				BASECOLOR
			>,
			Mix<
				Int<16384>,
				Black,
				BASECOLOR
			>,
			Stripes<
				2500,
				-3500,
				BASECOLOR,
				BASECOLOR,
				ALTCOLOR, // Blue
				Mix<
					Int<16000>,
					Black,
					BASECOLOR
				>,
				ALTCOLOR2 // DodgerBlue
			>
		>,
		White // White
	>,
	ALTCOLOR, // Blue
	0,
	6,
	1,
	2000,
	3
>;

// ElectroStaff Blade
using Style1_StaffBlade = StyleFire<
	Strobe<
		RotateColorsX<Variation,BASECOLOR>, //Rgb<95,0,210>
		Strobe<
			ALTCOLOR, //Rgb<100,100,150>
			RandomPerLEDFlicker<
				RotateColorsX<Variation,BASECOLOR>, //Rgb<95,0,210>
				Black
			>,
			50,
			1
		>,
		100,
		1
	>,
	RotateColorsX<
		Variation,
		//Rgb<23,0,65> // BASECOLOR / 0.3
		Mix<
			Int<16000>,
			Black,
			BASECOLOR
		>
	>,
	0,
	5,
	FireConfig<2,1000,5>,
	FireConfig<2,1000,5>,
	FireConfig<2,1000,5>,
	FireConfig<2,1000,5>
>;




// Smash Blade
using Style1_SmashBlade = Layers<
	StripesX<
		Sin<
			Int<4>,
			Int<3000>,
			Int<6000>
		>,
		Scale<
			TwistAngle<>,
			Int<-50>,
			Int<-100>
		>,
		StripesX<
			Sin<
				Int<3>,
				Int<1000>,
				Int<3000>
			>,
			Scale<
				TwistAngle<>,
				Int<25>,
				Int<80>
			>,
			Pulsing<
				RotateColorsX<
					Sin<Int<10>>,
					Rgb<255,50,50>
				>,
				RotateColorsX<
					Sin<Int<12>>,
					Rgb<200,0,0>
				>,
				3000
			>,
			Mix<
				Sin<Int<2>>,
				RotateColorsX<
					Sin<Int<12>>,
					Rgb<200,0,0>
				>,
				RotateColorsX<
					Sin<
						Scale<
							TwistAngle<>,
							Int<4>,
							Int<0>
						>
					>,
					Rgb<10,0,0>
				>
			>
		>,
		RotateColorsX<
			Sin<
				Scale<
					TwistAngle<>,
					Int<4>,
					Int<0>
				>
			>,
			Rgb<60,0,0>
		>,
		Pulsing<
			RotateColorsX<
				Sin<
					Scale<
						TwistAngle<>,
						Int<4>,
						Int<0>
					>
				>,
				Rgb<50,0,0>
			>,
			StripesX<
				Sin<
					Int<2>,
					Int<2000>,
					Int<4000>
				>,
				Sin<
					Int<2>,
					Int<25>,
					Int<75>
				>,
				Mix<
					Sin<Int<4>>,
					RotateColorsX<
						Sin<Int<4>>,
						Red
					>,
					RotateColorsX<
						Sin<
							Scale<
								TwistAngle<>,
								Int<14>,
								Int<2>
							>
						>,
						Rgb<255,50,50>
					>
				>,
				RotateColorsX<
					Sin<
						Scale<
							TwistAngle<>,
							Int<4>,
							Int<0>
						>
					>,
					Rgb<96,0,0>
				>
			>,
			2000
		>,
		Pulsing<
			RotateColorsX<
				Sin<
					Scale<
						TwistAngle<>,
						Int<10>,
						Int<6>
					>
				>,
				Rgb<128,0,0>
			>,
			RotateColorsX<
				Sin<
					Scale<
						TwistAngle<>,
						Int<4>,
						Int<10>
					>
				>,
				Rgb<50,0,0>
			>,
			3000
		>
	>,
	// Blade part 2?
	AlphaL<
		StripesX<
			Sin<
				Int<8>,
				Int<3000>,
				Int<6000>
			>,
			Scale<
				TwistAngle<>,
				Int<60>,
				Int<140>
			>,
			StripesX<
				Sin<
					Int<6>,
					Int<1000>,
					Int<3000>
				>,
				Scale<
					TwistAngle<>,
					Int<-25>,
					Int<-80>
				>,
				Pulsing<
					Mix<
						Sin<Int<4>>,
						RotateColorsX<
							Sin<Int<8>>,
							Red
						>,
						RotateColorsX<
							Sin<Int<6>>,
							Rgb<255,50,50>
						>
					>,
					RotateColorsX<
						Sin<
							Scale<
								TwistAngle<>,
								Int<4>,
								Int<0>
							>
						>,
						Rgb<20,0,0>
					>,
					4000
				>,
				Mix<
					Sin<Int<2>>,
					RotateColorsX<
						Sin<Int<8>>,
						Rgb<255,50,50>
					>,
					Black
				>
			>,
			RotateColorsX<
				Sin<Int<12>>,
				Rgb<60,0,0>
			>,
			Pulsing<
				RotateColorsX<
					Sin<Int<4>>,
					Rgb<50,0,0>
				>,
				StripesX<
					Sin<
						Int<2>,
						Int<2000>,
						Int<4000>
					>,
					Sin<
						Int<2>,
						Int<-25>,
						Int<-75>
					>,
					Mix<
						Sin<Int<4>>,
						RotateColorsX<
							Sin<Int<5>>,
							Red
						>,
						RotateColorsX<
							Sin<Int<16>>,
							Rgb<255,50,50>
						>
					>,
					RotateColorsX<
						Sin<Int<10>>,
						Rgb<96,0,0>
					>
				>,
				2000
			>,
			Pulsing<
				RotateColorsX<
					Sin<Int<9>>,
					Rgb<128,0,0>
				>,
				Black,
				3000
			>
		>,
		Int<10000>
	>
>;

// Party Blade
using Style1_PartyBlade = StyleFire<
	StripesX<
		Int<3000>,
		Scale<
			TwistAngle<>,
			Int<-500>,
			Int<0>
		>,
		Red,
		Orange,
		Yellow,
		Green,
		Blue,
		Magenta
	>,
	StripesX<
		Int<3000>,
		Scale<
			TwistAngle<>,
			Int<-500>,
			Int<0>
		>,
		Tomato,
		OrangeRed,
		Orange,
		Yellow,
		SteelBlue,
		DeepPink
	>,
	0,
	3,
	FireConfig<0,2000,5>,
	FireConfig<0,2000,5>,
	FireConfig<0,2000,5>
>;

// Fire blade with bright tip? TODO: separate bright tip for secondary/tirtiary styles...
using Style1_FireTipBlade =	Layers<
	StaticFire<
		Mix<
			SmoothStep<
				Scale<
					BladeAngle<>,
					Int<38000>,
					Int<23000>
				>,
				Int<8000>
			>,
			Mix<
				Int<400>,
				Black,
				BASECOLOR
			>,
			Mix<
				Int<6000>,
				Black,
				BASECOLOR
			>
		>,
		TRANSPARENT,
		0,
		2,
		4,
		2000,
		2
	>
>;

using Style1_FireTipBase = Layers<
	StaticFire <
		StripesX<
			Int<14000>,
			Scale<
				BladeAngle<>,
				Int<-5>,
				Int<-50>
			>,
			BASECOLOR,
			Mix<
				Scale<
					HoldPeakF<
						SwingSpeed<250>,
						Int<1000>,
						Int<8000>
					>,
					Int<6000>,
					Int<16000>
				>,
				Black,
				BASECOLOR
			>
		>,
		TRANSPARENT,
		0,
		2,
		4,
		2000,
		2
	>
>;