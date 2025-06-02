# Trabalho de Estrutura de Dados 
**Heloísa Borghardt Hand**  
**Isabeli Rocha de Rezende**

## HealthSys - Sistema de Gerenciamento de Pacientes

Este trabalho simula um banco de dados que armazena informações de pacientes, acessadas a partir de um arquivo CSV.

Possui uma interface de terminal interativa que permite consultar ou listar dados dos pacientes, como: ID, nome, CPF, idade e data de cadastro. O usuário pode buscar pacientes digitando o nome ou CPF, ou ainda visualizar todos os pacientes cadastrados.

---

## Estrutura do Projeto

- `main.c`: Função principal e menu interativo para o usuário.
- `bdpaciente.c`: Implementação do TAD `BDPaciente` com as funcionalidades principais.
- `bdpaciente.h`: Cabeçalho com a definição das estruturas e funções do TAD.
- `bd_paciente.csv`: Arquivo CSV com exemplo de dados dos pacientes.
- `Makefile`: Automatiza a compilação, execução e limpeza do projeto.
- `README.md`: Documentação do projeto.

---

## Como Compilar
### Usando o Makefile

Abra o terminal na pasta do projeto.

Digite o comando: make

Para executar o programa: make run

Para limpar os arquivos gerados: make clean

-Sem Makefile

Use o seguinte comando no terminal (Linux/macOS):

```
gcc main.c bdpaciente.c -o healthsys
./healthsys
```

No Windows (cmd ou PowerShell):

```
gcc main.c bdpaciente.c -o healthsys.exe
healthsys.exe
```
## Funcionalidades
- Na leitura de dados de pacientes a partir de um arquivo CSV, ele carrega automaticamente o conteúdo do arquivo bd_paciente.csv ao iniciar o programa.
- Armazena até 1000 pacientes em um vetor fixo de estruturas (Paciente), evitando alocação dinâmica.
- Lista todos os pacientes cadastrados no sistema em forma de lista.
- Consulta os pacientes pelo prefixo comparando os primeiros dígitos, por nome ou CPF.
- Possui um menu interativo e fácil de ser compreendido, onde o usuário pode escolher as opções: consultar paciente, listar pacientes ou sair do programa

## Decisões de Implementação

-Os dados dos pacientes são armazenados em um vetor fixo com limite para até 1000 pacientes, simplificando o gerenciamento de memória.
-Não há uso de alocação dinâmica para facilitar o controle do programa.
-A consulta por prefixo usa a função strncmp para comparar apenas os primeiros caracteres, tornando a busca mais flexível e rápida.
-O programa lê o arquivo CSV apenas uma vez na inicialização e não grava alterações de volta no arquivo.

## Observações
Neste trabalho, o sistema só lê os dados do arquivo CSV na inicialização e não salva alterações feitas durante a execução.

Na próxima fase, o programa poderá permitir:
-Atualizar informações dos pacientes.
-Remover registros.
-Salvar essas mudanças no arquivo CSV, garantindo que os dados sejam mantidos entre execuções.
-Isso tornará o sistema mais completo para o gerenciamento real dos pacientes.
