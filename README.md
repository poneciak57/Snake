# Gra snake w C++
Kultowa gra snake napisana w języku c++ przy użyciu popularnej biblioteki graficznej typu open source do tworzenia gier. 
Niestety coś mi się popsuło z repozytorium i usuneły mi sie dwa albo jeden commit przez co aplikacja nie jest skonczona commity zawieraly duzo lepszy system eventow napisany w modern C++ w nastepnych dniach prawdopodobnie go dodam i usune ten fragment. :)

# Zasady i obsługa gry
Kontrolki:
| Klawisz | Funkcja |
| ------- | ------- |
|'W'| wąż bedzie poruszał sie do góry|
|'S'| wąż bedzie poruszał sie do dołu|
|'A'| wąż bedzie poruszał sie w lewo|
|'D'| wąż bedzie poruszał sie w prawo|
|'SPACE'| pauza, unpaza, restart w przypadku przegranej|

Wąż może poruszać się przez ściany</br>
Celem gry jest zdobycie jak najwiekszej liczby punktów

# Jak uruchomić grę?
Aby uruchomić grę wystarczy uruchomić plik .exe w folderze build </br>
Jeżeli chciałbyś skompilować program samemu musisz pobrać i skompilować bilbioteke raylib zgodnie z poradnikiem na ich stronie. Nastepnie zmienić scieżkę include i lib w pliku makefile
```
2: include = raylib_inlcude_path
3: lib = raylib_lib_path
```
>nie używaj rzadnych cudzysłowów

zwroc także uwagę na funkcje `clean` czy używana przez nią funkcja usuwająca pliki jest wspierana przez twoje oprogramowanie/
>del - dla platformy windows </br>
>rm - dla platformy linux

</br>

## Przyszle ulepszenia
---
- zapis punktów i scoreboard najlepszych podejsc
- rozbudowany system eventow (nie bede kłamał był i zniknął a sie napracowalem)
- lepsze menu (albo jakiekolwiek)