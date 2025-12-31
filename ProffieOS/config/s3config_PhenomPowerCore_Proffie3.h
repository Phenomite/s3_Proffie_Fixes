// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 155;
const unsigned int currentLedsInStrip = 114; //32 inch blade at arduino patch time
#define VOLUME 2550
#define BOOT_VOLUME 250 //Low volume after upload
#define CLASH_THRESHOLD_G 1.25
#define FETT263_SWING_ON_SPEED 320
#define AUDIO_CLASH_SUPPRESSION_LEVEL 5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
// #define ENABLE_SSD1306
// #define OLED_FLIP_180
#define NO_REPEAT_RANDOM
#define KILL_OLD_PLAYERS
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
#define MOTION_TIMEOUT 60 * 1 * 1000 // 1 min
#define IDLE_OFF_TIME 60 * 1 * 1000 // 1 min
#define BLADE_DETECT_PIN 6
#define SAVE_PRESET
#define COLOR_CHANGE_DIRECT
#define ENABLE_ALL_EDIT_OPTIONS
#define ENABLE_SERIAL //BLE
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
#endif

#ifdef CONFIG_PROP
#include "../props/saber_sabertrio_buttons.h"
//#include "../props/saber_fett263_buttons.h"
#endif

// Modified for OS7.12
#ifdef CONFIG_PRESETS
#include "all_styles.h"


/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/
/*---------------------------------ENABLED FONTS----------------------------------*/
/*--------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------*/

