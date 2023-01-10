#include <FastLED.h>
#include <SparkFun_LED_8x7.h>
#include <Chaplex.h>
#define joyX A1
#define joyY A2

#define LED_PIN     7
#define NUM_LEDS    50
static byte led_pins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // Pins for LEDs
CRGB leds[NUM_LEDS];

float get_voltage(){

  unsigned int x=0;
float AcsValue=0.0,Samples=0.0,AvgAcs=0.0,AcsValueF=0.0;

  for (int x = 0; x < 20; x++){ //Get 150 samples
  AcsValue = analogRead(A0);     //Read current sensor values   
  Samples = Samples + AcsValue;  //Add samples together
  delay (3); // let ADC settle before next sample 3ms
}
AvgAcs=Samples/150.0;//Taking Average of Samples

//((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
//2.5 is offset(I assumed that arduino is working on 5v so the viout at no current comes
//out to be 2.5 which is out offset. If your arduino is working on different voltage than 
//you must change the offset according to the input voltage)
//0.100v(100mV) is rise in output voltage when 1A current flows at input
AcsValueF = (2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.100;
AcsValueF = AcsValueF / 10;
 return AcsValueF;
}

struct Model{
    double max;
    double min;
};

struct Point{
    double voltage;
};
bool predict(Model model, Point point);
bool predict(Model model, Point point){
    if(model.max >= point.voltage && model.min <= point.voltage){
        return true;
    }
    else{
        return false;
    }
}
Model train(Point train_data[], size_t train_data_size);
Model train(Point train_data[], size_t train_data_size){
    Point * p_end_of_struct = &(train_data[train_data_size-1]);
    Model model;
    model.max = 0;
    model.min = 10000;
    for(Point * ptr = train_data; ptr != p_end_of_struct; ptr+=1){
        if(ptr -> voltage <= model.min){
            model.min = ptr -> voltage;
        }
        if(ptr -> voltage >= model.max){
            model.max = ptr -> voltage;
        }
    }
    return model;


}
Model model;
void setup() {


  //setup leds

  Plex.init(led_pins);

  // Clear display
  Plex.clear();
  Plex.display();

  Serial.begin(9600); //Start Serial Monitor to display current read value on Serial monitor
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  Point training_data[100];
  Serial.println("Started to gather training data");
  for(int i = 0; i<= 100; ++i){
    float voltage = get_voltage();
    Serial.println(voltage);
    Point point;
    point.voltage = voltage;
    training_data[i] = point;
  }
      Serial.println("STARTED TRAINING");

   model = train(training_data, 100);
       Serial.println("TRAINING DONE");
              Serial.println("Model max: ");

       Serial.println(model.max);
       Serial.println("Model min: ");
       Serial.println(model.min);
;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float xValue = analogRead(joyX);
  float yValue = analogRead(joyY);
 
  //print the values with to plot or view
  Serial.print(xValue);
  Serial.print("\ttest");
  Serial.println(yValue);
  
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(500);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(500);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(500);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  for(int i = 0; i <= NUM_LEDS; i++)
  {
    leds[i] = CRGB(255, 0, 0);
    FastLED.show();
  }
  delay(1000);
   for(int i = 0; i <= NUM_LEDS-20; i++)
  {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
  }//Print the read current on Serial monitor
delay(50);

  float voltage = get_voltage();
  Serial.println(voltage);
  Point point;
  point.voltage = voltage;
  bool prediction = predict(model, point);
  if(prediction){
    Serial.println("ANOMALY");
    Plex.scrollText("Anomaly");
  } else {
    Serial.println("GOOD");
    Plex.scrollText("Not an Anomaly");
  }
}
