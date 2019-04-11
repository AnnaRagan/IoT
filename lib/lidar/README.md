# Konfigurowanie Lidar Lite 3 na Raspberry Pi 0 W
Dokładny, laserowy czujnik odległości działający w zakresie od 0 do 40 m z dokładnością 0,025 m. Napięcie zasilania wynosi od 4,75 V do 5,5 V i zużywa do 130 mA prądu. Urządzenie komunikuje się za pośrednictwem interfejsów: I2C lub PWM. Długość projektowanej fali świetlnej wynosi 905 nm.  
Zakłada się, że Pi jest już uruchomiony.
## Konfiguracja sprzętu
Zgodnie z dokumentacją Garmin Lidar Lite 3 można podłączyć za pomocą I2C lub PWM. Użyłem I2C do nawiązania połączenia zgodnie z poniższym schematem z podręcznika Garmin  
![alt text](https://github.com/AnnaRagan/IoT/blob/master/lib/lidar/i2c_connection_diagram.png)
## Konfigurowanie I2C
Najpierw upewnij się, że I2C jest włączony na Raspberry Pi.
Biblioteka Lidar-LIte działa tylko w środowisku linuxowym, zainstaluj i2c-dev i i2c-tools.
```
1. Open up a terminal window and type:  sudo raspi-config
2. Choose option: 5 Interfacing Options
3. Choose option: P5 I2C and hit enter
4. Choose:  <Yes> to turn on the I2C interface
5. Choose: Ok
6. Choose:  Finish
```
Biblioteka Lidar-LIte działa tylko w środowisku linuxowym, zainstaluj i2c-dev i i2c-tools.
```
sudo apt-get install i2c-tools
sudo apt-get install i2c-dev

```
Możesz przetestować połączenie za pomocą narzędzia i2cdetect  
```
i2cdetect [-y] z 1 lub 2
```
Jeśli poprawnie podłączono urządzenie, a sieć powróciła z adresem, to wszystko jest ustawione, Raspberry Pi rozmawia teraz z Lidar Lite. W moim przypadku jest zmapowany na 0x62.
## Naprawa problemu ze zwrotem danych (0 return issue):

```
Edit /boot/config.txt

Scroll to the bottom of the file.

Add the line:
dtoverlay=i2c_bcm2708

Save the file and reboot.
```
Ponieważ nie ma oficjalnych bibliotek Garmin Raspberry Pi, uzylem tej:  
https://github.com/Sanderi44/Lidar-Lite  
Dokumentację Garmin dla Lidar Lite 3 można znaleźć tutaj  
http://static.garmin.com/pumac/LIDAR_Lite_v3_Operation_Manual_and_Technical_Specifications.pdf
