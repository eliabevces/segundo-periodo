copia(A1,A2):-
see(A1),
tell(A2),
processa_arquivo,
seen,
told.

processa_arquivo:-
read(X),
processa_termo(X).

processa_termo(end_of_file):- !.
processa_termo(X):-
write(X),
write('.'),
processa_arquivo.

teste:-
tell('dados.pl'),
read(X),
write(X),
told.

resposta(R):-
nl,
write('digite s ou n '),
get(Resp), get0(_),
verifica(Resp, R),!.

resposta(R):-
write('	TA ERRADO '),
resposta(R).

verifica(115,sim).
verifica(83,sim).
verifica(110,nao).
verifica(78,nao).

dobre(X,Y):-
Y is 2*X.

calcula_dobro:-
leia_atomo(X),
Y is 2*X,
write('o dobro de '),
write(X),
write(' eh '),
write(Y),
write(' ').

leia_atomo(A):-
le_str(String),
name(A,String).