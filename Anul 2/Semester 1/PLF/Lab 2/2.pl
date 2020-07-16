removeAll(_, [], []).
removeAll(X, [X|T], L):- removeAll(X, T, L), !.
removeAll(X, [H|T], [H|L]):- removeAll(X, T, L ).
%Compilam astfel: removeAll(1,[1,1,2],L).
