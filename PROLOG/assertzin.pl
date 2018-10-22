inicio:-
repeat,
write('1-listar relacionamentos pai'),nl,
write('2-adicionar um relacionamento pai'),nl,
write('3-remove um relacionamento pai'),nl,
write('4- Fim'),nl,
read(R),
(R = 4 ,nl,write('Fim!!!!!!!!!!!');executa(R),fail).

executa(1):- listing(pai/2).
executa(2):- read(X),nl,read(Y),assertz(pai(X,Y)).
executa(3):- read(W),nl,retract(pai(W,_).
