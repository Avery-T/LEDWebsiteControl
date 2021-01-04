#include "FastLED.h" 
#define NUM_LEDS 300 
#define DATA_PIN 6
#define MAX_BRIGHTNESS 255 


/// to do 
//make brightness while loop return the action code
// to stop the while loop
CRGB leds[NUM_LEDS];

bool powerBtn(int); 
char changeBrightness(); 
char changeColor(); 
void clearSerial();
void waitForInput();
//bool powerOff = true;


void setup() 
{
  FastLED.addLeds<WS2811,DATA_PIN>(leds, NUM_LEDS); 
  Serial.begin(9600);
  Serial.setTimeout(5);
}

//implement all functionalaity in case statement
//make sure each function returns a new action 
void loop() 
{
  int powerCounter = 0, colorCounter = 0; 
  char newLedAction = 'o'; // any website action will turn leds on
  bool powerOff = false;
  clearSerial(); 
  waitForInput(); 
  
  while(!powerOff) 
  {
    Serial.print(newLedAction); 
    switch(newLedAction) 
    {
      case 'b': 
        newLedAction = changeBrightness();
        break;  
      case 'c':
        newLedAction = changeColor(colorCounter+=1);
        break;
      case 'o': 
       powerOff = powerBtn(powerCounter+=1);
       //powering it off makes it wait for power on input
      default:
       clearSerial(); 
       waitForInput();
       newLedAction = Serial.read();   
       break; 
    }
  }
}

char changeBrightness()
{
  int brightnessPrev;
  clearSerial();  
  waitForInput();
  char action = Serial.read(); 
  int brightness = Serial.parseInt();

  while(brightness)
  {
    Serial.print(brightness);
    //brightnessPrev = brightness; 
    FastLED.setBrightness(MAX_BRIGHTNESS * (brightness)/100);
    FastLED.show();
    clearSerial();  
    waitForInput();
    action = Serial.read();  
    if(action != ' ' || action != 'b')
      return action; 
    brightness = Serial.parseInt();
  } 
 }
   
bool powerBtn(int tempCounter)
{
  bool powerOff = false; 
  
  if(tempCounter % 2) 
    fill_solid(leds,NUM_LEDS,CRGB(0,255,0));
  else
  {
    FastLED.clear(); 
    powerOff = true;  
  }
  FastLED.show();
  return powerOff;   
}
char changeColor(int tempCounter)
{
  if(tempCounter % 2) 
    fill_solid(leds,NUM_LEDS,CRGB(0,0,225));
  else
    fill_solid(leds,NUM_LEDS,CRGB(0,255,0));
    
  FastLED.show();
  clearSerial();  
  waitForInput();
  return Serial.read();    
}
 
void clearSerial()
{
  while(Serial.available()) 
     Serial.read(); 
}
void waitForInput()
{
  while(!Serial.available()); 
}
