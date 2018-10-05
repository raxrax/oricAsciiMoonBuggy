// data[0] track update
void gameManagerUpdate()
{
    distance++;

    if (key1 == '+') lives++;
    if (key1 == 'P') gamePause();

    printBoard(distance);
    obstacles(distance);
    track(distance);
    freeObjects(distance);
}

void printBoard(int d)
{
    sprintf((void *) getpos(0, 26), "Dist:%d    ", d);
    sprintf((void *) getpos(11, 26), "Lives:%d ", lives);
    sprintf((void *) getpos(20, 26), "Level:%d ", level);
    sprintf((void *) getpos(29, 26), "Score:%d ", score);
}

void gamePause()
{
    printText("\014Pause\010", 17, MSG_Y - 2);
	get();
    printText("       ", 17, MSG_Y - 2);
}

void incScore(int inc)
{
    score += inc;
    if (score % 1000 == 0)
    {
        lives++;
        addObject(OBJ_TEXT_TEMP, 255, MSG_Y-1, "!+1 live");
    }
}



void track(int d)
{
    //float f1 = 24.55;

    updateTrack++;

    switch (updateTrack)
    {
        case 1:
          
			printTrack();

            if (trackCurPos == 40)
            {
                level++;
                trackCurPos = 0;
                distance = 0;
                addObject(OBJ_TEXT_TEMP, 255, MSG_Y - 1, "ZCongratulations! Prepare for next level");
            }

            break;

        case 250:
		    trackCurPos++;
            updateTrack = 0;
            break;
    }

}

void printTrack()
{
	unsigned char i;
	char *screenPos;
	unsigned char y = 24;
	
	printText("base___i___h___g___f___e___d___c___b___a", 0, y);
		//memset((void *)getpos(0,objects[currentObject].y), '_', 39-trackCurPos);
		//memset((void *)getpos(39-trackCurPos,objects[currentObject].y), '#', 1+trackCurPos);

	for (i = 39 - trackCurPos; i < 40; i++)
	{
		screenPos = (char *) getpos(i, y);
		*screenPos = 128 | *screenPos;
	}
}


void obstacles(int d)
{
    int rand = rand();

    unsigned char rand1 = rand % 10;
    unsigned char rand2 = rand % 5;

    lastObjectDistance++;

    switch (d)
    {
        case 50:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Craters'");
            break;

        case 1020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Rocks'");
            break;

        case 2020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Comets'");
            addObject(OBJ_EARTH, 0, 5, "00");
            break;

        case 3020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Walls'");
            break;

        case 4020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Traps'");
            break;

        case 5020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'UFO'");
            break;

        case 6020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Iterance'");
            break;

        case 7020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Meteors'");
            break;

        case 8020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Burning fire'");
            break;

        case 9020:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "ZGet ready! 'Inferno'");
            break;

        case 9920:
            addObject(OBJ_TEXT_TEMP, 255, MSG_Y, "!The base!");
            addObject(OBJ_BASE, 0, 14, "01");
            break;
    }

    //pass 1
    if (d > 100 && d < 1000)
    {
        if (rand1 == 1) addObstacles1(14);
    }

    //pass 2
    if (d > 1100 && d < 2000)
    {
        if (rand1 == 1) addObstacles1(15);
        if (rand1 == 2) addObstacles2(5);
    }

    //pass 3
    if (d > 2100 && d < 3000)
    {
        if (rand1 == 3) addObstacles3(10);
    }

    //pass 4
    if (d > 3100 && d < 4000)
    {
        if (rand1 == 3) addObstacles4(15);
        if (rand1 == 4) addObstacles2(5);
    }

    //pass 5
    if (d > 4100 && d < 5000)
    {
        if (rand1 == 1) addObstacles1(15);
        if (rand1 == 2) addObstacles2(5);
        if (rand1 == 3) addObstacles4(15);
        if (rand1 == 4) addObstacles5(10);

    }

    // pass 6
    if (d > 5100 && d < 6000)
    {
        if (d % 40 == 0) addObstaclesUFO();
		if (rand1 == 1) addObstacles1(50);
    }

    // pass 7
    if (d > 6100 && d < 7000)
    {
        if (rand % 5 == 1) addObstacles3(8);
        if (rand % 5 == 2) addObstacles2(10);

    }

    // pass 8
    if (d > 7100 && d < 8000)
    {
        if (rand%50 == 1) addObstaclesMeteor();
		if (d % 400 == 0) addObstaclesUFO();
		if (rand%30 == 2) addObject(OBJ_FALLING_STAR, rand % 30, 1, "\\");
    }

    // pass 9
    if (d > 8100 && d < 9000)
    {
        if (rand1 == 1) addObstacles3(15);
		if (d % 200 == 0) addObstaclesUFO();
		if (d % 70 == 0) addObstaclesMeteor();
		if (rand%30 == 2) addObject(OBJ_FALLING_STAR, rand % 30, 1, "\\");

    }

    //pass 10
    if (d > 9100 && d < 9850)
    {
        if (rand1 == 1) addObstacles1(15);
        if (rand1 == 2) addObstacles2(15);
        if (rand1 == 3) addObstacles3(15);
        if (rand1 == 4) addObstacles4(15);
        if (rand1 == 5) addObstacles5(15);
		if (d % 150 == 1) addObstaclesMeteor();
		if (d % 100 == 0) addObstaclesUFO();
    }
}