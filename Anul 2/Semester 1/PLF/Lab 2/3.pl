length1([], 0).
length1([H|T], N) :- length1(T, N1), N is N1+1.

grabs([],_,[],[]).
grabs([X|T],X,As,K):-As=[X|D],grabs(T,X,D,K).
grabs([H|T],X,As,K):- K=[H|E],grabs(T,X,As,E).

freq([],[]).
freq([A|L],[[A,N]|Y]) :-
   grabs([A|L],A,As,K),
   length1(As, N),
   freq(K,Y).

% freq([a,a,a,b,b,b,c,c,d],Ys).
