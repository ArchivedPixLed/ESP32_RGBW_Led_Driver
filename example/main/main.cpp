/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
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
  SK6812W sk6812 = SK6812W((gpio_num_t) SK6812_PIN, NUM_LED, RMT_CHANNEL_0);
  WS2812 ws2812 = WS2812((gpio_num_t) WS2812_PIN, NUM_LED, RMT_CHANNEL_1);
  while(1) {
    for (int h=0; h < 360; h++) {
      for (int i=0; i < NUM_LED; i++) {
          sk6812.setHSBPixel(i, h, 0.8, 0.7);
          ws2812.setHSBPixel(i, h, 0.8, 0.7);
      }
      sk6812.show();
      ws2812.show();
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    // for (int w=0; w < 255; w++) {
    //   for (int i=0; i < NUM_LED; i++) {
    //       sk6812.setPixel(i, w, w, w);
    //       ws2812.setPixel(i, w, w, w);
    //   }
    //   sk6812.show();
    //   ws2812.show();
    //   vTaskDelay(10 / portTICK_PERIOD_MS);
    // }
    // for (int b=0; b < 250; b++) {
    //   for (int i=0; i < NUM_LED; i++) {
    //       sk6812.setHSBPixel(i, 307, 200, b);
    //       ws2812.setHSBPixel(i, 307, 200, b);
    //   }
    //   sk6812.show();
    //   ws2812.show();
    //   vTaskDelay(10 / portTICK_PERIOD_MS);
    // }
  }

}
