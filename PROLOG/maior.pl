maior([P|R],M):-
maiorresto(R,P,M).

maiorresto([],X,X).

maiorresto([H|T],P,M):-
H>P,
maiorresto(T,H,M).

maiorresto([H|T],P,M):-
H =< P,
maiorresto(T,P,M).

tamanho(L,R):-
tamanhoaux(L,0,R).

tamanhoaux([],R,R).
tamanhoaux([_|T],A,L):-
A1 is A+1,
tamanhoaux(T,A1,L).