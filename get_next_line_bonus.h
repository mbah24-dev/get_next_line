/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:46:54 by mbah              #+#    #+#             */
/*   Updated: 2024/12/09 20:03:12 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE >= 9223372036854775807
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

/* ================= (GNL) ================ */

char	*get_next_line(int fd);
void	read_line_from_file(int fd, char **stash, char **temp_buffer);
char	*parse_line_content(char **stash, char **line_data);
char	*extract_before_newline(const char *string);
char	*extract_after_newline(const char *string);

/* ================= (GNL UTILS) ================ */
int		has_new_line(const char *string);
char	*ft_strdup(const char *original_string);
char	*ft_strjoin(const char *first_string, const char *second_string);
void	*ft_mcalloc(size_t element_count, size_t element_size);
void	free_all(char **string1, char **string2, char **string3);

#endif