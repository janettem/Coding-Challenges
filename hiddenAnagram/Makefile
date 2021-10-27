NAME = hiddenAnagram

SOURCES = sources/main.cpp sources/hiddenAnagram.cpp

all: $(NAME)

$(NAME):
	@ccache g++ $(SOURCES) -I headers/ -o $(NAME)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
