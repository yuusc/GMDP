import themidibus.*; // 注１
import ddf.minim.ugens.Frequency;

MidiBus myBus;
HashMap<String, Boolean> pressedKeys = new HashMap<String, Boolean>();


void setup() {
  size(1920,1080);
  MidiBus.list();
  myBus = new MidiBus(this, -1, 1); // 注２
  myBus.sendMessage(192, 3); // 注３
  int ltx,lty, xspan, yspan, extent;
  ltx = 350;
  lty = 600;
  xspan = 200;
  yspan = 150;
  extent = 120;
  
  for(int i=0;i<7;i++){
    int posx = ltx+xspan*i;
    for(int j = 0; j<3;j++){
      int posy = lty+yspan*j;
      circle(posx,posy,120);
    }
  }
  
}

void draw() {
}

void keyPressed() {
  if(mousePressed){
    notenumber();
  }
  String pitchName = getPitchName();
  if (pitchName == null) return;
  if (pressedKeys.getOrDefault(pitchName, false)) return;

  midisend(pitchName);
  pressedKeys.put(pitchName, true);
}

void keyReleased() {
  String pitchName = getPitchName();
  if (pitchName == null) return;

  myBus.sendNoteOff(0, (int) Frequency.ofPitch(pitchName).asMidiNote(), 127);
  pressedKeys.put(pitchName, false);
}

String getPitchName() {
  switch (key) {
    case 'z': return "C3";
    case 'x': return "D3";
    case 'c': return "E3";
    case 'v': return "F3";
    case 'b': return "G3";
    case 'n': return "A3";
    case 'm': return "B3";
    case 'a': return "C4";
    case 's': return "D4";
    case 'd': return "E4";
    case 'f': return "F4";
    case 'g': return "G4";
    case 'h': return "A4";
    case 'j': return "B4";
    case 'q': return "C5";
    case 'w': return "D5";
    case 'e': return "E5";
    case 'r': return "F5";
    case 't': return "G5";
    case 'y': return "A5";
    case 'u': return "B5";
  }

  return null;
}

void mouseClicked(){
  notenumber();
}

