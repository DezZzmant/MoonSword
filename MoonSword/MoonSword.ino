#include <microLED.h>
#include <FastLEDsupport.h> // вкл поддержку

#define LEDPIN 12
#define Button 5
bool flag = false;
microLED<30, LEDPIN, -1, LED_WS2818, ORDER_GRB, CLI_AVER> strip;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Check_button();
  
  if (flag == true) // Если флаг Поднят по нажатию кнопки, выводим изображение на ленту
  {
    
  }
  else // Если флаг опущен тушим ленту
  {
    
  }

}

void Led_on()
{
  
}

void Led_off()
{
  
}

void Check_button() //Функция проверки нажатия кнопки
{
 if  (digitalRead(Button) == HIGH) //Если кнопка нажата
 {
  flag = !flag; // перевернуть флаг на противоположное состояние
 }
}
