CC=gcc

all: stack_using_linkedlist

stack_using_linkedlist:
	$(CC) -o linlstStack stack_using_linkedlist.c utility.c 
	
clean:
	rm -f linlstStack
	 
