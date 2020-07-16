% Sa se calculeze suma elementelor pare dintr-o lista cu elemente numerice.

% sumaPar(L: lista, R: integer)
% L - lista de numere pentru care calculam suma numerelor pare
% R - rezultatul
% model de flux (i,o) sau (i,i)

sumaPar([],0):-!. % daca lista este vida, suma este 0. ! - taietura- se ignora restul clauzelor
sumaPar([A|L],S):-  %impartim lista in doua (capul A si coada L)
    A mod 2=:=0,
    sumaPar(L,S1), % calculam suma numerelor pare din restul listei
    S is A+S1,!. % rezultatul final este rezultatul apelului recursiv plus primul element
sumaPar([_|L],S):- % impartim lista in doua, dar nu ne intereseaza primul element (_ in loc de nume)
    sumaPar(L,S).

% Apel la executie:   sumaPar([1,2,3,4],S).
% se va afisa solutia  S=6