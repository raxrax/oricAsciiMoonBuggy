//data[0] - type
void bombUpdate()
{
	printChar(' ', objects[currentObject].x, objects[currentObject].y);
	
	switch (objects[currentObject].data[0]){
		case '0': //type1
		case '1': //type2
			objects[currentObject].y++;
			
			if (objects[currentObject].y%2)
				objects[currentObject].x++;
			
			switch(objects[currentObject].y){
				case JEEP_Y+1:
				objects[currentObject].active = 0;
				if (objects[currentObject].data[0] == '1')
					addObject(OBJ_OBSTACLE,objects[currentObject].x,JEEP_Y+1,"~  ");
				return;
			}
			
			switch (objects[currentObject].x){
				case 39:
				objects[currentObject].active = 0;
				return;
			}
		break;
	}
	printChar(objects[currentObject].data[1], objects[currentObject].x, objects[currentObject].y);
}