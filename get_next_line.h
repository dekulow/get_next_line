/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dekulow <dekulow@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:30:33 by dekulow           #+#    #+#             */
/*   Updated: 2024/01/26 11:34:37 by dekulow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

// --- REMOVE OR COMMENT --- //
//# include <stdio.h>
//# include <fcntl.h>
// --- REMOVE OR COMMENT --- //

char	*get_next_line(int fd);

#endif
