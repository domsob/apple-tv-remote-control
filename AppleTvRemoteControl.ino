#include <IRremote.h>

IRsend irsend;

unsigned int baudRate = 9600;
unsigned int buttonPin = 6;
unsigned int shortBreak = 400;
unsigned int longBreak = 5000;
unsigned int frequency = 38;

unsigned int menuBtn[68] = {9200,4500,650,500,650,1650,650,1650,700,1600,700,500,650,1650,650,1650,650,1650,650,1650,700,1600,700,1650,650,500,650,550,650,500,650,550,650,1650,650,1650,650,1650,650,550,650,500,650,550,650,500,650,500,700,500,650,500,700,1650,650,1650,650,1650,650,1650,650,500,700,500,650,1650,650};
unsigned int playBtn[68] = {9200,4500,650,500,650,1650,650,1650,700,1650,650,500,650,1650,650,1650,650,1650,650,1650,700,1600,700,1600,700,500,650,550,650,500,650,500,700,1650,650,1650,650,500,650,1650,650,550,650,500,650,550,600,550,650,550,650,500,650,1650,650,1650,650,1650,650,1700,650,500,650,500,700,1650,650};
unsigned int leftBtn[68] = {9200,4550,600,550,650,1650,650,1650,650,1700,600,550,650,1650,650,1650,650,1700,600,1700,600,1700,650,1650,650,550,600,550,650,550,600,550,650,1650,650,1700,600,550,650,550,600,1700,650,500,650,550,650,500,650,550,650,550,600,1700,600,1700,600,1700,650,1650,650,550,600,550,650,1650,650};
unsigned int rightBtn[68] = {9200,4500,650,550,650,1650,650,1650,650,1650,650,550,650,1650,650,1650,650,1650,650,1650,650,1650,650,1650,650,550,650,500,700,500,650,500,650,1650,700,500,650,1650,650,1650,650,550,600,550,650,550,650,500,650,550,650,500,650,1650,650,1650,650,1650,700,1600,700,500,650,550,650,1650,650};
unsigned int topBtn[68] = {9340,4600,580,580,640,1640,600,1700,580,1700,600,560,580,1700,600,1700,580,1700,600,1700,580,1700,600,1700,580,580,560,580,580,580,580,580,580,1700,580,580,580,1700,580,580,580,1700,580,580,580,580,580,560,600,560,580,580,580,560,600,580,560,580,580,1700,580,1720,580,1700,580,600,580}; 
unsigned int bottomBtn[68] = {9360,4580,580,580,580,1700,580,1700,600,1700,580,560,600,1700,580,1700,580,1720,580,1700,580,1700,600,1680,600,560,580,580,580,560,600,560,580,1700,600,560,580,580,580,1700,580,1700,580,580,580,580,580,600,560,560,580,580,580,560,600,580,560,560,600,1700,580,1700,580,1720,580,580,580};
unsigned int btnRawLength = 68;

void setup() {
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  Serial.begin(baudRate);
  Serial.println("Initialized.");
}

void loop() {
    if(!digitalRead(buttonPin)) { 
        Serial.println("Navigation process started.");
        unsigned int randomNumber = randNumber(0,25);
        Serial.print("Selected random number: ");
        Serial.println(randomNumber);
        delay(shortBreak);
        turnOn();
        
        //Your logic goes here...
        //You can use the random number to select e.g. an episode of you favorite TV series.
        
        Serial.println("Navigation process finished.");
    }
}

void gotoMovies() {
    gotoMainMenu();
    for(int i = 0; i < 10; i++) {
        top();
    }
    bottom();
    for(int i = 0; i < 5; i++) {
        left();
    }
    play();
    for(int i = 0; i < 8; i++) {
        left();
    }
}

void gotoShows() {
    gotoMainMenu();
    for(int i = 0; i < 10; i++) {
        top();
    }
    bottom();
    for(int i = 0; i < 5; i++) {
        left();
    }
    right();
    play();
    for(int i = 0; i < 8; i++) {
        left();
    }
}

void gotoAllShows() {
    gotoShows();
    for(int i = 0; i < 10; i++) {
        bottom();
    }
    for(int i = 0; i < 10; i++) {
        top();
    }
    bottom();
    bottom();
    delay(longBreak);
    right();
}

void gotoMainMenu() {
    for(int i = 0; i < 15; i++) {
        menu();
    }
}

void turnOn() {
    menu();
    delay(longBreak);
}

void menu() {
    irsend.sendRaw(menuBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void play() {
    irsend.sendRaw(playBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void left() {
    irsend.sendRaw(leftBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void right() {
    irsend.sendRaw(rightBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void top() {
    irsend.sendRaw(topBtn, btnRawLength, frequency);
    delay(shortBreak);
}

void bottom() {
    irsend.sendRaw(bottomBtn, btnRawLength, frequency);
    delay(shortBreak);
}

unsigned int randNumber(unsigned int min, unsigned int max) {
    double scaled = (double)rand() / RAND_MAX;
    return (max - min +1) * scaled + min;
}
