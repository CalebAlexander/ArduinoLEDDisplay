/*#include <led_sysdefs.h>
#include <bitswap.h>
#include <chipsets.h>
#include <color.h>
#include <colorpalettes.h>
#include <colorutils.h>
#include <controller.h>
#include <dmx.h>*/
#include <FastLED.h>
/*#include <fastled_config.h>
#include <fastled_delay.h>
#include <fastled_progmem.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <fastspi_nop.h>
#include <fastspi_ref.h>
#include <fastspi_types.h>
#include <hsv2rgb.h>

#include <lib8tion.h>
#include <noise.h>
#include <pixeltypes.h>
#include <platforms.h>
#include <power_mgt.h>*/


#include <LiquidCrystal.h>

#define NUM_LEDS 150
#define DATA_PIN 4

LiquidCrystal lcd(13,12,11,10,9,8);

CRGB leds[NUM_LEDS];

const int buttonOnePin = 7;
const int buttonTwoPin = 5;
const int buttonThreePin = 6;
const int switchPin = 2;
const int piezoPin = 0;

int count = 0;
int index = 0;
int change = 1;

bool changeLights = false;
int buttonOneState = 0;
int buttonOneLast = 0;
int buttonTwoState = 0;
int buttonTwoLast = 0;
int buttonThreeState = 0;
int buttonThreeLast = 0;

int red = 0;
int green = 0;
int blue = 0;

int pattern = 3; //start with lights off

int menu = 0;
int previousMenu = 0;
int mode = 0;
int previousMode = 0;
int mapC = 1;
int previousMapC = 1;

int temp = 1;

String defaultMenu1 = "Press Button To ";
String defaultMenu2 = "Change Lights  >";
String mode0 = "Random Lights  "; //14 characters long
String mode1 = "Random Lights 2";  //13 characters long
String mode2 = "Temperature Map";         //6  characters
String mode3 = "Lights Out     ";  //13 characters

#define TEMPERATURE_1 Candle
#define TEMPERATURE_2 Tungsten40W
#define TEMPERATURE_3 Tungsten100W
#define TEMPERATURE_4 Halogen
#define TEMPERATURE_5 CarbonArc
#define TEMPERATURE_6 HighNoonSun
#define TEMPERATURE_7 DirectSunlight
#define TEMPERATURE_8 OvercastSky
#define TEMPERATURE_9 ClearBlueSky
#define TEMPERATURE_10 WarmFluorescent
#define TEMPERATURE_11 StandardFluorescent
#define TEMPERATURE_12 CoolWhiteFluorescent
#define TEMPERATURE_13 BlackLightFluorescent
#define TEMPERATURE_14 MercuryVapor
#define TEMPERATURE_15 SodiumVapor
#define TEMPERATURE_16 MetalHalide
#define TEMPERATURE_17 HighPressureSodium

String temp1 = "Candle         ";
String temp2 = "Tungsten 40W   ";
String temp3 = "Tungsten 100W  ";
String temp4 = "Halogen        ";
String temp5 = "Carbon Arc     ";
String temp6 = "High Noon Sun  ";
String temp7 = "Direct SunLight";
String temp8 = "Overcast Sky   ";
String temp9 = "Clear Blue Sky ";
String temp10 = "WarmFluorescent";
String temp11 = "StrdFluorescent";
String temp12 = "CoolFluorescent";
String temp13 = "BlckFluorescent";
String temp14 = "Mercury Vapor  ";
String temp15 = "Sodium Vapor   ";
String temp16 = "Metal Halide   ";
String temp17 = "HighP Sodium   ";

static uint8_t starthue = 0;


void setup() {
  Serial.begin(9600);
  pinMode(buttonOnePin, INPUT);
  pinMode(buttonTwoPin, INPUT);
  pinMode(buttonThreePin, INPUT);
  pinMode(switchPin, INPUT);
  
  delay(1000);
  FastLED.addLeds<WS2811,DATA_PIN>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness(80);
  
  lcd.begin(16,2);
  lcd.cursor();
  lcd.setCursor(0,0);
  lcd.print(defaultMenu1);
  lcd.setCursor(0,1);
  lcd.print(defaultMenu2);

}



void loop() {
  displayMenu();
  checkSensors();
  doPatterns();
}



