// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 150;
const unsigned int currentLedsInStrip = 114; //32 inch blade at arduino patch time
#define VOLUME 2550
#define BOOT_VOLUME 200 //Low volume at arduino patch time
#define CLASH_THRESHOLD_G 1.25
#define FETT263_SWING_ON_SPEED 340
#define AUDIO_CLASH_SUPPRESSION_LEVEL 5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
// #define ENABLE_SSD1306
// #define OLED_FLIP_180
#define NO_REPEAT_RANDOM
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
#define MOTION_TIMEOUT 60 * 1 * 1000 // 1 min
#define IDLE_OFF_TIME 60 * 1 * 1000 // 1 min
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
//#define FETT263_TWIST_ON
//#define FETT263_TWIST_ON_NO_BM
#define FETT263_TWIST_OFF
#define FETT263_SWING_ON
#define FETT263_SWING_ON_NO_BM
//#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define FETT263_HOLD_BUTTON_OFF
#define FETT263_DISABLE_MULTI_BLAST
#define FETT263_DISABLE_MULTI_BLAST_TOGGLE
//Save space
//#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_TALKIE
#define KILL_OLD_PLAYERS
#endif

#ifdef CONFIG_PROP
#include "../props/saber_sabertrio_buttons.h"
// #include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS

Preset blade[] = {

//shite
  { "1-SOLARIEN;common", "tracks/track_1.wav",
 
/* copyright Fett263 Rotoscope (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.15 v3.27p
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
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Rotoscope (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,2000>>>>>(),

/* copyright Fett263 Rotoscope (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,2000>>>>(),

/* copyright Fett263 Rotoscope (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "solarien"
  },
//keep
  { "2-DESTINY;common", "tracks/track_2.wav",

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
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,2000>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<Int<50>>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-2000>>>,TrWipe<5>,AlphaL<DodgerBlue,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-2000>>>,TrDelayX<Sum<WavLen<EFFECT_PREON>,Int<10>>>>,EFFECT_PREON>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Rey TROS Spark [Color: PreonColorArg]
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,130,0>>,2000>>,
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

  "destiny"
  },
//shite
  { "3-RUIN;common","tracks/track_3.wav",

/* copyright Fett263 KyloRen (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#KyloRen
OS7.15 v3.27p
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
Clash Effect: Real Clash V3 [Color: ClashColorArg]
Emitter Effect: Unstable Flare [Color: EmitterColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,0,6,10,1000,2>,AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,-2000>,Sum<IntArg<EMITTER_SIZE_ARG,-2000>,Int<6000>>>,Int<-6000>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,AlphaL<
TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 KyloRen (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#KyloRen
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,0,6,10,1000,2>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,2000>>>>>(),

/* copyright Fett263 KyloRen (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#KyloRen
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,0,6,10,1000,2>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,2000>>>>(),

/* copyright Fett263 KyloRen (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#KyloRen
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: NoneEmitter Effect: Unstable Flare [Color: EmitterColorArg]
*/
StylePtr<Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,0,6,10,1000,2>,AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,-2000>,Sum<IntArg<EMITTER_SIZE_ARG,-2000>,Int<6000>>>,Int<-6000>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "ruin"
  },
//shite
  { "4-DAEMOS;common","tracks/track_4.wav",

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
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,2000>>>>>(),

/* copyright Fett263 Ahsoka (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<26000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<12600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,Mix<Int<18600>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,14,0>>,2000>>>>(),

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

  "daemos"
  },
//shite
  { "5-STARFALL;common","tracks/track_5.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
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
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,60>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,60>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,60>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "starfall"
  },
//shite
  { "6-ASCENSION;common", "tracks/track_6.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
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
Blast Effect: Responsive Blast Ripple [Color: BlastColorArg]
Clash Effect: Responsive Clash with Wave [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>>,EFFECT_BLAST>,
TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Simple (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "ascension"
  },
//shite
  { "7-DARK_EDITION;common", "tracks/track_7.wav",

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
InOutTrL<TrInstant,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Rotoscope (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.25p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
PowerUp Effect: Power Flash [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<80>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

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

  "dark edition"
  },
//shite
  { "8-PICO_DARK;common", "tracks/track_8.wav",

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
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

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

  "pico dark"
  },
//get rid of
  { "9-DARKNESS;common", "tracks/track_9.wav",

/* copyright Fett263 Acolyte (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Acolyte
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: SparkTip Retraction [Color: RetractionColorArg]
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
StylePtr<Layers<AudioFlicker<Stripes<25000,-1500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,



InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,244,157>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInSparkTipX<RotateColorsX<Int<4096>,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Acolyte (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Acolyte
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: SparkTip Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<25000,-1500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Acolyte (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Acolyte
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<25000,-1500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

/* copyright Fett263 Acolyte (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Acolyte
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: SparkTip Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<25000,-1500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "darkness"
  },
//keep
  { "10-VENGEANCE;common", "tracks/track_10.wav",

/* copyright Fett263 Visions (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Visions
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
Clash Effect: Responsive Clash [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,50>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Visions (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Visions
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,50>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Visions (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Visions
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,50>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

/* copyright Fett263 Visions (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Visions
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<Stripes<20000,-800,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,50>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "vengeance"
  },
//shite
  { "11-KROSGAARD;common", "tracks/track_11.wav",

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
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrColorCycleX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 KyloRen (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#KyloRen
OS7.14 v3.23p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StaticFire<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<3213>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,300>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,0,6,10,1000,2>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

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

  "krosgaard"
  },
//ehh
  { "12-MENACE;common", "tracks/track_12.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
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
Blast Effect: Responsive Blast Wave (Sound Based) [Color: BlastColorArg]
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<WavLen<>,Int<100>,Int<400>>,Int<100>,Scale<WavLen<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
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
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "menace"
  },
//shite
  { "13-SECOND;common", "tracks/track_13.wav",

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
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 JediSurvivor (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.25p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<2000>>,Int<6000>,Int<2000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<4000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,1000>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

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

  "second"
  },
//keep
  { "14-COUNT;common", "tracks/track_14.wav",

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
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Rotoscope (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

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

  "count"
  },
//shite
  { "15-TRAGEDY;common", "tracks/track_15.wav",

/* copyright Fett263 Acolyte (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Acolyte
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Reverse [Color: RetractionColorArg]
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
Emitter Effect: Unstable Flare [Color: EmitterColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<Stripes<25000,-1500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<180,180,255>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,-2000>,Sum<IntArg<EMITTER_SIZE_ARG,-2000>,Int<6000>>>,Int<-6000>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,


InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Acolyte (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Acolyte
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Reverse [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<25000,-1500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>>(),

/* copyright Fett263 Acolyte (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Acolyte
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Reverse [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<25000,-1500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

/* copyright Fett263 Acolyte (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Acolyte
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
PowerUp Effect: Power Surge (Unstable V1) [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
CoolDown Effect: Unstable Cool Down Reverse [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: NoneEmitter Effect: Unstable Flare [Color: EmitterColorArg]
*/
StylePtr<Layers<AudioFlicker<Stripes<25000,-1500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10640>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<18460>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<180,180,255>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>,
TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,200>,RandomPerLEDFlicker<Mix<Int<16384>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>>>>,TrFade<1200>>,EFFECT_IGNITION>,
TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "tragedy"
  },
//shite
  { "16-INFINIUM;common", "tracks/track_16.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
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
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,120>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,120>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,120>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "infinium"
  },
//keep
  { "17-MACE;common", "tracks/track_17.wav",

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
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,2000>>>>>(),

/* copyright Fett263 (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<153,0,255>>,2000>>>>(),

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

  "mace"
  },
//shite
  { "18-LEGACY;common", "tracks/track_18.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
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
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Simple (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "legacy"
  },
//get rid of
  { "19-SABERTRIO;common", "tracks/track_19.wav",

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
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<0>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>>(),

/* copyright Fett263 Rotoscope (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Rotoscope
OS7.14 v3.25p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>(),

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

  "sabertrio"
  },
//keeeep
  { "20-ECHOES;common", "tracks/track_20.wav",

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
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>(),

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

  "echoes"
  },
//keep
  { "21-HIGH_REPUBLIC;common", "tracks/track_21.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
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
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Simple (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "high republic"
  },
//delete
  { "22-LIGHT;common", "tracks/track_22.wav",

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
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,120>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,



InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
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
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>>(),

/* copyright Fett263 (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>(),

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
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,120>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,BendTimePowInvX<IgnitionTime<300>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "light"
  },
//shite
  { "23-SENZA;common", "tracks/track_23.wav",

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
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>>(),

/* copyright Fett263 (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>(),

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

  "senza"
  },
//shite
  { "24-HIGH_GROUND;common", "tracks/track_24.wav",

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
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>>(),

/* copyright Fett263 (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,38,255>>,2000>>>>(),

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

  "high ground"
  },
//shite
  { "25-PICO_LIGHT;common", "tracks/track_25.wav",

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
InOutTrL<TrJoinR<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>>,TrJoin<TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,TrSmoothFadeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,75,255>>,2000>>>>(),

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

  "pico light"
  },
//keep
  { "26-ROGUE;common", "tracks/track_26.wav",

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
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<80>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,2000>>>>>(),

/* copyright Fett263 JediSurvivor (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<8000>,Int<3000>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<-2600>,Int<-3600>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,Pulsing<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,1400>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,2000>>>>(),

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

  "rogue"
  },
//keep
  { "27-SHOCK_BATON;common", "tracks/track_27.wav",

/* copyright Fett263 EnergyWeapon (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#EnergyWeapon
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Center Absorb [Color: PreonColorArg]
Ignition Effect: Center In [Color: IgnitionColorArg]
Retraction Effect: Split Retraction [Color: RetractionColorArg]
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
StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<150,255,255>>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,
InOutTrL<TrCenterWipeInX<BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>,Int<16384>>,TrCenterWipeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,Int<16384>>,Black>,
TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_PREON>,TrInstant>,Remap<CenterDistF<>,Layers<TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<150,255,255>>,Int<200>,Int<100>,Int<32768>>>,AlphaL<RgbArg<PREON_COLOR_ARG,Rgb<150,255,255>>,SmoothStep<Int<0>,Scale<Trigger<EFFECT_PREON,WavLen<EFFECT_PREON>,Int<500>,Int<200>,Int<100>>,Int<-1>,Int<-20000>>>>>>,TrInstant>,EFFECT_PREON>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 EnergyWeapon (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#EnergyWeapon
OS7.14 v3.23p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Power Absorb [Color: PreonColorArg]
Ignition Effect: Center In [Color: IgnitionColorArg]
Retraction Effect: Split Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<150,255,255>>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,
InOutTrL<TrCenterWipeInX<BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>,Int<16384>>,TrCenterWipeX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>,Int<16384>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<150,255,255>>,2000>>>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<PREON_SIZE_ARG,32768>,Int<-4000>>>,TrLoopN<8,TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Divide<WavLen<EFFECT_PREON>,Int<8>>,Int<32768>>>>,EFFECT_PREON>>>(),

/* copyright Fett263 EnergyWeapon (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#EnergyWeapon
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Center Absorb [Color: PreonColorArg]
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<150,255,255>>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<150,255,255>>,2000>>>>(),

/* copyright Fett263 EnergyWeapon (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#EnergyWeapon
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Preon Effect: Sparking [Color: PreonColorArg]
Ignition Effect: SparkTip Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<150,255,255>>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<180,180,255>>,BendTimePowInvX<IgnitionTime<100>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<PREON_SIZE_ARG,2000>,Sum<IntArg<PREON_SIZE_ARG,2000>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>>>(),

  "shock baton"
  },
//shite
  { "28-SNIPPETS;common", "tracks/track_28.wav",

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
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,2000>>>>>(),

/* copyright Fett263 Ahsoka (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<22000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<10000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<18000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>,2000>>>>(),

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

  "snippets"
  },
//keeeeep
  { "29-DARK_SABER;common", "tracks/track_29.wav",

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
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,2000>>>>>(),

/* copyright Fett263 DarkSaber (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#DarkSaber
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<BrownNoiseFlicker<Mix<SwingSpeed<400>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,Stripes<5000,-300,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<25700>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<1285>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>>>,300>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,White>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<150,150,255>>,2000>>>>(),

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

  "dark saber"
  },
//shite
  { "30-CELESTIAL;common", "tracks/track_30.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
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
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Simple (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<38,255,75>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "celestial"
  },
//ehhhhh
  { "31-ALLIANCE;common", "tracks/track_31.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
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
Clash Effect: Responsive Clash with Wave [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,60>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,60>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,60>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "alliance"
  },
//shite
  { "32-HERO'S_JOURNEY;common", "tracks/track_32.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
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
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,
TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Int<200>,Int<100>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Simple (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "hero's journey"
  },
//already got
  { "33-BALANCE;common", "tracks/track_33.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
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
Clash Effect: Flash on Clash (Full Blade) [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Simple (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.25p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<250>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "balance"
  },
//keeeep
  { "34-GRAND_MASTER;common", "tracks/track_34.wav",

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
InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,BendTimePowInvX<IgnitionTime<175>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>>(),

/* copyright Fett263 (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.14 v3.01p
Single Style
On Behavior: Kyber Flow Up [Color: BaseColorArg]
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<Stripes<5000,-2500,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>(),

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

  "grand master"
  },
//ehhh
  { "35-SPECTRE;common", "tracks/track_35.wav",

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
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>>(),

 /* copyright Fett263 Ahsoka (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Ahsoka
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<Stripes<23000,-1300,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>(),

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

  "spectre"
  },
//ehhh
  { "36-RECONCILE;common", "tracks/track_36.wav",

/* copyright Fett263 Simple (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
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
Clash Effect: Random Clash with Wave [Color: ClashColorArg]
Battery Level: % Blade (Green to Red)
*/
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<ClashImpactF<>,Int<28000>,Int<8000>>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

/* copyright Fett263 Simple (Crystal Chamber) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
This Style Contains 2 Unique Combinations
Style Option
Off Behavior Options: Default (0): Off, 1: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,2000>>>>>(),

/* copyright Fett263 Simple (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,2000>>>>(),

/* copyright Fett263 Simple (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#Simple
OS7.15 v3.27p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<150>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "reconcile"
  },
//shite
  { "37-GUARDIAN;common", "tracks/track_37.wav",

/* copyright Fett263 JediSurvivor (Primary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
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
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<3600>,Int<1600>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2700>,Int<-4100>>,Mix<Int<16000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,
TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,EFFECT_BLAST>,
TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>,



InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>,
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
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<3600>,Int<1600>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2700>,Int<-4100>>,Mix<Int<16000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,ColorSelect<IntArg<OFF_OPTION_ARG,1>,TrInstant,Black,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,2000>>>>>(),

/* copyright Fett263 JediSurvivor (Accent LED / PCB) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.01p
Single Style
Style Option
Off Behavior: Fast Pulse Off-On [Color: Match ON Color]

Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Instant [Color: IgnitionColorArg]
Retraction Effect: Instant [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<3600>,Int<1600>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2700>,Int<-4100>>,Mix<Int<16000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,
InOutTrL<TrInstant,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>,2000>>>>(),

/* copyright Fett263 JediSurvivor (Quillion / Secondary Blade) OS7 Style
https://www.fett263.com/fett263-proffieOS7-style-library.html#JediSurvivor
OS7.14 v3.01p
Single Style
Style Option
Base Color: BaseColorArg (0)

--Effects Included--
Ignition Effect: Standard Ignition [Color: IgnitionColorArg]
Retraction Effect: Standard Retraction [Color: RetractionColorArg]
Lockup Effect: NoneLightning Block Effect: NoneDrag Effect: NoneMelt Effect: None */
StylePtr<Layers<StripesX<Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<3000>,Int<3000>>,Int<3600>,Int<1600>>,Scale<HoldPeakF<Sum<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_ALT_SOUND>>,Int<2000>,Int<4000>>,Int<-2700>,Int<-4100>>,Mix<Int<16000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,Mix<Sin<Int<20>,Int<22000>,Int<32768>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>,Mix<Int<8000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,255,0>>>>,
InOutTrL<TrWipeX<BendTimePowInvX<IgnitionTime<200>,Mult<IntArg<IGNITION_OPTION2_ARG,10992>,Int<98304>>>>,TrWipeInX<BendTimePowX<RetractionTime<0>,Mult<IntArg<RETRACTION_OPTION2_ARG,10992>,Int<98304>>>>,Black>>>(),

  "guardian"
  },
};

BladeConfig blades[] = {
  { 0, 
    SubBlade(1, 145, WS281XBladePtr<146, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()),
    SubBlade(0,0, NULL),
    SubBlade(0, 0, WS281XBladePtr<20, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4,bladePowerPin5, bladePowerPin1> >()),
    SubBlade(1,19, NULL),
    CONFIGARRAY(blade)
  },
};
#endif

#ifdef CONFIG_BUTTONS
  Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
  Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif