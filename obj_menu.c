void menuUpdate()
{
	int rand = rand()%30;
    if (key1 == 13) engineRunning = 0;

    printText("\007                .              ", objects[currentObject].x, objects[currentObject].y);
    printText("\007._ _  _  _ ._   |_ . . _  _   .", objects[currentObject].x, objects[currentObject].y + 1);
    printText("\007[ | )(_)(_)[ )  [_)(_|(_](_]\\_|", objects[currentObject].x, objects[currentObject].y + 2);
    printText("\007                      ._|._|._|", objects[currentObject].x, objects[currentObject].y + 3);

    printText("\007'SPACE' - Jump    '<' - Left", objects[currentObject].x, objects[currentObject].y + 6);
    printText("\007  'Z'   - Laser   '>' - Right", objects[currentObject].x, objects[currentObject].y + 7);
    printText("\007  'X'   - Missile 'P' - Pause", objects[currentObject].x, objects[currentObject].y + 8);

    printText("\007       'ENTER' - Start", objects[currentObject].x, objects[currentObject].y + 10);
}