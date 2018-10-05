void obstacleUpdate()
{
    objects[currentObject].x++;
    if (objects[currentObject].x > 38)
    {
        objects[currentObject].active = 0;
        if (objects[currentObject].y == JEEP_Y + 1)
            printText("~~", objects[currentObject].x - 2, objects[currentObject].y);
        else
            printText("   ", objects[currentObject].x - 2, objects[currentObject].y);
        return;
    }

    printText(objects[currentObject].data, objects[currentObject].x - 2, objects[currentObject].y);
}


// type '#  '
void addObstacles1(unsigned char minDistance)
{
    if (lastObjectDistance < minDistance ) return;
    addObject(OBJ_OBSTACLE, 3, JEEP_Y + 1, "~  ");
    lastObjectDistance = level;
}

// type ' /\'

void addObstacles2(unsigned char minDistance)
{
    if (lastObjectDistance < minDistance) return;
    addObject(OBJ_OBSTACLE, 3, JEEP_Y, " /\\");
    lastObjectDistance = level;
}

// type ' <)'

void addObstacles3(unsigned char minDistance)
{
    if (lastObjectDistance < minDistance) return;
    addObject(OBJ_OBSTACLE, 3, JEEP_Y - 1 - (rand() % 6), " <)");
    lastObjectDistance = level;
}


// type ' H'
//      ' H'

void addObstacles4(unsigned char minDistance)
{
    if (lastObjectDistance < minDistance) return;

    addObject(OBJ_OBSTACLE, 3, JEEP_Y, "  H");
    addObject(OBJ_OBSTACLE, 3, JEEP_Y - 1, "  H");
    lastObjectDistance = level;
}

// type ' ^^'

void addObstacles5(unsigned char minDistance)
{
    if (lastObjectDistance < minDistance) return;

    addObject(OBJ_TRAP, 3, JEEP_Y + 1, "0");
    lastObjectDistance = level;
}

// type '(O)' ufo
void addObstaclesUFO()
{
    //if (lastObjectDistance < minDistance) return;
	
    addObject(OBJ_UFO,0,2+rand()%8,"01");
    //lastObjectDistance = level;
}

// type '\*/' 
void addObstaclesMeteor()
{
    addObject(OBJ_METEOR,2+rand()%30,2,"");
}

void trapUpdate()
{
    objects[currentObject].x++;
    if (objects[currentObject].x == 25)
    {
        objects[currentObject].active = 0;
        addObject(OBJ_OBSTACLE, objects[currentObject].x - 1, objects[currentObject].y, "~~  ");
        addObject(OBJ_OBSTACLE, objects[currentObject].x, objects[currentObject].y - 1, " ^^");
        return;
    }

    printText("~^^", objects[currentObject].x - 2, objects[currentObject].y);
}