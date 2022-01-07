#include <MIDI.h>
#include <Digitizer.h>
#include <Keyboard.h>

#include "combination.h"

MIDI_CREATE_DEFAULT_INSTANCE();

int keypress(int num);
int keyrelease(int num);
int mouseclick(int num);


class ReceiveMIDI{  //LEDを点滅させる
  public:
  void noteon(int ch,int note){
    switch(ch){
      case 1:
        mouseclick(note);
        break;
      case 2:
        keypress(note);
        break;
    }
  }
  void noteoff(int ch,int note){
    switch(ch){
      case 1:
        break;
      case 2:
        keyrelease(note);
        break;
    }
  }
};  //ReceiveMIDI

class Interrupt{
  int interruptPin;
  int itrptState;
  
  public:
  Interrupt(int pin){ //(割り込みをするピン)
    interruptPin = pin;
    pinMode(interruptPin,INPUT_PULLUP); //スイッチのみで割り込みできるようにプルアップしている（タクトスイッチなどでGNDとピンを繋ぐ→stateがtrueに）
    itrptState = LOW;
  }
  void Update(){
    if((itrptState == LOW)&&(digitalRead(interruptPin) == LOW)){  //割り込まれていない状態でピンがLOWになったとき
      itrptState = HIGH;
      Serial.println("on");
    }else if((itrptState == HIGH)&&(digitalRead(interruptPin) == HIGH)){  //割り込まれている状態でピンがHIGHになったとき
      itrptState = LOW;
      Serial.println("off");
    }
  }
};  //Interrupt






int mouseclick(int num){
  /*TODO 位置を指定する!!!*/
  //Digitizer.move(DISPLAY_RESOLUTION_X/2,DISPLAY_RESOLUTION_Y/2);
  //Digitizer.click();
#if DEBUG >= 1
      Serial.println("click "+String(num));
#endif
}

int keypress(int num){
#if DEBUG >= 1
      //Serial.println("keypress");
      Serial.print("2: ");
#endif
  if(digitalRead(7) == LOW){
  switch (num){
    case 48:
      Keyboard.press(KEYLOWC); //Low C
#if DEBUG >= 1
      Serial.println("LowC");
#endif
      break;
    case 50:
      Keyboard.press(KEYLOWD); //Low D
#if DEBUG >= 1
      Serial.println("LowD");
#endif
      break;
    case 52:
      Keyboard.press(KEYLOWE); //Low E
#if DEBUG >= 1
      Serial.println("LowE");
#endif
      break;
    case 53:
      Keyboard.press(KEYLOWF); //Low F
#if DEBUG >= 1
      Serial.println("LowF");
#endif
      break;
    case 55:
      Keyboard.press(KEYLOWG); //Low G
#if DEBUG >= 1
      Serial.println("LowG");
#endif
      break;
    case 57:
      Keyboard.press(KEYLOWA); //Low A
#if DEBUG >= 1
      Serial.println("LowA");
#endif
      break;
    case 59:
      Keyboard.press(KEYLOWH); //Low H
#if DEBUG >= 1
      Serial.println("LowH");
#endif
      break;
    case 60:
      Keyboard.press(KEYC); //C
#if DEBUG >= 1
      Serial.println("C");
#endif
      break;
    case 62:
      Keyboard.press(KEYD); //D
#if DEBUG >= 1
      Serial.println("D");
#endif
      break;
    case 64:
      Keyboard.press(KEYE); //E
#if DEBUG >= 1
      Serial.println("E");
#endif
      break;
    case 65:
      Keyboard.press(KEYF); //F
#if DEBUG >= 1
      Serial.println("F");
#endif
      break;
    case 67:
      Keyboard.press(KEYG); //G
#if DEBUG >= 1
      Serial.println("G");
#endif
      break;
    case 69:
      Keyboard.press(KEYA); //A
#if DEBUG >= 1
      Serial.println("A");
#endif
      break;
    case 71:
      Keyboard.press(KEYH); //H
#if DEBUG >= 1
      Serial.println("H");
#endif
      break;
    case 72:
      Keyboard.press(KEYHIGHC); //High C
#if DEBUG >= 1
      Serial.println("HighC");
#endif
      break;
    case 74:
      Keyboard.press(KEYHIGHD); //High D
#if DEBUG >= 1
      Serial.println("HighD");
#endif
      break;
    case 76:
      Keyboard.press(KEYHIGHE); //High E
#if DEBUG >= 1
      Serial.println("HighE");
#endif
      break;
    case 77:
      Keyboard.press(KEYHIGHF); //High F
#if DEBUG >= 1
      Serial.println("HighF");
#endif
      break;
    case 79:
      Keyboard.press(KEYHIGHG); //High G
#if DEBUG >= 1
      Serial.println("HighG");
#endif
      break;
    case 81:
      Keyboard.press(KEYHIGHA); //High A
#if DEBUG >= 1
      Serial.println("HighA");
#endif
      break;
    case 83:
      Keyboard.press(KEYHIGHH); //High H
#if DEBUG >= 1
      Serial.println("HighH");
#endif
    default:
#if DEBUG >= 1
      Serial.println("none");
#endif
      return 0;
  }
  }else{  //debug(7 != LOW)
    switch (num){
    case 48:
#if DEBUG >= 1
      Serial.println("LowC");
#endif
      break;
    case 50:
#if DEBUG >= 1
      Serial.println("LowD");
#endif
      break;
    case 52:
#if DEBUG >= 1
      Serial.println("LowE");
#endif
      break;
    case 53:
#if DEBUG >= 1
      Serial.println("LowF");
#endif
      break;
    case 55:
#if DEBUG >= 1
      Serial.println("LowG");
#endif
      break;
    case 57:
#if DEBUG >= 1
      Serial.println("LowA");
#endif
      break;
    case 59:
#if DEBUG >= 1
      Serial.println("LowH");
#endif
      break;
    case 60:
#if DEBUG >= 1
      Serial.println("C");
#endif
      break;
    case 62:
#if DEBUG >= 1
      Serial.println("D");
#endif
    case 64:
#if DEBUG >= 1
      Serial.println("E");
#endif
      break;
    case 65:
#if DEBUG >= 1
      Serial.println("F");
#endif
    case 67:
#if DEBUG >= 1
      Serial.println("G");
#endif
      break;
    case 69:
#if DEBUG >= 1
      Serial.println("A");
#endif
      break;
    case 71:
#if DEBUG >= 1
      Serial.println("H");
#endif
      break;
    case 72:
#if DEBUG >= 1
      Serial.println("HighC");
#endif
      break;
    case 74:
#if DEBUG >= 1
      Serial.println("HighD");
#endif
      break;
    case 76:
#if DEBUG >= 1
      Serial.println("HighE");
#endif
      break;
    case 77:
#if DEBUG >= 1
      Serial.println("HighF");
#endif
      break;
    case 79:
#if DEBUG >= 1
      Serial.println("HighG");
#endif
      break;
    case 81:
#if DEBUG >= 1
      Serial.println("HighA");
#endif
      break;
    case 83:
#if DEBUG >= 1
      Serial.println("HighH");
#endif
      break;
    default:
#if DEBUG >= 1
      Serial.println("none");
#endif
      return 0;
  }
  }
  return 1;
}

