int speakerPin = 12;
int length = 16; // the number of notes
char notes[] = "EEDCDEED";
int beats[] = {4, 4, 4, 4, 4, 4, 4, 4}; // 4 beats per note
int tempo = 150;
void playTone(int tone, int duration) {
for (long i = 0; i < duration * 1000L; i += tone * 2) {
digitalWrite(speakerPin, HIGH);
delayMicroseconds(tone);
digitalWrite(speakerPin, LOW);
delayMicroseconds(tone);
}
}
void playNote(char note, int duration) {
char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',
'c', 'd', 'e', 'f', 'g', 'a', 'b',
'x', 'y' };
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
956, 834, 765, 593, 468, 346, 224,
655 , 715 };
int SPEE = 5;
// play the tone corresponding to the note name
for (int i = 0; i < 17; i++) {
if (names[i] == note) {
int newduration = duration/SPEE;
playTone(tones[i], newduration);
}
}
}
void setup() {
pinMode(speakerPin, OUTPUT);
}
void loop() {
for (int i = 0; i < length; i++) {
if (notes[i] == ' ') {
delay(beats[i] * tempo); // rest
} else {
playNote(notes[i], beats[i] * tempo);
}
// pause between notes
delay(tempo);
}
}