#include "Keyboard.h"
#define polos 2
#define gula 3
#define lampu 9

void setup() {
    // initialize control over the keyboard:
    Keyboard.begin();
    pinMode(polos,INPUT);
    pinMode(gula,INPUT);
    pinMode(lampu,OUTPUT);
    
    Keyboard.begin();
    delay(5000);
}

void loop() {

    if(digitalRead(polos) == HIGH){
     digitalWrite(lampu,HIGH);
     Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      Keyboard.releaseAll(); 
      delay(4000);

     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
     delay(4000);
   
     Keyboard.print("cd C:/Users/ACER/OneDrive - Universitas Airlangga/Kuliah/Semester 5/Robot Manipulator");
     delay(50);

     Keyboard.press(KEY_RETURN);
     Keyboard.releaseAll();
      Keyboard.print("\"tanpa_gula.cpp\""); //buka file
     delay(50);

      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      delay(5000);

     Keyboard.press(KEY_F11);
      Keyboard.releaseAll();
      delay(10000);

      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      Keyboard.releaseAll();
      delay(1000);

     Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      Keyboard.releaseAll();
     delay(1000);

     Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      Keyboard.releaseAll();
      delay(40900);
      digitalWrite(lampu,LOW);
    }

    //dengan gula GULA
    if(digitalRead(gula) == HIGH){
      digitalWrite(lampu,HIGH);
     Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
     Keyboard.releaseAll(); 
      delay(4000);

      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      delay(4000);
    
      Keyboard.print("cd C:/Users/ACER/OneDrive - Universitas Airlangga/Kuliah/Semester 5/Robot Manipulator");
      delay(50);

      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      Keyboard.print("\"gula.cpp\""); //buka file
      delay(50);

      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      delay(5000);

      Keyboard.press(KEY_F11);
      Keyboard.releaseAll();
      delay(10000);

      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      Keyboard.releaseAll();
      delay(1000);

      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      Keyboard.releaseAll();
      delay(1000);

      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      Keyboard.releaseAll();
      delay(70900);
      digitalWrite(lampu,LOW);
    }


}
