#include <MIDI.h>


int Ch = 2;
MIDI_CREATE_DEFAULT_INSTANCE();

void setup()
{
  Serial.begin(9600);
  MIDI.begin(Ch);
}
 
void loop()
{
    //チャンネル選択
 
    uint8_t data1,data2;
    if (MIDI.read()) {
        MIDI.setInputChannel(Ch);   //読み込むチャンネルを設定
        switch(MIDI.getType()) {
            case midi::NoteOn:        //鍵盤を押す
                data1 = MIDI.getData1();    // ノートNo.（音階）
                data2 = MIDI.getData2();    // ベロシティ（音の強さ）
                Serial.println(String(data1)+","+String(data2));
            break;
            case midi::NoteOff:       //鍵盤を離す
                data1 = MIDI.getData1();    // ノートNo.（音階）
                data2 = MIDI.getData2();    // ベロシティ（音の強さ）
                Serial.println(String(data1)+","+String(data2));
            break;
            case midi::ProgramChange: //音色の切り替え
                data1 = MIDI.getData1();    //プログラムNo.（音色）
                Serial.println(data1);
            break;
            case midi::PitchBend:     //音程（ピッチ）
                data1 = MIDI.getData1();    // ＭＳＢ
                data2 = MIDI.getData2();    // ＬＳＢ
                
 
                int Pitch = data2;
                Pitch = Pitch * 128 + data1 - 8192;
                Serial.println(String(data1)+","+String(data2)+","+String(Pitch));
            break;
 
        }
    }
}
