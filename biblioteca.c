//
// Created by Pedro Satoru on 24/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "biblioteca.h"


///////////////////IMPORTANTE///////////////


//Criar as listas "clientes.dat" e "extrato.dat", possivel que não se crie ao iniciar pela primeira vez o codigo e ocorra um erro



///////////////////IMPORTANTE///////////////


void ler_clientes(struct Cliente* lista_clientes, int* quantidade_clientes) {
    FILE *arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    *quantidade_clientes = 0;

    while (fread(&lista_clientes[*quantidade_clientes], sizeof(struct Cliente), 1, arquivo) == 1) {
        (*quantidade_clientes)++;
    }

    fclose(arquivo);
}

void salvar_clientes(struct Cliente* lista_clientes, int quantidade_clientes) {
    FILE *arquivo = fopen("clientes.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < quantidade_clientes; i++) {
        fwrite(&lista_clientes[i], sizeof(struct Cliente), 1, arquivo);
    }

    fclose(arquivo);
}

void ler_extrato(struct Extrato* lista_extrato, int* quantidade_extrato) {
    FILE *arquivo = fopen("extrato.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de extrato.\n");
        exit(1);
    }

    *quantidade_extrato = 0;

    while (fread(&lista_extrato[*quantidade_extrato], sizeof(struct Extrato), 1, arquivo) == 1) {
        (*quantidade_extrato)++;
    }

    fclose(arquivo);
}

void salva_extrato(struct Extrato* lista_extrato, int quantidade_extrato) {
    FILE *arquivo = fopen("extrato.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de extrato.\n");
        exit(1);
    }

    for (int i = 0; i < quantidade_extrato; i++) {
        fwrite(&lista_extrato[i], sizeof(struct Extrato), 1, arquivo);
    }

    fclose(arquivo);
}
void NovoCliente(struct Cliente* lista_clientes, int* quantidade_clientes, struct Extrato* lista_extrato, int* quantidade_extrato) {
    ler_clientes(lista_clientes, quantidade_clientes);

    char nome[100];
    char cpf[15];
    char tipo_conta[50];
    double saldo;
    char senha[20];
    int cliente_encontrado = 0;

    printf("Nome do cliente: ");
    scanf("%s", nome);
    printf("CPF do cliente: ");
    scanf("%s", cpf);
    printf("Tipo de conta (comum ou plus): ");
    scanf("%s", tipo_conta);
    printf("Saldo inicial da conta: ");
    scanf("%lf", &saldo);
    printf("Senha do cliente: ");
    scanf("%s", senha);

    for (int i = 0; i < *quantidade_clientes; i++) {
        if (strcmp(lista_clientes[i].cpf, cpf) == 0) {
            cliente_encontrado = 1;
            printf("Cliente ja existe\n");
            break;
        }
    }

    if (!cliente_encontrado) {
        strcpy(lista_clientes[*quantidade_clientes].nome, nome);
        strcpy(lista_clientes[*quantidade_clientes].cpf, cpf);
        strcpy(lista_clientes[*quantidade_clientes].tipo_conta, tipo_conta);
        lista_clientes[*quantidade_clientes].saldo = saldo;
        strcpy(lista_clientes[*quantidade_clientes].senha, senha);
        (*quantidade_clientes)++;

        // Adicionar um registro de extrato vazio para o novo cliente
        strcpy(lista_extrato[*quantidade_extrato].nome, nome);
        strcpy(lista_extrato[*quantidade_extrato].cpf, cpf);
        strcpy(lista_extrato[*quantidade_extrato].tipo_conta, tipo_conta);
        strcpy(lista_extrato[*quantidade_extrato].extrato, "");
        (*quantidade_extrato)++;

        salvar_clientes(lista_clientes, *quantidade_clientes);
        salva_extrato(lista_extrato, *quantidade_extrato);
        printf("Cliente novo cadastrado com sucesso\n");
    }
    printf("%d", *quantidade_clientes);
}


