void executeUpdate()
{
    switch (objects[currentObject].type)
    {
        case OBJ_STAR:
            starUpdate();
            break;
        case OBJ_TEXT:
            textUpdate();
            break;
        case OBJ_TEXT_ONCE:
            textOnceUpdate();
            break;
        case OBJ_JEEP:
            jeepUpdate();
            break;
        case OBJ_LASER:
            laserUpdate();
            break;
        case OBJ_OBSTACLE:
            obstacleUpdate();
            break;
        case OBJ_GAME_MANAGER:
            gameManagerUpdate();
            break;
        case OBJ_MENU:
            menuUpdate();
            break;
        case OBJ_MOUNTAIN:
            mountainUpdate();
            break;
        case OBJ_TEXT_TEMP:
            textTempUpdate();
            break;
        case OBJ_SHIP:
            shipUpdate();
            break;
        case OBJ_FALLING_STAR:
            fallingStarUpdate();
            break;
        case OBJ_EARTH:
            earthUpdate();
            break;
        case OBJ_TRAP:
            trapUpdate();
            break;
        case OBJ_BASE:
            baseUpdate();
            break;
		case OBJ_MISSILE:
            missileUpdate();
            break;
		case OBJ_UFO:
            UFOUpdate();
            break;
		case OBJ_BOMB:
            bombUpdate();
            break;
		case OBJ_EXPLOSION:
            explosionUpdate();
            break;	
		case OBJ_METEOR:
            meteorsUpdate();
            break;				
    }

    /**
        if (objects[currentObject].type == OBJ_STAR) starUpdate();
        if (objects[currentObject].type == OBJ_TEXT) textUpdate();
        if (objects[currentObject].type == OBJ_TEXT_ONCE) textOnceUpdate();
        if (objects[currentObject].type == OBJ_JEEP) jeepUpdate();
        if (objects[currentObject].type == OBJ_LASER) laserUpdate();
        if (objects[currentObject].type == OBJ_OBSTACLE) obstacleUpdate();
        if (objects[currentObject].type == OBJ_GAME_MANAGER) gameManagerUpdate();
        if (objects[currentObject].type == OBJ_MENU) menuUpdate();
        if (objects[currentObject].type == OBJ_MOUNTAIN) mountainUpdate();
        if (objects[currentObject].type == OBJ_TEXT_TEMP) textTempUpdate();
        if (objects[currentObject].type == OBJ_SHIP) shipUpdate();
        if (objects[currentObject].type == OBJ_FALLING_STAR) fallingStarUpdate();

     */
}