BUILD_DIR?=build
NCMD_FPATH=$(BUILD_DIR)/your.ncmd
SRC=ncb.c
BIN=$(BUILD_DIR)/ncb

all: clean build run inspect
	@echo "# DONE"

.PHONY: clean
clean:
	@echo "# Cleaning $(BUILD_DIR)"
	@rm -fr $(BUILD_DIR) || true
	@mkdir -p $(BUILD_DIR)

.PHONY: build
build:
	@echo "# Building $(SRC)"
	@gcc $(SRC) -o $(BIN)

.PHONY: run
run:
	@echo "# Running $(BIN)"
	@./$(BIN) $(NCMD_FPATH)

.PHONY: inspect
inspect:
	@echo "# Inspecting $(NCMD_FPATH)"
	@xxd -c 4 -b $(NCMD_FPATH)
