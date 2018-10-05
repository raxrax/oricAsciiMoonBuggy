void missileUpdate()
{
	int i;
	printChar(' ', objects[currentObject].x,objects[currentObject].y);
	
	objects[currentObject].y--;
	
	if (objects[currentObject].y == 0){
		objects[currentObject].active = 0;
		return;
	}
	
	
	//collision check
    for (i = 0; i < OBJECTS_MAX; i++)
    {
        switch (objects[i].active)
        {
            case 0:
                continue;
                break;
        }

        switch (objects[i].type)
        {
            case OBJ_UFO:
                if (
                        (objects[i].y == objects[currentObject].y || objects[i].y+1 == objects[currentObject].y)&&
                        (objects[i].x == objects[currentObject].x || objects[i].x+1 == objects[currentObject].x  || objects[i].x+2 == objects[currentObject].x)
                    )
                {
                    objects[i].active = 0;
                    printText("   ", objects[i].x, objects[i].y);
                    objects[currentObject].active = 0;
					addObject(OBJ_EXPLOSION,objects[currentObject].x,objects[currentObject].y,"0");
                    incScore(10);
                    return;
                }
                break;
        }

    }
	
	printChar('|', objects[currentObject].x,objects[currentObject].y);
}
