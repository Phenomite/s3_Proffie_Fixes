// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 144; //36 inch blade
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
#define OLED_FLIP_180
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
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_TALKIE
#define KILL_OLD_PLAYERS
#endif

#ifdef CONFIG_PROP
#include "../props/saber_sabertrio_buttons.h"
//#include "../props/saber_fett263_buttons.h"
#endif

// Modified for OS7.12
#ifdef CONFIG_PRESETS

/*--------------------------------- Helpers -------------------------
*/

// On-Demand Battery Level for all styles
using AllStyles_BatteryLevel = TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>;
// Custom sabertrio soundlevel add to all styles
using AllStyles_SaberTrioSoundLevel = TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>;

// Lightnings
using Lightning_BrightBlue = ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,LightCyan>,AudioFlicker<RgbArg<LB_COLOR_ARG,LightCyan>,Blue>,50,1>,TrConcat<TrInstant,GreenYellow,TrDelay<30>,BrownNoiseFlicker<Rgb<12,52,255>,Black,500>,TrFade<100>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,LightCyan>,Int<16000>>,30>,TrSmoothFade<600>>>;
using Lightning_Purple = ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb16<21301,0,65535>>,White,50,10>,TrConcat<TrInstant,GreenYellow,TrDelay<30>,BrownNoiseFlicker<Rgb<12,52,255>,Black,500>,TrFade<100>>,TrConcat<TrInstant,BrownNoiseFlicker<RgbArg<LB_COLOR_ARG,Rgb16<21301,0,65535>>,Black,500>,TrJoinR<TrWipe<125>,TrWipeIn<125>>>>;
using Lightning_White = ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,GreenYellow,TrDelay<30>,BrownNoiseFlicker<White,Black,500>,TrFade<100>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>;

// Melts
using Melt_Intense = LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrWipeIn<1500>,TrWipe<200>,SaberBase::LOCKUP_MELT>;
using Melt_Intense_Delayed = LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>;

// Drags
using Drag_White_Fire = LockupTrL<AlphaL<Stripes<2000,4000,RgbArg<DRAG_COLOR_ARG,White>,Mix<Sin<Int<30>>,Black,RgbArg<DRAG_COLOR_ARG,White>>,Mix<Int<8192>,Black,RgbArg<DRAG_COLOR_ARG,White>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<8000>>>,TrWipeIn<200>,TrFade<300>,SaberBase::LOCKUP_DRAG>;
using Drag_Orange_Fire = LockupTrL<AlphaL<Stripes<2000,4000,RgbArg<DRAG_COLOR_ARG,Orange>,Mix<Sin<Int<30>>,Black,RgbArg<DRAG_COLOR_ARG,Orange>>,Mix<Int<8192>,Black,RgbArg<DRAG_COLOR_ARG,Orange>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<8000>>>,TrWipeIn<200>,TrFade<300>,SaberBase::LOCKUP_DRAG>;
using Drag_White_Long = LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,LemonChiffon,200>,White>,SmoothStep<IntArg<DRAG_SIZE_ARG,20000>,Int<8000>>>,TrConcat<TrInstant,LemonChiffon,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrFade<300>,SaberBase::LOCKUP_DRAG>;

// Lockups (blade lock)
// Fett type (bigger memory no longer used): //LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,225,0>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>;
using Lockup_Intense_White = LockupTrL<AlphaL<Strobe<Rgb<200,200,200>,BrownNoiseFlicker<White,Blue,300>,30,20>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<15000>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<Rgb<128,128,212>,Strobe<BrownNoiseFlicker<White,Rgb<128,128,212>,500>,Rgb<128,128,212>,15,30>,60,500>,Int<32768>>,TrFade<300>>,TrConcat<TrInstant,GreenYellow,TrSmoothFade<100>,HumpFlickerL<Rgb<220,220,235>,120>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>;
using Lockup_Intense_OrangeRed = LockupTrL<AlphaL<Strobe<Red,BrownNoiseFlicker<Moccasin,DarkOrange,300>,30,20>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<15000>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<Orange,Strobe<BrownNoiseFlicker<White,Orange,500>,Pink,15,30>,60,500>,Int<32768>>,TrFade<300>>,TrConcat<TrInstant,GreenYellow,TrSmoothFade<100>,HumpFlickerL<DarkOrange,120>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>;
using Lockup_Intense_Yellow = LockupTrL<AlphaL<Strobe<Yellow,BrownNoiseFlicker<LemonChiffon,Black,300>,30,20>,Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<15000>,Int<18000>>>>,TrConcat<TrInstant,AlphaL<Blinking<Yellow,Strobe<BrownNoiseFlicker<White,Black,500>,LemonChiffon,15,30>,60,500>,Int<32768>>,TrFade<300>>,TrConcat<TrInstant,GreenYellow,TrSmoothFade<100>,HumpFlickerL<Yellow,120>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>;

// Clashes
using Clash_Responsive_Nate = TransitionEffectL<TrConcat<TrInstant,Rgb<255,97,0>,TrDelay<35>,AlphaL<TransitionEffect<TransitionEffect<Strobe<Orange,LemonChiffon,20,20>,BrownNoiseFlicker<Rgb<255,225,0>,LemonChiffon,300>,TrInstant,TrFade<300>,EFFECT_CLASH>,LemonChiffon,TrInstant,TrDelay<150>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<27000>,Int<6000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>;
using Clash_Real_GreenYellow = TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<108,255,0>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,21610>,Int<-10000>>>>,EFFECT_CLASH>;
using Clash_Flash_White = TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_CLASH>;

// Blasts
using Blast_Mix_Orange = Layers<
  TransitionEffectL<TrConcat<TrInstant,Orange,TrDelay<35>>,EFFECT_BLAST>,
  TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,LemonChiffon>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Int<150>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,
  TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<10000>>,White,NavajoWhite>,TrFade<300>>,EFFECT_BLAST>>;
// TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,BlastL<Rgb<100,200,255>,850,250,351>,AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Rgb<70,70,255>,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,BlastL<Rgb<100,200,255>,300,350,100000>,
//TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Rgb<255,125,0>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>,AlphaL<Remap<CenterDistF<Scale<BladeAngle<>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Rgb<255,125,0>>,Mix<Int<2096>,Rgb<74,36,0>,RgbArg<BLAST_COLOR_ARG,Rgb<255,125,0>>>>>,Bump<Scale<BladeAngle<>,Int<3000>,Int<29000>>,Int<26000>>>,TrJoin<TrSmoothFade<50>,TrCenterWipeX<Int<100>,Scale<BladeAngle<>,Int<3000>,Int<29000>>>>>,EFFECT_BLAST>;
using Blast_Wave_Yellow = Layers<
  TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<35>>,EFFECT_BLAST>,
  TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,200,0>>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Int<150>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<BladeAngle<>,Int<28000>,Int<8000>>>,EFFECT_BLAST>>;
using Blast_Flash_White = TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,TrFade<300>>,EFFECT_BLAST>;
using Blast_Flash_Cyan = TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<BLAST_COLOR_ARG,Cyan>,TrFade<300>>,EFFECT_BLAST>;

