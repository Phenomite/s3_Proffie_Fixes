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
#define MOTION_TIMEOUT 60*1*1000
#define SHARED_POWER_PINS
#define BLADE_DETECT_PIN 17
#define SAVE_PRESET
#define FETT263_TWIST_ON
#define FETT263_TWIST_OFF
#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define ENABLE_ALL_EDIT_OPTIONS
#define FETT263_EDIT_MODE_MENU
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_TALKIE
//#define NO_BATTERY_MONITOR
//#define NO_STATUS_LED

#endif

#ifdef CONFIG_PROP
#include"../props/s3button_config.h"
#endif

#ifdef CONFIG_PRESETS


/*--------------------------------- Helpers -------------------------
*/

// Custom sabertrio soundlevel add to all styles
using AllStyles_SaberTrioSoundLevel = TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<DisplaySoundLevel,Red,Green>,SmoothStep<DisplaySoundLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_SOUND_LEVEL>;

// On-Demand Battery Level for all styles
using AllStyles_BatteryLevel = TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>;


// Lightnings
using Lightning_BrightBlue = ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>;
using Lightning_White = ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>;


// Melts
using Melt_Intense = LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>;


// Drags
using Drag_WhiteLemonChiffon = LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>;
using Drag_White = LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<200,200,200>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<200,200,200>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>;
using Drag_Red = LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,0,0>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,0,0>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>;


// Lockups (blade lock)
// Fett type (bigger memory no longer used): //LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>;
using Lockup_NavajoWhiteFull = LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>;
using Lockup_Intense_White = LockupTrL<Layers<AlphaL<Blinking<White,Strobe<Orange,Rgb<255,255,255>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,AlphaL<Blinking<BrownNoiseFlicker<Orange,Rgb<255,255,255>,50>,BrownNoiseFlicker<Rgb<255,255,255>,White,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<16500>>>>,TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Rgb<255,255,255>,Rgb<128,128,128>,500>,Orange,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>;
using Lockup_Intense_OrangeRed = LockupTrL<Layers<AlphaL<Blinking<OrangeRed,Strobe<Orange,Rgb<255,64,0>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,AlphaL<Blinking<BrownNoiseFlicker<Orange,Rgb<255,64,0>,50>,BrownNoiseFlicker<Rgb<255,64,0>,OrangeRed,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<16500>>>>,TrConcat<TrInstant,AlphaL<Blinking<OrangeRed,Strobe<BrownNoiseFlicker<Rgb<255,64,0>,Rgb<128,32,0>,500>,Orange,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrConcat<TrInstant,OrangeRed,TrFade<400>>,SaberBase::LOCKUP_NORMAL>;
using Lockup_Intense_Yellow = LockupTrL<Layers<AlphaL<Blinking<LemonChiffon,Strobe<Orange,Rgb<255,225,0>,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,AlphaL<Blinking<BrownNoiseFlicker<Orange,Rgb<255,225,0>,50>,BrownNoiseFlicker<Rgb<255,225,0>,LemonChiffon,50>,100,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<16500>>>>,TrConcat<TrInstant,AlphaL<Blinking<LemonChiffon,Strobe<BrownNoiseFlicker<Rgb<255,225,0>,Rgb<128,113,0>,500>,Orange,15,30>,60,500>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<300>>,TrConcat<TrInstant,LemonChiffon,TrFade<400>>,SaberBase::LOCKUP_NORMAL>;

// Clashes
using Clash_Flash_Nate = TransitionEffectL<TrConcat<TrInstant,Rgb<255,225,0>,TrDelay<25>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Orange,LemonChiffon,20,20>,BrownNoiseFlicker<Rgb<255,225,0>,LemonChiffon,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,LemonChiffon,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>;
using Clash_Real_LightCyan = Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<191,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<191,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>;
using Clash_Real_GreenYellow = Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<108,255,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<108,255,0>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>;
using Clash_Real_OrangeRed = Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,14,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,14,0>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-10000>>>>,EFFECT_CLASH>>;
using Clash_Real_White = Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-10000>>>>,EFFECT_CLASH>>;
using Clash_Responsive_Red = TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,0,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>;
using Clash_Responsive_Orange = TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,97,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>;
using Clash_Responsive_LightCyan = TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<191,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>;
using Clash_Responsive_Moccasin = TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,199,119>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>;
using Clash_Flash_LemonChiffon = TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>;
using Clash_Flash_White = TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>;


// Blasts
using Blast_Responsive_Mix_Orange = TransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,68,0>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,68,0>>>>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<32000>>>,TrJoin<TrSmoothFade<50>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>>>,TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,68,0>>,Int<200>,Int<200>,Int<400>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>>,EFFECT_BLAST>;
using Blast_Wave_LemonChiffon = TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<150>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>;
using Blast_Wave_LightCyan = TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Int<150>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>;
using Blast_Wave_White = TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Int<150>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>;
using Blast_Wave_Yellow = TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,0>>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Int<150>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>;
using Blast_Flash_Moccasin = TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<BLAST_COLOR_ARG,Rgb<255,199,119>>,TrFade<300>>,EFFECT_BLAST>;
using Blast_Flash_White = TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_BLAST>;


// Preons / Postoffs
using Preon_Sparking_Cyan = TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<0,255,255>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<PREON_SIZE_ARG,700>,Sum<IntArg<PREON_SIZE_ARG,700>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>;
using Preon_Overload_Blue = TransitionEffectL<TrConcat<TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<30,60,200>>,10>,SmoothStep<IntArg<PREON_SIZE_ARG,700>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<30,60,200>>,15>,SmoothStep<Sum<Int<2000>,IntArg<PREON_SIZE_ARG,700>>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<30,60,200>>,20>,SmoothStep<Sum<Int<4000>,IntArg<PREON_SIZE_ARG,700>>,Int<-4000>>>,TrBoingX<Mult<Int<8192>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>;
using Preon_Emitter_Heat = TransitionEffectL<TrConcat<TrFadeX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,AlphaL<HumpFlickerL<Red,10>,SmoothStep<IntArg<PREON_SIZE_ARG,2800>,Int<-2000>>>,TrFadeX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,AlphaL<HumpFlickerL<Orange,15>,SmoothStep<IntArg<PREON_SIZE_ARG,2800>,Int<-3000>>>,TrFadeX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,AlphaL<HumpFlickerL<White,20>,SmoothStep<IntArg<PREON_SIZE_ARG,2800>,Int<-4000>>>,TrFadeX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>>,EFFECT_PREON>;
using Preon_AbsorbIn_Blue = TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<0,135,255>>,Int<200>,Int<500>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<6144>>>,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<0,135,255>>,Int<300>,Int<300>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<0,135,255>>,Int<400>,Int<100>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<12288>>>,AlphaL<RgbArg<PREON_COLOR_ARG,Rgb<0,135,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrBoingX<Mult<WavLen<EFFECT_PREON>,Int<6144>>,5>>,EFFECT_PREON>;
using Preon_AbsorbIn_Orange = TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<255,140,0>>,Int<200>,Int<500>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<6144>>>,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<255,140,0>>,Int<300>,Int<300>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<255,140,0>>,Int<400>,Int<100>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<12288>>>,AlphaL<RgbArg<PREON_COLOR_ARG,Rgb<255,140,0>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrBoingX<Mult<WavLen<EFFECT_PREON>,Int<6144>>,5>>,EFFECT_PREON>;
using Preon_Glitch_Sound_Red = TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,100>,RandomPerLEDFlicker<RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,RotateColorsX<Int<4000>,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-450>,Int<32768>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>;
using Postoff_Glitch_Audio_Red = TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AudioFlickerL<AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AudioFlickerL<AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,EFFECT_POSTOFF>;
using Postoff_Emitter_HeatFade = TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,EFFECT_POSTOFF>;
using Postoff_Emitter_Glow_Cyan = TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<POSTOFF_COLOR_ARG,Rgb<0,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,700>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>;