void doPatterns(){
  if (pattern == 0)
  {
    randomLights();
  }
  else if (pattern == 1)
  {
    randomMovingLights();
  }
  else if (pattern == 2)
  {
    colorMap();
  }
  else if (pattern == 3)
  {
    //do nothing                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
  }
}

void checkSensors(){
  buttonOneState = digitalRead(buttonOnePin);
  buttonTwoState = digitalRead(buttonTwoPin);
  buttonThreeState = digitalRead(buttonThreePin);

  if (digitalRead(switchPin) == HIGH){
    FastLED.setBrightness(analogRead(piezoPin)/8);
  }
  else{
    FastLED.setBrightness(80);
  }
  
  if (buttonOneState != buttonOneLast)
  {
    if (buttonOneState == HIGH)
    {
      Serial.println("Button One Pressed");
      if (menu == 0){
        //do nothing
      }
      else if (menu == 1)
      {
        if (mode == 0){
          //do nothing
        }
        else if(mode == 1){
          mode = 0;
        }
        else if(mode == 2){
          mode = 1;
        }
        else if(mode == 3){
          mode = 2;
        }
        Serial.print("should be scrolling up");
        Serial.print("\tMode: ");
        Serial.println(mode);
      }
      else if(menu ==2)
      {
        if (mapC == 1){
          //do nothing
        }
        else if(mapC == 2){
          mapC = 1;
        }
        else if(mapC == 3){
          mapC = 2;
        }
        else if(mapC == 4){
          mapC = 3;
        }
        else if(mapC == 5){
          mapC = 4;
        }
        else if(mapC == 6){
          mapC = 5;
        }
        else if(mapC == 7){
          mapC = 6;
        }
        else if(mapC == 8){
          mapC = 7;
        }
        else if(mapC == 9){
          mapC = 8;
        }
        else if(mapC == 10){
          mapC = 9;
        }
        else if(mapC == 11){
          mapC = 10;
        }
        else if(mapC == 12){
          mapC = 11;
        }
        else if(mapC == 13){
          mapC = 12;
        }
        else if(mapC == 14){
          mapC = 13;
        }
        else if(mapC == 15){
          mapC = 14;
        }
        else if(mapC == 16){
          mapC = 15;
        }
        else if(mapC == 17){
          mapC = 16;
        }
      }
    }
    delay(10);
  }
  buttonOneLast = buttonOneState;

  if (buttonTwoState != buttonTwoLast)
  {
    if (buttonTwoState == HIGH)
    {
      Serial.println("Button Two Pressed");
      if (menu == 0){
        //do nothing
      }
      else if(menu == 1){
        if (mode == 0){
          mode = 1;
        }
        else if(mode == 1){
          mode = 2;
        }
        else if(mode == 2){
          mode = 3;
        }
        else if(mode == 3){
          //do nothing
        }
        Serial.print("should be scrolling down");
        Serial.print("\tMode: ");
        Serial.println(mode);
      }
      else if(menu == 2){
        if (mapC == 1){
          mapC = 2;
        }
        else if(mapC == 2){
          mapC = 3;
        }
        else if(mapC == 3){
          mapC = 4;
        }
        else if(mapC == 4){
          mapC = 5;
        }
        else if(mapC == 5){
          mapC = 6;
        }
        else if(mapC == 6){
          mapC = 7;
        }
        else if(mapC == 7){
          mapC = 8;
        }
        else if(mapC == 8){
          mapC = 9;
        }
        else if(mapC == 9){
          mapC = 10;
        }
        else if(mapC == 10){
          mapC = 11;
        }
        else if(mapC == 11){
          mapC = 12;
        }
        else if(mapC == 12){
          mapC = 13;
        }
        else if(mapC == 13){
          mapC = 14;
        }
        else if(mapC == 14){
          mapC = 15;
        }
        else if(mapC == 15){
          mapC = 16;
        }
        else if(mapC == 16){
          mapC = 17;
        }
        else if(mapC == 17){
          //do nothing
        }
      }
    }
    delay(10);
  }
  buttonTwoLast = buttonTwoState;

  if (buttonThreeState != buttonThreeLast)
  {
    if (buttonThreeState == HIGH)
    {
      if (menu == 0)
      {
        menu++;//go to the next menu
        Serial.print("Menu: ");
        Serial.print(menu);
        Serial.print("\tPrevious Menu: ");
        Serial.print(previousMenu);
        Serial.print("\tMode: ");
        Serial.print(mode);
        Serial.print("\tPattern: ");
        Serial.println(pattern);
      }
      else if(menu == 1)
      {
        if (mode == 0){
          pattern = 0;// start pattern 1
          menu = 0;
          
          Serial.print("Menu: ");
          Serial.print(menu);
          Serial.print("\tPrevious Menu: ");
          Serial.print(previousMenu);
          Serial.print("\tMode: ");
          Serial.print(mode);
          Serial.print("\tPattern: ");
          Serial.println(pattern);
          mode = 0;
        }
        else if (mode == 1){
          pattern = 1;// start pattern 2
          menu = 0;
          
          Serial.print("Menu: ");
          Serial.print(menu);
          Serial.print("\tPrevious Menu: ");
          Serial.print(previousMenu);
          Serial.print("\tMode: ");
          Serial.print(mode);
          Serial.print("\tPattern: ");
          Serial.println(pattern);
          mode = 0;
        }
        else if (mode == 2){
          //pattern = 2;// start pattern 3
          menu = 2;
          
          Serial.print("Menu: ");
          Serial.print(menu);
          Serial.print("\tPrevious Menu: ");
          Serial.print(previousMenu);
          Serial.print("\tMode: ");
          Serial.print(mode);
          Serial.print("\tPattern: ");
          Serial.println(pattern);
          //mode = 0;
        }
        else if (mode == 3){
          for(int i = 0; i < NUM_LEDS; i++)
          {
            leds[i] = CRGB::Black;
            FastLED.show();
          }
          pattern = 3;//turn off lights
          menu = 0;
          
          Serial.print("Menu: ");
          Serial.print(menu);
          Serial.print("\tPrevious Menu: ");
          Serial.print(previousMenu);
          Serial.print("\tMode: ");
          Serial.print(mode);
          Serial.print("\tPattern: ");
          Serial.println(pattern);
          mode = 0;
        }
      }
      else if (menu == 2){
        if (mapC == 1){
          pattern = 2;
          temp = 1;
          menu = 0;
        }
        else if (mapC == 2){
          pattern = 2;
          temp = 2;
          menu = 0;
        }
        else if (mapC == 3){
          pattern = 2;
          temp = 3;
          menu = 0;
        }
        else if (mapC == 4){
          pattern = 2;
          temp = 4;
          menu = 0;
        }
        else if (mapC == 5){
          pattern = 2;
          temp = 5;
          menu = 0;
        }
        else if (mapC == 6){
          pattern = 2;
          temp = 6;
          menu = 0;
        }
        else if (mapC == 7){
          pattern = 2;
          temp = 7;
          menu = 0;
        }
        else if (mapC == 8){
          pattern = 2;
          temp = 8;
          menu = 0;
        }
        else if (mapC == 9){
          pattern = 2;
          temp = 9;
          menu = 0;
        }
        else if (mapC == 10){
          pattern = 2;
          temp = 10;
          menu = 0;
        }
        else if (mapC == 11){
          pattern = 2;
          temp = 11;
          menu = 0;
        }
        else if (mapC == 12){
          pattern = 2;
          temp = 12;
          menu = 0;
        }
        else if (mapC == 13){
          pattern = 2;
          temp = 13;
          menu = 0;
        }
        else if (mapC == 14){
          pattern = 2;
          temp = 14;
          menu = 0;
        }
        else if (mapC == 15){
          pattern = 2;
          temp = 15;
          menu = 0;
        }
        else if (mapC == 16){
          pattern = 2;
          temp = 16;
          menu = 0;
        }
        else if (mapC == 17){
          pattern = 2;
          temp = 17;
          menu = 0;
        }
      }
    }
    delay(10);
  }
  buttonThreeLast = buttonThreeState;
}

