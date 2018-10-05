#define OBJECTS_MAX 18

void executeUpdate();

static struct objectStruct
{
    char type;
    unsigned char active;
    unsigned char x;
    unsigned char y;
    char *data;
};


static char key1;

static unsigned char monitorEnable = 0;
static unsigned char objectsCount;
static unsigned char engineRunning = 0;
static unsigned char currentObject;
static unsigned char systemMinLoad = 10;

static struct objectStruct objects[OBJECTS_MAX];

static int multi40[27] = {0, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400, 440, 480, 520, 560, 600, 640, 680, 720, 760, 800, 840, 880, 920, 960, 1000, 1040};

void initObjects()
{
    unsigned char i;
    for (i = 0; i < OBJECTS_MAX; i++) objects[i].active = 0;

}

int getpos(unsigned x, unsigned y)
{
    return 0xbb80 + x + multi40[y];
}

void wait(int time)
{
    int now;
    if (time < 0) return;
    now = deek(0x276);
    while (now - deek(0x276) < time)
    {
        ;
    }
}

void printText(char *text, unsigned char x, unsigned char y)
{
    memcpy((void *) (0xBB80 + x + multi40[y]), text, strlen(text));
}

void printChar(char c, unsigned char x, unsigned char y)
{
    char *screenPos;
    screenPos = (char *) getpos(x,y);
    *screenPos = c;
}

void addObject(char type, unsigned char x, unsigned char y, char *data)
{
    unsigned char i;
    for (i = 0; i < OBJECTS_MAX; i++)
    {
        if (objects[i].active == 0)
        {
            objects[i].active = 1;
            objects[i].type = type;
            objects[i].x = x;
            objects[i].y = y;
            objects[i].data = data;
            return;
        }
    }
}

void objectProcessing()
{
    unsigned char i;
    objectsCount = 0;
    for (i = 0; i < OBJECTS_MAX; i++)
    {
		switch (objects[i].active){
			case 1:
				currentObject = i;
				objectsCount++;
				executeUpdate(i);
			break;
		}

    }
}

void deleteObject(unsigned char objectNumber)
{
    objects[objectNumber].active = 0;
}

void engine()
{
    engineRunning = 1;
    while (engineRunning == 1)
    {
        key1 = key();
        objectProcessing();
        system();
        if (key1 == 'Q') engineRunning = 0;
    }
}

void system()
{
    int load = 0xffff - deek(0x276);

    if (key1 == '!') monitorEnable = 1 - monitorEnable;
   
    wait(systemMinLoad - load);
	
	if (monitorEnable == 1) sprintf((void *) 0xbb80, "load:%d obj:%d  ", (0xffff - deek(0x276)), objectsCount);
	
    doke(0x276, 0);
}
