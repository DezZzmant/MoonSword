#define COLOR_DEBTH 3
#define LEDPIN 12
#define Button 9
#define NUMLEDS 30
#include <microLED.h>
#include <FastLEDsupport.h> // вкл поддержку

int brig = 17;
bool flag = false;
microLED<30, LEDPIN, MLED_NO_CLOCK, LED_WS2818, ORDER_GRB, CLI_AVER> strip;
int center = 15;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
pinMode(Button,INPUT_PULLUP);
strip.setBrightness(120);
strip.clear();
strip.show();
delay(100);

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
  for (int i = 0; i < 15; i++) 
  {
  strip.leds[center - i]=mHSV(120, 255, brig);
  strip.show();
  strip.leds[center + i]=mHSV(120, 255, brig);
  strip.show();
  brig+=17;
 delay(1000);
  }
  //for (int i = 0; i < NUMLEDS / 2; i++) strip.leds[i] = mHSV(0, 255, 255);      // красный
  //for (int i = NUMLEDS / 2; i < NUMLEDS; i++) strip.leds[i] = mHSV(80, 255, 255); // примерно зелёный
  //strip.show(); // выводим изменения
  //delay(2000);
  
  
  
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