// Emitters
using Emitter_Orange_Flicker = 	AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,100,0>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2500>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<8000>>>,Int<-8000>>>;
using Emitter_Cyan_Flicker = AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Cyan>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2500>,Int<-6000>>>;

// Stabs
using Stab_LemonChiffon = TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>;
using Stab_Red = TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,0,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>;

/*--------------------------------------------------------------------------------*/


/*==================================*/
/*==== Style_PhenomElectroStaff ====*/
/*==================================*/
using Style_PhenomElectroStaff = Layers<
	StaticFire<Strobe<RgbArg<BASE_COLOR_ARG,Rgb<0,80,255>>,Strobe<Rgb<100,80,190>,RandomPerLEDFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,80,255>>,Black>,50,1>,100,1>,Mix<Int<6425>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,80,255>>>,0,5,2,1000,5>,
	AlphaL<Stripes<10000,-2000,HumpFlicker<Rgb<0,0,40>,Rgb<20,30,0>,50>,HumpFlicker<Blue,NavajoWhite,50>,HumpFlicker<Rgb<0,0,80>,Rgb<40,60,0>,50>>,SwingSpeed<600>>,
	Blast_Responsive_Mix_Orange,
	Clash_Responsive_Orange,
	Lockup_Intense_OrangeRed,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,IgnitionTime<300>>,TrColorCycleX<RetractionTime<0>>,Black>,
	Preon_Sparking_Cyan,
	Postoff_Emitter_Glow_Cyan,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*==================================*/


/*=================================*/
/*====== Style_MeatyStarTrek ======*/
/*=================================*/
using Style_MeatyStarTrek = Layers<
	Mix<SmoothStep<Int<16384>,Int<6425>>,Remap<InvertF<RampF>,Stripes<2600,-1800,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,Stripes<2600,-1600,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<4000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>>>,
	TransitionEffectL<TrConcat<TrJoin<TrDelay<3900>,TrFade<300>>,StripesX<Int<3500>,Scale<SlowNoise<Int<3000>>,Int<-2500>,Int<-3500>>,RgbArg<SWING_COLOR_ARG,Rgb<85,85,200>>,Mix<Int<10280>,Black,RgbArg<SWING_COLOR_ARG,Rgb<85,85,200>>>,RandomPerLEDFlicker<Mix<Int<2570>,Black,RgbArg<SWING_COLOR_ARG,Rgb<85,85,200>>>,RgbArg<SWING_COLOR_ARG,Rgb<85,85,200>>>>,TrFade<400>>,EFFECT_FORCE>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Remap<CenterDistF<>,Stripes<2600,-2800,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<500>>,EFFECT_IGNITION>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<5000,-2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Red>,Bump<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Red>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Red>>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>>,EFFECT_BLAST>,
	Clash_Real_OrangeRed,
	Stab_LemonChiffon,
	Lockup_Intense_OrangeRed,
	Lightning_BrightBlue,
	Drag_White,
	Melt_Intense,
	InOutTrL<TrJoinR<TrCenterWipeX<IgnitionTime<300>,Int<16384>>,TrSmoothFadeX<IgnitionTime<300>>>,TrCenterWipeX<RetractionTime<0>,Int<16384>>,Black>,
	Preon_Overload_Blue,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>,TrCenterWipeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>>,Remap<CenterDistF<>,Stripes<2000,-1500,Black,Rgb<255,14,0>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>,Remap<CenterDistF<>,Stripes<1000,-500,Black,Rgb<255,14,0>,Black>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>>,EFFECT_POSTOFF>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*==================================*/


/*==================================*/



/*--------------------------------- Style_KyloUnstableRage -------------------------
copyright Fett263 CustomBlade (Primary Blade) OS6 Style
https://fett263.com/fett263-proffieOS6-style-library.html#CustomBlade
OS6.7 v4.020
Single Style
Unstable Rage
--Effects Included--
Ignition Effect: Standard Ignition
PowerUp Effect: Unstable Power Up Forward
Retraction Effect: Standard Retraction
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Blast Effect: Blast Wave (Random)
Clash Effect: Real Clash V1
Swing Effect: AudioFlicker Swing (Scaled Full Blade)
*/
using Style_KyloUnstableRage = Layers<Stripes<3000,-3500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,
	AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,0,0>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<250>>,TrInstant>,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>>>>,TrFade<600>>,EFFECT_IGNITION>,
	Blast_Wave_LightCyan,
	Clash_Real_White,
	Lockup_Intense_White,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeX<IgnitionTime<250>>,TrWipeInX<RetractionTime<500>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_PhenomTragedySenate-------------------------
based off eyeballing https://www.reddit.com/r/lightsabers/comments/fqh6ef/free_font_senate_majority_sidious_inspired/
OS6.7 v4.020
Single Style
Base Style: Rotoscope - Single Color (Prequels)
Base Color: Rgb<255,0,0> (0)
--Effects Included--
Ignition Effect: Lightning Strike
PowerUp Effect: Power Surge (Unstable V2)
Retraction Effect: Cycle Down
CoolDown Effect: Power Burst Reverse
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Blast Effect: Blast Wave (Random)
Clash Effect: Real Clash V1
Swing Effect: AudioFlicker Swing (Scaled Full Blade)
Emitter Effect: Emitter Flare
*/
using Style_PhenomTragedySenate = Layers<RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
	//AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,20,0>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,1700>,Int<-6000>>>,
	// Whiteish Rage swing flicker
	AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<150,150,150>>>,Scale<IsLessThan<SwingSpeed<800>,Int<13600>>,Scale<SwingSpeed<800>,Int<-19300>,Int<32768>>,Int<0>>>,
	TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<800>>,EFFECT_RETRACTION>,
	Blast_Wave_White,
	Clash_Real_White,
	Lockup_NavajoWhiteFull,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrConcat<TrWipeInX<Mult<IgnitionTime<480>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Black>,TrJoin<TrDelayX<Mult<IgnitionTime<480>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1500>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<IgnitionTime<480>,Int<19660>>>>,TrColorCycleX<RetractionTime<600>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_PhenomCrispyPinkFlicker-------------------------
