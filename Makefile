CC = gcc
CFLAGS = -c -Wall
TST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit 
COV_LIBS = -lgcov -coverage
SRC_DIR= src
TST_DIR= tests
SRC_FILES = $(addprefix $(SRC_DIR)/, *.c) 
TST_FILES = $(addprefix $(TST_DIR)/, *.c)

all: check_calculator_tests

roman_calculator.o:  $(SRC_FILES) $(addprefix $(SRC_DIR)/, roman_calculator.h)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(SRC_FILES) 

check_calculator.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS)  $(TST_FILES) 

check_calculator_tests: roman_calculator.o check_calculator.o
	$(CC) roman_calculator.o check_calculator.o $(TST_LIBS) $(COV_LIBS) -o check_calculator_tests

test: check_calculator_tests
	./check_calculator_tests

.PHONY: clean all

clean:
	-rm *.o *.log check_calculator_tests

