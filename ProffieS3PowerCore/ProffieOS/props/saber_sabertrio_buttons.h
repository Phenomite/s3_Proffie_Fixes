/* Sabertrio Proffie Preconfiguration 5.0
based on Fett263 Button (prop) file for use with ProffieOS7.
Includes Gesture Control, Edit Settings, Track Player

ProffieOS: Control software for lightsabers and other props.
http://fredrik.hubbe.net/lightsaber/teensy_saber.html
Copyright (c) 2016-2019 Fredrik Hubinette

Fett263 Button (prop) file, "Edit Mode", "Track Player"
Copyright (c) 2022-2023 Fernando da Rosa
Visit https://www.fett263.com/proffieOS7-fett263-prop-file.html for required set up and additional information

Voice Prompts and sounds required for certain features and should be included in /common folder or /font folder on SD card.

Track Player requires track files to be located in /font/tracks for font specific tracks or /common/tracks for universal (all presets) or a combination of the two.

---------- 2 SWITCH CONTROLS (ACTIVATION and AUXILIARY) ----------

 Ignite Blade                 - Press & release ACTIVATION SWITCH while blade is OFF.
                                NOTE: The 'no blade' sound effect will play when neither a blade nor blade plug is detected (Neo Proffie Saber only).
 Mute Mode                    - Press & hold AUXILIARY SWITCH + press & release ACTIVATION SWITCH while blade is OFF.
 Retract Blade                - Press & hold ACTIVATION SWITCH while blade is ON.
 Blaster Block Effect         - Press & release AUXILIARY SWITCH while blade is ON.
 Blade Lockup Effect          - Press & hold AUXILIARY SWITCH & strike blade while blade is ON.
 Blade Tip Drag Effect        - Press & hold AUXILIARY SWITCH and strike blade downwards while blade is ON (Neo Proffie Saber only).
 Wall Melt Effect             - Press & hold AUXILIARY SWITCH and strike blade forward while blade is ON (Neo Proffie Saber only).
 Force Effect                 - Press & hold AUXILIARY SWITCH while blade is ON.
 Force Lightning Parry Effect - Double press & hold ACTIVATION SWITCH when blade is ON (Neo Proffie Saber only).
 Kyber Dial                   - Press & hold AUXILIARY SWITCH + press & release ACTIVATION SWITCH while blade is ON.
                                    Twist rotate saber to change blade color.
                                    Press & release AUXILIARY SWITCH to select color and exit Kyber Dial.
                                    Press & release ACTIVATION SWITCH to revert to default color and exit Kyber Dial.
 Sound Bank Selection         - Press & hold AUXILIARY SWITCH while blade is OFF.
                                    Press & release AUXILIARY SWITCH while in Sound Bank Selection to cycle to the next sound font.
                                    Press & release ACTIVATION SWITCH while in Sound Bank Selection to cycle to the previous sound font.
                                    Press & Hold ACTIVATION or AUXILIARY SWITCH while in Sound Bank Selection to select a sound font.
 Settings Menu                - Press & Hold AUXILIARY SWITCH & ACTIVATION SWITCH while blade is OFF.
                                    Press & release AUXILIARY SWITCH while in Settings Menu to cycle forward to next menu option.
                                    Press & release ACTIVATION SWITCH while in Settings Menu to cycle backwards to previous menu option.
                                    Press & hold ACTIVATION SWITCH while in Settings Menu to exit.
 Setting Menu Options         - Press & hold AUXILARY SWITCH while in Settings Menu to enter a menu option.
                                    Press & release AUXILIARY SWITCH while in a menu option to increase value or enable the option.
                                    Press & release ACTIVATION SWITCH while in a menu option to decrease value or disable the option.
                                    Press & hold AUXILIARY SWITCH while in a menu option to save setting and exit the option.
                                    Press & hold ACTIVATION SWITCH while in a menu option to revert setting / cancel and exit the option.
 Battery Level Meter          - Press & release AUXILIARY SWITCH while blade is OFF.
 Quick  Gesture Toggle        - Press & hold ACTIVATION SWITCH + twist rotate the saber while blade is OFF.
 Track Player                 - Press & hold ACTIVATION SWITCH + press & release AUXILIARY SWITCH.
*/

#ifndef PROPS_SABER_SABERTRIO_BUTTONS_H
#define PROPS_SABER_SABERTRIO_BUTTONS_H

#ifndef MOTION_TIMEOUT
#define MOTION_TIMEOUT 60 * 15 * 1000
#endif

#ifndef FETT263_SWING_ON_SPEED
#define FETT263_SWING_ON_SPEED 250
#endif

#ifndef FETT263_LOCKUP_DELAY
#define FETT263_LOCKUP_DELAY 200
#endif

#ifndef FETT263_BM_CLASH_DETECT
#define FETT263_BM_CLASH_DETECT 0
#endif

#ifndef FETT263_FORCE_PUSH_LENGTH
#define FETT263_FORCE_PUSH_LENGTH 5
#endif

#ifdef FETT263_BC_SAY_BATTERY_VOLTS_PERCENT
#define FETT263_SAY_BATTERY_VOLTS
#define FETT263_SAY_BATTERY_PERCENT
#endif

#if defined(FETT263_EDIT_MODE_MENU) || defined(FETT263_EDIT_SETTINGS_MENU)
#define FETT263_USE_SETTINGS_MENU
#endif

#if NUM_BUTTONS < 1
#error /props/saber_sabertrio_buttons.h requires 2 Buttons for operation
#endif

#if defined(FETT263_HOLD_BUTTON_LOCKUP) && NUM_BUTTONS == 1
#error FETT263_HOLD_BUTTON_LOCKUP cannot be used with 1 Button Controls
#endif

#if defined(FETT263_EDIT_MODE_MENU) && !defined(ENABLE_ALL_EDIT_OPTIONS)
#error ENABLE_ALL_EDIT_OPTIONS must be defined to enable FETT263_EDIT_MODE_MENU
#endif

#if defined(FETT263_EDIT_SETTINGS_MENU) && !defined(ENABLE_ALL_EDIT_OPTIONS)
#error ENABLE_ALL_EDIT_OPTIONS must be defined to enable FETT263_EDIT_SETTINGS_MENU
#endif

#if defined(FETT263_EDIT_MODE_MENU) && defined(FETT263_EDIT_SETTINGS_MENU)
#error FETT263_EDIT_SETTINGS_MENU cannot be combined with FETT263_EDIT_MODE_MENU
#endif

#if defined(FETT263_SPIN_MODE) && defined(FETT263_SAVE_CHOREOGRAPHY)
#error FETT263_SPIN_MODE cannot be used with FETT263_SAVE_CHOREOGRAPHY
#endif

#if defined(FETT263_SPIN_MODE) && defined(FETT263_HOLD_BUTTON_LOCKUP)
#error FETT263_SPIN_MODE cannot be used with FETT263_HOLD_BUTTON_LOCKUP
#endif

#if defined(FETT263_SWING_ON) && defined(FETT263_SWING_ON_PREON)
#error You cannot define both FETT263_SWING_ON and FETT263_SWING_ON_PREON
#endif

#if defined(FETT263_TWIST_ON) && defined(FETT263_TWIST_PREON)
#error You cannot define both FETT263_TWIST_ON and FETT263_TWIST_ON_PREON
#endif

#if defined(FETT263_STAB_ON) && defined(FETT263_STAB_PREON)
#error You cannot define both FETT263_STAB_ON and FETT263_STAB_ON_PREON
#endif

#if defined(FETT263_TWIST_OFF) && defined(FETT263_TWIST_OFF_NO_POSTOFF)
#error You cannot define both FETT263_TWIST_OFF and FETT263_TWIST_OFF_NO_POSTOFF
#endif

#if defined(FETT263_FORCE_PUSH_ALWAYS_ON) && defined(FETT263_FORCE_PUSH)
#error You cannot define both FETT263_FORCE_PUSH_ALWAYS_ON and FETT263_FORCE_PUSH
#endif

#if defined(FETT263_CLASH_STRENGTH_SOUND) && !defined(FETT263_MAX_CLASH)
#define FETT263_MAX_CLASH 16
#endif

#ifdef FETT263_TWIST_OFF
#define TWIST_OFF_GESTURE
#endif

#ifdef FETT263_TWIST_OFF_NO_POSTOFF
#define TWIST_OFF_GESTURE
#endif

#ifdef FETT263_SWING_ON
#define SWING_GESTURE
#endif

#ifdef FETT263_SWING_ON_PREON
#define SWING_GESTURE
#endif

#if defined(FETT263_SWING_ON_NO_BM) && !defined(SWING_GESTURE)
#error FETT263_SWING_ON_NO_BM requires either FETT263_SWING_ON or FETT263_SWING_ON_PREON
#endif

#ifdef FETT263_STAB_ON
#define STAB_GESTURE
#endif

#ifdef FETT263_STAB_ON_PREON
#define STAB_GESTURE
#endif

#if defined(FETT263_STAB_ON_NO_BM) && !defined(STAB_GESTURE)
#error FETT263_STAB_ON_NO_BM requires either FETT263_STAB_ON or FETT263_STAB_ON_PREON
#endif

#ifdef FETT263_TWIST_ON
#define TWIST_GESTURE
#endif

#ifdef FETT263_TWIST_ON_PREON
#define TWIST_GESTURE
#endif

#if defined(FETT263_TWIST_ON_NO_BM) && !defined(TWIST_GESTURE)
#error FETT263_TWIST_ON_NO_BM requires either FETT263_TWIST_ON or FETT263_TWIST_ON_PREON
#endif

#ifdef FETT263_THRUST_ON
#define THRUST_GESTURE
#endif

#ifdef FETT263_THRUST_ON_PREON
#define THRUST_GESTURE
#endif

#if defined(FETT263_THRUST_ON_NO_BM) && !defined(THRUST_GESTURE)
#error FETT263_THRUST_ON_NO_BM requires either FETT263_THRUST_ON or FETT263_THRUST_ON_PREON
#endif

#ifdef FETT263_FORCE_PUSH_ALWAYS_ON
#define FORCE_PUSH_CONDITION true
#define FETT263_FORCE_PUSH
#else
#define FORCE_PUSH_CONDITION battle_mode_
#endif

// Sabertrio - Modified button timeout settings
#ifndef BUTTON_DOUBLE_CLICK_TIMEOUT
#define BUTTON_DOUBLE_CLICK_TIMEOUT 500
#endif

#ifndef BUTTON_SHORT_CLICK_TIMEOUT
#define BUTTON_SHORT_CLICK_TIMEOUT 600
#endif

#ifndef BUTTON_HELD_TIMEOUT
#define BUTTON_HELD_TIMEOUT 300
#endif

#ifndef BUTTON_HELD_MEDIUM_TIMEOUT 
#define BUTTON_HELD_MEDIUM_TIMEOUT 500
#endif

#ifndef BUTTON_HELD_LONG_TIMEOUT
#define BUTTON_HELD_LONG_TIMEOUT 1000
#endif

// Sabertrio - Ignition threshold for low battery alert (Saber will not ignite if battery voltage is below this threshold)
#ifndef IGNITION_LOW_BATTERY_THRESHOLD
#define IGNITION_LOW_BATTERY_THRESHOLD 2.8
#endif

#include "prop_base.h"
#include "../sound/hybrid_font.h"
#include "../sound/effect.h"
#include "../common/current_preset.h"
#include "../common/file_reader.h"
#include "../common/malloc_helper.h"
#include <stm32l4xx.h>

#undef PROP_TYPE
#define PROP_TYPE SaberFett263Buttons

EFFECT(dim);          // for EFFECT_POWERSAVE
EFFECT(battery);      // for EFFECT_BATTERY_LEVEL
EFFECT(bmbegin);      // for Begin Battle Mode
EFFECT(bmend);        // for End Battle Mode
EFFECT(vmbegin);      // for Begin Volume Menu
EFFECT(vmend);        // for End Volume Menu
EFFECT(volup);        // for increase volume
EFFECT(voldown);      // for decrease volume
EFFECT(volmin);       // for minimum volume reached
EFFECT(volmax);       // for maximum volume reached
EFFECT(mute);         // for Mute Mode
EFFECT(faston);       // for EFFECT_FAST_ON
EFFECT(blstbgn);      // for Begin Multi-Blast
EFFECT(blstend);      // for End Multi-Blast
EFFECT(push);         // for Force Push gesture in Battle Mode
EFFECT(quote);        // quote on force effect
EFFECT(no_blade);     // for NO BLADE img
EFFECT(kyber);        // for KyberDial img
EFFECT(volumemenu);   // for Volume Menu img
EFFECT(length);       // for Blade Length Menu img
EFFECT(clearscreen);  // for clearing OLED screen
EFFECT(fontmenu);     // for Soundbank selection prompt
EFFECT(plus);         // for Blade Length increment
EFFECT(minus);        // for Blade Length decrement
EFFECT(menuback);
EFFECT(systemmenu);
EFFECT(default);
EFFECT(tr);
EFFECT2(trloop, trloop);

#ifdef FETT263_USE_SETTINGS_MENU
EFFECT(medit); // Edit Mode
#endif

#include "../sound/sound_library.h"

class GestureControlFile : public ConfigFile {
public:
  void iterateVariables(VariableOP *op) override {
    CONFIG_VARIABLE2(gestureon, 1);
#ifdef SWING_GESTURE
    CONFIG_VARIABLE2(swingon, 1);
#else
    CONFIG_VARIABLE2(swingon, 0);
#endif
    CONFIG_VARIABLE2(swingonspeed, FETT263_SWING_ON_SPEED);
#ifdef TWIST_GESTURE
    CONFIG_VARIABLE2(twiston, 1);
#else
    CONFIG_VARIABLE2(twiston, 0);
#endif
#ifdef THRUST_GESTURE
    CONFIG_VARIABLE2(thruston, 1);
#else
    CONFIG_VARIABLE2(thruston, 0);
#endif
#ifdef STAB_GESTURE
    CONFIG_VARIABLE2(stabon, 1);
#else
    CONFIG_VARIABLE2(stabon, 0);
#endif
#ifdef TWIST_OFF_GESTURE
    CONFIG_VARIABLE2(twistoff, 1);
#else
    CONFIG_VARIABLE2(twistoff, 0);
#endif
#ifdef FETT263_POWER_LOCK
    CONFIG_VARIABLE2(powerlock, 1);
#else
    CONFIG_VARIABLE2(powerlock, 0);
#endif
#ifdef FORCE_PUSH_CONDITION
    CONFIG_VARIABLE2(forcepush, 1);
#else
    CONFIG_VARIABLE2(forcepush, 0);
#endif
    CONFIG_VARIABLE2(forcepushlen, FETT263_FORCE_PUSH_LENGTH);
    CONFIG_VARIABLE2(lockupdelay, FETT263_LOCKUP_DELAY);
    CONFIG_VARIABLE2(clashdetect, FETT263_BM_CLASH_DETECT);
#ifdef FETT263_MAX_CLASH
    CONFIG_VARIABLE2(maxclash, FETT263_MAX_CLASH);
#else
    CONFIG_VARIABLE2(maxclash, 16);
#endif
}
  bool gestureon;         // gesture controls on/off for use with "Gesture Sleep"
  bool swingon;           // Swing On ignition
  int swingonspeed;       // Swing On speed (200 ~ 500 range)
  bool twiston;           // Twist On ignition
  bool thruston;          // Thrust On ignition
  bool stabon;            // Stab On ignition
  bool forcepush;         // Force Push
  uint32_t forcepushlen;  // Force Push Length
  uint32_t lockupdelay;   // Lockup Delay (for Battle Mode)
  bool twistoff;          // Twist Off retraction
  bool powerlock;         // disable PWR button for retraction, for use with "Power Lock" mode to prevent button turning saber off
  int clashdetect;        // maximum Clash Strength to detect Clash during Battle Mode (0 ~ 10 range)
  int maxclash;           // maximum Clash Strength for Clash Sound and Detection works with CLASH_THRESHOLD_G to create range of Clash Strength (8 ~ 16 range)
};

