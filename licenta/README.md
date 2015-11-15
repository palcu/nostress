# licenta

## Enunț

Mihaela e o studentă ajunsă în ultimul an la Facultatea de Matematică și Informatică. Ca să termine facultatea, studenții trebuie să scrie o lucrare de licență, sub îndrumarea unui profesor. Ea ar vrea să facă licența cu decanul facultății, dar dumnealui este o persoană ocupată, care se poate întâlni cu studenții doar în anumite N1 intervale de timp. Pe lângă asta, Mihaela s-a angajat, și se poate întâlni cu decanul doar în anumite N2 intervale de timp. În final, întâlnirea pentru stabilirea licenței ar trebui să dureze minim K minute, deoarece Mihaela nu prea știe ce subiect să aleagă pentru lucrare.

## Cerință

Date fiind cele două mulțimi de intervale în care fiecare este liber, să se returneze primul interval de timp în care Mihaela se poate întâlni cu decanul, iar întâlnirea are o durată de minim K minute, sau `-1` în caz că acesta nu există

## Date de intrare
* fiecare moment de timp va fi un număr natural pozitiv nenul care exprimă timpul în minute trecut de la miezul nopții
* pe prima linie se citește durata K
* pe a doua linie se citește N1, numărul de intervale de timp în care se poate întâlni decanul
* pe următoarele N1 linii, se află două numere X și Y, reprezentând timpul când o întâlnire a decanului se poate desfășura
* pe următoarea linie se citește N2, numărul de intervale de timp în care se poate întâlni Mihaela
* pe următoarele N2 linii, se află două numere X și Y, reprezentând timpul când o întâlnire a Mihaelei se poate desfășura

## Date de ieșire
* două numere naturale pozitive nenule, reprezentând primul interval de timp în care Mihaela se poate întâlni cu decanul, sau `-1` în caz că acesta nu există.

## Limite

* se garantează că intervalele de timp ale Mihaelei nu se suprapun între ele. Mai formal, oricare fi (Xi, Yi) și (Xj, Yj) două intervale de timp, (Yi < Xj) sau (Yj < Xi).
* se garantează separat același lucru și pentru intervalele de timp de timp ale decanului
* 0 < K < ceva_ce_vom_decide1
* 0 <= N1, N2 < ceva_ce_vom_decide2
* 1 < Xi < Yi < ceva_ce_vom_decide3, oricare ar fi un interval de timp (Xi, Yi)

## Exemplul 1

```
30
3
110 120
10 30
50 100
2
50 85
10 40
```

Mihaela și decanul ar putea să se întâlnească în intervalul `10-30`, dar acesta este de numai 20 minute. Așa că ei decid să înceapă întâlnirea să se desfășoare în intervalul `50 80`.

## Exemplul 2
```
100
2
40 50
60 80
2
30 40
10 20
```

Nu există niciun interval de timp de minim 100 de minute în care aceștia să se poată întâlni, așa că răspunsul este `-1`.
