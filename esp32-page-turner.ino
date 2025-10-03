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

BleKeyboard bleKeyboard("bt page turner");
#define back 4
#define next 2

void setup() {
  // put your setup code here, to run once:
  pinMode(back, INPUT_PULLUP);
  pinMode(next, INPUT_PULLUP);
  bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected() && digitalRead(back) == 0) {
    bleKeyboard.write(218);
    delay(1000);
  }
  else if(bleKeyboard.isConnected() && digitalRead(next) == 0) {
    bleKeyboard.write(217);
    delay(1000);
  }
}
