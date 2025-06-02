#ifndef BDPACIENTE_H       // Diretiva para evitar múltiplas inclusões do mesmo cabeçalho
#define BDPACIENTE_H

// Define a quantidade máxima de pacientes que o sistema pode armazenar
#define MAX_PACIENTES 1000  

// Estrutura que representa um paciente
typedef struct {
    int id;                     // Identificador único do paciente
    char cpf[20];               // CPF do paciente (formato string)
    char nome[100];             // Nome completo do paciente
    int idade;                  // Idade do paciente
    char data_cadastro[11];     // Data de cadastro (formato "dd/mm/aaaa" ou similar)
} Paciente;

// Estrutura que representa o banco de dados de pacientes
typedef struct {
    Paciente pacientes[MAX_PACIENTES]; // Array de pacientes
    int quantidade;                    // Quantidade atual de pacientes cadastrados
} BDPaciente;

// Declaração das funções disponíveis para manipular o banco de dados
void inicializarBD(BDPaciente *bd);                     // Inicializa o banco de dados
void carregarCSV(BDPaciente *bd, const char *nomeArquivo); // Carrega os dados de um arquivo CSV
void listarPacientes(const BDPaciente *bd);             // Lista todos os pacientes cadastrados
void consultarPaciente(const BDPaciente *bd);           // Consulta pacientes por nome ou CPF
void liberarBD(BDPaciente *bd);                         // Libera recursos do banco de dados (se necessário futuramente)

#endif // Fim da diretiva de inclusão única 
