#include <stdio.h>
#include "biblioteca.h"

///////////////////IMPORTANTE///////////////


//Criar as listas "clientes.dat" e "extrato.dat", possivel que não se crie ao iniciar pela primeira vez o codigo e ocorra um erro



///////////////////IMPORTANTE///////////////

int main(){

    // Declaração das variáveis locais
    struct Cliente lista_clientes[1000];
    struct Extrato lista_extrato[1000];
    int quantidade_clientes = 0;
    int quantidade_extrato = 0;
    // Inicializa as listas e executa o loop principal.
    while (1) {
        printf("1: Novo cliente\n");
        printf("2: Apaga cliente\n");
        printf("3: Listar clientes\n");
        printf("4: Debito\n");
        printf("5: Deposito\n");
        printf("6: Extrato\n");
        printf("7: Transferencia entre contas\n");
        printf("8: Sair\n");
        printf("9: Relistar as opcoes\n");

        int op;
        printf("Digite a opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                NovoCliente( lista_clientes, &quantidade_clientes, lista_extrato, &quantidade_extrato);
                break;
            case 2:
                ApagaCliente(lista_clientes, &quantidade_clientes, lista_extrato, &quantidade_extrato);
                break;
            case 3:
                ListarClientes(lista_clientes, quantidade_clientes);
                break;
            case 4:
                Debito(lista_clientes, quantidade_clientes, lista_extrato, quantidade_extrato);
                break;
            case 5:
                Deposito(lista_clientes, quantidade_clientes, lista_extrato, quantidade_extrato);
                break;
            case 6:
                Extrato(lista_clientes, quantidade_clientes, lista_extrato, quantidade_extrato);
                break;
            case 7:
                TransferenciaEntreContas(lista_clientes, quantidade_clientes, lista_extrato, quantidade_extrato);
                break;
            case 8:
                printf("Voce saiu. Volte sempre!\n");
                return 0;
            default:
                printf("Opcao invalida\n");
        }
    }
}