#ifdef FETT263_USE_SETTINGS_MENU
/*=== Blade Length Editing ===*/
int length_edit_length = 0;

// Edit Length Preview for Edit Mode
// LengthEdit uses blade color and creates single white pixel at last pixel, black above last pixel
template<class BASE, class LIGHTUP, class BLACK = BLACK>
class LengthEdit {
public:
  void run(BladeBase* blade) {
    base_.run(blade);
    lightup_.run(blade);
    black_.run(blade);
  }

  OverDriveColor getColor(int led) {
    if (led == length_edit_length) return lightup_.getColor(led);
    if (led > length_edit_length) return black_.getColor(led);
    return base_.getColor(led);
  }
  
private:
  BASE base_;
  LIGHTUP lightup_;
  BLACK black_;
};
#endif

class IntEdit {
  public:
    void run(BladeBase* blade) {  }
    int getInteger(int led) { return int_edit_; }
    static void SetIntValue(int value) { int_edit_ = value; }

  private:
    static int int_edit_;
};

int IntEdit::int_edit_ = 0;

// Color List
struct ColorListEntry { Color16 color; ColorNumber color_number; };

static constexpr ColorListEntry color_list_[] = {
  { Red::color(), COLOR_RED },
  { OrangeRed::color(), COLOR_ORANGERED },
  { DarkOrange::color(), COLOR_DARKORANGE },
  { Orange::color(), COLOR_ORANGE },
  { { 46260, 33410, 0 }, COLOR_GOLD },
  { Yellow::color(), COLOR_YELLOW },
  { GreenYellow::color(), COLOR_GREENYELLOW },
  { Green::color(), COLOR_GREEN },
  { Aquamarine::color(), COLOR_AQUAMARINE },
  { Cyan::color(), COLOR_CYAN },
  { DeepSkyBlue::color(), COLOR_DEEPSKYBLUE },
  { DodgerBlue::color(), COLOR_DODGERBLUE },
  { Blue::color(), COLOR_BLUE },
  { { 7710, 15420, 51400 }, COLOR_ICEBLUE },
  { { 11102, 92, 53864 }, COLOR_INDIGO },
  { { 24000, 0, 50536 }, COLOR_PURPLE },
  { { 30324, 0, 49768 }, COLOR_DEEPPURPLE },
  { Magenta::color(), COLOR_MAGENTA },
  { DeepPink::color(), COLOR_DEEPPINK },
  { { 25700, 25700, 38550 }, COLOR_SILVER },
  { { 21845, 21845, 51400 }, COLOR_GLACIER },
  { { 46260, 46260, 65535 }, COLOR_ICEWHITE },
  { LightCyan::color(), COLOR_LIGHTCYAN },
  { Moccasin::color(), COLOR_MOCCASIN },
  { LemonChiffon::color(), COLOR_LEMONCHIFFON },
  { NavajoWhite::color(), COLOR_NAVAJOWHITE },
  { White::color(), COLOR_WHITE }
};

// Edit Color Submenu
const int rgb_arg_menu_[] {
  BASE_COLOR_ARG,
  ALT_COLOR_ARG,
  ALT_COLOR2_ARG,
  ALT_COLOR3_ARG,
  BLAST_COLOR_ARG,
  CLASH_COLOR_ARG,
  LOCKUP_COLOR_ARG,
  DRAG_COLOR_ARG,
  LB_COLOR_ARG,
  STAB_COLOR_ARG,
  PREON_COLOR_ARG,
  IGNITION_COLOR_ARG,
  RETRACTION_COLOR_ARG,
  POSTOFF_COLOR_ARG,
  SWING_COLOR_ARG,
  EMITTER_COLOR_ARG,
  OFF_COLOR_ARG
};

// Edit Style Setting Submenu
const int int_arg_menu_[] {
  STYLE_OPTION_ARG,
  STYLE_OPTION2_ARG,
  STYLE_OPTION3_ARG,
  IGNITION_OPTION_ARG,
  IGNITION_OPTION2_ARG,
  IGNITION_TIME_ARG,
  IGNITION_DELAY_ARG,
  IGNITION_POWER_UP_ARG,
  RETRACTION_OPTION_ARG,
  RETRACTION_OPTION2_ARG,
  RETRACTION_TIME_ARG,
  RETRACTION_DELAY_ARG,
  RETRACTION_COOL_DOWN_ARG,
  LOCKUP_POSITION_ARG,
  DRAG_SIZE_ARG,
  MELT_SIZE_ARG,
  SWING_OPTION_ARG,
  EMITTER_SIZE_ARG,
  OFF_OPTION_ARG,
  // preon always needs to be last options to allow check for SFX_preon in menu
  PREON_OPTION_ARG,
  PREON_SIZE_ARG
};

// The Saber class implements the basic states and actions for the saber.
class SaberFett263Buttons : public PROP_INHERIT_PREFIX PropBase {
public:
  SaberFett263Buttons() : PropBase() {}
  
  const char* name() override { return "SaberFett263Buttons"; }

  GestureControlFile saved_gesture_control;

  void RestoreGestureState() {
    saved_gesture_control.ReadINIFromDir(NULL, "gesture");
  }

  void SaveGestureState() {
    STDOUT.println("Saving Gesture State");
    saved_gesture_control.WriteToRootDir("gesture");
  }

  void GenerateIniFiles() {
    SaveState(current_preset_.preset_num);
    SaveGestureState();
  }

  Color16 GetColorArg(int blade, int arg) {
    char argspace[32];
    if (style_parser.GetArgument(current_preset_.GetStyle(blade), arg + 2, argspace)) {
      char* tmp;
      int r = strtol(argspace, &tmp, 0);
      int g = strtol(tmp+1, &tmp, 0);
      int b = strtol(tmp+1, NULL, 0);
      return Color16(r,g,b);
    }
    return Color16();
  }

  // Color / Style Editing
  HSL hsl_;
  ShowColorAllBladesTemplate<ShowColorStyle> show_color_all_;
#ifdef FETT263_USE_SETTINGS_MENU
  ShowColorSingleBladeTemplate<LengthEdit<ShowColorStyle,Pulsing<White,Rgb<100,100,100>,800>>,LengthEdit<ShowColorStyle,Pulsing<White,Rgb<100,100,100>,800>>> show_length_;
#if NUM_BLADES > 1
  ShowColorSingleBladeTemplate<Pulsing<ShowColorStyle,Black,800>,Pulsing<ShowColorStyle,Black,800>> show_preview_;

  void BladePreview(int blade) {
    if (blade_preview_ >= blade_num_) {
      show_preview_.Stop(blade_preview_);
    }
    blade_preview_ = blade;
    show_preview_.Start(blade);
    ShowColorStyle::SetColor(GetColorArg(blade_num_, 1));
  }
#endif

  void LengthPreview(int blade) {
    show_length_.Start(blade);
    length_edit_length = blade_length_ - 1;
    ShowColorStyle::SetColor(GetColorArg(blade_num_, 1));
  }
#endif

  ShowColorSingleBladeTemplate<ShowColorStyle> show_color_;
  ShowColorSingleBladeTemplate<Mix<Bump<Int<16384>,Int<14000>>,RgbArg<1,Rgb<255,0,0>>,ShowColorStyle>> bump_color_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<Int<26000>,Int<8000>>,RgbArg<1,Rgb<255,0,0>>,ShowColorStyle>> tip_color_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<Int<7000>,Int<-6000>>,RgbArg<1,Rgb<255,0,0>>,ShowColorStyle>> hilt_color_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<Int<7000>,Int<-6000>>,Black,ShowColorStyle>> pre_color_;
  ShowColorSingleBladeTemplate<Mix<Bump<IntEdit,Int<10000>>,Black,ShowColorStyle>> show_lockup_position_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<IntEdit,Int<6000>>,Black,ShowColorStyle>> show_drag_size_;
  ShowColorSingleBladeTemplate<Mix<SmoothStep<IntEdit,Int<-6000>>,Black,ShowColorStyle>> show_emitter_size_;

  // Set In/Out (Ignition/Retraction) Arguments
  void SetInOut() {
    char style_arg[10];
    // Reminder - use search and replace to rename "calc_" per PR comments
    itoa(calc_, style_arg, 10);
    current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2, style_arg));
    current_preset_.Save();
    switch (menu_type_) {
      case MENU_STYLE_OPTION:
      case MENU_STYLE_OPTION2:
      case MENU_STYLE_OPTION3:
      case MENU_IGNITION_TIME:
      case MENU_IGNITION_OPTION:
      case MENU_IGNITION_OPTION2:
      case MENU_IGNITION_POWER_UP_OPTION:
      case MENU_OFF_OPTION:
        break;
      case MENU_IGNITION_DELAY:
        SetPresetFast(current_preset_.preset_num);
        break;
      case MENU_PREON_OPTION:
      case MENU_PREON_SIZE:
        UpdatePreon();
        break;
      case MENU_RETRACTION_TIME:
      case MENU_RETRACTION_OPTION:
      case MENU_RETRACTION_OPTION2:
      case MENU_RETRACTION_COOL_DOWN_OPTION:
      case MENU_RETRACTION_DELAY:
        UpdateStyle();
        off_event_ = true;
        restart_millis_ = millis();
        break;
      default:
        break;
    }
  }

  void RevertInOut() {
    char style_arg[10];
    itoa(arg_revert_, style_arg, 10);
    current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2, style_arg));
    switch (menu_type_) {
      case MENU_RETRACTION_OPTION:
      case MENU_RETRACTION_TIME:
      case MENU_RETRACTION_COOL_DOWN_OPTION:
      case MENU_RETRACTION_DELAY:
        char ig[10];
        itoa(ignite_time_, ig, 10);
        current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, ig));
        break;
      default:
        break;
    }
    current_preset_.Save();
  }

  void SayStyleNumber(int style_num) {
    sound_library_.SayStyle();
    sound_library_.SayNumber(style_num, SAY_WHOLE);
    if (style_parser.UsesArgument(current_preset_.GetStyle(blade_num_), STYLE_OPTION_ARG + 2)) {
      char argspace[32];
      style_parser.GetArgument(current_preset_.GetStyle(blade_num_), STYLE_OPTION_ARG + 2, argspace);
      int opt = strtol(argspace, NULL, 0);
      sound_library_.SayOption();
      sound_library_.SayNumber(opt, SAY_WHOLE);
    }
  }

  // Stop location/size previews in Style Settings Mode
  void StopSettingPreview() {
    switch (set_num_) {
      case LOCKUP_POSITION_ARG:
        show_lockup_position_.Stop(blade_num_);
        break;
      case DRAG_SIZE_ARG:
      case MELT_SIZE_ARG:
        show_drag_size_.Stop(blade_num_);
        break;
      case EMITTER_SIZE_ARG:
      case PREON_SIZE_ARG:
        show_emitter_size_.Stop(blade_num_);
        break;
      default:
        break;
    }
    UpdateStyle();
    menu_type_ = MENU_STYLE_SETTING_SUB;
  }

  // Save IntArg values 16 ~ 25 from Edit Mode Menu selection
  void SaveStyleSetting() {
    char style_arg[10];
    itoa(calc_, style_arg, 10);
    current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2, style_arg));
    current_preset_.Save();
    StopSettingPreview();
    MenuSave();
  }

  void CancelStyleSetting() {
    StopSettingPreview();
    MenuCancel();
  }

/*=== Color Editing ===*/
  #define H_CHANGE (M_PI / 98304)
  #define L_ANGLE (M_PI / 30)
  #define H_ANGLE (M_PI / 16384)
  #define EDIT_MODE_ZOOM (M_PI * 2 / 2000)
  void EditColor() {
    if (edit_color_ && color_mode_ != COLOR_LIST) {
      float a = fusor.angle2() - hsl_angle_;
      if (a > M_PI) a-=M_PI*2;
      if (a < -M_PI) a+=M_PI*2;
      float angle = 100;
      switch (color_mode_) {
        case EDIT_COLOR: angle = H_ANGLE; break;
        case ZOOM_COLOR:
        case CC_ZOOM_COLOR:
          angle = EDIT_MODE_ZOOM;
          break;
        case EDIT_WHITE:
        case EDIT_BLACK: angle = L_ANGLE; break;
        default: break;
      }
      int steps = 0;
      if (a > angle * 2/3) {
        hsl_angle_ += angle;
        if (hsl_angle_ > M_PI) hsl_angle_ -= M_PI*2;
        steps++;
      }
      if (a < -angle * 2/3) {
        hsl_angle_ -= angle;
        if (hsl_angle_ < M_PI) hsl_angle_ += M_PI*2;
        steps--;
      }
      switch (color_mode_) {
        default: break;
        case EDIT_COLOR:
        case ZOOM_COLOR:
        case CC_ZOOM_COLOR:
          hsl_.H = fract(hsl_.H - H_CHANGE * steps);
          break;
        case EDIT_WHITE:
          if (steps > 0) {
            if (hsl_.L < 1.0) {
              hsl_.L = clamp(hsl_.L + 0.01, 0.5, 1.0);
              if (hsl_.L == 1.0) {
                sound_library_.SayMaximum();
                hsl_angle_ = fusor.angle2();
              }
            }
          }
          if (steps < 0) {
            if (hsl_.L > 0.5) {
              hsl_.L = clamp(hsl_.L - 0.01, 0.5, 1.0);
              if (hsl_.L == 0.5) {
                sound_library_.SayMinimum();
                hsl_angle_ = fusor.angle2();
              }
            }
          }
          break;
        case EDIT_BLACK:
          if (steps > 0) {
            if (hsl_.L < 0.5) {
              hsl_.L = clamp(hsl_.L + 0.01, 0.01, 0.5);
              if (hsl_.L == 0.5) {
                sound_library_.SayMaximum();
                hsl_angle_ = fusor.angle2();
              }
            }
          }
          if (steps < 0) {
            if (hsl_.L > 0.01) {
              hsl_.L = clamp(hsl_.L - 0.01, 0.01, 0.5);
              if (hsl_.L == 0.01) {
                sound_library_.SayMinimum();
                hsl_angle_ = fusor.angle2();
              }
            }
          }
          break;
      }
      ShowColorStyle::SetColor(Color16(hsl_));
    }
  }

  // Saves New Color from Edit Mode Preview Styles to Preset
  void NewColor(int blade, int effect) {
    STDOUT << "NewColor(" << blade << "," << effect << ")\n";
    char new_color[32];
    Color16 color_source;
    switch (color_mode_) {
      case COLOR_LIST:
      case CC_COLOR_LIST:
        color_source = Color16(color_list_[dial_].color);
        break;
      default:
        color_source = Color16(hsl_);
        break;
    }
    itoa(Color16(color_source).r, new_color, 10);
    strcat(new_color, ",");
    itoa(Color16(color_source).g, new_color + strlen(new_color), 10);
    strcat(new_color, ",");
    itoa(Color16(color_source).b, new_color + strlen(new_color), 10);

#if NUM_BLADES > 1
    if (color_mode_ == CC_COLOR_LIST  || color_mode_ == CC_ZOOM_COLOR) {
      for (int i = 1; i <= NUM_BLADES; i++) {
        current_preset_.SetStyle(i,style_parser.SetArgument(current_preset_.GetStyle(i), effect + 2, new_color));
      }
    } else {
      current_preset_.SetStyle(blade,style_parser.SetArgument(current_preset_.GetStyle(blade), effect + 2, new_color));
    }
#else
    current_preset_.SetStyle(blade,style_parser.SetArgument(current_preset_.GetStyle(blade), effect + 2, new_color));
#endif
    color_mode_ = NONE;
  }

  // Toggles ColorChange Mode if current style uses RgbArg to CC_COLOR_LIST
  void ToggleCCMode() {
    bool uses_rgb_arg = false;
    for (int i = 1; i <= NUM_BLADES; i++)
    uses_rgb_arg |= style_parser.UsesArgument(current_preset_.GetStyle(i), 3);
    if (!uses_rgb_arg) {
#ifndef DISABLE_COLOR_CHANGE
      ToggleColorChangeMode();
#endif
    } else {
      bool handles_color_change;
    #define USES_COLOR_CHANGE(N) \
      handles_color_change |= current_config->blade##N->current_style() && current_config->blade##N->current_style()->IsHandled(HANDLED_FEATURE_CHANGE_TICKED);
      ONCEPERBLADE(USES_COLOR_CHANGE)
      if (!handles_color_change) {
        color_mode_ = CC_COLOR_LIST;
        show_color_all_.Start();
        for (int i = 1; i <= NUM_BLADES; i++) {
          if (style_parser.UsesArgument(current_preset_.GetStyle(i), BASE_COLOR_ARG + 2)) {
            ShowColorStyle::SetColor(GetColorArg(i, BASE_COLOR_ARG));
            break;
          }
        }
        current_menu_angle_ = fusor.angle2();
        dial_ = -1;
        hybrid_font.PlayCommon(&SFX_ccbegin);
      } else {
#ifndef DISABLE_COLOR_CHANGE
        ToggleColorChangeMode();
#endif
      }
    }
  }

  void DoInteractivePreon() {
    if (CheckInteractivePreon()) {
      SaberBase::DoEffect(EFFECT_INTERACTIVE_PREON, 0);
    } else {
      if (wav_player->isPlaying()) {
        SoundLoop();
      }
      DoIgnition();
    }
  }

  void DoInteractiveBlast() {
    if (CheckInteractiveBlast()) {
      SaberBase::DoEffectR(EFFECT_INTERACTIVE_BLAST);
    } else {
      SaberBase::DoBlast();
      if (battle_mode_) ToggleBattleModeMultiBlast();
    }
  }

  void Setup() override {
    RestoreGestureState();
  }

  bool chdir(const char* dir) override {
    bool ret = PropBase::chdir(dir);
    num_tracks_ = RunCommandAndGetSingleLine("list_current_tracks", nullptr, 0, 0, 0);
    track_num_ = 0;
    return ret;
  }

  enum ClashType {
    CLASH_NONE,
    CLASH_CHECK,
    CLASH_BATTLE_MODE,
    CLASH_LOCKUP,
    CLASH_LOCKUP_END,
  };

  void Clash2(bool stab, float strength) override {
    Event(BUTTON_NONE, stab ? EVENT_STAB : EVENT_CLASH);
    SaberBase::SetClashStrength(strength);
    IgnoreClash(100);
  }

