%impartire
divide(D, _, D).
divide(D, C, C) :-
    dif(D, C).

%divizorii unui nr N
divisor(N, R) :-
    UB is floor(sqrt(N)),
    between(2, UB, D),
    0 is N mod D,
    C is N / D,
    divide(D, C, R).

%lipeste listei un element(in fata)
new([],F,[F]).  % if your list is empty.
new([X|XS],F,[F,X|XS]):-
	new(XS,F,YS).

%creeaza lista de divizori inclusiv N pe prima pozitie
divisors(N, Ds) :-
    setof(D, divisor(N, D), Dr),
    new(Dr,N,Ds).

%creeaza rezultatul doar ca formeaza lista de liste
accCp([],[]).
accCp([H|T1],[Rezi|T2]) :-
	accCp(T1,T2),
	divisors(H,Rezi),!.
accCp([H|T1],[[H]|T2]) :-
	accCp(T1,T2).

%functie care concateneaza liste
list_concat([],[]).
list_concat([L|Xss],Ys) :-
    append(L,Ys0,Ys),
    list_concat(Xss,Ys0).

%functie main care da rezultatul cerut
rezultat(L1,Rez):-
	accCp(L1,L2),
	list_concat(L2,Rez).

%punctul b, lista de liste
pctB([],[]).
pctB([H|T1],[H2|T2]):-is_list(H),!,
                    rezultat(H,H2),
                    pctB(T1,T2).
pctB([H|T1],[H|T2]):-pctB(T1,T2).

%APEL: pctB([1, [2, 5, 7], 4, 5, [1, 4], 3, 2, [6, 2, 1], 4, [7, 2, 8, 1], 2],R); true.
%pt ca sa afiseze toata lista