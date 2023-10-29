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




char* get_current_time();

void ler_clientes();

void salvar_clientes();

void ler_extrato();

void salva_extrato();

void NovoCliente();

void ApagaCliente();

void ListarClientes();

void Debito();

void Deposito();

void Extrato();

void TransferenciaEntreContas();

#endif //PROJETO2_BIBLIOTECA_H
