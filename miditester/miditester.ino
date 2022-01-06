
#define MIDI_CH  2
#define VELOCITY 127
byte notes = 48;
 
#define MIDI_ON  0x90|(MIDI_CH - 1)
#define MIDI_OFF 0x80|(MIDI_CH - 1)


void setup() {
  // put your setup code here, to run once:
  Serial.begin(31250);
}

void loop() {
  // Note on message
  SEND_MIDI(MIDI_ON, notes, VELOCITY);
 
  delay(1000);
 
  // Note off message
  SEND_MIDI(MIDI_OFF, notes, VELOCITY);
 
  delay(1000);
}

void SEND_MIDI(byte cate, byte note, byte velo) {
  byte data[3] = {cate, note, velo};
  for (byte i = 0 ; i < 3 ; i++) Serial.write(data[i]);
}
