# make
all: debug

# make debug
debug: debug/bin/vector

# make clean
clean:
	rm -rf debug/obj

# make mrproper
mrproper:
	rm -rf debug/


debug/bin/vector: main.c debug/obj/Vector.o
	gcc -Wall -Wextra -g $^ -o $@

debug/obj/Vector.o: Vector.c Vector.h
	gcc -Wall -Wextra -g -c $< -o $@



.PHONY: all debug clean mrproper

# will create all necessary directories after the Makefile is parsed
$(shell mkdir -p debug/obj debug/bin)