void displayMenu(){
  if (previousMenu != menu || previousMode != mode || previousMapC != mapC)// if the new menu is different from the old menu
  {
    if (menu == 0) // display defualt menu
    {
      Serial.println("should be printing defualt menu");
      lcd.setCursor(0,0);
      lcd.print(defaultMenu1);
      lcd.setCursor(0,1);
      lcd.print(defaultMenu2);
    }
    else if(menu == 1)
    {
      Serial.print("menu = ");
      Serial.println(menu);
      if (mode == 0)
      {
        Serial.println("should be printing mode 0");
        lcd.setCursor(0,0);
        lcd.print(mode0+"<");
        lcd.setCursor(0,1);
        lcd.print(mode1+" ");
      }
      else if (mode == 1)
      {
        Serial.println("should be printing mode 1");
        lcd.setCursor(0,0);
        lcd.print(mode0+" ");
        lcd.setCursor(0,1);
        lcd.print(mode1+"<");
      }
      else if (mode == 2)
      {
        Serial.println("should be printing mode 2");
        lcd.setCursor(0,0);
        lcd.print(mode1+" ");
        lcd.setCursor(0,1);
        lcd.print(mode2+"<");
      }
      else if (mode == 3)
      {
        
        Serial.println("should be printing mode 3");
        lcd.setCursor(0,0);
        lcd.print(mode2+" ");
        lcd.setCursor(0,1);
        lcd.print(mode3+"<");
        
      }
    }
    else if (menu == 2)
    {
      if (mapC == 1){
        lcd.setCursor(0,0);
        lcd.print(temp1+"<");
        lcd.setCursor(0,1);
        lcd.print(temp2+" ");
      }
      else if (mapC == 2){
        lcd.setCursor(0,0);
        lcd.print(temp1+" ");
        lcd.setCursor(0,1);
        lcd.print(temp2+"<");
      }
      else if (mapC == 3){
        lcd.setCursor(0,0);
        lcd.print(temp2+" ");
        lcd.setCursor(0,1);
        lcd.print(temp3+"<");
      }
      else if (mapC == 4){
        lcd.setCursor(0,0);
        lcd.print(temp3+" ");
        lcd.setCursor(0,1);
        lcd.print(temp4+"<");
      }
      else if (mapC == 5){
        lcd.setCursor(0,0);
        lcd.print(temp4+" ");
        lcd.setCursor(0,1);
        lcd.print(temp5+"<");
      }
      else if (mapC == 6){
        lcd.setCursor(0,0);
        lcd.print(temp5+" ");
        lcd.setCursor(0,1);
        lcd.print(temp6+"<");
      }
      else if (mapC == 7){
        lcd.setCursor(0,0);
        lcd.print(temp6+" ");
        lcd.setCursor(0,1);
        lcd.print(temp7+"<");
      }
      else if (mapC == 8){
        lcd.setCursor(0,0);
        lcd.print(temp7+" ");
        lcd.setCursor(0,1);
        lcd.print(temp8+"<");
      }
      else if (mapC == 9){
        lcd.setCursor(0,0);
        lcd.print(temp8+" ");
        lcd.setCursor(0,1);
        lcd.print(temp9+"<");
      }
      else if (mapC == 10){
        lcd.setCursor(0,0);
        lcd.print(temp9+" ");
        lcd.setCursor(0,1);
        lcd.print(temp10+"<");
      }
      else if (mapC == 11){
        lcd.setCursor(0,0);
        lcd.print(temp10+" ");
        lcd.setCursor(0,1);
        lcd.print(temp11+"<");
      }
      else if (mapC == 12){
        lcd.setCursor(0,0);
        lcd.print(temp11+" ");
        lcd.setCursor(0,1);
        lcd.print(temp12+"<");
      }
      else if (mapC == 13){
        lcd.setCursor(0,0);
        lcd.print(temp12+" ");
        lcd.setCursor(0,1);
        lcd.print(temp13+"<");
      }
      else if (mapC == 14){
        lcd.setCursor(0,0);
        lcd.print(temp13+" ");
        lcd.setCursor(0,1);
        lcd.print(temp14+"<");
      }
      else if (mapC == 15){
        lcd.setCursor(0,0);
        lcd.print(temp14+" ");
        lcd.setCursor(0,1);
        lcd.print(temp15+"<");
      }
      else if (mapC == 16){
        lcd.setCursor(0,0);
        lcd.print(temp15+" ");
        lcd.setCursor(0,1);
        lcd.print(temp16+"<");
      }
      else if (mapC == 17){
        lcd.setCursor(0,0);
        lcd.print(temp16+" ");
        lcd.setCursor(0,1);
        lcd.print(temp17+"<");
      }
    }
    previousMenu = menu;
  }
  else
  {
    //keep the same thing on the screen
  }
}


