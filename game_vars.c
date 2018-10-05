#define CURSOR_START 10 // #26a,10
#define CURSOR_END 3 // #26a,3

#define JEEP_X 30
#define JEEP_Y 20

#define MSG_Y 7
#define MAX_DISTANCE 10000;


// objects
#define OBJ_GAME_MANAGER 1
#define OBJ_STAR 2
#define OBJ_TEXT 3
#define OBJ_TEXT_ONCE 4
#define OBJ_LASER 6
#define OBJ_OBSTACLE 7
#define OBJ_MENU 8
#define OBJ_MOUNTAIN 9
#define OBJ_TEXT_TEMP 10
#define OBJ_SHIP 11
#define OBJ_FALLING_STAR 12
#define OBJ_EARTH 13
#define OBJ_TRAP 14
#define OBJ_BASE 15
#define OBJ_MISSILE 16
#define OBJ_UFO 17
#define OBJ_BOMB 18
#define OBJ_EXPLOSION 19
#define OBJ_METEOR 20

static unsigned char lastObjectDistance = 0;
static unsigned char lives = 3;
static unsigned char level = 1;

static int updateTrack = 0;
static int trackCurPos = 0;

static int score = 0;
static int highScore = 0;

static unsigned int distance;

static char *systemMessage = " ";
static char *t;