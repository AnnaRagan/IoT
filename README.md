# IoT
### Repozytorium projektu 

Moduły:
- /lib/main - Punkt wejścia sw,
- /lib/lidar - Konfiguracja laserowego czujnika odległości,
- /lib/app - Aplikacja smartfonową,
- /lib/io - Głośnik oraz przetwarzanie tekstu na mowę,
- /lib/ml -  Maszynowe przetwarzanie obrazu,
- /sch - Schamat połączeń,
- /test/* - pliki do testów jednostkowych oraz systemowych.
- /.build/ - katalog tymczasowy/z wynikami kompilacji

Do przemyślenia:
- /lib/web

Lista prac:
 - [ ] Schemat połączeń: [drawIo](https://tnij.me/6t0rK)
 - [ ] ML:
   - [x] Stworzenie modelu i przetestowanie go,
   - [ ] Integracja z resztą funkcjonalności.
 - [ ] LIDAR:
   - [x] Opracowanie HW oraz testy funkcjonalne,
   - [ ] Integracja z resztą funkcjonalności.
 - [ ] Aplikacja na telefon:
   - [x] Tethering internetu,
   - [x] Przesyłanie danych GPS,
   - [x] Przesyłanie dźwięku z mikrofonu,
   - [ ] Integracja z resztą funkcjonalności.
 - [ ] Polecenia głosowe:
   - [x] Opracowanie HW
   - [x] Odtwarzanie dzwięku
     - [x] Używając telefonu
     - [-] Używając głośnika
   - [ ] Rozpoznawanie dzwięku

Układy można podzelić na dwie części:
 - te, które są niezbedne do bezpiecznego poruszania się po mieście i **muszą** działać niezaleźnie od połaczenia internetowego:
   - rpi + kamera + LIDAR
 - te, które stanowią dodatkową funkcjonalność
   - przetwarzanie obrazu na głos,
   - odbieranie danych gps
   