void notenumber(){
//クリックすると、ここの処理が実行
//マウスの位置情報を取得　mouseX,mouseY
  int ltx,lty, xspan, yspan, extent;
  ltx = 350;
  lty = 600;
  xspan = 200;
  yspan = 150;
  extent = 120;
  String pitchName;
  if(mouseX>=ltx-(extent/2) && mouseX<=ltx+(extent/2) && mouseY>=lty-(extent/2) && mouseY<=lty+(extent/2)){
    pitchName = "C5";
  }else if(mouseX>=ltx-(extent/2)+xspan*1 && mouseX<=ltx+(extent/2)+xspan*1 && mouseY>=lty-(extent/2) && mouseY<=lty+(extent/2)){
    pitchName = "D5";
  }else if(mouseX>=ltx-(extent/2)+xspan*2 && mouseX<=ltx+(extent/2)+xspan*2 && mouseY>=lty-(extent/2) && mouseY<=lty+(extent/2)){
    pitchName = "E5";
  }else if(mouseX>=ltx-(extent/2)+xspan*3 && mouseX<=ltx+(extent/2)+xspan*3 && mouseY>=lty-(extent/2) && mouseY<=lty+(extent/2)){
    pitchName = "F5";
  }else if(mouseX>=ltx-(extent/2)+xspan*4 && mouseX<=ltx+(extent/2)+xspan*4 && mouseY>=lty-(extent/2) && mouseY<=lty+(extent/2)){
    pitchName = "G5";
  }else if(mouseX>=ltx-(extent/2)+xspan*5 && mouseX<=ltx+(extent/2)+xspan*5 && mouseY>=lty-(extent/2) && mouseY<=lty+(extent/2)){
    pitchName = "A5";
  }else if(mouseX>=ltx-(extent/2)+xspan*6 && mouseX<=ltx+(extent/2)+xspan*6 && mouseY>=lty-(extent/2) && mouseY<=lty+(extent/2)){
    pitchName = "B5";
  }else if(mouseX>=ltx-(extent/2) && mouseX<=ltx+(extent/2) && mouseY>=lty-(extent/2)+yspan*1 && mouseY<=lty+(extent/2)+yspan*1){
    pitchName = "C4";
  }else if(mouseX>=ltx-(extent/2)+xspan*1 && mouseX<=ltx+(extent/2)+xspan*1 && mouseY>=lty-(extent/2)+yspan*1 && mouseY<=lty+(extent/2)+yspan*1){
    pitchName = "D4";
  }else if(mouseX>=ltx-(extent/2)+xspan*2 && mouseX<=ltx+(extent/2)+xspan*2 && mouseY>=lty-(extent/2)+yspan*1 && mouseY<=lty+(extent/2)+yspan*1){
    pitchName = "E4";
  }else if(mouseX>=ltx-(extent/2)+xspan*3 && mouseX<=ltx+(extent/2)+xspan*3 && mouseY>=lty-(extent/2)+yspan*1 && mouseY<=lty+(extent/2)+yspan*1){
    pitchName = "F4";
  }else if(mouseX>=ltx-(extent/2)+xspan*4 && mouseX<=ltx+(extent/2)+xspan*4 && mouseY>=lty-(extent/2)+yspan*1 && mouseY<=lty+(extent/2)+yspan*1){
    pitchName = "G4";
  }else if(mouseX>=ltx-(extent/2)+xspan*5 && mouseX<=ltx+(extent/2)+xspan*5 && mouseY>=lty-(extent/2)+yspan*1 && mouseY<=lty+(extent/2)+yspan*1){
    pitchName = "A4";
  }else if(mouseX>=ltx-(extent/2)+xspan*6 && mouseX<=ltx+(extent/2)+xspan*6 && mouseY>=lty-(extent/2)+yspan*1 && mouseY<=lty+(extent/2)+yspan*1){
    pitchName = "B4";
  }else if(mouseX>=ltx-(extent/2) && mouseX<=ltx+(extent/2) && mouseY>=lty-(extent/2)+yspan*2 && mouseY<=lty+(extent/2)+yspan*2){
    pitchName = "C3";
  }else if(mouseX>=ltx-(extent/2)+xspan*1 && mouseX<=ltx+(extent/2)+xspan*1 && mouseY>=lty-(extent/2)+yspan*2 && mouseY<=lty+(extent/2)+yspan*2){
    pitchName = "D3";
  }else if(mouseX>=ltx-(extent/2)+xspan*2 && mouseX<=ltx+(extent/2)+xspan*2 && mouseY>=lty-(extent/2)+yspan*2 && mouseY<=lty+(extent/2)+yspan*2){
    pitchName = "E3";
  }else if(mouseX>=ltx-(extent/2)+xspan*3 && mouseX<=ltx+(extent/2)+xspan*3 && mouseY>=lty-(extent/2)+yspan*2 && mouseY<=lty+(extent/2)+yspan*2){
    pitchName = "F3";
  }else if(mouseX>=ltx-(extent/2)+xspan*4 && mouseX<=ltx+(extent/2)+xspan*4 && mouseY>=lty-(extent/2)+yspan*2 && mouseY<=lty+(extent/2)+yspan*2){
    pitchName = "G3";
  }else if(mouseX>=ltx-(extent/2)+xspan*5 && mouseX<=ltx+(extent/2)+xspan*5 && mouseY>=lty-(extent/2)+yspan*2 && mouseY<=lty+(extent/2)+yspan*2){
    pitchName = "A3";
  }else if(mouseX>=ltx-(extent/2)+xspan*6 && mouseX<=ltx+(extent/2)+xspan*6 && mouseY>=lty-(extent/2)+yspan*2 && mouseY<=lty+(extent/2)+yspan*2){
    pitchName = "B3";
  }else{
    return;
  }
  midisend(pitchName);
}

void midisend(String pitchName){
  myBus.sendNoteOn(0, (int) Frequency.ofPitch(pitchName).asMidiNote(), 127);
}
