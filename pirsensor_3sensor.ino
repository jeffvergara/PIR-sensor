//the time we give the sensor to calibrate (10-60 secs according to the datasheet)
int calibrationTime = 10;       
 
//the time when the sensor outputs a low impulse
long unsigned int lowIn;        
 
//the amount of milliseconds the sensor has to be low
//before we assume all motion has stopped
long unsigned int pause = 5000; 
 
boolean lockLow = true;
boolean takeLowTime; 
 
int pirPin0 = 3;    //pir_sensor1
int pirPin1 = 5;    //pir_sensor2
int pirPin2 = 6;   //pir_sensor3
int ledPin = 8; //all ledPin is equievalent to relay
 
 
/////////////////////////////
//SETUP
void setup(){
  Serial.begin(9600);
  //pinMode(ledPin, OUTPUT);
  pinMode(pirPin0, INPUT);
  pinMode(ledPin, HIGH);
  //digitalWrite(pirPin, LOW);
 
  //give the sensor some time to calibrate
  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }
 
////////////////////////////
//LOOP
void loop(){    
  //input for pir_sensor1
       if(digitalRead(pirPin0) == HIGH){
       digitalWrite(ledPin, LOW);   //the led visualizes the sensors output pin state
       //delay(3000);
       
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }        
         takeLowTime = true;
     
       }
      {    
 //input for pir sensor2 
       if(digitalRead(pirPin1) == HIGH){
       digitalWrite(ledPin, LOW);   //the led visualizes the sensors output pin state
       //delay(3000);
       
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }        
         takeLowTime = true;
      }
}  
{    
 //input for pir sensor3 
       if(digitalRead(pirPin2) == HIGH){
       digitalWrite(ledPin, LOW);   //the led visualizes the sensors output pin state
       //delay(3000);
       
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }        
         takeLowTime = true;
      }
}  
     //output for pir_sensor0
     if(digitalRead(pirPin0) == HIGH){
       digitalWrite(ledPin, LOW);   //the led visualizes the sensors output pin state
       //delay(3000);
       
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }        
         takeLowTime = true;
       }
 
     if(digitalRead(pirPin0) == LOW){      
       digitalWrite(ledPin, HIGH);  //relay
       //delay(3000);
       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause,
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){ 
           //makes sure this block of code is only executed again after
           //a new motion sequence has been detected
           lockLow = true;                       
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       //output for pir_sensor1
       if(digitalRead(pirPin1) == HIGH){
       digitalWrite(ledPin, LOW);   //the led visualizes the sensors output pin state
       //delay(3000);
       
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }        
         takeLowTime = true;
       }
 
     if(digitalRead(pirPin1) == LOW){      
       digitalWrite(ledPin, HIGH);  //the led visualizes the sensors output pin state
       //delay(3000);
       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause,
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){ 
           //makes sure this block of code is only executed again after
           //a new motion sequence has been detected
           lockLow = true;                       
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
     }
       //output for pir_sensor2
       if(digitalRead(pirPin2) == HIGH){
       digitalWrite(ledPin, LOW);   //the led visualizes the sensors output pin state
       //delay(3000);
       
       if(lockLow){ 
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;           
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec");
         delay(50);
         }        
         takeLowTime = true;
       }
 
     if(digitalRead(pirPin2) == LOW){      
       digitalWrite(ledPin, HIGH);  //the led visualizes the sensors output pin state
       //delay(3000);
       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause,
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){ 
           //makes sure this block of code is only executed again after
           //a new motion sequence has been detected
           lockLow = true;                       
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
     }




       }
  }
