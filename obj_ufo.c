//data[0] state
void UFOUpdate()
{
	int rand;
	rand = rand();
	
	printText("   ", objects[currentObject].x,objects[currentObject].y);

	//move
	if (rand%2 == 0){
		objects[currentObject].x++;
		if (rand%3 == 0 && objects[currentObject].y>1)
			objects[currentObject].y--;
		if (rand%3 == 1 && objects[currentObject].y<8)
			objects[currentObject].y++;
		
		//destroy
		if (objects[currentObject].x == 37){
			objects[currentObject].active = 0;
			objects[currentObject].data[0] = '0';
			return;
		}
	}
	

	//bomb
	if (rand%30 == 0){
		if (rand()%6 == 0)
			addObject(OBJ_BOMB,objects[currentObject].x,objects[currentObject].y,"1*");
		else
			addObject(OBJ_BOMB,objects[currentObject].x,objects[currentObject].y,"0+");
	}

	
	printText("(O)", objects[currentObject].x,objects[currentObject].y);
	
}