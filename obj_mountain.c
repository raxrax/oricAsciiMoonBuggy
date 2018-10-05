#define OBJ_MOUNTAIN 9

//char *mountain[5] = {
//    "            /\\          /\\            ",
//    "   /\\      /  \\  /\\    /  \\      /\\   ",
//    "  /  \\/\\  /    \\/  \\  /   /\\  /\\/  \\  ",
//    " /    \\ \\/      \\   \\/   /  \\/ /    \\ ",
//    "/      \\/        \\      /    \\/      \\"
//};

static char *mountain[5] = {
    "        /---\\          _/-\\           ",
    "    .--/\\/\\_ \\        /    \\      ___ ",
    "  _/        \\/\\\\__   /\\/\\  /\\  __/   \\",
    "\\/         _/  /  \\ /  . \\/  \\/ . \\\\_/",
    " /    __   /  /    /./      -.\\ _    _"
};

void mountainUpdate()
{
    int i;
    static unsigned char offset;
    static unsigned char update;

    update++;
    if (update < 10 && update > 1) return;

    update = 1;
    offset++;

    if (offset == 38) offset = 0;

    for (i = 0; i < 5; i++)
    {
        memcpy((void *) getpos(objects[currentObject].x, objects[currentObject].y + i), mountain[i]+(38 - offset), offset);
        memcpy((void *) getpos(offset + objects[currentObject].x, objects[currentObject].y + i), mountain[i], 38 - offset);
    }

}