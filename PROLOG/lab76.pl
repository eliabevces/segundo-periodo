gera(concatena_com([],L), L).
:-op(80, xfx, gera).
:-op(50, xfx,concatena_com).

existe_em(X,[Y|_]):-
X=Y,!.

existe_em(X,[Y|Z]):-
not(X=Y),
existe_em(X,Z).

:-op(50,xfx,existe_em).

deleta(X,[X|Y],Y).
deleta(X,[Y|Z],[Y|R]):-
not(X=Z),
deleta(X,Z,R).

:-op(80, fx, deleta).

se(entao(pai(X,Y),filho(Y,X))).
:-op(80,fx,se).
:-op(70,xfx,entao).