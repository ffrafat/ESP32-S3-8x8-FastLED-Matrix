#include <FastLED.h>

#define LED_PIN     14 // Pin connected to the LED matrix
#define NUM_LEDS    64  // Number of LEDs in the matrix
#define BRIGHTNESS  50  // Brightness level
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    rainbowCycle(10); // Adjust the speed of the rainbow effect
}

// Fill the screen with a rainbow
void rainbowCycle(uint8_t wait) {
    static uint8_t hue = 0;
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CHSV((i + hue) & 255, 255, 255); // Create rainbow colors
    }
    FastLED.show();
    delay(wait);
    hue++; // Increment hue for the next frame
}
