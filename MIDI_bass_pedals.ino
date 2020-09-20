/*
MIDI On/Off Messages
By Amanda Ghassaei
July 2012
https://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

*/
 
 int velocity = 100;//velocity of MIDI notes, must be between 0 and 127
 //higher velocity usually makes MIDI instruments louder
 
 int noteON = 144;//144 = 10010000 in binary, note on command
 int noteOFF = 128;//128 = 10000000 in binary, note off command

int i = 0;
int val = LOW; //0;
int note = 0;

int state [14] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
int globalNoteOn = LOW;

int ctr = 0;

void setup() {
  //  Set MIDI baud rate:
  //Serial.begin(31250);
  Serial.begin(9600);
  pinMode(0,INPUT_PULLUP);
  //pinMode(1,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(13,INPUT_PULLUP);
  //pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(30);
  ctr = ctr+1;
  globalNoteOn = LOW;
  for (i=0; i<14; ++i) {
  if (state[i] == LOW){
    globalNoteOn = HIGH;
  }
}
//digitalWrite(LED_BUILTIN, globalNoteOn);
for (i=0; i<14; ++i) {
  //val = digitalRead(c_pin);
  val = digitalRead(i);
  note = 35 + i;
  if (i == 0){
    note = 37;
  }
  if (i == 2){
    note = 36;
  }
  //if (c_state!=val){
  if (state[i] != val){
    //c_state= val;
    state[i] = val;
    if (val==LOW){
      MIDImessage(noteON, note, velocity);//turn note on
    }
    else {
      MIDImessage(noteOFF, note, velocity);//turn note off
    }
  } 
}
}

//send MIDI message
void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
Serial.write(command);//send note on or note off command 
Serial.write(MIDInote);//send pitch data
Serial.write(MIDIvelocity);//send velocity data
//Serial.print("noteON, clock cycle: ");
//Serial.println(ctr);
}
