:- dynamic(ator/4).

inicio:-
repeat,
consult('atores.pl'),
write('1-listar atores'),nl,
write('2-adicionar ator'),nl,
write('3-remove ator'),nl,
write('4- Fim'),nl,
le_atomo(R),
(R = 4 ,nl,write('Fim!!!!!!!!!!!');executa(R),fail).

executa(1):-
    listing(ator/4).

executa(2):-
write('Nome do ator: '),
    le_atomo(X),
    write('Nome do filme: '),
    le_atomo(Y),nl,
    write('data de lançamento: '),
    le_atomo(Z),nl,
    write('RANK: '),
    le_atomo(W),nl,
    assertz(ator(X,Y,Z,W)),
    tell('atores.pl'),
    listing(ator/4),
    told.

executa(3):-
	write('Nome do ator: '),
    le_atomo(X),
    write('Nome do filme: '),
    le_atomo(Y),nl,
    retract(ator(X,Y,Z,W)),
    tell('atores.pl'),
    listing(ator/4),
    told.


le_atomo(Atomo) :-
le_str(String),
name(Atomo, String).

le_str(String) :-
get0(Char),
le_str_aux(Char, String).

le_str_aux(-1, []) :- !. % EOF

le_str_aux(10, []) :- !. % EOL(UNIX)

le_str_aux(13, []) :- !. % EOL (DOS)

le_str_aux(Char, [Char|Resto]) :-
le_str(Resto).


