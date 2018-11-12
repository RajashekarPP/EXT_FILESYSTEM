CC = gcc
#CFLAGS = -Wall
DEPS = headers.h
OBJ = superblock_groupdesc.o main.o ls_command.o cp_command.o cd_command.o inode_info.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< 
all:
	$(CC) -c -o $@ $^
clean:
	rm -rf *.o
