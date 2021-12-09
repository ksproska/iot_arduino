# Podstawy Internetu Rzeczy - Arduino

## L02

### [Zad 1](L01_01/L01_01.ino) - Konﬁguracja, odczyt i sterowanie pinami cyfrowymi

Przygotuj prosty programu wykorzystujący przełączniki przyciskane (zielony i czerwony) oraz diody świecące według wska-
zówek Prowadzącego laboratorium. Przykładowy program: Po naciśnięciu przycisku zielonego zmień kolor świecącej diody.
Przycisk czerwony włącza i wyłącza świecenie.

### [Zad 2](L01_02/L01_02.ino) - Sterowanie jasnością świecenia diody z wykorzystaniem PWM

Napisz program, który w reakcji na przyciski będzie rozjaśniał i ściemniał wybraną diodę. Na przykład, dioda zielona, po
przytrzymaniu przycisku zielonego dioda będzie rozjaśniała się, a po przytrzymaniu czerwonego będzie ściemniana.
Prowadzący laboratorium może zmodyﬁkować zadanie.

### [Zad 3](L01_03/L01_03.ino) - Uzyskiwanie kolorów pośrednich w diodzie RGB

Napisz program, który w sposób łagodny będzie zmieniał kolory diody RGB w cyklu, na przykład, czerwony > zielony >
niebieski > czerwony ..., wyświetlając kolory pośrednie.
Prowadzący laboratorium może zmodyﬁkować zadanie.

## L03

### [Zad 1](L02_01/L02_01.ino) - Program z eliminacją wpływy drgania styków

Napisz program, Program, po naciśnięciu i zwolnieniu jednego z przycisków (zielony i czerwony) ma zgasić zaświeconą diodę
i zapalić kolejną dokładnie w cyklu R,G,B,R,G,... .
Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

### [Zad 2](L02_02/L02_02.ino) - Program wykonujący współbieżnie różne zadania

Napisz program, który będzie zmieniał stany kolorowych diod w diodzie RGB co 0,9s czerwonej, 1,0s zielonej i 1,1s niebieskiej.
Program przygotować tak, aby nie blokować przełączania diod wzajemnie, nie blokować wykonania programu. Program ma
pozwalać na dodanie kolejnych zadań w funkcji loop() , które będą wykonywane bez znacznych opóźnień.
Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

### [Zad 3](L02_03/L02_03.ino) - Wykorzystanie wyświetlacza LCD - Program „Stoper elektroniczny”

Napisz program, który będzie działał jako stoper elektroniczny, podając czas na wyświetlaczu LCD. Klawisz zielony uruchamia
i zatrzymuje stoper. Klawisz czerwony zatrzymuje stoper jeśli działał, i resetuje wartość czasu do wartości 0. Precyzja pomiaru
to 1 sekunda.
Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

## L04

### [Zad 1](L03_01/L03_01.ino) - Wysyłanie danych do komputera PC przez łącze szeregowe

Napisz program, który będzie wysyłał informację o stanie przycisków czerwonego i zielonego przez łącze szeregowe do kom-
putera PC. Sprawdź jaką maksymalną szybkość transmisji danych możesz skonﬁgurować. Spróbuj zwizualizować stany przy-
cisków na wykresie w Serial Plotter
Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

### [Zad 2](L03_02/L03_02.ino) - Sterowanie pracą Arduino za pomocą komend wysyłanych przez łącze szeregowe z PC

Napisz program, który będzie reagował na komendy wysyłane z narzędzia Serial Monitor do zestawu Arduino. Program
powinien zapalać wszystkie diody LED z zadaną każdej osobno jasnością w reakcji na komendę. Postać komendy ustal
samodzielnie.
Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

### [Zad 3](L03_03/L03_03.ino) - Odczyt wartości napięcia zadanego potencjometrem

Napisz program, który dla napięcia zadanego potencjometrem, na wyświetlaczu LCD wyświetli wartość, którą odczytał ADC
i rzeczywistą wartość napięcia zadanego potencjometrem. Sprawdź, czy wartości ustawiane potencjometrem osiągają skrajne
wartości odczytu (0 i 1023) i czy są one stabilne. Skonsultuj się z innymi uczestnikami laboratorium, jak to wyglądało w ich
przypadku.
Proszę wykonać dokładnie to zadanie i nie zmieniać go.

### [Zad 4](L03_04/L03_04.ino) - Monitorowanie napięcia wejściowego portu za pomocą narzędzia Serial Plotter z Arduino IDE

Napisz program, który odczytuje wartość z przetwornika analogowo-cyfrowego, a następnie wysyła przez łącze szeregowe do
komputera. Zobacz wynik jego działania przy pomocy narzędzi Serial Monitor i Serial Plotter z Arduino IDE.
Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

## L05

### [Zad 1](L05_2/L05_2.ino) - Sterowanie programem przy pomocy enkodera

Przygotuj program, który będzie pozwalał sterować świeceniem diody RGB. Program ma być wyposażony w przewijalne menu
na ekranie wyświetlacza LCD (w kolejnych liniach wyświetlane są dwie pozycje z menu). Samodzielnie zaprojektuj strukturę
menu programu. Nawigacja po menu (przemieszczanie się pomiędzy pozycjami) ma odbywać się za pomocą enkodera. Wybór
pozycji menu odbywa się za pomocą przycisku. Minimalna funkcjonalność to zapalanie i gaszenie wybranej diody. Można
też zaimplementować ustawianie jasności każdego kolory diody enkoderem. Warto też program oprzeć na przerwaniach
zgłaszanych przy zmianie stanu enkodera.

## L06

### [Zad 1](L06_1/L06_1.ino) - Program wykorzystujący czujniki DS18B20

Przygotuj program, który uczyni zestaw laboratoryjny małą „stacją pogodową”. Na wyświetlaczu LCD ma prezentować
temperaturę wewnętrzną (czujnik wewnątrz zestawu) i zewnętrzną (sonda na przewodzie). Ponadto program powinien pa-
miętać wartość maksymalną i minimalną temperatury mierzonej przez sondę na przewodzie. Dodatkowo, dioda RGB, może
sygnalizować czy jesteśmy w streﬁe komfortu temperaturowego, lub jest za gorąco, lub za zimno.
Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

### [Zad 2](L06_2/L06_2.ino) - Implementacja własnej biblioteki ze sterownikiem wybranego urządzenia

Przygotuj własną bibliotekę, która będzie służyła do sterowania diodą RGB. Samodzielnie zaprojektuj interfejs programi-
styczny tej biblioteki, tak aby pozwalał podać, do których pinów podłączona jest dioda, oraz aby pozwalał ustawiać kolory
poprzez podanie wartości komponentów RGB oraz przez nazwy kolorów: RED, GREEN, BLUE, YELLOW, CYAN, MA-
GENTA, BLACK, WHITE. Zadbaj o kolorowanie składni w Arduino IDE.
Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.