void ApagaCliente(struct Cliente* lista_clientes, int* quantidade_clientes, struct Extrato* lista_extrato, int* quantidade_extrato) {
    ler_clientes(lista_clientes, quantidade_clientes);
    ler_extrato(lista_extrato, quantidade_extrato);

    char cpf[15];
    int cliente_encontrado = 0;

    printf("Digite o CPF do cliente a ser apagado: ");
    scanf("%s", cpf);

    for (int i = 0; i < *quantidade_clientes; i++) {
        if (strcmp(lista_clientes[i].cpf, cpf) == 0) {
            cliente_encontrado = 1;

            // Remove o cliente da lista de clientes
            for (int j = i; j < *quantidade_clientes - 1; j++) {
                strcpy(lista_clientes[j].nome, lista_clientes[j + 1].nome);
                strcpy(lista_clientes[j].cpf, lista_clientes[j + 1].cpf);
                strcpy(lista_clientes[j].tipo_conta, lista_clientes[j + 1].tipo_conta);
                lista_clientes[j].saldo = lista_clientes[j + 1].saldo;
                strcpy(lista_clientes[j].senha, lista_clientes[j + 1].senha);
            }
            (*quantidade_clientes)--;

            // Remove os registros do extrato associados ao cliente
            for (int j = 0; j < *quantidade_extrato; j++) {
                if (strcmp(lista_extrato[j].cpf, cpf) == 0) {
                    for (int k = j; k < *quantidade_extrato - 1; k++) {
                        strcpy(lista_extrato[k].nome, lista_extrato[k + 1].nome);
                        strcpy(lista_extrato[k].cpf, lista_extrato[k + 1].cpf);
                        strcpy(lista_extrato[k].tipo_conta, lista_extrato[k + 1].tipo_conta);
                        strcpy(lista_extrato[k].extrato, lista_extrato[k + 1].extrato);
                    }
                    (*quantidade_extrato)--;
                    j--;  // Revisar a posição após a remoção
                }
            }

            printf("Cliente foi excluído\n");
            salvar_clientes(lista_clientes, *quantidade_clientes);
            salva_extrato(lista_extrato, *quantidade_extrato);
            break;
        }
    }

    if (!cliente_encontrado) {
        printf("Cliente nao encontrado\n");
    }
}


void ListarClientes(struct Cliente* lista_clientes, int quantidade_clientes) {
    ler_clientes(lista_clientes, &quantidade_clientes);

    for (int i = 0; i < quantidade_clientes; i++) {
        printf("Nome: %s\n", lista_clientes[i].nome);
        printf("CPF: %s\n", lista_clientes[i].cpf);
        printf("Tipo de conta: %s\n", lista_clientes[i].tipo_conta);
        printf("Saldo: %.2lf\n", lista_clientes[i].saldo);
        printf("\n");
    }
}


void Debito(struct Cliente* lista_clientes, int quantidade_clientes, struct Extrato* lista_extrato, int quantidade_extrato) {
    ler_clientes(lista_clientes, &quantidade_clientes);
    ler_extrato(lista_extrato, &quantidade_extrato);

    char cpf[15];
    char senha[20];
    double valor;

    printf("Digite seu CPF: ");
    scanf("%s", cpf);
    printf("Digite sua senha: ");
    scanf("%s", senha);
    printf("Digite o valor a ser debitado: ");
    scanf("%lf", &valor);

    int cliente_encontrado = 0;
    int indice_cliente = -1;
    int indice_extrato = -1;

    // Encontrar o cliente e o respectivo índice
    for (int i = 0; i < quantidade_clientes; i++) {
        if (strcmp(lista_clientes[i].cpf, cpf) == 0 && strcmp(lista_clientes[i].senha, senha) == 0) {
            cliente_encontrado = 1;
            indice_cliente = i;

            // Encontrar o índice correspondente no extrato
            for (int j = 0; j < quantidade_extrato; j++) {
                if (strcmp(lista_extrato[j].cpf, cpf) == 0) {
                    indice_extrato = j;
                    break;
                }
            }

            break;
        }
    }

    if (cliente_encontrado) {
        if (strcmp(lista_clientes[indice_cliente].tipo_conta, "plus") == 0) {
            double taxa = valor * 0.03;
            if (lista_clientes[indice_cliente].saldo - valor - taxa >= -5000.0) {
                lista_clientes[indice_cliente].saldo -= valor + taxa;
                printf("Valor debitado com sucesso\n");

                if (indice_extrato != -1) {
                    // Registrar a transação no extrato do cliente
                    char transacao[100];
                    snprintf(transacao, sizeof(transacao), "Debito: %.2lf (Tarifa: %.2lf) Saldo: %.2lf\n", valor, taxa, lista_clientes[indice_cliente].saldo);
                    strcat(lista_extrato[indice_extrato].extrato, transacao);
                    // Salvar o extrato atualizado
                    salva_extrato(lista_extrato, quantidade_extrato);
                } else {
                    // Caso não encontre o índice no extrato
                    printf("Erro ao encontrar o índice do extrato para o cliente.\n");
                }
                // Salvar os clientes atualizados
                salvar_clientes(lista_clientes, quantidade_clientes);
            } else {
                printf("Saldo insuficiente (limite de crédito excedido)\n");
            }
        } else if (strcmp(lista_clientes[indice_cliente].tipo_conta, "comum") == 0) {
            double taxa = valor * 0.05;
            if (lista_clientes[indice_cliente].saldo - valor - taxa >= -1000.0) {
                lista_clientes[indice_cliente].saldo -= valor + taxa;
                printf("Valor debitado com sucesso\n");

                if (indice_extrato != -1) {
                    // Registra a transação no extrato do cliente
                    char transacao[100];
                    snprintf(transacao, sizeof(transacao), " Debito: %.2lf (Tarifa: %.2lf) Saldo: %.2lf\n", valor, taxa, lista_clientes[indice_cliente].saldo);
                    strcat(lista_extrato[indice_extrato].extrato, transacao);
                    // Salva o extrato atualizado
                    salva_extrato(lista_extrato, quantidade_extrato);
                } else {
                    // Caso não encontre o índice no extrato
                    printf("Erro ao encontrar o indice do extrato para o cliente.\n");
                }
                // Salvar os clientes atualizados
                salvar_clientes(lista_clientes, quantidade_clientes);
            } else {
                printf("Saldo insuficiente (limite de credito excedido)\n");
            }
        } else {
            printf("Tipo de conta invalido\n");
        }
    } else {
        printf("Senha ou CPF incorretos ou cliente não encontrado\n");
    }
}

