/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvll.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:32:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 13:50:43 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect/libvect.h"
#include "libft/libft.h"
#include "libft/malloc.h"

#ifndef LIBVLL_H
# define LIBVLL_H

# ifndef VLL_DLINK
#  define VLL_DLINK		1
# endif

# ifndef VLL_SIZE
#  define VLL_SIZE		1
# endif

# ifndef VLL_TAIL
#  define VLL_TAIL		1
# endif

# define ISVLL(n)		(n->data.used == (size_t)-1 && n->data.total == sizeof(t_vll))

typedef struct			s_vll_node
{
	t_vect				data;
	struct s_vll_node	*next;
# if (VLL_SIZE == 1)
	struct s_vll_node	*prev;
# endif
}						t_vll_node;

typedef struct			s_vll
{
	t_vll_node			*head;
# if (VLL_TAIL == 1)
	t_vll_node			*tail;
# endif
# if (VLL_SIZE == 1)
	size_t				size;
# endif
}						t_vll;

size_t					vll_size(t_vll *l);
t_vll_node				*vll_add(t_vll *l, void *data, size_t size);
t_vll_node				*vll_add_back(t_vll *l, t_vll_node *n, void *data, size_t size);
t_vll_node				*vll_add_front(t_vll *l, t_vll_node *n, void *data, size_t size);
t_vll_node				*vll_node_new(void *data, size_t size);
t_vll_node				*vll_tail(t_vll *l);
t_vll_node				*vll_tail_add(t_vll *l, void *data, size_t size);
t_vll_node				*vll_vll_add(t_vll *l, t_vll *new);
void					vll_init(t_vll *l);
void					vll_node_add_back(t_vll *l, t_vll_node *n, t_vll_node *new);
void					vll_node_add_front(t_vll *l, t_vll_node *n, t_vll_node *new);

#endif
