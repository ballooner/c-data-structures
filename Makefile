SRC_DIR:=src/
INCLUDE_DIR:=include/
SRC_FILES:=$(wildcard $(SRC_DIR)*.c)

CC:=gcc
C_FLAGS:=-W -Wextra -Wall -pedantic-errors -I$(INCLUDE_DIR)

main: $(SRC_FILES)
	$(CC) $(C_FLAGS) $(SRC_FILES) -o test
