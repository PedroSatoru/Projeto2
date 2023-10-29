#include <stdio.h>
#include "biblioteca.h"

///////////////////IMPORTANTE///////////////


//Criar as listas "clientes.dat" e "extrato.dat", possivel que não se crie ao iniciar pela primeira vez o codigo e ocorra um erro



///////////////////IMPORTANTE///////////////

int main(){
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
        printf("Digite a opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                NovoCliente();
                break;
            case 2:
                ApagaCliente();
                break;
            case 3:
                ListarClientes();
                break;
            case 4:
                Debito();
                break;
            case 5:
                Deposito();
                break;
            case 6:
                Extrato();
                break;
            case 7:
                TransferenciaEntreContas();
                break;
            case 8:
                printf("Você saiu. Volte sempre!\n");
                return 0;
            default:
                printf("Opcao invalida\n");
        }
    }
}
