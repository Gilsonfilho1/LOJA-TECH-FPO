#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITENS 100

struct Produto{
    int id;
    char nome[50];
    float precoUnitario;
    int quantidadeEstoque;
};

void Menu(){
    printf("*******************************\n");
    printf("*****    LOJA TECH FPO    *****\n");
    printf("*******************************\n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Listar Produtos\n");
    printf("3 - Relatorio Valor Total dos Produtos\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
}


int main(){
    
    struct Produto estoque[MAX_ITENS];
    int quantidadeAtual = 0;
    int opcao;
    
    do{
        Menu();
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
            Cadastrar(estoque, &quantidadeAtual);
            break;
            case 2:
            //Listar(estoque, quantidadeAtual);
            break;
            case 3:
            //Relatorio(estoque, quantidadeAtual);
            break;
            case 4:
            printf("Saindo do programa...\n");
            break;
            default:
            printf("Opcao invalida! Tente novamente.\n");
        }
        
    } while (opcao != 4);
    
    return 0;
}

void Cadastrar(struct Produto lista[], int *quantidadeAtual){
    if(*quantidadeAtual >= MAX_ITENS){
        printf("\nErro: Estoque cheio!\n");
        return;
    }

    printf("\n--- Cadastrar Produto ---\n");

    printf("Digite o ID: ");
    scanf("%d", &lista[*quantidadeAtual].id);
    getchar();

    printf("Digite o Nome: ");
    fgets(lista[*quantidadeAtual].nome, 50, stdin);
    lista[*quantidadeAtual].nome[strcspn(lista[*quantidadeAtual].nome, "\n")] = 0;

    do {
        printf("Digite o Preco Unitario: ");
        scanf("%f", &lista[*quantidadeAtual].precoUnitario);
        if(lista[*quantidadeAtual].precoUnitario < 0) printf("Preco invalido! \n");
    } while (lista[*quantidadeAtual].precoUnitario < 0);

    do {
        printf("Digite a Quantidade em Estoque: ");
        scanf("%d", &lista[*quantidadeAtual].quantidadeEstoque);
        if(lista[*quantidadeAtual].quantidadeEstoque < 0){
            printf("Quantidade invalida! \n");
        }
    } while (lista[*quantidadeAtual].quantidadeEstoque < 0);

    (*quantidadeAtual)++;
    printf("Produto cadastrado com sucesso!\n");


}