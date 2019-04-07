CC = gcc
CFLAGS = -W -Wall
D_OBJECTS = main_d.o menu_d.o user_d.o
OBJECTS = main.o menu.o user.o

all : manager

manager : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
manage_debug : $(D_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main_d.o : main.c
	$(CC) -DDEBUG_MODE  $(CFLAGS) -c -o $@ $^

menu_d.o : menu.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

user_d.o : user.c
	$(CC) -DDEBUG_MODE $(CFLAGS) -c -o $@ $^

clean :
	rm *.o manager manager_debug
