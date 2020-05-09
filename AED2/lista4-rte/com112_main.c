#include <stdio.h>
#include <stdlib.h>
#include "com112_file.h"
#include "com112_sort.h"
#include <stdbool.h>
#include <time.h>

void waiter()
{
    char str[50];
    while (1)
    {
        printf("\n\nDigite qualquer tecla e pressione enter para continuar!\n\n");
        scanf("%s", str);
        break;
    }
}

int *menu(int vet[])
{
    int op, tempo1, tempo2;
    while ((op != 1) && (op != 2) && (op != 3))
    {
        printf("\e[H\e[2J");
        printf("\n\n\n\n\n");
        printf("                    ==========Metodos de ordenacao==========\n");
        printf("                    =         1 - Bubble Sort              =\n");
        printf("                    =         2 - Selection Sort           =\n");
        printf("                    =         3 - Insertion Sort           =\n");
        printf("                    ========================================\n");
        printf("\n");

        printf("              Entre com a opcao desejada (Digite o numero da opcao): ");
        scanf("%d", &op);
        int *v;
        if (op == 1)
        {
            tempo1 = clock();
            v = bubbleSort(vet);
            tempo2 = clock();
            int quantidade = v[0];
            v[quantidade + 7] = ("%f", (tempo2 - tempo1) / 1000.0) * 100000000;
            printf("\nVetor ordenado através do BubbleSort!\n");
            return v;
        }
        else if (op == 2)
        {
            tempo1 = clock();
            v = selectionSort(vet);
            tempo2 = clock();
            printf("\nVetor ordenado através do SelectionSort!\n");
            int quantidade = v[0];
            v[quantidade + 8] = ("%f", (tempo2 - tempo1) / 1000.0) * 100000000;
            return v;
        }
        else if (op == 3)
        {
            tempo1 = clock();
            v = insertionSort(vet);
            tempo2 = clock();
            printf("\nVetor ordenado através do InsertionSort!\n");
            int quantidade = v[0];
            v[quantidade + 9] = ("%f", (tempo2 - tempo1) / 1000.0) * 100000000;
            return v;
        }
    }
}

void relatorio()
{
    printf("\e[H\e[2J");
    printf("\n\n\n");
    printf("                    ==================================================\n");
    printf("                    =      Numero de elementos ordenados: 34         =\n");
    printf("                    =      Metodo Bubble Sort                        =\n");
    printf("                    =          Tempo de execucão: 250s               =\n");
    printf("                    =          Numero de comparacoes 34              =\n");
    printf("                    =          Numero de movimentacoes: 55           =\n");
    printf("                    =      Metodo Selection Sort                     =\n");
    printf("                    =          Tempo de execucão: 250s               =\n");
    printf("                    =          Numero de comparacoes 34              =\n");
    printf("                    =          Numero de movimentacoes: 55           =\n");
    printf("                    =      Metodo Insertion Sort                     =\n");
    printf("                    =          Tempo de execucão: 250s               =\n");
    printf("                    =          Numero de comparacoes 34              =\n");
    printf("                    =          Numero de movimentacoes: 55           =\n");
    printf("                    ==================================================\n");
    char a;
    printf("Para sair aperte qualquer tecla.\n");
    scanf("%c", &a);
}

int main()
{
    int op, i;
    int *vetor;
    int cont = 0;
    while (op != 4)
    {
        printf("\e[H\e[2J");
        printf("\n\n\n\n\n");
        printf("                    ==========Metodos de ordenacao==========\n");
        printf("                    =                                      =\n");
        printf("                    =                                      =\n");
        printf("                    =         1 - Metodos de Ordenacao     =\n");
        printf("                    =         2 - Relatorio                =\n");
        printf("                    =         3 - Gerar Numeros            =\n");
        printf("                    =         4 - Sair                     =\n");
        printf("                    =         5 - Creditos                 =\n");
        printf("                    =                                      =\n");
        printf("                    ========================================\n");
        printf("\n");

        printf("              Entre com a opcao desejada (Digite o numero da opcao): ");
        scanf("%d", &op);

        if (op == 1)
        {

            if (cont == 0)
            {
                vetor = lerArquivoEntrada();
                cont++;
            }
            int *result;
            result = menu(vetor);
            bool result_of_archive = abrirArquivoSaida(result, result[0]);
            for (i = 1; i < result[0] + 1; i++)
            {
                printf("%d ", result[i]);
            }
            printf("\n\n");
            if (result_of_archive)
            {
                printf("Arquivo de saida criado com sucesso!\n");
            }
            else
            {
                printf("Erro ao criar arquivo de saida!\n");
            }

            result_of_archive = escreverArquivoRelatorio(result);

            waiter();
        }
        else if (op == 2)
        {
            lerArquivoRelatorio();

            waiter();
        }
        else if (op == 3)
        {
            int quantidade, i;
            int *vet;
            bool result_of_archive;
            printf("\e[H\e[2J");
            printf("Entre com a quantidade de numeros a serem gerados: ");
            scanf("%d", &quantidade);

            vet = malloc(quantidade * sizeof(vet));

            for (i = 0; i < quantidade; i++)
            {
                vet[i] = rand() % 1000;
            }

            printf("Numeros gerados de forma aleatoria:\n");

            for (i = 0; i < quantidade; i++)
            {
                printf("%d ", vet[i]);
            }
            printf("\n");

            result_of_archive = abrirArquivoEntrada(vet, quantidade);

            if (result_of_archive)
            {
                printf("Arquivo criado com sucesso!");
            }
            else
            {
                printf("Erro ao criar arquivo!");
            }

            waiter();
            free(vet);
        }
        else if (op == 5)
        {
            printf("\e[H\e[2J");
            printf("                    ==========Creditos======================\n");
            printf("                    =                                      =\n");
            printf("                    =                                      =\n");
            printf("                    =         Marcelo Magalhaes Silva      =\n");
            printf("                    =         2020004243                   =\n");
            printf("                    =         COM112                       =\n");
            printf("                    ========================================\n");
            waiter();
        }
    }

    return 0;
}