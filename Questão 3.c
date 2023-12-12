#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct produto
{
    char nome[200];
    float preco;
    int quantidadeEmEstoque;
};

float calcularValorTotal(struct produto mercadoria)
{
    return mercadoria.preco * mercadoria.quantidadeEmEstoque;
}

void realizarCompra(struct produto *mercadoria, int quantidade)
{
    if (quantidade <= mercadoria->quantidadeEmEstoque)
    {
        mercadoria->quantidadeEmEstoque -= quantidade;
        printf("\nCompra realizada com sucesso!\n");
    }
    else
    {
        printf("\nQuantidade inválida. A compra não foi realizada.\n\n");
    }
}

void consultarEstoque(struct produto mercadoria)
{
    printf("\nNome do produto: %s", mercadoria.nome);
    printf("\nPreço: R$ %.2f", mercadoria.preco);
    printf("\nQuantidade em estoque: %d", mercadoria.quantidadeEmEstoque);
    printf("\nValor total em estoque: R$ %.2f\n", calcularValorTotal(mercadoria));
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct produto mercadoria;
    int opcao;
    int quantidade;

    printf("Digite o nome do produto: ");
    gets(mercadoria.nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &mercadoria.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &mercadoria.quantidadeEmEstoque);

    system("CLS || CLEAR");

    do
    {

        printf("         OPÇÕES          \n");
        printf("1| Realizar uma compra  |\n");
        printf("2| Consultar estoque    |\n");
        printf("3| Sair do programa     |\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        system("CLS || CLEAR");
        
        switch (opcao)
        {
        case 1:
            printf("\nDigite a quantidade a ser comprada: ");
            scanf("%d", &quantidade);
            realizarCompra(&mercadoria, quantidade);
            break;
        case 2:
            consultarEstoque(mercadoria);
            break;
        case 3:
            printf("\nSaindo do programa.\n");
            break;
        default:
            printf("\nQuantidade no estoque insuficiente. Tente novamente.\n");
            break;
        }

    } while (opcao != 3);

    return 0;
}