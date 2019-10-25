# My-MiDi-KeyboardPS-2-Arduino
A program for Arduino that turns the keyboardPS/2 into an 8-bit synthesizer
Данная программа позволяет сделать из платы Arduino Uno, простейшего динамика и клавиатуры PS/2 простой синтезатор, 
с режимом воспроизведения заранее записанной в прошивку музыки.
1. Подключите клавиатуру:
* пин данных во 2 вход
* пин синхронизации в 3 вход
* 5V
2. Подключите динамик:
* VCC c последовательным резистором в 8 вход
* GND к земле
3. Загрузите прошивку в память микроконтроллера

Схема подключения:
![Схема подключения](https://github.com/Shar170/My-MiDi-KeyboardPS-2-Arduino/blob/master/connecting.jpg?raw=true)
