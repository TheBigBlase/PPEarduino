int incomingBytes=0;


void setup() {
 pinMode(10,OUTPUT); // pin moteurs
 pinMode(9,OUTPUT);
 Serial.begin(9600);
 pinMode(13,INPUT);
 pinMode(12,INPUT);
}

void loop() {
  if(digitalRead(12)==LOW){ // if click, then stop 
      analogWrite(9,0);
      analogWrite(10,0);
      Serial.println("Abording...");
  }
}

void serialEvent(){
    analogWrite(9,0);
    analogWrite(10,0);
    delay(100);
    incomingBytes = Serial.read()-'0'; //-0 to read as numbers (no bs convertion needed)
    Serial.println("I have recieved : ");
    Serial.println(incomingBytes);
    
    if(incomingBytes == 1){
      Serial.println("Turning counter clockwise"); //if 1, turn 
      analogWrite(9,255);
      analogWrite(10,0);
    }
    
    else if (incomingBytes==2){ // if 2 turn other way 
      Serial.println("Turning clockwise");
      analogWrite(9,0);
      analogWrite(10,255);
    }
    
    else { //abord 
      Serial.println("Did not understand");
      analogWrite(9,0);
      analogWrite(10,0); 
    }
}
