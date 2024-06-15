#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 16
int sound_sensor = A2; // assign to pin A2
int smoothSoundValue = 0; // variable to store the smoothed sound value
const int alpha = 10; // smoothing factor

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  strip.begin(); 
  strip.show();
  Serial.begin(9600); // begin Serial Communication
}

void loop()
{
  int soundValue = 0; // create variable to store many different readings
  for (int i = 0; i < 32; i++) // create a for loop to read 
              { 
    soundValue += analogRead(sound_sensor);  
  } // read the sound sensor
 
  soundValue >>= 5; // bitshift operation 
  Serial.println(soundValue); // print the value of sound sensor

  // Smooth the sound value using exponential moving average
  smoothSoundValue = (alpha * soundValue + (100 - alpha) * smoothSoundValue) / 100;

  // Increase sensitivity by adjusting the mapping range
  int ledsToLight = map(smoothSoundValue, 0, 256, 0, NUM_LEDS); // Increased sensitivity

  // Ensure the value is within range
  ledsToLight = constrain(ledsToLight, 0, NUM_LEDS);

  // Clear all LEDs
  strip.clear();

  // Light up the calculated number of LEDs with a gradient color
  for(int i = 0; i < ledsToLight; i++) {
    uint32_t color = getColorForSoundValue(smoothSoundValue);
    strip.setPixelColor(i, color); // Set LED color
  }
  
  strip.show();
  delay(100); // increase delay to reduce flickering
}

uint32_t getColorForSoundValue(int soundValue) {
  // Map the sound value to a color ranging from green to red
  int r, g, b;
  if (soundValue < 64) { // Green to Yellow
    r = map(soundValue, 0, 63, 0, 255);
    g = 255;
    b = 0;
  } else if (soundValue < 128) { // Yellow to Orange
    r = 255;
    g = map(soundValue, 64, 127, 255, 165);
    b = 0;
  } else if (soundValue < 192) { // Orange to Red
    r = 255;
    g = map(soundValue, 128, 191, 165, 0);
    b = 0;
  } else { // Red
    r = 255;
    g = 0;
    b = 0;
  }
  return strip.Color(r, g, b);
}
