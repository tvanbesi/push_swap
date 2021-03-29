#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>	// REMOVE FOR DEFENSE

# include "libft.h"

# define STDIN			0
# define STDOUT			1
# define STDERR			2
# define CHUNK_SIZE		100
# define BUFFER_SIZE	4096


typedef struct		s_stack
{
	int		maxsize;
	int		top;
	int		*items;
}					t_stack;

typedef enum		e_optype
{
	INVALID,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_optype;

typedef enum		e_chunk
{
	MIN,
	MAX
}					t_chunk;

typedef enum		e_stack_id
{
	A,
	B
}					t_stack_id;

int		prompt(char **line);

void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack);
void	rrotate(t_stack *stack);
void	stack_operation(t_stack *a, t_stack *b, int operation);

int		getoperation(char *line);

void	printstacks(t_stack *a, t_stack *b);

void	sort_three(t_stack *a, t_stack *b);
void	sort_fourfive(t_stack *a, t_stack *b);
void	insertsort(t_stack *a, t_stack *b);
void	pivot(t_stack *a, t_stack *b);

int		issorted(t_stack *stack, int (*f)(int, int), int start_pos);
int		ascending(int a, int b);
int		descending(int a, int b);
int		getival(t_stack *stack, int val);
int		getilval(t_stack *stack);
int		getibval(t_stack *stack);
int		getlval(t_stack *stack);
int		getbval(t_stack *stack);
int		getlval_t(t_stack *stack, int threshold);
int		getbval_t(t_stack *stack, int threshold);

int		getinsertidx(t_stack *a, int nb_to_insert);
int		getinsertidx_r(t_stack *a, int nb_to_insert);
void	put_on_top(t_stack *a, int idx, int stack_id);

#endif
