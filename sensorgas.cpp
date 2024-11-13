#define PIN_CO 27   
#define PIN_NH3 26  
#define PIN_NO2 25  

const float S_analog = 1023.0;
 
int co, nh3; 
float no2;

void setup() {
  Serial.begin(115200);
}

/*float COPPM(int rawValueCO) {
    // fator de calibração para converter os dados para PPM (teste)
    float fator1 = 1.2;  
    return rawValueCO * fator1;
}

float NO2PPM(int rawValueNO2) {
    // fator de calibração para converter os dados para PPM (teste)
    float fator2 = 2;  
    return rawValueNO2 * fator2;
}

float NH3PPM(int rawValueNH3) {
    // fator de calibração para converter os dados para PPM (teste)
    float fator3 = 1.5;  
    return rawValueNH3 * fator3;
}

float convertToPPM(int rawValue) {
    // fator de calibração para converter os dados para PPM (teste)
    float fator = 0.1;  
    return rawValue * fator;
}*/

void loop() {
    /*int coValue = analogRead(PIN_CO);
    int nh3Value = analogRead(PIN_NH3);
    int no2Value = analogRead(PIN_NO2);

    float coPPM = convertToPPM(coValue);
    float nh3PPM = convertToPPM(nh3Value);
    float no2PPM = convertToPPM(no2Value);

    Serial.print("CO (ppm): ");
    Serial.print(coPPM);
    Serial.print(" | NH3 (ppm): ");
    Serial.print(nh3PPM);
    Serial.print(" | NO2 (ppm): ");
    Serial.println(no2PPM);

    delay(1000);*/

co = map (analogRead(PIN_CO), 0, S_analog, 1, 1000); // Calcolo Monossido di Carbonio
nh3 = map (analogRead(PIN_NH3), 0, S_analog, 1, 500); // Calcolo Ammoniaca
no2 = (map (analogRead(PIN_NO2), 0, S_analog, 5, 1000)) / 100.0 ; // Calcolo Diossido di Azoto
 
Serial.print("CO: ");
Serial.print(co);
Serial.print(" ppm\t");
Serial.print("NH3: ");
Serial.print(nh3);
Serial.print("ppm\t");
Serial.print("NO2: ");
Serial.print(no2);
Serial.println("ppm");
 
delay(1000);
}
