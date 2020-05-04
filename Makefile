NAME= "hello_world";

all:
	cc -std=c99 -Wall $(NAME).c mpc.c -ledit -lm -o $(NAME);

