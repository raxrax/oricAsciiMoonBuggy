void laserUpdate()
{
    int i;
	char *screen;

    objects[currentObject].x--;
    objects[currentObject].x--;

	screen = (char *)getpos(objects[currentObject].x,objects[currentObject].y);
	
	
    //collision check
	if (*screen != 32){
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
				case OBJ_OBSTACLE:
					if (
							objects[i].y == objects[currentObject].y &&
							(objects[i].x == objects[currentObject].x + 1 || objects[i].x == objects[currentObject].x + 2 || objects[i].x == objects[currentObject].x)

						)
					{
						objects[i].active = 0;
						printText("        ", objects[currentObject].x - 2, objects[currentObject].y);
						objects[currentObject].active = 0;
						addObject(OBJ_EXPLOSION,objects[currentObject].x,objects[currentObject].y,"0");
						incScore(10);
						return;
					}
					break;
			}

		}
	}
	switch (objects[currentObject].x -7){
		case 0:
		case 1:
		    printText("       ", objects[currentObject].x, objects[currentObject].y);
			objects[currentObject].active = 0;
			return;
		break;
		
		case 2:
		case 3:
		case 4:
		case 5:
		    printText("**    ", objects[currentObject].x, objects[currentObject].y);
			return;
		break;
	}
	
    printText("----  ", objects[currentObject].x, objects[currentObject].y);
}