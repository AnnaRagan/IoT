# Konfigurowanie Lidar Lite 3 na Raspberry Pi 0 W
Dokładny, laserowy czujnik odległości działający w zakresie od 0 do 40 m z dokładnością 0,025 m. Napięcie zasilania wynosi od 4,75 V do 5,5 V i zużywa do 130 mA prądu. Urządzenie komunikuje się za pośrednictwem interfejsów: I2C lub PWM. Długość projektowanej fali świetlnej wynosi 905 nm.
Zakłada się, że Pi jest już uruchomiony.
## Konfiguracja sprzętu
Zgodnie z dokumentacją Garmin Lidar Lite 3 można podłączyć za pomocą I2C lub PWM. Użyłem I2C do nawiązania połączenia zgodnie z poniższym schematem z podręcznika Garmin

## Naprawa problemu ze zwrotem danych (0 return issue):

```
Edit /boot/config.txt

Scroll to the bottom of the file.

Add the line:
dtoverlay=i2c_bcm2708

Save the file and reboot.
```
Dokumentację Garmin dla Lidar Lite 3 można znaleźć tutaj
http://static.garmin.com/pumac/LIDAR_Lite_v3_Operation_Manual_and_Technical_Specifications.pdf
