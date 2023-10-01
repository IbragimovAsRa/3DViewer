CC=gcc
RUN = build/3dViewer
FLAGS=-Wall -Werror -Wextra -std=c11
MAC_FLAGS=-lcheck -lm
LINUX_FLAGS=-lcheck -lsubunit -lm -lrt -lpthread
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
FILES=$(wildcard Parser/*.c Transformer/*.c)
OBJ=*.o
TEST_FILES = $(wildcard Tester/*.c)

OS := $(shell uname -s)

ifeq ($(OS),Darwin)
	OPEN=open
endif
ifeq ($(OS),Linux)
	OPEN=xdg-open
endif

.PHONY: all tests test.a

all:install
	$(RUN)


test.a: $(FILES)
	$(CC) -c $(FLAGS) $(FILES)
	ar rc $@ $(OBJ)
	ranlib $@
	rm -rf *.o

tests: test.a create_obj_file
ifeq ($(OS),Darwin)
	$(CC) $(FLAGS) $(TEST_FILES) $< -o test $(MAC_FLAGS)
else
	$(CC) $(FLAGS) $(TEST_FILES) $< -o test $(LINUX_FLAGS)
endif

	./test

gcov_report: clean create_obj_file
ifeq ($(OS),Darwin)
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(FILES) $(TEST_FILES) -o test $(MAC_FLAGS)
	./test
	rm tester.*
	rm cases.*
	lcov -t "s21_test" -o postreport.info -c -d .
	genhtml -o report postreport.info
	$(OPEN) report/index.html
else
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(FILES) $(TEST_FILES) -o test $(LINUX_FLAGS)
	./test
	lcov -t "s21_test" -o postreport.info -c -d .
	genhtml -o report postreport.info
	$(OPEN) report/index.html

endif

install: uninstall
	mkdir build
	cd build && cmake build ../
	make -C ./build/

uninstall:
	rm -Rf build/
	rm -rf 3DViewer_v1.0.tar

dvi:
	texi2html 3dviewer.texi
	$(OPEN) 3dviewer.html

dist:
	tar -cf 3DViewer_v1.0.tar \
	 							3dViewer\
								Parser\
								Tester\
								Transformer\
								CMakeLists.txt\
								Makefile\
								../README.md\
								../LICENSE 2> /dev/null

format:
	clang-format -i Parser/*.c Parser/*.h Tester/*.c Tester/*.h Transformer/*.c Transformer/*.h 3dViewer/*.cpp 3dViewer/*.h

clean_gcov:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf test
	rm -rf test.a
	rm -rf report
	rm -rf postreport.info

clean: clean_gcov uninstall
	rm -rf *.o
	rm -rf *.a
	rm -rf *.html
	rm -rf *.ini
	rm -rf test
	rm -rf test.a
	rm -rf test_cub.obj

create_obj_file:
	echo "v 1 -1 -1" > test_cub.obj
	echo "v 1 -1 1" >> test_cub.obj
	echo "v -1 -1 1" >> test_cub.obj
	echo "" >> test_cub.obj
	echo "f 1/1/2 2/3/1 3/1/2" >> test_cub.obj
	echo "f 2/1/1 3/2/3 1/2/3" >> test_cub.obj