// Preons
using Preon_BallDrop = TransitionEffectL<TrConcat<TrWaveX<BrownNoiseFlicker<White,Rgb<10,10,10>,400>,Percentage<WavLen<EFFECT_PREON>,150>,Int<1000>,WavLen<EFFECT_PREON>,Int<32768>>,Black,TrDelay<100>>,EFFECT_PREON>;
using Preon_Flashing_Second_White = TransitionEffectL<TrConcat<TrFadeX<Mult<Int<4096>,WavLen<EFFECT_PREON>>>,AlphaL<PulsingL<RgbArg<PREON_COLOR_ARG,White>,Int<1000>>,SmoothStep<IntArg<PREON_SIZE_ARG,5000>,Int<-5000>>>,TrDelayX<Mult<Int<28672>,WavLen<EFFECT_PREON>>>>,EFFECT_PREON>;
using Preon_Sparking_Cyan = TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<0,255,255>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<PREON_SIZE_ARG,700>,Sum<IntArg<PREON_SIZE_ARG,700>,Int<4000>>>,Int<-2000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>;
using Preon_Overload_Blue = TransitionEffectL<TrConcat<TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<30,60,200>>,10>,SmoothStep<IntArg<PREON_SIZE_ARG,700>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<30,60,200>>,15>,SmoothStep<Sum<Int<2000>,IntArg<PREON_SIZE_ARG,700>>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<30,60,200>>,20>,SmoothStep<Sum<Int<4000>,IntArg<PREON_SIZE_ARG,700>>,Int<-4000>>>,TrBoingX<Mult<Int<8192>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>;
using Preon_Emitter_Heat = TransitionEffectL<TrConcat<TrFadeX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,AlphaL<HumpFlickerL<Red,10>,SmoothStep<IntArg<PREON_SIZE_ARG,2800>,Int<-2000>>>,TrFadeX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,AlphaL<HumpFlickerL<Orange,15>,SmoothStep<IntArg<PREON_SIZE_ARG,2800>,Int<-3000>>>,TrFadeX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,AlphaL<HumpFlickerL<White,20>,SmoothStep<IntArg<PREON_SIZE_ARG,2800>,Int<-4000>>>,TrFadeX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>>,EFFECT_PREON>;
using Preon_AbsorbIn_Blue = TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<0,135,255>>,Int<200>,Int<500>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<6144>>>,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<0,135,255>>,Int<300>,Int<300>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<0,135,255>>,Int<400>,Int<100>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<12288>>>,AlphaL<RgbArg<PREON_COLOR_ARG,Rgb<0,135,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrBoingX<Mult<WavLen<EFFECT_PREON>,Int<6144>>,5>>,EFFECT_PREON>;
using Preon_AbsorbIn_Orange = TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<255,140,0>>,Int<200>,Int<500>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<6144>>>,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<255,140,0>>,Int<300>,Int<300>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,TransitionLoopL<TrSparkX<RgbArg<PREON_COLOR_ARG,Rgb<255,140,0>>,Int<400>,Int<100>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<12288>>>,AlphaL<RgbArg<PREON_COLOR_ARG,Rgb<255,140,0>>,SmoothStep<IntArg<PREON_SIZE_ARG,2000>,Int<-4000>>>,TrBoingX<Mult<WavLen<EFFECT_PREON>,Int<6144>>,5>>,EFFECT_PREON>;
using Preon_Glitch_Sound_Red = TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,100>,RandomPerLEDFlicker<RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>,RotateColorsX<Int<4000>,RgbArg<PREON_COLOR_ARG,Rgb<255,14,0>>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-450>,Int<20000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>;

// Postoffs
using Postoff_Eye_White = TransitionEffectL<TrConcat<TrCenterWipeX<Int<200>>,AlphaL<AudioFlicker<RotateColorsX<Int<200>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Int<16384>,Scale<NoisySoundLevel,Int<14000>,Int<20000>>>>,TrJoin<TrDelayX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<16384>>>,TrCenterWipeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8000>>>>,Layers<AlphaL<AudioFlicker<RotateColorsX<Int<200>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>,RotateColorsX<Int<600>,RgbArg<BASE_COLOR_ARG,Rgb<255,255,255>>>>,Bump<Int<16384>,Scale<NoisySoundLevel,Int<14000>,Int<20000>>>>,AlphaL<Black,LinearSectionF<Int<16384>,Scale<NoisySoundLevel,Int<4000>,Int<8000>>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10000>>>>,EFFECT_POSTOFF>;
using Postoff_Glitch_Audio_Red = TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AudioFlickerL<AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AudioFlickerL<AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,EFFECT_POSTOFF>;
using Postoff_Emitter_HeatFade = TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,EFFECT_POSTOFF>;
using Postoff_Emitter_Glow_Cyan = TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<POSTOFF_COLOR_ARG,Rgb<0,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,700>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>;

// Emitters
//noise uses more mem. fett: AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,
using Emitter_Orange_AudioFlicker = AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Orange>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2500>,Sum<IntArg<EMITTER_SIZE_ARG,2500>,Int<5500>>>,Int<-5500>>>;
using Emitter_Cyan_Flicker = AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Cyan>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2500>,Sum<IntArg<EMITTER_SIZE_ARG,2500>,Int<5500>>>,Int<-5500>>>;
using Emitter_Green_Flicker = AlphaL<AudioFlickerL<RgbArg<EMITTER_COLOR_ARG,Green>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2500>,Sum<IntArg<EMITTER_SIZE_ARG,2500>,Int<5500>>>,Int<-5500>>>;
using Emitter_BloodOrange_Normal = AlphaL<Rgb<255,28,0>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<5500>>,Int<-5500>>>;
using Emitter_Black_Wick = AlphaL<Black,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1750>,Int<2250>>,Int<-2500>>>;
using Emitter_White_Wick = AlphaL<Rgb<85,85,200>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1750>,Int<2250>>,Int<-2500>>>;
using Emitter_White_Unstable = AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,187,108>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>;

// Ignitions
using Ignition_WhiteBlue_Flicker = TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<DeepSkyBlue>,TrFade<1200>>,EFFECT_IGNITION>;
using Ignition_WhiteBlue_Flicker_Half = TransitionEffectL<TrConcat<TrInstant,AlphaL<AudioFlicker<White,DodgerBlue>,SmoothStep<Int<12000>,Int<-32768>>>,TrFade<1200>>,EFFECT_IGNITION>;
using Ignition_Orange_Flicker = TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Orange>>,TrFade<1200>>,EFFECT_IGNITION>;
using Ignition_Green_Flicker = TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Green>>,TrFade<1200>>,EFFECT_IGNITION>;
using Ignition_White_Flicker = TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<White>,TrFade<1200>>,EFFECT_IGNITION>;
using Ignition_Red_Unstable = TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<250>>,TrInstant>,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,155,155>>>>>,TrFade<600>>,EFFECT_IGNITION>;
using Ignition_Blue_Stripe = TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<250>>,TrInstant>,Stripes<7000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<10,52,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<10,52,255>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<10,52,255>>>>,TrFade<470>>,EFFECT_IGNITION>;

// Stabs
using Stab_White = TransitionEffectL<TrConcat<TrJoin<TrDelayX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<LemonChiffon>,SmoothStep<IntArg<MELT_SIZE_ARG,27000>,Int<9000>>>,TrWipe<200>>,EFFECT_STAB>;
using Stab_DarkOrange = TransitionEffectL<TrConcat<TrJoin<TrDelayX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<OrangeRed>,SmoothStep<IntArg<MELT_SIZE_ARG,27000>,Int<9000>>>,TrWipe<200>>,EFFECT_STAB>;
using Stab_Orange = TransitionEffectL<TrConcat<TrJoin<TrDelayX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<Orange>,SmoothStep<IntArg<MELT_SIZE_ARG,27000>,Int<9000>>>,TrWipe<200>>,EFFECT_STAB>;
using Stab_Fire = TransitionEffectL<TrConcat<TrJoin<TrDelayX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeIn<200>>,AlphaL<Remap<InvertF<RampF>,StaticFire<RgbArg<BASE_COLOR_ARG,DarkOrange>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Orange>>,0,5,0,3000,15>>,SmoothStep<Int<27000>,Int<20000>>>,TrFade<200>>,EFFECT_STAB>;//TransitionEffectL<TrConcat<TrJoin<TrDelayX<Percentage<WavLen<EFFECT_STAB>,90>>,TrWipeIn<200>>,AlphaL<Stripes<5000,1200,DarkOrange,Orange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<27000>,Int<20000>>>,TrFade<200>>,EFFECT_STAB>;