void randomLights(){
  // ************* RANDOM LIGHTS ************************
  /*for (int i = 0; i < NUM_LEDS;i++){
    leds[i].r = random(0,255);
    leds[i].g = random(0,255);
    leds[i].b = random(0,255);
    FastLED.show();
  }*/
  count = random(0, NUM_LEDS);
  leds[count].r = random(0,255);
  leds[count].g = random(0,255);
  leds[count].b = random(0,255);
  FastLED.show();
}

void randomMovingLights(){
  // ******************* RANDOM MOVING LIGHTS **************************************
  
  index += change;
    
  leds[index].r = random(0,255);
  leds[index].g = random(0,255);
  leds[index].b = random(0,255);
  
  if (index >= NUM_LEDS){
    change = -change;
  }
  else if(index <= 0){
    change = -change;  
  }
   
  //leds[index] = CRGB::Black; 
}

void colorMap(){
  
  // draw a generic, no-name rainbow
  
  fill_rainbow( leds + 2, NUM_LEDS - 5, --starthue, 20);

  // Choose which 'color temperature' profile to enable.
  if (temp == 1){
    FastLED.setTemperature( TEMPERATURE_1 ); // first temperature
    leds[0] = TEMPERATURE_1; // show indicator pixel
  }
  else if (temp == 2){
    FastLED.setTemperature( TEMPERATURE_2 ); // first temperature
    leds[0] = TEMPERATURE_2; // show indicator pixel
  }
  else if (temp == 3){
    FastLED.setTemperature( TEMPERATURE_3 ); // first temperature
    leds[0] = TEMPERATURE_3; // show indicator pixel
  }
  else if (temp == 4){
    FastLED.setTemperature( TEMPERATURE_4 ); // first temperature
    leds[0] = TEMPERATURE_4; // show indicator pixel
  }
  else if (temp == 5){
    FastLED.setTemperature( TEMPERATURE_5 ); // first temperature
    leds[0] = TEMPERATURE_5; // show indicator pixel
  }
  else if (temp == 6){
    FastLED.setTemperature( TEMPERATURE_6); // first temperature
    leds[0] = TEMPERATURE_6; // show indicator pixel
  }
  else if (temp == 7){
    FastLED.setTemperature( TEMPERATURE_7 ); // first temperature
    leds[0] = TEMPERATURE_7; // show indicator pixel
  }
  else if (temp == 8){
    FastLED.setTemperature( TEMPERATURE_8 ); // first temperature
    leds[0] = TEMPERATURE_8; // show indicator pixel
  }
  else if (temp == 9){
    FastLED.setTemperature( TEMPERATURE_9 ); // first temperature
    leds[0] = TEMPERATURE_9; // show indicator pixel
  }
  else if (temp == 10){
    FastLED.setTemperature( TEMPERATURE_10 ); // first temperature
    leds[0] = TEMPERATURE_10; // show indicator pixel
  }
  else if (temp == 11){
    FastLED.setTemperature( TEMPERATURE_11 ); // first temperature
    leds[0] = TEMPERATURE_11; // show indicator pixel
  }
  else if (temp == 12){
    FastLED.setTemperature( TEMPERATURE_12 ); // first temperature
    leds[0] = TEMPERATURE_12; // show indicator pixel
  }
  else if (temp == 13){
    FastLED.setTemperature( TEMPERATURE_13 ); // first temperature
    leds[0] = TEMPERATURE_13; // show indicator pixel
  }
  else if (temp == 14){
    FastLED.setTemperature( TEMPERATURE_14 ); // first temperature
    leds[0] = TEMPERATURE_14; // show indicator pixel
  }
  else if (temp == 15){
    FastLED.setTemperature( TEMPERATURE_15 ); // first temperature
    leds[0] = TEMPERATURE_15; // show indicator pixel
  }
  else if (temp == 16){
    FastLED.setTemperature( TEMPERATURE_16 ); // first temperature
    leds[0] = TEMPERATURE_16; // show indicator pixel
  }
  else{
    FastLED.setTemperature( TEMPERATURE_17 ); // first temperature
    leds[0] = TEMPERATURE_17; // show indicator pixel
  }
  


  FastLED.show();
  FastLED.delay(8);
  
}


