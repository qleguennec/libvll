/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvll.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:32:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 00:46:40 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect/libvect.h"
#include "libft/libft.h"
#include "libft/malloc.h"
// remove
#include <stdio.h>

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

# define VLL_DEF_DELIM		"[],'"

# define VLL_IMPORT_STR		1

# define VLL_EXPORT_STR		1
# define VLL_EXPORT_DELIM	2

# define VLL_PRINT_NL		1

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
void					vll_free(t_vll *l);
void					vll_init(t_vll *l);
void					vll_node_add_back(t_vll *l, t_vll_node *n, t_vll_node *new);
void					vll_node_add_front(t_vll *l, t_vll_node *n, t_vll_node *new);

t_vll					*vll_fmap(t_vll *l, t_vll *(*f)(t_vll *));
void					vll_map_io(t_vll *l, void (*f)(t_vect *v));
void					vll_vect_map(t_vll *l, void (*f)(t_vect *));

t_vll					*vll_import(char **s, char *delim, int opts);
void					vll_export(t_vll *l, t_vect *v, char *delim, int opts);
void					vll_print(int fd, t_vll *l, int opts);

#endif