/*=== Main loop function for the Saber ===*/
  void Loop() override {
    PropBase::Loop();
    DetectTwist();
    Vec3 mss = fusor.mss();
    if (clash_type_ != CLASH_NONE && millis() - clash_impact_millis_ > 1) {
      // CHECK PUSH
      if (clash_type_ == CLASH_CHECK) {
        Event(BUTTON_NONE, EVENT_PUSH);
        STDOUT.println("EVENT PUSH");
        clash_type_ = CLASH_NONE;
      }
      if (clash_type_ != CLASH_LOCKUP_END) {
        if (clash_type_ == CLASH_BATTLE_MODE && SaberBase::GetClashStrength() > saved_gesture_control.clashdetect) {
          SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
          SaberBase::DoBeginLockup();
          auto_lockup_on_ = true;
        } else {
          SaberBase::DoClash();
        }
        clash_type_ = CLASH_NONE;
      }
    }
    sound_library_.Poll(wav_player);
    EditColor();
    FreeWavplayerIfPossible();
    if (SaberBase::IsOn()) {
      DetectSwing();
      if (auto_lockup_on_ &&
          !swinging_ &&
          fusor.swing_speed() > 120 &&
          millis() - clash_impact_millis_ > saved_gesture_control.lockupdelay &&
          SaberBase::Lockup()) {
          SaberBase::DoEndLockup();
          SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
        auto_lockup_on_ = false;
      }
      if (auto_melt_on_ &&
          !swinging_ &&
          fusor.swing_speed() > 60 &&
          millis() - clash_impact_millis_ > saved_gesture_control.lockupdelay &&
          SaberBase::Lockup()) {
        SaberBase::DoEndLockup();
        SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
        auto_melt_on_ = false;
      }
      // EVENT_PUSH
      if (fabs(mss.x) < 3.0 &&
          mss.y * mss.y + mss.z * mss.z > 100 &&
          fusor.swing_speed() < 20 &&
          fabs(fusor.gyro().x) < 5) {
        if (millis() - push_begin_millis_ > saved_gesture_control.forcepushlen) {
          // Checking for Clash at end of movement
          clash_type_ = CLASH_CHECK;
          push_begin_millis_ = millis();
          clash_impact_millis_ = millis();
        }
      } else {
        push_begin_millis_ = millis();
      }
    } else {
      // EVENT_SWING - Swing On gesture control to allow fine tuning of speed needed to ignite
      if (menu_ || millis() - saber_off_time_millis_ < MOTION_TIMEOUT) {
        SaberBase::RequestMotion();
        if (swinging_ && fusor.swing_speed() < 90) {
          swinging_ = false;
        }
        if (!swinging_ && fusor.swing_speed() > saved_gesture_control.swingonspeed) {
          swinging_ = true;
          Event(BUTTON_NONE, EVENT_SWING);
        }
      }
    }
    // EVENT_THRUST
    if (mss.y * mss.y + mss.z * mss.z < 16.0 &&
        mss.x > 14  &&
        fusor.swing_speed() < 150) {
      if (millis() - thrust_begin_millis_ > 15) {
        Event(BUTTON_NONE, EVENT_THRUST);
        thrust_begin_millis_ = millis();
      }
    } else {
      thrust_begin_millis_ = millis();
    }
    DetectMenuTurn();
#ifdef ENABLE_AUDIO
    TrackPlayer();

    // Sabertrio - BGM for Menu Systems (Soundbank Selection & Settings Menu)
    if (preset_menu_) {
      if ((millis() - bgm_begin_millis) >= (bgm_duration - 50)) { // Restarts BGM after it finishes
        StartMenuBGM();
      }
    }

    if (system_menu_bgm_switch_){ // Start BGM for Settings Menu after callout
      delay(1000);
      StartSystemMenuBGM();
      system_menu_bgm_switch_ = false;
    }

    if (menu_) {
     if ((millis() - bgm_begin_millis) >= (bgm_duration - 80)) { // Restarts BGM after it finishes
       StartSystemMenuBGM();
     }
   }  
#else
    STDOUT.println("Audio disabled.");
#endif
  }

/*=== Audio & Track Players ===*/
  enum TrackMode {
    PLAYBACK_OFF,
    PLAYBACK_LOOP,
    PLAYBACK_ROTATE,
    PLAYBACK_RANDOM,
  };

  void StartTrackPlayer() {
    if (num_tracks_ > 0) {
      sound_library_.SaySelect();
      StartMenu(MENU_TRACK_PLAYER);
      track_num_ = 1;
      PlayTrack();
    } else {
      // Loop default track if tracks not found
      sound_library_.SayLoop();
      track_num_ = 0;
      track_mode_ = PLAYBACK_LOOP;
      StartOrStopTrack();
    }
  }

  void TrackPlayer() {
    if (track_mode_ != PLAYBACK_OFF) {
      if (!track_player_) {
        if (track_num_ <= 0 && track_mode_ == PLAYBACK_LOOP) {
          StartOrStopTrack();
          if (!track_player_ || !track_player_->isPlaying()) track_mode_ = PLAYBACK_OFF;
        } else {
          switch (track_mode_) {
            case PLAYBACK_ROTATE:
              track_num_ += 1;
              if (track_num_ > num_tracks_) track_num_ = 1;
              break;
            case PLAYBACK_RANDOM:
              track_num_ = rand() % num_tracks_;
              if (track_num_ <= 0) track_num_ = num_tracks_;
              break;
            default:
              break;
          }
          PlayTrack();
        }
      }
    } else {
      if (track_player_ && !track_player_->isPlaying()) {
        track_player_.Free();
      }
    }
  }

  void PlayEffectTrack() {
    if (!track_player_->isPlaying()) {
      if (num_tracks_ > 0) {
        if (track_num_ <= 0) track_num_ = 1;
        PlayTrack();
      } else {
        StartOrStopTrack();
      }
    }
  }

  void PlayTrack() {
    char playtrack[128];
    RunCommandAndGetSingleLine("list_current_tracks", nullptr, track_num_, playtrack, sizeof(playtrack));
    MountSDCard();
    EnableAmplifier();
    track_player_ = GetFreeWavPlayer();
    if (track_player_) {
      track_player_->Play(playtrack);
    } else {
      STDOUT.println("No available WAV players.");
    }
  }

  void StopTrackPlayer() {
    track_mode_ = PLAYBACK_OFF;
    if (track_player_) {
      track_player_->Stop();
      track_player_.Free();
    } else {
      StartOrStopTrack();
    }
  }

  void SoundLoop() {
    if (wav_player->isPlaying()) {
      wav_player->set_fade_time(0.2);
      wav_player->FadeAndStop();
      wav_player.Free();
      STDOUT.println("End Wav Player");
    } else {
      wav_player = GetFreeWavPlayer();
      if (wav_player) {
        wav_player->PlayOnce(&SFX_trloop);
      } else {
        STDOUT.println("Out of WAV players!");
      }
    }
  }

  void FreeWavplayerIfPossible() {
    if (!wav_player) return;
    if (menu_) return;
    if (wav_player->isPlaying()) return;
    wav_player.Free();
  }

  void StopWavPlayers() { // For preventing audio stacking and stopping audio beeps etc.
    if (wav_player && wav_player->isPlaying()) {
      wav_player->Stop();
      wav_player.Free();
    }
  }

  // Sabertrio - Adds menu hum sound effect
  void StartMenuBGM() {
    bgm_begin_millis = millis();
#ifdef ENABLE_AUDIO
    MountSDCard();
    EnableAmplifier();
    bgm_player_ = GetFreeWavPlayer();
    if (bgm_player_){
      bgm_player_->PlayOnce(&SFX_menuback);
      bgm_duration = bgm_player_->length() * 1000; // Get the duration of the currently playing BGM
    } else {
      STDOUT.println("No available WAV players.");
    }
#else
    STDOUT.println("Audio disabled.");
#endif
  }

  void StopMenuBGM() {
#ifdef ENABLE_AUDIO
    bgm_player_->Stop();
    bgm_player_.Free();
    bgm_begin_millis = 0;
    bgm_duration = 0;
#else
    STDOUT.println("Audio disabled.");
#endif
  }

  void StartSystemMenuBGM() {
    bgm_begin_millis = millis();
#ifdef ENABLE_AUDIO
    MountSDCard();
    EnableAmplifier();
    bgm_player_ = GetFreeWavPlayer();
    if (bgm_player_){
      bgm_player_->PlayOnce(&SFX_systemmenu);
      bgm_duration = bgm_player_->length() * 1000; // Get the duration of the currently playing BGM
    } else {
      STDOUT.println("No available WAV players.");
    }
#else
    STDOUT.println("Audio disabled.");
#endif
  }

  void StopSystemMenuBGM() {
#ifdef ENABLE_AUDIO
    bgm_player_->Stop();
    bgm_player_.Free();
    bgm_begin_millis = 0;
    bgm_duration = 0;
#else
    STDOUT.println("Audio disabled.");
#endif
  } 

  void SelectPreset(int preset) {
#ifdef SAVE_PRESET
    SaveState(preset);
#endif
    SetPreset(preset, true);
  }

  void DetectMenuTurn() {
    float a = fusor.angle2() - current_menu_angle_;
    if (a > M_PI) a-=M_PI*2;
    if (a < -M_PI) a+=M_PI*2;
    if (a > twist_menu_ * 2/3) {
      if (!swinging_) {
        Event(BUTTON_NONE, EVENT_TWIST_RIGHT);
        STDOUT.println("EVENT MENU TURN RIGHT");
      }
      current_menu_angle_ = fusor.angle2();
    }
    if (a < -twist_menu_ * 2/3) {
      if (!swinging_) {
        Event(BUTTON_NONE, EVENT_TWIST_LEFT);
        STDOUT.println("EVENT MENU TURN LEFT");
      }
      current_menu_angle_ = fusor.angle2();
    }
  }

