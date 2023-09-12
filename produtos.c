#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char nome[60];
    int codigo;
    int quantidade_estoque;
    int preco;
}produto;

typedef struct {
    int max;
    int n;
    produto *itens;
} t_lista;

t_lista* criarLista(int tam) {
    t_lista *lista = (t_lista *) malloc(sizeof(t_lista));
    lista->max = tam;
    lista->n = 0;
    lista->itens = (int *) malloc(sizeof(int) * tam);
    return lista;
}

int tamanho(t_lista *lista) {
    return lista->n;
}

int cheia(t_lista *lista) {
     
    if (lista->n == lista->max) {
        return 1;
    }
    return 0;
}

int vazia(t_lista *lista) {
    if (lista->n == 0) {
        return 1;
    }
    return 0;
}


int inserirIndice_Produto(t_lista *lista, int indice, produto p) {
    if (!cheia(lista) && (indice < lista->n)) {
        for (int i = lista->n - 1; i >= indice; i--) {
            lista->itens[i + 1] = lista->itens[i];
        }
        lista->itens[indice] = p;
        lista->n++;
        (*lista).n;
        return 1;
    }
    return 0;
}


int inserirProduto(t_lista *lista, produto p) {
    if (!cheia(lista)) {
        lista->itens[lista->n] = p;
        lista->n++;
        return 1;
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    int op1;
    t_lista *lista = criarLista(100); 
    do
	{
		printf("\nDigite 1 para cadastrar um produto\n");
		
		scanf("%d",&op1);
		fflush(stdin);
		
		switch(op1)
		{
			case 1:
			
				produto novoProduto;
                printf("Digite o nome do produto: ");
                scanf("%s", novoProduto.nome);
                printf("Digite o código do produto: ");
                scanf("%d", &novoProduto.codigo);
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &novoProduto.quantidade_estoque);
                printf("Digite o preço do produto: ");
                scanf("%d", &novoProduto.preco);

                if (inserirProduto(lista, novoProduto)) {
                    printf("Produto cadastrado com sucesso!\n");
                } else {
                    printf("A lista está cheia. Não foi possível cadastrar o produto.\n");
                }
                break;
			
			case 0:
				break;
			default: printf("Opção Inválida!\n");
		}
	}while(op1 >= 1 && op1 <=2);
}