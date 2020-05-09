#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "com112_file.h"
bool abrirArquivoEntrada(int var[], int quantidade)
{
    FILE *arquivo;
    int i;
    arquivo = fopen("com112_entrada.txt", "wt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        return false;
    }
    else
    {

        fprintf(arquivo, "%d\n", quantidade);
        for (i = 0; i < quantidade; i++)
        {
            fprintf(arquivo, "%d ", var[i]);
        }

        fclose(arquivo);
        return true;
    }
}

bool abrirArquivoSaida(int var[], int quantidade)
{
    FILE *arquivo;
    int i;
    arquivo = fopen("com112_saida.txt", "wt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        return false;
    }
    else
    {

        fprintf(arquivo, "%d\n", quantidade);
        for (i = 1; i < quantidade + 1; i++)
        {
            fprintf(arquivo, "%d ", var[i]);
        }

        fclose(arquivo);
        return true;
    }
}

int *lerArquivoEntrada()
{
    FILE *arquivo;
    char *result;
    int *vet;
    arquivo = fopen("com112_entrada.txt", "rt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        fclose(arquivo);
        return NULL;
    }
    else
    {
        char linha[50];
        int cont = 0, quant, i;
        printf("Arquivo aberto com sucesso!\n");
        while (!feof(arquivo))
        {

            if (cont == 0)
            {
                fscanf(arquivo, "%d", &quant);
                cont++;
                vet = malloc((quant + 5) * sizeof(int));
                vet[0] = quant;
            }
            else
            {

                for (i = 1; i < (quant + 1); i++)
                {
                    fscanf(arquivo, "%d", &vet[i]);
                    //printf("%d ", vet[i]);
                }
            }
        }
        return vet;
        fclose(arquivo);
    }
}

bool escreverArquivoRelatorio(int var[])
{
    FILE *arquivo;
    int i;
    arquivo = fopen("com112_relatorio.txt", "wt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        return false;
    }
    else
    {
        int q = var[0];
        fprintf(arquivo,"                    ==================================================\n");
        fprintf(arquivo,"                    =      Numero de elementos ordenados: %d         =\n",var[0]);
        fprintf(arquivo,"                    =      Metodo Bubble Sort                        =\n");
        fprintf(arquivo,"                    =          Tempo de execucão: %f                 =\n",(var[q+4])/100000000.0);
        fprintf(arquivo,"                    =          Numero de comparacoes %d              =\n",var[q+1]);
        fprintf(arquivo,"                    =          Numero de movimentacoes: %d           =\n",var[q+2]);
        fprintf(arquivo,"                    =      Metodo Selection Sort                     =\n");
        fprintf(arquivo,"                    =          Tempo de execucão: 250s               =\n");
        fprintf(arquivo,"                    =          Numero de comparacoes 34              =\n");
        fprintf(arquivo,"                    =          Numero de movimentacoes: 55           =\n");
        fprintf(arquivo,"                    =      Metodo Insertion Sort                     =\n");
        fprintf(arquivo,"                    =          Tempo de execucão: 250s               =\n");
        fprintf(arquivo,"                    =          Numero de comparacoes 34              =\n");
        fprintf(arquivo,"                    =          Numero de movimentacoes: 55           =\n");
        fprintf(arquivo,"                    ==================================================\n");

        fclose(arquivo);
        return true;
    }
}

void lerArquivoRelatorio()
{
    FILE *arquivo;
    char *result;
    arquivo = fopen("com112_relatorio.txt", "rt");

    if (arquivo == NULL)
    {
        printf("ERRO AO ABRIR ARQUIVO!");
        fclose(arquivo);
        
    }
    else
    {
        char linha[50];
        
        printf("Arquivo aberto com sucesso!\n");
        while (!feof(arquivo))
        {
            fscanf(arquivo, "%c", &linha);
            printf("%s",linha);
        }
        
    }
    fclose(arquivo);
}