*/
using Style_PhenomCrispyPinkFlicker = Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<220,0,200>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<220,0,200>>>>,
	AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<0,150,100>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,3000>,Int<-6000>>>,
	AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<0,220,255>>>,Scale<IsLessThan<SwingSpeed<250>,Int<13600>>,Scale<SwingSpeed<250>,Int<-19300>,Int<32768>>,Int<0>>>,
	TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<220,0,200>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<128,0,225>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<128,0,225>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<128,0,225>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<128,0,225>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<128,0,225>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
	Blast_Wave_White,
	Clash_Responsive_LightCyan,
	Lockup_Intense_White,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,IgnitionTime<150>>,TrColorCycleX<RetractionTime<0>,950,7500>,Black>,
	Preon_AbsorbIn_Blue,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<POSTOFF_COLOR_ARG,Rgb<118,0,194>>,SmoothStep<IntArg<PREON_SIZE_ARG,2800>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_PhenomSparkleOff-------------------------
Made to replicate the CFX effect here:
https://www.youtube.com/watch?v=GcZVxD_0w9U
*/
using Style_PhenomSparkleOff = Layers<
	AudioFlicker<GreenYellow,HumpFlicker<RgbArg<BASE_COLOR_ARG,Orange>,RgbArg<ALT_COLOR_ARG,Rgb<180,130,0>>,30>>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,Black>,SmoothStep<Int<10000>,Int<-10000>>>,TrFade<1000>>,EFFECT_IGNITION>,
	TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AudioFlicker<Red,Rgb<128,0,0>>,TrDelay<500>>,EFFECT_RETRACTION>,
	Blast_Responsive_Mix_Orange,
	Clash_Flash_White,
	Lockup_Intense_OrangeRed,
	Lightning_BrightBlue,
	Drag_Red,
	Melt_Intense,
	Stab_Red,
	InOutTrL<TrWipeSparkTipX<White,IgnitionTime<400>,Int<150>>,
		TrConcat<TrWipeInX<RetractionTime<0>>,
			StrobeX<Black,Layers<
				Sparkle<Black,BlinkingX<Rgb<50,90,0>,Rgb<127,0,0>,Scale<SlowNoise<Int<3000>>,Int<0>,Int<300>>,Int<500>>,2048,2048>,
				SparkleL<BlinkingX<Rgb<127,127,60>,GreenYellow,Scale<SlowNoise<Int<3000>>,Int<0>,Int<300>>,Int<500>>,500>>,
				Int<19>,
				Scale<SlowNoise<Int<3000>>,Int<10>,Int<110>>
			>,TrInstant>
	>,
	Preon_Emitter_Heat,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_BanishedPurpleOverload-------------------------
My custom Jaydalorian banished style for os6.7:
*/
using Style_BanishedPurpleOverload = Layers<StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>>,0,5,0,3000,15>,
	AlphaL<Mix<SwingSpeed<600>,Red,Orange,White>,Scale<SwingSpeed<500>,Int<0>,Int<32768>>>,
	Blast_Wave_Yellow,
	Clash_Responsive_Moccasin,
	Lockup_NavajoWhiteFull,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<1138>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,RetractionTime<1049>>,Black>,
	Preon_Emitter_Heat,
	Postoff_Glitch_Audio_Red,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/


/*--------------------------------- EnginesBurn------------------------------*/
/* OS6.7 v4.019
Single Style
Fire Blade Fastest (Sparking)
Base Color: Rgb<152,130,61> (0)
--Effects Included--
Preon Effect: Emitter Heat Up
Ignition Effect: SparkTip Ignition
Retraction Effect: Metal Forge (Cool Down)
CoolDown Effect: Unstable Cool Down Forward
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Blast Effect: Blast Wave (Random)
Clash Effect: Real Clash V1
*/
using Style_EnginesBurn = Layers<StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<152,130,61>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<152,130,61>>>,0,5,0,3000,5>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<600>>,TrInstant>,Stripes<3000,-3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
	Blast_Wave_White,
	Clash_Real_White,
	Lockup_Intense_White,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrConcat<TrFadeX<RetractionTime<600>>,White,TrFadeX<RetractionTime<600>>,DarkOrange,TrFadeX<RetractionTime<600>>,Red,TrFadeX<RetractionTime<600>>>,Black>,
	Preon_Emitter_Heat,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/


/*--------------------------------- GreyscaleEndureRageCustom-------------------------
OS6.7 v4.019
Single Style
Base Style: Fallen Order Second Sister
Base Color: Rgb<255,0,0> (0)
--Effects Included--
Preon Effect: Faulty Ignition (PreOn Color)
Ignition Effect: Standard Ignition
PowerUp Effect: Unstable Power Up Forward
Retraction Effect: SparkTip Retraction
Lockup Effect: Responsive Lockup, Begin Effect: Full Blade Flash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Fire Drag
Melt Effect: Responsive Melt
Blast Effect: Blast Wave (Random)
Clash Effect: Random Clash with Wave
Emitter Effect: Flickering Flare
*/
using GreyscaleEndureRageCustom = Layers<StaticFire<RgbArg<BASE_COLOR_ARG,Red>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,244,157>>>,0,5,0,2000,10>,
	//StripesX<Int<1500>,Int<-6000>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<2570>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
	Emitter_Orange_Flicker,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>>>>,TrFade<800>>,EFFECT_IGNITION>,
	// BinDark swing power wave (but in light orange)
	AlphaL<AlphaL<Stripes<1500,-3500,RgbArg<SWING_COLOR_ARG,Rgb<255,150,0>>,Mix<Int<8000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<255,150,0>>>,Mix<Int<4000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<255,150,0>>>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<800>,Int<13600>>,Scale<SwingSpeed<800>,Int<-16000>,Int<32768>>,Int<0>>,Int<650>,Scale<SwingAcceleration<100>,Int<25000>,Int<15000>>>>,SmoothStep<Int<15000>,Int<16000>>>,
	//AlphaL<AlphaL<Stripes<1500,-6000,RgbArg<SWING_COLOR_ARG,Rgb<255,120,0>>,Mix<Int<8000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<255,120,0>>>,Mix<Int<4000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<255,120,0>>>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<800>,Int<13600>>,Scale<SwingSpeed<800>,Int<-16000>,Int<32768>>,Int<0>>,Int<650>,Scale<SwingAcceleration<100>,Int<25000>,Int<15000>>>>,SmoothStep<Int<15000>,Int<16000>>>,
	Clash_Responsive_Moccasin,
	Lockup_NavajoWhiteFull,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,250,250>>,RetractionTime<1550>>,Black>,
	Preon_Glitch_Sound_Red,
	//POSTOFF fizzle cooldown
	Postoff_Glitch_Audio_Red,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- GreyscaleBinaryDark-------------------------
