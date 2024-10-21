#include <FastLED.h>

#define LED_PIN     14
#define NUM_LEDS    64
#define BRIGHTNESS  10
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

// Digit images for numbers 0-9
const uint8_t IMAGES[][8] = {
    {
        0b00000000,
        0b00011000,
        0b00011000,
        0b00111000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b01111110
    },
    {
        0b00000000,
        0b00111100,
        0b01100110,
        0b00000110,
        0b00001100,
        0b00110000,
        0b01100000,
        0b01111110
    },
    {
        0b00000000,
        0b00111100,
        0b01100110,
        0b00000110,
        0b00011100,
        0b00000110,
        0b01100110,
        0b00111100
    },
    {
        0b00000000,
        0b00001100,
        0b00011100,
        0b00101100,
        0b01001100,
        0b01111110,
        0b00001100,
        0b00001100
    },
    {
        0b00000000,
        0b01111110,
        0b01100000,
        0b01111100,
        0b00000110,
        0b00000110,
        0b01100110,
        0b00111100
    },
    {
        0b00000000,
        0b00111100,
        0b01100110,
        0b01100000,
        0b01111100,
        0b01100110,
        0b01100110,
        0b00111100
    },
    {
        0b00000000,
        0b01111110,
        0b01100110,
        0b00001100,
        0b00001100,
        0b00011000,
        0b00011000,
        0b00011000
    },
    {
        0b00000000,
        0b00111100,
        0b01100110,
        0b01100110,
        0b00111100,
        0b01100110,
        0b01100110,
        0b00111100
    },
    {
        0b00000000,
        0b00111100,
        0b01100110,
        0b01100110,
        0b00111110,
        0b00000110,
        0b01100110,
        0b00111100
    },
    {
        0b00000000,
        0b00111100,
        0b01100110,
        0b01101110,
        0b01110110,
        0b01100110,
        0b01100110,
        0b00111100
    }
};

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
    for (int number = 9; number >= 0; number--) {
        displayNumber(number);
        delay(1000); // Delay for 1 second between numbers
    }
}

void displayNumber(int number) {
    // Clear the matrix
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    
    // Define colors for each number
    CRGB colors[10] = {
        CRGB::Red,
        CRGB::Green,
        CRGB::Blue,
        CRGB::Yellow,
        CRGB::Magenta,
        CRGB::Cyan,
        CRGB::White,
        CRGB::Orange,
        CRGB::Purple,
        CRGB::Pink
    };
    
    // Get the bitmap for the current number
    const uint8_t *bitmap = IMAGES[number];

    // Draw the number on the LED matrix
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (bitmap[y] & (1 << (7 - x))) {
                leds[y * 8 + x] = colors[number]; // Set LED to the corresponding color
            }
        }
    }

    FastLED.show(); // Update the LED display
}
