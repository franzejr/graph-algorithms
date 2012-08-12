#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

typedef struct grafo{
	int visitado; // Inteiro que diz se o vertice foi ou nao visitado
	
}grafo;

int main(){

	int VERTICES =  3;
	int elemento;
	int x;

	stack<int> pilha;
	
	grafo g[VERTICES]; // Cria um vetor da estrutura grafo

	int matrizAdjacencia[VERTICES][VERTICES];

	
	for(int x=0; x<VERTICES;  x++){
		
		for(int y=0; y<VERTICES; y++){
		
			scanf("%d", &elemento);
			matrizAdjacencia[x][y] = elemento;
	
		}
	}

	//Imprimindo a matriz para saber como esta
	for(int x=0; x<VERTICES;  x++){
		
		printf("\n");
		for(int y=0; y<VERTICES; y++){
		
			printf("%d ",matrizAdjacencia[x][y]);
	
		}
	}

	cout <<endl; //Pula uma linha para ficar bonito
	

	
	//Coloca todos os visitados como 0, isto é, diz que eles não foram visitados ainda.
	for(int z = 0; z< VERTICES; z++){
	
		g[z].visitado = 0;	
	
	}
	
	pilha.push(0);
	g[0].visitado = 1;
	
	
	
	while( !pilha.empty() ){
	//printf ("Sem esse print o programa não funciona");
	
		x = pilha.top();
		
		for(int j=0; j < VERTICES; j++){
		
			for(int i=0; i < VERTICES; i++){
				
				if( matrizAdjacencia[j][i] == 1){
					
					if( g[i].visitado == 0){
						
						g[i].visitado = 1; //O vertice foi visitado
						
						pilha.push(i);
						x = pilha.top();

					
					}
					
				}						
		
			}
			
			
		
		}
		
		pilha.pop();
	
	}
	
	int xt=0;
	
	printf("os visitados foram: \n");
	for(xt=0; xt<VERTICES; xt++){
	
		printf("%d ", g[xt].visitado);
	
	
	}

return 0;
}