Phenom custom remake from official style
https://fett263.com/fett263-proffieOS6-style-library.html#CustomBlade
OS6.7 v4.020
Single Style
Dual Phase (Force Change)
Default: AudioFlicker (Single Color (50%))
1: AudioFlicker (Single Color (50%))
Base Color: Rgb<255,0,0> (0)
Dual Phase Control: use Force to toggle phases.
--Effects Included--
Ripple Swing Effect: Force Toggle between swing ripple color matching blade color
Preon Effect: Sparking (PreOn Color)
Ignition Effect: SparkTip Ignition
Retraction Effect: Cycle Down
CoolDown Effect: Power Burst Reverse
PostOff Effect: Emitter Spark (Preon Size)
Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Blast Effect: Blast Wave (Random)
Clash Effect: Flash on Clash (Full Blade)
Swing Effect: AudioFlicker Swing (Scaled Cutting Edge)
*/
using GreyscaleBinaryDark = Layers<ColorSelect<IncrementModuloF<EffectPulseF<EFFECT_FORCE>,Int<32000>>,TrColorCycle<2450>,AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>>>,AudioFlicker<RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>>,
	EffectSequence<EFFECT_FORCE,
		// Darkside (index 0 but comes 2nd)
		// Rgb<255,68,0> DarkOrange
		Layers<
			AlphaL<AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,68,0>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<650>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<16000>,Int<32000>>>,
			AlphaL<AlphaL<Stripes<2000,-2250,RgbArg<SWING_COLOR_ARG,Rgb<255,120,0>>,Mix<Int<8000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<255,120,0>>>,Mix<Int<4000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<255,120,0>>>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<800>,Int<13600>>,Scale<SwingSpeed<800>,Int<-16000>,Int<32768>>,Int<0>>,Int<650>,Scale<SwingAcceleration<100>,Int<25000>,Int<15000>>>>,SmoothStep<Int<15000>,Int<16000>>>>,
		// Lightside (index 1 but comes 1st)
		// Rgb<0,255,210> GreenCyan
		Layers<
			AlphaL<AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<224,255,255>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<650>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<16000>,Int<32000>>>,
			AlphaL<AlphaL<Stripes<2000,-2250,RgbArg<SWING_COLOR_ARG,Rgb<50,255,210>>,Mix<Int<8000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<50,255,210>>>,Mix<Int<4000>,Black,RgbArg<SWING_COLOR_ARG,Rgb<50,255,210>>>>,HoldPeakF<Scale<IsLessThan<SwingSpeed<800>,Int<13600>>,Scale<SwingSpeed<800>,Int<-16000>,Int<32768>>,Int<0>>,Int<650>,Scale<SwingAcceleration<100>,Int<25000>,Int<15000>>>>,SmoothStep<Int<15000>,Int<16000>>>>
	>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<800>>,EFFECT_RETRACTION>,
	Blast_Wave_LemonChiffon,
	Clash_Flash_LemonChiffon,
	Lockup_NavajoWhiteFull,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<1500>>,TrColorCycleX<RetractionTime<500>>,Black>,
	// Prespark from OG Bindark modded
	TransitionEffectL<TrConcat<TrDelay<500>,RgbArg<PREON_COLOR_ARG,Black>,TrWaveX<OrangeRed,Int<750>,Int<175>,Int<1575>,Int<-3000>>,Black,TrInstant,AlphaL<AudioFlickerL<OrangeRed>,Bump<Int<12000>,Int<11500>>>,TrDelay<150>>,EFFECT_PREON>,
	// Endure preon edit
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,100>,RandomPerLEDFlicker<RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,RotateColorsX<Int<4000>,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<0>,Int<10000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,
	// Post off
	TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,Rgb<255,0,0>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<1500>>,Int<2000>,Int<4500>>,Int<-4000>>>,TrDelayX<RetractionTime<0>>,Black,TrDelay<897>,AlphaL<RandomPerLEDFlicker<RgbArg<POSTOFF_COLOR_ARG,Rgb<255,0,0>>,Black>,Bump<Int<10500>,Int<11500>>>,TrDelay<150>>,EFFECT_RETRACTION>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_GreenSwingOrange-------------------------
OS6.7 v4.019
AudioFlicker (Single Color (75%))
Base Color: Rgb<80,230,110> (WHITE effects)
--Effects Included--
Preon Effect: Power Absorb (PreOn Color)
Ignition Effect: SparkTip Ignition
PowerUp Effect: Power Burst Forward
Retraction Effect: Cycle Down
Lockup Effect: Intensity Lockup V1, Begin Effect: Full Blade Flash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Blast Effect (Randomly Selected): Responsive Blast Ripple Fade, Responsive Blast Wave (Large)
Clash Effect: Responsive Clash (RED)
Swing Effect: Bright Swing (Scaled Cutting Edge) (YELLOW)
*/
using Style_GreenSwingOrange = Layers<
	Stripes<10000,-850,RgbArg<BASE_COLOR_ARG,Rgb<80,230,140>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<80,230,140>>>,Mix<Int<6425>,RgbArg<BASE_COLOR_ARG,Rgb<80,230,140>>,White>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<80,230,140>>>>,
	//AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<80,230,140>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<80,230,140>>>>,
	//AlphaL<AlphaL<RgbArg<SWING_COLOR_ARG,Rgb<193,13,200>>,Scale<IsLessThan<SwingSpeed<250>,Int<13600>>,Scale<SwingSpeed<250>,Int<-19300>,Int<32768>>,Int<0>>>,SmoothStep<Int<16000>,Int<16000>>>,
	AlphaL<RgbArg<SWING_COLOR_ARG,Rgb<255,140,0>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Stripes<5000,-2500,RgbArg<IGNITION_COLOR_ARG,Rgb<80,255,140>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,140,0>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,140,0>>>>,TrFade<800>>,EFFECT_IGNITION>,
	Blast_Responsive_Mix_Orange,
	Clash_Responsive_Red,
	Lockup_Intense_White,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<55,255,169>>,IgnitionTime<300>>,TrColorCycleX<RetractionTime<0>,950,7500>,Black>,
	Preon_AbsorbIn_Orange,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_GreenBlueAudioFlicker-------------------------