//Swing brights
using Swing_Heat = AlphaL<Mix<SwingSpeed<800>,Red,Orange,White>,Scale<SwingSpeed<700>,Int<0>,Int<32768>>>;
using Swing_Red = AlphaL<Red,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>;
using Swing_Audio_Red = AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,85,85>>>,Scale<IsLessThan<SwingSpeed<700>,Int<13600>>,Scale<SwingSpeed<700>,Int<-19300>,Int<32768>>,Int<0>>>;
using Swing_Audio_White = AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,Scale<IsLessThan<SwingSpeed<700>,Int<13600>>,Scale<SwingSpeed<700>,Int<-19300>,Int<32768>>,Int<0>>>;
using Swing_Audio_Green = AlphaL<AudioFlickerL<Green>,Scale<SwingSpeed<600>,Int<0>,Int<32768>>>;
using Swing_Audio_Blue = AlphaL<AudioFlickerL<DeepSkyBlue>,Scale<IsLessThan<SwingSpeed<250>,Int<13600>>,Scale<SwingSpeed<250>,Int<-19300>,Int<32768>>,Int<0>>>;
using Swing_Stripes_WhiteBlue = AlphaL<Stripes<5000,-5000,HumpFlicker<Rgb<0,0,100>,White,120>,Black>,SwingSpeed<500>>;

//Misc transitions
using Misc_WipeRandom_Blue = TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<1000>>,Int<300>,Int<3000>>>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Cyan>,Int<0>>,TrSparkX<RgbArg<EMITTER_COLOR_ARG,Cyan>,Scale<NoisySoundLevel,Int<200>,Int<600>>,Int<250>,Int<0>>>>;
using Force_Flicker = TransitionEffectL<TrConcat<TrSmoothFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>,Strobe<Black,Rgb<60,20,0>,30,30>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,60>>,StaticFire<DarkOrange,Strobe<Black,Cyan,30,30>,0,3,300>,TrFadeX<Percentage<WavLen<EFFECT_FORCE>,20>>>,EFFECT_FORCE>;

// Neo Switch RGB (Sabertrio Power Core)
using Switch_Red = Red;
using Switch_Green = Green;
using Switch_Blue = Blue;
using Switch_White = White;
using Switch_Orange = DarkOrange;
using Switch_RGB_Swing = Layers<RotateColorsX<IncrementF<SwingSpeed<100>,Int<16384>,Int<32768>,Scale<SwingSpeed<100>,Int<0>,Int<8000>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>;
using Switch_Yellow = Yellow;
using Switch_Magenta = Magenta;
using Switch_Rainbow = RotateColorsX<Saw<Int<7>>,RgbArg<BASE_COLOR_ARG,Red>>;

/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/


// Nosloppy style: https://pastebin.com/Dn9VQkSp
// Visual: https://www.youtube.com/watch?v=1M6fM5XNVCw
using Style_Bilari_ElectroChain = Layers<
  RotateColorsX<Variation,AudioFlicker<BrownNoiseFlicker<Red,Black,1000>,Red>>,
  Mix<LayerFunctions<LinearSectionF<Int<4000>,Int<1000>>,LinearSectionF<Int<9000>,Int<1000>>,LinearSectionF<Int<14000>,Int<1000>>,LinearSectionF<Int<19000>,Int<1000>>,LinearSectionF<Int<24000>,Int<1000>>,LinearSectionF<Int<29000>,Int<1000>>,LinearSectionF<Int<34000>,Int<1000>>>,Black,
  Layers<
    Force_Flicker,
    Clash_Responsive_Nate,
    Blast_Mix_Orange,
    //TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<5000>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    Lockup_Intense_White,
    //LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<23000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
    Drag_White_Long,
    Lockup_Intense_White,
    Lightning_BrightBlue,
    Melt_Intense,
    Stab_Fire,
    Ignition_White_Flicker,
    InOutTrL<TrInstant,TrConcat<TrFadeX<RetractionTime<0>>,HumpFlickerL<White,50>,TrInstant>>>>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;


/*===============================*/
/*==== Style_PhenomChristmas ====*/
/*===============================*/
using Style_PhenomChristmas = Layers<
  //Pulsing lights (fett)
  //StripesX<Int<600>,Int<-1200>,Black,Pulsing<Black,ColorSequence<1000,Red,Blue,Orange,Magenta,Green>,1000>,Black>,
  StripesX<Int<600>,Int<-1200>,Black,Pulsing<Black,RotateColorsX<IncrementF<SwingSpeed<100>,Int<16384>,Int<32768>,Scale<SwingSpeed<100>,Int<0>,Int<8000>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,1000>,Black>,
  Blast_Wave_Yellow,
  Clash_Responsive_Nate,
  Lockup_Intense_Yellow,
  Lightning_Purple,
  Drag_White_Fire,
  Stab_DarkOrange,
  Melt_Intense,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeX<RetractionTime<2850>>,Black>,
  TransitionEffectL<TrConcat<TrWaveX<RotateColorsX<Variation,Blue>,Int<200>,Int<300>,Int<200>,Int<0>>,Mix<SmoothStep<Int<27500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Blue,DodgerBlue,200>>>,TrWaveX<RotateColorsX<Variation,Blue>,Int<175>,Int<300>,Int<175>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Blue,DodgerBlue,200>>>,TrWaveX<RotateColorsX<Variation,Blue>,Int<150>,Int<300>,Int<150>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Blue,Red,200>>>,TrWaveX<RotateColorsX<Variation,Blue>,Int<150>,Int<300>,Int<150>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<DeepSkyBlue,Blue,200>>>,TrWaveX<RotateColorsX<Variation,Blue>,Int<100>,Int<300>,Int<100>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Blue,DodgerBlue,200>>>,TrDelay<100>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Blue,Red,200>>>,TrWipe<100>,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Blue,Rgb<60,15,0>,200>>>,TrFade<100>,White,TrInstant>,EFFECT_PREON>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*===============================*/


/*============================*/
/*==== Style_Rainbow_Fire ====*/
/*============================*/
using Style_Rainbow_Fire = Layers<
  StaticFire<RotateColorsX<Saw<Int<7>>,Gradient<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RotateColorsX<Int<-4000>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RotateColorsX<Int<-8000>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,Mix<Int<10280>,Black,RotateColorsX<Saw<Int<7>>,Gradient<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RotateColorsX<Int<-4000>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RotateColorsX<Int<-8000>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>>,0,3,100,2000,16>,
  //StyleFire<Stripes<30000,-80,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Mix<Int<16384>,Black,Stripes<30000,-80,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,0,4>,
  //Stripes<30000,-300,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,
  Blast_Flash_White,
  Clash_Flash_White,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Force_Flicker,
  Melt_Intense,
  Stab_White,
  Postoff_Emitter_HeatFade,
  InOutTrL<TrWipeX<IgnitionTime<400>>,TrWipeX<RetractionTime<1100>>,Black>,
  // InOutTrL<TrWipeX<IgnitionTime<300>>,TrSelect<Scale<IsLessThan<BladeAngle<>,Int<18384>>,Int<0>,Int<1>>,TrWipeInX<Scale<BladeAngle<>,Int<2000>,Int<100>>>,TrWipeX<Scale<BladeAngle<>,Int<100>,Int<2000>>>>,Black>,
  Preon_BallDrop,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*============================*/


/*==================================*/
/*==== Style_PhenomElectroStaff ====*/
/*==================================*/
using Style_PhenomElectroStaff = Layers<
  RotateColorsX<Variation,BrownNoiseFlicker<BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<2,72,255>>,Black,300>,Stripes<3000,-4000,Rgb<50,50,75>,Rgb<100,100,150>,Rgb<10,10,15>,Rgb<150,150,225>>,200>>,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<2,72,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
  Swing_Stripes_WhiteBlue,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_OrangeRed,
  Lightning_White,
  Drag_White_Long,
  Force_Flicker,
  Stab_Fire,
  Melt_Intense,
  InOutTrL<TrColorCycleX<Percentage<IgnitionTime<0>,90>,10000,10000>,TrColorCycleX<RetractionTime<>,6000,5000>>,
  Preon_Sparking_Cyan,
  Postoff_Emitter_Glow_Cyan,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*==================================*/


