#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

int swap(t_stack **a);

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	void			*content;
	struct s_node	*target_node;
	struct s_node	*prev;
	struct s_node	*next;
}					t_stack;


#endif
