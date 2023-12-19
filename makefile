CC=gcc
CFLAGS+=-Wall -Wextra -Werror #-g3 -fsanitize=address
OBJ+=src/main.o src/my_curl.o src/data_manager.o src/utils.o src/string_utils.o
TARGET+=my_curl

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

.PHONY: all clean fclean all
clean:
	rm -f src/*.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
