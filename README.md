# datainsamlare-analysverktyg-Saman

GitHub repo link: https://github.com/samansadeq/datainsamlare-analysverktyg-Saman/

## Datainsamlare Analysverktyg - Saman

MeasurementApp – README
🔹 Beskrivning
Detta projekt heter MeasurementApp och är ett C++-program som hanterar mätvärden, till exempel temperaturer.
Användaren kan lägga till värden, visa statistik, sortera, söka och spara data till fil.
Programmet innehåller två delar:
1. En enklare version med funktioner (mitt första projekt).
2. En mer avancerad version med klass, struct och filhantering (andra projektet).

🔹 Funktioner
Lägga till nya mätvärden (heltal eller decimaltal).
Visa statistik:
antal värden
summa
medelvärde
min- och maxvärde
varians
standardavvikelse
Söka efter ett specifikt värde.
Sortera värden i stigande eller fallande ordning.
Spara och läsa in data från fil (CSV-format).

🔹 Programstruktur
Projektet består av flera filer:
main.cpp – huvudprogrammet med meny och logik för båda systemen.
data_manager.h / data_manager.cpp – innehåller klassen DataManager som hanterar beräkningar, lagring och filinläsning.
measurement.h – innehåller structen Measurement med värde och tidsstämpel.

🔹 Datainmatning
Användaren matar in mätvärden manuellt i menyn.
Programmet kontrollerar ogiltig input (t.ex. bokstäver) och tillåter både heltal och decimaltal.

🔹 Datahantering
Alla värden lagras i:
vector<double> i den enkla versionen.
vector<Measurement> i den avancerade versionen (med värde + tidsstämpel).
Statistiken räknas ut med hjälp av egna funktioner eller metoder i klassen.

🔹 Filhantering
Programmet sparar data automatiskt till en fil som heter data.csv och läser in den igen vid nästa start.
Exempel på filinnehåll:
2025-10-27 09:00,22.5
2025-10-27 10:00,23.1

🔹 Menygränssnitt
Användaren möts av en huvudmeny:
Enkel version (funktioner)
Avancerad version (klass)
Avsluta programmet
Båda versionerna har egna undermenyer med val för att lägga till värden, visa statistik, sortera osv.

🔹 Sammanfattning
MeasurementApp uppfyller alla krav i båda uppgifterna:
Datainmatning och felhantering.
Statistiska beräkningar.
Menybaserat gränssnitt.
Uppdelning i flera filer.
Klass och struct för tydlig struktur.
Filhantering (läsa/spara data).
Programmet fungerar som ett komplett mätsystem för att analysera och spara mätdata i C++.
