p(1).
p(2):-!.
p(3).

classe(Numero,positivo)  :-  Numero  >  0,!. 
classe(0,zero):-!. 
classe(Numero,negativo)  :-  Numero  <  0. 

divide([],[],[]).

divide([H|T],P,N):-
classe(H,positivo),
divide(T,P1,N),
append([H],P1,P),!.


divide([H|T],P,N):-
classe(H,zero),
divide(T,P1,N),
append([H],P1,P),!.

divide([H|T],P,N):-
classe(H,negativo),
divide(T,P,N1),
append([H],N1,N),!.
