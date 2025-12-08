#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100

// Mantive sua struct exatamente como você criou [cite: 14-18]
struct Produto {
    int Id;
    char Nome[50];
    float PrecoUnitario;
    int QuantidadeEstoque;
};

// Protótipos das funções (avisando ao C que elas existem)
void Cadastrar(struct Produto lista[], int *qtd);
void Listar(struct Produto lista[], int qtd);
void Relatorio(struct Produto lista[], int qtd);
void ExibirOpcoes();

int main() {
    // Declaração do Vetor (Array) e do contador no main [cite: 9, 12]
    struct Produto estoque[MAX_ITENS];
    int quantidadeAtual = 0;
    int opcao;

    // Loop repetitivo (do-while) exigido no PDF 
    do {
        ExibirOpcoes(); // Apenas mostra o texto
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado (o "Enter" que sobra)

        switch(opcao) {
            case 1:
                // Passamos o vetor e o endereço do contador (&) para poder modificá-lo
                Cadastrar(estoque, &quantidadeAtual);
                break;
            case 2:
                Listar(estoque, quantidadeAtual);
                break;
            case 3:
                Relatorio(estoque, quantidadeAtual);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

        if(opcao != 4) {
            printf("\nPressione Enter para continuar...");
            getchar(); // Pausa para o usuário ler
        }

    } while (opcao != 4);

    return 0;
}

// Função apenas para exibir o texto do menu (Interface)
void ExibirOpcoes() {
    // Tenta limpar a tela (funciona em Windows e Linux)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("*******************************\n");
    printf("***** LOJA TECH FPO    *****\n");
    printf("*******************************\n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Listar Produtos\n");
    printf("3 - Relatorio Valor Total dos Produtos\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
}

// 1. Lógica de Cadastro [cite: 21-23]
void Cadastrar(struct Produto lista[], int *qtd) {
    if (*qtd >= MAX_ITENS) {
        printf("\nErro: Estoque cheio!\n");
        return;
    }

    printf("\n--- Cadastrar Produto ---\n");
    
    printf("Digite o ID: ");
    scanf("%d", &lista[*qtd].Id);
    getchar(); // Limpar buffer

    printf("Digite o Nome: ");
    fgets(lista[*qtd].Nome, 50, stdin);
    // Remove o \n (enter) que o fgets captura no final
    lista[*qtd].Nome[strcspn(lista[*qtd].Nome, "\n")] = 0;

    // Validação de preço negativo 
    do {
        printf("Digite o Preco Unitario: ");
        scanf("%f", &lista[*qtd].PrecoUnitario);
        if(lista[*qtd].PrecoUnitario < 0) printf("Preco invalido! \n");
    } while (lista[*qtd].PrecoUnitario < 0);

    // Validação de quantidade negativa 
    do {
        printf("Digite a Quantidade em Estoque: ");
        scanf("%d", &lista[*qtd].QuantidadeEstoque);
        if(lista[*qtd].QuantidadeEstoque < 0) printf("Quantidade invalida! \n");
    } while (lista[*qtd].QuantidadeEstoque < 0);

    (*qtd)++; // Incrementa o contador total
    printf("Produto cadastrado com sucesso!\n");
}

// 2. Lógica de Listagem [cite: 24-25]
void Listar(struct Produto lista[], int qtd) {
    if (qtd == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Produtos ---\n");
    printf("ID   | Nome                 | Preco      | Qtd\n");
    printf("------------------------------------------------\n");
    for(int i = 0; i < qtd; i++) {
        printf("%-4d | %-20s | R$ %-6.2f | %d\n", 
            lista[i].Id, 
            lista[i].Nome, 
            lista[i].PrecoUnitario, 
            lista[i].QuantidadeEstoque);
    }
}

// 3. Lógica de Relatório Financeiro [cite: 27-30]
void Relatorio(struct Produto lista[], int qtd) {
    float total = 0;
    for(int i = 0; i < qtd; i++) {
        // Fórmula: Quantidade * Preço
        total += (lista[i].QuantidadeEstoque * lista[i].PrecoUnitario);
    }
    printf("\n--- Relatorio Financeiro ---\n");
    printf("Total de itens cadastrados: %d\n", qtd);
    printf("Valor Total do Estoque: R$ %.2f\n", total);
}