// S3 PowerCore blade array
Preset blade[] = {

  // #######################################
  // ##           CANON DEFAULT           ##
  // #######################################

  { "Ksith-HIGHGROUND;common","tracks/track1.wav",
  StylePtr<Style_Menorah>(), StylePtr<Switch_Blue>(), "menorah kenobi"},

  { "Ksith-ECHOES;common","tracks/track1.wav",
  StylePtr<Style_BlueHumpFlicker>(), StylePtr<Switch_Blue>(), "anakin ahsoka"},

  { "KP-Ezra-Stdv2;common", "tracks/swrebelstheme.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "staple sword std"},

  { "KP-Ezra-Trainingv2;common", "tracks/swrebelstheme.wav",
  StylePtr<Style_BlueHumpFlicker>(), StylePtr<Switch_Blue>(), "staple sword training"},

  { "KSith-GRANDHUNTER;common", "tracks/combat1.wav",
  StylePtr<Style_RedAngryAudio>(), StylePtr<Switch_Red>(), "ks grandhunter"},

  { "Ksith-DARKSABERMANDO;common","tracks/track1.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "mando darksaber"},

  { "Ksith-GRANDMASTER;common", "tracks/track1.wav",
  StylePtr<Style_GreenHumpFlicker>(), StylePtr<Switch_Green>(), "yoda bootup"},

  { "Ksith-COUNT;common","tracks/track1.wav",
  StylePtr<Style_RedHumpFlicker>(), StylePtr<Switch_Red>(), "count dooku"},

  { "Ksith-MACE;common","tracks/track1.wav",
  StylePtr<Style_PurpleHumpFlicker>(), StylePtr<Switch_Magenta>(), "mace windu"},

  { "Ksith-THEBALANCE;common","tracks/track1.wav",
  StylePtr<Style_GreenHumpFlicker>(), StylePtr<Switch_Green>(), "the balance"},

  { "KP-SHOCKBATON;common", "tracks/track1.wav",
  StylePtr<Style_PhenomElectroStaff>(), StylePtr<Switch_White>(), "shockbaton"},

  { "Ksith-DESTINY;common","tracks/track1.wav",
  StylePtr<Style_YellowHumpFlicker>(), StylePtr<Switch_Yellow>(), "rey tros"},

  { "Starfall-HIGHREPUBLIC;common", "tracks/track1.wav",
  StylePtr<Style_YellowHumpFlicker>(), StylePtr<Switch_Yellow>(), "high republic"},


  // #######################################
  // ##              KSITH                ##
  // #######################################

  { "Ksith-ROGUE;common","tracks/track1.wav",
  StylePtr<Style_PhenomSparkleOff>(), StylePtr<Switch_Orange>(), "killer of stars"},

  // Rogue One Vader Ending
  { "KSith-ROGUEVADER;common", "tracks/hallway.wav",
  StylePtr<Style_RedHumpFlicker>(), StylePtr<Switch_Red>(), "ks roguevader"},

  // Obi-Wan S1 Vader Finale
  { "KSith-WHATREMAINS;common", "tracks/vaderobi_dialogue.wav",
  StylePtr<Style_RedAngryAudio>(), StylePtr<Switch_Red>(), "ks obivader"},

  // The Tales S1 - Ahsoka vs Inquisitor
  { "KSith-GHOST;common", "tracks/combat1.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "ks ghost"},

  // Ahsoka S1 Shin Hati
  { "KSith-HATI;common", "tracks/woodsfight.wav",
  StylePtr<Style_DarkBloodOrangeHumpFlicker>(), StylePtr<Switch_Orange>(), "ks hati"},


  // #######################################
  // ##           KYBERPHONIC             ##
  // #######################################

  // Kylo - The Force Awakens (Kyberphonic Unstable v3 - paid)
  { "KP-KyloTLJ;common", "tracks/reyvkylo.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "kylo TLJ"},
  { "KP-KyloTFA;common", "tracks/reyvkylo.wav",
  StylePtr<Style_UnstableUnleashed>(), StylePtr<Switch_Red>(), "kylo TFA"},

  // Ahsoka Season 1 (Baylan Skoll) (paid)
  // { "KP-SunSkoll;common", "tracks/ahsokatheme.wav",
  // StylePtr<Style_DarkBloodOrangeHumpFlicker>(), StylePtr<Switch_Orange>(), "kpsunskoll"},

  // Son of Corellia (paid)
  { "KP-SonOfCorellia;common", "tracks/tfa.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "son of corellia"},

  // Ahsoka Season 1 - Ahsoka white (paid)
  { "KP-TheSorcererV2;common", "tracks/ahsokatheme.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "kp sorcerer v2"},

  // Dark saber (Mando live action show)
  // { "KP-DarkV3;common", "tracks/mandotheme.wav",
  // StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "dark saber"},

  // TFA Graflex v2 (paid)
  { "KP-TFAStarkiller;common", "tracks/reyvkylo.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "tfa starkill"},

  // TLJ Praetorian Guards
  // { "KPBilariWhip;common", "tracks/reyvkylo.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_Red>(), "tfa bilari"},

  // TLJ Praetorian Guards
  // { "KPVibroArbir;common", "tracks/reyvkylo.wav",
  // StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "tfa arbir"},

  // Adam Project movie MagCyl
  // { "KPAdamProjectMagCyl;common", "tracks/track_16.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_Red>(), "magcyl"},

  // TFM - F1 Racer (paid)
  // { "KP-PodRacer;common", "tracks/track_13.wav",
  // StylePtr<Style_EnginesBurn>(), StylePtr<Switch_Yellow>(), "podracer"},


  // ################################################
  // ##   github/Ferase/JediSurvivor-Soundfonts    ##
  // ################################################

  // Jedi Survivor - Bode
  // { "SWJS-BodeAkuna;common", "tracks/hallway.wav",
  // StylePtr<Style_RedAngryAudio>(), StylePtr<Switch_Red>(), "swjs bodeakuna"},

  // Jedi Survivor - Cal Kestis Green
  { "SWJS-CalGreen;common", "tracks/hallway.wav",
  StylePtr<Style_GreenHumpFlicker>(), StylePtr<Switch_Green>(), "swjs calgreen"},

  // Jedi Survivor - Cal Kestis Yellow
  { "SWJS-CalYellow;common", "tracks/hallway.wav",
  StylePtr<Style_YellowHumpFlicker>(), StylePtr<Switch_Yellow>(), "swjs calyellow"},

  // Jedi Survivor - Dagan Gera Light
  { "SWJS-DaganLight;common", "tracks/hallway.wav",
  StylePtr<Style_OrangeHumpFlicker>(), StylePtr<Switch_Orange>(), "swjs dagan lite"},

  // Jedi Survivor - Rick the Door Technician
  { "SWJS-Rick;common", "tracks/hallway.wav",
  StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_Red>(), "swjs rick"},

  // Jedi Survivor - Ninth Sister
  { "SWJS-NinthSister;common", "tracks/hallway.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<Switch_Red>(), "swjs ninth"},


  // #######################################
  // ##            GREYSCALE              ##
  // #######################################

  // Greyscale - Binary Dark (paid)
  { "GS-BinaryDark;common", "tracks/track1.wav",
  StylePtr<GreyscaleBinaryDark>(), StylePtr<Switch_Red>(), "gs bd"},

  // Greyscale - Endure (paid)
  { "GS-Endure;common", "tracks/track1.wav",
  StylePtr<GreyscaleEndureRageCustom>(), StylePtr<Switch_Red>(), "gs endure"},

  // Greyscale - Stitched (free)
  { "GS-Stitched;common", "tracks/track1.wav",
  StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_Red>(), "gs stitched"},

  // Greyscale - Crispity (free)
  { "GS-Crispity;common", "tracks/track1.wav",
  StylePtr<Style_GreenBlueAudioFlicker>(), StylePtr<Switch_Green>(), "gs crispy"},

  // Greyscale - Mercenary (free)
  { "GS-Mercenary;common", "tracks/track1.wav",
  StylePtr<Style_GreenSwingOrange>(), StylePtr<Switch_Orange>(), "gs mercenary"},


  // ####################################
  // ##             OTHERS             ##
  // ####################################

  // BlueMamba (Etsy) - DC Deathstroke (authored with Semz Nerd)
  { "BM-Mercenary;common", "tracks/hallway.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "bm merc"},

  // Syndicate Custom Relics - Retribution (electroblade)
  // { "SCRRetribution;common", "tracks/combat1.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<Switch_White>(), "scr retrib"},

  // Mongo https://www.youtube.com/watch?v=TieX5N51b5I
  { "Mongo-DuneV2;common", "tracks/dune.wav",
  StylePtr<Style_PhenomElectroStaff>(), StylePtr<Switch_White>(), "mongo dune"},

  // Cosmic Ape - Dreamhunter (paid)
  // { "CADreamhunter;common", "tracks/track1.wav",
  // StylePtr<Style_GreenSwingOrange>(), StylePtr<Switch_Green>(), "ca dh"},

  // Epiphany - Epic (MUSIC BASED)
  { "Epiphany-EpicMusic;common", "tracks/track1.wav",
  StylePtr<Style_Rainbow_Fire>(), StylePtr<Switch_Rainbow>(), "music epic"},


  // #######################################
  // ##            MEATY NUBS             ##
  // #######################################

  // https://www.youtube.com/shorts/YZBsMuEkjx4
  // { "MeatyC110P;common", "tracks/swrebelstheme.wav",
  // StylePtr<Style_OrangeHumpFlicker>(), StylePtr<Switch_Orange>(), "meaty c110p"},

  // https://www.youtube.com/shorts/YZBsMuEkjx4
  // { "MeatyDomo;common", "tracks/MrRoboto.wav", //Killroy
  // StylePtr<Style_GreenSwingOrange>(), StylePtr<Switch_Blue>(), "meaty domo"},

  // https://www.youtube.com/watch?v=c3NMZTPvBTE
  { "Meaty-StarTrek;common", "tracks/sttngtheme.wav",
  StylePtr<Style_PhenomStarTrek>(), StylePtr<Switch_Blue>(), "meaty trek"},


  // #######################################
  // ##           JAYDALORIAN             ##
  // #######################################

  // Jaydalorian Banished (paid)
  { "JD-Banished;common", "tracks/track1.wav",
  StylePtr<Style_BanishedPurpleOverload>(), StylePtr<Switch_Magenta>(), "jd banish"},

  // Jaydalorian Decimate (free)
  // { "JDDecimate;common", "tracks/track1.wav",
  // StylePtr<Style_PhenomCrispyPinkFlicker>(), StylePtr<WHITE>(), "jd decimate"},


  // #######################################
  // ##          MOUNTAIN SABERS          ##
  // #######################################

  // Double Agent Pong Krell (paid)
  { "MS-PongKrell;common", "tracks/swrebelstheme.wav",
  StylePtr<Style_GreenBlueAudioFlicker>(), StylePtr<Switch_Green>(), "ms doubleagent"},

  // Star Trek Whale probe ep 4 (paid)
  { "MS-StarTrekWhaleProbe;common", "tracks/STT.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<Switch_White>(), "ms st whale"},

  // The Beginner (free)
  // { "MSTheBeginner;common", "tracks/sw.wav",
  // StylePtr<Style_Original_BlueRotoscope>(), StylePtr<Switch_Blue>(), "ms thebeginner"},

  // Daft Punk Tribute
  // { "MSDaftPunk;common", "tracks/daftpunkaround.wav",
  // StylePtr<Style_PhenomCrispyPinkFlicker>(), StylePtr<Switch_Magenta>(), "ms daftpunk"},


  // #######################################
  // ##               CFX                 ##
  // #######################################

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


  // #######################################
  // ##              REDDIT               ##
  // #######################################

  // { "Reddit-ARCANE;common", "tracks/track1.wav",
  // StylePtr<Style_PhenomSparkleOff>(), StylePtr<Switch_Red>(), "reddit arcane"},

  // { "Reddit-Ronin;common", "tracks/track1.wav", //Not a jedi
  // StylePtr<Style_UnstableRage>(), StylePtr<WHITE>(), "reddit ronin"},

  // Palpatine
  { "Reddit-SenateMajority;common", "tracks/palpatheme.wav",
  StylePtr<Style_PhenomTragedySenate>(), StylePtr<Switch_Red>(), "reddit senatemajority"},

  // Portal game
  { "Reddit-Portal;common", "tracks/stillalive.wav",
  StylePtr<Style_PortalGame>(), StylePtr<Switch_Blue>(), "geekbot9999 portal"},


  // #######################################
  // ##              MISC                 ##
  // #######################################

  { "SlaveOneTwoPointOne;common", "tracks/track1.wav",
  StylePtr<Style_SlaveOne>(), StylePtr<Switch_Blue>(), "nosloppy slave1"},


  // #######################################
  // ##             CHRISTMAS             ##
  // #######################################

  // Meatynubs Christmas V2 10/16/22
  { "Meaty-Christmas;common", "tracks/christmas_sesame1.wav",
  StylePtr<Style_PhenomChristmas>(), StylePtr<Switch_RGB_Swing>(), "meaty christ"},

  // MOUNTAIN SABERS Ball Drop - New Years (paid)
  { "MS-BallDrop;common", "tracks/newyearcantina.wav",
  StylePtr<Style_Rainbow_Fire>(), StylePtr<Switch_Rainbow>(), "ms newyear"},

  // Jaydalorian Christmas (free)
  // { "JD-Christmas;common", "tracks/christmas.wav",
  // StylePtr<Style_Menorah>(), StylePtr<Switch_RGB_Swing>(), "jd christmas"},

  // Jaydalorian New years (free)
  { "JD-Newyears;common", "tracks/newyearcantina.wav",
  StylePtr<Style_Rainbow_Fire>(), StylePtr<Switch_Rainbow>(), "jd newyear"},


};

BladeConfig blades[] = {
  { 0,
    WS281XBladePtr<currentLedsInStrip, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), //Main
    //SubBlade(0,0, NULL), // Crystal
    WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5, bladePowerPin1> >(), //Switch
    CONFIGARRAY(blade)
  },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