#ifdef FETT263_USE_SETTINGS_MENU
#define GESTURE_OPTIONS 6
#define SET_SUBMENUS 6
#endif

  enum MenuType {
    MENU_TOP,
    MENU_PRESET,
    MENU_VOLUME,
    MENU_TRACK_PLAYER,
#ifdef FETT263_USE_SETTINGS_MENU
    MENU_BLADE_LENGTH,
    MENU_LENGTH,
    MENU_GESTURE_SUB,
    MENU_SWINGON,
    MENU_TWISTON,
    MENU_THRUSTON,
    MENU_STABON,
    MENU_FORCEPUSH,
    MENU_TWISTOFF,
    MENU_POWERLOCK,
    MENU_SETTING_SUB,
    MENU_DIM_BLADE,
    MENU_CLASH_THRESHOLD,
    MENU_SWINGON_SPEED,
    MENU_FORCEPUSH_LENGTH,
    MENU_LOCKUP_DELAY,
    MENU_CLASH_DETECT,
    MENU_MAX_CLASH,
    MENU_STYLE_SETTING_SUB,
    MENU_OFF_OPTION,
    MENU_STYLE_OPTION,
    MENU_STYLE_OPTION2,
    MENU_STYLE_OPTION3,
    MENU_IGNITION_OPTION,
    MENU_IGNITION_OPTION2,
    MENU_IGNITION_TIME,
    MENU_IGNITION_POWER_UP_OPTION,
    MENU_IGNITION_DELAY,
    MENU_RETRACTION_OPTION,
    MENU_RETRACTION_OPTION2,
    MENU_RETRACTION_TIME,
    MENU_RETRACTION_COOL_DOWN_OPTION,
    MENU_RETRACTION_DELAY,
    MENU_LOCKUP_POSITION,
    MENU_DRAG_SIZE,
    MENU_MELT_SIZE,
    MENU_SWING_OPTION,
    MENU_EMITTER_SIZE,
    MENU_PREON_OPTION,
    MENU_PREON_SIZE,
    MENU_COLOR_BASE,
    MENU_COLOR_ALT,
    MENU_COLOR2_ALT,
    MENU_COLOR3_ALT,
    MENU_COLOR_BLAST,
    MENU_COLOR_CLASH,
    MENU_COLOR_LOCKUP,
    MENU_COLOR_DRAG,
    MENU_COLOR_LB,
    MENU_COLOR_STAB,
    MENU_COLOR_PREON,
    MENU_COLOR_IGNITE,
    MENU_COLOR_RETRACT,
    MENU_COLOR_PSTOFF,
    MENU_COLOR_SWING,
    MENU_COLOR_EMITTER,
    MENU_COLOR_OFF,
#endif
  };

  enum MainMenu {
    EDIT_STYLE = 1,
    EDIT_COLORS = 2,
    EDIT_FONT = 3,
    EDIT_TRACK = 4,
    EDIT_SETTINGS = 5,
    COPY_PRESET = 6,
    DELETE_PRESET = 7,
    EXIT_MENU = 8,
  };

  enum StyleSubMenu {
    EDIT_STYLE_SELECT = 1,
    EDIT_STYLE_SETTINGS = 2,
  };

  enum ColorSubMenu {
    EDIT_EFFECT_COLOR = 1,
#if NUM_BLADES == 1
    RESET_COLORS = 2,
#else
    COPY_COLORS = 2,
    RESET_COLORS = 3,
#endif
  };
  enum ColorOptions {
    COLOR_LIST_MODE = 0,
    COLOR_HUE_MODE = 1,
    WHITE_MODE = 2,
    BLACK_MODE = 3,
  };

  enum SettingsMenu {
    EDIT_VOLUME = 1,
    EDIT_CONTROL_SETTINGS = 2,
    EDIT_CLASH_THRESHOLD = 3,
    EDIT_BLADE_LENGTH = 4,
    EDIT_BRIGHTNESS = 5,
    EDIT_KYBER_CRYSTAL = 6,
  };

  enum GestureControls {
    GESTURE_TWIST_IGNITION = 6,
    GESTURE_TWIST_RETRACTION = 1,
    GESTURE_SWINGON_IGNITION = 2,
    GESTURE_SWINGON_SPEED = 3,
    GESTURE_THRUST_IGNITION = 4,
    GESTURE_STAB_IGNITION = 5,
  };

  int GetStyleNumber(int blade_num) {
    const char* tmp;
    tmp = current_preset_.GetStyle(blade_num);
    int style_num = FirstWord(tmp, "builtin") ? atoi(SkipWord(tmp)) : 0;
    return style_num;
  }

  void ChangeStyleNumber(int blade_num, int direction) {
    int num_presets = current_config->num_presets;
    int style_num = GetStyleNumber(blade_num);
    style_num += direction;
    if (style_num < 0) style_num = num_presets - 1;
    if (style_num >= num_presets) style_num = 0;
    char style_arg[10];
    itoa(style_num, style_arg, 10);
    current_preset_.SetStyle(blade_num, style_parser.SetArgument(current_preset_.GetStyle(blade_num), 1, style_arg));
  }

  void ChangeStyleNumberAllBlades(int direction) {
    for (int i = 1; i <= NUM_BLADES; i++) {
      ChangeStyleNumber(i, direction);
    }
    current_preset_.Save();
    UpdateStyle();
  }

  // Uses font_num_ value for starting font, not current font
  void ChangeFont(int direction) {
    int num_fonts = RunCommandAndGetSingleLine("list_fonts", nullptr, 0, 0, 0);
    font_num_ += direction;
    if (font_num_ > num_fonts) font_num_ = 1;
    if (font_num_ <= 0) font_num_ = num_fonts;
    char font[128];
    RunCommandAndGetSingleLine("list_fonts", nullptr, font_num_, font, sizeof(font));
    strcat(font, ";common");
    current_preset_.font = mkstr(font);
    current_preset_.Save();
    SetPresetFast(current_preset_.preset_num);
    hybrid_font.SB_Effect(EFFECT_NEWFONT, 0);
  }

  int GetNumberOfPresets() {
    CurrentPreset tmp;
    tmp.SetPreset(-1);
    return tmp.preset_num + 1;
  }

#ifdef FETT263_USE_SETTINGS_MENU
  // Gesture Control Boolean Menu
  void EnterBooleanMenu(MenuType t, bool current_value) {
    menu_type_ = t;
    choice_ = current_value;
    if(t == MENU_OFF_OPTION) calc_ = choice_;
    sound_library_.SayBool(current_value);
  }

  void StartEditMode() {
    if (track_player_) {
      StopTrackPlayer();
    }
    if (!SFX_medit) {
      ProffieOSErrors::error_in_font_directory();
      STDOUT.println("Edit Mode prompts missing");
    } else {
#ifdef FETT263_EDIT_SETTINGS_MENU
      STDOUT.println("Enter Edit Settings Menu");
#else
      STDOUT.println("Enter Edit Mode");
#endif
      GenerateIniFiles();
      menu_top_pos_ = 0;
#ifdef FETT263_EDIT_SETTINGS_MENU
      SaberBase::DoSettingsMenu();
      sound_library_.SaySettingsMenu();
      StartMenu(MENU_SETTING_SUB);
      delay(1200);
#else
      sound_library_.SayEditMode();
      StartMenu(MENU_TOP);
      FastOn();
#endif
    }
  }
#endif

  void CopyPreset(bool announce) {
    int32_t pos = current_preset_.preset_num;
    current_preset_.preset_num = -1;
    current_preset_.SaveAt(pos);
    if (announce) {
      sound_library_.SayCopyPreset();
      wav_player.Free();
    }
  }

  // Check if ShowColor for ColorChange / Color Editing is active to prevent other events
  bool CheckShowColorCC() {
    if (color_mode_ == CC_COLOR_LIST || color_mode_ == CC_ZOOM_COLOR) return true;
    if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) return true;
    return false;
  }

  // Check to see if ShowColor style is being used and use MenuUndo to properly close if button presses or holds not in menu are used
  bool CancelShowColor() {
    if (color_mode_ != NONE) {
      if (CheckShowColorCC()) {
        EndColorZoom();
        return true;
      } else {
        MenuUndo();
        return true;
      }
    } else {
      switch (menu_type_) {
#ifdef FETT263_EDIT_SETTINGS_MENU
        case MENU_LENGTH:
#if NUM_BLADES > 1
        case MENU_BLADE_LENGTH:
#endif
          MenuUndo();
          return true;
          break;
#endif
        default:
          return false;
          break;
      }
    }
  }

  bool DoColorZoom() {
    if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_SMOOTH) {
      SaberBase::SetColorChangeMode(SaberBase::COLOR_CHANGE_MODE_ZOOMED);
      return true;
    }
    if (color_mode_ == COLOR_LIST || color_mode_ == CC_COLOR_LIST) {
      hsl_ = Color16(color_list_[dial_].color).toHSL();
    }
    switch (color_mode_) {
      case COLOR_LIST:
      case EDIT_COLOR:
        color_mode_ = ZOOM_COLOR;
        hsl_angle_ = fusor.angle2();
        return true;
        break;
      case CC_COLOR_LIST:
        color_mode_ = CC_ZOOM_COLOR;
        edit_color_ = true;
        hsl_angle_ = fusor.angle2();
        return true;
        break;
      default:
        return false;
        break;
    }
  }

  // If Color Zoom mode is active save NewColor and end ShowColor style
  bool EndColorZoom() {
#ifndef DISABLE_COLOR_CHANGE
    if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_ZOOMED) {
      ToggleColorChangeMode();
      return true;
    }
#endif
    switch (color_mode_) {
      case ZOOM_COLOR:
      case EDIT_COLOR:
      case COLOR_LIST:
        MenuChoice();
        return true;
        break;
      case CC_COLOR_LIST:
      case CC_ZOOM_COLOR:
        edit_color_ = false;
        hybrid_font.PlayCommon(&SFX_ccend);
        NewColor(1, BASE_COLOR_ARG);
        current_preset_.Save();
        show_color_all_.Stop();
        UpdateStyle();
        wav_player.Free();
        return true;
        break;
      default:
        return false;
        break;
    }
  }

/*=== Menu Logic ===*/
  // Start Menu Mode
  void StartMenu(MenuType menu) {
    twist_menu_ = M_PI / 4;
    current_menu_angle_ = fusor.angle2();
    menu_type_ = menu;
    menu_ = true;
  }

  // Edit Mode Menu Select (AUX Button)
  void MenuChoice() {
    enable_twist_ = false; // Disable twist for menu selection
    switch (menu_type_) {
      case MENU_PRESET:
        sound_library_.SaySelect();
        menu_type_ = MENU_TOP;
        menu_ = false;
        break;
      case MENU_VOLUME:
        if (!SaberBase::IsOn()) {
#ifdef FETT263_USE_SETTINGS_MENU
          menu_type_ = MENU_SETTING_SUB;
#endif
          MenuSave();
        } else {
          MenuExit();
        }
        break;
#ifdef FETT263_USE_SETTINGS_MENU
#if NUM_BLADES > 2
      case MENU_BLADE_LENGTH:
        if (blade_num_ == 0) {
          blade_num_ = 1;
        }
        FastOn();
        enable_twist_ = true;
        sound_library_.SaySelect();
        show_preview_.Stop(blade_preview_);
        SaveState(current_preset_.preset_num);
        blade_preview_ = 0;
        max_length_ = GetMaxBladeLength(blade_num_);
        blade_length_ = GetBladeLength(blade_num_);
        if (blade_length_ < 1) blade_length_ = max_length_;
        length_revert_ = blade_length_;
        LengthPreview(blade_num_);
        menu_type_ = MENU_LENGTH;
        break;
#endif
      case MENU_LENGTH:
        menu_type_ = MENU_SETTING_SUB;
        current_preset_.Save();
        show_length_.Stop(blade_num_);
        UpdateStyle();
        Off(OFF_FAST);
        delay(500);
        MenuSave();
        enable_twist_ = false;
        break;
      case MENU_GESTURE_SUB:
        switch (gesture_num_) {
          case GESTURE_SWINGON_IGNITION:
            EnterBooleanMenu(MENU_SWINGON, saved_gesture_control.swingon);
            break;
          case GESTURE_SWINGON_SPEED:
            menu_type_ = MENU_SWINGON_SPEED;
            enable_twist_ = true;
            sound_library_.SaySelect();
            calc_ = saved_gesture_control.swingonspeed;
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case GESTURE_TWIST_IGNITION:
            EnterBooleanMenu(MENU_TWISTON, saved_gesture_control.twiston);
            break;
          case GESTURE_THRUST_IGNITION:
            EnterBooleanMenu(MENU_THRUSTON, saved_gesture_control.thruston);
            break;
          case GESTURE_STAB_IGNITION:
            EnterBooleanMenu(MENU_STABON, saved_gesture_control.stabon);
            break;
          case GESTURE_TWIST_RETRACTION:
            EnterBooleanMenu(MENU_TWISTOFF, saved_gesture_control.twistoff);
            break;
          default:
            break;
        }
        break;
      case MENU_SWINGON:
        if (choice_) {
          saved_gesture_control.swingon = true;
          SaveGestureState();
        } else {
          saved_gesture_control.swingon = false;
          SaveGestureState();
        }
        menu_type_ = MENU_GESTURE_SUB;
        MenuSave();
        break;
      case MENU_SWINGON_SPEED:
        sound_library_.SaySelect();
        sound_library_.SayNumber(calc_, SAY_WHOLE);
        saved_gesture_control.swingonspeed = calc_;
        SaveGestureState();
        menu_type_ = MENU_GESTURE_SUB;
        MenuSave();
        break;
      case MENU_TWISTON:
        if (choice_) {
          saved_gesture_control.twiston = true;
          SaveGestureState();
        } else {
          saved_gesture_control.twiston = false;
          SaveGestureState();
        }
        menu_type_ = MENU_GESTURE_SUB;
        MenuSave();
        break;
      case MENU_THRUSTON:
        if (choice_) {
          saved_gesture_control.thruston = true;
          SaveGestureState();
        } else {
          saved_gesture_control.thruston = false;
          SaveGestureState();
        }
        menu_type_ = MENU_GESTURE_SUB;
        MenuSave();
        break;
      case MENU_STABON:
        if (choice_) {
          saved_gesture_control.stabon = true;
          SaveGestureState();
        } else {
          saved_gesture_control.stabon = false;
          SaveGestureState();
        }
        menu_type_ = MENU_GESTURE_SUB;
        MenuSave();
        break;
      case MENU_TWISTOFF:
        if (choice_) {
          saved_gesture_control.twistoff = true;
          SaveGestureState();
        } else {
          saved_gesture_control.twistoff = false;
          SaveGestureState();
        }
        menu_type_ = MENU_GESTURE_SUB;
        MenuSave();
        break;
      case MENU_SETTING_SUB:
        switch (menu_sub_pos_) {
          case EDIT_VOLUME:
            menu_type_ = MENU_VOLUME;
            sound_library_.SaySelect();
            break;
          case EDIT_CONTROL_SETTINGS:
            menu_type_ = MENU_GESTURE_SUB;
            sound_library_.SaySelectOption();
            gesture_num_ = 0;
            MenuDial(0);
            break;
          case EDIT_CLASH_THRESHOLD:
            menu_type_ = MENU_CLASH_THRESHOLD;
            enable_twist_ = true;
            sound_library_.SaySelect();
            clash_t_ = GetCurrentClashThreshold();
            sound_library_.SayNumber(clash_t_, SAY_DECIMAL);
            break;
          case EDIT_BLADE_LENGTH:
#if (NUM_BLADES >= 1 && NUM_BLADES <=5)
            menu_type_ = MENU_LENGTH;
            SaveState(current_preset_.preset_num);
            blade_num_ = 1;
            FastOn();
            enable_twist_ = true;
            max_length_ = GetMaxBladeLength(blade_num_);
            blade_length_ = GetBladeLength(blade_num_);
            sound_library_.SaySelect();
            if (blade_length_ < 1) blade_length_ = max_length_;
            length_revert_ = blade_length_;
            LengthPreview(blade_num_);
#else
            menu_type_ = MENU_BLADE_LENGTH;
            blade_num_ = 0;
            sound_library_.SaySelectBlade();
#endif
            break;
          case EDIT_BRIGHTNESS:
            FastOn();
            enable_twist_ = true;
            menu_type_ = MENU_DIM_BLADE;
            dim_revert_ = dim = pow(SaberBase::GetCurrentDimming() / 16384.0, 1/2.5);
            sound_library_.SaySelect();
            break;
          case EDIT_KYBER_CRYSTAL:
            blade_num_ = 2;
            effect_num_ = 0;
            menu_type_ = MENU_STYLE_SETTING_SUB;
            // Gets the current value of Pulsing Crystal, value is annouced and sets to revert argument.
            char argspace_revert[32];
            style_parser.GetArgument(current_preset_.GetStyle(blade_num_), OFF_OPTION_ARG + 2, argspace_revert);
            arg_revert_ = strtol(argspace_revert, NULL, 0);
            sound_library_.SayBool(arg_revert_);
            break;
        }
        break;
      case MENU_CLASH_THRESHOLD:
        sound_library_.SaySelect();
        sound_library_.SayNumber(clash_t_, SAY_DECIMAL);
        SetClashThreshold(clash_t_);
        SaveGlobalState();
        menu_type_ = MENU_SETTING_SUB;
        MenuSave();
        break;
      case MENU_DIM_BLADE:
        SaveGlobalState();
        menu_type_ = MENU_SETTING_SUB;
        UpdateStyle();
        delay(500);
        Off(OFF_FAST);
        MenuSave();
        enable_twist_ = false;
        break;
      case MENU_STYLE_SETTING_SUB:
        char argspace[32];
        style_parser.GetArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2, argspace);
        calc_ = strtol(argspace, NULL, 0);
        IntEdit::SetIntValue(calc_);
        if (NUM_BLADES == 1) blade_num_ = 1;
        switch (set_num_) {
          case PREON_OPTION_ARG:
          case PREON_SIZE_ARG:
            // sound for preon menus chosen below, based on if SFX_preon exists or not
            break;
          default:
            //Saves current state and exits the Crystal Menu when user did not specify a Pulsing Crystal Value
            menu_type_ = MENU_SETTING_SUB;
            current_preset_.Save();
            MenuSave();
            Off(OFF_FAST);
            set_num_ = 0;
            SaberBase::DoPulsingCrystal();
            break;
        }
        switch (set_num_) {
          case STYLE_OPTION_ARG:
            menu_type_ = MENU_STYLE_OPTION;
            arg_revert_ = strtol (argspace, NULL, 0);
            sound_library_.SayOption();
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case STYLE_OPTION2_ARG:
            menu_type_ = MENU_STYLE_OPTION2;
            arg_revert_ = strtol (argspace, NULL, 0);
            sound_library_.SayOption();
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case STYLE_OPTION3_ARG:
            menu_type_ = MENU_STYLE_OPTION3;
            arg_revert_ = strtol (argspace, NULL, 0);
            sound_library_.SayOption();
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case IGNITION_OPTION_ARG:
          case IGNITION_OPTION2_ARG:
            arg_revert_ = strtol (argspace, NULL, 0);
            if (set_num_ == IGNITION_OPTION2_ARG) {
              menu_type_ = MENU_IGNITION_OPTION2;
            } else {
              menu_type_ = MENU_IGNITION_OPTION;
              sound_library_.SayOption();
            }
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case IGNITION_TIME_ARG:
            menu_type_ = MENU_IGNITION_TIME;
            arg_revert_ = strtol (argspace, NULL, 0);
            break;
          case IGNITION_POWER_UP_ARG:
            menu_type_ = MENU_IGNITION_POWER_UP_OPTION;
            arg_revert_ = strtol (argspace, NULL, 0); 
            sound_library_.SayOption();
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case IGNITION_DELAY_ARG:
            menu_type_ = MENU_IGNITION_DELAY;
            arg_revert_ = strtol (argspace, NULL, 0);         
            break;
          case RETRACTION_OPTION_ARG:
          case RETRACTION_OPTION2_ARG:
            char ig[32];
            style_parser.GetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, ig);
            ignite_time_ = strtol(ig, NULL, 0);
            current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, "1"));
            arg_revert_ = strtol(argspace, NULL, 0);
            if (set_num_ == RETRACTION_OPTION2_ARG) {
              menu_type_ = MENU_RETRACTION_OPTION2;
            } else {
              menu_type_ = MENU_RETRACTION_OPTION;
              sound_library_.SayOption();
            }
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case RETRACTION_TIME_ARG:
            menu_type_ = MENU_RETRACTION_TIME;
            char igt[32];
            style_parser.GetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, igt);
            ignite_time_ = strtol(igt, NULL, 0);
            current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, "1"));
            arg_revert_ = strtol(argspace, NULL, 0);
            break;
          case RETRACTION_COOL_DOWN_ARG:
            menu_type_ = MENU_RETRACTION_COOL_DOWN_OPTION;
            char igc[32];
            style_parser.GetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, igc);
            ignite_time_ = strtol(igc, NULL, 0);
            current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, "1"));
            arg_revert_ = strtol(argspace, NULL, 0);
            sound_library_.SayOption();
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case RETRACTION_DELAY_ARG:
            menu_type_ = MENU_RETRACTION_DELAY;
            char igd[32];
            style_parser.GetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, igd);
            ignite_time_ = strtol(igd, NULL, 0);
            current_preset_.SetStyle(blade_num_,style_parser.SetArgument(current_preset_.GetStyle(blade_num_), RETRACTION_TIME_ARG, "1"));
            arg_revert_ = strtol(argspace, NULL, 0);
            break;
          case LOCKUP_POSITION_ARG:
            menu_type_ = MENU_LOCKUP_POSITION;
            ShowColorStyle::SetColor(GetColorArg(blade_num_, LOCKUP_COLOR_ARG));
            //show_lockup_position_.Start(blade_num_);
            break;
          case DRAG_SIZE_ARG:
            menu_type_ = MENU_DRAG_SIZE;
            ShowColorStyle::SetColor(GetColorArg(blade_num_, DRAG_COLOR_ARG));
            //show_drag_size_.Start(blade_num_);
            break;
          case MELT_SIZE_ARG:
            menu_type_ = MENU_MELT_SIZE;
            ShowColorStyle::SetColor(GetColorArg(blade_num_, DRAG_COLOR_ARG));
            //show_drag_size_.Start(blade_num_);
            break;
          case SWING_OPTION_ARG:
            menu_type_ = MENU_SWING_OPTION;
            arg_revert_ = strtol (argspace, NULL, 0);
            sound_library_.SayOption();
            sound_library_.SayNumber(calc_, SAY_WHOLE);
            break;
          case EMITTER_SIZE_ARG:
            menu_type_ = MENU_EMITTER_SIZE;
            ShowColorStyle::SetColor(GetColorArg(blade_num_, EMITTER_COLOR_ARG));
            //show_emitter_size_.Start(blade_num_);
            break;

          case OFF_OPTION_ARG:
            menu_type_ = MENU_OFF_OPTION;
            break;
          case PREON_OPTION_ARG:
            if (!SFX_preon) {
              sound_library_.SaySelectOption();
            } else {
              sound_library_.SaySelect();
              menu_type_ = MENU_PREON_OPTION;
              arg_revert_ = strtol (argspace, NULL, 0);
              sound_library_.SayOption();
              sound_library_.SayNumber(calc_, SAY_WHOLE);
            }
            break;
          case PREON_SIZE_ARG:
            if (!SFX_preon) {
              sound_library_.SaySelectOption();
            } else {
              sound_library_.SaySelect();
              menu_type_ = MENU_PREON_SIZE;
              arg_revert_ = strtol (argspace, NULL, 0);
              ShowColorStyle::SetColor(GetColorArg(blade_num_, PREON_COLOR_ARG));
              //show_emitter_size_.Start(blade_num_);
            }
            break;
          default:
            break;
        }
        break;
      //Saves Pulsing Crystal value
      case MENU_OFF_OPTION:
        menu_type_ = MENU_SETTING_SUB;
        StopSystemMenuBGM();
        for (int i = 0; i < GetNumberOfPresets(); i++) {
          current_preset_.Set(current_preset_.preset_num + 1);
          SetInOut();
        }
        StartSystemMenuBGM();
        MenuSave();
        Off(OFF_FAST);
        SaberBase::DoPulsingCrystal();
        break;

