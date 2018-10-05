#include <lib.h>

#include "engine.c"
#include "game_vars.c"

#include "obj_jeep.c"
#include "obj_mountain.c"
#include "obj_laser.c"
#include "obj_obstacle.c"
#include "obj_star.c"
#include "obj_text.c"
#include "obj_freeObjects.c"
#include "obj_gameManager.c"
#include "obj_base.c"
#include "obj_menu.c"
#include "obj_missile.c"
#include "obj_ufo.c"
#include "obj_bomb.c"
#include "obj_explosion.c"
#include "obj_meteors.c"

#include "engine_objects.c"

char *copyright = "rax@Sofia2018";

char *getHighScore()
{
    char *t3;
    sprintf(t, "High score:%d ", highScore);
    return t;
}


void scene2()
{
    lives = 5;
    distance = 0;
    updateTrack = 0;
    trackCurPos = 0;
    score = 0;
    level = 1;

    while (lives > 0)
    {
        cls();
        initObjects();
        //addObject(OBJ_STAR,30,5,"1.1");
        //addObject(OBJ_STAR,10,7,"2.1");
        //addObject(OBJ_STAR,10,10,"3.1");
        addObject(OBJ_TEXT_ONCE, 0, JEEP_Y + 2, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        addObject(OBJ_TEXT_ONCE, 0, JEEP_Y + 1, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        addObject(OBJ_TEXT_ONCE, 23, 0, getHighScore());
        addObject(OBJ_JEEP, JEEP_X, JEEP_Y, "00000");
        addObject(OBJ_MOUNTAIN, 1, 9, "0");
        addObject(OBJ_GAME_MANAGER, 0, JEEP_Y + 4, "0");

		printTrack();
        engine();
        lives--;
    }

    if (score > highScore) highScore = score;
}

void scene1()
{
    initObjects();
    addObject(OBJ_TEXT_ONCE, 35, 0, "     ");
    addObject(OBJ_TEXT_TEMP, 0, 23, "9Ascii Moon Buggy");
    addObject(OBJ_TEXT_TEMP, 32, 23, "!rax@2018");
    addObject(OBJ_TEXT_ONCE, 0, JEEP_Y + 2, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    addObject(OBJ_TEXT_ONCE, 0, JEEP_Y + 1, "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    addObject(OBJ_TEXT, 0, JEEP_Y - 5, "        __/\\_'--./-\\__._/-\\           ");
    addObject(OBJ_TEXT, 0, JEEP_Y - 4, "   _.--'                   '--./\\       ");
    addObject(OBJ_TEXT, 0, JEEP_Y - 3, "/-\\                              '-/-\\_");
    addObject(OBJ_MENU, 4, 1, "0");
    addObject(OBJ_JEEP, JEEP_X, JEEP_Y, "00001");
    addObject(OBJ_TEXT_ONCE, 23, 0, getHighScore());
    engine();

}

void font()
{
    poke(0xb400 + 95 * 8, 0);
    poke(0xb401 + 95 * 8, 0);
    poke(0xb402 + 95 * 8, 0);
    poke(0xb403 + 95 * 8, 0);
    poke(0xb404 + 95 * 8, 0);
    poke(0xb405 + 95 * 8, 0);
    poke(0xb406 + 95 * 8, 0);
    poke(0xb407 + 95 * 8, 63);
}

void init()
{
    cls();
    paper(0);
    ink(7);
    font();

    poke(0x26A, CURSOR_START);	
	poke(0x24e,4);
	poke(0x24f,1);
	
	//doke(0x306,30000);
}

void end()
{
    text();
    cls();
    poke(0x26a, CURSOR_END);
	poke(0x24e,32);
	poke(0x24f,4);
}

void main()
{
    while (key1 != 'Q')
    {
        init();
        scene1();
        cls();
        scene2();
    }
    end();
}
