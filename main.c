#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM_L 6
#define TAM_C 6



void percorrerTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC)
{

}

char PerguntarCasas(int *L, int *C, char tabLogico[TAM_L][TAM_C])
{
    printf("\nLinha: ");
    scanf("%i", L);

    printf("Coluna: ");
    scanf("%i", C);

    return tabLogico[*L][*C];
}

void solicitarDimensoesTabuleiro(int *pQtdL, int *pQtdC){

    printf("\nDigite a quantidade de linhas do seu tabuleiro: ");
    scanf("%i", pQtdL);

    printf("\nDigite a quantidade de colunas do seu tabuleiro: ");
    scanf("%i", pQtdC);

}

void preencherTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC){

    for(int l=0; l<*pQtdL; l++){
        for (int c=0; c<*pQtdC; c++){
            tab[l][c] = '-';
        }
    }

}

void construirTabuleiro(char tab[TAM_L][TAM_C], char tabLog[TAM_L][TAM_C], int *pQtdL, int *pQtdC){

    // Pedir para o usuário as dimensões de linha e de coluna
    solicitarDimensoesTabuleiro(pQtdL, pQtdC);

    // Preencher o tabuleiro
    preencherTabuleiro(tab, pQtdL, pQtdC);
    preencherTabuleiro(tabLog, pQtdL, pQtdC);
}

void visualizarTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC){

    for(int l=0; l<*pQtdL; l++){
        for (int c=0; c<*pQtdC; c++){
            printf("| %c |", tab[l][c]);
        }
        printf("\n");
    }
}

int main()
{
    char tabuleiro[TAM_L][TAM_C];
    char tabuleiroLogico[TAM_L][TAM_C];
    int qtdL, qtdC;
    int maxPontos = (qtdL + qtdC) / 2;
    maxPontos = 2;
    int pontos = 0;
    int L, C;
    int L1, C1;
    int L2, C2;
    char cartas ={'a','b','c','d','e','f','g'};
    construirTabuleiro(tabuleiro, tabuleiroLogico, &qtdL, &qtdC);
    visualizarTabuleiro(tabuleiro, &qtdL, &qtdC);

    srand = (time(NULL));

    for(int l = 0; l < qtdL; l++)
    {
        for(int c = 0; c < qtdC, c++)
        {
            int r = rand(sizeof(cartas)/sizeof(char));
            char aleatorio = cartas[r];
            tabuleiroLogico[l][c] = aleatorio;

        }

    }

    bool sair;
    sair = false;

    while(true)
    {
        char primeiraCarta = PerguntarCasas(&L, &C, tabuleiroLogico);
        tabuleiro[L][C] = primeiraCarta;
        L1 = L;
        C1 = C;
        visualizarTabuleiro(tabuleiro, &qtdL, &qtdC);
        char segundaCarta = PerguntarCasas(&L, &C, tabuleiroLogico);
        while(L == L1 && C == C1)
        {
            printf("Você já escolheu esta casa");
            char segundaCarta = PerguntarCasas(&L, &C, tabuleiroLogico);
        }
        tabuleiro[L][C] = segundaCarta;
        L2 = L;
        C2 = C;
        visualizarTabuleiro(tabuleiro, &qtdL, &qtdC);

    if(primeiraCarta == segundaCarta)
    {
        printf("\n\nACERTO MIZERAVI \n\n");
        pontos++;

    }
    else
    {
        printf("\n\nERROU, TIO\n\n");
        tabuleiro[L1][C1] = '-';
        tabuleiro[L2][C2] = '-';
    }

    visualizarTabuleiro(tabuleiro, &qtdL, &qtdC);

    }



    return 0;
}
