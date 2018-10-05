void freeObjects(int d)
{
    int rand;
    static update;
    update++;
    if (update < 300) return;

    rand = rand();
    update = rand % 200;

    switch (rand % 5)
    {
        case 0:
            addObject(OBJ_STAR, 0, rand % 7 + 2, "3>0");
            break;
        case 1:
            addObject(OBJ_STAR, 0, rand % 7 + 2, "3}0");
            break;
        case 2:
            addObject(OBJ_FALLING_STAR, rand % 30, 1, "\\");
            break;
        case 3:
            addObject(OBJ_SHIP, 0, rand % 4 + 5, "0");
            break;
    }

}


// data[0] char
void fallingStarUpdate()
{

    printChar(' ', objects[currentObject].x, objects[currentObject].y);
    objects[currentObject].x++;
    objects[currentObject].y++;

    if (objects[currentObject].y == 9 || objects[currentObject].x == 39)
    {
        objects[currentObject].active = 0;
        if (rand() % 3 == 0) addObject(OBJ_FALLING_STAR, rand() % 30, 1, "\\");
        return;
    }
    printChar(objects[currentObject].data[0], objects[currentObject].x, objects[currentObject].y);
}

//data [0] - state
void shipUpdate()
{
    printChar(' ', objects[currentObject].x, objects[currentObject].y);

    switch (objects[currentObject].data[0])
    {

        case '0':
            objects[currentObject].x = 0;
            objects[currentObject].data[0] = '1';
            break;
        case '1':
            if (objects[currentObject].x == 30)
            {
                objects[currentObject].data[0] = '2';
                //if (rand()%3==0) objects[currentObject].data[0] = '3';
            }
            objects[currentObject].x += 2;
            printChar('}', objects[currentObject].x, objects[currentObject].y);
            break;
        case '2':
            if (objects[currentObject].x == 15) objects[currentObject].data[0] = '3';
            objects[currentObject].x--;
            printChar('{', objects[currentObject].x, objects[currentObject].y);
            break;
        case '3':
            if (objects[currentObject].y == 2) objects[currentObject].data[0] = '4';
            objects[currentObject].x += 2;
            objects[currentObject].y--;
            printChar('}', objects[currentObject].x, objects[currentObject].y);
            break;
        case '4':
            objects[currentObject].active = 0;
            objects[currentObject].data[0] = '0';
            break;
    }
}

// data [0] - timer
// data [1] - show text
void earthUpdate()
{
    if (objects[currentObject].data[0] == '0') objects[currentObject].data[0] = 0;

    objects[currentObject].data[0]++;

    switch (objects[currentObject].data[0])
    {
        case 40: // move speed
            objects[currentObject].x++;
            objects[currentObject].data[0] = 1;
            if (objects[currentObject].x == 10 && objects[currentObject].data[1] == '0')
            {
                objects[currentObject].data[1] = '1';
                addObject(OBJ_TEXT_TEMP, objects[currentObject].x + 3, objects[currentObject].y, "\30<- this is the Earth :)");
            }

            if (objects[currentObject].x == 38)
            {
                printText("   ", objects[currentObject].x, objects[currentObject].y);
                objects[currentObject].active = 0;
                return;
            }

            break;
    }
    printText(" o", objects[currentObject].x, objects[currentObject].y);
}