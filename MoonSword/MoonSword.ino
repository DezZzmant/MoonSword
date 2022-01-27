#define COLOR_DEBTH 3
#define LEDPIN 12
#define Button 9
#define NUMLEDS 60
#include <microLED.h>
#include <FastLEDsupport.h> // вкл поддержку
DEFINE_GRADIENT_PALETTE( heatmap_gp ) {   // делаем палитру огня
  0, 0, 0, 0,     // black
  255, 0, 255, 120,   // RGB
  255, 0, 255, 170,  // RGB2
  255, 0, 255, 60  // RGB3
};
CRGBPalette16 fire_p = heatmap_gp;
bool gReverseDirection = false;
int brig = 255;
bool flag = false;
microLED<0, LEDPIN, MLED_NO_CLOCK, LED_WS2818, ORDER_GRB, CLI_AVER> strip;
int center = 15;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
pinMode(Button,INPUT_PULLUP);
strip.setBrightness(60);
strip.clear();
strip.show();
delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (flag == true) // Если флаг Поднят по нажатию кнопки, выводим изображение на ленту
  {
    Flag_on();
  }
  else // Если флаг опущен тушим ленту
  {
    Fire1();
  }

}

void Flag_on()
{
  microLED<NUMLEDS, LEDPIN, MLED_NO_CLOCK, LED_WS2818, ORDER_GRB, CLI_AVER> strip;
  strip.clear();
  int brig = 255;
  for (int i = 0; i < NUMLEDS / 2; i++) 
  {
  strip.leds[center - i]=mHSV(120, 255, brig);
  strip.show();
  strip.leds[center + i]=mHSV(120, 255, brig);
  strip.show();
  brig-=25;
 delay(10);
  }
  for(int i=255;i>=60;i--)
 {
  strip.setBrightness(i);
  strip.show();
  delay(10);
 }
  flag=false;
  delay(100);
}

void Flag_off()
{
  strip.clear();
  strip.show();
}

void Check_button() //Функция проверки нажатия кнопки
{
 if  (digitalRead(Button) == HIGH) //Если кнопка нажата
 {
  flag = true; 
 }
 else{flag=false;}
}

void Fire1()
{
  Check_button();
  microLED<0, LEDPIN, MLED_NO_CLOCK, LED_WS2818, ORDER_GRB, CLI_AVER> strip;
  static int count = 0;
  count += 10;
  strip.begin();
  for (int i = 0; i < 50; i++)
    strip.send(CRGBtoData(ColorFromPalette(fire_p, inoise8(i * 25, count), 255, LINEARBLEND)));
  strip.end();
  delay(30);
  Check_button();
}
