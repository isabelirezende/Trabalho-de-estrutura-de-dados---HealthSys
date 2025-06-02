#include <stdio.h>  // Biblioteca padrão de entrada/saída
#include <stdlib.h> // Biblioteca padrão para funções como malloc e free
#include <string.h> // Biblioteca para manipulação de strings
#include "bdpaciente.h" // Header do TAD BDPaciente

// Função que exibe o menu principal do programa e trata as opções do usuário
void menu(BDPaciente *bd) {
    int opcao; // Variável para armazenar a escolha do usuário
    do {
        // Exibe o menu de opções
        printf("\n=== MENU ===\n");
        printf("1 - Consultar paciente\n");
        printf("2 - Listar todos os pacientes\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao); // Lê a opção escolhida
        getchar(); // Limpa o caractere '\n' deixado no buffer pelo scanf

        // Executa a ação correspondente à opção escolhida
        switch (opcao) {
            case 1:
                consultarPaciente(bd); // Chama a função para consultar paciente
                break;
            case 2:
                listarPacientes(bd); // Chama a função para listar todos os pacientes
                break;
            case 0:
                printf("Saindo...\n"); // Mensagem de saída
                break;
            default:
                printf("Opção inválida!\n"); // Mensagem de erro para opção inválida
        }
    } while (opcao != 0); // Repete o menu até o usuário escolher sair (opção 0)
}

// Função principal do programa
int main() {
    BDPaciente bd; // Declara uma variável do tipo BDPaciente (estrutura do banco de dados)

    inicializarBD(&bd); // Inicializa o banco de dados com 0 pacientes
    carregarCSV(&bd, "bd_paciente.csv"); // Carrega os dados de um arquivo CSV para o banco de dados
    menu(&bd); // Chama o menu principal para interação com o usuário
    liberarBD(&bd); // Libera recursos (não faz nada neste caso, mas pode ser útil futuramente)

    return 0; // Retorna 0 indicando que o programa terminou com sucesso
}
