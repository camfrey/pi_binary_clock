start: display.c main.c
	cc -c display.c; cc -c main.c

all: display.o main.o framebuffer.o
	cc -o clock main.o display.o framebuffer.o
clean: display.o main.o clock
	rm main.o; rm display.o; rm clock 
run: clock.sh clock
	./clock.sh | ./clock

input: clock
	./clock
