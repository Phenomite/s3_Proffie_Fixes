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

