#include <stdio.h>
#include "LedStrip.h"
#include "freertos/task.h"

#define WS2812_PIN 14
#define SK6812_PIN 12
#define NUM_LED 5

extern "C" {
   void app_main();
}

void app_main()
{
  // Set up an sk6812 RGBW strip on RMT_CHANNEL_0, pin 14
  SK6812W sk6812 = SK6812W((gpio_num_t) SK6812_PIN, NUM_LED, RMT_CHANNEL_0);

  // Set up a ws2812 RGB strip on RMT_CHANNEL_1, pin 12
  WS2812 ws2812 = WS2812((gpio_num_t) WS2812_PIN, NUM_LED, RMT_CHANNEL_1);

  while(1) {
    for (int h=0; h < 360; h++) {
      // Set colors
      for (int i=0; i < NUM_LED; i++) {
          // Seamlessly drive RGB and RGBW strips with the same HSB command.
          // For the sk6812, the white led is also used in the computed color.
          sk6812.setHSBPixel(i, h, 0.8, 0.7);
          ws2812.setHSBPixel(i, h, 0.8, 0.7);
      }
      // Show colors
      sk6812.show();
      ws2812.show();
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
  }

}
