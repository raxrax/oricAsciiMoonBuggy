// data[0] - speed
// data[1] - char
// data[2] - '0' = destroy
void starUpdate()
{

    unsigned char speed = (char) objects[currentObject].data[0] - 48;

    printChar(' ', objects[currentObject].x, objects[currentObject].y);
    objects[currentObject].x += speed;

    if (objects[currentObject].x > 39)
    {
        objects[currentObject].y = rand() % 17 + 2;
        objects[currentObject].x = 2;
        if (objects[currentObject].data[2] == '0')
            objects[currentObject].active = 0;
        return;
    }
    printChar(objects[currentObject].data[1], objects[currentObject].x, objects[currentObject].y);
}
