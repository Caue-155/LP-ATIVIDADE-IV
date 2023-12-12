#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Produto
{
    char nome[200];
    float preco;
    int quantidadeEstoque;
};

float calcularValorTotal(struct Produto produto)
{
    return produto.preco * produto.quantidadeEstoque;
}

void realizarCompra(struct Produto *produto, int quantidade)
{
    if (quantidade <= produto->quantidadeEstoque)
    {
        produto->quantidadeEstoque - quantidade;
        printf("\nCompra realizada com sucesso!\n");
    }
    else
    {
        printf("\nQuantidade inv�lida. A compra n�o foi realizada.\n\n");
    }
}

void consultarEstoque(struct Produto produto)
{
    printf("\nNome do produto: %s", produto.nome);
    printf("\nPre�o: R$ %.2f", produto.preco);
    printf("\nQuantidade em estoque: %d", produto.quantidadeEstoque);
    printf("\nValor total em estoque: R$ %.2f\n", calcularValorTotal(produto));
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct Produto produto;
    int opcao;
    int quantidade;

    printf("Digite o nome do produto: ");
    gets(produto.nome);

    printf("Digite o pre�o do produto: ");
    scanf("%f", &produto.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto.quantidadeEstoque);

    system("CLS || CLEAR");

    do
    {

        printf("            OP��ES                  \n");
        printf("1| Realizar compra                   |\n");
        printf("2| Consultar a quantidade no estoque |\n");
        printf("3| Sair do programa                  |\n");
        printf("\nEscolha uma op��o: ");
        scanf("%d", &opcao);

        system("CLS || CLEAR");
        
        switch (opcao)
        {
        case 1:
            printf("\nDigite a quantidade a ser comprada: ");
            scanf("%d", &quantidade);
            realizarCompra(&produto, quantidade);
            break;
        case 2:
            consultarEstoque(produto);
            break;
        case 3:
            printf("\nSaindo do programa.\n");
            break;
        default:
            printf("\nOp��o inv�lida. Tente novamente.\n");
            break;
        }

    } while (opcao != 3);

    return 0;
}