/*=================================*/
/*====== Style_PhenomStarTrek ======*/
/*=================================*/
using Style_PhenomStarTrek = Layers<
  Mix<SmoothStep<Int<16384>,Int<6425>>,Remap<InvertF<RampF>,Stripes<2600,-1800,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<4000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>>,Stripes<2600,-1600,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<4000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<0,0,255>>>>>,
  TransitionEffectL<TrConcat<TrJoin<TrDelay<3900>,TrFade<300>>,StripesX<Int<3500>,Scale<SlowNoise<Int<3000>>,Int<-2500>,Int<-3500>>,RgbArg<SWING_COLOR_ARG,Rgb<85,85,200>>,Mix<Int<10280>,Black,RgbArg<SWING_COLOR_ARG,Rgb<85,85,200>>>,RandomPerLEDFlicker<Mix<Int<2570>,Black,RgbArg<SWING_COLOR_ARG,Rgb<85,85,200>>>,RgbArg<SWING_COLOR_ARG,Rgb<85,85,200>>>>,TrFade<400>>,EFFECT_FORCE>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Remap<CenterDistF<>,Stripes<2600,-2800,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<500>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<5000,-2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,0,0>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<BLAST_COLOR_ARG,Red>,Bump<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>,Int<6000>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Remap<CenterDistF<Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>,Stripes<1600,-2000,RgbArg<BLAST_COLOR_ARG,Red>,Mix<Int<2096>,Black,RgbArg<BLAST_COLOR_ARG,Red>>>>,TrCenterWipeX<Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<3000>,Int<29000>>>>,EFFECT_BLAST>,
  Clash_Responsive_Nate,
  Stab_White,
  Lockup_Intense_OrangeRed,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  InOutTrL<TrJoinR<TrCenterWipeX<IgnitionTime<300>,Int<16384>>,TrSmoothFadeX<IgnitionTime<300>>>,TrCenterWipeX<RetractionTime<0>,Int<16384>>,Black>,
  Preon_Overload_Blue,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>,TrCenterWipeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>>,Remap<CenterDistF<>,Stripes<2000,-1500,Black,Rgb<255,14,0>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>,Remap<CenterDistF<>,Stripes<1000,-500,Black,Rgb<255,14,0>,Black>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<8192>>>>,EFFECT_POSTOFF>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*==================================*/

/*--------------------------------- Style_PhenomTragedySenate-------------------------
based off eyeballing https://www.reddit.com/r/lightsabers/comments/fqh6ef/free_font_senate_majority_sidious_inspired/
OS6.7 v4.020
*/
using Style_PhenomTragedySenate = Layers<
  RandomFlicker<Stripes<24000,-1400,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<11565>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,
  //AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,20,0>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,1700>,Int<-6000>>>,
  // Whiteish Rage swing flicker
  Swing_Audio_Red,
  TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,40>,TrFade<1200>>,EFFECT_IGNITION>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<800>>,EFFECT_RETRACTION>,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_Fire,
  InOutTrL<TrConcat<TrWipeInX<Mult<IgnitionTime<480>,Int<6553>>>,RandomBlink<30000,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,Black>,TrJoin<TrDelayX<Mult<IgnitionTime<480>,Int<19660>>>,TrWipeInX<Mult<IgnitionTime<230>,Int<6553>>>>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,IntArg<EMITTER_SIZE_ARG,1500>,Sum<Int<5000>,IntArg<EMITTER_SIZE_ARG,1000>>>,Int<-3000>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<IgnitionTime<480>,Int<19660>>>>,TrColorCycleX<RetractionTime<600>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_PhenomCrispyPinkFlicker-------------------------
*/
using Style_PhenomCrispyPinkFlicker = Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<220,0,200>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<220,0,200>>>>,
  Emitter_Cyan_Flicker,
  Swing_Audio_Blue,
  Ignition_WhiteBlue_Flicker,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<191,255,255>>,IgnitionTime<150>>,TrColorCycleX<RetractionTime<0>,1500,7500>,Black>,
  Preon_AbsorbIn_Blue,
  TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<POSTOFF_COLOR_ARG,Rgb<118,0,194>>,SmoothStep<IntArg<PREON_SIZE_ARG,2800>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_PhenomSparkleOff-------------------------
Made to replicate the CFX effect here:
https://www.youtube.com/watch?v=GcZVxD_0w9U
*/
using Style_PhenomSparkleOff = Layers<
  RotateColorsX<Variation,AudioFlicker<GreenYellow,HumpFlicker<RgbArg<BASE_COLOR_ARG,Orange>,RgbArg<ALT_COLOR_ARG,Rgb<180,130,0>>,30>>>,
  Ignition_WhiteBlue_Flicker_Half,
  TransitionEffectL<TrConcat<TrFadeX<WavLen<EFFECT_RETRACTION>>,AudioFlicker<Red,Rgb<128,0,0>>,TrDelay<500>>,EFFECT_RETRACTION>,
  Blast_Mix_Orange,
  Clash_Flash_White,
  Lockup_Intense_OrangeRed,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_DarkOrange,
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
using Style_BanishedPurpleOverload = Layers<
  StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<95,0,210>>>,0,5,0,3000,15>,
  Swing_Heat,
  Blast_Mix_Orange,
  Clash_Real_GreenYellow,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<1138>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,RetractionTime<1049>>,Black>,
  Preon_Emitter_Heat,
  Postoff_Glitch_Audio_Red,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_UnstableRage -------------------------
copyright Fett263 CustomBlade (Primary Blade) OS6 Style
OS6.7 v4.020
*/
using Style_UnstableRage = Layers<
  Stripes<3000,-3500,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Black>,BrownNoiseFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<3855>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,200>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<3855>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,
  Ignition_Red_Unstable,
  Emitter_BloodOrange_Normal,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeX<IgnitionTime<250>>,TrWipeInX<RetractionTime<500>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- EnginesBurn------------------------------*/
/* OS6.7 v4.019
*/
using Style_EnginesBurn = Layers<
  StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<152,130,61>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<152,130,61>>>,0,5,0,3000,5>,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<600>>,TrInstant>,Stripes<3000,-3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<152,130,61>>>>>,TrFade<800>>,EFFECT_RETRACTION>,
  Emitter_Cyan_Flicker,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrConcat<TrFadeX<RetractionTime<600>>,White,TrFadeX<RetractionTime<600>>,DarkOrange,TrFadeX<RetractionTime<600>>,Red,TrFadeX<RetractionTime<600>>>,Black>,
  Preon_Emitter_Heat,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- GreyscaleEndureRageCustom-------------------------
OS6.7 v4.019
*/
using GreyscaleEndureRageCustom = Layers<
  StaticFire<RgbArg<BASE_COLOR_ARG,Red>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Red>>,0,5,0,1500,5>,
  Emitter_Orange_AudioFlicker,
  TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,Stripes<3000,-3500,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>>,Black>,BrownNoiseFlicker<RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,97,0>>>>>,TrFade<800>>,EFFECT_IGNITION>,
  Swing_Heat,
  Clash_Responsive_Nate,
  Blast_Mix_Orange,
  Lockup_Intense_White,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInSparkTipX<RgbArg<RETRACTION_COLOR_ARG,White>,RetractionTime<1550>>,Black>,
  Preon_Glitch_Sound_Red,
  //POSTOFF fizzle cooldown
  Postoff_Glitch_Audio_Red,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- GreyscaleBinaryDark-------------------------
