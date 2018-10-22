media(L,R):-
medias(L,0,0,R).

medias([],X,Y,R):-
R is X/Y.
medias([H|T],X,Tam,Y):-
Tam1 is Tam+1,
A is X+H,
medias(T,A,Tam1,Y).


soma(L,L1,R):-
somas(L,L1,[],R).


somas([],[],X,R):-
inverter(X,R).

somas([H|T],[H1|T1],Lis,R):-
Temp is H+H1,
somas(T,T1,[Temp|Lis],R).

inverter([],[]).
inverter([X|Y],R):-
inverter(Y,R1),
append(R1,[X],R).

produto_escalar(L,L1,R):-
produto_escalars(L,L1,[],R).

produto_escalars([],[],X,Y):-
soma_v(X,Y).

produto_escalars([H|T],[H1|T1],Lis,R):-
Temp is H*H1,
produto_escalars(T,T1,[Temp|Lis],R).

soma_v([],0).
soma_v([H|T],R):-
soma_v(T,R1),
R is R1+H.
