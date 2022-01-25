#include <microLED.h>
#include <FastLEDsupport.h> // вкл поддержку

#define LEDPIN 12
#define Button 9
bool flag = false;
microLED<30, LEDPIN, MLED_NO_CLOCK, LED_WS2818, ORDER_GRB, CLI_AVER> strip;
int center = 15;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
pinMode(Button,INPUT_PULLUP);
strip.setBrightness(60);
strip.clear();
strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  Check_button();
  
  if (flag == true) // Если флаг Поднят по нажатию кнопки, выводим изображение на ленту
  {
    Flag_on();
    
  }
  else // Если флаг опущен тушим ленту
  {
    strip.clear();
    strip.show();
    delay(1);
  }

}

void Flag_on()
{
  for (int i = 0; i < 15; i++) {
  strip.leds[center - i]=mRed;
  strip.leds[center + i]= mGreen;
  strip.show();
  delay(100);
  
  }
  
}

void Flag_off()
{
  strip.clear();
  strip.show();
}

void Check_button() //Функция проверки нажатия кнопки
{
 if  (digitalRead(Button) == LOW) //Если кнопка нажата
 {
  flag = true; // перевернуть флаг на противоположное состояние
 }
 else{flag=false;}
}
