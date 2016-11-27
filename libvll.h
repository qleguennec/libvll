/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvll.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:32:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/27 15:48:44 by qle-guen         ###   ########.fr       */
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

# ifndef VLL_VLL
#  define VLL_VLL		1
#endif

typedef struct			s_vll_node
{
	void				*p;
	struct s_vll_node	*next;
# if (VLL_SIZE)
	struct s_vll_node	*prev;
# endif
}						t_vll_node;

typedef struct			s_vll
{
	t_vll_node			*head;
# if (VLL_TAIL)
	t_vll_node			*tail;
# endif
# if (VLL_SIZE)
	size_t				size;
# endif
# if (VLL_VLL)
	int					vll_vll : 1;
#endif
}						t_vll;

# define IS_VLL(l)		(l->vll_vll)

size_t					vll_size(t_vll *l);
t_vll					*vll_new(void);
t_vll_node				*vll_add(t_vll *l, void *data, size_t size);
t_vll_node				*vll_add_back(t_vll *l, t_vll_node *n, void *data, size_t size);
t_vll_node				*vll_add_front(t_vll *l, t_vll_node *n, void *data, size_t size);
t_vll_node				*vll_node_new(void *data);
t_vll_node				*vll_tail(t_vll *l);
t_vll_node				*vll_tail_add(t_vll *l, void *data, size_t size);
t_vll_node				*vll_vect_node_new(void *data, size_t size);
void					vll_dup(t_vll *dest, t_vll *src);
void					vll_init(t_vll *l);
void					vll_node_add_back(t_vll *l, t_vll_node *n, t_vll_node *new);
void					vll_node_add_front(t_vll *l, t_vll_node *n, t_vll_node *new);

#endif
