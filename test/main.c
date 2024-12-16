/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:20:03 by mbah              #+#    #+#             */
/*   Updated: 2024/12/15 15:20:24 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "../get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	printf("---------------------------\nBUFFER_SIZE\t=\t%llu\n---------------------------\n", (unsigned long long int)BUFFER_SIZE);
	printf("---------------------------\nINT_MAX\t\t=\t%d\nLONG_MAX\t=\t%ld\nLL_MAX\t\t=\t%lld\nULL_MAX\t\t=\t%llu\n---------------------------\n", INT_MAX, LONG_MAX, LLONG_MAX, ULLONG_MAX);
	if (argc != 2)
	{
		printf("Pas de fichier a lire.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Fichier impossible a lire.\n");
		return (0);
	}
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../get_next_line_bonus.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s file1 ...\n", argv[0]);
        return (1);
    }

    int fds[argc - 1];
    char *line;
    int finished = 0;
    int i;

    // Ouvrir les fichiers
    for (i = 1; i < argc; i++) {
        fds[i - 1] = open(argv[i], O_RDONLY);
        if (fds[i - 1] < 0) {
            perror("Error opening file");
            return (1);
        }
    }

    printf("Reading files simultaneously:\n");
    while (!finished) {
        finished = 1;
        for (i = 0; i < argc - 1; i++) {
            if (fds[i] != -1) { // Si le fichier n'est pas encore terminé
                line = get_next_line(fds[i]);
                if (line) {
                    printf("File %d: %s", i + 1, line);
                    free(line);
                    finished = 0;
                } else {
                    close(fds[i]);
                    fds[i] = -1; 
                }
            }
        }
    }

    printf("Done reading all files.\n");
    return (0);
}
