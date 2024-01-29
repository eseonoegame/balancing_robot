---- PROJECT BALANCING ROBOT ----

---- librairie arduino "wire" ----

1. `Wire.beginTransmission(ADXL345_ADDR)`: Cette commande commence la transmission I2C avec l'appareil dont l'adresse est spécifiée en paramètre (`ADXL345_ADDR` dans ce cas). Cela prépare le bus I2C pour envoyer des données à cet appareil.

2. `Wire.write(byte)`: Cette commande envoie un octet de données sur le bus I2C. Dans ce code, elle est utilisée pour envoyer l'adresse du registre que nous voulons lire ou écrire.

3. `Wire.endTransmission()`: Cette commande termine la transmission I2C initiée par `beginTransmission`. Elle renvoie une valeur qui indique si la transmission a réussi ou échoué.

4. `Wire.requestFrom(ADXL345_ADDR, 6, true)`: Cette commande demande des données de l'appareil spécifié (`ADXL345_ADDR`) sur le bus I2C. Dans ce cas, elle demande 6 octets de données. Le dernier paramètre (`true`) indique à la bibliothèque Wire d'envoyer un signal de stop après la réception des données.

5. `Wire.read()`: Cette commande lit un octet de données reçu du bus I2C. Dans le code, elle est utilisée pour lire les valeurs d'accélération sur les axes x, y et z.

