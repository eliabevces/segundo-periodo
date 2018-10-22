historico(marcelo,[ip,pl]).
historico(francisco, [c1,ip,c2,poo,pl,aed2]).

grade(computacao,[ip,aed2,pl,poo]).

formado(A,C):-
historico(A,L1),
grade(C,L2),
esta_contido(L2,L1).

esta_contido([],_).

esta_contido([X|R],L):-
member(X,L),
esta_contido(R,L).

pendencias(A,C,R):-
historico(A,L1),
grade(C,L2),
dif(L2,L1,R).

dif([],_,[]).
dif([H|T],L,[H|Z]):-
\+member(H,L),
dif(T,L,Z).

dif([H|T],L,Z):-
member(H,L),
dif(T,L,Z).