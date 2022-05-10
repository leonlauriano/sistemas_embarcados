// C++ code
//
int butPin = 7, i=0, ledPin = 6;

int v[9] = {9,6,4,8,5,3,1,2,7};


void setup()
{
  pinMode(butPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(butPin)){
    Serial.print("v []:{");

    for (i=0; i<=8; i++) {
      if (i<8) {
        Serial.print(v[i]);
        Serial.print(",");                   
      } else{
      	Serial.print(v[i]);
      	Serial.println("}");
  	  }
      delay(1000);
  	
	}
  } 
  
}
                          