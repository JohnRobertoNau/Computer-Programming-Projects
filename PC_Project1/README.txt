Problema 1: cutii
A durat cateva ore sa rezolv prima problema si am efectuat-o in 2-3 zile deoarece a trebuit sa mai aduc modificari
Rezolvare contine pe langa main, 2 functii:
-O functie de parcurgere, care returneaza 1 daca prizonierul si-a gasit propriul bilet
in mai putin de p/2 pasi si 0 in caz contrar
-O functie care arata ciclurile parcurse. Am folosit un vector a ( la inceput cu toate elementele 0) pentru a verifica daca o cutie a fost sau nu intr-un ciclu
In vectorul b am pastrat numerele care trebuie afisate.

Problema 4: masini
La problema a 4a am lucrat cateva zile. Am folosit o structura pentru a accesa mai usor caracteristicile fiecarei masini.
Am folosit 4 functii: o functie pentru cerinta a, una pentru b, una pentru c si o functie care m-a ajutat sa rezolv cerinta c.
-Prima functie cerintaA calculeaza cate masini consuma benzina, cate consuma motorina,cate sunt de tip hibrid si cate sunt electrice.
-Functia cerintaB calculeaza consumul total si suma totala al tuturor masinilor de acelasi brand.
Am folosit vectorul w pentru a memora pozitiile la care am gasit brandul respectiv. Vectorii ct si st i-am folosit pentru a memora consumul total si suma totala.
"*nr" l-am folosit pentru a afla numarul de elemente al vectorului w
-Pentru cerinta c am folosit doua functii. Functia nrcorect verifica daca un numar e corect sau nu si returneaza 1 in caz afirmativ si 0 in caz negativ
In functia cerintaC am folosit vectorul w pentru a pastra pozitiile masinilor cu numere invalide si k pentru a tine minte cate sunt
IN MAIN am folosit un sir "start" pentru a stabili subpunctul problemei
si am alocat dinamic vectorii.
In functie de cerinta, am apelat functiile respective si am afisat rezultatul cerut

