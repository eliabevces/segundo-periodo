
inicio:-
repeat,
write('1-especifica evidência'),nl,
write('2-visualiza evidência'),nl,
write('3-adivinhe'),nl,
write('4-remove respostas'),nl,
write('5-sair'),nl,
le_atomo(R),
(R = 5 ,nl,write('Fim!!!!!!!!!!!');executa(R),fail).

executa(1):-
hipotetiza(Animal),
assertz(animal(Animal)).

executa(2):-
nl,
sim(S),
write(S),nl.

executa(3):-
write('O animal eh: '),
animal(Animal),
write(Animal),nl.

executa(4):-
removeRespostas.




/* hipoteses a serem testadas*/
hipotetiza(leopardo) :- leopardo, !.
hipotetiza(tigre) :- tigre, !.
hipotetiza(girafa) :- girafa, !.
hipotetiza(zebra) :- zebra, !.
hipotetiza(avestruz) :- avestruz, !.
hipotetiza(pinguim) :- pinguim, !.
hipotetiza(albatroz) :- albatroz, !.
hipotetiza(desconhecido). /* nao diagnosticado */

/* regras de identificação do animal */
leopardo :-
	mamifero,
	carnivoro,
	verifica(tem_manchas_escuras).
tigre :-
	mamifero,
	carnivoro,
	verifica(tem_listras_pretas).
girafa :-
	ungulado,
	verifica(tem_pescoco_grande),
	verifica(tem_pernas_grandes).
zebra :-
	ungulado,
	verifica(tem_listras_pretas).
avestruz :-
	passaro,
	verifica(nao_voa),
	verifica(tem_pescoco_grande).
pinguim :-
	passaro,
	verifica(nao_voa),
	verifica(nada),
	verifica(branco_e_preto).
albatroz :-
	passaro,
	verifica(aparece_em_estoria_de_marinheiro),
	verifica(voa).

/* regras de classificação */

mamifero :-
	verifica(tem_pelo), !.
mamifero :-
	verifica(amamenta).
passaro :-
	verifica(tem_penas), !.
passaro :-
	verifica(voa),
	verifica(poe_ovos).
carnivoro :-
	verifica(come_carne), !.
carnivoro :-
	verifica(tem_dentes_pontiagudos),
	verifica(tem_garras).
ungulado :-
	mamifero,
	verifica(tem_cascos), !.
ungulado :-
	mamifero,
	verifica(rumina).

/* formulando perguntas */
pergunta(Pergunta) :-
	write('O animal tem a seguinte caracteristica: '),
	write(Pergunta),
	write('? '),
	le_atomo(Resposta),
	nl,
	trate(Pergunta,Resposta).

trate(Pergunta,Resposta) :-
	Resposta == s,
	assert(sim(Pergunta)),!.
trate(Pergunta,Resposta) :-
	Resposta == n,
	assert(nao(Pergunta)),!,fail.
trate(Pergunta,_):-
	write('resposta invalida!'), nl,nl,
	pergunta(Pergunta).

:- dynamic sim/1,nao/1.

/* verificando */

verifica(S) :- sim(S),!.
verifica(S) :- nao(S),!, fail.
verifica(S) :- pergunta(S).

/* remove todas as assercoes de sim e nao */

removeRespostas :- retractall(sim(_)),
					retractall(nao(_)),
					retractall(animal(_)).

removeRespostas :- abolish(sim/1), abolish(nao/1),dynamic(sim/1),dynamic(nao/1).


le_atomo(A) :-
le_str(S),
name(A, S).

le_str(S) :-
get0(C),
le_str_aux(C, S).

le_str_aux(-1, []) :- !. % EOF

le_str_aux(10, []) :- !. % EOL(UNIX)

le_str_aux(13, []) :- !. % EOL (DOS)

le_str_aux(C, [C|R]) :-
le_str(R).