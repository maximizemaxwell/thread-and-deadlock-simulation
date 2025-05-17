include ../common.mk
TARGET := $(PREFIX)/sum_threads
$(TARGET): sum_threads.c
	$(CC) $(CFLAGS) $< -o $@ -pthread
all: $(TARGET)
clean: ; rm -f $(TARGET)
