#define C5  523    //도
#define D5  587    //레
#define E5  659    //미
#define F5  698    //파
#define G5  784   //솔
#define A5  880   //라
#define B5  988   //시
#define C6  1047  //도


int tonepin = 12;


int melody[] = {
C5,C5,C5,C5,C5,
E5,G5,G5,E5,C5,
G5,G5,E5,G5,G5,E5,
C5,C5,C5,

G5,G5,E5,C5,
G5,G5,G5,
G5,G5,E5,C5,
G5,G5,G5,

G5,G5,E5,C5,
G5,G5,G5,A5,G5,
C6,G5,C6,G5,
E5,D5,C5
};

int noteDurations[]={
4,8,8,4,4,
4,8,8,4,4,
8,8,4,8,8,4,
4,4,2,
4,4,4,4,
4,4,2,
4,4,4,4,
4,4,2,
4,4,4,4,
8,8,8,8,2,
4,4,4,4,
4,4,2
};


void setup() { 
} 
void loop() {
  for (int i = 0; i < sizeof(melody); i++) {
    
    int Durations = 1000/noteDurations[i];    // 음계의 음길이 계산
    tone(tonepin, melody[i], Durations);    
    int pauseBetweenNotes = Durations *1.3 ;
    delay(pauseBetweenNotes);
    noTone(tonepin);
  }

}
