CC = gcc
CFLAGS = -pthread -Wall -Wextra -g
TARGET = Readwritelock
LOG_ANALYZER = analyze_logs

all: $(TARGET)

$(TARGET): src/rwlock.c src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/rwlock.c src/main.c

$(LOG_ANALYZER): tests/analyze_logs.c
	$(CC) -o $(LOG_ANALYZER) tests/analyze_logs.c

test: $(TARGET) $(LOG_ANALYZER)
	@mkdir -p logs
	@./$(TARGET)
	@./$(LOG_ANALYZER)

clean:
	rm -f $(TARGET) $(LOG_ANALYZER)
	rm -f logs/*.log