#include<stdbool.h>
#ifndef COM112_FILE_H
#define COM112_FILE_H

bool abrirArquivoEntrada(int var[],int quantidade);
int* lerArquivoEntrada();
bool abrirArquivoSaida(int var[],int quantidade);
bool escreverArquivoRelatorio(int var[]);
void lerArquivoRelatorio();

#endif