Phenom custom remake from official style
OS6.7 v4.020
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
  Swing_Audio_White,
  Blast_Mix_Orange,
  Clash_Flash_White,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<1500>>,TrColorCycleX<RetractionTime<500>>,Black>,
  // Prespark from OG Bindark modded
  TransitionEffectL<TrConcat<TrDelay<500>,RgbArg<PREON_COLOR_ARG,Black>,TrWaveX<OrangeRed,Int<750>,Int<175>,Int<1575>,Int<-3000>>,Black,TrInstant,AlphaL<AudioFlickerL<OrangeRed>,Bump<Int<12000>,Int<11500>>>,TrDelay<150>>,EFFECT_PREON>,
  // Endure preon edit
  Preon_Glitch_Sound_Red,
  // Post off
  TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,Rgb<255,0,0>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<1500>>,Int<2000>,Int<4500>>,Int<-4000>>>,TrDelayX<RetractionTime<0>>,Black,TrDelay<897>,AlphaL<RandomPerLEDFlicker<RgbArg<POSTOFF_COLOR_ARG,Rgb<255,0,0>>,Black>,Bump<Int<12000>,Int<11500>>>,TrDelay<150>>,EFFECT_RETRACTION>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_GreenSwingOrange-------------------------
Custom with base of Path Engine by meatynubs

*/
using Style_GreenSwingOrange = Layers<
  Mix<Int<16237>,StaticFire<RgbArg<BASE_COLOR_ARG,Orange>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Orange>>,0,3,0,2000,4>,StripesX<Int<6000>,Scale<SlowNoise<Int<2000>>,Int<-1600>,Int<-3200>>,RgbArg<ALT_COLOR_ARG,Rgb<80,50,210>>,RandomPerLEDFlicker<Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<80,50,210>>>,Mix<Int<1285>,Black,RgbArg<ALT_COLOR_ARG,Rgb<80,50,210>>>>,BrownNoiseFlicker<Mix<Int<1285>,Black,RgbArg<ALT_COLOR_ARG,Rgb<80,50,210>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR_ARG,Rgb<80,50,210>>>,300>,RgbArg<ALT_COLOR_ARG,Rgb<80,50,210>>,RandomPerLEDFlicker<Black,Mix<Int<16384>,Black,RgbArg<ALT_COLOR_ARG,Rgb<80,50,210>>>>,RgbArg<ALT_COLOR_ARG,Rgb<80,50,210>>>>,
  Swing_Audio_Green,
  Ignition_Green_Flicker,
  Blast_Flash_Cyan,
  Clash_Real_GreenYellow,
  Misc_WipeRandom_Blue,
  Lockup_Intense_Yellow,
  Lightning_BrightBlue,
  Drag_Orange_Fire,
  Stab_DarkOrange,
  Melt_Intense,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Green>,IgnitionTime<300>>,TrColorCycleX<RetractionTime<0>,950,7500>,Black>,
  Preon_AbsorbIn_Orange,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_GreenBlueAudioFlicker-------------------------
Pong Krell The Clone Wars
*/
using Style_GreenBlueAudioFlicker = Layers<
  RotateColorsX<Variation,AudioFlicker<RotateColorsX<Variation,Rgb16<23829,65535,1514>>,RotateColorsX<Variation,Rgb16<4702,5401,65535>>>>,
  Swing_Audio_White,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  Ignition_WhiteBlue_Flicker_Half,
  InOutTrL<TrWipeSparkTipX<White,IgnitionTime<200>,Int<100>>,TrWipeInX<RetractionTime<0>>,Black>,
  Preon_Overload_Blue,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_TripleLightsideFlicker-------------------------
Blue/Aquamarine/Purple AudioFlicker
*/
// using Style_TripleLightsideFlicker = 
// Layers<
//   AudioFlicker<RotateColorsX<Variation,Rgb<0,0,255>>,AudioFlicker<RotateColorsX<Variation,Rgb<0,255,0>>,Rgb<189,8,255>>>,
//   //AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,White>>,SwingSpeed<600>>, 
//   //AlphaL<AudioFlickerL<RgbArg<SWING_COLOR_ARG,Rgb<255,255,255>>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
//   Blast_Mix_Orange,
//   Clash_Responsive_Nate,
//   Lockup_Intense_White,
//   Lightning_White,
//   Drag_White_Fire,
//   Melt_Intense,
//   Stab_White,
//   TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RgbArg<IGNITION_COLOR_ARG,Rgb<198,49,255>>>,TrFade<1200>>,EFFECT_IGNITION>,
//   InOutTrL<TrWipeSparkTipX<RandomFlicker<White,RgbArg<IGNITION_COLOR_ARG,Rgb<255,190,255>>>,IgnitionTime<200>,Int<100>>,TrWipeInX<RetractionTime<500>>,Black>,
//   Preon_Glitch_Sound_Red,
//   AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------- Style_DarksaberLive-------------------------
*/
using Style_DarksaberLive = Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<250,248,255>>,Mix<Int<21610>,Black,RgbArg<BASE_COLOR_ARG,Rgb<250,248,255>>>>,
  Blast_Wave_Yellow,
  Clash_Responsive_Nate,
  Lockup_Intense_Yellow,
  Lightning_BrightBlue,
  Drag_Orange_Fire,
  Melt_Intense,
  Stab_Fire,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<500>>,TrWipeInX<RetractionTime<0>>,Black>,
  AllStyles_BatteryLevel,
  AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*---------------------------- Style_Original_BlueRotoscope----------------------
Based on Star Wars: Episode IV - A New Hope / with swing bright
Rgb<10,95,255> Custom DodgerBlue
b0111 28672 and b0110 24576 for the stripe audioflicker since i like subtle
*/
using Style_Original_BlueRotoscope = Layers<
  AudioFlicker<Stripes<14000,-4000,RgbArg<BASE_COLOR_ARG,Rgb<5,39,255>>,RgbArg<BASE_COLOR_ARG,Rgb<5,39,255>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<5,39,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<5,39,255>>,Mix<Int<28672>,Black,RgbArg<BASE_COLOR_ARG,Rgb<5,39,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<5,39,255>>>,
  AlphaL<RgbArg<SWING_COLOR_ARG,Rgb<125,125,255>>,SwingSpeed<1000>>,
  Emitter_White_Wick,
  Ignition_Blue_Stripe,
  Blast_Flash_White,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeX<IgnitionTime<250>>,TrWipeInX<RetractionTime<0>>,Black>,
  Preon_Sparking_Cyan,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/
/* All the following styles use this template:
OS6.7 v4.019
*/

/*
Luke/Ani/Ahsoka
*/
using Style_BlueHumpFlicker = Layers<
  HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,120>,
  Ignition_WhiteBlue_Flicker,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<195,195,255>>,IgnitionTime<300>,Int<300>>,TrWipeInSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<64,64,255>>,RetractionTime<0>,Int<1000>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*
Temple Guardian
*/
using Style_YellowHumpFlicker = Layers<
  HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<200,180,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<200,180,0>>>,120>,
  Ignition_White_Flicker,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,195>>,IgnitionTime<300>,Int<300>>,TrWipeInSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,64>>,RetractionTime<0>,Int<1000>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*
C1-10P
*/
using Style_OrangeHumpFlicker = Layers<
  HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,97,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,97,0>>>,120>,
  Ignition_White_Flicker,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,195>>,IgnitionTime<300>,Int<300>>,TrWipeInSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,64>>,RetractionTime<0>,Int<1000>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*
Mace Rgb<198,49,255> (AOTC) - Rgb<173,13,255> (ROTS)
*/
using Style_PurpleHumpFlicker = Layers<
  HumpFlicker<RgbArg<BASE_COLOR_ARG,Magenta>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Magenta>>,120>,
  Ignition_White_Flicker,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,195,255>>,IgnitionTime<300>,Int<300>>,TrWipeInSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,64,255>>,RetractionTime<0>,Int<1000>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*
Quigon
*/
using Style_GreenHumpFlicker = Layers<
  HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,120>,
  Ignition_White_Flicker,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<195,255,195>>,IgnitionTime<300>,Int<300>>,TrWipeInSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<64,255,64>>,RetractionTime<0>,Int<1000>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*
