#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR "Error\n"
# define DUMMY_RANK -1

# include <stddef.h> // size_t
# include <stdlib.h>

// sentinel
typedef struct s_stack
{
	int				size;
	struct s_node	*dummy_node;
}					t_stack;
// node
typedef struct s_node
{
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

// printf
int					ft_printf(const char *format, ...);
// libft
long				atol(const char *nptr);
// error check
int					ft_is_digit(char **argv, int size);
int					ft_is_sort(int *arr, int size);
// make stack
int					*compression(int *arr, int size);
t_stack				*make_stack(void);
t_stack				*stack_utils(int *arr, int size);

#endif