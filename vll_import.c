/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vll_import.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:18:50 by qle-guen          #+#    #+#             */
/*   Updated: 2016/11/28 17:57:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvll_intern.h"

/*
 * delim[0] is the character for closing a list, e.g '['
 * delim[1] is the character for closing a list, e.g ']'
 * delim[2] is the character for separating elements, e.g ','
 * delim[3] is the character for delimiting elements, e.g '"'
 * if the string s or delim is not well formatted, the result is undefined
*/

static void		skip_whitespace(char **s)
{
	while (ft_isspace(**s))
		(*s)++;
}

static void		vll_vll_import(char **s, t_vll *ret, char *delim, int opts)
{
	t_vll		*l;
	t_vll_node	*n;

	n = NULL;
	while (**s && **s != delim[1])
	{
		l = import(s, delim, opts);
		n = vll_add_front(ret, n, l, 0);
		skip_whitespace(s);
		++(*s);
	}
}

static void		data_import(char **s, t_vll *ret, char *delim, int opts)
{
	char		*s1;
	t_vll_node	*n;

	n = NULL;
	while (**s && **s != delim[1])
	{
		skip_whitespace(s);
		++(*s);
		s1 = *s;
		while (**s && **s != delim[3])
			++(*s);
		n = vll_add_front(ret, n, s1, *s - s1);
		if (opts & VLL_IMPORT_STR)
			vect_mset_end(n->p, '\0', 1);
		++(*s);
		skip_whitespace(s);
	}
}

t_vll			*import(char **s, char *delim, int opts)
{
	t_vll		*ret;

	skip_whitespace(s);
	++(*s);
	skip_whitespace(s);
	ret = vll_new();
#if (VLL_VLL)
	if (**s == delim[0])
	{
		ret->vll_vll = 1;
		vll_vll_import(s, ret, delim, opts);
		return (ret);
	}
#endif
	data_import(s, ret, delim, opts);
	return (ret);
}

t_vll			*vll_import(char *s, char *delim, int opts)
{
	return (import(&s, delim, opts));
}
