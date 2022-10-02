#include <OneWire.h> 
#include <DallasTemperature.h>
#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 

// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
#define ONE_WIRE_BUS 3
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
int Light_LED_YELLOW = 3;
int Light_LED_RED =  4;
int Light_LED_GREEN = 5;
int B_received =  0;

int Buzzer_EMR = 6;
float Temperature;

void setup(void) {
  pinMode(Light_LED_YELLOW, OUTPUT);
  pinMode(Light_LED_RED, OUTPUT);
  pinMode(Light_LED_GREEN, OUTPUT);
  //pinMode(Buzzer_EMR,OUTPUT);

  Serial.begin(9600);
  //Sensors.begin();
  Serial.println("SELF BOOTING > > > ");
  delay(100);
  Serial.println("> > > 1");
  delay(100);
  Serial.println("> > > 2");
  delay(100);
  Serial.println("> > > 3");
  delay(1000);
  sensors.requestTemperatures(); // Send the command to get temperature readings 
  delay(100);


  Serial.println("DT_Mid_SR : READING");
  Serial.print(sensors.getTempCByIndex(0));
  delay(100);
  Serial.println("DT_OT_SR : READING : ");
  Serial.print(sensors.getTempCByIndex(1));
  delay(100);
  Serial.println("DT_CR_SR : READING : ");
  Serial.print(sensors.getTempCByIndex(2));
  delay(100);



}

void loop() {
   Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 Serial.println("DONE"); 
/********************************************************************/
 Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
   delay(1000); 

   Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(1)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
   delay(1000); 

   Serial.print("Temperature is: "); 
 Serial.print(sensors.getTempCByIndex(2)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
   delay(1000);


if (MyBlue.available()) B_received = MyBlue.read(); 
  Serial.println("Ok bluetooth received");
  if (B_received == 1) { 
    }else if (B_received == 2) { digitalWrite(Light_LED_YELLOW, HIGH); digitalWrite(Light_LED_RED, HIGH); digitalWrite(Light_LED_GREEN, HIGH);  Serial.println("COOKER SET 60C LIMIT"); delay(100);
    }else if (B_received == 3) { digitalWrite(Light_LED_YELLOW, HIGH); digitalWrite(Light_LED_RED, HIGH); digitalWrite(Light_LED_GREEN, HIGH);  Serial.println("LED Off"); delay(100);
    }else if (B_received == 4) { digitalWrite(Light_LED_YELLOW, HIGH); digitalWrite(Light_LED_RED, HIGH); digitalWrite(Light_LED_GREEN, HIGH);  Serial.println("LED Off"); delay(100);
    }else if (B_received == 5) { digitalWrite(Light_LED_YELLOW, HIGH); digitalWrite(Light_LED_RED, HIGH); digitalWrite(Light_LED_GREEN, HIGH);  Serial.println("LED Off"); delay(100);
    }else if (B_received == 6) { digitalWrite(Light_LED_YELLOW, HIGH); digitalWrite(Light_LED_RED, HIGH); digitalWrite(Light_LED_GREEN, HIGH);  Serial.println("LED Off"); delay(100);
}   else{ Serial.println("WRONG INPUT FROM BLUETOOTH APPLICATON"); }
}