SRCS =	  parse_file.c math.c utils.c window.c draw.c math2.c math3.c
OBJS = $(SRCS:.c=.o)
SRCS_SSE =	 math.sse.c
OBJS_SEE = $(SRCS_SSE:.sse.c=.sse.o)
BONUS_SRCS = fdf_bonus.c window_bonus.c utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
GNL_SRCS = gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
CC = cc
AR = ar
C_FLAGS = -Wall -Wextra -Werror -Ofast -g # -O3 -g -fsanitize=address
LD_FLAGS := -L./libft -lft -L./ -lmlx_Linux -lXext -lX11 -lm -lz 
NAME = fdf
LD_FLAGS_OBJ = 
.PHONY: clean

all: $(NAME)


clean:
	cd libft && make fclean
	rm -rf $(OBJS)  $(BONUS_OBJS) $(GNL_OBJS) debug bonus b_debug main.o $(OBJS_SEE)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.sse.o: %.sse.c fdf.h
	$(CC) $(C_FLAGS) -msse -msse2 -c -o $@ $< $(LD_FLAGS_OBJ)

%.o: %.c fdf.h
	$(CC) $(C_FLAGS) -c -o $@ $< $(LD_FLAGS_OBJ)

$(NAME):  libft/libft.a main.o $(OBJS) $(GNL_OBJS) $(OBJS_SEE)
	$(CC) $(C_FLAGS) -o  $@ main.o $(OBJS) $(GNL_OBJS) $(OBJS_SEE) $(LD_FLAGS) 

libft/libft.a:
	cd libft && make fclean all


bonus: libft/libft.a $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(OBJS_SEE)
	$(CC) $(C_FLAGS) -o  $@ $(OBJS)  $(BONUS_OBJS) $(GNL_OBJS) $(OBJS_SEE) $(LD_FLAGS) 

debug: C_FLAGS+= -g
debug: LD_FLAGS+= -fsanitize=address
debug: LD_FLAGS_OBJ+= -fsanitize=address
debug:  libft/libft.a main.o  $(OBJS) $(GNL_OBJS) $(OBJS_SEE)
	$(CC) $(C_FLAGS) -o $@ main.o $(OBJS) $(GNL_OBJS) $(OBJS_SEE) $(LD_FLAGS)


b_debug: C_FLAGS+= -g
b_debug: LD_FLAGS+= -fsanitize=address
b_debug: LD_FLAGS_OBJ+= -fsanitize=address
b_debug: libft/libft.a $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(OBJS_SEE)
	$(CC) $(C_FLAGS) -o  $@ $(OBJS)  $(BONUS_OBJS) $(GNL_OBJS) $(OBJS_SEE) $(LD_FLAGS)

