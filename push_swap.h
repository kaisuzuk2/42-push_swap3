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
// cost
typedef struct s_cost
{
	int				rr;
	int				rrr;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}					t_cost;

// printf
int					ft_printf(const char *format, ...);
// libft
long				ft_atol(const char *nptr);
// error check
int					ft_is_digit(char **argv, int size);
int					ft_is_sort(int *arr, int size);
int					ft_is_duplicates(int *arr, int size);
// make stack
int					*compression(int *arr, int size);
t_stack				*make_stack(void);
t_stack				*stack_utils(int *arr, int size);
// stack op
void				push_a(t_stack *stk_a, t_stack *stk_b);
void				push_b(t_stack *stk_b, t_stack *stk_a);
void				rotate_a(t_stack *stk_a);
void				rotate_b(t_stack *stk_b);
void				rotate_both(t_stack *stk_a, t_stack *stk_b);
void				reverse_rotate_a(t_stack *stk_a);
void				reverse_rotate_b(t_stack *stk_b);
void				reverse_rotate_both(t_stack *stk_a, t_stack *stk_b);
void				swap_a(t_stack *stk);
// calc cost
t_cost				*calc_cost(t_stack *stk_a, t_stack *stk_b);

// sort
void				sort_three(t_stack *stk_a);
void				sort_five(t_stack *stk_a, t_stack *stk_b);
void				push_back(t_stack *stk_a, t_stack *stk_b);
void				sort(t_stack *stk_a, t_stack *stk_b);

// operation_helper
int					get_max_node_index(t_stack *stk);
int					get_min_node_index(t_stack *stk);
t_node				*get_max_node(t_stack *stk);
t_node				*get_min_node(t_stack *stk);
#endif