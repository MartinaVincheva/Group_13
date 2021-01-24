CC=gcc
CFILE=project_Group15.c
TARGET=project_Group15
all:
	$(CC) $(CFILE) -o $(TARGET)
clean:
	rm project_Group15
