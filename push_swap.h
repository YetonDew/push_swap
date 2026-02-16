#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}					t_stack;

/* -------- stack_utils.c -------- */
int		stack_len(t_stack *stack);
t_stack	*find_last(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
bool	is_sorted(t_stack *stack);

/* -------- init.c -------- */
void	init_stack_a(t_stack **a, char **argv);

/* -------- init_nodes.c -------- */
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);

/* -------- sort_stack.c -------- */
void	sort_stack(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

/* -------- sort_small.c -------- */
void	sort_three(t_stack **a);

/* -------- swaps.c -------- */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/* -------- push.c -------- */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

/* -------- rotations.c -------- */
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);

/* -------- rrotations.c -------- */
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

/* -------- utils.c -------- */
long	ft_atol(const char *str);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
t_stack	*get_cheapest(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top, char name);

/* -------- ft_split.c -------- */
char	**ft_split(char const *s, char c);

/* -------- ft_strlen.c -------- */
size_t	ft_strlen(const char *s);

/* -------- ft_substr.c -------- */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* -------- ft_strlcpy.c -------- */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
