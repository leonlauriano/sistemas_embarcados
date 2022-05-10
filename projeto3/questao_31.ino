// C++ code
//
int ledPin1 = 12, ledPin2 = 8, ledPin3 = 7;
String leituraSerial = "";
  
void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  leituraSerial = Serial.readString();
  //Serial.println(leituraSerial);
  if (leituraSerial == "vermelho") {
  	digitalWrite(ledPin1, HIGH);
    Serial.println("pare");
 	}else{
  	digitalWrite(ledPin1, LOW);
  
	}
  if (leituraSerial == "amarelo") {
  	digitalWrite(ledPin2, HIGH);
    Serial.println("atencao");
 	}else{
  	digitalWrite(ledPin2, LOW);
  
	}
  if (leituraSerial == "verde") {
  	digitalWrite(ledPin3, HIGH);
    Serial.println("siga");
 	}else{
  	digitalWrite(ledPin3, LOW);
  delay(500);
	}
}