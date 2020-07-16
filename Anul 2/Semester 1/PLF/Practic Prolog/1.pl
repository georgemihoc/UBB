elimin([],[]).
elimin([H1|[H2|[H3|T]]],L):-H1>H2,
                           H2>H3,!,
                           L1=[H2|[H3|T]],
                           elimin(L1,L).
elimin([H1|[H2|[H3|T]]],L):-H1>H2,
                           H2=<H3,!,
                           L1=[H3|T],
                           elimin(L1,L).
elimin([H1|[H2|[]]],[]):-H1>H2,!.
elimin([H|T],[H|L]):-elimin(T,L).