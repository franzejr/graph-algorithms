#include <cstdio>
#include <iostream>
#include <queue>


using namespace std;


typedef struct grafo{
	int dist; // Inteiro que diz a distancia do vertice ate o primeiro
}grafo;

int const vertices = 3;
grafo g[vertices];
int matrizAdjacencia[vertices][vertices];


int main(){

	queue<int> fila;
	int elemento;
	
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




return 0;
}