Pong Krell The Clone Wars
--Effects Included--
Preon Effect: Rey TROS Spark
Ignition Effect: Custom bright white/purple sparktip + Ignition purple audioflicker
Retraction Effect: Standard Retraction
Lockup Effect: Intensity Lockup V1, Begin Effect: Full Blade Flash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Stab Effect: AudioFlicker Stab
Blast Effect: Blast Wave (Random)
Clash Effect: Real Clash V1
Swing Effect: AudioFlicker Swing (Scaled Full Blade)
*/
using Style_GreenBlueAudioFlicker = Layers<AudioFlicker<RotateColorsX<Variation,Rgb16<23829,65535,1514>>,RotateColorsX<Variation,Rgb16<4702,5401,65535>>>,
	//AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,White>>,SwingSpeed<600>>,	
	AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
	Blast_Responsive_Mix_Orange,
	Clash_Responsive_Orange,
	Lockup_Intense_White,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<198,49,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
	InOutTrL<TrWipeSparkTipX<RandomFlicker<White,RgbArg<IGNITION_COLOR_ARG,Rgb<255,190,255>>>,IgnitionTime<200>,Int<100>>,TrWipeInX<RetractionTime<0>>,Black>,
	Preon_Emitter_Heat,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_TripleLightsideFlicker-------------------------
Blue/Aquamarine/Purple AudioFlicker

--Effects Included--
Preon Effect: Rey TROS Spark
Ignition Effect: Custom bright white/purple sparktip + Ignition purple audioflicker
Retraction Effect: Standard Retraction
Lockup Effect: Intensity Lockup V1, Begin Effect: Full Blade Flash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Stab Effect: AudioFlicker Stab
Blast Effect: Blast Wave (Random)
Clash Effect: Real Clash V1
Swing Effect: AudioFlicker Swing (Scaled Full Blade)
*/
using Style_TripleLightsideFlicker = Layers<AudioFlicker<RotateColorsX<Variation,Rgb<0,0,255>>,AudioFlicker<RotateColorsX<Variation,Rgb<0,255,0>>,Rgb<189,8,255>>>,
	//AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,White>>,SwingSpeed<600>>,	
	//AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
	Blast_Responsive_Mix_Orange,
	Clash_Responsive_Orange,
	Lockup_Intense_White,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<198,49,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
	InOutTrL<TrWipeSparkTipX<RandomFlicker<White,RgbArg<IGNITION_COLOR_ARG,Rgb<255,190,255>>>,IgnitionTime<200>,Int<100>>,TrWipeInX<RetractionTime<500>>,Black>,
	Preon_Glitch_Sound_Red,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_DarksaberLive-------------------------
*/
using Style_DarksaberLive = Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<239,249,255>>,Mix<Int<20479>,Black,RgbArg<BASE_COLOR_ARG,Rgb<239,249,255>>>>,
	Blast_Responsive_Mix_Orange,
	Clash_Responsive_Orange,
	Lockup_NavajoWhiteFull,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	AllStyles_BatteryLevel,
	AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*---------------------------- StandardBlueOriginalRotoscope----------------------
Based on Star Wars: Episode IV - A New Hope / with swing bright
Rgb<9,105,255> Custom DodgerBlue
111 and 110 for the stripe audioflicker since i like subtle
*/
using StandardBlueOriginalRotoscope = Layers<
	AudioFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<15,55,255>>,RgbArg<BASE_COLOR_ARG,Rgb<15,55,255>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<15,55,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<15,55,255>>,Mix<Int<28672>,Black,RgbArg<BASE_COLOR_ARG,Rgb<15,55,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<15,55,255>>>,
	AlphaL<RgbArg<SWING_COLOR_ARG,Rgb<150,150,255>>,Scale<IsLessThan<SwingSpeed<700>,Int<13600>>,Scale<SwingSpeed<700>,Int<-19300>,Int<32768>>,Int<0>>>,
	//emitter wick
	AlphaL<AudioFlickerL<Black>,SmoothStep<Int<2700>,Int<-2500>>>,
	//AlphaL<Green,SmoothStep<Scale<SlowNoise<Int<1600>>,Int<1000>,Int<4000>>,Int<-4000>>>,
	TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Stripes<7000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<100,100,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<100,100,255>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<100,100,255>>>>,TrFade<500>>,EFFECT_IGNITION>,
	Blast_Responsive_Mix_Orange,
	Clash_Responsive_Orange,
	Lockup_NavajoWhiteFull,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeX<IgnitionTime<250>>,TrWipeInX<RetractionTime<0>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/
/* All the following styles use this template:
OS6.7 v4.019
RandomFlicker (Single Color (50%))
--Effects Included--
Ignition Effect: SparkTip Ignition
Retraction Effect: Standard Retraction
Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
LightningBlock Effect: Responsive Lightning Block
Drag Effect: Intensity Sparking Drag
Melt Effect: Intensity Melt
Stab Effect: AudioFlicker Stab
Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
Clash Effect: Flash on Clash (Full Blade)
*/

/*--------------------------------- StandardBlueSparkAudioFlicker-------------------------
Luke/Ani/Ahsoka
*/
using StandardBlueSparkAudioFlicker = Layers<
	HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,120>,
	Blast_Responsive_Mix_Orange,
	Clash_Flash_LemonChiffon,
	Lockup_NavajoWhiteFull,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*--------------------------------- StandardYellowRandomFlicker-------------------------
Temple Guardian
*/
using StandardYellowSparkRandomFlicker = Layers<
	HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<200,180,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<200,180,0>>>,120>,
	Blast_Wave_LemonChiffon,
	Clash_Flash_LemonChiffon,
	Lockup_NavajoWhiteFull,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*--------------------------------- StandardYellowRandomFlicker-------------------------
C1-10P
*/
using StandardOrangeSparkRandomFlicker = Layers<
	HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,97,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,97,0>>>,120>,
	Blast_Wave_LemonChiffon,
	Clash_Flash_LemonChiffon,
	Lockup_NavajoWhiteFull,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*--------------------------------- StandardPurpleSparkHumpFlicker-------------------------
Mace Rgb<198,49,255> (AOTC) - Rgb<173,13,255> (ROTS)
*/
using StandardPurpleSparkHumpFlicker = Layers<
	HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<202,49,243>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<202,49,243>>>,60>,
	Blast_Wave_LemonChiffon,
	Clash_Flash_LemonChiffon,
	Lockup_NavajoWhiteFull,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*--------------------------------- StandardGreenRandomFlicker-------------------------
*/
using StandardGreenSparkRandomFlicker = Layers<
	HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,120>,
	Blast_Wave_LemonChiffon,
	Clash_Flash_LemonChiffon,
	Lockup_NavajoWhiteFull,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*--------------------------------- StandardRedRandomFlicker-------------------------
*/
using StandardRedSparkRandomFlicker = Layers<
	HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,120>,
	Blast_Wave_LemonChiffon,
	Clash_Flash_LemonChiffon,
	Lockup_NavajoWhiteFull,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*--------------------------------- StandardRedRandomFlicker-------------------------
