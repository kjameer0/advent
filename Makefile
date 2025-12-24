DIR_INC=include
DIR_LIB=lib
DIR_OBJ=obj
# compiler
CC := gcc
CFLAGS := -Wall -Wextra -I/opt/homebrew/include
LDFLAGS := -L/opt/homebrew/lib -lcmocka

SOURCES := $(wildcard $(DIR_LIB)/*.c)
# use SOURCES as input
# create a new list OBJECTS that replaces lib/ with
# /obj. DIR_LIB is used twice to match all files
# in /lib with a .c extension
OBJECTS := $(patsubst $(DIR_LIB)/%.c,$(DIR_OBJ)/%.o,$(SOURCES))

lib: $(OBJECTS)

$(DIR_OBJ)/%.o: $(DIR_LIB)/%.c $(DIR_INC)/%.h
	gcc -c -o $@ $<
# builds a specific day's binary: Ex: make day1 DAY=1
day$(DAY)/main: day$(DAY)/main.c $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# build library for testing
.PHONY: build-lib-test
build-lib-test: lib
	$(CC) $(CFLAGS) $(LDFLAGS) $(DIR_LIB)/__test__/t.c -o $(DIR_LIB)/__test__/test $(OBJECTS)

.PHONY: run-lib-test
run-lib-test: build-lib-test
	$(DIR_LIB)/__test__/test
