byte ssdigits[10][7] = {{1,1,1,1,1,1,0},
{0,1,1,0,0,0,0},
{1,1,0,1,1,0,1},
{1,1,1,1,0,0,1},
{0,1,1,0,0,1,1},
{1,0,1,1,0,1,1},
{1,0,1,1,1,1,1},
{1,1,1,0,0,0,0},
{1,1,1,1,1,1,1},
{1,1,1,0,0,1,1}
};

const int buttonPin = 12;
int buttonState = 0;
int num = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void SSWrite(int digit){
  byte pin = 2;
  for(byte seg = 0; seg < 7; seg++){
    digitalWrite(pin, 1 - ssdigits[digit][seg]);
    pin++;
  }
}



void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if(buttonState == 1){
    num = 0;
  }

  SSWrite(num);
  delay(1000);
  if(num >= 9){
    num = 0;
  }else{
    num++;
  }

}