//Nates DarkBloodOrangeCustomHumpFlickerBladestyle https://pastebin.com/XTPLnpy3
*/
using Style_DarkBloodOrangeHumpFlicker = Layers<
	HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,120>,
	Blast_Wave_LemonChiffon,
	Clash_Flash_Nate,
	Lockup_Intense_Yellow,
	Lightning_White,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	Stab_LemonChiffon,
	InOutTrL<TrWipeSparkTip<Rgb<255,28,0>,325,1000>,TrWipeInSparkTip<Rgb<255,28,0>,650,1000>>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*--------------------------------- StandardRainbow-------------------------
*/
using Style_Rainbow = Layers<
	Stripes<30000,-300,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
	Blast_Flash_White,
	Clash_Flash_White,
	Lockup_NavajoWhiteFull,
	Lightning_White,
	Drag_White,
	Melt_Intense,
	InOutTrL<TrWipeX<IgnitionTime<500>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,RetractionTime<900>>,Black>,
	AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;



/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/



Preset blade[] = {

	// ################################################
	// ################################################
	// ##             SABERTRIO STOCK                ##
	// ################################################
	// ################################################

	{ "1-SABERTRIO;common", "tracks/track1.wav",
	StylePtr<StandardBlueOriginalRotoscope>(), StylePtr<WHITE>(), "Sabertrio"},

	{ "2-DARK_EDITION;common", "tracks/track1.wav",
	StylePtr<StandardRedSparkRandomFlicker>(), StylePtr<WHITE>(), "Dark Edition"},

	{ "3-THE_LIGHT;common","tracks/track_3.wav",
	StylePtr<StandardBlueSparkAudioFlicker>(), StylePtr<WHITE>(), "The Light"},

	{ "4-THE_BALANCE;common","tracks/track_4.wav",
	StylePtr<StandardGreenSparkRandomFlicker>(), StylePtr<WHITE>(), "The Balance"},

	{ "5-THE_DARK;common","tracks/track_5.wav",
	StylePtr<StandardRedSparkRandomFlicker>(), StylePtr<WHITE>(), "The Dark"},

	// { "6-VENGEANCE;common", "tracks/track1.wav",
	// StylePtr<StandardRedSparkRandomFlicker>(),
	// StylePtr<WHITE>(), "Vengeance"},

	// Based on darksaber?? but with flicker swing
	{ "8-SNIPPETS;common", "tracks/track_8.wav",
	StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "Snippets"},

	// Same style as the dark / vengeance
	{ "9-MENACE;common", "tracks/track_9.wav",
	StylePtr<StandardRedSparkRandomFlicker>(), StylePtr<WHITE>(), "Menace"},

	{ "10-TEMPLE_GUARDIAN;common", "tracks/track_10.wav",
	StylePtr<StandardYellowSparkRandomFlicker>(), StylePtr<WHITE>(), "Temple Guardian"},

	{ "11-SHOCK_BATON;common", "tracks/track_11.wav",
	StylePtr<Layers<BrownNoiseFlicker<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>,
	TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<2,72,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
	Blast_Wave_White,
	Clash_Responsive_LightCyan,
	Lockup_NavajoWhiteFull,
	Lockup_Intense_White,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	InOutTrL<TrCenterWipeInX<IgnitionTime<200>,Int<16384>>,TrCenterWipeInX<RetractionTime<0>,Int<16384>>,Black>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<RgbArg<PREON_COLOR_ARG,Rgb<255,255,255>>,Rgb<100,100,150>,300>,LayerFunctions<SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>,SmoothStep<Int<30768>,Int<4000>>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
	//Battery/Sabertrio
	AllStyles_BatteryLevel,
	AllStyles_SaberTrioSoundLevel
	>>(), StylePtr<WHITE>(), "Shock Baton"},

	// { "12-THE_TRAGEDY;common", "tracks/track_12.wav",
	// StylePtr<Style_PhenomTragedySenate>(), StylePtr<WHITE>(), "The Tragedy"},


	// ################################################
	// ################################################
	// ##                   KSith                    ##
	// ################################################
	// ################################################


	// TFA Graflex v2
	{ "KSithRogue;common", "tracks/hallway.wav",
	StylePtr<StandardRedSparkRandomFlicker>(), StylePtr<WHITE>(), "ksith rogue"},


	// ################################################
	// ################################################
	// ##                KYBERPHONIC                 ##
	// ################################################
	// ################################################


	// TFA Graflex v2
	{ "KPTFATakodana;common", "tracks/tfa.wav",
	StylePtr<StandardBlueOriginalRotoscope>(), StylePtr<WHITE>(), "tfa takodana"},

	// TFA Graflex v2
	{ "KPTFAStarkiller;common", "tracks/reyvkylo.wav",
	StylePtr<StandardBlueOriginalRotoscope>(), StylePtr<WHITE>(), "tfa starkiller"},

	// Free (using mando music meh)
	{ "KPBattle1;common", "tracks/mando.wav",
	StylePtr<StandardBlueSparkAudioFlicker>(), StylePtr<WHITE>(), "battle1"},

	// Free (using mando music meh)
	{ "KPBattle3;common", "tracks/mando.wav",
	StylePtr<Style_TripleLightsideFlicker>(), StylePtr<WHITE>(), "battle3"},

	// Ahsoka Season 1 ( Baylan Skoll )
	{ "KPSunSkoll;common", "tracks/mando.wav",
	StylePtr<Style_DarkBloodOrangeHumpFlicker>(), StylePtr<WHITE>(), "sunskoll"},

	// Dark saber (live action)
	{ "KPDarkV3;common", "tracks/mandotheme.wav",
	StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "dark saber"},

	// Asohka white (mando)
	{ "KPTheSorcererBeskar;common", "tracks/thesorcerer.wav",
	StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "the sorcerer"},

	// Asohka blue (clone wars)
	{ "KPCommanderTano;common", "tracks/swclonewars.wav",
	StylePtr<StandardBlueSparkAudioFlicker>(), StylePtr<WHITE>(), "commander tano"},

	// Kylo - The Force Awakens (Kyberphonic Unstable v2)
	{ "KPUnstableV2;common", "tracks/track1.wav",
	StylePtr<Style_KyloUnstableRage>(), StylePtr<WHITE>(), "unstable v2"},

	// Adam Project
	// { "KPAdamProjectMagCyl;common", "tracks/track_16.wav",
	// StylePtr<Layers<Mix<LayerFunctions<LinearSectionF<Int<2000>,Int<1800>>,LinearSectionF<Int<4500>,Int<1000>>,LinearSectionF<Int<6200>,Int<1000>>,LinearSectionF<Int<8500>,Int<1500>>,LinearSectionF<Int<12000>,Int<3200>>,LinearSectionF<Int<16000>,Int<2700>>,LinearSectionF<Int<19500>,Int<2300>>,LinearSectionF<Int<24000>,Int<4800>>,LinearSectionF<Int<28000>,Int<1500>>,LinearSectionF<Int<30000>,Int<1200>>,LinearSectionF<Int<32000>,Int<1500>>>,Black,HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<22000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<100,100,150>>>,30>>,
	// Blast_Wave_White,
	// Clash_Flash_White,
	// Lockup_Intense_White,
	// Lightning_White,
	// Drag_White,
	// Melt_Intense,
	// Stab_Red,
	// InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
	// //Battery/Sabertrio
	// AllStyles_BatteryLevel,
	// AllStyles_SaberTrioSoundLevel
	// >>(), StylePtr<WHITE>(), "magcyl"},

	// Metamorphose (Transformers)
	{ "KPMetamorphose;common", "tracks/track1.wav",
	StylePtr<StandardPurpleSparkHumpFlicker>(), StylePtr<WHITE>(), "metamorphose"},

	// TFM - F1 Racer
	{ "KPFOneRacer;common", "tracks/track_13.wav",
	StylePtr<Style_EnginesBurn>(), StylePtr<WHITE>(), "podracer"},



	// ################################################
	// ################################################
	// ##                 GREYSCALE                  ##
	// ################################################
	// ################################################


	// Greyscale - Binary Dark (paid)
	{ "GSBinaryDark;common", "tracks/track1.wav",
	StylePtr<GreyscaleBinaryDark>(), StylePtr<WHITE>(), "gs binarydark"},

	// Greyscale - Crispy (free)
	{ "GSCrispity;common", "tracks/track1.wav",
	StylePtr<Style_PhenomCrispyPinkFlicker>(), StylePtr<WHITE>(), "gs crispy"},

	// Greyscale - Endure (paid)
	{ "GSEndure;common", "tracks/track1.wav",
	StylePtr<GreyscaleEndureRageCustom>(), StylePtr<WHITE>(), "gs endure"},

	// Greyscale - Coda (free)
	{ "GSCoda;common", "tracks/track1.wav",
	StylePtr<Style_PhenomSparkleOff>(), StylePtr<WHITE>(), "gs coda"},

	// Greyscale - Deadlink (free)
	{ "GSDeadlink;common", "tracks/track1.wav",
	StylePtr<Style_PhenomSparkleOff>(), StylePtr<WHITE>(), "gs deadlink"},

	// Greyscale - Apocalypse (free)
	{ "GSApocalypse;common", "tracks/track1.wav",
	StylePtr<Style_BanishedPurpleOverload>(), StylePtr<WHITE>(), "gs apocalypse"},

	// Greyscale - Mercenary (free)
	{ "GSMercenary;common", "tracks/track1.wav",
	StylePtr<Style_GreenSwingOrange>(), StylePtr<WHITE>(), "gs mercenary"},


	// ################################################
	// ## Mountain Sabers ##
	// ################################################

	// The Beginner (free)
	{ "MSTheBeginner;common", "tracks/sw.wav",
	StylePtr<StandardBlueOriginalRotoscope>(), StylePtr<WHITE>(), "ms thebeginner"},

	// Double Agent Pong Krell (paid)
	{ "MSPongKrell;common", "tracks/swrebelstheme.wav",
	StylePtr<Style_GreenBlueAudioFlicker>(), StylePtr<WHITE>(), "ms doubleagent"},

	// Star Trek Whale probe ep 4 (paid)
	{ "MSStarTrekWhaleProbe;common", "tracks/STT.wav",
	StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "whale probe"},


	// ################################################
	// ##  Meaty  ##
	// ################################################

	// https://www.youtube.com/shorts/YZBsMuEkjx4
	{ "MeatyC110P;common", "tracks/swrebelstheme.wav",
	StylePtr<StandardOrangeSparkRandomFlicker>(), StylePtr<WHITE>(), "meaty c110p"},

	// https://www.youtube.com/shorts/YZBsMuEkjx4
	{ "MeatyDomo;common", "tracks/MrRoboto.wav", //Killroy
	StylePtr<Style_TripleLightsideFlicker>(), StylePtr<WHITE>(), "meaty domo"},

	// https://www.youtube.com/watch?v=c3NMZTPvBTE
	{ "MeatyStarTrek;common", "tracks/sttngtheme.wav",
	StylePtr<Style_MeatyStarTrek>(), StylePtr<WHITE>(), "meaty trek"},

	// Christmas V2 10/16/22
	{ "MeatyChristmas;common", "tracks/track1.wav",
	StylePtr<Style_Rainbow>(), StylePtr<WHITE>(), "meaty christmas"},


	// ####################################
	// ####################################
	// ##             OTHERS             ##
	// ####################################
	// ####################################


	{ "MongoDuneV2;common", "tracks/dune.wav",
	StylePtr<Style_PhenomElectroStaff>(), StylePtr<WHITE>(), "mongo dune"},

	// Cosmic Ape - Dreamhunter (paid)
	{ "CADreamhunter;common", "tracks/track1.wav",
	StylePtr<Style_GreenSwingOrange>(), StylePtr<WHITE>(), "ca dreamhunter"},

	// Jaydalorian Banished (paid)
	{ "JDBanished;common", "tracks/track1.wav",
	StylePtr<Style_BanishedPurpleOverload>(), StylePtr<WHITE>(), "jd banished"},

	// Jaydalorian Decimate (free)
	{ "JDDecimate;common", "tracks/track1.wav",
	StylePtr<Style_GreenBlueAudioFlicker>(), StylePtr<WHITE>(), "jd decimate"},

	// // CFX Default - Shatterpoint (converted)
	// { "GCSShatterpoint;common", "tracks/track1.wav",
	// StylePtr<StandardPurpleSparkHumpFlicker>(), StylePtr<WHITE>(), "gcs windu"},

	// CFX Default - Kamino (converted)
	{ "CFX-Kamino;common", "tracks/track1.wav",
	// Rain effect
	StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,30,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,30,255>>>>,SparkleL<Black,400>,
	Blast_Responsive_Mix_Orange,
	Clash_Responsive_Orange,
	Lockup_NavajoWhiteFull,
	Lightning_BrightBlue,
	Drag_WhiteLemonChiffon,
	Melt_Intense,
	InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<500>>,Black>,
	//Battery & Sabertrio
	AllStyles_BatteryLevel,
	AllStyles_SaberTrioSoundLevel
	>>(), StylePtr<WHITE>(), "cfx kamino"},


	// ################################################
	// ## Reddit ##
	// ################################################


	{ "Reddit-ARCANE;common", "tracks/track1.wav",
	StylePtr<Style_PhenomSparkleOff>(), StylePtr<WHITE>(), "reddit arcane"},

	// Palpatine
	{ "Reddit-Senate-Majority;common", "tracks/palpatheme.wav",
	StylePtr<Style_PhenomTragedySenate>(), StylePtr<WHITE>(), "reddit senate majority"},

	{ "Reddit-Ronin;common", "tracks/track1.wav", //Not a jedi
	StylePtr<Style_KyloUnstableRage>(), StylePtr<WHITE>(), "reddit ronin"},

	// Portal fireblade
	{ "Reddit-Portal;common", "tracks/stillalive.wav",
	StylePtr<Layers<Layers<Remap<Scale<CenterDistF<>,Int<0>,Int<65536>>,Remap<InvertF<RampF>,Mix<SmoothStep<Int<19652>,Int<13123>>,StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<0,44,249>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,44,249>>>,0,2,0,3000,3>,StaticFire<RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>>,0,2,0,3000,3>>>>,AlphaL<Black,LinearSectionF<Int<16384>,Int<8171>>>>,
	Blast_Flash_White,
	Clash_Flash_White,
	Lightning_White,
	InOutTrL<TrCenterWipeInX<IgnitionTime<500>,Int<16384>>,TrCenterWipeInX<RetractionTime<500>,Int<16384>>,Black>,
	AllStyles_BatteryLevel,
	AllStyles_SaberTrioSoundLevel
	>>(), StylePtr<WHITE>(), "geekbot9999 portal"},


	// ################################################
	// ##  Misc  ##
	// ################################################


	// Slave 1 with seismic charge preon - NoSloppy
	{ "SlaveOneTwoPointOne;common", "tracks/track1.wav",
	StylePtr<Layers<Mix<SmoothStep<Int<16384>,Int<4000>>,Stripes<10000,500,Rgb<0,30,80>,Rgb<0,60,180>>,Stripes<10000,-500,Rgb<0,30,80>,Rgb<0,60,180>>>,
	// Clash - 3 stage fading impact spot
	TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
	// Blast
	//MultiTransitionEffectL<TrConcat<TrDelay<700>,AlphaL<Black,Int<0>>,TrFade<800>,LocalizedClashL<HumpFlicker<DarkOrange,Red,50>,2000,50,EFFECT_BLAST>,TrFade<600>>,EFFECT_BLAST>,
	LocalizedClashL<Blinking<White,Black,130,800>,1560,50,EFFECT_BLAST>,
	LocalizedClashL<Blinking<Red,Black,130,500>,1560,15,EFFECT_BLAST>,
	// Lockup
	LockupTrL<Layers<
	AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
	AlphaL<BrownNoiseFlicker<Yellow,Black,50>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,
	TrConcat<TrInstant,
	AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
	TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
	TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<100>>,EFFECT_LOCKUP_BEGIN>,
	TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
	// Non-Responsive Drag
	//LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
	Drag_WhiteLemonChiffon,
	Lightning_BrightBlue,
	Stab_LemonChiffon,
	// //Begin Lightning Transition
	// TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb16<21301,0,65535>,Black,500>,TrFade<100>>,
	// //End Lightning Transition
	// TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb16<21301,0,65535>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >>,  
	// Melt
	// LockupTrL<
	// //Mely Colors
	// AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
	// // Melt Shape
	// SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
	// //Melt Begin and End transitions
	// TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>,
	// Ignition Powerup
	TransitionEffectL<TrConcat<TrInstant,BrownNoiseFlicker<DeepSkyBlue,White,100>,TrFade<800>>,EFFECT_IGNITION>,
	// In/out using Trigger for instantaneous Center-out wipes
	InOutTrL<TrConcat<TrInstant,Layers<
	AlphaL<Black,SmoothStep<Scale<Trigger<EFFECT_IGNITION,Int<300>,Int<1000>,Int<500>>,Int<16385>,Int<0>>,Int<-1>>>,
	AlphaL<Black,SmoothStep<Scale<Trigger<EFFECT_IGNITION,Int<300>,Int<1000>,Int<500>>,Int<16384>,Int<32768>>,Int<0>>>>,TrDelay<1000>>,
		//TrJoin<TrWipe<700>,TrWipeIn<700>>
		TrCenterWipeInX<RetractionTime<700>,Int<16384>>
	>,
	TransitionEffectL<TrConcat<TrInstant,Cyan,TrDelay<50>>,EFFECT_IGNITION>,
	// Asteroid impacts after detonation - timed sequence
	TransitionEffectL<TrConcat<
	TrDelay<1500>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Red,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<3000>,Int<6000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
	TrDelay<400>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Orange,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<6000>,Int<10000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
	TrDelay<200>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Black,White,100>,Bump<ChangeSlowly<SlowNoise<Int<30000>>,Int<60000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<300>,AlphaL<Red,Int<0>>,
	TrDelay<200>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Yellow,Red,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<10000>,Int<28000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<200>,AlphaL<Red,Int<0>>,
	TrDelay<500>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Orange,White,100>,Bump<ChangeSlowly<SlowNoise<Int<30000>>,Int<60000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<200>,AlphaL<Red,Int<0>>,
	TrDelay<100>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Red,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<5000>,Int<13000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
	TrDelay<500>,GreenYellow,TrDelay<25>>,EFFECT_IGNITION>,
	// Seismic Charge preon effect. use with linked preon sound
	TransitionEffectL<TrConcat<TrDelay<2125>,Cyan,TrFade<100>,Black,TrDelay<10>,Cyan,TrFade<150>
	>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrDelay<2125>,AlphaL<White,Bump<Int<16384>,Int<32768>>>,TrFade<100>, Black,TrDelay<10>,AlphaL<White,Bump<Int<16384>,Int<32768>>>,TrFade<150>
	>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrDelay<2100>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<3000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<4000>>>,
	//TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<5000>>>,
	TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<10000>>>,
	TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,
	TrSmoothFade<175>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<30000>>>,
	TrSmoothFade<125>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<35000>>>,
	TrSmoothFade<150>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<30000>>>,
	TrSmoothFade<75>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,
	TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<8000>>>,
	TrSmoothFade<25>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<3000>>>,TrFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,TrDelay<25>>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Scale<Trigger<EFFECT_PREON,Int<2000>,Int<1000>,Int<500>>,Int<-1000>,Int<16500>>,Int<1500>>>,TrDelay<2000>>,EFFECT_PREON>,
	TransitionEffectL<TrConcat<TrDelay<1100>,AlphaL<Red,Int<0>>,TrSmoothFade<700>,Black,TrDelay<100>,AlphaL<White,Bump<Int<16384>,Int<3000>>>,TrDelay<100>>,EFFECT_PREON>,
	//Battery & Sabertrio
	AllStyles_BatteryLevel,
	AllStyles_SaberTrioSoundLevel
	>>(), StylePtr<WHITE>(), "slave1"},

	// Epiphany - Epic (MUSIC BASED)
	{ "MusicEpic;common", "tracks/track1.wav",
	StylePtr<Style_Rainbow>(), StylePtr<WHITE>(), "music epic"},

};

BladeConfig blades[] = {
	{
		0,
		WS281XBladePtr<115, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
		SimpleBladePtr<CreeXPE2WhiteTemplate<550>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),
		CONFIGARRAY(blade)
	},
};

#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif