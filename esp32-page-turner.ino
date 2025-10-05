// bluetooth low energy page turner using esp32
// Copyright (C) 2025 Michael Bell

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <BleKeyboard.h>
#include "driver/rtc_io.h"

BleKeyboard bleKeyboard("MBs page turner");
#define back 4
#define next 2
#define wakeup_back GPIO_NUM_4
#define wakeup_next GPIO_NUM_2
//#define BUTTON_PIN_BITMASK ((1ULL >> 2) | (1ULL >> 4))
#define BUTTON_PIN_BITMASK(GPIO) (1ULL << GPIO)
uint64_t bitmask = BUTTON_PIN_BITMASK(wakeup_back) | BUTTON_PIN_BITMASK(wakeup_next);
#define USE_EXT0_WAKEUP 0


void setup() {
  // put your setup code here, to run once:
  pinMode(back, INPUT_PULLUP);
  pinMode(next, INPUT_PULLUP);
  pinMode(22, OUTPUT);
  digitalWrite(22, LOW);
  bleKeyboard.begin();
  esp_sleep_enable_ext1_wakeup_io(bitmask, ESP_EXT1_WAKEUP_ALL_LOW);
  rtc_gpio_pullup_en(wakeup_back);
  rtc_gpio_pulldown_dis(wakeup_back);
  rtc_gpio_pullup_en(wakeup_next);
  rtc_gpio_pulldown_dis(wakeup_next);
  delay(1000);
}

void loop() {
  if(digitalRead(back) == 0 && digitalRead(next) == 0) {
    digitalWrite(22, HIGH);
    delay(1000);
    esp_deep_sleep_start();
  }
  else if(bleKeyboard.isConnected() && digitalRead(next) == 0) {
    bleKeyboard.write(217);
    delay(1000);
  }
  else if(bleKeyboard.isConnected() && digitalRead(back) == 0) {
    bleKeyboard.write(218);
    delay(1000);
  }
}
