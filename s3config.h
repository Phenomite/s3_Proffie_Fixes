#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1750
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 4.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define COLOR_CHANGE_DIRECT
#define NO_REPEAT_RANDOM
#define IDLE_OFF_TIME 60*1*1000
#define MOTION_TIMEOUT 60*3*1000
#define SHARED_POWER_PINS
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define BLADE_DETECT_PIN 17
#define SAVE_PRESET
#define FETT263_TWIST_ON
#define FETT263_TWIST_OFF
#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define ENABLE_ALL_EDIT_OPTIONS
#define FETT263_EDIT_MODE_MENU
#define DISABLE_BASIC_PARSER_STYLES

#endif

#ifdef CONFIG_PROP
#include"../props/s3button_config.h"
#endif

#ifdef CONFIG_PRESETS


// NOTE - Custom sabertrio soundlevel add to all styles:
// TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>

// NOTE2 - Replace rubbish Sabertrio battery level with Fett263 On-Demand Battery Level:
// TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,


Preset blade[] = {
	{"1-SABERTRIO;common", "tracks/track_1.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), DodgerBlue, Animated(Moccasin)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,
	RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Sabertrio"},



	{"2-DARK_EDITION;common", "tracks/track_2.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Red, Animated (Moccasin)

	--Effects Included--
	Ignition Effect: Standard Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Dark Edition"},



	{"3-THE_LIGHT;common","tracks/track_3.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), DeepSkyBlue, Original (LemonChiffon)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "The Light"},



	{"4-THE_BALANCE;common","tracks/track_4.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Green, Prequel(NavajoWhite)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "The Balance"},



	{"5-THE_DARK;common","tracks/track_5.wav" ,
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Red, Orignal (LemonChiffon)

	--Effects Included--
	Ignition Effect: Standard Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "The Dark"},



	{"6-VENGEANCE;common","tracks/track_6.wav" ,
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Red, Animated (Moccasin)

	--Effects Included--
	Ignition Effect: Standard Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Vengeance"},




	{"7-KROSSGUARD;common", "tracks/track_7.wav",
	/* copyright Fett263 KyloRen (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#KyloRen
	OS6.6 v3.01
	Single Style
	Base Style: Kylo Ren Unstable (Film Based), Red, Sequel (LightCyan)

	--Effects Included--
	Ignition Effect: Standard Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Medium), Responsive Blast Fade (Sound Based)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,300>,Mix<Int<10280>,
	Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,6,10,1000,2>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<191,255,255>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,
	TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<10000>>,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>>>,
	TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<000>>,Scale<WavLen<>,Int<9000>,Int<13000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>>>,
	TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<191,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,
	Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,TrFade<400>>,
	SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,
	Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<191,255,255>>>,
	SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<191,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,
	SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,
	RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,
	RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeX<IgnitionTime<250>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Krossguard"},



	{"8-SNIPPETS;common", "tracks/track_8.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: AudioFlicker (Single Color (50%)), Silver, Animated (Moccasin)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,199,119>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Snippets"},



	{"9-MENACE;common", "tracks/track_9.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Red, Prequel (NavajoWhite)

	--Effects Included--
	Ignition Effect: Standard Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Menace"},



	{"10-TEMPLE_GUARDIAN;common", "tracks/track_10.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Gold, Animated (Moccasin)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,199,119>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,199,119>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Temple Guardian"},



	{"11-SHOCK_BATON;common", "tracks/track_11.wav",
	/* copyright Fett263 EnergyWeapon (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#EnergyWeapon
	OS6.6 v3.01
	Single Style
	Base Style: Shock Baton (DodgerBlue, White)

	--Effects Included--
	Preon Effect: Polar Spark (PreOn Color)
	Ignition Effect: Center In
	PowerUp Effect: Power Surge (Unstable V2)
	Retraction Effect: Center In
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Wave (Random), Responsive Blast Wave (Medium)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	Ignition Time: 200
	*/
	StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,TransitionEffectL<TrConcat<TrInstant,
	HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,255,255>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,
	Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,EFFECT_BLAST>,
	TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,
	Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,
	RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,
	AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,
	Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,26000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,
	AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,26000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,
	StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,
	RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,
	AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrCenterWipeInX<IgnitionTime<200>,Int<16384>>,TrCenterWipeInX<RetractionTime<0>,Int<16384>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,Rgb<100,100,150>,300>,
	LayerFunctions<SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>,SmoothStep<Int<30768>,Int<4000>>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Shock Baton"},



	{"12-THE_TRAGEDY;common", "tracks/track_12.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: AudioFlicker (Single Color (75%)), Red, Prequel (NavajoWhite)

	--Effects Included--
	Ignition Effect: Standard Ignition
	PowerUp Effect: Power Surge (Unstable V1)
	Retraction Effect: Standard Retraction
	CoolDown Effect: Unstable Cool Down Forward
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Medium), Responsive Blast Fade (Sound Based)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,
	Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,
	Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrExtendX<RetractionTime<0>,TrInstant>,Stripes<3000,-3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,
	RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,
	Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,
	187,108>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<10000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<000>>,Scale<WavLen<>,Int<9000>,Int<13000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<16384>,
	Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeX<IgnitionTime<250>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "The Tragedy"},



	{"13-TEENSY_SF;common", "tracks/track_13.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Cyan, Prequel (NavajoWhite)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "TeensySF"},



	{"14-SMOOTH_JEDI;common", "tracks/track_14.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Blue, Original (LemonChiffon)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Smooth Jedi"},



	{"15-SMOOTH_GREY;common", "tracks/track_15.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: AudioFlicker (Single Color (75%)), Gold, Sequel (LightCyan)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Medium), Responsive Blast Fade (Sound Based)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<191,255,255>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<10000>>,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>,Mix<Int<16384>,
	Black,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<000>>,Scale<WavLen<>,Int<9000>,Int<13000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>,Mix<Int<16384>,Black,
	RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<191,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<191,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<191,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Smooth Grey"},



	{"16-SMOOTH_FUZZ;common", "tracks/track_16.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Purple, Prequel(NavajoWhite)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	RetractionTime : 800
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,
	AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,187,108>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,
	Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>,
	TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,
	TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,
	TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,
	Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>>,
	SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,
	TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,
	RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,
	AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,
	RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,
	TrWipeInX<RetractionTime<800>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Smooth Fuzz"},



	{"17-ROGUE_COMMANDER;common", "tracks/track_17.wav",
	/* copyright Fett263 FallenOrder (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#FallenOrder
	OS6.6 v3.01
	Single Style
	Base Style: Fallen Order Ninth Sister, Red, Orignal (LemonChiffon)

	--Effects Included--
	Ignition Effect: Standard Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	RetractionTime : 800
	*/
	StylePtr<Layers<Stripes<18000,-1600,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,
	Stripes<9000,-900,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,
	LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,
	TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,
	Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,
	LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,
	SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,
	RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,
	RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeX<IgnitionTime<300>>,
	TrWipeInX<RetractionTime<800>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Rogue Commander"},



	{"18-TYTHONIAN_CRYSTAL;common", "tracks/track_18.wav",
	/* copyright Fett263 Simple (Primary Blade) OS6 Style
	https://fett263.com/fett263-proffieOS6-style-library.html#Simple
	OS6.6 v3.01
	Single Style
	Base Style: RandomFlicker (Single Color (50%)), Green, Original (LemonChiffon)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	Retraction Effect: Standard Retraction
	Lockup Effect: Responsive Lockup (Absorb)
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Stab Effect: AudioFlicker Stab
	Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
	Clash Effect: Flash on Clash (Full Blade)
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,
	SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,
	RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,
	Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,
	Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,
	BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,
	TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,
	TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,
	Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,
	Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,
	TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "Tythonian Crystal"},


	// ############################
	// ADDITIONAL CUSTOM SOUNDFONTS
	// ############################


	// Portal fireblade force change aperture:
	{"RedditPortal;common", "tracks/stillalive.wav",
	/* OS6.7 v4.019
	Single Style
	Dual Phase (Force Change)
	Default: Fire Blade Slow (Normal)
	1: Fire Blade Slow (Normal)

	Base Color: Rgb<255,0,0> (0)
	Dual Phase Control: use Force to toggle phases.

	--Effects Included--
	Ignition Effect: Standard Ignition
	PowerUp Effect: Power Burst Forward
	Retraction Effect: Gravity Retraction
	Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Dissipate
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Blast Effect: Blast Wave (Sound Based)
	Clash Effect: Random Clash
	Battery Level: Blade Location (Green to Red)
	*/
	StylePtr<Layers<ColorSelect<IncrementModuloF<EffectPulseF<EFFECT_FORCE>,Int<32000>>,TrFade<50>,StaticFire<Gradient<RgbArg<BASE_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<2500>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Int<10280>,Black,Gradient<RgbArg<BASE_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<2500>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,68,0>>>>>,0,1,0,2000,2>,StaticFire<Gradient<Mix<Int<2500>,Black,RgbArg<BASE_COLOR_ARG,Rgb<4,30,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<4,30,255>>>,Mix<Int<10280>,Black,Gradient<Mix<Int<2500>,Black,RgbArg<BASE_COLOR_ARG,Rgb<4,30,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<4,30,255>>>>,0,1,0,2000,2>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Stripes<5000,-2500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,68,0>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,68,0>>>>,TrFade<800>>,EFFECT_IGNITION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_CLASH>,Scale<ClashImpactF<>,Int<9000>,Int<12000>>>,RgbArg<CLASH_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,68,0>>>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,26000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<2,72,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<2,72,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<2,72,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<2,72,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeX<IgnitionTime<300>>,TrSelect<Scale<IsLessThan<BladeAngle<>,Int<18384>>,Int<0>,Int<1>>,TrWipeInX<Scale<BladeAngle<>,Int<2000>,Int<100>>>,TrWipeX<Scale<BladeAngle<>,Int<100>,Int<2000>>>>,Black>,
	//Battery
	TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>,
	//Sabertrio
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "geekbot9999 portal"},



	// Greyscale - Binary Dark
	{"GSBinaryDark;common", "tracks/track1.wav",
	StylePtr<Layers<
	//Force effect toggles between Red and Deep Sky Blue. You can still use the color wheel to try out other colors paired together or edit the colors below yourself.
	EffectSequence<EFFECT_FORCE,Layers<HumpFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,50,120>>,50>,
	AlphaL<AudioFlickerL<Stripes<1000,-1500,RandomPerLEDFlicker<RotateColorsX<Variation,Cyan>,Black>,Black,RotateColorsX<Variation,DeepSkyBlue>,Black>>,SwingSpeed<350>>,
	AlphaL<AlphaL<Stripes<2000,-2250,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<0,50,40>>,Pulsing<RotateColorsX<Variation,Rgb<0,35,20>>,Black,800>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>,Int<550>,Scale<SwingAcceleration<100>,Int<20000>,Int<10000>>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<15000>,Int<5000>>,Int<16000>>>,
	TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<3000>,HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,TrDelay<5000>,HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,TrFade<5000>>,EFFECT_IGNITION>>,
	Layers<HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,
	AlphaL<AudioFlickerL<Stripes<1000,-1500,RandomPerLEDFlicker<RotateColorsX<Variation,DarkOrange>,Black>,Black,RotateColorsX<Variation,Red>,Black>>,SwingSpeed<350>>,
	AlphaL<AlphaL<Stripes<2000,-2250,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,30,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,15,0>>,Black,800>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>,Int<550>,Scale<SwingAcceleration<100>,Int<20000>,Int<10000>>>>,SmoothStep<Scale<Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>,Int<15000>,Int<5000>>,Int<16000>>>,
	TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-1550,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<3000>,HumpFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,50,120>>,50>,TrDelay<5000>,HumpFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,50,120>>,50>,TrFade<5000>>,EFFECT_IGNITION>>>,
	TransitionEffectL<TrConcat<TrInstant,White,TrFade<150>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrDelay<1000>,StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,TrFade<1000>,AlphaL<StyleFire<Stripes<2500,-5000,BrownNoiseFlicker<RotateColorsX<Variation,Magenta>,Black,20>,RotateColorsX<Variation,Rgb<10,0,10>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb<255,25,255>>,70>,RotateColorsX<Variation,Rgb<128,0,128>>>,RotateColorsX<Variation,Rgb<80,0,80>>,0,5,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>,FireConfig<2,3000,0>>,Bump<Int<3500>,Int<23384>>>,TrFade<600>>,EFFECT_FORCE>,
	LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,NavajoWhite>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,White>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,TrFade<350>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
	ResponsiveStabL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Yellow>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,50>>,TrFadeX<Percentage<WavLen<EFFECT_STAB>,50>>>,
	ColorSelect<WavNum<EFFECT_BLAST>,TrInstant,
	TransitionEffectL<TrConcat<TrInstant,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,TrDelay<500>>,EFFECT_BLAST>,
	TransitionEffectL<TrConcat<TrInstant,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,TrFade<500>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,TrFade<350>>,EFFECT_BLAST>>,
	Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,NavajoWhite>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<300>,Int<200>,Int<940>>>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>>,TrFade<350>>,EFFECT_CLASH>,TransitionEffectL<TrConcat<TrWaveX<RgbArg<CLASH_COLOR_ARG,NavajoWhite>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,AlphaL<HumpFlicker<White,Rgb<40,60,60>,50>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>>,TrFade<350>>,EFFECT_CLASH>>,
	LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,27500>,Int<5000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,29250>,Int<5000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<6000>>>,TrConcat<TrWipeIn<100>,AlphaL<Red,SmoothStep<Int<29000>,Int<8000>>>,TrExtend<2000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<29000>,Int<8000>>>,TrFade<3000>>,TrFade<250>,SaberBase::LOCKUP_MELT>,
	EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
	InOutTrL<TrWipeSparkTip<White,1500>,TrColorCycleX<Int<500>,500>>,
	EffectSequence<EFFECT_FORCE,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,DeepSkyBlue>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<1500>>,Int<2000>,Int<4500>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_RETRACTION>>,Black,TrDelay<897>,AlphaL<RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,Bump<Int<10500>,Int<11500>>>,TrDelay<150>>,EFFECT_RETRACTION>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Red>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<1500>>,Int<2000>,Int<4500>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_RETRACTION>>,Black,TrDelay<897>,AlphaL<RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,Bump<Int<10500>,Int<11500>>>,TrDelay<150>>,EFFECT_RETRACTION>>,
	EffectSequence<EFFECT_FORCE,
	TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,DeepSkyBlue>,125>,SmoothStep<Scale<NoisySoundLevel,Int<2500>,Int<15000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>,
	TransitionEffectL<TrConcat<TrDelayX<WavLen<EFFECT_RETRACTION>>,AlphaL<BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,125>,SmoothStep<Scale<NoisySoundLevel,Int<2500>,Int<15000>>,Int<-4000>>>,TrFadeX<WavLen<EFFECT_POSTOFF>>>,EFFECT_RETRACTION>>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	EffectSequence<EFFECT_FORCE,
	TransitionEffectL<TrConcat<TrDelay<500>,Black,TrWaveX<RotateColorsX<Variation,Red>,Int<750>,Int<175>,Int<1575>,Int<-3000>>,Black,TrInstant,AlphaL<RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,Bump<Int<12000>,Int<11500>>>,TrDelay<150>>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrDelay<500>,Black,TrWaveX<RotateColorsX<Variation,DeepSkyBlue>,Int<750>,Int<175>,Int<1575>,Int<-3000>>,Black,TrInstant,AlphaL<RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,Bump<Int<12000>,Int<11500>>>,TrDelay<150>>,EFFECT_PREON>>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<Scale<NoisySoundLevel,Int<150>,Int<10000>>,Int<-4000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>
	//Sabertrio
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "greyscale binary dark"},



	// Greyscale - Endure
	{"GSEndure;common", "common/tracks/mars.wav",
	StylePtr<Layers<
	Mix<Scale<BladeAngle<19000>,Int<32768>,Int<0>>,Blinking<HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>,RotateColorsX<Variation,Red>,918,900>,HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>>,
	TransitionEffectL<TrConcat<TrDelay<1200>,HumpFlicker<RotateColorsX<Variation,Red>,AudioFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb16<11585,0,0>>>,35>,TrFade<450>,RotateColorsX<Variation,Rgb16<26858,591,0>>,TrFade<300>,RotateColorsX<Variation,Rgb16<65535,11439,0>>,TrFade<50>>,EFFECT_FORCE>,
	AlphaL<AudioFlickerL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,Black,RotateColorsX<Variation,Red>,Black>>,SwingSpeed<265>>,
	AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<350>>,
	AlphaL<AlphaL<Stripes<2000,-3750,RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,0,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<850>,Int<13600>>,Scale<SwingSpeed<850>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<14500>,Int<16000>>>,
	LockupTrL<Layers<AlphaL<AudioFlickerL<Rgb<255,150,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
	AlphaL<Moccasin,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<650>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Black,300>,TrFade<1000>,AudioFlickerL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>>,TrFade<2675>>,SaberBase::LOCKUP_NORMAL>,
	ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
	AlphaL<Mix<Scale<BladeAngle<19000>,Int<32768>,Int<0>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,2,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<1750>,Int<4125>>,Int<-4000>>>,
	ResponsiveStabL<Orange>,EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
	ResponsiveClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
	TransitionEffectL<TrConcat<TrInstant,Stripes<1900,-2350,RotateColorsX<Variation,Rgb16<65535,5115,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,8357,0>>,RotateColorsX<Variation,Orange>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<75,0,0>>>>,TrFade<2350>>,EFFECT_IGNITION>,
	TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb16<65535,1899,0>>,40>,TrFade<1750>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,1899,0>>,Black,300>,TrInstant>,EFFECT_RETRACTION>,
	LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
	LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
	EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
	InOutTrL<TrJoin<TrWipe<2000>,TrWaveX<White,Int<2150>,Int<400>,Int<2000>,Int<0>>>,TrJoin<TrWipeIn<1750>,TrWaveX<White,Int<1750>,Int<400>,Int<1750>,Int<32768>>>>,
	TransitionEffectL<TrConcat<TrDelay<1750>,AlphaL<Mix<Trigger<EFFECT_RETRACTION,Int<4250>,Int<6000>,Int<2500>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<14386,0,0>>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>>,SmoothStep<Scale<NoisySoundLevel,Int<-1125>,Int<20000>>,Int<-4000>>>,TrDelay<5000>>,EFFECT_RETRACTION>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<1750>,Int<250>,Int<3000>>,StyleFire<Gradient<RotateColorsX<Variation,Rgb16<65535,11439,0>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Red>>,RotateColorsX<Variation,Rgb<60,0,0>>,0,1,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>,FireConfig<0,2000,5>>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<14386,0,0>>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<25000>>,Int<-4000>>>,TrDelay<2000>>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrDelay<1150>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<125>,Int<350>,Int<315>,Int<0>>>,TrDelay<850>>,EFFECT_PREON>,
	//Sabertrio
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "greyscale endure"},



	// Adam project MagCyl
	{"KPAdamProjectMagCyl;common", "tracks/track1.wav",
	/* OS6.7 v4.019
	Single Style
	Base Style: The Adam Project Saber

	Base Color: Rgb<100,100,150> (0)

	--Effects Included--
	Ignition Effect: Stack
	Retraction Effect: Unstack
	Lockup Effect: Full Blade Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Blast Effect: Blast Wave (Random)
	Clash Effect: Flash on Clash (Full Blade)
	*/
	StylePtr<Layers<Mix<LayerFunctions<LinearSectionF<Int<2000>,Int<1800>>,LinearSectionF<Int<4500>,Int<1000>>,LinearSectionF<Int<6200>,Int<1000>>,LinearSectionF<Int<8500>,Int<1500>>,LinearSectionF<Int<12000>,Int<3200>>,LinearSectionF<Int<16000>,Int<2700>>,LinearSectionF<Int<19500>,Int<2300>>,LinearSectionF<Int<24000>,Int<4800>>,LinearSectionF<Int<28000>,Int<1500>>,LinearSectionF<Int<30000>,Int<1200>>,LinearSectionF<Int<32000>,Int<1500>>>,Black,HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<22000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,30>>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<166,202,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<0,135,255>>>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<0,135,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<0,135,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<0,135,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<6554>,Int<0>>>,TrDelayX<Mult<IgnitionTime<500>,Int<8192>>>,AlphaL<Black,SmoothStep<Int<13108>,Int<0>>>,TrDelayX<Mult<IgnitionTime<500>,Int<8192>>>,AlphaL<Black,SmoothStep<Int<19662>,Int<0>>>,TrDelayX<Mult<IgnitionTime<500>,Int<8192>>>,AlphaL<Black,SmoothStep<Int<26216>,Int<0>>>,TrDelayX<Mult<IgnitionTime<500>,Int<8192>>>>,TrConcat<TrInstant,AlphaL<Black,SmoothStep<Int<26216>,Int<0>>>,TrDelayX<Mult<RetractionTime<0>,Int<8172>>>,AlphaL<Black,SmoothStep<Int<19662>,Int<0>>>,TrDelayX<Mult<RetractionTime<0>,Int<8172>>>,AlphaL<Black,SmoothStep<Int<13108>,Int<0>>>,TrDelayX<Mult<RetractionTime<0>,Int<8172>>>,AlphaL<Black,SmoothStep<Int<6554>,Int<0>>>,TrDelayX<Mult<RetractionTime<0>,Int<8192>>>>,Black>,
	//Battery
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	//Sabertrio
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "adam project"},



	// All standard blades - Rotoscope prequels Light/Blue
	{"KPBattle1Light;common", "tracks/track1.wav",
	/* OS6.7 v4.019
	Single Style
	Base Style: Rotoscope - Single Color (Original Trilogy)

	Base Color: Rgb<2,72,255> (0)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	PowerUp Effect: Power Surge (Stable)
	Retraction Effect: Blink Off
	Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Blast Effect: Blast Wave (Random)
	Clash Effect: Real Clash V1
	*/
	StylePtr<Layers<RandomFlicker<Stripes<10000,-2600,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>,TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,IgnitionTime<0>>,TrJoin<TrBoingX<RetractionTime<0>,3>,TrWipeInX<RetractionTime<0>>>,Black>,
	//Battery
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	//Sabertrio
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "battle 1"},



	// All standard blades - Rototscope prequels Dark/Red
	{"KPBattle2Dark;common", "tracks/track1.wav",
	/* OS6.7 v4.019
	Single Style
	Base Style: Rotoscope - Single Color (Original Trilogy)

	Base Color: Rgb<255,0,0> (0)

	--Effects Included--
	Ignition Effect: SparkTip Ignition
	PowerUp Effect: Power Surge (Stable)
	Retraction Effect: Standard Retraction
	Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb
	LightningBlock Effect: Responsive Lightning Block
	Drag Effect: Intensity Sparking Drag
	Melt Effect: Intensity Melt
	Blast Effect: Blast Wave (Random)
	Clash Effect: Real Clash V1
	*/
	StylePtr<Layers<RandomFlicker<Stripes<10000,-2600,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>>,TrFade<1200>>,EFFECT_IGNITION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,IgnitionTime<0>>,TrWipeInX<RetractionTime<0>>,Black>,
	//Battery
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
	//Sabertrio
	TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>>>(),
	StylePtr<WHITE>(), "battle 2"},


};

BladeConfig blades[] = {
	{ 0, WS281XBladePtr<133, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
		SimpleBladePtr<CreeXPE2WhiteTemplate<550>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>()
	, CONFIGARRAY(blade) },
};

#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
