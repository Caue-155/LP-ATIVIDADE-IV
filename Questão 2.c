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

void situacaoAluno(struct alunos aluno)
{
    if (aluno.media >= 7)
    {
        printf("\n%s:Aprovado!", aluno.nome);
    }
    if (aluno.media < 7)
    {
        printf("\n%s:Reprovado!", aluno.nome);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int a, b;
    struct alunos aluno[5];

    for (a = 0; a < 5; a++)
    {
        printf("Digite o nome do %dº aluno:", a + 1);
        gets(aluno[a].nome);

        fflush(stdin);

        printf("Digite a data de nascimento do aluno:");
        gets(aluno[a].dataDeNascimento);

        fflush(stdin);

        printf("Digite a 1º nota do aluno:");
        scanf("%f", &aluno[a].primeiraNota);

        printf("Digite a 2º nota do aluno:");
        scanf("%f", &aluno[a].segundaNota);

        aluno[a].media = calcularMedia(aluno[a]);

        fflush(stdin);
    }

    fflush(stdin);
    system("CLS || CLEAR");

    for (a = 0; a < 5; a++)
    {
        printf("\n\nNome do %dº aluno:%s", a + 1, aluno[a].nome);

        printf("\nData de nascimento do aluno:%s", aluno[a].dataDeNascimento);

        printf("\nMédia do aluno:%.2f\n", aluno[a].media);

        situacaoAluno(aluno[a]);
    }
    return 0;
}