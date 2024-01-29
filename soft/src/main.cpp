#include <Arduino.h>

int ax, ay, az;
int xeq, yeq, zeq;
int debutA, dureeA;

int correctionFactorTare(int ax, ay, az) // change l'etat du buzzer en fonction de la duree eteinte ou allumee.
{
  if (millis() - debutA > dureeA)
  {
    a = ax + ay + az;
    if (a > 9, 81 and ax > 0) // si robot dérive en x+.
    {
      // corriger la tare en x+.
    }

    debutA = millis();
  }
}

// put function declarations here:
int get_acceleration()
{
}
int balance_correction(ax, ay, az, xeq, yeq, zeq)
{
}
int tare_correction(ax, ay, az, xeq, yeq, zeq)
{
}

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop()
{
  // put your main code here, to run repeatedly:
  ax, ay, az = get_acceleration();                             // Recuperation des valeurs de l'accelerometre.
  correctionFactorAngle = calculBalanceCorrection(ax, ay, az); // Calcul de la correction de l'angle du robot.
  correctionFactorTare = calculTareCorrection(ax, ay, az);     // Calcul de la tare de la balance du robot.
}