int keyrelease(int num){
    switch (num){
    case 48:
      Keyboard.release(KEYLOWC); //Low C
      break;
    case 50:
      Keyboard.release(KEYLOWD); //Low D
      break;
    case 52:
      Keyboard.release(KEYLOWE); //Low E
      break;
    case 53:
      Keyboard.release(KEYLOWF); //Low F
      break;
    case 55:
      Keyboard.release(KEYLOWG); //Low G
      break;
    case 57:
      Keyboard.release(KEYLOWA); //Low A
      break;
    case 59:
      Keyboard.release(KEYLOWH); //Low H
      break;
    case 60:
      Keyboard.release(KEYC); //C
      break;
    case 62:
      Keyboard.release(KEYD); //D
      break;
    case 64:
      Keyboard.release(KEYE); //E
      break;
    case 65:
      Keyboard.release(KEYF); //F
      break;
    case 67:
      Keyboard.release(KEYG); //G
      break;
    case 69:
      Keyboard.release(KEYA); //A
      break;
    case 71:
      Keyboard.release(KEYH); //H
      break;
    case 72:
      Keyboard.release(KEYHIGHC); //High C
      break;
    case 74:
      Keyboard.release(KEYHIGHD); //High D
      break;
    case 76:
      Keyboard.release(KEYHIGHE); //High E
      break;
    case 77:
      Keyboard.release(KEYHIGHF); //High F
      break;
    case 79:
      Keyboard.release(KEYHIGHG); //High G
      break;
    case 81:
      Keyboard.release(KEYHIGHA); //High A
      break;
    case 83:
      Keyboard.release(KEYHIGHH); //High H
      break;
    default:
      return 0;
  }
  return 1;
}

ReceiveMIDI midi1;
Interrupt itrpt1(7);  //7番ピンをGNDに落とす(ボタンを押す)と割り込み(state == true)


void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(115200);
  Keyboard.begin();
  Digitizer.setDisplayResolution(0, 0, DISPLAY_RESOLUTION_X, DISPLAY_RESOLUTION_Y);
  Digitizer.setLogicalResolution(0, 0, LOGICAL_RESOLUTION_X, LOGICAL_RESOLUTION_Y);
  pinMode(7,INPUT_PULLUP);
}

void loop() {
  uint8_t data1;
    if (MIDI.read()) {
        midi::Channel ch = MIDI.getChannel();
        switch(MIDI.getType()) {
            case midi::NoteOn:        //鍵盤を押す
              data1 = MIDI.getData1();    // ノートNo.（音階）
              midi1.noteon(ch,data1);
              //Serial.println("NoteOn "+String(ch)+","+String(data1));
              break;
            case midi::NoteOff:       //鍵盤を離す
              data1 = MIDI.getData1();    // ノートNo.（音階）
              midi1.noteoff(ch,data1);
              //Serial.println("NoteOff "+String(ch)+","+String(data1));
              break;
            default:
              break;
        }
    }
}