#endif
      default:
        break;
    }
  }

  void MenuDialIncrement(int direction) {
    switch (menu_type_) {
      case MENU_PRESET:
#ifdef FETT263_USE_SETTINGS_MENU
      case MENU_LENGTH:
#endif
        direction *= 5;
        break;
      default:
        break;
    }
    MenuDial(direction);
  }

// Edit Mode Dial
  void MenuDial(int direction) {
    if (menu_type_ != MENU_SWINGON_SPEED && menu_type_ != MENU_CLASH_THRESHOLD){
      StopWavPlayers(); // Instant menu selections
    }

    switch (menu_type_) {
      default:
        break;
      case MENU_PRESET:
        if (SaberBase::IsOn()) {
          if (direction > 0) {
            next_preset_fast();
          } else {
            previous_preset_fast();
          }
        } else {
          int num_presets = GetNumberOfPresets();
          int preset = (current_preset_.preset_num + num_presets * 10 + direction) % num_presets;
          SelectPreset(preset);
        }
        break;
      case MENU_VOLUME:
        ChangeVolume(direction);
        break;
      case MENU_TRACK_PLAYER:
        if (track_player_) {
          track_player_->Stop();
          track_player_.Free();
        }
        track_num_ += direction;
        if (track_num_ > num_tracks_) track_num_ = 1;
        if (track_num_ <= 0) track_num_ = num_tracks_;
        PlayTrack();
        break;
#ifdef FETT263_USE_SETTINGS_MENU
      case MENU_LENGTH:
        if (direction > 0) {
        hybrid_font.PlayCommon(&SFX_plus);
        } else {
         hybrid_font.PlayCommon(&SFX_minus);
        }
        blade_length_ += direction;
        if (blade_length_ >= max_length_) {
          sound_library_.SayMaximum();
          blade_length_ = max_length_;
        }
        if (blade_length_ <= 1) {
          sound_library_.SayMinimum();
          blade_length_ = 1;
        }
        length_edit_length = blade_length_ - 1;
        SetBladeLength(blade_num_, blade_length_);
        SaveState(current_preset_.preset_num);
        break;
      case MENU_GESTURE_SUB:
        gesture_num_ += direction;
        if (gesture_num_ <= 0) gesture_num_ = GESTURE_OPTIONS;
        if (gesture_num_ > GESTURE_OPTIONS) gesture_num_ = 1;
        switch (gesture_num_) {
          default:
            break;
          case GESTURE_TWIST_IGNITION:
            sound_library_.SayTwistIgnition();
            SaberBase::DoTwistIgnite();
            break;
          case GESTURE_TWIST_RETRACTION:
            sound_library_.SayTwistRetraction();
            SaberBase::DoTwistRetract();
            break;
          case GESTURE_SWINGON_IGNITION:
            sound_library_.SaySwingIgnition();
            SaberBase::DoSwingIgnite();
            break;
          case GESTURE_SWINGON_SPEED:
            sound_library_.SaySwingOnSpeed();
            SaberBase::DoSwingOnSpeed();
            break;
          case GESTURE_THRUST_IGNITION:
            sound_library_.SayThrustIgnition();
            SaberBase::DoThrustIgnite();
            break;
          case GESTURE_STAB_IGNITION:
            sound_library_.SayStabIgnition();
            SaberBase::DoStabIgnite();
            break;
        }
        break;
      case MENU_SWINGON:
      case MENU_TWISTON:
      case MENU_THRUSTON:
      case MENU_STABON:
      case MENU_FORCEPUSH:
      case MENU_TWISTOFF:
      case MENU_POWERLOCK:
        choice_ = direction > 0;
        sound_library_.SayBool(choice_);
        break;
      case MENU_SWINGON_SPEED:
        // direction check
        if (direction > 0) {
          sound_library_.SayUp();
        } else {
          sound_library_.SayDown();
        }

        // increment or decrement by 50
        calc_ += direction*50; 
        
        // checks maximum
        if (calc_ >= 600) { 
          sound_library_.SayMaximum();
          calc_ = 600;
        }
        // checks minimum
        if (calc_ <= 200) { 
          sound_library_.SayMinimum();
          calc_ = 200;
        }

        // says the number
        if (calc_%100 == 0) {
          sound_library_.SayNumber(calc_, SAY_WHOLE);
        }
        break;
      case MENU_FORCEPUSH_LENGTH:
      case MENU_CLASH_DETECT:
        if (direction > 0) {
          if (calc_ < 10) {
            sound_library_.SayUp();
            calc_ += 1;
          }
          if (calc_ >= 10) {
            calc_ = 10;
            sound_library_.SayMaximum();
          }
        } else {
          if (calc_ > 1) {
            sound_library_.SayDown();
            calc_ -= 1;
          }
          if (calc_ <= 1) {
            calc_ = 1;
            sound_library_.SayMinimum();
          }
        }
        sound_library_.SayNumber(calc_, SAY_WHOLE);
        break;
      case MENU_MAX_CLASH:
        if (direction > 0) {
          if (calc_ < 16) {
            sound_library_.SayUp();
            calc_ += 1;
          }
          if (calc_ >= 16) {
            calc_ = 16;
            sound_library_.SayMaximum();
          }
        } else {
          if (calc_ > GetCurrentClashThreshold()) {
            sound_library_.SayDown();
            calc_ -= 1;
          }
          if (calc_ <= GetCurrentClashThreshold()) {
            calc_ = GetCurrentClashThreshold();
            sound_library_.SayMinimum();
          }
        }
        sound_library_.SayNumber(calc_, SAY_WHOLE);
        break;
      case MENU_LOCKUP_DELAY:
        if (direction > 0) {
          if (calc_ < 1200) {
            sound_library_.SayUp();
            calc_ += 100;
          }
          if (calc_ >= 1200) {
            calc_ = 1200;
            sound_library_.SayMaximum();
          }
        } else {
          if (calc_ > 200) {
            sound_library_.SayDown();
            calc_ -= 100;
          }
          if (calc_ <= 200) {
            calc_ = 200;
            sound_library_.SayMinimum();
          }
        }
        sound_library_.SayNumber(calc_, SAY_WHOLE);
        sound_library_.SayMillis();
        break;
      case MENU_SETTING_SUB:
        menu_sub_pos_ += direction;
        revert_volume = dynamic_mixer.get_volume();
        if (menu_sub_pos_ <= 0) menu_sub_pos_ = SET_SUBMENUS;
        if (menu_sub_pos_ > SET_SUBMENUS) menu_sub_pos_ = 1;
        switch (menu_sub_pos_) {
          case EDIT_VOLUME:
            sound_library_.SayEditVolume();
            SaberBase::DoVolMenu();
            break;
          case EDIT_CONTROL_SETTINGS:
            sound_library_.SayEditControlSettings();
            SaberBase::DoControlSettings();
            break;
          case EDIT_CLASH_THRESHOLD:
            sound_library_.SayEditClashThreshold();
             SaberBase::DoClashThreshold();
            break;
          case EDIT_BLADE_LENGTH:
            sound_library_.SayEditBladeLength();
            SaberBase::DoBladeLength();
            break;
          case EDIT_BRIGHTNESS:
            sound_library_.SayEditBrightness();
            SaberBase::DoBrightness();
            break;
          case EDIT_KYBER_CRYSTAL:
            sound_library_.SayCrystalPulse();
            SaberBase::DoPulsingCrystal();
            break;
          default:
            SaberBase::DoSettingsMenu();
            break;
        }
        break;
      case MENU_CLASH_THRESHOLD:
        if (direction > 0) {
          hybrid_font.PlayCommon(&SFX_plus);
        } else {
          hybrid_font.PlayCommon(&SFX_minus);
        }
        clash_t_ += direction*0.25;
        if (clash_t_ >= saved_gesture_control.maxclash) {
          sound_library_.SayMaximum();
          clash_t_ = saved_gesture_control.maxclash;
        }
        if (clash_t_ <= 1.0) {
          sound_library_.SayMinimum();
          clash_t_ = 1.0;
        }
        if (fmod(clash_t_, 1.0) == 0) {
          sound_library_.SayNumber(clash_t_, SAY_WHOLE);
        }
        break;
      case MENU_DIM_BLADE:
        if (direction > 0) {
          dim = std::min<float>(dim + 0.1, 1.0);
          if (dim >= 1.0) {
            dim = 1.0;
            sound_library_.SayMaximum();
          } else {
            sound_library_.SayUp();
          }
#endif
        } else {
          dim = std::max<float>(dim - 0.1, 0.2);
          if (dim <= 0.2) {
            dim = 0.2;
            sound_library_.SayMinimum();
          } else {
            sound_library_.SayDown();
          }
        }
        SaberBase::SetDimming(pow(dim, 2.2) * 16384);
        break;

      // Sets argument value for Pulsing Crystal 
      case MENU_STYLE_SETTING_SUB:
        for (int i = 0; i < (int)NELEM(int_arg_menu_); i++) {
          // Set arg_dial_ to the index that corresponds to set_num_ = 18
          arg_dial_ = 18; // 18 would corresnpond to OFF_OPTION_ARG
          
          set_num_ = int_arg_menu_[arg_dial_]; 
          if (style_parser.UsesArgument(current_preset_.GetStyle(blade_num_), set_num_ + 2)) break;
        }
        switch (set_num_) {
          case STYLE_OPTION_ARG:
            sound_library_.SayStyleOptions();
            break;
          case STYLE_OPTION2_ARG:
            sound_library_.SayStyleOptions();
            sound_library_.SayNumber(2, SAY_WHOLE);
            break;
          case STYLE_OPTION3_ARG:
            sound_library_.SayStyleOptions();
            sound_library_.SayNumber(3, SAY_WHOLE);
            break;
          case IGNITION_OPTION_ARG:
            sound_library_.SayIgnitionOptions();
            break;
          case IGNITION_OPTION2_ARG:
            sound_library_.SayIgnitionOptions();
            sound_library_.SayNumber(2, SAY_WHOLE);
            break;
          case IGNITION_TIME_ARG:
            sound_library_.SayIgnitionTime();
            break;
          case IGNITION_POWER_UP_ARG:
            sound_library_.SayPowerUpOptions();
            break;
          case IGNITION_DELAY_ARG:
            sound_library_.SayIgnitionDelay();
            break;
          case RETRACTION_OPTION_ARG:
            sound_library_.SayRetractionOptions();
            break;
          case RETRACTION_OPTION2_ARG:
            sound_library_.SayRetractionOptions();
            sound_library_.SayNumber(2, SAY_WHOLE);
            break;
          case RETRACTION_TIME_ARG:
            sound_library_.SayRetractionTime();
            break;
          case RETRACTION_COOL_DOWN_ARG:
            sound_library_.SayCoolDownOptions();
            break;
          case RETRACTION_DELAY_ARG:
            sound_library_.SayRetractionDelay();
            break;
          case LOCKUP_POSITION_ARG:
            sound_library_.SayClashLockupPosition();
            break;
          case DRAG_SIZE_ARG:
            sound_library_.SayDragSize();
            break;
          case MELT_SIZE_ARG:
            sound_library_.SayMeltSize();
            break;
          case SWING_OPTION_ARG:
            sound_library_.SaySwingOption();
            break;
          case EMITTER_SIZE_ARG:
            sound_library_.SayEmitterSize();
            break;
          case OFF_OPTION_ARG:
            menu_type_ = MENU_OFF_OPTION;
            MenuDial(direction);
            break;
          case PREON_OPTION_ARG:
            sound_library_.SayPreonOptions();
            break;
          case PREON_SIZE_ARG:
            sound_library_.SayPreonSize();
            break;
          default:
            //sound_library_.SaySelectOption();
            break;
        }
        break;

      case MENU_IGNITION_TIME:
      case MENU_RETRACTION_TIME:
      case MENU_IGNITION_DELAY:
      case MENU_RETRACTION_DELAY:
        if (SaberBase::IsOn()) {
          if (direction > 0) {
            calc_ += 100;
            SetInOut();
          } else {
            if (calc_ >= 100) {
              calc_ -= 100;
              if (calc_ >= 100) {
                SetInOut();
                next_event_ = true;
                break;
              } 
            } else {
              calc_ = 0;
              if (menu_type_ == MENU_IGNITION_DELAY || menu_type_ == MENU_RETRACTION_DELAY) {
                sound_library_.SayMinimum();
              } else {
                sound_library_.SayAuto();
              }
              next_event_ = true;
            }
          }
        }
        break;
      case MENU_STYLE_OPTION:
      case MENU_STYLE_OPTION2:
      case MENU_STYLE_OPTION3:
      case MENU_IGNITION_OPTION:
      case MENU_IGNITION_POWER_UP_OPTION:
      case MENU_RETRACTION_OPTION:
      case MENU_RETRACTION_COOL_DOWN_OPTION:
      case MENU_SWING_OPTION:

      // Crystal Menu Enable/Disable Value
      // Enable: calc_ = 1
      // Disable: calc_ = 0
      case MENU_OFF_OPTION:
        if (direction > 0) {
          calc_ = 1;
        } else {
          calc_ = 0;
        }
        EnterBooleanMenu(MENU_OFF_OPTION, calc_);
        SetInOut();
        FreeBladeStyles();
        AllocateBladeStyles();
        break;
      case MENU_PREON_OPTION:
      case MENU_IGNITION_OPTION2:
      case MENU_RETRACTION_OPTION2:
        if (SaberBase::IsOn()) {
          calc_ += (direction * 1000);
          calc_ &= 0x7fff;
          SetInOut();
          sound_library_.SayNumber(calc_, SAY_WHOLE);
        }
        break;
      case MENU_LOCKUP_POSITION:
      case MENU_EMITTER_SIZE:
      case MENU_PREON_SIZE:
        if (direction > 0) {
          calc_ += 1000;
          sound_library_.SayUp();
        } else {
          if (calc_ > 0) {
            calc_ -= 1000;
            sound_library_.SayDown();
          } else {
            if (calc_ < 1000) {
              calc_ = 0;
              sound_library_.SayMinimum();
            }
          }
        }
        IntEdit::SetIntValue(calc_);
        break;
      case MENU_DRAG_SIZE:
      case MENU_MELT_SIZE:
        if (direction > 0) {
          if (calc_ > 1000) {
            calc_ -= 1000;
            sound_library_.SayUp();
          } else {
            if (calc_ < 1000) {
              calc_ = 0;
              sound_library_.SayMaximum();
            }
          }
        } else {
          if (calc_ < 32768) {
            calc_ += 1000;
            sound_library_.SayDown();
          } else {
            if (calc_ >= 32768) {
              calc_ = 32768;
              sound_library_.SayMinimum();
            }
          }
        }
        IntEdit::SetIntValue(calc_);
        break;
#endif
    }
  }

