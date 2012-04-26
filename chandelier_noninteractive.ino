// Chandelier workshop program (Non-interactive version)
// Created by Nathen Street 24 March 2012
// Program choice determined by switch on circuit board
// Option 1: Chase 
// Option 2: Always on

int lightsOne = 0;                      // light group 1
int lightsTwo = 1;                      // light group 2
int lightsThree = 2;                    // light group 3

int chaseOne[] =   {1, 1, 0, 0, 1, 0, 1, 0};
int chaseTwo[] =   {0, 1, 1, 1, 1, 1, 0, 1};
int chaseThree[] = {1, 0, 1, 0, 1, 1, 1, 0};

int chaseDelay = 4000;

int lightSwitch = 4;                    // Header
int switchPower = 3;                    // Header
int state = 0;                          // Light on or off state

String program;

void setup() {
  pinMode(lightsOne, OUTPUT);
  pinMode(lightsTwo, OUTPUT);
  pinMode(lightsThree, OUTPUT);
  
  pinMode(lightSwitch, INPUT);
  pinMode(switchPower, OUTPUT);
  
  // determine what program - this means for program changes
  // the power has to be turned on/off
  digitalWrite(switchPower, HIGH);
  delay(2000);
  state = digitalRead(lightSwitch);
  
  if (state == HIGH) {
    program = "alwaysOn";
  } else {
    program = "blink";
  }
}



void loop() {
  if (program == "alwaysOn") {
    digitalWrite(lightsOne, HIGH);
    digitalWrite(lightsTwo, HIGH);
    digitalWrite(lightsThree, HIGH);
  }
  
  if (program == "blink") {
    for (int i=0; i<8; i++) {
      digitalWrite(lightsOne, chaseOne[i]);
      digitalWrite(lightsTwo, chaseTwo[i]);
      digitalWrite(lightsThree, chaseThree[i]);
      delay(chaseDelay);
    }
  }
  
}
