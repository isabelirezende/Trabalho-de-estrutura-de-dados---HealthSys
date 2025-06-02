# Nome do compilador
CC = gcc

# Flags de compilação 
CFLAGS = -Wall

# Arquivos fonte
SRC = main.c bdpaciente.c

# Arquivos objeto
OBJ = $(SRC:.c=.o)

# Nome do executável
TARGET = healthsys

# Regra padrão
all: $(TARGET)

# Como construir o executável
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para arquivos objeto (compilação individual)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de arquivos gerados
clean:
	rm -f $(TARGET) $(OBJ)

# Comando de execução (opcional)
run: all
	./$(TARGET)
