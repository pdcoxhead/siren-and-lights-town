int piezo = 0;
int redled = 9;
int greenled = 10;
int blueled = 11;

int piezoSensitivity = 1;

long clRed   =   0xFF0000;
long clGreen =   0x00FF00;
long clBlue  =   0x0000FF;
long clWhite =   0xFFFFFF;
long clMagenta = 0xFF00FF;
long clYellow =  0xFFFF00;
long clCyan =    0x00FFFF;
long clPurple =  0x800080;
long clPink =    0xFFC0CB;

int duration = 4000;
double delta = 1000;
double deltaCircle = (2 * M_PI)/delta;

void setRGBColour(long value)
{

    short iRGB[3];
    iRGB[2] = value & 0xFF;          //BLUE
    iRGB[1] = (value >> 0x8) & 0xFF;   //GREEN
    iRGB[0] = (value >> 0x10) & 0xFF;   //RED
    
    analogWrite(redled,   iRGB[0]);
    analogWrite(greenled, iRGB[1]);
    analogWrite(blueled,  iRGB[2]); 
}

void setup()
{
   pinMode(piezo, INPUT);
   pinMode(redled, OUTPUT);
   pinMode(greenled, OUTPUT);
   pinMode(blueled, OUTPUT);
   setRGBColour(clRed);
   delay(10);
   
   setRGBColour(clGreen);
   delay(250);
   setRGBColour(clBlue);
   delay(250);
   setRGBColour(clYellow);
   delay(250);
   setRGBColour(clMagenta);
   delay(250);
   setRGBColour(clCyan);
   delay(250);
   setRGBColour(clPink);
   delay(250);
 }
 int sirenMode = 0;
 enum eHero
 {
  eBatman,
  eGreenLattern,
  eSpiderman 
 };
 eHero HeroMode = eBatman;

void loop()
{
  if (HeroMode == eBatman)
  {
     setRGBColour(clYellow);
     delay(duration);
     HeroMode = eGreenLattern;
  }
  else if (HeroMode == eGreenLattern)
  {
    setRGBColour(clGreen);
    delay(duration / 4);

    setRGBColour(clWhite);
    delay(duration / 4);

    setRGBColour(clGreen);    
    delay(duration / 4);
    
    setRGBColour(clWhite);
    delay(duration / 4);
     HeroMode = eSpiderman;
  }
  else if (HeroMode == eSpiderman)
  {
    setRGBColour(clBlue);
    delay(duration / 4);

    setRGBColour(clRed);
    delay(duration / 4);

    setRGBColour(clBlue);    
    delay(duration / 4);
    
    setRGBColour(clRed);
    delay(duration / 4);
     HeroMode = eBatman;
  }
}

