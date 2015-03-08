SRC= main.c \
	linkedlist.c \
	randarray.c

OBJ=$(SRC:.c=.o)

all: clean run
	
run: $(OBJ)
	gcc $^ -o $@
	./$@

%.o: %.c
	gcc -c -g $< -o $@

clean:
	@rm -rf *.o
