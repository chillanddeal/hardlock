
//  Welcome to Laser Piano Puzzle ver 1.o
//  Arduino IDE ver 1.8.4
//  Created for ATmega328P with internal clock 8MHz
//  Remember to burn bootloader with internal clock settings
//  Schematic included filename : laserpianoschematic


int sensorValue = 0;                                                      //variable to storage sensor data
int threshold = 880;                                                      //sensor value above which norhing happens
int test = 0;                                                             //variable to storage test switch data
String key = "1111111";                                                   //variable to storage input key
String password = "3220340";                                              //password must be from behind!
const int bum =  2;                                                       //PIN on which magic happens :D
int toneDuration = 200;                                                   //time of laser sound in ms
int tones[] = { 196, 220, 247, 262, 294, 330 };                           //decide which note plays on pins
int melody[] = {   196, 294, 262, 196, 247, 247, 262,                     //sound track of test melody (notes)
                   0,   196, 262, 196, 247, 247, 262};
int noteDurations[] = {    4, 4, 4, 4, 3, 3, 4,                           //sound track of test melody (sound last time)
                           4, 4, 4, 4, 3, 3, 4 };
void setup() {
              pinMode(bum, OUTPUT);                                       //PIN for magic :D
              pinMode(0, INPUT);                                         //PIN for test melody
              }

void loop() {                                     // M    A  I    N           L   O   O   P
  
key.remove(7);                                                            //cuts key to 6 digits
if (key == password) {                                                    //check if key is correct
                   digitalWrite(bum, HIGH);                               //KKKKKKKKAAAAAAAAAAAAABBBBBBBBBBBBBUUUUUUUUUUUUUUMMMMMMMMMMMMMMMM!!!!!!!!!!!!!!!!
                   }


                                                    // SENSOR READ AND NOTE PLAYN FUNCTION

for (int sensorPin = 0; sensorPin < 6; sensorPin++) {                     // TO CHANGE NUMBER OF LASERS CHANGE X VALUE (sensorPin < X;) AND ADD NOTES IN TONES[] MAX 6 on Atmega328!!!
                                         sensorValue = analogRead(sensorPin);
                                         if (sensorValue < threshold) {
                                                                        tone(8, tones[sensorPin], toneDuration);
                                                                        key = sensorPin + key;
                                                                        while (sensorValue < threshold) {
                                                                                                          sensorValue = analogRead(sensorPin);
                                                                                                          delay(10);
                                                                                                         }
                                                                      }
                                                    }
                                                    // TEST SWITCH READ AND TEST MELODY PLAY FUNCTION

test = digitalRead(0);                                                                             //read test switch PIN

if (test == HIGH) {                                                                                //check if test switch is on
  for (int thisNote = 0; thisNote < 14; thisNote++) {
                                      int noteDuration = 1000 / noteDurations[thisNote];
                                      tone(8, melody[thisNote], noteDuration);
                                      int pauseBetweenNotes = noteDuration * 1.30;
                                      delay(pauseBetweenNotes);
                                      noTone(8);
                                      delay(20);
                                                    }

                         } 
}
