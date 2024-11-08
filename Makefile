# Trình biên dịch và cờ biên dịch
CC = gcc
CFLAGS = -std=c99
TARGET = detectdeadlock

# Biên dịch toàn bộ
all: $(TARGET)

# Định nghĩa quy tắc biên dịch
$(TARGET): src/detectdeadlock.c
	$(CC) $(CFLAGS) -o $(TARGET) src/detectdeadlock.c

# Quy tắc dọn dẹp
clean:
	rm -f $(TARGET)