// Edit Mode Undo (ACT Button)
  void MenuUndo() {
    switch (menu_type_) {
      case MENU_TOP:
        sound_library_.SayExit();
        MenuExit();
        break;
#ifdef FETT263_USE_SETTINGS_MENU
#if NUM_BLADES > 1
      case MENU_BLADE_LENGTH:
        menu_type_ = MENU_SETTING_SUB;
        show_preview_.Stop(blade_preview_);
        blade_preview_ = 0;
        MenuCancel();
        break;
#endif
      case MENU_LENGTH:
        menu_type_ = MENU_SETTING_SUB;
        SetBladeLength(blade_num_, length_revert_);
        SaveState(current_preset_.preset_num);
        show_length_.Stop(blade_num_);
        UpdateStyle();
        delay(500);
        Off(OFF_FAST);
        MenuRevert();
        enable_twist_ = false;
        break;
      case MENU_GESTURE_SUB: // sub menu for settings menu
        menu_type_ = MENU_SETTING_SUB;
        MenuReturn();
        break;
      case MENU_SWINGON:
      case MENU_SWINGON_SPEED:
        menu_type_ = MENU_GESTURE_SUB;
        MenuCancel();
        enable_twist_ = false;
        break;
      case MENU_TWISTON:
      case MENU_THRUSTON:
      case MENU_STABON:
      case MENU_TWISTOFF:
        menu_type_ = MENU_GESTURE_SUB;
        MenuCancel();
        break;
      case MENU_CLASH_THRESHOLD:
        menu_type_ = MENU_SETTING_SUB;
        MenuCancel();
        enable_twist_ = false;
        break;
      case MENU_DIM_BLADE:
        SaberBase::SetDimming(pow(dim_revert_, 2.5) * 16384);
        UpdateStyle();
        menu_type_ = MENU_SETTING_SUB;
        SaveGlobalState();
        delay(200);
        Off(OFF_FAST);
        MenuRevert();
        enable_twist_ = false;
        break;
      case MENU_VOLUME:
        menu_type_ = MENU_SETTING_SUB;
        dynamic_mixer.set_volume(revert_volume);
        MenuRevert();
        break;
      case MENU_SETTING_SUB:
#ifdef FETT263_EDIT_SETTINGS_MENU
        MenuExit();
        menu_sub_pos_ = 0;
#else
        menu_type_ = MENU_TOP;
        MenuCancel();
#endif
        break;
#endif
      case MENU_STYLE_SETTING_SUB:
        menu_type_ = MENU_SETTING_SUB;
        MenuCancel();
        delay(200);
        Off(OFF_FAST);
        SaberBase::DoPulsingCrystal();
        break;

      case MENU_OFF_OPTION:
        menu_type_ = MENU_SETTING_SUB;
        RevertInOut();
        SetPresetFast(current_preset_.preset_num);
        MenuRevert();
        delay(200);
        Off(OFF_FAST);
        SaberBase::DoPulsingCrystal();
        break;
    }
  }

  // Exit Edit Mode
  void MenuExit() {
    switch (menu_type_) {
      case MENU_PRESET:
        first_preset();
        sound_library_.SaySelect();
        break;
      case MENU_VOLUME:
        sound_library_.SayExit();
        break;
#ifdef FETT263_EDIT_SETTINGS_MENU
      case MENU_SETTING_SUB:
        in_menu_ = false;
        menu_time_ = millis();
        sound_library_.SayExit();
        break;
#endif
      default:
        break;
    }
    menu_type_ = MENU_TOP;
    menu_ = false;
    in_menu_ = false;
    twist_menu_ = M_PI / 2.5;
    wav_player.Free();
    StopSystemMenuBGM();
    Off(OFF_FAST);
  }

  void MenuSave() {
    if (menu_type_ == MENU_VOLUME) {
      hybrid_font.PlayCommon(&SFX_vmend);
    } else {
      sound_library_.SaySave();
    }

    if (menu_type_ == MENU_SETTING_SUB) {
      SaberBase::DoSettingsMenu();
    }
    if (in_menu_) {
      MenuPrompt();
      MenuDial(0);
    }
  }

  void MenuSelect() {
    sound_library_.SaySelect();
    if (menu_type_ == MENU_SETTING_SUB) SaberBase::DoSettingsMenu();
    MenuPrompt();
    MenuDial(0);
  }

  void MenuConfirm() {
    sound_library_.SayConfirm();
    if (menu_type_ == MENU_SETTING_SUB) SaberBase::DoSettingsMenu();
    MenuPrompt();
    MenuDial(0);
  }

  void MenuCancel() {
    sound_library_.SayCancel();
    if (menu_type_ == MENU_SETTING_SUB) {
      SaberBase::DoSettingsMenu();
    }
    MenuPrompt();
    MenuDial(0);
  }
  
  void MenuReturn() {
    sound_library_.SayReturn();
    if (menu_type_ == MENU_SETTING_SUB) {
      SaberBase::DoSettingsMenu();
    }
    MenuPrompt();
    MenuDial(0);
  }

  void MenuRevert() {
    sound_library_.SayRevert();
    if (menu_type_ == MENU_SETTING_SUB) {
      SaberBase::DoSettingsMenu();
    }
    MenuPrompt();
    MenuDial(0);
  }

  void MenuPrompt() {
    switch (menu_type_) {
      case MENU_TOP:
        sound_library_.SayMainMenu();
        break;
#ifdef FETT263_EDIT_SETTINGS_MENU
#if NUM_BLADES > 1
      case MENU_BLADE_LENGTH:
        sound_library_.SaySelectBlade();
        break;
#endif
      case MENU_GESTURE_SUB:
        sound_library_.SayEditControlSettings();
        break;
      case MENU_SETTING_SUB:
        sound_library_.SaySettingsMenu();
        break;
#endif
      default:
        break;
    }
  }

  enum EditColorMode {
    NONE,
    CC_COLOR_LIST,
    CC_ZOOM_COLOR,
    COLOR_LIST,
    EDIT_COLOR,
    EDIT_BLACK,
    EDIT_WHITE,
    ZOOM_COLOR,
  };

  bool Parse(const char *cmd, const char* arg) override {
    if (PropBase::Parse(cmd, arg)) return true;
    if (!strcmp(cmd, "list_current_tracks")) {
      // Tracks must be in: font/tracks/*.wav
      LOCK_SD(true);
      for (const char* dir = current_directory; dir; dir = next_current_directory(dir)) {
        PathHelper path(dir, "tracks");
        ListTracks(path);
      }
      LOCK_SD(false);
      return true;
    }
    if (!strcmp(cmd, "get_gesture") && arg) {
      saved_gesture_control.Print(arg);
      return true;
    }
    if (!strcmp(cmd, "set_gesture") && arg) {
      saved_gesture_control.Set(arg);
      SaveGestureState();
      return true;
    }
#ifndef DISABLE_DIAGNOSTIC_COMMANDS
    if (!strcmp(cmd, "left") || !strcmp(cmd, "l")) {
      MenuDial(-1);
      return true;
    }
    if (!strcmp(cmd, "right") || !strcmp(cmd, "r")) {
      MenuDial(1);
      return true;
    }
#endif
    return false;
  }

  void ToggleBattleMode() {
    if (!battle_mode_) {
      battle_mode_ = true;
      if (SFX_bmbegin) {
        hybrid_font.PlayCommon(&SFX_bmbegin);
      } else {
        hybrid_font.DoEffect(EFFECT_FORCE, 0);
      }
    } else {
      battle_mode_ = false;
      if (SFX_bmend) {
        hybrid_font.PlayCommon(&SFX_bmend);
      } else {
        beeper.Beep(0.5, 3000);
      }
    }
  }

  void ToggleMultiBlast() {
    swing_blast_ = !swing_blast_;
    if (swing_blast_) {
      if (SFX_blstbgn) {
        hybrid_font.PlayCommon(&SFX_blstbgn);
      } else {
        hybrid_font.SB_Effect(EFFECT_BLAST, 0);
      }
    } else {
      if (SFX_blstend) {
        hybrid_font.PlayCommon(&SFX_blstend);
      } else {
        hybrid_font.SB_Effect(EFFECT_BLAST, 0);
      }
    }
  }

  void ToggleBattleModeMultiBlast() {
    if (battle_mode_ && !swing_blast_) {
      check_blast_ = true;
      last_blast_millis_ = millis();
    }
    swing_blast_ = false;
  }

  void DoAutoMultiBlast() {
    if (check_blast_) {
      if (millis() - last_blast_millis_ < 2000) {
        swing_blast_ = true;
        SaberBase::DoBlast();
      }
      check_blast_ = false;
    }
  }

  void DoIgnition() {
    if(battery_monitor.battery() > IGNITION_LOW_BATTERY_THRESHOLD){
      if (SFX_preon) {
        On();
      } else {
        FastOn();
      }
    } else {
      ProffieOSErrors::low_battery();
      delay(488);  // Stops low battery warning from stacking
    }
  }

  void CheckQuote() {
    if (SFX_quote) {
      if (fusor.angle1() < - M_PI / 3) {
        force_quote_ = !force_quote_;
      }
      ForceQuote();
    } else {
      SaberBase::DoForce();
    }
  }

  void ForceQuote() {
    if (force_quote_) {
      SFX_quote.SelectNext();
      SaberBase::DoEffect(EFFECT_QUOTE, 0);
    } else {
      SaberBase::DoForce();
    }
  }

  // Battery Level
  void DoBattery() {
#if defined (FETT263_SAY_BATTERY_PERCENT) && defined (FETT263_SAY_BATTERY_VOLTS)
    if (fusor.angle1() < - M_PI / 3) {
      sound_library_.SayBatteryVolts();
    } else {
      sound_library_.SayBatteryPercent();
    }
#elif defined(FETT263_SAY_BATTERY_PERCENT)
    sound_library_.SayBatteryPercent();
#elif defined(FETT263_SAY_BATTERY_VOLTS)
    sound_library_.SayBatteryVolts();
#else
    hybrid_font.PlayCommon(&SFX_battery);
#endif
  }

  // Sabertrio - Soundbank Selection / Preset Menu
  void PresetMenu(bool preset_forward_) {
    if(preset_forward_) {
      next_preset();
    } else {
      previous_preset();
    }
  }

  // Reset Preset Colors
  void ResetColors(){
    ToggleColorChangeMode();
    SaberBase::SetVariation(0);
    current_preset_.SetStyle(blade_num_, style_parser.CopyArguments("~", current_preset_.GetStyle(blade_num_),  int_arg_menu_, NELEM(int_arg_menu_)));
    current_preset_.Save();
    UpdateStyle();
  }

  // Go to first Preset
  void first_preset() {
#ifdef SAVE_PRESET
    SaveState(0);
#endif
    SetPreset(0, true);
  }

  void ChangeVolume(int v) {
    float current_volume = dynamic_mixer.get_volume();
    float volume = current_volume + (VOLUME * (v * 0.1));
    if (volume > VOLUME) {
      volume = VOLUME;
      sound_library_.SayMaximumVolume();
    } else if (volume < (VOLUME * 0.1)) {
      volume = VOLUME * 0.1;
      sound_library_.SayMininumVolume();
    } else {
      if (v > 0) {
        STDOUT.println("Volume up");
        hybrid_font.PlayCommon(&SFX_volup);
      } else {
        STDOUT.println("Volume Down");
        hybrid_font.PlayCommon(&SFX_voldown);
      }
    }
    STDOUT.print("Current Volume: ");
    STDOUT.println(dynamic_mixer.get_volume());
    dynamic_mixer.set_volume(volume);
    SaberBase::DoEffect(EFFECT_VOLUME_LEVEL, 0);
  }

  RefPtr<BufferedWavPlayer> wav_player;

  float current_menu_angle_ = 0.0;
  float current_twist_angle_ = 0.0;
  float clash_t_ = 2.00;
