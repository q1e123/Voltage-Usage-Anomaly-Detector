void low_voltage_usage(){
//Turn all lights RED
    for( int i=0; i<NUM_LEDS; i++){
        leds[i] = CRGB(255, 0, 0);
        FastLED.show();
    }
}

void medium_voltage_usage(){
    //Trun all lights purple and flash
    for(int i = 0; i<NUM_LEDS; i++){
        leds[i] = CRGB(255, 0, 255);
        FastLED.setBrightness(6*i);
        FastLED.show();
        delay(50);
    }

}

void high_voltage_usage(){
    //Turn lights from blue to magenta from right to left
    for( int i=NUM_LEDS; i>0; i--){
        leds[i = CRGB(20*i,0, 255-20*i);
        FastLED.setBrightness(60-2*i);
        FastLED.show();
        delay(50);
    
}
