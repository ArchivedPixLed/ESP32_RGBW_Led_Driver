# ESP32_RGBW_Led_Driver :sheep: :rainbow:
A C++ esp-idf library to drive RGB and RGBW led strips in a smart way.

It allows you to seamlessly drive RGB **and** RGBW strips, with the same HSB or RGB commands. Currently, WS2812 and SK6812 (RGB and RGBW) are supported, but any led type can be easily added. You can also potentially drive any led strip with custom durations (for [RGB strips](https://pixled.github.io/ESP32_RGBW_Led_Driver/classRGB__Strip.html#a9e827e6aa443285a811a11df0b64f5aa) and [RGBW strips](https://pixled.github.io/ESP32_RGBW_Led_Driver/classRGBW__Strip.html#a9d6003c75a32d2f9eec4af86caa1cea1)).

Registered led strips can be used instanciating the right C++ class.

This library is designed to be minimal, and only includes functions to set up each pixel color in RGB or HSB, without any animations or whatever.

# Get Started
## Install
### 1. Install ESP-IDF 
If not done yet, check the official [esp-idf documentation](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html).

### 2. Clone this project
`git clone https://github.com/PixLed/ESP32_RGBW_Led_Driver`

### 3. Set up an ESP-IDF project.

See the [esp-idf documentation](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html#step-5-start-a-project)

Because the library is written in C++, you should replace `main.c` by `main.cpp` and declare a main function as follow :
```
extern "C" {
   void app_main();
}

void app_main() {
   // Your code goes here
}
```

You can also directly use this repository as a project.

To be able to compile C++, you also need to "Enable C++ exceptions", as the esp-idf compiler will recall you. To do so : `make menuconfig` -> `Compiler options` -> `Enable C++ exceptions` (use `space` to select)

### 4. Copy libraries in your own project

Copy the content of the `components` folder in the `components` directory of your own project.

### 5. Drive your leds!

# Example

A complete example is available [there](https://github.com/PixLed/ESP32_RGBW_Led_Driver/blob/master/main/main.cpp).
## Set up your strip
Start instanciating your led strip, according to you led type :
```
SK6812W strip = SK6812W((gpio_num_t) SK6812_PIN, NUM_LED, RMT_CHANNEL_0);
```
Following commands are then available **whatever the type of your leds is**.

## Set colors
In RGB :
```
strip.setPixel(i, red, green, blue);
```
In HSB :
```
strip.setHSBPixel(i, hue, saturation, brightness);
```
For RGBW strips, the white component will automatically be computed. For more details, see the [reference](https://pixled.github.io/ESP32_RGBW_Led_Driver/LedStrip_8cpp.html).

You can also set the white component manually using :
```
strip.setPixel(i, red, green, blue, white);
```

## Show colors
Once all your pixels are set up, you can send them to your strip with :
```
strip.show();
```

# Reference
The complete C++ reference is available directly in the code, and online [there](https://pixled.github.io/ESP32_RGBW_Led_Driver/).

# Have fun! :sheep: :rainbow:

# Credits
Original `ws2812` library and content of `components/cpp_utils` from [nkolban's repository](https://github.com/nkolban/esp32-snippets).
