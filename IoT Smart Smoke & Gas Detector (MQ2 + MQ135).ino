// ================= PIN TANIMLARI =================
int transistorPin = 2;       // Buzzer'ları kontrol eden transistör
int ledPin = 4;              // Kırmızı LED
int buttonPin = 7;           // Test butonu

int mq2Analog = A0;          // MQ2 analog pin
int mq135Analog = A1;        // MQ135 analog pin

int mq2Digital = 8;          // MQ2 dijital pin
int mq135Digital = 9;        // MQ135 dijital pin

// ================= DEĞİŞKENLER =================
unsigned long startTime;
const unsigned long warmupTime = 5UL * 60UL * 1000UL; // 5 dakika ısınma

bool systemReady = false;

int mq2Baseline = 0;
int mq135Baseline = 0;

// ================= FONKSİYON PROTOTİPLERİ =================
void normalMode();
void warningMode();
void alarmMode();
void testMode();
int getAverage(int pin);
void blinkLEDDuringWarmup();

// ================= SETUP =================
void setup() {
  Serial.begin(9600);

  pinMode(transistorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(mq2Digital, INPUT);
  pinMode(mq135Digital, INPUT);

  startTime = millis();
}

// ================= LOOP =================
void loop() {
  unsigned long elapsed = millis() - startTime;

  // ===== WARMUP =====
  if (!systemReady) {
    blinkLEDDuringWarmup();
    if (elapsed >= warmupTime) {
      mq2Baseline = getAverage(mq2Analog);
      mq135Baseline = getAverage(mq135Analog);
      systemReady = true;
      digitalWrite(ledPin, LOW);
      Serial.println("Sistem Hazır!");
    }
    // BUTON TESTİ İSINA SÜRESİNDEN BAĞIMSIZ
    if (digitalRead(buttonPin) == LOW) {
      testMode();
    }
    return;
  }

  // ===== OKUMA =====
  int mq2Val = analogRead(mq2Analog);
  int mq135Val = analogRead(mq135Analog);

  int mq2Dig = digitalRead(mq2Digital);
  int mq135Dig = digitalRead(mq135Digital);

  int diffMQ2 = mq2Val - mq2Baseline;
  int diffMQ135 = mq135Val - mq135Baseline;

  Serial.print("MQ2: "); Serial.print(mq2Val);
  Serial.print(" | MQ135: "); Serial.print(mq135Val);
  Serial.print(" | D2: "); Serial.print(mq2Dig);
  Serial.print(" | D135: "); Serial.println(mq135Dig);

  // ===== BUTON TEST =====
  if (digitalRead(buttonPin) == LOW) {
    testMode();
    return;
  }

  // ===== ALARM VE UYARI =====
  if (mq2Dig == HIGH || mq135Dig == HIGH) {
    alarmMode();
  } else if (diffMQ2 > 200 || diffMQ135 > 180) {
    alarmMode();
  } else if (diffMQ2 > 120 || diffMQ135 > 100) {
    warningMode();
  } else {
    normalMode();
  }

  delay(200); // Stabilizasyon gecikmesi
}

// ================= FONKSİYONLAR =================
int getAverage(int pin) {
  long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += analogRead(pin);
    delay(50);
  }
  return sum / 20;
}

void blinkLEDDuringWarmup() {
  // LED ısınma sırasında yanıp sönsün
  digitalWrite(ledPin, millis() / 500 % 2);
}

void normalMode() {
  digitalWrite(transistorPin, LOW);
  digitalWrite(ledPin, LOW);
}

void warningMode() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(transistorPin, HIGH);
  delay(200);
  digitalWrite(transistorPin, LOW);
  delay(800);
}

void alarmMode() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(transistorPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(transistorPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(150);
  }
}

void testMode() {
  Serial.println("TEST MODE");
  for (int i = 0; i < 3; i++) {
    digitalWrite(transistorPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(transistorPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(300);
  }
}