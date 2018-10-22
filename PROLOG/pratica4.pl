%inserirn(+pos,+num,+lista,-retorno)
inserirn(1,X,E,[X|E]).
inserirn(P,N,[H|T],[H|Z]):-
P1 is P-1,
inserirn(P1,N,T,Z).


inserirl(_,[],E,E).
inserirl(P,[X|Y],L,R):-
inserirn(P,X,L,R1),
P1 is P+1,
inserirl(P1,Y,R1,R).

%remove(+pos,+lista,-retorno).

remove(1,[_|Y],Y).
remove(P,[H|T],[H|Z]):-
P1 is P-1,
remove(P1,T,Z).

%remove(+pos1,+pos2,+lista,-retorno).
%pos1<pos2

remove2(N1,N2,L,R):-
remove(N2,L,R1),
remove(N1,R1,R).