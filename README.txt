1. Para compilar utilize o comando "make all" do makefile, resultando no executável "run"

2. dentro da pasta jsonInput o arquivo scene deverá ter o seguinte formato

Um objeto chamado "camera", com vetores com os nomes: "origin", "horizontal", "vertical" e "corner"
Representando respectivamente a coordenada do(a):
	- A origem dos raios
	- A largura da tela onde serão projetados
	- A altura da tela onde serão projetados
	- O canto inferior esquerdo da tela onde serão projetados
     Cada valor deve sempre ser escrito com um '.' para representar a casa decimal, mesmo que o valor não tenha parte decimal. (ex: 1 deve ser escrito como 1.0 ).

Um array chamado "primitives" com arrays contendo respectivamente o x,y,z,raio de esferas a serem adicionadas na cena. O raio deve sempre ser escrito com um '.' para representar a casa decimal, mesmo que o valor não tenha parte decimal. (ex: 1 deve ser escrito como 1.0 ).


Exemplo:

{
    "camera":{
        "origin":[0.0,0.0,0.0],
        "horizontal":[4.0,0.0,0.0],
        "vertical":[0.0,2.0,0.0],
        "corner":[-2.0,-1.0,-1.0]
    }

    "primitives":[
        [ 0, 0,-1, 0.5],
        [ 1, 0,-1, 0.5],
        [-1, 0,-1, 0.5],
        [ 0, 1,-1, 0.5],
        [ 0,-1,-1, 0.5]
    ]
}


3. Ao ser executado, o programa exibirá uma função sample que dará uma demonstração da projeção dos raios sobre uma esfera


4. A imagem resultante dessa projeção será salva em imageOutput