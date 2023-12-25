CC = gcc
TEST_LIBS = -lcheck
ifeq ($(shell uname -s), Linux)
	TEST_LIBS += -lsubunit -lm
endif
CFLAGS =  -g -lm
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
VALGRIND_FLAGS_v2 = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
BUILD_DIR = build
EXEC = /build/SmartCalc

all: install open

install:
	[ -d $(BUILD_DIR) ] || mkdir -p $(BUILD_DIR)
	cd build && qmake ../Front
	make -C ./build/

open:
ifeq ($(shell uname), Linux)
	.$(EXEC)
else
	open .$(EXEC)
endif

uninstall: clean
	rm -Rf build/
	rm -rf ../SmartCalc.tar
	rm -rf ../SmartCalc.app

dvi:
	open -a 'google chrome' SmartCalc.html

dist: uninstall clean
	cd ../../ && tar -czvf SmartCalc.tar src

valgrind: test
	valgrind $(VALGRIND_FLAGS_v2) ./test
	grep -n "ERROR SUMMARY" valgrind.txt

test: clean 
	$(CC) $(CFLAGS) -c calculation.c my_heder.h --coverage -lm
	$(CC) $(CFLAGS) -c parser.c my_heder.h --coverage -lm
	$(CC) $(CFLAGS) -c variable_result.c my_heder.h --coverage -lm
	$(CC) $(CFLAGS) -c help_functions.c my_heder.h --coverage -lm
	$(CC) $(CFLAGS) -c ./tests/test.c ./tests/s21_test_calc.h --coverage -lm
	$(CC) $(CFLAGS) -c ./tests/test_qalc.c ./tests/s21_test_calc.h --coverage -lm
	$(CC) $(CFLAGS) -c my_test.c my_heder.h --coverage -lm
	$(CC) $(CFLAGS) calculation.o my_test.o parser.o variable_result.o help_functions.o test.o test_qalc.o -o test -lcheck --coverage -lm
	./test
	rm -rf *.o tests/*.o

gcov_flag:
	$(eval CFLAGS += -fprofile-arcs -ftest-coverage)

gcov_report: clean gcov_flag test
	gcov $(SOURCES)
	rm -rf test*.gcno test*.gcda test*.gcov
	gcovr -s --html-details -o coverage.html
	open coverage.html
	rm -rf *.gcno *.gcda *.gcov
	
style:
	clang-format --style=google -i *.c *.h
	clang-format --style=google -i tests/*.c tests/*.h

test_leaks: my_heder.a
	$(CC) $(CFLAGS) -c calculation.c my_heder.h --coverage 
	$(CC) $(CFLAGS) -c parser.c my_heder.h --coverage 
	$(CC) $(CFLAGS) -c variable_result.c my_heder.h --coverage 
	$(CC) $(CFLAGS) -c help_functions.c my_heder.h --coverage 
	$(CC) $(CFLAGS) -c ./tests/test.c ./tests/s21_test_calc.h --coverage
	$(CC) $(CFLAGS) -c ./tests/test_qalc.c ./tests/s21_test_calc.h --coverage
	$(CC) $(CFLAGS) -c my_test.c my_heder.h --coverage 
	$(CC) $(CFLAGS) calculation.o my_test.o parser.o variable_result.o help_functions.o test.o test_qalc.o -o test -lcheck --coverage
ifeq ($(shell uname -s), Linux)
	rm -rf *.o tests/*.o
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
else
	leaks --atExit -- ./test
endif

clean:
	rm -rf *.a *.o tests/*.o tests/*.gch test *.gcno *.gcda *.gcov *.gch *.info coverage* *.dSYM

.PHONY: my_heder.a all clean test style
