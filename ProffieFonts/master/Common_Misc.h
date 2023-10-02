// ================================ COMMON CODE ===========================

// Blade Angle / Lockup Position scale.
using LockupScale = Scale<
	BladeAngle<>, 
	Scale<
		BladeAngle<0, 16000>, 
		Sum<
			IntArg<LOCKUP_POSITION_ARG, 16000>, 
			Int<-12000>
		>, 
		Sum<
			IntArg<LOCKUP_POSITION_ARG, 16000>, 
			Int<10000>
		>
	>, 
	Sum<
		IntArg<LOCKUP_POSITION_ARG, 16000>, 
		Int<-10000>
	>
	/* // Alternate to the above Sum. Integrate it?
	Scale<
		SwingSpeed<100>, 
		Int<14000>, 
		Int<18000>
	>
	*/
>;

// Lockup Clash Impact Color
using LockupClashColor = Mix<
	IsLessThan<
		ClashImpactF<>, 
		Int<26000>
	>, 
	LOCKUPCOLOR, 
	AlphaL<
		LOCKUPCOLOR, 
		Bump<
			LockupScale,
			Scale<
				ClashImpactF<>, 
				Int<20000>, 
				Int<60000>
			>
		>
	>
>;

// Ignition Flicker Stripes, used in Stabalize Ignition.
using Ignition_FlickerStripes = Stripes<
	3000,
	-3500,
	RotateColorsX<
		Variation,
		//Rgb<90,180,255> //IGNITION_COLOR_ARG
		IGNITIONCOLOR
	>,
	RandomPerLEDFlicker<
		RotateColorsX<
			Variation,
			//Rgb<0,26,60> // IGNITION_COLOR_ARG / 4.25
			Mix<
				Int<7710>,
				Black, 
				IGNITIONCOLOR
			>
		>,
		Black
	>,
	BrownNoiseFlicker<
		RotateColorsX<
			Variation,
			//Rgb<90,180,255> //IGNITION_COLOR_ARG
			IGNITIONCOLOR
		>,
		RotateColorsX<
			Variation,
			//Rgb<0,26,60> //IGNITION_COLOR_ARG / 4.25
			Mix<
				Int<7710>,
				Black, 
				IGNITIONCOLOR
			>
		>,
		200
	>,
	RandomPerLEDFlicker<
		RotateColorsX<
			Variation,
			//Rgb<0,42,128> // IGNITION_COLOR_ARG / 2
			Mix<
				Int<16384>,
				Black, 
				IGNITIONCOLOR
			>
		>,
		RotateColorsX<
			Variation,
			//Rgb<0,26,60> // IGNITION_COLOR_ARG / 4.25
			Mix<
				Int<7710>,
				Black, 
				IGNITIONCOLOR
			>
		>
	>
>;

// ShowBatteryLevelHilt
using ShowBatteryLevelHilt = TrConcat<
	TrDelay<1500>,
	Black,
	TrFade<1000>,
	AlphaL<
		Mix<
			BatteryLevel,
			Red,
			Green
		>,
		Bump<
			//Int<0>, //BatteryLevel
			IntArg<EMITTER_SIZE_ARG, 2000>, //Int<12000>
			Int<-1000>
		>
	>,
	TrFade<3000>
>;

// Battery Monitor on Boot
using BatteryLevelOnBoot = TransitionEffectL<
	ShowBatteryLevelHilt,
	EFFECT_BOOT
>;

// Battery level on font change
using BatteryLevelOnFontChange = TransitionEffectL<
	ShowBatteryLevelHilt,
	EFFECT_NEWFONT
>;

// Battery level
using BatteryLevelOnDemand = TransitionEffectL<
	ShowBatteryLevelHilt,
	EFFECT_BATTERY_LEVEL
>;