
#define VELOCITY 127
 
#define MIDI_ON_CH1 0x90
#define MIDI_OFF_CH1 0x80
#define MIDI_ON_CH2 0x91
#define MIDI_OFF_CH2 0x81


void setup() {
  // put your setup code here, to run once:
  Serial.begin(31250);
}

void loop() {
  // Note on message
  SEND_MIDI(MIDI_ON_CH1, 60, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 60, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 64, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 67, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 60, 0);
  SEND_MIDI(MIDI_ON_CH1, 64, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 64, 0);
  SEND_MIDI(MIDI_ON_CH1, 67, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 67, 0);
  SEND_MIDI(MIDI_OFF_CH2, 60, 0);
  SEND_MIDI(MIDI_OFF_CH2, 64, 0);
  SEND_MIDI(MIDI_OFF_CH2, 67, 0);
  delay(1000);
  
  SEND_MIDI(MIDI_ON_CH1, 72, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 72, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 76, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 79, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 72, 0);
  SEND_MIDI(MIDI_ON_CH1, 76, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 76, 0);
  SEND_MIDI(MIDI_ON_CH1, 79, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 79, 0);
  SEND_MIDI(MIDI_OFF_CH2, 72, 0);
  SEND_MIDI(MIDI_OFF_CH2, 76, 0);
  SEND_MIDI(MIDI_OFF_CH2, 79, 0);
  delay(1000);

  SEND_MIDI(MIDI_ON_CH1, 48, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 48, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 52, VELOCITY);
  SEND_MIDI(MIDI_ON_CH2, 55, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 48, 0);
  SEND_MIDI(MIDI_ON_CH1, 52, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 52, 0);
  SEND_MIDI(MIDI_ON_CH1, 55, VELOCITY);
  delay(500);
  SEND_MIDI(MIDI_OFF_CH1, 55, 0);
  SEND_MIDI(MIDI_OFF_CH2, 48, 0);
  SEND_MIDI(MIDI_OFF_CH2, 52, 0);
  SEND_MIDI(MIDI_OFF_CH2, 55, 0);
  delay(2000);
}

void SEND_MIDI(byte cate, byte note, byte velo) {
  byte data[3] = {cate, note, velo};
  for (byte i = 0 ; i < 3 ; i++) Serial.write(data[i]);
}
