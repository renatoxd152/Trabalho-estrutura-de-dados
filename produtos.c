#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct
{
    char nome[61];
    int codigo;
    int quantidade_estoque;
    float preco;
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
    lista->itens = (produto *) malloc(sizeof(produto) * tam); 
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

void listarProdutos() {
    FILE *arquivo = fopen("C:\\Users\\Projeto 6\\Documents\\Trabalho-estrutura-de-dados\\produtos.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("Produtos no arquivo:\n\n");

    produto p;
    while (fscanf(arquivo, "Nome:%s\nCódigo do produto:%d\nQuantidade no estoque:%d\nPreço do produto:%f\n",
                   p.nome, &p.codigo, &p.quantidade_estoque, &p.preco) != EOF) {
        printf("Nome: %s\nCódigo do produto: %d\nQuantidade no estoque: %d\nPreço do produto: %.2f\n\n",
               p.nome, p.codigo, p.quantidade_estoque, p.preco);
    }

    fclose(arquivo);
}


void listarProduto(t_lista *lista, int codigo)
{
    int indice = 0;
    if(!vazia(lista))
    {
        for(int i=0; i < lista->n;i++)
        {
            if(lista->itens[i].codigo == codigo)
            {
                printf("Nome:%sCódigo do produto:%d\nQuantidade no estoque:%d\nPreço do produto:%.2f\n",lista->itens[i].nome,lista->itens[i].codigo,lista->itens[i].quantidade_estoque,lista->itens[i].preco);
            }
            else
            {
                indice = 1;
            }   
        }
        if(indice)
        {
            printf("\nNão foi encontrado nenhum produto com esse código!\n");
        }

    }
    else
    {
        printf("\nA lista de produtos está vazia!");
    }
}

int atualizarProduto(t_lista *lista,int indice)
{
    
    printf("\nDigite o novo nome para o produto:");
    scanf(" %s",lista->itens[indice].nome);
    
    printf("\nDigite a nova quantidade para o estoque:");
    scanf("%d",&lista->itens[indice].quantidade_estoque);
   
    printf("\nDigite o novo preço para o produto:");
    scanf("%f",&lista->itens[indice].preco);
   

    printf("\nO produto foi atualizado com sucesso!");
    
}


int encontrarProduto(t_lista *lista, int codigo)
{
    if(!vazia(lista))
    {
        for(int i=0; i < lista->n;i++)
        {
            if(lista->itens[i].codigo == codigo)
            {
                return i;
            }   
        }
        return -1;
    }
    else
    {
        printf("\nA lista de produtos está vazia!\n");
    }
}
int encontrarCodigo(int codigo) {
    FILE *arquivo = fopen("C:\\Users\\Projeto 6\\Documents\\Trabalho-estrutura-de-dados\\produtos.txt", "r");

    if (arquivo == NULL) {
        return -1;
    }

    produto p;
    int linha = 0;

    while (fscanf(arquivo, "Nome:%s\nCódigo do produto:%d\nQuantidade no estoque:%d\nPreço do produto:%f\n",
                   p.nome, &p.codigo, &p.quantidade_estoque, &p.preco) != EOF) {
        linha++;

        if (p.codigo == codigo) {
            fclose(arquivo); 
            return linha; 
        }
    }

    fclose(arquivo); 

    return -1;
}


t_lista* copiarLista(t_lista *listaOriginal) {
    t_lista *novaLista = criarLista(listaOriginal->max);

    for (int i = 0; i < listaOriginal->n; i++) {
        inserirProduto(novaLista, listaOriginal->itens[i]);
    }

    return novaLista;
}


int ordernarQuantidade(t_lista *lista)
{
    t_lista *copiaLista = copiarLista(lista);
    produto aux;
    for(int i=0;i< copiaLista->n;i++)
    {
        for(int x= i+1; x < copiaLista->n;x++)
        {
            if(copiaLista->itens[i].quantidade_estoque > copiaLista->itens[x].quantidade_estoque)
            {
                aux = copiaLista->itens[i];
                copiaLista->itens[i] = copiaLista->itens[x];
                copiaLista->itens[x] = aux;
            }
        }
    }
    listarProdutos(copiaLista);

    free(copiaLista->itens);
    free(copiaLista);
}
float ordernarPreco(t_lista *lista)
{
    t_lista *copiaLista = copiarLista(lista);
    produto aux;
    for(int i=0;i< copiaLista->n;i++)
    {
        for(int x= i+1; x < copiaLista->n;x++)
        {
            if(copiaLista->itens[i].preco > copiaLista->itens[x].preco)
            {
                aux = copiaLista->itens[i];
                copiaLista->itens[i] = copiaLista->itens[x];
                copiaLista->itens[x] = aux;
            }
        }
    }
    listarProdutos(copiaLista);

    free(copiaLista->itens);
    free(copiaLista);
}
int ordernarCodigo(t_lista *lista)
{
    t_lista *copiaLista = copiarLista(lista);
    produto aux;
    for(int i=0;i< copiaLista->n;i++)
    {
        for(int x= i+1; x < copiaLista->n;x++)
        {
            if(copiaLista->itens[i].codigo > copiaLista->itens[x].codigo)
            {
                aux = copiaLista->itens[i];
                copiaLista->itens[i] = copiaLista->itens[x];
                copiaLista->itens[x] = aux;
            }
        }
    }

    listarProdutos(copiaLista);
    free(copiaLista->itens);
    free(copiaLista);
}
void produtosEstoqueBaixo(t_lista *lista,int quantidade)
{
    for(int i=0;i< lista->n;i++)
    {
        if(lista->itens[i].quantidade_estoque < quantidade)
        {
            printf("Nome:%sCódigo do produto:%d\nQuantidade no estoque:%d\nPreço do produto:%.2f\n",lista->itens[i].nome,lista->itens[i].codigo,lista->itens[i].quantidade_estoque,lista->itens[i].preco);
        }
    }
    }
void ordernarNome(t_lista *lista)
{
    t_lista *copiaLista = copiarLista(lista);
    produto aux;
    for(int i=0;i< copiaLista->n;i++)
    {
        for(int x= i+1; x < copiaLista->n;x++)
        {
            if(strcmp(copiaLista->itens[i].nome,copiaLista->itens[x].nome)>0)
            {
                aux = copiaLista->itens[i];
                copiaLista->itens[i] = copiaLista->itens[x];
                copiaLista->itens[x] = aux;
            }
        }
    }
    listarProdutos(copiaLista);

    free(copiaLista->itens);
    free(copiaLista);
}
int salvarListaEmArquivo(t_lista *lista) {
    FILE *arquivo = fopen("C:\\Users\\Projeto 6\\Documents\\Trabalho-estrutura-de-dados\\produtos.txt", "a");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    else
    {
        for (int i = 0; i < lista->n; i++) {
                fprintf(arquivo, "Nome:%s\nCódigo do produto:%d\nQuantidade no estoque:%d\nPreço do produto:%.2f\n",
                        lista->itens[i].nome, lista->itens[i].codigo, lista->itens[i].quantidade_estoque, lista->itens[i].preco);
                fprintf(arquivo, "\n");
            }

            fclose(arquivo);
            return 1;
    } 
}


int submenu(t_lista *lista)
{
    int op2,estoque;
    do
    {
        printf("\nDigite 1 para gerar um relatório de produtos ordenados pelo nome\n");
        printf("\nDigite 2 para gerar um relatório de produtos ordenados pelo código\n");
        printf("\nDigite 3 para gerar um relatório de produtos ordenados pela quantidade\n");
        printf("\nDigite 4 para gerar um relatório de produtos ordenados pela preço\n");
        printf("\nDigite 5 para gerar um relatório de produtos com estoque baixo\n");
        printf("\nDigite 0 para voltar para o menu principal\n");
        scanf("%d",&op2);
        switch (op2)
        {
            case 1:
                ordernarNome(lista);
                break;
            case 2:
                ordernarCodigo(lista);
                break;
            case 3:
                ordernarQuantidade(lista);
                break;
            case 4:
                ordernarPreco(lista);
            case 5:
                printf("\nDigite o valor de estoque que é considerado baixo:");
                scanf("%d",&estoque);
                produtosEstoqueBaixo(lista,estoque);
                break;
            
            default:
                break;
        }
    } while (op2 != 0);
    
}

int main(int argc, char const *argv[])
{
    int op1,cod,indice;
    t_lista *lista = criarLista(100); 
    produto novoProduto;
    do
    {
        printf("\nDigite 1 para cadastrar um produto\n");
        printf("\nDigite 2 para remover um produto\n");
        printf("\nDigite 3 para listar os produtos\n");
        printf("\nDigite 4 para consultar informações de um produto!\n");
        printf("\nDigite 5 para atualizar um produto\n");
        printf("\nDigite 6 para acessar o submenu de relatórios\n");
        printf("\nDigite 0 para sair\n");
        scanf("%d", &op1);
       
        switch(op1)
        {
            case 1:
                printf("Digite o nome do produto: ");
                getchar();
                fgets(novoProduto.nome,50,stdin);
                novoProduto.nome[strcspn(novoProduto.nome, "\n")] = '\0';

                
                printf("Digite o código do produto: ");
                scanf("%d", &novoProduto.codigo);
                getchar();
                
                printf("Digite a quantidade em estoque: ");
                scanf("%d", &novoProduto.quantidade_estoque);
                getchar();
                
                printf("Digite o preço do produto: ");
                scanf("%f", &novoProduto.preco);
                getchar();
               
                if(encontrarCodigo(novoProduto.codigo) != -1)
                {
                    printf("\nNão é possível cadastrar o mesmo produto no sistema!");
                    break;
                }
                else
                {
                    if (inserirProduto(lista, novoProduto)) 
                    {
                        printf("Produto cadastrado com sucesso!\n");
                        int retorno = salvarListaEmArquivo(lista);
                        if(retorno == 1)
                        {
                            printf("\nOs dados foram gravados com sucesso!");
                        }
                        break;
                    } else 
                    {
                        printf("A lista está cheia. Não foi possível cadastrar o produto.\n");
                        break;
                    }
                }
                
                
            case 2:
                printf("Digite o código do produto:");
                scanf("%d",&cod);
                removerProduto(lista,cod);
                break;
            case 3:
                listarProdutos(lista);
                break;
            case 4:
                printf("\nDigite o código para listar um produto:");
                scanf("%d",&cod);
                listarProduto(lista,cod);
                break;
            case 5:
                printf("\nDigite o codigo do produto que deseja atualizar:");
                scanf("%d",&cod);
                indice = encontrarProduto(lista,cod);
                
                
                if(indice != -1)
                {
                    atualizarProduto(lista,indice);
                    break;
                }
                else
                {
                    printf("\nNão foi encontrado nenhum produto com esse código!");
                    break;
                }
            case 6:
                submenu(lista);
                break;
            case 0:
                break;
        }
    }while(op1 != 0);
    
}
