#include <cstdio>
#include <iostream>
#include <stack>

/*
Aluno: Franzé Jr.

Este algoritmo verifica se ha ciclo em grafos.
Dado um grafo g, todos os vértices são pintados de branco.
Um vértice(o qual iniciamos) é pintado de cinza, cinza significa que
o vértice está sendo analisado. Branco é que ele ainda não foi analisado
preto diz que nós já analisamos e não podemos concluir nada.

Se o algoritmo encontrar um cinza vizinho de cinza, o algoritmo termina,
pois há ciclo. Se ele não encontrar isso, não há ciclo.



*/



using namespace std;


typedef struct grafo{
	int cor; // Inteiro que diz a cor do vértice, 0 - branco , 1- cinza, 2 - preto	
}grafo;

int const vertices = 3;
grafo g[vertices];
int matrizAdjacencia[vertices][vertices];


int existeBranco(){
	int i;

	for(i=0; i<vertices; i++){
	
		if(g[i].cor == 0) return i;
		
		
	
	}
	
	return -1;


}

bool existeCinza(int z){

	for(int i=0; i< vertices; i++){
		if( i != z && matrizAdjacencia[z][i] == 1){
		
			if( g[i].cor == 1) return true;
		
		}
	
	}
	
	return false;

}

int existeVizinhoBranco(int z){

	for(int i=0; i< vertices; i++){
		if( (i != z) && matrizAdjacencia[z][i] == 1){
		
			if( g[i].cor == 0)
			{
			return i;
			 }
			//Se existe vizinho branco de z, retorna o indice do primeiro vizinho
		
		}
	
	}
	
	return -1;

}


int main(){

	
	
	stack<int> pilha;
	
	int elemento;
	int u, z,w;
	
	
	
	//Pegando os elementos e colocando na matriz de adjacência
	for(int x=0; x<vertices;  x++){
		
		for(int y=0; y<vertices; y++){
		
			scanf("%d", &elemento);
			matrizAdjacencia[x][y] = elemento;
	
		}
	}
	
	//Imprimindo a matriz para saber como esta
	for(int x=0; x<vertices;  x++){
		
		printf("\n");
		for(int y=0; y<vertices; y++){
		
			printf("%d ",matrizAdjacencia[x][y]);
	
		}
	}

	cout <<endl; //Pula uma linha so pra ficar bonito
	
	
	//Pintando todos os vértices de  branco
	
	for(int z = 0; z< vertices; z++){
	
		g[z].cor = 0; // 0 representa branco	
	
	}
	
	printf("Imprimindo o vetor de vertices apos ser pintado: ");
	for(int z = 0; z< vertices; z++){
	
		printf("%d", g[z].cor);
	
	}
	
	
	cout <<endl; //Pula uma linha so pra ficar bonito
	
	while(existeBranco() != -1){
		
		//Recebe um vértice de G
		u = existeBranco() ;
	
		//Colocando o primeiro na pilha e pinta este de cinza
		pilha.push(u);
		g[u].cor = 1;
		
		
		while(!pilha.empty()){
			
			z = pilha.top();
			
			
			if(existeCinza(z)){
				
				printf("Achoooou!\n");
				return 1; //Achou ciclo, esse 1 eh so pra trollar
			}
			
			w = existeVizinhoBranco(z);
			if( w != -1 ){
			
				pilha.push(w);
				g[w].cor = 1; //w fica com cor cinza
			
			}
			else{
				pilha.pop();
				g[z].cor = 2; //Z fica com cor preta
			
			}
			
		
		
		}
	
	}
	
	printf(" NAAAAAO Achoooou! Heahuehauehuahea\n");
	return 0;
	






}