void Deposito(struct Cliente* lista_clientes, int quantidade_clientes, struct Extrato* lista_extrato, int quantidade_extrato) {
    ler_clientes(lista_clientes, &quantidade_clientes);
    ler_extrato(lista_extrato, &quantidade_extrato);

    char cpf[15];
    char senha[20];
    double valor;

    printf("Digite seu CPF: ");
    scanf("%s", cpf);
    printf("Digite sua senha: ");
    scanf("%s", senha);
    printf("Digite o valor a ser depositado: ");
    scanf("%lf", &valor);

    int cliente_encontrado = 0;
    int indice_cliente = -1;
    int indice_extrato = -1;

    for (int i = 0; i < quantidade_clientes; i++) {
        if (strcmp(lista_clientes[i].cpf, cpf) == 0 && strcmp(lista_clientes[i].senha, senha) == 0) {
            cliente_encontrado = 1;
            indice_cliente = i;

            for (int j = 0; j < quantidade_extrato; j++) {
                if (strcmp(lista_extrato[j].cpf, cpf) == 0) {
                    indice_extrato = j;
                    break;
                }
            }

            break;
        }
    }

    if (cliente_encontrado) {
        lista_clientes[indice_cliente].saldo += valor;
        printf("Valor depositado com sucesso\n");

        if (indice_extrato != -1) {
            // Registrar a transação no extrato do cliente
            char transacao[100];
            snprintf(transacao, sizeof(transacao), "Deposito: %.2lf, Saldo: %.2lf\n",valor, lista_clientes[indice_cliente].saldo);
            strcat(lista_extrato[indice_extrato].extrato, transacao);
            // Salvar o extrato atualizado
            salva_extrato(lista_extrato, quantidade_extrato);
            // Salvar os clientes atualizados
            salvar_clientes(lista_clientes, quantidade_clientes);
        } else {
            // Caso não encontre o índice no extrato
            printf("Erro ao encontrar o índice do extrato para o cliente.\n");
        }
    } else {
        printf("Senha ou CPF incorretos ou cliente nao encontrado\n");
    }
}

void Extrato(struct Cliente* lista_clientes, int quantidade_clientes, struct Extrato* lista_extrato, int quantidade_extrato) {
    char cpf[15];
    char senha[20];

    printf("Digite seu CPF: ");
    scanf("%s", cpf);
    printf("Digite sua senha: ");
    scanf("%s", senha);

    for (int i = 0; i < quantidade_clientes; i++) {
        if (strcmp(lista_clientes[i].cpf, cpf) == 0 && strcmp(lista_clientes[i].senha, senha) == 0) {
            printf("Nome: %s\n", lista_extrato[i].nome);
            printf("Tipo da conta: %s\n", lista_extrato[i].tipo_conta);

            // Imprimir o extrato linha por linha
            char* token = strtok(lista_extrato[i].extrato, "!");
            while (token != NULL) {
                printf("%s\n", token);
                token = strtok(NULL, "!");
            }

            printf("\n");
            return;
        }
    }

    printf("Senha ou CPF incorretos\n");
}

