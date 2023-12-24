const int Do = 9;
const int Re = 7;
const int Mi = 5;
const int Fa = 3;
const int Sol = 6;
const int La = 4;
const int Si = 2;
const int Oktaf = 8;

const int Buzz = 13;

int nilaiOktaf = 4;
bool oktafButtonState = LOW;
bool lastOktafButtonState = LOW;
unsigned long lastOktafPressTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode(Do, INPUT);
  pinMode(Re, INPUT);
  pinMode(Mi, INPUT);
  pinMode(Fa, INPUT);
  pinMode(Sol, INPUT);
  pinMode(La, INPUT);
  pinMode(Si, INPUT);
  pinMode(Oktaf, INPUT);

  pinMode(Buzz, OUTPUT);
}

void loop() {
  
  oktafButtonState = digitalRead(Oktaf);

  if (oktafButtonState != lastOktafButtonState) {

    if (oktafButtonState == HIGH && (millis() - lastOktafPressTime) > 500) {

      if (nilaiOktaf == 4) {
        nilaiOktaf = 5;
      } else {
        nilaiOktaf = 4;
      }
      lastOktafPressTime = millis();
    }
  }


  lastOktafButtonState = oktafButtonState;


  if (digitalRead(Do) == HIGH) {
    Serial.println("Do");
    tone(Buzz, 261 * pow(2, nilaiOktaf - 4));
  } else if (digitalRead(Re) == HIGH) {
    Serial.println("Re");
    tone(Buzz, 293 * pow(2, nilaiOktaf - 4));
  } else if (digitalRead(Mi) == HIGH) {
    Serial.println("Mi");
    tone(Buzz, 329 * pow(2, nilaiOktaf - 4));
  } else if (digitalRead(Fa) == HIGH) {
    Serial.println("Fa");
    tone(Buzz, 349 * pow(2, nilaiOktaf - 4));
  } else if (digitalRead(Sol) == HIGH) {
    Serial.println("Sol");
    tone(Buzz, 392 * pow(2, nilaiOktaf - 4));
  } else if (digitalRead(La) == HIGH) {
    Serial.println("La");
    tone(Buzz, 440 * pow(2, nilaiOktaf - 4));
  } else if (digitalRead(Si) == HIGH) {
    Serial.println("Si");
    tone(Buzz, 493 * pow(2, nilaiOktaf - 4));
  } else {
    Serial.println("No Sound!");
    noTone(Buzz);
  }

  delay(10);
}
