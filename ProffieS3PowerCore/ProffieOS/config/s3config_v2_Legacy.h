// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 150;
#define VOLUME 1750
#define CLASH_THRESHOLD_G 4.5
#define AUDIO_CLASH_SUPPRESSION_LEVEL 5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SSD1306
#define OLED_FLIP_180
#define NO_REPEAT_RANDOM
#define KILL_OLD_PLAYERS
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 15 * 1000
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS
#define BLADE_DETECT_PIN 17
#define SAVE_PRESET
#define COLOR_CHANGE_DIRECT
#define ENABLE_ALL_EDIT_OPTIONS
#define FETT263_EDIT_SETTINGS_MENU
#define FETT263_ENABLE_SPIN_MODE
#define FETT263_DISABLE_CHANGE_STYLE
#define FETT263_DISABLE_COPY_PRESET
#define FETT263_DISABLE_CHANGE_FONT
#define FETT263_LOCKUP_DELAY 200
#define FETT263_BM_CLASH_DETECT 8 
#define FETT263_FORCE_PUSH
#define FETT263_TWIST_ON
#define FETT263_TWIST_ON_NO_BM
#define FETT263_TWIST_OFF
//#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define FETT263_HOLD_BUTTON_OFF
#define FETT263_DISABLE_MULTI_BLAST
#define FETT263_DISABLE_MULTI_BLAST_TOGGLE
#endif

#ifdef CONFIG_PROP
#include "../props/saber_sabertrio_buttons.h"
// #include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS

