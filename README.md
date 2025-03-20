# DINING PHILOSOPHERS PROBLEM

![image](https://github.com/user-attachments/assets/8079257c-3e38-435c-88a1-83b3ff1c4bbe)


- [Opis problemu](#opis-problemu)
- [Instrukcje uruchomienia projektu](#instrukcje-uruchomienia-projektu)
    - [uruchomienie projektu](#uruchomienie-projektu)
    - [linter](#linter)
- [Czym są wątki i co reprezentują](#czym-są-wątki-i-co-reprezentują)
- [Sekcje krytyczne i ich rozwiązanie](#sekcje-krytyczne-i-ich-rozwiązanie)

## Opis problemu
 - N filozofow siedzi przy okraglym stole
 - kazdy filozof posiada dwa widelce (jeden z lewej drugi z prawej strony)
 - filozof zajada tylko wtedy kiedy podniesie dwa widelce (z lewej i prawej strony) jednoczenie, tym samym zabierajac mozliwosc zajadania filozofom siedzacym obok niego, zabierajac im po jednym widelcu
 - gdy filozof nie zajada, wowczas mysli

chodzi o to, aby zaimplementowac mechanizmy prewentujace deadlocka (gdy wszyscy filozofowie podniosa jeden widelec i beda czekac na drugi), oraz dostepu do jednego zasobu (widelca) dokladnie przez jednego filozofa

## Instrukcje uruchomienia projektu

#### uruchomienie projektu
w sciezce projektu ```philosophers.exe 5```

gdzie argument to ilosc filozofow

#### linter
w sciezce projektu
```cpplint --filter=-whitespace,-legal $YOURFILENAME$```


## Czym są wątki i co reprezentują
watki to nasi filozofowie, poniewaz dzialaja w tym samym czasie, probujac zajadac

## Sekcje krytyczne i ich rozwiązanie
mutexami beda nasze widelce gdyz do nich dostep powinien miec tylko jeden filozof naraz

bez mutexow mogloby dojsc do tzw. race condition, czyli stanu w ktorym dwoch filozofow mysli ze ma ten sam widelec, mimo ze ktorys z nich podniosl go pierwszy

deadlock to sytuacja w ktorej zaden watek nie moze kontynuowac pracy, poniewaz kazdy watek czeka na zasob ktory trzyma juz inny watek

poczatkowa sytuacja gdzie sekcja krytyczna moze wystapic, to gdy wszyscy filozofowie podniasa ten sam widelec np. lewy
najprostszym rozwiazaniem jest zaimplementowanie rozwiazania modulo 2, przysty filozof podnosi lewy widelec jako pierwszy, nieparzysty filozof podnosi prawy widelec jako pierwszy
(majac na mysli parzysty filozof mam na mysli jego miejsce w tablicy)

problem można też rozwiązać w alternatywny sposób, stosując semafory, wówczas filozof może jeść tylko gdy dwa widelce są dostępne co reprezentuje właśnie semafor.
w zastosowaniu z mutexami, podnoszone widelce są "synchronicznie", najpierw lewy potem prawy, więc filozof może czekać gdy podniesiony jest tylko jeden widelec.
