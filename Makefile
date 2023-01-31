TARGET = stack
CC = gcc

$(TARGET) : main.o stack_functions.o errors.o
	$(CC) main.o stack_functions.o errors.o -o $(TARGET)

main.o : main.cpp
	$(CC) -c main.cpp -o main.o

stack_functions.o : stack_functions.cpp
	$(CC) -c stack_functions.cpp -o stack_functions.o

errors.o : errors.cpp
	$(CC) -c errors.cpp -o errors.o

clean:
	rm *.o