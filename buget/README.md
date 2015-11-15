# buget

## Enunț

Prim-ministrul României și-a dat demisia, iar în locul său a fost numit de către președinte un prim-ministru tehnocrat.

> TEHNOCRAȚÍE s. f. 1. Orientare în sociologia și politologia contemporană potrivit căreia rolul în conducerea societății trebuie să revină specialiștilor din diverse domenii. 2. Sistem de guvernare controlat de tehnicieni, îndeosebi experți tehnici, ca alternativă la cel în care conducerea o au factorii politici. ♦ Intelectualitate tehnică (cu rol conducător). – Din fr. technocratie. 

> https://dexonline.ro/definitie/tehnocrație

Însă, imediat ce s-a întâmplat acest lucru, au început problemele. Prim-ministrul are în subordinea lui N agenții, fiecare cu bugetul Bi și un total al bugetelor S. Parlamentul României vrea să aprobe noua lege bugetului, prin care bugetul total al agențiilor din subordinea prim-ministrului să fie redus la B, care este mai mic ca S. 

## Cerință

Fiindcă noul prim-ministru vrea să fie imparțial, el vrea să găsească un plafon maxim K, astfel încât toate agențiile să aibă bugetul mai mic sau egal cu acest K, noua sumă a tuturor bugetelor să fie mai mică sau egală cu B, iar numărul de agenții care au bugetul scăzut să fie minim.

## Date de intrare

* pe prima linie se află N (numărul de agenții) și B (noua buget total al agențiilor).
* pe a doua linie vor fi N numere, reprezentând bugetul inițial al fiecărei agenții

## Date de ieșire

* pe prima linie se va afla K, plafonul maxim.

## Limite
* 0 < N < ceva_ce_trebuie_sa_decidem1
* 1 < buget < ceva_ce_trebuie_sa_decidem2
* 1 <= plafon < ceva_ce_trebuie_sa_decidem2
* Se garantează că există un plafon în acel interval astfel încât suma bugetelor să fie mai mică sau egală cu B.

## Exemplu

```
5 38
9 4 12 2 15
```

Suma inițială este `9+4+12+2+15=42`. 

O variantă ar putea fi un plafon maxim de 3. Suma ar deveni `3+3+3+2+3=13`, care este mai mică sau egală decât 38, dar ar fi afectate 4 agenții.

Varianta cea mai bună ar fi un plafon maxim de 12. Suma ar deveni `9+4+12+2+12=38`, care este mai mică sau egală decât 38, și este afectată o singură agenție.
