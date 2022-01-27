[33mcommit db53e49aea621f8f2a47ea9463bd3b0285ded54b[m[33m ([m[1;36mHEAD -> [m[1;32mmain[m[33m, [m[1;31morigin/main[m[33m)[m
Author: DezZzmant <semy91@mail.ru>
Date:   Wed Jan 26 02:27:13 2022 +0500

    almost work

[1mdiff --git a/MoonSword/MoonSword.ino b/MoonSword/MoonSword.ino[m
[1mindex 273800f..ad4f5e4 100644[m
[1m--- a/MoonSword/MoonSword.ino[m
[1m+++ b/MoonSword/MoonSword.ino[m
[36m@@ -2,13 +2,17 @@[m
 #include <FastLEDsupport.h> // вкл поддержку[m
 [m
 #define LEDPIN 12[m
[31m-#define Button 5[m
[32m+[m[32m#define Button 9[m
 bool flag = false;[m
[31m-microLED<30, LEDPIN, -1, LED_WS2818, ORDER_GRB, CLI_AVER> strip;[m
[31m-[m
[32m+[m[32mmicroLED<30, LEDPIN, MLED_NO_CLOCK, LED_WS2818, ORDER_GRB, CLI_AVER> strip;[m
[32m+[m[32mint center = 15;[m
 void setup() {[m
   // put your setup code here, to run once:[m
[31m-[m
[32m+[m[32m  //Serial.begin(9600);[m
[32m+[m[32mpinMode(Button,INPUT_PULLUP);[m
[32m+[m[32mstrip.setBrightness(60);[m
[32m+[m[32mstrip.clear();[m
[32m+[m[32mstrip.show();[m
 }[m
 [m
 void loop() {[m
[36m@@ -17,29 +21,41 @@[m [mvoid loop() {[m
   [m
   if (flag == true) // Если флаг Поднят по нажатию кнопки, выводим изображение на ленту[m
   {[m
[32m+[m[32m    Flag_on();[m
     [m
   }[m
   else // Если флаг опущен тушим ленту[m
   {[m
[31m-    [m
[32m+[m[32m    strip.clear();[m
[32m+[m[32m    strip.show();[m
[32m+[m[32m    delay(1);[m
   }[m
 [m
 }[m
 [m
[31m-void Led_on()[m
[32m+[m[32mvoid Flag_on()[m
 {[m
[32m+[m[32m  for (int i = 0; i < 15; i++) {[m
[32m+[m[32m  strip.leds[center - i]=mRed;[m
[32m+[m[32m  strip.leds[center + i]= mGreen;[m
[32m+[m[32m  strip.show();[m
[32m+[m[32m  delay(100);[m
[32m+[m[41m  [m
[32m+[m[32m  }[m
   [m
 }[m
 [m
[31m-void Led_off()[m
[32m+[m[32mvoid Flag_off()[m
 {[m
[31m-  [m
[32m+[m[32m  strip.clear();[m
[32m+[m[32m  strip.show();[m
 }[m
 [m
 void Check_button() //Функция проверки нажатия кнопки[m
 {[m
[31m- if  (digitalRead(Button) == HIGH) //Если кнопка нажата[m
[32m+[m[32m if  (digitalRead(Button) == LOW) //Если кнопка нажата[m
  {[m
[31m-  flag = !flag; // перевернуть флаг на противоположное состояние[m
[32m+[m[32m  flag = true; // перевернуть флаг на противоположное состояние[m
  }[m
[32m+[m[32m else{flag=false;}[m
 }[m
