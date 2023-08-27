# make
all: build test

# make build
build: reduce filter map pipe

# make test
test:
	bash test.sh

# make clean
clean:
	rm reduce filter map pipe

reduce: reduce.c reduce.h
	gcc -Wall -Wextra -g $^ -o $@

filter: filter.c filter.h
	gcc -Wall -Wextra -g $^ -o $@

map: map.c map.h
	gcc -Wall -Wextra -g $^ -o $@

pipe: pipe.c pipe.h
	gcc -Wall -Wextra -g $^ -o $@

.PHONY: all build test clean
