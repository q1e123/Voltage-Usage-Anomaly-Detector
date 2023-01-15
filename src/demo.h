//Includem biblioteca FastLED
#include <FastLED.h>
//Definim pinul care leaga placa Arduino de banda LED
#define LED_PIN 2
//Definim cate becuri LED sa fie folosite
#define NUM_LEDS 70
//Creăm un vector de tip CRGB 
CRGB leds[NUM_LEDS];

void setup() {
  //Declaram banda LED, in cazul nostru modelul este WS2812, impreuna cu pinul, si calibrarea RGB
  FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
  //Setam o putere maxima de 5V, respectiv 500mA
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
}

void low_voltage_usage(){
    //Aprinde toate ledurile roșii
    for( int i=0; i<NUM_LEDS; i++){
        leds[i] = CRGB(255, 0, 0);
        FastLED.show();
    }
}


void medium_voltage_usage(){
    //Aprinde toate ledurile mov intermitent.
    for(int i = 0; i<NUM_LEDS; i++){
        leds[i] = CRGB(255, 0, 255);
        FastLED.setBrightness(6*i);
        FastLED.show();
        delay(50);
    }

}

void high_voltage_usage(){
    //Aprinde toate ledurile din albastru in magenta de la stanga la dreapta.
    for( int i=NUM_LEDS; i>0; i--){
        leds[i = CRGB(20*i,0, 255-20*i);
        FastLED.setBrightness(60-2*i);
        FastLED.show();
        delay(50);
}

