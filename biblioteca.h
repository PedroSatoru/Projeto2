//
// Created by Pedro Satoru on 24/10/2023.
//

#ifndef PROJETO2_BIBLIOTECA_H
#define PROJETO2_BIBLIOTECA_H

///////////////////IMPORTANTE///////////////


//Criar as listas "clientes.dat" e "extrato.dat", possivel que não se crie ao iniciar pela primeira vez o codigo e ocorra um erro



///////////////////IMPORTANTE///////////////


struct Cliente {
    char nome[100];
    char cpf[12];
    char tipo_conta[6];
    double saldo;
    char senha[20];
};

struct Extrato {
    char nome[100];
    char cpf[12];
    char tipo_conta[6];
    char extrato[1000];
};




void ler_clientes(struct Cliente* lista_clientes, int* quantidade_clientes);

void salvar_clientes(struct Cliente* lista_clientes, int quantidade_clientes);

void ler_extrato(struct Extrato* lista_extrato, int* quantidade_extrato);

void salva_extrato(struct Extrato* lista_extrato, int quantidade_extrato);

void NovoCliente(struct Cliente* lista_clientes, int* quantidade_clientes, struct Extrato* lista_extrato, int* quantidade_extrato);

void ApagaCliente(struct Cliente* lista_clientes, int* quantidade_clientes, struct Extrato* lista_extrato, int* quantidade_extrato);

void ListarClientes(struct Cliente* lista_clientes, int quantidade_clientes);

void Debito(struct Cliente* lista_clientes, int quantidade_clientes, struct Extrato* lista_extrato, int quantidade_extrato);

void Deposito(struct Cliente* lista_clientes, int quantidade_clientes, struct Extrato* lista_extrato, int quantidade_extrato);

void Extrato(struct Cliente* lista_clientes, int quantidade_clientes, struct Extrato* lista_extrato, int quantidade_extrato);

void TransferenciaEntreContas(struct Cliente* lista_clientes, int quantidade_clientes, struct Extrato* lista_extrato, int quantidade_extrato);

#endif //PROJETO2_BIBLIOTECA_H