#include "matrix.h"

int XY(int x, int y) {
  /**
   * Maps the correct cartesian coordinate to an array index.
   * 
   * @param x the x coordinate
   * @param y the y coordinate
   * @return the proper array index
  **/
  return y*COLS + x;
}

int XY_canvas(int x, int y) {
  /**
   * Maps the correct cartesian coordinate to the LED string canvas. Accounts for padding.
   * 
   * @param x the x coordinate of the image pixel
   * @param y the y coordinate of the image pixel
   * @return i the index of the FastLED array to manipulate
  **/
  int i;
  int j = XY(x, y);
  int q = (j/COLS)*PADDING;

  if (y&1) {
    int rX = COLS - 1 - x;
    i = y * COLS + rX + q;
  } else {
    i = j + q;
  }
  return i;
}

void loadImage(struct CRGB *leds_dest, const unsigned char *img) {
  /**
   * Loads input image onto the canvas.
   * 
   * @param leds_dest the canvas destination to map the image onto
   * @param img image list of length 3 * number of pixels
   * @return None
   * 
   * After calling this function, buffers are filled with the appropriate image data.
   * FastLED.show() must be called afterwards to update the LED string.
  **/
  int source_index = 0;
  int dest_index = 0;
  for (int j=0; j<ROWS; j++) {
    for (int i=0; i<COLS; i++) {
      source_index = 3*XY(i,j);
      dest_index = XY_canvas(i,j);
      leds_dest[ XY_canvas(i,j) ].r = pgm_read_word_near(img + source_index);
      leds_dest[ XY_canvas(i,j) ].g = pgm_read_word_near(img + source_index + 1);
      leds_dest[ XY_canvas(i,j) ].b = pgm_read_word_near(img + source_index + 2);
    }
  }
}

void loadColor(struct CRGB *leds_dest, struct CRGB color) {
  /**
   * Loads a color onto the canvas
   * 
   * @param leds_dest the canvas destination to load a color onto
   * @param color the color to fill the canvas with
   * @return None
   * 
   * After calling this function, buffers are filled with the appropriate color data.
   * FastLED.show() must be called afterwards to update the LED string.
  **/
  for (int j = 0; j < ROWS; j++) {
    for (int i = 0; i < COLS; i++) {
      leds_dest[XY_canvas(i, j)] = color;
    }
  }
}

void indexDebug(struct CRGB *leds_dest, struct CRGB color) {
  /**
   * Debug function to check whether the LED string matrix has been properly set up.
   * Iterates through the canvas and turns on single LED in order
   * 
   * @param leds_dest the canvas destination to load a color onto
   * @param color the color to fill the canvas with
   * @return None
  **/
  for (int j = 0; j < ROWS; j++) {
    for (int i = 0; i < COLS; i++) {
      leds_dest[XY_canvas(i, j)] = color;
      FastLED.show();
      delay(50);
    }
  }
  delay(500);
  FastLED.clear();
  FastLED.show();
}
