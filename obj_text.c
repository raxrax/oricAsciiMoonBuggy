
void textUpdate()
{
    printText(objects[currentObject].data, objects[currentObject].x, objects[currentObject].y);
}

void textTempUpdate()
{
    unsigned char i, l;
    char *screenPos;
    int x = objects[currentObject].x > 39 ? 20 - strlen(objects[currentObject].data) / 2 : objects[currentObject].x;

    // print text
    l = strlen(objects[currentObject].data);
    for (i = 1; i < l; i++)
    {
        screenPos = (void *) getpos(x + i - 1, objects[currentObject].y);
        *screenPos = objects[currentObject].data[i];
    }
    //printText(objects[currentObject].data+1,x,objects[currentObject].y);

    objects[currentObject].data[0]--;
    if (objects[currentObject].data[0] == 1)
    {
        memset((void *) getpos(x, objects[currentObject].y), 32, strlen(objects[currentObject].data));
        objects[currentObject].active = 0;
    }
}

void textOnceUpdate()
{
    printText(objects[currentObject].data, objects[currentObject].x, objects[currentObject].y);
    objects[currentObject].active = 0;
}