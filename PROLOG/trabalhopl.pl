:- dynamic distancia/3.
:- dynamic goal/1.

consulta_arquivo:-
	open('arquivo.txt',read, S),
	assertar(S),
	close(S).


assertar(S):-
	at_end_of_stream(S),!.

assertar(S):-
	\+ at_end_of_stream(S),!,
	leiaPalavra(S,X),
	leiaPalavra(S,Y),
	leiaPalavra(S,Z1),
	atom_number(Z1,Z),
	assert(distancia(X,Y,Z)),
	assertar(S).

caminho(X,Y):-
	distancia(X,Y,_).

caminho(X,Y):-
	distancia(X,Z,_),
	caminho(Z,Y).

dist_caminhos(X,Y,Z):-
	distancia(X,Y,Z).


dist_caminhos(X,Y,L):-
	distancia(X,A,T),	
	dist_caminhos(A,Y,Z1),
	L is Z1+T.

caminhos(X,Y,Z):-
	findall(W,dist_caminhos(X,Y,W),Z).

menor_caminho(X,Y,Z):-
	caminhos(X,Y,L),
	menor_lista(L,Z).

menor_lista([X],X).

menor_lista([H|T],W):-
	menor_lista(T,W1),
	H<W1,
	W is H.

menor_lista([H|T],W):-
	menor_lista(T,W1),
	H>W1,
	W is W1.


maior_caminho(X,Y,Z):-
	caminhos(X,Y,L),
	maior_lista(L,Z).

maior_lista([X],X).

maior_lista([H|T],W):-
	maior_lista(T,W1),
	H>W1,
	W is H.

maior_lista([H|T],W):-
	maior_lista(T,W1),
	H<W1,
	W is W1.

procurar_menor:-
	new(J, frame('procurar menor')),
	new(C, dialog),
	send(C, append, new(Cidade1, text_item('primeira cidade'))),
	send(C, append, new(Cidade2, text_item('segunda cidade'))),
	send(C, append(button(procurar, and(message(@prolog, janela_dist,
										 Cidade1?selection,
										 Cidade2?selection),
									message(Cidade1, clear),
									message(Cidade2, clear))))),
	send(C, append, button(fechar, message(J, destroy))),
	send(J, append, C),
	send(J, open).


janela_dist(Cidade1, Cidade2):-
	menor_caminho(Cidade1, Cidade2, Dist),
	new(J, frame('distancia')),
	new(D, dialog),
	atom_number(T, Dist),
	send(D, append(text_item('Cidade1: ',Cidade1))),
	send(D, append(text_item('Cidade2: ',Cidade2))),
	send(D, append(text_item('Menor distancia: ',T))),
	send(J, append, D),
	send(J, open).



leiaPalavra(Fluxo,Palavra):-
	get_code(Fluxo,Caracter),
	verificaELeiaResto(Caracter,Caracteres,Fluxo),
	atom_codes(Palavra,Caracteres).

verificaELeiaResto(10, [], _):- !.
verificaELeiaResto(32, [], _):-!.
verificaELeiaResto(-1, [], _):- !. 

verificaELeiaResto(Caracter,[Caracter|Caracteres],F):-
get_code(F,ProxCaracter),
verificaELeiaResto(ProxCaracter,Caracteres,F).

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

listar_cidades:-
	setof(X,Y^caminho(X,Y),L1),
	setof(X1,Y1^caminho(Y1,X1),L2),
	concatena(L1,L2,L3),
	comprimir(L3,L),
	length(L,Tam),!,
	new(J, frame('quantidade_de_cidades')),
	new(D, dialog),
	send(D, append(text_item('N de cidades :', Tam))),
	send(J, append, D),
	send(J,open).
	

concatena([], L, L). 
concatena([X | R1], L, [X | R]):-
     concatena(R1, L, R). 

inverter([],[]).
inverter([X|Y],R):-
inverter(Y,R1),
append(R1,[X],R).

solve_prof(Node, Solution):-
	depthfirst([],Node,Solution1),
	inverter(Solution1,Solution).

depthfirst(Path, Node, [Node|Path]):-
	goal(Node).

depthfirst(Path, Node, Sol):-
	distancia(Node,Node1,_),
	\+ member(Node1, Path),
	depthfirst([Node|Path],Node1, Sol).


todos_caminhos(X,Y):-
	assert(goal(Y)),
	setof(H,X^solve_prof(X,H),L),
	distancia_lista(L, Lista_dist),
	separar(L,Lista_dist,Fim),
	write(Fim),
	retractall(goal(_)).
	





separar([],[],[]).
separar([H|T],[H1|T1],R):-
	append([H1],[],L1),
	append([H],L1,L),
	separar(T,T1,R1),
	juntar(L,R1,R).


distancia_lista([],[]).
distancia_lista([H|T],R):-
	distanciar(H,R1),
	distancia_lista(T,R2),
	juntar(R1,R2,R).

juntar(R1,R2,[R1|R2]).

distanciar([_],0).
distanciar([H|T],R):-
	retira_cabeca(T,H1),
	distancia(H,H1,Dist1),
	distanciar(T,Dist2),
	R is Dist1 + Dist2.


retira_cabeca([H|_],H).