#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct alunos
{
    char nome[222];
    char dataDeNascimento[222];
    float primeiraNota;
    float segundaNota;
    float media;
};

int calcularMedia(struct alunos aluno)
{
    return (aluno.primeiraNota + aluno.segundaNota) / 2;
}

void situacaoAluno(struct alunos aluno[])
{
    int a;
    for (a = 0; a < 1; a++)
    {
        if (aluno[a].media >= 7)
        {
            printf("\nSituação: Aprovado!");
        }
        else
        {
            printf("\nSituação: Reprovado!");
        }
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int a, b;
    struct alunos aluno[2];
    float somaTotal;

    for (a = 0; a < 2; a++)
    {
        printf("Digite o nome do %dº aluno:", a + 1);
        gets(aluno[a].nome);

        fflush(stdin);

        printf("Digite a data de nascimento do aluno:");
        gets(aluno[a].dataDeNascimento);

        fflush(stdin);

        for (b = 0; b < 1; b++)
        {
            printf("Digite a 1º nota do aluno:");
            scanf("%f", &aluno[a].primeiraNota);

            printf("Digite a 2º nota do aluno:");
            scanf("%f", &aluno[a].segundaNota);
        }

        fflush(stdin);
    }

    fflush(stdin);
    system("CLS || CLEAR");

    for (a = 0; a < 2; a++)
    {
        printf("\n\nNome do %dº aluno:%s", a + 1, aluno[a].nome);

        printf("\nData de nascimento do aluno:%s", aluno[a].dataDeNascimento);

        printf("\nMédia do aluno:%.2f\n", calcularMedia);

        situacaoAluno(aluno);
    }
    return 0;
}