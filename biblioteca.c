//
// Created by Pedro Satoru on 24/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "biblioteca.h"



struct Cliente lista_clientes[100];
struct Extrato lista_extrato[100];

int quantidade_clientes = 0;
int quantidade_extrato = 0;


// Função para obter o tempo atual no formato de string
char* get_current_time() {
    time_t rawtime;
    struct tm* timeinfo;

    // Obter o tempo atual
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Formatar o tempo como uma string (AAA-MM-DD HH:MM:SS)
    static char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    return buffer;
}

void ler_clientes() {
    FILE *arquivo = fopen("clientes.dat", "rb"); // Abra o arquivo em modo binário de leitura.
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    quantidade_clientes = 0;  // Reinicialize a quantidade de clientes

    while (fread(&lista_clientes[quantidade_clientes], sizeof(struct Cliente), 1, arquivo) == 1) {
        quantidade_clientes++;
    }

    fclose(arquivo);
}

void salvar_clientes() {
    FILE *arquivo = fopen("clientes.dat", "wb"); // Abra o arquivo em modo binário de escrita.
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < quantidade_clientes; i++) {
        fwrite(&lista_clientes[i], sizeof(struct Cliente), 1, arquivo);
    }

    fclose(arquivo);
}

void ler_extrato() {
    FILE *arquivo = fopen("extrato.dat", "rb"); // Abra o arquivo de extrato em modo binário de leitura.
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de extrato.\n");
        exit(1);
    }

    quantidade_extrato = 0;  // Reinicialize a quantidade de extratos

    while (fread(&lista_extrato[quantidade_extrato], sizeof(struct Extrato), 1, arquivo) == 1) {
        quantidade_extrato++;
    }

    fclose(arquivo);
}

void salva_extrato() {
    FILE *arquivo = fopen("extrato.dat", "wb"); // Abra o arquivo de extrato em modo binário de escrita.
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de extrato.\n");
        exit(1);
    }

    for (int i = 0; i < quantidade_extrato; i++) {
        fwrite(&lista_extrato[i], sizeof(struct Extrato), 1, arquivo);
    }

    fclose(arquivo);
}

