
#define TeclaTOGGLE 0xBA45FF00
#define TeclaGIRO 0xB847FF00

const int IR_PIN = 11;
const int CONTROL_PIN1 = 3;
const int CONTROL_PIN2 = 7;

bool motorHigh = false;
bool motorHigh2 = false;

void setup() {
  Serial.begin(9600);     

  pinMode(CONTROL_PIN1, OUTPUT);
  pinMode(CONTROL_PIN2, OUTPUT);

  IrReceiver.begin(IR_PIN, DISABLE_LED_FEEDBACK); 
} 

void loop() {
  if (IrReceiver.decode()) {        
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); 

    if (IrReceiver.decodedIRData.decodedRawData == TeclaTOGGLE) {
      Serial.println("Recibido inicio");
      motorHigh = !motorHigh;
    } else if (IrReceiver.decodedIRData.decodedRawData == TeclaGIRO) {
      Serial.println("Recibido Giro");
      motorHigh2 = !motorHigh2;
    }

    IrReceiver.resume();       
  }

  digitalWrite(CONTROL_PIN1, motorHigh ? HIGH : LOW);
  digitalWrite(CONTROL_PIN2, motorHigh2 ? HIGH : LOW);

  delay(100);            
}