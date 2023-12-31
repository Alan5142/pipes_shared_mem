CC ?= gcc

APP_NAME_PIPE_SIMPLE = pipe_simple
APP_NAME_PIPE_PROCESS = pipe_process
APP_NAME_PIPE_PROCESS_NAMED_WRITE = pipe_process_named_write
APP_NAME_PIPE_PROCESS_NAMED_READ = pipe_process_named_read
APP_NAME_SHARED_MEMORY_READ = shared_memory_read
APP_NAME_SHARED_MEMORY_WRITE = shared_memory_write

OBJ_FILES_PIPE_SIMPLE = pipe_simple.o
OBJ_FILES_PIPE_PROCESS = pipe_process.o
OBJ_FILES_PIPE_PROCESS_NAMED_WRITE = pipe_process_named_write.o
OBJ_FILES_PIPE_PROCESS_NAMED_READ = pipe_process_named_read.o
OBJ_FILES_SHARED_MEMORY_READ = shared_memory_read.o
OBJ_FILES_SHARED_MEMORY_WRITE = shared_memory_write.o
LIBS = .


all: $(APP_NAME_PIPE_SIMPLE) $(APP_NAME_PIPE_PROCESS) $(APP_NAME_PIPE_PROCESS_NAMED_WRITE) $(APP_NAME_PIPE_PROCESS_NAMED_READ) $(APP_NAME_SHARED_MEMORY_READ) $(APP_NAME_SHARED_MEMORY_WRITE)

$(APP_NAME_PIPE_SIMPLE): $(OBJ_FILES_PIPE_SIMPLE)
	$(CC) -o $@ $^

$(APP_NAME_PIPE_PROCESS): $(OBJ_FILES_PIPE_PROCESS)
	$(CC) -o $@ $^

$(APP_NAME_PIPE_PROCESS_NAMED_WRITE): $(OBJ_FILES_PIPE_PROCESS_NAMED_WRITE)
	$(CC) -o $@ $^

$(APP_NAME_PIPE_PROCESS_NAMED_READ): $(OBJ_FILES_PIPE_PROCESS_NAMED_READ)
	$(CC) -o $@ $^

$(APP_NAME_SHARED_MEMORY_READ): $(OBJ_FILES_SHARED_MEMORY_READ)
	$(CC) -o $@ $^

$(APP_NAME_SHARED_MEMORY_WRITE): $(OBJ_FILES_SHARED_MEMORY_WRITE)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $^ -g

clean:
	rm *.o $(APP_NAME_PIPE_SIMPLE) $(APP_NAME_PIPE_PROCESS)