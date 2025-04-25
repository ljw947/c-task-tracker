all:
	rm -rf build
	mkdir -p build
	gcc -g -Wall src/*.c src/*.h -o build/main -lncurses