Slightly different to other standards, white tip on, audioflicker orange ignition
*/
using Style_RedHumpFlicker = Layers<
  HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,120>,
  Ignition_Orange_Flicker,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,195,195>>,IgnitionTime<300>,Int<300>>,TrWipeInSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,64,64>>,RetractionTime<0>,Int<1000>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

using Style_RedAngryAudio = Layers<
  AudioFlicker<Stripes<10000,-4000,Red,Red,BrownNoiseFlicker<Red,Mix<Int<16448>,Black,Red>,200>,Red,BrownNoiseFlicker<Red,Mix<Int<7710>,Black,Red>,200>>,Red>,
  Ignition_Orange_Flicker,
  //Swing_Red,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_White,
  Lightning_BrightBlue,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,195,195>>,IgnitionTime<300>,Int<300>>,TrWipeInSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,64,64>>,RetractionTime<0>,Int<1000>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;

/*--------------------------------- Style_DarkBloodOrangeHumpFlicker-------------------------
//Nates DarkBloodOrangeCustomHumpFlickerBladestyle https://pastebin.com/XTPLnpy3
*/
using Style_DarkBloodOrangeHumpFlicker = Layers<
  HumpFlicker<Rgb<191,21,0>,AudioFlicker<Mix<Int<8192>,Black,RgbArg<BASE_COLOR_ARG,Rgb<191,21,0>>>,Rgb<191,21,0>>,90>,
  AlphaL<RotateColorsX<Variation,Rgb<255,28,0>>,SwingSpeed<200>>,
  Emitter_BloodOrange_Normal,
  Blast_Mix_Orange,
  Clash_Responsive_Nate,
  Lockup_Intense_Yellow,
  Lightning_White,
  Drag_White_Fire,
  Melt_Intense,
  Stab_White,
  InOutTrL<TrWipeSparkTipX<Rgb<255,28,0>,IgnitionTime<325>,Int<500>>,TrWipeInSparkTipX<Rgb<255,28,0>,RetractionTime<650>,Int<1000>>,Black>,
  AllStyles_BatteryLevel, AllStyles_SaberTrioSoundLevel>;



