char *explosionAnimation[3] ={
	" + ",
	"+*+",
	" + ",
};


void explosionUpdate()
{   
	static state;
	printText("   ", objects[currentObject].x,objects[currentObject].y);
	
		
	//destroy
	if (state == 3){
		objects[currentObject].active = 0;
		state = 0;
		return;
	}

	//print
	printText(
		explosionAnimation[state],
		objects[currentObject].x,
		objects[currentObject].y
	);

	//inc animation
	state++;
	
}