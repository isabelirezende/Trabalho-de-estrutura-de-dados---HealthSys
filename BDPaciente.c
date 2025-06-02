#include <stdio.h>     // Biblioteca padrão de entrada e saída
#include <stdlib.h>    // Biblioteca padrão para funções utilitárias (não usada diretamente aqui)
#include <string.h>    // Biblioteca para manipulação de strings
#include "bdpaciente.h" // Arquivo de cabeçalho com a definição das estruturas usadas

// Função para inicializar o banco de dados de pacientes
void inicializarBD(BDPaciente *bd) {
    bd->quantidade = 0; // Define a quantidade de pacientes como 0 ao iniciar
}

// Função para carregar dados de pacientes a partir de um arquivo CSV
void carregarCSV(BDPaciente *bd, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r"); // Abre o arquivo para leitura
    if (!arquivo) { // Verifica se houve erro ao abrir o arquivo
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    char linha[256]; // Buffer para armazenar cada linha do arquivo
    fgets(linha, sizeof(linha), arquivo); // Lê a primeira linha (cabeçalho) e descarta

    // Lê cada linha do arquivo até o final
    while (fgets(linha, sizeof(linha), arquivo)) {
        Paciente p; // Estrutura temporária para armazenar os dados do paciente
        sscanf(linha, "%d,%19[^,],%99[^,],%d,%10s", // Extrai os dados formatados da linha
               &p.id, p.cpf, p.nome, &p.idade, p.data_cadastro);
        bd->pacientes[bd->quantidade++] = p; // Armazena o paciente no banco de dados e incrementa o contador
    }
    fclose(arquivo); // Fecha o arquivo após a leitura
}

// Função para listar todos os pacientes cadastrados
void listarPacientes(const BDPaciente *bd) {
    printf("\nLista de Pacientes:\n");
    for (int i = 0; i < bd->quantidade; i++) { // Percorre o array de pacientes
        Paciente p = bd->pacientes[i]; // Recupera o paciente atual
        printf("%d %s %s %d %s\n", p.id, p.cpf, p.nome, p.idade, p.data_cadastro); // Imprime os dados do paciente
    }
}

// Função para consultar pacientes por nome ou CPF
void consultarPaciente(const BDPaciente *bd) {
    int opcao;
    char busca[100];

    // Exibe o menu de opções para o usuário
    printf("Escolha o modo de consulta:\n");
    printf("1 - Por nome\n");
    printf("2 - Por CPF\n");
    printf("3 - Retornar ao menu principal\n");
    scanf("%d", &opcao);
    getchar(); // Limpa o caractere '\n' deixado pelo scanf

    if (opcao == 3) return; // Retorna ao menu principal

    printf("Digite o prefixo: ");
    fgets(busca, sizeof(busca), stdin); // Lê o prefixo digitado pelo usuário
    busca[strcspn(busca, "\n")] = 0; // Remove o caractere de nova linha '\n' da string

    int encontrados = 0; // Contador de pacientes encontrados
    for (int i = 0; i < bd->quantidade; i++) {
        Paciente p = bd->pacientes[i]; // Recupera o paciente atual

        // Verifica se o prefixo corresponde ao início do nome ou do CPF, dependendo da opção escolhida
        if ((opcao == 1 && strncmp(p.nome, busca, strlen(busca)) == 0) ||
            (opcao == 2 && strncmp(p.cpf, busca, strlen(busca)) == 0)) {
            printf("%d %s %s %d %s\n", p.id, p.cpf, p.nome, p.idade, p.data_cadastro); // Exibe o paciente encontrado
            encontrados++;
        }
    }

    if (!encontrados) { // Se nenhum paciente for encontrado
        printf("Nenhum paciente encontrado.\n");
    }
}

// Função para liberar recursos do banco de dados (não usada neste caso)
void liberarBD(BDPaciente *bd) {
    // Nada a liberar no momento, pois não há alocação dinâmica.
}