/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
/*---------------------------------ENABLED FONTS----------------------------------*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/

// S3 PowerCore blade array
Preset blade[] = {

  // ################################################
  // ################################################
  // ##             SABERTRIO STOCK                ##
  // ################################################
  // ################################################

  { "1-SABERTRIO;common", "tracks/track1.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "sabertrio"},

  // { "2-DARK_EDITION;common", "tracks/track1.wav",
  // StylePtr<Style_RedHumpFlicker>(), StylePtr<Switch_Red>(), "dark ed"},

  { "3-THE_LIGHT;common","tracks/track_3.wav",
  StylePtr<Style_BlueHumpFlicker>(), StylePtr<Switch_Blue>(), "the light"},

  { "4-THE_BALANCE;common","tracks/track_4.wav",
  StylePtr<Style_GreenHumpFlicker>(), StylePtr<Switch_Green>(), "the bal"},

  { "5-THE_DARK;common","tracks/track_5.wav",
  StylePtr<Style_RedHumpFlicker>(), StylePtr<Switch_Red>(), "the dark"},

  // { "6-VENGEANCE;common", "tracks/track1.wav",
  // StylePtr<Style_DarkBloodOrangeHumpFlicker>(),StylePtr<WHITE>(), "vengeance"},

  // { "8-SNIPPETS;common", "tracks/track_8.wav",
  // StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "snippets"},

  // { "9-MENACE;common", "tracks/track_9.wav",
  // StylePtr<Style_RedHumpFlicker>(), StylePtr<Switch_Red>(), "menace"},

  // { "10-TEMPLE_GUARDIAN;common", "tracks/track_10.wav",
  // StylePtr<Style_YellowHumpFlicker>(), StylePtr<WHITE>(), "templ guard"},

  { "11-SHOCK_BATON;common", "tracks/track_11.wav",
  StylePtr<Style_PhenomElectroStaff>(), StylePtr<Switch_Blue>(), "shockbaton"},

  // { "12-THE_TRAGEDY;common", "tracks/track_12.wav",
  // StylePtr<Style_PhenomTragedySenate>(), StylePtr<WHITE>(), "The Tragedy"},

  // ####################################
  // ####################################
  // ##             OTHERS             ##
  // ####################################
  // ####################################

  // BlueMamba (Etsy) - DC Deathstroke (authored with Semz Nerd)
  { "BMMercenary;common", "tracks/hallway.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "bm merc"},

  // Syndicate Custom Relics - Retribution (electroblade)
  // { "SCRRetribution;common", "tracks/combat1.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_White>(), "scr retrib"},

  // Mongo https://www.youtube.com/watch?v=TieX5N51b5I
  { "MongoDuneV2;common", "tracks/dune.wav",
  StylePtr<Style_PhenomElectroStaff>(), StylePtr<Switch_White>(), "mongo dune"},

  // Cosmic Ape - Dreamhunter (paid)
  // { "CADreamhunter;common", "tracks/track1.wav",
  // StylePtr<Style_GreenSwingOrange>(), StylePtr<Switch_Green>(), "ca dh"},

  // Epiphany - Epic (MUSIC BASED)
  { "MusicEpic;common", "tracks/track1.wav",
  StylePtr<Style_Rainbow_Fire>(), StylePtr<Switch_Rainbow>(), "music epic"},


  // ################################################
  // ################################################
  // ##   github Ferase JediSurvivor-Soundfonts    ##
  // ################################################
  // ################################################

  // Jedi Survivor - Bode
  { "SWJSBodeAkuna;common", "tracks/hallway.wav",
  StylePtr<Style_RedAngryAudio>(), StylePtr<Switch_Red>(), "swjs bodeakuna"},

  // Jedi Survivor - Cal Kestis Green
  { "SWJSCalGreen;common", "tracks/hallway.wav",
  StylePtr<Style_GreenHumpFlicker>(), StylePtr<Switch_Green>(), "swjs calgreen"},

  // Jedi Survivor - Cal Kestis Yellow
  { "SWJSCalYellow;common", "tracks/hallway.wav",
  StylePtr<Style_YellowHumpFlicker>(), StylePtr<Switch_Yellow>(), "swjs calyellow"},

  // Jedi Survivor - Cal Kestis Blue
  // { "SWJSCalBlue;common", "tracks/hallway.wav",
  // StylePtr<Style_BlueHumpFlicker>(), StylePtr<WHITE>(), "swjs calblue"},

  // // Jedi Survivor - Cal Kestis Magenta
  // { "SWJSCalMagenta;common", "tracks/hallway.wav",
  // StylePtr<Style_PurpleHumpFlicker>(), StylePtr<WHITE>(), "swjs calmag"},

  // Jedi Survivor - Dagan Gera Light
  { "SWJSDaganLight;common", "tracks/hallway.wav",
  StylePtr<Style_OrangeHumpFlicker>(), StylePtr<Switch_Orange>(), "swjs dagan lite"},

  // Jedi Survivor - Dagan Gera Dark
  // { "SWJSDaganDark;common", "tracks/hallway.wav",
  // StylePtr<Style_RedAngryAudio>(), StylePtr<Switch_Red>(), "swjs dagan dark"},

  // Jedi Survivor - Rick the Door Technician
  { "SWJSRick;common", "tracks/hallway.wav",
  StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_Blue>(), "swjs rick"},

  // Jedi Survivor - Ninth Sister
  { "SWJSNinthSister;common", "tracks/hallway.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "swjs ninth"},

  // Jedi Survivor - Darth Vader
  // { "SWJSDarthVader;common", "tracks/hallway.wav",
  // StylePtr<Style_RedAngryAudio>(), StylePtr<WHITE>(), "swjs darth"},


  // ################################################
  // ################################################
  // ##                   KSith                    ##
  // ################################################
  // ################################################

  // Rogue One Vader Ending
  { "KSithRogue;common", "tracks/hallway.wav",
  StylePtr<Style_RedHumpFlicker>(), StylePtr<Switch_Red>(), "ks roguevader"},

  // Obi-Wan S1 Vader Finale
  { "KSithWhatRemains;common", "tracks/vaderobi_dialogue.wav",
  StylePtr<Style_RedAngryAudio>(), StylePtr<Switch_Red>(), "ks obivader"},

  // The Tales S1 - Ahsoka vs Inquisitor
  { "KSithGhost;common", "tracks/combat1.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "ks ghost"},

  // { "KSithProto;common", "tracks/combat1.wav",
  // StylePtr<Style_PhenomElectroStaff>(), StylePtr<Switch_White>(), "ks proto"},

  // Ahsoka S1 Shin Hati
  { "KSithHati;common", "tracks/woodsfight.wav",
  StylePtr<Style_DarkBloodOrangeHumpFlicker>(), StylePtr<Switch_Orange>(), "ks hati"},


  // ################################################
  // ################################################
  // ##                KYBERPHONIC                 ##
  // ################################################
  // ################################################

  // Ahsoka Season 1 ( Baylan Skoll )
  { "KPSunSkoll;common", "tracks/ahsokatheme.wav",
  StylePtr<Style_DarkBloodOrangeHumpFlicker>(), StylePtr<Switch_Orange>(), "kpsunskoll"},

  // Son of Corellia
  { "KPSonOfCorellia;common", "tracks/tfa.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "sonofcorellia"},

  // Ahsoka Season 1 - Ahsoka white
  { "KPTheSorcererV2;common", "tracks/ahsokatheme.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "kp sorcerer v2"},

  // Dark saber (live action)
  { "KPDarkV3;common", "tracks/mandotheme.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "dark saber"},

  // // Asohka white (mandalorian)
  // { "KPTheSorcererBeskar;common", "tracks/thesorcerer.wav",
  // StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "kp sorcerer"},

  // TFA Graflex v2
  // { "KPTFATakodana;common", "tracks/tfa.wav",
  // StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "tfa takodana"},

  // TFA Graflex v2
  { "KPTFAStarkiller;common", "tracks/reyvkylo.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "tfa starkill"},

  // Kylo - The Force Awakens (Kyberphonic Unstable v3)
  { "TROS;common", "tracks/reyvkylo.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "kylo TROS"},
  { "TLJ;common", "tracks/reyvkylo.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "kylo TLJ"},
  { "TFA;common", "tracks/reyvkylo.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "kylo TFA"},

  // TLJ Praetorian Guards
  // { "KPBilariWhip;common", "tracks/reyvkylo.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_Red>(), "tfa bilari"},

  // TLJ Praetorian Guards
  // { "KPVibroArbir;common", "tracks/reyvkylo.wav",
  // StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "tfa arbir"},

  // Asohka blue (clone wars)
  // { "KPCommanderTano;common", "tracks/swclonewars.wav",
  // StylePtr<Style_BlueHumpFlicker>(), StylePtr<Switch_Blue>(), "cmdr tano"},

  // Adam Project
  // { "KPAdamProjectMagCyl;common", "tracks/track_16.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_Red>(), "magcyl"},

  // TFM - F1 Racer (paid)
  { "KPFOneRacer;common", "tracks/track_13.wav",
  StylePtr<Style_EnginesBurn>(), StylePtr<Switch_Yellow>(), "podracer"},


  // ################################################
  // ################################################
  // ##                 GREYSCALE                  ##
  // ################################################
  // ################################################

  // Greyscale - Binary Dark (paid)
  { "GSBinaryDark;common", "tracks/track1.wav",
  StylePtr<GreyscaleBinaryDark>(), StylePtr<Switch_Red>(), "gs bd"},

  // Greyscale - Endure (paid)
  { "GSEndure;common", "tracks/track1.wav",
  StylePtr<GreyscaleEndureRageCustom>(), StylePtr<Switch_Red>(), "gs endure"},

  // Greyscale - Paradise V2 (paid)
  // { "GSParadise;common", "tracks/track1.wav",
  // StylePtr<Style_GreenSwingOrange>(), StylePtr<Switch_Yellow>(), "gs paradise"},

  // // Greyscale - Decay V2 (free)
  // { "GSDecay;common", "tracks/track1.wav",
  // StylePtr<Style_PurpleHumpFlicker>(), StylePtr<WHITE>(), "gs decay"},

  // Greyscale - Crispy (free)
  { "GSCrispity;common", "tracks/track1.wav",
  StylePtr<Style_PhenomCrispyPinkFlicker>(), StylePtr<Switch_Magenta>(), "gs crispy"},

  // Greyscale - Coda (free)
  // { "GSCoda;common", "tracks/track1.wav",
  // StylePtr<Style_PhenomSparkleOff>(), StylePtr<Switch_Green>(), "gs coda"},

  // Greyscale - Deadlink (free)
  // { "GSDeadlink;common", "tracks/track1.wav",
  // StylePtr<Style_PhenomSparkleOff>(), StylePtr<WHITE>(), "gs deadlink"},

  // Greyscale - Apocalypse (free)
  // { "GSApocalypse;common", "tracks/track1.wav",
  // StylePtr<Style_GreenBlueAudioFlicker>(), StylePtr<Switch_Yellow>(), "gs apocalypse"},

  // Greyscale - Mercenary (free)
  { "GSMercenary;common", "tracks/track1.wav",
  StylePtr<Style_GreenSwingOrange>(), StylePtr<Switch_Orange>(), "gs mercenary"},


  // ###########################################
  // ##  Meaty  ##
  // ###########################################

  // https://www.youtube.com/shorts/YZBsMuEkjx4
  // { "MeatyC110P;common", "tracks/swrebelstheme.wav",
  // StylePtr<Style_OrangeHumpFlicker>(), StylePtr<Switch_Orange>(), "meaty c110p"},

  // https://www.youtube.com/shorts/YZBsMuEkjx4
  // { "MeatyDomo;common", "tracks/MrRoboto.wav", //Killroy
  // StylePtr<Style_GreenSwingOrange>(), StylePtr<Switch_Blue>(), "meaty domo"},

  // https://www.youtube.com/watch?v=c3NMZTPvBTE
  { "MeatyStarTrek;common", "tracks/sttngtheme.wav",
  StylePtr<Style_PhenomStarTrek>(), StylePtr<Switch_Blue>(), "meaty trek"},

  // Christmas V2 10/16/22
  // { "MeatyChristmas;common", "tracks/christmas_sesame1.wav",
  // StylePtr<Style_PhenomChristmas>(), StylePtr<Switch_RGB_Swing>(), "meaty christ"},


  // ###########################################
  // ## Jaydalorian ##
  // ###########################################

  // Jaydalorian Christmas (free)
  // { "JDChristmas;common", "tracks/christmas.wav",
  // StylePtr<Style_PhenomChristmas>(), StylePtr<Switch_RGB_Swing>(), "jd christmas"},

  // Jaydalorian New years (free)
  // { "JDNewyears;common", "tracks/newyearcantina.wav",
  // StylePtr<Style_Rainbow_Fire>(), StylePtr<Switch_Rainbow>(), "jd newyear"},

  // Jaydalorian Banished (paid)
  { "JDBanished;common", "tracks/track1.wav",
  StylePtr<Style_BanishedPurpleOverload>(), StylePtr<Switch_Magenta>(), "jd banish"},

  // Jaydalorian Decimate (free)
  // { "JDDecimate;common", "tracks/track1.wav",
  // StylePtr<Style_PhenomCrispyPinkFlicker>(), StylePtr<WHITE>(), "jd decimate"},


  // ###########################################
  // ## Mountain Sabers ##
  // ###########################################

  // Ball Drop - New Years (paid)
  // { "MSBallDrop;common", "tracks/newyearcantina.wav",
  // StylePtr<Style_Rainbow_Fire>(), StylePtr<Switch_Rainbow>(), "ms newyear"},

  // The Beginner (free)
  // { "MSTheBeginner;common", "tracks/sw.wav",
  // StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "ms thebeginner"},

  // Double Agent Pong Krell (paid)
  { "MSPongKrell;common", "tracks/swrebelstheme.wav",
  StylePtr<Style_GreenBlueAudioFlicker>(), StylePtr<Switch_Green>(), "ms doubleagent"},

  // Star Trek Whale probe ep 4 (paid)
  { "MSStarTrekWhaleProbe;common", "tracks/STT.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "ms st whale"},

  // Daft Punk Tribute
  // { "MSDaftPunk;common", "tracks/daftpunkaround.wav",
  // StylePtr<Style_PhenomCrispyPinkFlicker>(), StylePtr<Switch_Magenta>(), "ms daftpunk"},




  // ################################################
  // ## CFX Ripped Fonts ##
  // ################################################

  // // CFX Default - Shatterpoint (converted)
  // { "GCSShatterpoint;common", "tracks/track1.wav",
  // StylePtr<Style_PurpleHumpFlicker>(), StylePtr<WHITE>(), "gcs windu"},

  // CFX Default - Kamino (converted)
  // { "CFX-Kamino;common", "tracks/track1.wav",
  // StylePtr<
  //   Layers<
  //     // 50% audioflicker
  //     AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,19,255>>,Mix<Int<8192>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,19,255>>>>,
  //     // Rain effect
  //     SparkleL<White,250>,
  //     Blast_Mix_Orange,
  //     Clash_Responsive_Nate,
  //     Lockup_Intense_White,
  //     Lightning_BrightBlue,
  //     Drag_White_Fire,
  //     Melt_Intense,
  //     InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<500>>,Black>,
  //     //Battery & Sabertrio
  //     AllStyles_BatteryLevel,
  //     AllStyles_SaberTrioSoundLevel
  //   >
  // >(), StylePtr<Switch_Blue>(), "cfx kamino"},


  // ################################################
  // ## From Reddit ##
  // ################################################

  // { "Reddit-ARCANE;common", "tracks/track1.wav",
  // StylePtr<Style_PhenomSparkleOff>(), StylePtr<Switch_Red>(), "reddit arcane"},

  // Palpatine
  { "Reddit-Senate-Majority;common", "tracks/palpatheme.wav",
  StylePtr<Style_PhenomTragedySenate>(), StylePtr<Switch_Red>(), "reddit senatemajority"},

  // { "Reddit-Ronin;common", "tracks/track1.wav", //Not a jedi
  // StylePtr<Style_UnstableRage>(), StylePtr<WHITE>(), "reddit ronin"},

  // Portal fireblade
  { "Reddit-Portal;common", "tracks/stillalive.wav",
  StylePtr<
    Layers<
      Layers<Remap<Scale<CenterDistF<>,Int<0>,Int<65536>>,Remap<InvertF<RampF>,Mix<SmoothStep<Int<19652>,Int<13123>>,StaticFire<RgbArg<BASE_COLOR_ARG,Rgb<0,44,249>>,Mix<Int<10280>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,44,249>>>,0,2,0,3000,3>,StaticFire<RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>>,0,2,0,3000,3>>>>,AlphaL<Black,LinearSectionF<Int<16384>,Int<8171>>>>,
      Blast_Flash_White,
      Clash_Flash_White,
      Lightning_White,
      InOutTrL<TrCenterWipeInX<IgnitionTime<500>,Int<16384>>,TrCenterWipeInX<RetractionTime<500>,Int<16384>>,Black>,
      AllStyles_BatteryLevel,
      AllStyles_SaberTrioSoundLevel
    >
  >(), StylePtr<Switch_Blue>(), "geekbot9999 portal"},


  // ################################################
  // ##  Misc  ##
  // ################################################

  // Slave 1 with seismic charge preon - author NoSloppy https://pastebin.com/u/NoSloppy
  // Heavy on memory, ive removed things that cause it to bloat (but does reduce quality)
  { "SlaveOneTwoPointOne;common", "tracks/track1.wav",
  StylePtr<
    Layers<
      Mix<SmoothStep<Int<16384>,Int<4000>>,Stripes<10000,500,Rgb<0,30,80>,Rgb<0,60,180>>,Stripes<10000,-500,Rgb<0,30,80>,Rgb<0,60,180>>>,
      // Clash - 3 stage fading impact spot
      Clash_Responsive_Nate,
      // Blast
      LocalizedClashL<Blinking<White,Black,130,800>,1560,50,EFFECT_BLAST>,
      LocalizedClashL<Blinking<Red,Black,130,500>,1560,15,EFFECT_BLAST>,
      // Lockup
      Lockup_Intense_Yellow,
      // Non-Responsive Drag
      Drag_White_Fire,
      Lightning_White,
      Stab_Fire,
      Melt_Intense,
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
      //TrDelay<400>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Orange,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<6000>,Int<10000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
      TrDelay<400>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Black,White,100>,Bump<ChangeSlowly<SlowNoise<Int<30000>>,Int<60000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<300>,AlphaL<Red,Int<0>>,
      //TrDelay<300>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Yellow,Red,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<10000>,Int<28000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<200>,AlphaL<Red,Int<0>>,
      TrDelay<500>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Orange,White,100>,Bump<ChangeSlowly<SlowNoise<Int<30000>>,Int<60000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<200>,AlphaL<Red,Int<0>>,
      //TrDelay<100>,GreenYellow,TrDelay<25>,AlphaL<BrownNoiseFlicker<Red,White,100>,Bump<Scale<SlowNoise<Int<30000>>,Int<5000>,Int<13000>>,ChangeSlowly<SlowNoise<Int<30000>>,Int<20000>>>>,TrDelay<100>,AlphaL<Red,Int<0>>,
      TrDelay<500>,GreenYellow,TrDelay<25>>,EFFECT_IGNITION>,
      // Seismic Charge preon effect. use with linked preon sound
      TransitionEffectL<TrConcat<TrDelay<2125>,Cyan,TrFade<100>,Black,TrDelay<10>,Cyan,TrFade<150>
      >,EFFECT_PREON>,
      TransitionEffectL<TrConcat<TrDelay<2125>,AlphaL<White,Bump<Int<16384>,Int<32768>>>,TrFade<100>, Black,TrDelay<10>,AlphaL<White,Bump<Int<16384>,Int<32768>>>,TrFade<150>
      >,EFFECT_PREON>,
      //TransitionEffectL<TrConcat<TrDelay<2100>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<3000>>>,TrDelay<100>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<4000>>>,
      //TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<5000>>>,
      //TrSmoothFade<150>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<10000>>>,
      //TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,
      //TrSmoothFade<175>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<30000>>>,
      //TrSmoothFade<125>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<35000>>>,
      //TrSmoothFade<250>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<30000>>>,
      //TrSmoothFade<75>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,
      //TrSmoothFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<8000>>>,
      //TrSmoothFade<25>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<3000>>>,
      //TrFade<50>,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Int<16384>,Int<20000>>>,TrDelay<25>>,EFFECT_PREON>,
      // TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlicker<DeepSkyBlue,White,100>,Bump<Scale<Trigger<EFFECT_PREON,Int<2000>,Int<1000>,Int<500>>,Int<-1000>,Int<16500>>,Int<1500>>>,TrDelay<2000>>,EFFECT_PREON>,
      TransitionEffectL<TrConcat<TrDelay<1100>,AlphaL<Red,Int<0>>,TrSmoothFade<700>,Black,TrDelay<100>,AlphaL<White,Bump<Int<16384>,Int<3000>>>,TrDelay<100>>,EFFECT_PREON>,
      //Battery & Sabertrio
      AllStyles_BatteryLevel,
      AllStyles_SaberTrioSoundLevel
    >
  >(), StylePtr<Switch_Blue>(), "slave1"},

};

BladeConfig blades[] = {
  { 0,
    WS281XBladePtr<currentLedsInStrip, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    WS281XBladePtr<1, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin1> >(),
    CONFIGARRAY(blade)
  },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
