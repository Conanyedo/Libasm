NAME = libasm.a
NS = nasm
NS_FLAGS = -f macho64
LD_FLAG = -macosx_version_min 10.7.0 -lSystem

SRC = ft_read.s\
	  ft_write.s\
	  ft_strcmp.s\
	  ft_strlen.s\
	  ft_strcpy.s\
	  ft_strdup.s\

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.s
	@$(NS) $(NS_FLAGS) $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all