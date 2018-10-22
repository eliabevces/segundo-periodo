% identificação(Nome,Idade,Número de contato):

identificacao(maria,28,3499814-0989).
identificacao(paulo,30,3499945-3678).
identificacao(laura,18,3499712-6577).
identificacao(pedro,22,3499431-0908).
identificacao(larissa,18,3499126-9982).
identificacao(carlos,30,3490231-9132).
identificacao(monica,25,3491245-0741).
identificacao(marcio,16,3499812-8450).
identificacao(julia,20,3499743-8888).
identificacao(tiago,22,3499627-0901).
identificacao(fabiola,28,3499034-1234).
identificacao(breno,21,3499010-4321).
identificacao(marcus,17,6199852-3548).
identificacao(aurora,18,3499684-2574).
identificacao(daisy,20,3499584-8564).
identificacao(matheus,19,3199858-6584).
identificacao(bruno,30,6499875-5244).
identificacao(ana,30,6199854-7485).
identificacao(marcia,25,3198547-8452).
identificacao(marcio,20,6198457-8457).
identificacao(elisa,18,3499658-7485).

% masculino(Nome):

masculino(pedro).
masculino(paulo).
masculino(carlos).
masculino(marcio).
masculino(tiago).
masculino(breno).
masculino(marcus).
masculino(matheus).
masculino(bruno).
masculino(marcio).

%feminino(nome):

feminino(laura).
feminino(maria).
feminino(larissa).
feminino(monica).
feminino(julia).
feminino(fabiola).
feminino(aurora).
feminino(daisy).
feminino(ana).
feminino(marcia).
feminino(elisa).

% at_fisicos(Nome,Cor dos olhos, Cor da pele,Comprimento/formato/cor do
% cabelo,Altura, Peso):

at_fisicos(maria,verde,parda,longo_liso_preto,1.60,50).
at_fisicos(paulo,marrom,branca,curto_liso_preto,1.70,80).
at_fisicos(laura,castanho_escuro,branca,longo_liso_preto,1.50,55).
at_fisicos(pedro,castanho_escuro,preta,curto_encaracolado_preto,1.80,70).
at_fisicos(larissa,roxo,branca,longo_liso_loiro,1.55,53.2).
at_fisicos(carlos,marrom_escuro,branca,longo_encaracolado_marrom,1.75,66).
at_fisicos(monica,mel,preta,medio_liso_castanho,1.78,69.5).
at_fisicos(marcio,castanho_claro,parda,curto_liso_marrom,1.85,77.5).
at_fisicos(julia,azul,preta,longo_liso_preto,1.66,57).
at_fisicos(tiago,preto,branca,medio_encaracolado_marrom,1.60,80).
at_fisicos(fabiola,verde_claro,branca,longo_liso_loiro,1.50,55.7).
at_fisicos(breno,castanho_escuro,parda,curto_encaracolado_preto,1.67,76.7).
at_fisicos(marcus,verde,preta,longo_encaracolado_loiro,1.90,75).
at_fisicos(aurora,azul,branca,curto_liso_castanho,1.62,55).
at_fisicos(daisy,castanho,branca,longo_encaracolado_preto,1.70,60).
at_fisicos(matheus,verde,preta,curto_liso_loiro,1.80,90).
at_fisicos(bruno,mel,preta,longo_encaracolado_marrom,1.60,70).
at_fisicos(ana,verde,branca,curto_liso_loiro,1.66,68).
at_fisicos(marcia,marrom,branca,longo_liso_azul,1.70,70).
at_fisicos(marcio,azul,preta,curto_encaracolado_ruivo,1.85,90).
at_fisicos(elisa,verde,branca,longo_liso_loiro,1.50,54).

%esporte(Nome,Esporte praticado):

esporte(maria,natacao).
esporte(paulo,handbol).
esporte(laura,tenis).
esporte(pedro,futebol).
esporte(larissa,tenis).
esporte(carlos,futebol).
esporte(monica,corrida).
esporte(marcio,judo).
esporte(julia,corrida).
esporte(tiago,handbol).
esporte(fabiola,futebol).
esporte(breno,volei).
esporte(marcus,basquete).
esporte(aurora,peteca).
esporte(daisy,basquete).
esporte(matheus,tenis).
esporte(bruno,futebol).
esporte(ana,basquete).
esporte(marcia,volei).
esporte(marcio,judo).
esporte(elisa,corrida).

% fav_filme(Nome,Filme favorito):

fav_filme(maria,rambo).
fav_filme(paulo,avatar).
fav_filme(laura,velozes_e_furiosos).
fav_filme(pedro,capitao_america).
fav_filme(larissa,homem_aranha).
fav_filme(carlos,avatar).
fav_filme(monica,velozes_e_furiosos).
fav_filme(marcio,pantera_negra).
fav_filme(julia,homem_aranha).
fav_filme(tiago,garfield).
fav_filme(fabiola,transformers).
fav_filme(breno,pantera_negra).
fav_filme(marcus,her).
fav_filme(aurora,her).
fav_filme(daisy,vingadores).
fav_filme(matheus,garfield).
fav_filme(bruno,vingadores).
fav_filme(ana,avatar).
fav_filme(marcia,pantera_negra).
fav_filme(marcio,her).
fav_filme(elisa,homem_aranha).

% fav_banda(Nome,Banda favorita):

fav_banda(maria,pink_floyd).
fav_banda(paulo,guns_n_roses).
fav_banda(laura,pink_floyd).
fav_banda(pedro,red_hot_chill_peppers).
fav_banda(larissa,linkin_park).
fav_banda(carlos,linkin_park).
fav_banda(monica,the_rolling_stones).
fav_banda(marcio,red_hot_chill_peppers).
fav_banda(julia,simple_plan).
fav_banda(tiago,coldplay).
fav_banda(fabiola,the_beatles).
fav_banda(breno,metallica).
fav_banda(marcus,twenty_one_pilots).
fav_banda(aurora,imagine_dragons).
fav_banda(daisy,twenty_one_pilots).
fav_banda(matheus,supercombo).
fav_banda(bruno,imagine_dragons).
fav_banda(ana,lukas_graham).
fav_banda(marcia,supercombo).
fav_banda(marcio,twenty_one_pilots).
fav_banda(elisa,simple_plan).

feminino_idade(X,Y):-
   identificacao(Y,X,Z),
   feminino(Y).

masculino_idade(X,Y):-
   identificacao(Y,X,Z),
   masculino(Y).

feminino_gosto_compativel(X,Y):-
   (esporte(Y,X);fav_filme(Y,X);fav_banda(Y,X)),
   feminino(Y).

masculino_gosto_compativel(X,Y):-
   (esporte(Y,X);fav_filme(Y,X);fav_banda(Y,X)),
   masculino(Y).

