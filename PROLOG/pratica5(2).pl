media(L,R):-
medias(L,0,0,R).


medias([],X,Y,R):-
R is X/Y.
medias([H|T],A,Tam,R):-
Tam1 is Tam+1,
A1 is A+H,
medias(T,A1,Tam1,R).

soma(L,R):-
somas(L,0,R).

somas([],R,R).

somas([H|T],A,R):-
A1 is A+H,
somas(T,A1,R).

inverter([],[]).

inverter([H|T],R):-
inverter(T,R1),
append(R1,[H],R).

prod_esc(L,L1,R):-
prod_escs(L,L1,[],R).

prod_escs([],[],L,R):-
somav(L,R).

prod_escs([H|T],[H1|T1],Lis,R):-
Temp is H*H1,
prod_escs(T,T1,[Temp|Lis],R).



somav([],0).
somav([H|T],R):-
somav(T,R1),
R is R1+H.

inserirn(1,H,T,[H|T]).
inserirn(X,Y,[H|T],[H|Z]):-
X1 is X-1,
inserirn(X1,Y,T,Z).

vsoma(L,L1,R):-
vsomas(L,L1,[],R).

vsomas([],[],L,L).

vsomas([H|T],[H1|T1],L,R):-
Temp is H+H1,
vsomas(T,T1,[Temp|L],R).