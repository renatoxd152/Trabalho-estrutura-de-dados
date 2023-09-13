#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct
{
    char nome[61];
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

int removerProduto(t_lista *lista, int codigo) {
    if (!vazia(lista)) {
        int indice = -1; 
        
        for (int i = 0; i < lista->n; i++) {
            if (lista->itens[i].codigo == codigo) {
                indice = i; 
                break;
            }
        }
        
        if (indice != -1) { 
            
            for (int i = indice; i < lista->n - 1; i++) {
                lista->itens[i] = lista->itens[i + 1];
            }
            lista->n--; 
            printf("Produto com código %d removido com sucesso!.\n", codigo);
        } else {
            printf("Produto com código %d não encontrado na lista.\n", codigo);
        }
    } else {
        printf("A lista está vazia. Não é possível remover produtos.\n");
    }
}



int main(int argc, char const *argv[])
{
    int op1;
    t_lista *lista = criarLista(100); 
    do
    {
        printf("\nDigite 1 para cadastrar um produto\n");
        printf("\nDigite 2 para remover um produto\n");
        printf("\nDigite 3 para atualizar um produto\n");
        printf("\nDigite 4 para consultar informações de um produto\n");
        printf("\nDigite 0 para sair\n");
        scanf("%d", &op1);
       
        switch(op1)
        {
            case 1:
                produto novoProduto;
                
                
                printf("Digite o nome do produto: ");
                getchar();
                fgets(novoProduto.nome,50,stdin);
                
                
                printf("Digite o código do produto: ");
                scanf("%d", &novoProduto.codigo);
                getchar();
                
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &novoProduto.quantidade_estoque);
                getchar();
                
                printf("Digite o preço do produto: ");
                scanf("%d", &novoProduto.preco);
                getchar();
                
                if (inserirProduto(lista, novoProduto)) {
                    printf("Produto cadastrado com sucesso!\n");
                } else {
                    printf("A lista está cheia. Não foi possível cadastrar o produto.\n");
                }
                break;
            case 2:
                int cod;
                printf("Digite o código do produto:");
                scanf("%d",&cod);
                removerProduto(lista,cod);
                break;
            case 0:
                break;
        }
    }while(op1 >= 1 && op1 <= 2);
    
}
