#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 2
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0

const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};

int KARE1[8][8] =	{
                    {0,0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,0},
                    {0,1,1,1,1,1,1,0},
                    {0,0,0,0,0,0,0,0}
};

int KARE2[8][8] =	{{1,1,1,1,1,1,1,1},
                    {1,0,0,0,0,0,0,1},
                    {1,0,1,1,1,1,0,1},
                    {1,0,1,1,1,1,0,1},
                    {1,0,1,1,1,1,0,1},
                    {1,0,1,1,1,1,0,1},
                    {1,0,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1,1}};

int KARE3[8][8] =	{{1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1},
                    {1,1,0,0,0,0,1,1},
                    {1,1,0,1,1,0,1,1},
                    {1,1,0,1,1,0,1,1},
                    {1,1,0,0,0,0,1,1},
                    {1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1}};

int KARE4[8][8] =	{{1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1},
                    {1,1,1,0,0,1,1,1},
                    {1,1,1,0,0,1,1,1},
                    {1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1},
                    {1,1,1,1,1,1,1,1}};

void setup() {
  for (int i = 2; i <= 17; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  lcd.begin(16, 2);
}

void loop() {

  lcd.print("Pharmacy 1+1");
  for (int c=0; c<22; c++){
    drawScreen(KARE1);
  }
  lcd.clear();
  delay(444);
	
  lcd.print("Low prices");
  for (int c=0; c<22; c++){
    drawScreen(KARE2);
  }
  lcd.clear();
  delay(444);
  
  lcd.print("Open 24/7");
  for (int c=0; c<22; c++){
    drawScreen(KARE3);
  }
  lcd.clear();
  delay(444);
  
  lcd.print("Best medicines");
  for (int c=0; c<22; c++){
    drawScreen(KARE4);

  }
  lcd.clear();
  delay(444);
  
  lcd.print("Loyal employees");
  for (int c=0; c<22; c++){
    drawScreen(KARE3);
  }
  lcd.clear();
  delay(444);
  
  lcd.print("www.pharmacy.com");
  for (int c=0; c<22; c++){
    drawScreen(KARE2);

  }
  lcd.clear();
  delay(444);

}

void  drawScreen(int letter[8][8]){
  for (int c=0; c<8; c++){

    digitalWrite(col[c], HIGH);
    for (int r = 0; r < 8; r++){
      digitalWrite(row[r], letter[r][c]);
      delayMicroseconds(100);
    }

    for (int r = 0; r < 8; r++){
      digitalWrite(row[r], HIGH);
      delayMicroseconds(100);
    }

    digitalWrite(col[c], LOW);
  }

}