#include <SparkFun_LED_8x7.h>
#include <Chaplex.h>

// Global variables
static byte led_pins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // Pins for LEDs

void setup() {

  // Initialize LED array
  Plex.init(led_pins);

  // Clear display
  Plex.clear();
  Plex.display();
}

void loop(int a=10) {
  if (a<0)Plex.scrollText("Anomaly");
  else if (a>0)Plex.scrollText("Not an Anomaly");
  Plex.display();
  delay(10000);
}