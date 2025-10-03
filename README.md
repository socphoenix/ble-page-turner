# ble-page-turner
Bluetooth Low Energy page turner for arduino/esp32. Made to fit as compactly as possible (i.e. into a glasses case).

Most page turners come in large form factors that are fantastic for pianists and others with free feet. As an organist this is not the case. This projects goal was to compress one of these down to a size I can fit under the keyboard with velcro to operate with my knee. The code uses pin 4 as back, pin 2 as forward. The prototype case was made from a thin glasses case:
![33521AFB-3A9F-415C-BF17-A7A70DFA2D4F](https://github.com/user-attachments/assets/1ea9bbfc-3b19-4956-bb3e-3811f156132c)
![86C9E136-82E1-405E-BB4C-490275860356](https://github.com/user-attachments/assets/c494d7c2-8011-47a5-9903-a11dd3e2808e)
![EE6370D1-9DFB-41BE-A061-27B61A423291](https://github.com/user-attachments/assets/97e21357-96d2-4fa1-8989-afed2234111f)


I found an esp32 unit that advertised being able to run down to 2.2 volts, so this also gets the benefit in my mind of being powered with user replaceable rechargeable (or not) AAs instead of needing to make sure it is charged.


This project relies on [T-vK's bleKeyboard library](https://github.com/T-vK/ESP32-BLE-Keyboard), with an additional fix that hasn't been committed to master. To access this fix please see [pull request 343](https://github.com/T-vK/ESP32-BLE-Keyboard/pull/343), or I have a fork of this commit [here](https://github.com/socphoenix/ESP32-BLE-Keyboard). Many thanks to [Trident Apollo](https://github.com/TriDEntApollO) for the fix of the library!
