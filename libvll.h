/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvll.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:32:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/26 17:02:22 by qle-guen         ###   ########.fr       */
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
t_vll_node				*vll_tail(t_vll *l);
void					vll_add(t_vll *l, void *data, size_t size);
void					vll_tail_add(t_vll *l, void *data, size_t size);

#endif