Preset blade[] = {

  { "1-SABERTRIO;common", "tracks/track_1.wav",
    
 /* copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Fade (Medium) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<10000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Rotoscope (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.25p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>>(),

/* copyright Fett263 Rotoscope (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(), 

  "sabertrio"  
  },

  { "2-ECHOES;common", "tracks/track_2.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Medium) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(), 

  "echoes"  
  },

  { "4-SENZA;common","tracks/track_4.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Large) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,120>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,60>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,60>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(), 

  "senza"  
  },

  { "5-HIGH_GROUND;common","tracks/track_5.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Medium) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(), 

  "high ground"  
  },

  { "6-PICO_LIGHT;common", "tracks/track_6.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Wipe + Fade [Color: IgnitionColorArg]
Retraction Effect: Wipe In + Fade [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Full Blade Blast Fade [Color: BlastColorArg]
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Wipe + Fade [Color: IgnitionColorArg]
Retraction Effect: Wipe In + Fade [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>>,
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Wipe + Fade [Color: IgnitionColorArg]
Retraction Effect: Wipe In + Fade [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>>>,
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,Black>>>(),
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>>>,
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "pico light"  
  },

  { "7-ROGUE;common", "tracks/track_7.wav",

/* copyright Fett263 JediSurvivor (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Large) [Color: BlastColorArg]
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,1400>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<80>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<80>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 JediSurvivor (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,1400>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<80>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<80>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,2000>>>>>(),

/* copyright Fett263 JediSurvivor (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,1400>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<80>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<80>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,1400>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<80>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<80>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "rogue"  
  },

  { "9-SNIPPETS;common", "tracks/track_9.wav",

/* copyright Fett263 Ahsoka (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Large) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<Stripes<22000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Ahsoka (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<22000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,2000>>>>>(),

/* copyright Fett263 Ahsoka (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<22000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<AudioFlicker<Stripes<22000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "snippets"  
  },

  { "10-DARK_SABER;common", "tracks/track_10.wav",

/* copyright Fett263 DarkSaber (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#DarkSaber
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Medium) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,Stripes<5000,-300,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<25700>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>>,300>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 DarkSaber (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#DarkSaber
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,Stripes<5000,-300,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<25700>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>>,300>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,2000>>>>>(),

/* copyright Fett263 DarkSaber (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#DarkSaber
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,Stripes<5000,-300,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<25700>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>>,300>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,Stripes<5000,-300,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<25700>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>>,300>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "dark saber"  
  },

  { "12-GRAND_MASTER;common", "tracks/track_12.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Medium) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,120>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<175>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<175>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,120>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<175>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,120>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<175>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "grand master"  
  },

  { "13-SPECTRE;common", "tracks/track_13.wav",

/* copyright Fett263 Ahsoka (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Large) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<Stripes<23000,-1300,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Ahsoka (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<23000,-1300,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>>(),

/* copyright Fett263 Ahsoka (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<23000,-1300,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<AudioFlicker<Stripes<23000,-1300,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "spectre"  
  },

  { "15-DESTINY;common", "tracks/track_15.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Rey TROS Spark [Color: PreonColorArg]
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Sound Based) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,68,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,68,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<Int<50>>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrWipe<5>,AlphaL<DodgerBlue,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrDelayX<Sum<WavLen<EFFECT_PREON>,Int<10>>>>,EFFECT_PREON>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Rey TROS Spark [Color: PreonColorArg]
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,2000>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<Int<50>>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-2000>>>,TrWipe<5>,AlphaL<DodgerBlue,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-2000>>>,TrDelayX<Sum<WavLen<EFFECT_PREON>,Int<10>>>>,EFFECT_PREON>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Rey TROS Spark [Color: PreonColorArg]
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<Int<50>>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrWipe<5>,AlphaL<DodgerBlue,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrDelayX<Sum<WavLen<EFFECT_PREON>,Int<10>>>>,EFFECT_PREON>>>(),
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<Int<50>>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrWipe<5>,AlphaL<DodgerBlue,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-2000>>>,TrDelayX<Sum<WavLen<EFFECT_PREON>,Int<10>>>>,EFFECT_PREON>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "destiny"  
  },

  { "16-DAEMOS;common", "tracks/track_16.wav",

/* copyright Fett263 Ahsoka (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Fade (Large) [Color: BlastColorArg]
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<Stripes<26000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<12600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<18600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,TrFade<300>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Ahsoka (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<26000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<12600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<18600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,2000>>>>>(),

/* copyright Fett263 Ahsoka (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<26000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<12600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<18600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<AudioFlicker<Stripes<26000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<12600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<18600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "daemos"  
  },

  { "17-DARK_EDITION;common", "tracks/track_17.wav",

/* copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: Cycle Down [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Medium) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<10>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<80>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrColorCycleX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Rotoscope (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.25p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<80>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
InOutTrL<TrInstant,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Rotoscope (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<10>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<80>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<10>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<80>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "dark edition"  
  },

  { "18-PICO_DARK;common", "tracks/track_18.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Wipe + Fade [Color: IgnitionColorArg]
Retraction Effect: Wipe In + Fade [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Full Blade Blast Fade [Color: BlastColorArg]
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Wipe + Fade [Color: IgnitionColorArg]
Retraction Effect: Wipe In + Fade [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Wipe + Fade [Color: IgnitionColorArg]
Retraction Effect: Wipe In + Fade [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,Black>>>(),
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),

  "pico dark"  
  },

  { "21-KROSGAARD;common", "tracks/track_20.wav",

/* copyright Fett263 KyloRen (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#KyloRen
OS7.14 v3.23p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Cycle Down [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Medium) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,6,10,1000,2>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrColorCycleX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 KyloRen (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#KyloRen
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Cycle Down [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,6,10,1000,2>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrColorCycleX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 KyloRen (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#KyloRen
OS7.14 v3.23p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Delay: Standard Delay
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Cycle Down [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<IgnitionDelayX<Int<350>,Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,6,10,1000,2>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrColorCycleX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>>(),
StylePtr<IgnitionDelayX<Int<350>,Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,6,10,1000,2>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrColorCycleX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "krosgaard"  
  },

  { "23-SECOND;common", "tracks/track_21.wav",

/* copyright Fett263 JediSurvivor (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Fade (Large) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<2000>>,Int<6000>,Int<2000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<4000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,1000>>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<150,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<150,255,255>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 JediSurvivor (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.25p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<2000>>,Int<6000>,Int<2000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<4000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,1000>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 JediSurvivor (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<2000>>,Int<6000>,Int<2000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<4000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,1000>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<2000>>,Int<6000>,Int<2000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<4000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,1000>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "second"  
  },

  { "24-COUNT;common", "tracks/track_22.wav",

/* copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Medium) [Color: BlastColorArg]
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<180,180,255>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<180,180,255>>,TrFade<300>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<180,180,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Rotoscope (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Rotoscope (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "count"  
  },

  { "26-MACE;common", "tracks/track_23.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect:
0: mainLockMulti0Shape - Begin: Real Clash - Style: Intensity AudioFlicker - End: Full Blade Absorb
[Color: LockupColorArg]
Lightning Block Effect:
0: mainLBMulti0Shape - Begin: Responsive Impact - Style: Strobing AudioFlicker - End: Full Blade Absorb
[Color: LBColorArg]
Drag Effect:
0: mainDragMulti0Shape - Begin: Wipe In - Style: Intensity Sparking Drag - End: Wipe Out
[Color: DragColorArg]
Melt Effect:
0: mainMeltMulti0Shape - Begin: Wipe In - Style: Intensity Melt - End: Wipe Out
[Color: StabColorArg]
Blast Effect: Responsive Blast Wave (Medium) [Color: BlastColorArg]
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,120>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
LockupTrL<TransitionEffect<AlphaL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>,AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,BrownNoiseFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<12000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>,300>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<22000>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Mix<Int<20000>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,TrExtend<5000,TrInstant>,TrFade<5000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,199,119>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL,Int<1>>,
ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Blue>,50,1>,TrConcat<TrExtend<200,TrInstant>,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,Bump<Scale<BladeAngle<>,Int<10000>,Int<21000>>,Int<10000>>>,TrFade<200>>,TrConcat<TrInstant,RgbArg<LB_COLOR_ARG,Rgb<150,255,255>>,TrFade<400>>,Int<1>>,
LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<180,130,0>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,
LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,28000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,0>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,120>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,120>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

/* (Accent LED / PCB) */
StylePtr<WHITE>(),  

  "mace"  
  },
};

BladeConfig blades[] = {
  { 0, 
    SubBlade(1, 145, WS281XBladePtr<146, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()),
    SubBlade(0,0, NULL),
    WS281XBladePtr<20, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
    WS281XBladePtr<20, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),
    SimpleBladePtr<CreeXPE2WhiteTemplate<550>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),
    CONFIGARRAY(blade) 
  },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
