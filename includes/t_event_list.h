/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_event_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 23:20:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/08/05 23:21:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EVENT_LIST_H
# define T_EVENT_LIST_H

typedef struct s_event_list	t_event_list;

struct	s_event_list
{
	int		mask;
	int		(*hook)();
	void	*param;
};

#endif
