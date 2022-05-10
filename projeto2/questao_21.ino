// C++ code
//
int butPin1 = 8, pot, butPin2 = 7, i=0, a[10]; 


  
void setup()
{
  pinMode(butPin1, INPUT);
  pinMode(butPin2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(butPin1)){	
  	Serial.print("A[10]: ");
 
    for (i=0 ; i<=9; i++){
      if (i<9){
        Serial.print(a[i]);
        Serial.print(",");
        
      }else{
          Serial.print(a[i]);
          Serial.println("}");
        }
         delay(1000);
     }
          
  } 	
  if (digitalRead(butPin2)){
    pot = analogRead(A0);
    a[i] = pot; 
    Serial.print(i);
    Serial.print(" ");
    Serial.println(pot);
    i++; 
    if (i>9) {
      i=0;
      Serial.println("Chegou na ultima posicao");
    }
    delay(500);
  } 
   
}
