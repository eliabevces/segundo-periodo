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
	Z is Z1+T.