// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 144;
const unsigned int currentLedsInStrip = 34;
#define VOLUME 1750
#define BOOT_VOLUME 300
#define CLASH_THRESHOLD_G 1.25
#define FETT263_SWING_ON_SPEED 320
#define AUDIO_CLASH_SUPPRESSION_LEVEL 5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define NO_REPEAT_RANDOM
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
#define MOTION_TIMEOUT 60 * 1 * 1000
#define IDLE_OFF_TIME 60 * 1 * 1000
#define BLADE_DETECT_PIN 17
#define SAVE_STATE
#define COLOR_CHANGE_DIRECT
#define ENABLE_ALL_EDIT_OPTIONS
#define FETT263_EDIT_SETTINGS_MENU
#define FETT263_ENABLE_SPIN_MODE
#define FETT263_DISABLE_CHANGE_STYLE
#define FETT263_DISABLE_COPY_PRESET
#define FETT263_DISABLE_CHANGE_FONT
#define FETT263_LOCKUP_DELAY 100
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

  { "Ksith-ECHOES;common","tracks/track1.wav",
  StylePtr<Style_BlueHumpFlicker>(), StylePtr<WHITE>(), "anakin ahsoka"},

  { "KP-Ezra-Stdv2;common", "tracks/swrebelstheme.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<WHITE>(), "staple sword std"},

  { "KP-Ezra-Trainingv2;common", "tracks/swrebelstheme.wav",
  StylePtr<Style_BlueHumpFlicker>(), StylePtr<WHITE>(), "staple sword training"},

  { "KSith-GRANDHUNTER;common", "tracks/combat1.wav",
  StylePtr<Style_RedAngryAudio>(), StylePtr<WHITE>(), "ks grandhunter"},

  { "Ksith-DARKSABERMANDO;common","tracks/track1.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "mando darksaber"},

  { "Ksith-GRANDMASTER;common", "tracks/track1.wav",
  StylePtr<Style_GreenHumpFlicker>(), StylePtr<WHITE>(), "yoda bootup"},

  { "Ksith-COUNT;common","tracks/track1.wav",
  StylePtr<Style_RedHumpFlicker>(), StylePtr<WHITE>(), "count dooku"},

  { "Ksith-MACE;common","tracks/track1.wav",
  StylePtr<Style_PurpleHumpFlicker>(), StylePtr<WHITE>(), "mace windu"},

  { "Ksith-THEBALANCE;common","tracks/track1.wav",
  StylePtr<Style_GreenHumpFlicker>(), StylePtr<WHITE>(), "the balance"},

  { "KP-SHOCKBATON;common", "tracks/track1.wav",
  StylePtr<Style_PhenomElectroStaff>(), StylePtr<WHITE>(), "shockbaton"},

  { "Ksith-DESTINY;common","tracks/track1.wav",
  StylePtr<Style_YellowHumpFlicker>(), StylePtr<WHITE>(), "rey tros"},

  { "Starfall-HIGHREPUBLIC;common", "tracks/track1.wav",
  StylePtr<Style_YellowHumpFlicker>(), StylePtr<WHITE>(), "high republic"},


  // #######################################
  // ##              KSITH                ##
  // #######################################

  { "Ksith-ROGUE;common","tracks/track1.wav",
  StylePtr<Style_PhenomSparkleOff>(), StylePtr<WHITE>(), "killer of stars"},

  // Rogue One Vader Ending
  { "KSith-ROGUEVADER;common", "tracks/hallway.wav",
  StylePtr<Style_RedHumpFlicker>(), StylePtr<WHITE>(), "ks roguevader"},

  // Obi-Wan S1 Vader Finale
  { "KSith-WHATREMAINS;common", "tracks/vaderobi_dialogue.wav",
  StylePtr<Style_RedAngryAudio>(), StylePtr<WHITE>(), "ks obivader"},

  // The Tales S1 - Ahsoka vs Inquisitor
  { "KSith-GHOST;common", "tracks/combat1.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<WHITE>(), "ks ghost"},

  // Ahsoka S1 Shin Hati
  { "KSith-HATI;common", "tracks/woodsfight.wav",
  StylePtr<Style_DarkBloodOrangeHumpFlicker>(), StylePtr<WHITE>(), "ks hati"},


  // #######################################
  // ##           KYBERPHONIC             ##
  // #######################################

  // Kylo - The Force Awakens (Kyberphonic Unstable v3 - paid)
  { "KP-KyloTLJ;common", "tracks/reyvkylo.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<WHITE>(), "kylo TLJ"},
  { "KP-KyloTFA;common", "tracks/reyvkylo.wav",
  StylePtr<Style_UnstableUnleashed>(), StylePtr<WHITE>(), "kylo TFA"},

  // Ahsoka Season 1 (Baylan Skoll) (paid)
  // { "KP-SunSkoll;common", "tracks/ahsokatheme.wav",
  // StylePtr<Style_DarkBloodOrangeHumpFlicker>(), StylePtr<WHITE>(), "kpsunskoll"},

  // Son of Corellia (paid)
  { "KP-SonOfCorellia;common", "tracks/tfa.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<WHITE>(), "son of corellia"},

  // Ahsoka Season 1 - Ahsoka white (paid)
  { "KP-TheSorcererV2;common", "tracks/ahsokatheme.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "kp sorcerer v2"},

  // Dark saber (Mando live action show)
  // { "KP-DarkV3;common", "tracks/mandotheme.wav",
  // StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "dark saber"},

  // TFA Graflex v2 (paid)
  { "KP-TFAStarkiller;common", "tracks/reyvkylo.wav",
  StylePtr<Style_Original_BlueRotoscope>(), StylePtr<WHITE>(), "tfa starkill"},

  // TLJ Praetorian Guards
  // { "KPBilariWhip;common", "tracks/reyvkylo.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<WHITE>(), "tfa bilari"},

  // TLJ Praetorian Guards
  // { "KPVibroArbir;common", "tracks/reyvkylo.wav",
  // StylePtr<Style_UnstableRage>(), StylePtr<WHITE>(), "tfa arbir"},

  // Adam Project movie MagCyl
  // { "KPAdamProjectMagCyl;common", "tracks/track_16.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<WHITE>(), "magcyl"},

  // TFM - F1 Racer (paid)
  // { "KP-PodRacer;common", "tracks/track_13.wav",
  // StylePtr<Style_EnginesBurn>(), StylePtr<WHITE>(), "podracer"},


  // ################################################
  // ##   github/Ferase/JediSurvivor-Soundfonts    ##
  // ################################################

  // Jedi Survivor - Bode
  // { "SWJS-BodeAkuna;common", "tracks/hallway.wav",
  // StylePtr<Style_RedAngryAudio>(), StylePtr<WHITE>(), "swjs bodeakuna"},

  // Jedi Survivor - Cal Kestis Green
  { "SWJS-CalGreen;common", "tracks/hallway.wav",
  StylePtr<Style_GreenHumpFlicker>(), StylePtr<WHITE>(), "swjs calgreen"},

  // Jedi Survivor - Cal Kestis Yellow
  { "SWJS-CalYellow;common", "tracks/hallway.wav",
  StylePtr<Style_YellowHumpFlicker>(), StylePtr<WHITE>(), "swjs calyellow"},

  // Jedi Survivor - Dagan Gera Light
  { "SWJS-DaganLight;common", "tracks/hallway.wav",
  StylePtr<Style_OrangeHumpFlicker>(), StylePtr<WHITE>(), "swjs dagan lite"},

  // Jedi Survivor - Rick the Door Technician
  { "SWJS-Rick;common", "tracks/hallway.wav",
  StylePtr<Style_Bilari_ElectroChain>(), StylePtr<WHITE>(), "swjs rick"},

  // Jedi Survivor - Ninth Sister
  { "SWJS-NinthSister;common", "tracks/hallway.wav",
  StylePtr<Style_UnstableRage>(), StylePtr<WHITE>(), "swjs ninth"},


  // #######################################
  // ##            GREYSCALE              ##
  // #######################################

  // Greyscale - Binary Dark (paid)
  { "GS-BinaryDark;common", "tracks/track1.wav",
  StylePtr<GreyscaleBinaryDark>(), StylePtr<WHITE>(), "gs bd"},

  // Greyscale - Endure (paid)
  { "GS-Endure;common", "tracks/track1.wav",
  StylePtr<GreyscaleEndureRageCustom>(), StylePtr<WHITE>(), "gs endure"},

  // Greyscale - Stitched (free)
  { "GS-Stitched;common", "tracks/track1.wav",
  StylePtr<Style_Bilari_ElectroChain>(), StylePtr<WHITE>(), "gs stitched"},

  // Greyscale - Crispity (free)
  { "GS-Crispity;common", "tracks/track1.wav",
  StylePtr<Style_GreenBlueAudioFlicker>(), StylePtr<WHITE>(), "gs crispy"},

  // Greyscale - Mercenary (free)
  { "GS-Mercenary;common", "tracks/track1.wav",
  StylePtr<Style_GreenSwingOrange>(), StylePtr<WHITE>(), "gs mercenary"},


  // ####################################
  // ##             OTHERS             ##
  // ####################################

  // BlueMamba (Etsy) - DC Deathstroke (authored with Semz Nerd)
  { "BM-Mercenary;common", "tracks/hallway.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "bm merc"},

  // Syndicate Custom Relics - Retribution (electroblade)
  // { "SCRRetribution;common", "tracks/combat1.wav",
  // StylePtr<Style_Bilari_ElectroChain>(), StylePtr<WHITE>(), "scr retrib"},

  // Mongo https://www.youtube.com/watch?v=TieX5N51b5I
  { "Mongo-DuneV2;common", "tracks/dune.wav",
  StylePtr<Style_PhenomElectroStaff>(), StylePtr<WHITE>(), "mongo dune"},

  // Cosmic Ape - Dreamhunter (paid)
  // { "CADreamhunter;common", "tracks/track1.wav",
  // StylePtr<Style_GreenSwingOrange>(), StylePtr<WHITE>(), "ca dh"},

  // Epiphany - Epic (MUSIC BASED)
  { "Epiphany-EpicMusic;common", "tracks/track1.wav",
  StylePtr<Style_Rainbow_Fire>(), StylePtr<WHITE>(), "music epic"},


  // #######################################
  // ##            MEATY NUBS             ##
  // #######################################

  // https://www.youtube.com/shorts/YZBsMuEkjx4
  // { "MeatyC110P;common", "tracks/swrebelstheme.wav",
  // StylePtr<Style_OrangeHumpFlicker>(), StylePtr<WHITE>(), "meaty c110p"},

  // https://www.youtube.com/shorts/YZBsMuEkjx4
  // { "MeatyDomo;common", "tracks/MrRoboto.wav", //Killroy
  // StylePtr<Style_GreenSwingOrange>(), StylePtr<WHITE>(), "meaty domo"},

  // https://www.youtube.com/watch?v=c3NMZTPvBTE
  { "Meaty-StarTrek;common", "tracks/sttngtheme.wav",
  StylePtr<Style_PhenomStarTrek>(), StylePtr<WHITE>(), "meaty trek"},


  // #######################################
  // ##           JAYDALORIAN             ##
  // #######################################

  // Jaydalorian Banished (paid)
  { "JD-Banished;common", "tracks/track1.wav",
  StylePtr<Style_BanishedPurpleOverload>(), StylePtr<WHITE>(), "jd banish"},

  // Jaydalorian Decimate (free)
  // { "JDDecimate;common", "tracks/track1.wav",
  // StylePtr<Style_PhenomCrispyPinkFlicker>(), StylePtr<WHITE>(), "jd decimate"},


  // #######################################
  // ##          MOUNTAIN SABERS          ##
  // #######################################

  // Double Agent Pong Krell (paid)
  { "MS-PongKrell;common", "tracks/swrebelstheme.wav",
  StylePtr<Style_GreenBlueAudioFlicker>(), StylePtr<WHITE>(), "ms doubleagent"},

  // Star Trek Whale probe ep 4 (paid)
  { "MS-StarTrekWhaleProbe;common", "tracks/STT.wav",
  StylePtr<Style_DarksaberLive>(), StylePtr<WHITE>(), "ms st whale"},

  // The Beginner (free)
  // { "MSTheBeginner;common", "tracks/sw.wav",
  // StylePtr<Style_Original_BlueRotoscope>(), StylePtr<WHITE>(), "ms thebeginner"},

  // Daft Punk Tribute
  // { "MSDaftPunk;common", "tracks/daftpunkaround.wav",
  // StylePtr<Style_PhenomCrispyPinkFlicker>(), StylePtr<WHITE>(), "ms daftpunk"},


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
  // >(), StylePtr<WHITE>(), "cfx kamino"},


  // #######################################
  // ##              REDDIT               ##
  // #######################################

  // { "Reddit-ARCANE;common", "tracks/track1.wav",
  // StylePtr<Style_PhenomSparkleOff>(), StylePtr<WHITE>(), "reddit arcane"},

  // { "Reddit-Ronin;common", "tracks/track1.wav", //Not a jedi
  // StylePtr<Style_UnstableRage>(), StylePtr<WHITE>(), "reddit ronin"},

  // Palpatine
  { "Reddit-SenateMajority;common", "tracks/palpatheme.wav",
  StylePtr<Style_PhenomTragedySenate>(), StylePtr<WHITE>(), "reddit senatemajority"},

  // Portal game
  { "Reddit-Portal;common", "tracks/stillalive.wav",
  StylePtr<Style_PortalGame>(), StylePtr<WHITE>(), "geekbot9999 portal"},


  // #######################################
  // ##              MISC                 ##
  // #######################################

  { "SlaveOneTwoPointOne;common", "tracks/track1.wav",
  StylePtr<Style_SlaveOne>(), StylePtr<WHITE>(), "nosloppy slave1"},


  // #######################################
  // ##             CHRISTMAS             ##
  // #######################################

  // Meatynubs Christmas V2 10/16/22
  // { "Meaty-Christmas;common", "tracks/christmas_sesame1.wav",
  // StylePtr<Style_PhenomChristmas>(), StylePtr<WHITE>(), "meaty christ"},

  // MOUNTAIN SABERS Ball Drop - New Years (paid)
  // { "MS-BallDrop;common", "tracks/newyearcantina.wav",
  // StylePtr<Style_Rainbow_Fire>(), StylePtr<WHITE>(), "ms newyear"},

  // Jaydalorian Christmas (free)
  // { "JD-Christmas;common", "tracks/christmas.wav",
  // StylePtr<Style_Menorah>(), StylePtr<WHITE>(), "jd christmas"},

  // Jaydalorian New years (free)
  // { "JD-Newyears;common", "tracks/newyearcantina.wav",
  // StylePtr<Style_Rainbow_Fire>(), StylePtr<WHITE>(), "jd newyear"},

};

BladeConfig blades[] = {
  { 0,
    WS281XBladePtr<maxLedsPerStrip, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    SimpleBladePtr<CreeXPE2WhiteTemplate<550>, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(),
    CONFIGARRAY(blade)
  },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
