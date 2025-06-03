#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR "Error\n"
# define DUMMY_RANK -1

# include <limits.h>
# include <stddef.h> // size_t
# include <stdlib.h>

// operation
# define SWAP_A "sa\n"
# define PUSH_A "pa\n"
# define PUSH_B "pb\n"
# define ROTATE_A "ra\n"
# define ROTATE_B "rb\n"
# define ROTATE_BOTH "rr\n"
# define REVERSE_ROTATE_A "rra\n"
# define REVERSE_ROTATE_B "rrb\n"
# define REVERSE_ROTATE_BOTH "rrr\n"

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
long				ft_atol(const char *nptr);
// error check
int					ft_is_digit(char **argv, int size);
int					ft_is_sort(int *arr, int size);
// make stack
int					*compression(int *arr, int size);
t_stack				*make_stack(void);
t_stack				*stack_utils(int *arr, int size);
// stack op
void				push(t_stack *to_stack, t_stack *from_stack, char *op);
void				rotate(t_stack *stk, char *op);
void				reverse_rotate(t_stack *stk, char *op);
void				swap(t_stack *stk, char *op);

// sort
void				sort_three(t_stack *stk_a);
void				sort_five(t_stack *stk_a, t_stack *stk_b);

// operation_helper
int					max_node(t_stack *stk);
int					min_node(t_stack *stk);

#endif