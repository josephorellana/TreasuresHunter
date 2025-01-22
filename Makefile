# Nombre del ejecutable
TARGET = bin/treasures_hunter

# Directorios
SRC_DIR = src
ADAPTERS_DIR = src/adapters/ui
INCLUDE_DIR = include
INCLUDE_DIR_ADAPTERS = src/adapters/include
INCLUDE_DIR_PDCURSES = third_party/PDCurses/include
LIB_PDCURSES = third_party/PDCurses/lib
BUILD_DIR = build

# Archivos fuente y de cabecera
SRC = $(wildcard $(SRC_DIR)/*.c) \
      $(wildcard $(ADAPTERS_DIR)/*.c)

OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC)))

# Flags del compilador
CFLAGS = -I$(INCLUDE_DIR) -I$(INCLUDE_DIR_PDCURSES) -I$(INCLUDE_DIR_ADAPTERS) -Wall -Wextra -g
LDFLAGS = -L$(LIB_PDCURSES) -lpdcurses -lwinmm

# Regla por defecto
all: $(TARGET)

# Enlazar el ejecutable
$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

# Compilación de los objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(ADAPTERS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear directorio de build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	mkdir -p bin

# Limpiar archivos generados
clean:
	rm -rf $(BUILD_DIR) bin

# Phony targets
.PHONY: all clean
