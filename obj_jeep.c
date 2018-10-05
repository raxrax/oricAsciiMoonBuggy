#define OBJ_JEEP 5

#define JEEP_ANIMATION 1
#define JEEP_STATE 0
#define JEEP_DIRECTION 2
#define JEEP_STEP 3


//====
static char *jeepAnimation[12] = {
    "   Omn",
    "(|)-(|)",

    "   Omn",
    "(\\)-(\\)",

    "   Omn",
    "(-)-(-)",

    "   Omn",
    "(/)-(/)",

    "   oMn", // 8 jump 1
    "(/)-(/)",

    "   omn", // 10 jimp 2
    "(+)_(+)",
};

static char *jeepCrashAnimation[18] = {
    "            oo ___  ",
    "             cnOMMnb",
    "         o o   ___  ",
    "             cnONMnb",
    "         o     ___  ",
    "        o    cmOMNnb",
    "      o        ___  ",
    "       o     cnOMMnb",
    "     o         ___  ",
    "      o      cuOMMmb",
    "               ___  ",
    "    o o      cmONMnb",
    "   o           ___  ",
    "      o      cuOUMnb",
    "               ___  ",
    "  o   o      cnOMMmb",
    "               ___  ",
    " o    o      cmOMMnb",
};

// data[0] - animation frame
// data[1] - state 0 - normal; 1 - jump; 2 - crash
// data[2] - jump direction
// data[3] - jump step
void jeepUpdate()
{
    int i, oldX, oldY;
    char animation;

	//state crash
    if (objects[currentObject].data[JEEP_STATE] == '2')
    {
        jeepCrash();
        return;
    }

	//reset animation
    if (objects[currentObject].data[JEEP_ANIMATION] > 7)
        objects[currentObject].data[JEEP_ANIMATION] = 1;

    animation = (char) objects[currentObject].data[JEEP_ANIMATION] -1;



    oldX = objects[currentObject].x;
    oldY = objects[currentObject].y;

	jeepControls();
	
    //state normal
    if (objects[currentObject].data[JEEP_STATE] == '0')
    {
        objects[currentObject].data[JEEP_ANIMATION] += 2;
    }

    //state jump
    if (objects[currentObject].data[JEEP_STATE] == '1')
    {
        animation = 8;
        if (objects[currentObject].data[JEEP_STEP] == 5) objects[currentObject].data[JEEP_DIRECTION] = 0;
        if (objects[currentObject].data[JEEP_STEP] == 9) objects[currentObject].data[JEEP_DIRECTION] = 1;
        if (objects[currentObject].data[JEEP_STEP] == 12) animation = 10;
        if (objects[currentObject].data[JEEP_STEP] == 12) objects[currentObject].data[JEEP_STATE] = '0';
        objects[currentObject].y += objects[currentObject].data[JEEP_DIRECTION];
        objects[currentObject].data[JEEP_STEP]++;
    }

    printText("       ", oldX, oldY - 1);
    printText("       ", oldX, oldY);

    printText(jeepAnimation[animation], objects[currentObject].x, objects[currentObject].y - 1);
    printText(jeepAnimation[animation + 1], objects[currentObject].x, objects[currentObject].y);

    jeepCollisionCheck();

}

void jeepCollisionCheck()
{
    unsigned char i, x, y, ox, oy, state;

    x = objects[currentObject].x;
    y = objects[currentObject].y;
    state = objects[currentObject].data[JEEP_STATE];

    for (i = 0; i < OBJECTS_MAX; i++)
    {
		switch (objects[i].active){
			case 0:
				continue;
			break;
		}
		
        switch(objects[i].type ){
			case OBJ_OBSTACLE:
				ox = objects[i].x;
				oy = objects[i].y;
				if (
						//line1
						(oy == y && ox >= x && ox <= x+5)
						
						// line2
						||(oy == y-1 && ox > x+3 && ox < x+5)
						
						//trap
						|| (state == '0' && oy == y + 1 && (ox == x || ox == x + 1 || ox == x + 3 || ox == x + 5))
					)
				{
					objects[currentObject].data[JEEP_ANIMATION] = 1;
					objects[currentObject].data[JEEP_STATE] = '2';
					explode();
				}

				if (ox == x)
				{
					incScore(10);
				}
			break;
			
			case OBJ_BOMB:
			case OBJ_METEOR:
				if (
					(objects[i].y == objects[currentObject].y ||objects[i].y == objects[currentObject].y+1)
					&& objects[i].x >= objects[currentObject].x
					&& objects[i].x <= objects[currentObject].x+7
					)
				{
					objects[currentObject].data[JEEP_ANIMATION] = 1;
					objects[currentObject].data[JEEP_STATE] = '2';
					explode();
				}
			break;
		}
    }

}

void jeepCrash()
{
    static unsigned char update;
    unsigned char animation = objects[currentObject].data[JEEP_ANIMATION] -1;

    update++;
    if (update < 2) return;
    update = 0;

    if (objects[currentObject].y < JEEP_Y)
    {
        printText("                      ", objects[currentObject].x - 12, objects[currentObject].y - 1);
        objects[currentObject].y++;
    }

    printText(jeepCrashAnimation[animation], objects[currentObject].x - 12, objects[currentObject].y - 1);
    printText(jeepCrashAnimation[animation + 1], objects[currentObject].x - 12, objects[currentObject].y);

    if (animation > 15)
    {
        animation = 0;
        engineRunning = 0;
        objects[currentObject].data[JEEP_ANIMATION] = 1;
        objects[currentObject].data[JEEP_STATE] = '0';
        wait(300);
        return;
    }

    objects[currentObject].data[JEEP_ANIMATION]++;
    objects[currentObject].data[JEEP_ANIMATION]++;


}

void jeepControls()
{
	static unsigned char lastLaser;
	static unsigned char lastMissile;
    lastLaser++;
	lastMissile++;
		
	//shoot
    if (key1 == 'Z' && lastLaser > 1)
    {
        addObject(OBJ_LASER, objects[currentObject].x, objects[currentObject].y, "\018");
        lastLaser = 0;
        shoot();
    }

    //jump
    if (key1 == ' ' && objects[currentObject].data[JEEP_STATE] != '1')
    {
        objects[currentObject].data[JEEP_DIRECTION] = -1;
        objects[currentObject].data[JEEP_STEP] = 1;
        objects[currentObject].data[JEEP_STATE] = '1';
    }

	//missile
	if (key1 == 'X' && lastMissile > 5)
	{
		addObject(OBJ_MISSILE, objects[currentObject].x+5, objects[currentObject].y, "");
		lastMissile=0;
		shoot();
	}
	
	//left
	if (key1 == ',' && objects[currentObject].x>15)
	{
		objects[currentObject].x --;
	}
		
	//right
	if (key1 == '.' && objects[currentObject].x<32)
	{
		objects[currentObject].x ++;
	}
}