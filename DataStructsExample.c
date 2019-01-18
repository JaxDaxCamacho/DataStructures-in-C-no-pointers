#include <stdio.h>
#include <string.h>

void my_scanf_long(char* s, int n){
	fgets(s, n, stdin);
	s[strlen(s)-1] = '\0';
};

typedef struct { char nome[50]; } autor;

typedef struct { char categoria[50]; } categoria;

typedef struct { 
	int numero;
	char titulo[50];
	categoria genero; 
	autor escritor; 
} livro;

void printcat(categoria x){
    printf("%s \n",x.categoria);
}

void printaut(autor x){
        printf("%s \n",x.nome);
}


void escrevelivros(livro x[],int y){
	int i;
	for(i=0; i<y ;i++){
		printf("Numero: %i\n", x[i].numero);
		printf("Titulo: %s\n", x[i].titulo);
		printcat(x[i].genero);
		printaut(x[i].escritor);
	};
		
}


void pesquisalivro(livro x[],int y,int pesq){
	int encontrado=0;
	int o;
	for(o=0; o<y;o++){
		if(x[o].numero==pesq){
			encontrado=1;
			printf("Livro Encontrado \n");
			printf("Numero: %i\n", x[o].numero);
			printf("Titulo: %s\n", x[o].titulo);
			printcat(x[o].genero);
			printaut(x[o].escritor);
		}
	}
	if(encontrado=0){
		printf("\n Nao encontrado");
	}
}

int main() {
	int numlivros,num,pesquisa,c,i,j,select;
	autor a;
	livro livros[5];
	categoria categorias[3];
	
	printf("Indique o nome do autor: \n");
	
	my_scanf_long(a.nome,50);
	getchar();
	for(c=0;c<3;c++){
		printf("Insira uma das categorias do livro:");
		
		my_scanf_long(categorias[c].categoria,50);
		
	};
	
	printf("Categorias guardadas. Quantos livros pretende registar: (max 5)\n");
	scanf("%i",&numlivros);
	printf("vamos registar os livros: \n");
	
		for(i=0;i<numlivros;i++){
				printf("insira o numero do livro:\n");
				scanf("%i",&num);
				livros[i].numero=num;
				printf("insira  o titulo do livro :\n");
				getchar();
				my_scanf_long(livros[i].titulo,50);

				printf("Listagem de Categorias \n");
					for(j=0;j<3;j++){
							printf("\n %i ->",j);
							printf("%s",categorias[j].categoria);
						};
				printf("\n Escolha a categoria 0-2 \n");
				scanf("%i",&num);
				select=num;
				livros[i].genero=categorias[select];
				livros[i].escritor=a;
				printf("categoria escolhida \n O autor deste livro e : %s  \n",a.nome);
				};
				
				escrevelivros(livros,numlivros);
				printf("Pesquisar um livro, Indique um numero: \n");
				scanf("%i",&pesquisa);
				pesquisalivro(livros,numlivros,pesquisa);
			
			return 0;
}