#ifdef FETT263_USE_SETTINGS_MENU
  int blade_length_;
  int max_length_;
  float dim;
  float dim_revert_;
#endif

/*=== Button Mapping ===*/
  bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
    switch (EVENTID(button, event, modifiers)) {

/* START of MODIFICATION by Sabertrio for button mapping. [1/1] */
/* Defines the button mapping style that is used across all Sabertrio sabers. */
#ifdef BLADE_DETECT_PIN
      case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_ON, MODE_ANY_BUTTON | MODE_OFF):
        // Might need to do something cleaner, but let's try this for now.
        blade_detected_ = true;
#ifdef FETT263_SAVE_GESTURE_OFF
        RestoreGestureState();
#else
        saved_gesture_control.gestureon = true;
#endif
        FindBladeAgain();
        SaberBase::DoBladeDetect(true);
        return true;

      case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_BLADE_DETECT, EVENT_LATCH_OFF, MODE_ANY_BUTTON | MODE_OFF):
        // Might need to do something cleaner, but let's try this for now.
        Off();
        blade_detected_ = false;
        SaberBase::DoNoBlade();
#ifdef FETT263_SAVE_GESTURE_OFF
        SaveGestureState();
#endif
        saved_gesture_control.gestureon = false;
        FindBladeAgain();
        SaberBase::DoBladeDetect(false);
        return true;
#endif

      case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_OFF):
        if (menu_ && menu_type_ == MENU_TRACK_PLAYER) {
          menu_ = false;
          menu_type_ = MENU_TOP;
          sound_library_.SayUp();
          return true;
        }
        return false;

#ifndef FETT263_MOTION_WAKE_POWER_BUTTON
      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
        if (menu_) return false;
        SaberBase::RequestMotion();
        saber_off_time_millis_ = millis();
        return true;
#endif

// 2 Button Controls
      case EVENTID(BUTTON_AUX, EVENT_PRESSED, MODE_OFF):
        SaberBase::RequestMotion();
        saber_off_time_millis_ = millis();
        if (!preset_menu_ && !in_menu_) {
          sound_library_.SayResetBeep();  // Beep to prompt user to release aux button for system reset
        }
        return true;

      case EVENTID(BUTTON_POWER, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_AUX, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_AUX2, EVENT_LATCH_ON, MODE_OFF):
      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF):
      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_OFF):
        if (in_menu_) {
          sound_library_.ClearSoundQueue();
          MenuDial(-1);
          return true;

        } else if (preset_menu_) {
          preset_forward_= false;
          PresetMenu(preset_forward_);
          return true;

        } else {
          if (!blade_detected_) {
            Off();
            hybrid_font.PlayCommon(&SFX_no_blade);
            SaberBase::DoNoBlade();
            return true;
          } else {
            if (millis() - menu_time_ > 1000) {
              DoInteractivePreon();
            }
          }
        }
        return true;

      // Gesture Sleep Toggle
      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_OFF | BUTTON_POWER):
        if (!in_menu_) {
          if (!saved_gesture_control.gestureon) {
            saved_gesture_control.twistoff = true;
            saved_gesture_control.gestureon = true;
            sound_library_.SayGesturesOn();
          } else {
            saved_gesture_control.gestureon = false;
            saved_gesture_control.twistoff = false;
            sound_library_.SayGesturesOff();
          }
          SaveGestureState();
        }
        return true;

#ifndef FETT263_DISABLE_COPY_PRESET
      case EVENTID(BUTTON_AUX, EVENT_CLICK_LONG, MODE_OFF | BUTTON_POWER):
        StopWavPlayers();  // Stops reset beep
        if (menu_) return true;
        CopyPreset(true);
        return true;
#endif

      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF | BUTTON_POWER):
      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON | BUTTON_POWER):
        StopWavPlayers();  // Stops reset beep
        if (!mode_volume_) {
          StartOrStopTrack();
        }
        return true;
        
      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_OFF| BUTTON_AUX):
        if (menu_) return true;
        if (in_menu_) return false;
        StopWavPlayers();  // Stops reset beep
        if (!preset_menu_ && blade_detected_) {
          if(battery_monitor.battery() > IGNITION_LOW_BATTERY_THRESHOLD){
            hybrid_font.PlayCommon(&SFX_mute);
            delay(500);
            if (SetMute(true)) {
              unmute_on_deactivation_ = true;
              On();
            }
          } else {
            ProffieOSErrors::low_battery();
            delay(488);
          }
          return true;
        } else if (!preset_menu_ && !blade_detected_) {
          hybrid_font.PlayCommon(&SFX_no_blade);
          SaberBase::DoNoBlade();
          return true;
        }
        return false;

      case EVENTID(BUTTON_AUX, EVENT_HELD_MEDIUM, MODE_OFF | BUTTON_POWER):
        StopWavPlayers();  // Stops reset beep
        
      case EVENTID(BUTTON_AUX, EVENT_HELD_LONG, MODE_OFF | BUTTON_POWER):
        StopWavPlayers();  // Stops reset beep
#ifdef FETT263_USE_SETTINGS_MENU
        // Enter Edit Mode
        if (!menu_ && !in_menu_ && !preset_menu_) {
          StartEditMode();
          in_menu_ = true;
          menu_time_ = millis();
          system_menu_bgm_switch_ = true;
          MenuDial(1);
        }
#else
        // If Edit Mode Menu Disabled Save .ini files for SD card editing
        if (menu_) return true;
        GenerateIniFiles();
        sound_library_.SaySave();
#endif
        return true;

      case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):
        if (menu_) return true;
        if (CheckShowColorCC()) return true;
        return false;

      case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ON):
#ifndef DISABLE_COLOR_CHANGE
        if (CheckShowColorCC()) {
          ResetColors();
          sound_library_.SayRevert();
          return true;
        }
#endif
        return false;

      case EVENTID(BUTTON_AUX, EVENT_HELD_LONG, MODE_ON):
        if (CancelShowColor()) return false;
        if (menu_) {
#ifdef FETT263_EDIT_SETTINGS_MENU
        if (menu_type_ == MENU_SETTING_SUB) {
          MenuChoice();
#else
          if (menu_type_ == MENU_TOP) {
#endif
            MenuChoice();
          }
          return true;
        }
        return true;

#ifndef FETT263_DISABLE_CHANGE_STYLE
      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_ON | BUTTON_AUX):
        if (menu_ || CheckShowColorCC()) return true;
        ChangeStyleNumberAllBlades(fusor.angle1() < - M_PI / 3 ? -1 : 1);
        hybrid_font.PlayCommon(&SFX_ccchange);
        return true;
#endif

#ifndef FETT263_DISABLE_CHANGE_FONT
      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_OFF | BUTTON_AUX):
        if (menu_) return true;
        ChangeFont(fusor.angle1() < - M_PI / 3 ? -1 : 1);
        return true;
#endif

      case EVENTID(BUTTON_AUX, EVENT_HELD_LONG, MODE_ON | BUTTON_POWER):
        if (menu_ || CheckShowColorCC()) return true;
        if (saved_gesture_control.powerlock) {
          wav_player.Free();
          battle_mode_ = false;
          Off();
        }
        return true;

      case EVENTID(BUTTON_POWER, EVENT_HELD_MEDIUM, MODE_ON):
#ifndef DISABLE_COLOR_CHANGE
        if (CheckShowColorCC()) {
          ResetColors();
          sound_library_.SayRevert();
          return true;
        }
#endif
        if (in_menu_) {
          MenuUndo();
          return true;
        }
#ifdef FETT263_HOLD_BUTTON_OFF
        if (!swinging_) {
          check_blast_ = false;
          swing_blast_ = false;
          Off();
          saber_off_time_millis_ = millis();
          battle_mode_ = false;
          return true;
        }
#endif
        return false;

      case EVENTID(BUTTON_POWER, EVENT_HELD_LONG, MODE_ON):
        if (CheckShowColorCC()) return true;
        if (in_menu_) {
          MenuUndo();
          return true;
        }
        return false;

      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON):
      case EVENTID(BUTTON_POWER, EVENT_LATCH_OFF, MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_LATCH_OFF, MODE_ON):
      case EVENTID(BUTTON_AUX2, EVENT_LATCH_OFF, MODE_ON):
        if (CheckShowColorCC()) return true;
        if(in_menu_) {
          sound_library_.ClearSoundQueue();
          MenuDial(-1);
          return true;
        } else {
#ifndef FETT263_HOLD_BUTTON_OFF
          if (!swinging_) {
            check_blast_ = false;
            swing_blast_ = false;
            if (!saved_gesture_control.powerlock) {
              Off();
              saber_off_time_millis_ = millis();
              battle_mode_ = false;
            }
          }
#endif
          return true;
        }

      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_ON):
        if (in_menu_) {
          sound_library_.ClearSoundQueue();
          MenuDial(1);
          return true;
        }

        if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_NONE) {
          if (millis() - kyber_time_ >1000) {
            DoInteractiveBlast();
            return true;
          }
          return true;
        }

      case EVENTID(BUTTON_AUX, EVENT_HELD_MEDIUM, MODE_ON):
        if (in_menu_) {
          MenuChoice();
          return true;
        }

#ifndef DISABLE_COLOR_CHANGE
        if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) {
          ToggleColorChangeMode();
          MenuSave();
          return true;
        }
#endif
        if (SaberBase::GetColorChangeMode() == SaberBase::COLOR_CHANGE_MODE_NONE) {
          CheckQuote();
          return true;
        }
        return false;

      case EVENTID(BUTTON_POWER, EVENT_CLICK_LONG, MODE_ON):
        if (CancelShowColor()) return true;
        if (in_menu_) {
          MenuDial(-1);
          return true;
        }
        return false;

#if !defined(FETT263_DISABLE_MULTI_BLAST) && !defined(FETT263_DISABLE_MULTI_BLAST_TOGGLE)
      case EVENTID(BUTTON_AUX, EVENT_CLICK_LONG, MODE_ON):
        if (menu_ || CancelShowColor()) return true;
        ToggleMultiBlast();
        return true;
