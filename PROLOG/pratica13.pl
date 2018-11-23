distancia(uberlandia,catalao,100).
distancia(uberlandia,itumbiara,100).
distancia(cristalina,brasilia,100).
distancia(uberlandia,araxa,200).
distancia(catalao,cristalina,200).
distancia(itumbiara,goiania,200).
distancia(goiania,brasilia,250).
distancia(catalao,goiania,260).
distancia(araxa,belo_horizonte,350).
distancia(sao_paulo,rio_de_janeiro,400).
distancia(belo_horizonte,brasilia,700).


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
	send(C, append, new(Cidade1, text item('primeira cidade'))),
	send(C, append, new(Cidade2, text item('segunda cidade'))),
	send(C, append, button(fechar, message(J, destroy))),
	send(J, append, C),
	send(J, open).