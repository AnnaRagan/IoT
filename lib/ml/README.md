# Moduł wykrywania świateł dla pieszych

## Działanie algorytmu
Wczytywane są dwa wzorce - dla świateł koloru czerwonego i zielonego.
Pobierana jest w pętli klatka obrazu z kamery. W każdego iteracji algorytmu przeprowadzana jest binaryzacja pobranej klatki. Następnie, wykonywana jest dylatacja zbinaryzowanego obrazu. Kolejnym krokiem jest detekcja krawędzi algorytmem Canny. Pośród krawędzi wykrywane są kontury. Dla każdego znalezionego obiektu znajdywany jest jego tzw. bounding box (najmniejszy prostokąt kompletnie otaczający dany obiekt). Usuwane są bounding boxy zawierające się w innych bounding boxach. Każdy bounding box oznacza miejsce w klatce obrazu, w którym potencjalnie znajduje się światło przejścia dla pieszych. Dla każdego bounding boxa wycinany jest odpowiedni fragment klatki, który następnie porównywany jest z dwoma wzorcami - światła czerwonego i zielonego. Dla każdego fragmentu obrazu wyliczany jest współczynnik dopasowania. Znajdowany jest bounding box o najlepszym dopasowaniu – zarówno dla światła zielonego, jak i czerwonego.  Rozpatrywane są trzy sytuacje:
- jeżeli największy współczynnik dla światła zielonego < 0.5 oraz największy współczynnik dla światła czerownego < 0.5 to w danej klatce obrazu nie wykryto świateł przejścia dla pieszych,
- jeżeli największy współczynnik dla światła zielonego jest większy od największego współczynnika dla światła czerownego to w danej klatce obrazu wykryto zielone światło przejścia dla pieszych,
- jeżeli największy współczynnik dla światła czerwonego jest większy od największego współczynnika dla światła zielonego to w danej klatce obrazu wykryto czerwone światło przejścia dla pieszych.

Podczas uruchomienia aplikacji, uruchamiany jest serwer GRPC, który nasłuchuje na porcie 50051. W momencie podłączenia, między serwerem i klientem tworzy się dwukierunkowe połączenie. Każda zmiana w wykryciu, bądź niewykryciu świateł na obrazie powoduje nadanie sygnału z serwera do klienta. Klient może wysłać do serwera akcję zatrzymania bądź uruchomienia przetwarzania obrazu.

## Użyte narzędzia i technologie
Język C++, OpenCV, Docker, Raspberry Pi 3, Raspberry Pi Camera

## Uruchomienie
```bash
docker run \
  -it \
  -p 50051:50051 \
  --device=/dev/video0:/dev/video0 \
  --rm \
  mareklabuz/ubuntu-traffic-lights \
  /root/trafficLights log 0
```

## Klient
Przykład kodu klienta w folderze client
