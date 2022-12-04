CFLAGS += -Wall
SAMPLE_FILES = sample.txt input.txt

main: main.c
	$(CC) $(CFLAGS) $< -o $@

test: $(SAMPLE_FILES) main
	$(CURDIR)/main $(SAMPLE_FILES)
