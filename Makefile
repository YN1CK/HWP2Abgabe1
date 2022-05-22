# Makefile
# Yannick Reiss
NAME		=	program
CC		=	g++
FLAGS	=	-Wall -g
INLCUDE	=	akku.h position.h drohne.h
OBJECTS	=	akku.cpp position.cpp drohne.cpp testbench.cpp

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)
	touch object.o

%.o: %.c $(INCLUDE)
		$(CC) $(FLAGS) -c -o $@ $<

run: $(NAME)
	./$(NAME)

clean:
	rm $(NAME) *.o

.PHONY: run
.PHONY: clean