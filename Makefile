SRC_DIR:=src/
INCLUDE_DIR:=include/
TEST_DIR:=tests/
SRC_FILES:=$(wildcard $(SRC_DIR)*.c)
TEST_FILES:=$(wildcard $(TEST_DIR)*.c)

CC:=gcc
C_FLAGS:=-W -Wextra -Wall -pedantic-errors -I$(INCLUDE_DIR)

test: $(SRC_FILES) $(TEST_FILES)
	$(CC) $(C_FLAGS) $(SRC_FILES) $(TEST_FILES) -o testing

clean: 
	@rm -f testing
