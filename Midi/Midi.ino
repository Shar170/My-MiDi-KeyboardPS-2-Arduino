  /*  PS2Keyboard library example
    
    PS2Keyboard now requries both pins specified for begin()
  
    keyboard.begin(data_pin, irq_pin);
    
    Valid irq pins:
       Arduino Uno:  2, 3
       Arduino Due:  All pins, except 13 (LED)
       Arduino Mega: 2, 3, 18, 19, 20, 21
       Teensy 2.0:   All pins, except 13 (LED)
       Teensy 2.0:   5, 6, 7, 8
       Teensy 1.0:   0, 1, 2, 3, 4, 6, 7, 16
       Teensy++ 2.0: 0, 1, 2, 3, 18, 19, 36, 37
       Teensy++ 1.0: 0, 1, 2, 3, 18, 19, 36, 37
       Sanguino:     2, 10, 11
    
    for more information you can read the original wiki in arduino.cc
    at http://www.arduino.cc/playground/Main/PS2Keyboard
    or http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html
    
    Like the Original library and example this is under LGPL license.
    
    Modified by Cuninganreset@gmail.com on 2010-03-22
    Modified by Paul Stoffregen <paul@pjrc.com> June 2010
  */
     
  #include <PS2Keyboard.h>
  PS2Keyboard keyboard;
  const int DataPin = 2;
  const int IRQpin =  3;
  
  const int CountNotes = 11;
  const int CountRows = 4;
  int speakerPin = 8;
  int tempo = 200;
  int startTone = 1600, startTone_old = 1600;
 // int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 870, 800, 770};
  int tones[CountNotes];
  char names[CountRows][CountNotes] = { 
                                          {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '['}, 
                                          {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', char(39)},
                                          {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', ' '},
                                          {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-'}
                                       };
  
  
  void playTone(int tone, int duration,int SpPin ) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
      digitalWrite(SpPin , HIGH);
      delayMicroseconds(tone);
      digitalWrite(SpPin , LOW);
      delayMicroseconds(tone);
    }
  }
  
  void playNote(char note, int duration, int SpPin) {
    // проиграть тон, соответствующий ноте
    for(int j = 0; j< CountRows-1; j++)
      for (int i = 0; i < CountNotes; i++)
        if (names[j][i] == note) playTone((double(4/(j+1))*tones[i]), duration, SpPin);
    // проиграть макрос
    for (int i = 0; i < CountNotes; i++)
      if (names[CountRows-1][i] == note) playMacros(i);
  }

  void RestartTone(int start){
     for(int i =0; i < CountNotes; i++)
      tones[i] = start - i*(double(start)/CountNotes - 20);
  }
  
  void setup() {
    pinMode(A0, INPUT);
    //startTone = analogRead(A0) + 1000;
   // startTone_old = startTone;
    RestartTone(startTone);
    
    pinMode(speakerPin, OUTPUT);
    delay(500);
    
    keyboard.begin(DataPin, IRQpin);
    //Serial.begin(9600);
   // Serial.println("MIDI keyboard by Shar170");
  }
  
  void loop() {
    tempo = int( double(analogRead(A0))/5 + 25);
   /* if (abs(startTone - startTone_old) < 10){
      //RestartTone(startTone);
      tempo = startTone;
      startTone_old = startTone;
    }*/
    
    if (keyboard.available()) {      
      // read the next key
      char c = keyboard.read();
      playNote(c , tempo, speakerPin);
    }
  }

  void playMacros(int NumMacros){
    switch(NumMacros){
      case 0:
        playNote('k', tempo, speakerPin);
        playNote('j', tempo, speakerPin);
        playNote('h', tempo, speakerPin);
        break;
        
      case 1:
        playNote('k', tempo, speakerPin);
        delay(100);
        playNote('j', tempo, speakerPin);
        delay(100);
        playNote('h', tempo, speakerPin);
        break;
        
      case 2:
        playNote(char(39), tempo, speakerPin);
        delay(60);
        playNote(';', tempo, speakerPin);
        delay(60);
        
        playNote(char(39), tempo, speakerPin);
        delay(60);
        playNote(';', tempo, speakerPin);
        delay(60);
        
        playNote(char(39), tempo, speakerPin);
        delay(60);
        playNote(';', tempo, speakerPin);
        delay(60);
        
        playNote('l', tempo, speakerPin);
        delay(80);
        playNote('k', tempo, speakerPin);
        delay(80);
        playNote('j', tempo, speakerPin);
        delay(80);
        
        playNote('k', tempo, speakerPin);
        delay(80);
        playNote('j', tempo, speakerPin);
        delay(80);
        playNote('h', tempo, speakerPin);
        delay(90);
        playNote('j', tempo, speakerPin);
        delay(80);
        playNote('h', tempo, speakerPin);
        delay(80);
        playNote('g', tempo, speakerPin);

        playNote('l', tempo, speakerPin);
        delay(80);
        playNote('k', tempo, speakerPin);
        delay(80);
        playNote('j', tempo, speakerPin);
        delay(80);
        break;
        
      case 3:
      /////////////////////////
        break;
        
      case 4:
      /////////////////////////
        break;
        
      case 5:
      /////////////////////////
        break;
        
      case 6:
      /////////////////////////
        break;
        
      case 7:
      /////////////////////////
        break;
        
      case 8:
      /////////////////////////
        break;
        
      case 9:
      /////////////////////////
        break;
        
      case 10:
      /////////////////////////
        break;
        
      case 11:
      /////////////////////////
        break;
         
    }
  }

  
