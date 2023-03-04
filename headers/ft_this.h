/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_this.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/04 00:51:41 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THIS_H
# define FT_THIS_H

typedef struct s_array		t_array;
typedef struct s_hasmap		t_hashmap;
typedef struct s_object		t_object;

typedef struct s_this
{
	t_array			*array;
	t_hashmap		*hashmap;
	t_object		*object;
}	t_this;

//						this
t_this					*fthis(void);

#endif
