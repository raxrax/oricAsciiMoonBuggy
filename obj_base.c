static char *baseASCII[7] = {
    "  ___________________         ",
    " /                   \\       ",
    "/                     \\      ",
    "|'-._              _.-'|      ",
    "| |. ''----------'' .| |_____.",
    "| |:  | ||    :| |  :| /____/|",
    "| |:  | ||    :| |  :||____|_|",
};


//data[0] - state 
//data[1] - offset
void baseUpdate()
{
    int i;

    switch (objects[currentObject].data[0])
    {
            //init
        case '0':
            objects[currentObject].data[0] = '1';
            objects[currentObject].data[1] = 0;
            break;

            //inc
        case '1':
            for (i = 0; i < 7; i++)
            {
                printText(
                        baseASCII[i]+(29 - objects[currentObject].data[1]),
                        objects[currentObject].x,
                        objects[currentObject].y + i
                        );
            }

            objects[currentObject].data[1]++;
            if (objects[currentObject].data[1] > 30)
                objects[currentObject].data[0] = '2';
            break;
            //waiting
        case '2':
            objects[currentObject].data[1]++;
            if (objects[currentObject].data[1] == 78)
                objects[currentObject].data[0] = '3';
            break;

            // erase
        case '3':
            for (i = 0; i < 7; i++)
            {
                memset(
                        (void *) getpos(objects[currentObject].x, objects[currentObject].y + i),
                        32,
                        30
                        );
            }
            objects[currentObject].data[0] = '0';
            objects[currentObject].data[1] = '1';
            objects[currentObject].active = 0;
            break;
    }
}

