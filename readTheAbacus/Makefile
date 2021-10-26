NAME = readTheAbacus

SOURCES = sources/main.cpp sources/readTheAbacus.cpp

all: $(NAME)

$(NAME):
	@ccache g++ $(SOURCES) -I headers/ -o $(NAME)

fclean:
	@/bin/rm -f $(NAME)

re: fclean all
