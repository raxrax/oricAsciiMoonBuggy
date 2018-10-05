void meteorsUpdate()
{
	printText("  ", objects[currentObject].x-1,objects[currentObject].y-1);
	printText("  ", objects[currentObject].x-1,objects[currentObject].y);
	
	objects[currentObject].y++;

	if (objects[currentObject].y %3 ==0)
		objects[currentObject].x++;
	
	if (objects[currentObject].y > JEEP_Y){
		objects[currentObject].active = 0;
		addObject(OBJ_OBSTACLE, objects[currentObject].x, JEEP_Y + 1, "~  ");
		return;
	}
	
	printText("''", objects[currentObject].x-1,objects[currentObject].y+-1);
	printText("{}", objects[currentObject].x-1,objects[currentObject].y);

	
}