void TransferenciaEntreContas(struct Cliente* lista_clientes, int quantidade_clientes, struct Extrato* lista_extrato, int quantidade_extrato) {
    ler_clientes(lista_clientes, &quantidade_clientes);
    ler_extrato(lista_extrato, &quantidade_extrato);

    char cpf_origem[15];
    char senha_origem[20];
    char cpf_destino[15];
    double valor;

    printf("Digite seu CPF: ");
    scanf("%s", cpf_origem);
    printf("Digite sua senha: ");
    scanf("%s", senha_origem);
    printf("Digite o CPF do destinatario: ");
    scanf("%s", cpf_destino);
    printf("Digite o valor a ser transferido: ");
    scanf("%lf", &valor);

    int origem_encontrado = 0;
    int destino_encontrado = 0;
    int origem_index = -1;
    int destino_index = -1;

    // Encontrar o cliente de origem e o cliente de destino na lista de clientes
    for (int i = 0; i < quantidade_clientes; i++) {
        if (strcmp(lista_clientes[i].cpf, cpf_origem) == 0 && strcmp(lista_clientes[i].senha, senha_origem) == 0) {
            origem_encontrado = 1;
            origem_index = i;
        }
        if (strcmp(lista_clientes[i].cpf, cpf_destino) == 0) {
            destino_encontrado = 1;
            destino_index = i;
        }
    }

    if (!origem_encontrado) {
        printf("Cliente de origem nao encontrado ou senha incorreta.\n");
    } else if (!destino_encontrado) {
        printf("Cliente de destino nao encontrado.\n");
    } else {
        double taxa = 0.03 * valor;
        double saldo_origem = lista_clientes[origem_index].saldo;
        if (strcmp(lista_clientes[origem_index].tipo_conta, "plus") == 0) {
            if (saldo_origem - valor - taxa >= -5000.0) {
                lista_clientes[origem_index].saldo = saldo_origem - valor - taxa;
                lista_clientes[destino_index].saldo += valor;
                printf("Transferencia realizada com sucesso.\n");

                // Registrar as transações no extrato de origem e destino
                char transacao[100];
                snprintf(transacao, sizeof(transacao), "Transferência para %s (Valor: %.2lf, Tarifa: %.2lf, Saldo: %.2lf)\n", lista_clientes[destino_index].nome, valor, taxa, lista_clientes[origem_index].saldo);
                strcat(lista_extrato[origem_index].extrato, transacao);
                snprintf(transacao, sizeof(transacao), "Transferência de %s (Valor: %.2lf, Saldo: %.2lf)\n",lista_clientes[origem_index].nome, valor, lista_clientes[destino_index].saldo);
                strcat(lista_extrato[destino_index].extrato, transacao);
                salva_extrato(lista_extrato, quantidade_extrato);
                salvar_clientes(lista_clientes, quantidade_clientes);
            } else {
                printf("Saldo insuficiente (limite de crédito excedido).\n");
            }
        } else if (strcmp(lista_clientes[origem_index].tipo_conta, "comum") == 0) {
            if (saldo_origem - valor - taxa >= -1000.0) {
                lista_clientes[origem_index].saldo = saldo_origem - valor - taxa;
                lista_clientes[destino_index].saldo += valor;
                printf("Transferencia realizada com sucesso.\n");

                // Registrar as transações no extrato de origem e destino
                char transacao[100];
                snprintf(transacao, sizeof(transacao), "Transferencia para %s (Valor: %.2lf, Tarifa: %.2lf, Saldo: %.2lf)\n",lista_clientes[destino_index].nome, valor, taxa, lista_clientes[origem_index].saldo);
                strcat(lista_extrato[origem_index].extrato, transacao);
                snprintf(transacao, sizeof(transacao), "Transferencia de %s (Valor: %.2lf, Saldo: %.2lf)\n",lista_clientes[origem_index].nome, valor, lista_clientes[destino_index].saldo);
                strcat(lista_extrato[destino_index].extrato, transacao);
                salva_extrato(lista_extrato, quantidade_extrato);
                salvar_clientes(lista_clientes, quantidade_clientes);
            } else {
                printf("Saldo insuficiente (limite de crédito excedido).\n");
            }
        } else {
            printf("Tipo de conta de origem inválido.\n");
            }
        }
    }