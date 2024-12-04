CFILES = get_next_line.c get_next_line_utils.c
TIME_TEST_FILE = gnl_time_test_runner.c
TEST_FILE = gnl_test_runner.c
OUTPUT = a.out
CFLAGS = -Wall -Wextra -Werror 
CBUFFER = -D BUFFER_SIZE=$(BUFFER)

BUFFER = 42

build:
	cc $(CFILES) $(TEST_FILE) $(CFLAGS) $(CBUFFER) -g -o $(OUTPUT)

smallbuf:
	$(MAKE) run BUFFER=1

bigbuf:
	$(MAKE) run BUFFER=10000000

nobuf:
	cc $(CFILES) $(TEST_FILE) $(CFLAGS) -g -o $(OUTPUT)
	./$(OUTPUT)

run_time_test: $(CFILES) $(TIME_TEST_FILE)
	cc $(CFILES) $(TIME_TEST_FILE) $(CFLAGS) $(CBUFFER) -g -o $(OUTPUT)
	./$(OUTPUT)

run:
	$(MAKE) build
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)

valgrind: build
	valgrind --leak-check=full ./$(OUTPUT) text.txt