#endif

      case EVENTID(BUTTON_POWER, EVENT_CLICK_SHORT, MODE_ON | BUTTON_AUX):
        if (menu_ || CancelShowColor()) return true;
        if (fusor.angle1() > M_PI / 3) {
          /* By default, power safe is disabled in the Sabertrio Proffie Preconfiguration.
          The commented out line below is to ensure this feature is not accidently accessed when toggling kyber dial.*/
          //SaberBase::DoEffect(EFFECT_POWERSAVE, 0);
        } else {
#ifndef DISABLE_COLOR_CHANGE
          if (SaberBase::GetColorChangeMode() != SaberBase::COLOR_CHANGE_MODE_NONE) {
            ToggleColorChangeMode();
            MenuSave();
            return true;
          } else {
            SaberBase::DoKyber();
            ToggleColorChangeMode();
            kyber_time_ = millis();
          }
#endif
        }
        return true;

      // Lockup
      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_AUX):
        if (menu_ || CheckShowColorCC()) return true;
        if (!SaberBase::Lockup()) {
          if (fusor.angle1() < - M_PI / 8) {
            SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
            SaberBase::DoBeginLockup();
          } else {
            SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
            SaberBase::DoBeginLockup();
          }
          check_blast_ = false;
          swing_blast_ = false;
          return true;
        }
        return true;
        break;

      case EVENTID(BUTTON_POWER, EVENT_SECOND_HELD, MODE_ON):
        if (menu_ || CheckShowColorCC()) return true;
        SaberBase::SetLockup(SaberBase::LOCKUP_LIGHTNING_BLOCK);
        check_blast_ = false;
        swing_blast_ = false;
        SaberBase::DoBeginLockup();
        return true;

      case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_AUX):
        if (menu_ || CheckShowColorCC()) return true;
        if (!SaberBase::Lockup()) {
          if (fusor.angle1() < - M_PI / 4) {
            SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
          } else {
            SaberBase::SetLockup(SaberBase::LOCKUP_MELT);
          }
          check_blast_ = false;
          swing_blast_ = false;
          SaberBase::DoBeginLockup();
          return true;
        }
        return true;
        break;

      // Off functions
      // Handles PresetMenu Exit and second case for PowerOn
      case EVENTID(BUTTON_POWER, EVENT_HELD_LONG, MODE_OFF):
        if (in_menu_) {
          MenuUndo();
          return true;
        }

        if (preset_menu_) {
          preset_menu_ = false;
          hybrid_font.PlayCommon(&SFX_boot);
          StopMenuBGM();
          return true;

        } else {
          if (menu_) {
            return false;
          }
          if (!blade_detected_) {
            Off();
            hybrid_font.PlayCommon(&SFX_no_blade);
            SaberBase::DoNoBlade();
            return true;
          } else {
            if (millis() - menu_time_ > 1000) {
              DoIgnition();
            }
          }
        }
      return true;

      case EVENTID(BUTTON_AUX, EVENT_CLICK_SHORT, MODE_OFF):
        if (in_menu_) {
          sound_library_.ClearSoundQueue();
          MenuDial(1);
          return true;
        }
        if (preset_menu_) {
          preset_forward_ = true;
          PresetMenu(preset_forward_);
        } else {
          StopWavPlayers();  // Stops reset beep
          SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
        }
        return true;

      case EVENTID(BUTTON_AUX, EVENT_CLICK_LONG, MODE_OFF):
        if (!in_menu_ && !preset_menu_) {
          NVIC_SystemReset(); // Reset the system (used to reinitialise OLED screen)
        }
        return true;

      case EVENTID(BUTTON_AUX, EVENT_HELD_LONG, MODE_OFF):
        if (in_menu_) {
          MenuChoice();
          return true;
        }
        if (!preset_menu_) {
          preset_menu_ = true;
          delay(800);
          preset_forward_ = true;
          hybrid_font.PlayCommon(&SFX_fontmenu);
          delay(1500);
          StartMenuBGM();
          SaberBase::DoNewFont();
        } else {
          StopMenuBGM();
          preset_menu_ = false;
          hybrid_font.PlayCommon(&SFX_boot);
        }
        return true;

      // Gesture Controls (not button specific)
      case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_ON):
        if (wav_player && wav_player->isPlaying()) {
          current_menu_angle_ = fusor.angle2();
          return false;
        }
        if (color_mode_ == CC_COLOR_LIST) {
          dial_ = (dial_ + 1) % NELEM(color_list_);
          ShowColorStyle::SetColor(Color16(color_list_[dial_].color));
          hybrid_font.PlayCommon(&SFX_ccchange);
          return true;
        }
        if (in_menu_ && enable_twist_) {
          MenuDial(1);
          return true;
        }
        return false;

      case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_ON):
        if (wav_player && wav_player->isPlaying()) {
          current_menu_angle_ = fusor.angle2();
          return false;
        }
        if (color_mode_ == CC_COLOR_LIST) {
          if (dial_ <= 0) dial_ = NELEM(color_list_);
          dial_ = dial_ - 1;
          ShowColorStyle::SetColor(Color16(color_list_[dial_].color));
          hybrid_font.PlayCommon(&SFX_ccchange);
          return true;
        }
        if (in_menu_ && enable_twist_) {
          MenuDial(-1);
          return true;
        }
        return false;

      case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_OFF):
        if (wav_player && wav_player->isPlaying()) {
          current_menu_angle_ = fusor.angle2();
          return false;
        }
        if (in_menu_ && enable_twist_) {
          MenuDial(1);
          return true;
        }
        return false;

      case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_OFF):
        if (wav_player && wav_player->isPlaying()) {
          current_menu_angle_ = fusor.angle2();
          return false;
        }
        if (in_menu_ && enable_twist_) {
          MenuDial(-1);
          return true;
        }
        return false;

      case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_ON):
        if (menu_ || CheckShowColorCC()) return true;
        if (swing_blast_) {
          SaberBase::DoBlast();
          return true;
        } else {
          DoAutoMultiBlast();
        }
        return true;

      case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_ON | BUTTON_POWER):
        if (wav_player && wav_player->isPlaying()) {
          current_menu_angle_ = fusor.angle2();
          return false;
        }
        if (in_menu_ && enable_twist_) {
          MenuDialIncrement(1);
          return true;
        }
        if (swinging_) {
          return false;
        }
      return false;

      case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_ON | BUTTON_POWER):
        if (wav_player && wav_player->isPlaying()) {
          current_menu_angle_ = fusor.angle2();
          return false;
        }
        if (in_menu_) {
          MenuDialIncrement(-1);
          return true;
         }
        if (swinging_) {
          return false;
        }
        return false;

      case EVENTID(BUTTON_NONE, EVENT_TWIST_RIGHT, MODE_OFF | BUTTON_POWER):
        if (wav_player && wav_player->isPlaying()) {
          current_menu_angle_ = fusor.angle2();
          return false;
        }
        if (menu_) {
          if (menu_type_ == MENU_TRACK_PLAYER) {
            track_mode_ = PLAYBACK_ROTATE;
            sound_library_.SayRotate();
            return true;
          } else {
            MenuDialIncrement(1);
            return true;
          }
        }
        return false;

      case EVENTID(BUTTON_NONE, EVENT_TWIST_LEFT, MODE_OFF | BUTTON_POWER):
        if (wav_player && wav_player->isPlaying()) {
          current_menu_angle_ = fusor.angle2();
          return false;
        }
        if (menu_) {
          if (menu_type_ == MENU_TRACK_PLAYER) {
            track_mode_ = PLAYBACK_LOOP;
            sound_library_.SayLoop();
            return true;
          } else {
            MenuDialIncrement(-1);
            return true;
          }
        }
        return false;

      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF):
        if (menu_) return true;
        SaberBase::DoEffectR(EFFECT_OFF_CLASH);
        return true;

      // Auto Lockup Mode
      case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON):
        if (menu_ || SaberBase::Lockup() || CheckShowColorCC()) return true;
        // Allow normal clashes if blade continues to swing after clash detected in Battle Mode
        if (!battle_mode_ || swinging_) {
          clash_impact_millis_ = millis();
          SaberBase::DoClash();
          return true;
        }
        clash_impact_millis_ = millis();
        check_blast_ = false;
        swing_blast_ = false;
        if (fusor.angle1() < - ((M_PI / 2) - 0.25)) {
          SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
          SaberBase::DoBeginLockup();
          auto_melt_on_ = true;
          return true;
        }
        clash_type_ = CLASH_BATTLE_MODE;
        return true;

      case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON):
        if (menu_ || SaberBase::Lockup() || CheckShowColorCC()) return true;
        clash_impact_millis_ = millis();
        check_blast_ = false;
        swing_blast_ = false;
        if (!swinging_) {
          if (!battle_mode_) {
            SaberBase::DoStab();
            return true;
          }
          if (fusor.angle1() < - M_PI / 4) {
            SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
          } else {
            SaberBase::SetLockup(SaberBase::LOCKUP_MELT);
          }
          auto_melt_on_ = true;
          SaberBase::DoBeginLockup();
        }
        return true;

      case EVENTID(BUTTON_NONE, EVENT_SWING, MODE_OFF):
        if (!saved_gesture_control.gestureon) return true;
        if (!saved_gesture_control.swingon) return true;
        if (preset_menu_) return false;
        if (!menu_) {
          wav_player.Free();
          if (blade_detected_) {
            if(battery_monitor.battery() > IGNITION_LOW_BATTERY_THRESHOLD){
              FastOn();
            } else {
              ProffieOSErrors::low_battery();
              delay(488);
            }
          } else {
            Off();
            hybrid_font.PlayCommon(&SFX_no_blade);
            SaberBase::DoNoBlade();
          }
        }
        return true;

      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON):
        if (!saved_gesture_control.gestureon) return true;
        if (!saved_gesture_control.twistoff) return true;
        if (menu_ || CheckShowColorCC()) return true;
        if (millis() - last_twist_ > 1000) {
          check_blast_ = false;
          swing_blast_ = false;
          battle_mode_ = false;
          Off();
          last_twist_= millis();
        }
        saber_off_time_millis_ = millis();
        battle_mode_ = false;
        return true;

      case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_OFF):
        if (!saved_gesture_control.gestureon) return true;
        if (!saved_gesture_control.twiston) return true;
        if (preset_menu_) return false;
        // Delay twist events to prevent false trigger from over twisting
        if (!menu_) {
          wav_player.Free();
          if (millis() - last_twist_ > 1000 && millis() - saber_off_time_ > 1000) {
            if (blade_detected_) {
              if(battery_monitor.battery() > IGNITION_LOW_BATTERY_THRESHOLD){
                On();
              } else {
                ProffieOSErrors::low_battery();
                delay(488);
              }
            } else {
              Off();
              hybrid_font.PlayCommon(&SFX_no_blade);
              SaberBase::DoNoBlade();
            }
            last_twist_ = millis();
          }
#ifndef FETT263_TWIST_ON_NO_BM
          battle_mode_ = true;
#endif
        }
        return true;

      case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_OFF):
        if (!saved_gesture_control.gestureon) return true;
        if (!saved_gesture_control.stabon) return true;
        if (preset_menu_) return false;
        if (!menu_) {
          wav_player.Free();
          if (blade_detected_) {
            if(battery_monitor.battery() > IGNITION_LOW_BATTERY_THRESHOLD){
              FastOn();
            } else {
              ProffieOSErrors::low_battery();
              delay(488);
            }
          } else {
            Off();
            hybrid_font.PlayCommon(&SFX_no_blade);
            SaberBase::DoNoBlade();
          }
        }
        return true;

      case EVENTID(BUTTON_NONE, EVENT_THRUST, MODE_OFF):
        if (!saved_gesture_control.gestureon) return true;
        if (!saved_gesture_control.thruston) return true;
        if (preset_menu_) return false;
        if (!menu_) {
          wav_player.Free();
          if (blade_detected_) {
            if(battery_monitor.battery() > IGNITION_LOW_BATTERY_THRESHOLD){
              FastOn();
            } else {
              ProffieOSErrors::low_battery();
              delay(488);
            }
          } else {
            Off();
            hybrid_font.PlayCommon(&SFX_no_blade);
            SaberBase::DoNoBlade();
          }
        }
        return true;

      case EVENTID(BUTTON_NONE, EVENT_PUSH, MODE_ON):
        if (menu_ || CheckShowColorCC()) return true;
        if (!saved_gesture_control.forcepush) return true;
        if (FORCE_PUSH_CONDITION &&
           millis() - last_push_millis_ > 1000) {
          if (SFX_push) {
            hybrid_font.PlayCommon(&SFX_push);
          } else {
            hybrid_font.DoEffect(EFFECT_FORCE, 0);
          }
          last_push_millis_ = millis();
        }
        return true;

      // Events that needs to be handled regardless of what other buttons
      // are pressed.
      case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
      case EVENTID(BUTTON_AUX, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
        if (SaberBase::Lockup()) {
          SaberBase::DoEndLockup();
          SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
          return true;
        }
    }
    return false;
  }
/* END of MODIFICATION by Sabertrio for button mapping. [1/1] */

  void SB_Effect(EffectType effect, float location) override {
    switch (effect) {
      case EFFECT_INTERACTIVE_BLAST: hybrid_font.PlayCommon(&SFX_blast); return;
      case EFFECT_TRACK: PlayEffectTrack(); return;
      case EFFECT_QUOTE: hybrid_font.PlayCommon(&SFX_quote); return;
      case EFFECT_NEXT_QUOTE:
        SFX_quote.SelectNext();
        hybrid_font.PlayCommon(&SFX_quote);
        return;
      case EFFECT_FAST_OFF:
      case EFFECT_OFF:
        if (SaberBase::IsOn()) {
          if (effect == EFFECT_FAST_OFF) {
            Off(OFF_FAST);
          } else {
            Off();
          }
          saber_off_time_millis_ = millis();
        }
        return;
      case EFFECT_SECONDARY_RETRACTION:
        if (SaberBase::IsOn()) {
          hybrid_font.PlayCommon(&SFX_in);
        }
        return;
      case EFFECT_POWERSAVE:
        if (SFX_dim) {
          hybrid_font.PlayCommon(&SFX_dim);
        } else {
          beeper.Beep(0.5, 3000);
        }
        return;
      case EFFECT_BATTERY_LEVEL:
        DoBattery();
        return;
      case EFFECT_INTERACTIVE_PREON:
        preon_effect_ = true;
        return;
      case EFFECT_FAST_ON:
        if (SaberBase::IsOn()) {
          if (!preon_effect_ && SFX_faston) {
            hybrid_font.PlayCommon(&SFX_faston);
          }
        } else {
          if(battery_monitor.battery() > IGNITION_LOW_BATTERY_THRESHOLD){
            FastOn();
            preon_effect_ = false;
          } else {
            ProffieOSErrors::low_battery();
            delay(488);
          }
        }
        return;
      case EFFECT_ON:
        if(battery_monitor.battery() > IGNITION_LOW_BATTERY_THRESHOLD){
          if (!SaberBase::IsOn()) {
            On();
          }
        } else {
          ProffieOSErrors::low_battery();
          delay(488);
        }
        return;
      case EFFECT_SECONDARY_IGNITION:
        if (SaberBase::IsOn()) {
          hybrid_font.PlayCommon(&SFX_out);
        }
        return;
      case EFFECT_TRANSITION_SOUND: hybrid_font.PlayCommon(&SFX_tr); return;
      case EFFECT_SOUND_LOOP: SoundLoop(); return;
      case EFFECT_BEGIN_BATTLE_MODE:
        if (!battle_mode_) ToggleBattleMode();
        return;
      case EFFECT_END_BATTLE_MODE:
        if (battle_mode_) ToggleBattleMode();
        return;
      case EFFECT_BEGIN_AUTO_BLAST:
        if (!swing_blast_) ToggleMultiBlast();
        return;
      case EFFECT_END_AUTO_BLAST:
        if (swing_blast_) ToggleMultiBlast();
        return;
      default:
        break; // avoid compiler warnings
    }
  }

private:
  bool swing_blast_ = false; // Multi-Blast Mode (Swing = Blast Deflect)
  bool check_blast_ = false; // Check if Multi-Blast mode should be enabled (Battle Mode)
  bool auto_lockup_on_ = false; // Battle Mode Lockup active
  bool auto_melt_on_ = false; // Battle Mode Melt/Drag active
  bool battle_mode_ = false; // Battle Mode active

  // Sabertrio Proffie Preconfiguration exclusive variables
  bool mode_volume_ = false;
  bool preset_menu_ = false;
  bool preset_forward_;
  bool in_menu_ = false;
  bool enable_twist_ = false;

  uint32_t last_twist_ = millis();
  uint32_t saber_off_time_ = millis();
  uint32_t menu_time_ = millis();
  uint32_t kyber_time_ = millis();
  float revert_volume;

  bool preon_effect_ = false; // used for interactive preon, must be reset with EFFECT_FAST_ON
  bool menu_ = false; // Edit Mode / Menu System active
  bool force_quote_ = false; // Quote Player active (in place of force effect)
  uint32_t thrust_begin_millis_; // Thrust timer
  uint32_t push_begin_millis_; // Push timer
  uint32_t clash_impact_millis_; // Clash timer
  uint32_t last_push_millis_; // Last Push (to prevent gesture spamming)
  uint32_t last_blast_millis_; // Last Blast (for Battle Mode Multi-Blast detection)
  uint32_t saber_off_time_millis_; // Off timer
  uint32_t restart_millis_; // Used to time restarts to show preon timing
  uint32_t bgm_begin_millis; // Timer for BGM in soundbank selection menu
  uint32_t bgm_duration; // Duration of BGM in soundbank selection menu
  bool system_menu_bgm_switch_ = false; // Switch for BGM in system menu
  ClashType clash_type_ = CLASH_NONE;
  MenuType menu_type_ = MENU_TOP;
  int menu_top_pos_ = 0; // Top menu dial position
  int menu_sub_pos_ = 0; // Sub menu dial position
  TrackMode track_mode_ = PLAYBACK_OFF;
  int track_num_; // Track Number for Track Player
  int num_tracks_; // Number of Tracks Found
  int ignite_time_; // Ignition timer for Edit Mode retraction preview
  int dial_ = -1; // Menu dial "tick"
  int sub_dial_; // Sub menu dial "tick"
  int arg_dial_; // Argument Sub menu dial "tick"
  int gesture_num_;
  float twist_menu_ = M_PI / 2.5; // default Twist Right / Left sensitivity
  bool choice_ = false;

  // Edit Mode selection confirmation
  // for True/False control when deleting, disabling/enabling or copying
  bool off_event_ = false; // Do off event in Edit Mode
  bool restart_ = false; // Ignite blade after off event in Edit Mode
  bool next_event_ = false;

  // Do next event in Edit Mode, allows an action/wav to complete before
  // "next event" begins, for use with choreography and ignition/retraction previews where menu sound
  // would otherwise be truncated by change in state
  EditColorMode color_mode_;
  bool edit_color_ = false; // Color Editing Mode active
  float hsl_angle_ = 0.0; // HSL angle for Color Editing
  int font_num_; // Font number from list_fonts array for use in Edit Mode dial

#ifdef FETT263_USE_SETTINGS_MENU
  int blade_preview_ = 0; // Blade number for "preview" style
  int blade_num_; // Active Blade Number for editing
  int length_revert_; // Original Blade Length for Revert
  // Calculated value for IntArg (Settings Arguments)
  // used to add or subtract from original saved value by dial
  int calc_;
  int effect_num_; // Effect Arg Number
  int set_num_; // Settings Arg Number
  int style_revert_; // Original Style Number for Revert
  int arg_revert_; // Original Arg vale for Revert
  int count; // Counter for Pulsing Crystal Menu
#endif
};
// end of button map
