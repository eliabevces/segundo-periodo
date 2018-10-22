ultimo_elemento(X,[X]).
ultimo_elemento(X,[_|H]):-
ultimo_elemento(X,H).


penultimo_elem(X,[X,_]).
penultimo_elem(X,[_|H]):-
penultimo_elem(X,H).

nesimo_elem(X,[X|_],1).
nesimo_elem(X,[_|H],Y):-
Y1 is Y-1,
nesimo_elem(X,H,Y1).


inverter([],[]).
inverter([X|Y],R):-
inverter(Y,R1),
append(R1,[X],R).

palindromo(X):-
inverter(X,R),
X==R.



retirar_ocor(_,[],[]).
retirar_ocor(X,[X|Y],R):-
retirar_ocor(X,Y,R).
retirar_ocor(X,[Y|Z],R):-
X\=Y,
retirar_ocor(X,Z,R1),
inserir_cabeca(Y,R1,R).


comprimir([],[]).
comprimir([X|Y],R):-
comprimir(Y,R2),
retirar_ocor(X,R2,R1),
inserir_cabeca(X,R1,R).

inserir_cabeca(X,R,[X|R]).