%11. Sa se genereze toate subsirurile de lungime 2n+1, 
%formate doar din 0, -1 sau 1, astfel incat a1 = 0,...,a2n+1 = 0 
%si| ai+1 – ai | = 1 sau 2, pentru orice 1<= i <= 2n.

candidat(1,_,[0],E):-!,
	abs(0-E)>0.
candidat(N,M,[0|Rez],_):-
	N = M,!,
	N1 is N-1,
	candidat(N1,M,Rez,0).
candidat(N,M,[1|Rez],E):-
	abs(1-E)>0,
	N1 is N-1,
	candidat(N1,M,Rez,1).
candidat(N,M,[0|Rez],E):-
	abs(0-E)>0,
	N1 is N-1,
	candidat(N1,M,Rez,0).
candidat(N,M,[-1|Rez],E):-
	abs(-1-E)>0,
	N1 is N-1,
	candidat(N1,M,Rez,-1).	

main(0,[]).
main(N,L):-
	N1 is N*2+1,
	candidat(N1,N1,L,0).