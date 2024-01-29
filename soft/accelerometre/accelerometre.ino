#include <Wire.h>

// Adresse I2C par défaut de l'ADXL345
#define ADXL345_ADDR 0x53

// Registres de l'ADXL345
#define ADXL345_REG_X_LSB 0x32
#define ADXL345_REG_POWER_CTL 0x2D
#define ADXL345_REG_DATA_FORMAT 0x31

// Fonction pour initialiser l'ADXL345
void initADXL345() 
{
  Wire.beginTransmission(ADXL345_ADDR);
  Wire.write(ADXL345_REG_POWER_CTL);
  Wire.write(0); // Mettre en mode mesure
  Wire.endTransmission();

  Wire.beginTransmission(ADXL345_ADDR);
  Wire.write(ADXL345_REG_DATA_FORMAT);
  Wire.write(0x08); // Mettre en mode pleine résolution
  Wire.endTransmission();
}

// Fonction pour lire les valeurs d'accélération
void readAccelValues
(int16_t &accelX, int16_t &accelY, int16_t &accelZ) {
  Wire.beginTransmission(ADXL345_ADDR);
  Wire.write(ADXL345_REG_X_LSB);
  Wire.endTransmission(false);

  Wire.requestFrom(ADXL345_ADDR, 6, true);
  
  accelX = Wire.read() | (Wire.read() << 8);
  accelY = Wire.read() | (Wire.read() << 8);
  accelZ = Wire.read() | (Wire.read() << 8);
}

void setup() 
{
  Serial.begin(9600);
  Wire.begin();

  // Initialiser l'ADXL345
  initADXL345();
}

void loop() 
{
  // Lire les valeurs d'accélération
  int16_t accelX, accelY, accelZ;
  readAccelValues(accelX, accelY, accelZ);

  // Afficher les valeurs
  Serial.print("AccelX: ");
  Serial.print(accelX);
  Serial.print("\tAccelY: ");
  Serial.print(accelY);
  Serial.print("\tAccelZ: ");
  Serial.println(accelZ);

  delay(1000); // Attendre 1 seconde entre chaque lecture
}
