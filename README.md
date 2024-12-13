# 📜 **get_next_line**  

<p align="center">
  <img src="https://github.com/mbah24-dev/mbah24-dev/blob/main/42_badges/get_next_linee.png" alt="GNL 42 project badge"/>
</p>

Bienvenue dans le dépôt **get_next_line**, une implémentation élégante et robuste de la fonction `get_next_line` 🧵. Ce projet est un incontournable de l'école 42, conçu pour lire ligne par ligne depuis un fichier ou une entrée standard. 🌟

---

## 🛠️ **Fonctionnalités**
- 📄 Lecture ligne par ligne à partir d'un descripteur de fichier.
- 💾 Gestion optimisée de la mémoire avec un **buffer** configurable.
- 🚀 Compatibilité avec des fichiers, des sockets ou l'entrée standard.
- 🔄 Rappelable pour continuer la lecture d'où elle s'était arrêtée.

---

## 🚧 **Prototype**

```c
char *get_next_line(int fd);
```
---
## 🌟 Exemple d’utilisation

Voici un exemple simple pour illustrer l’utilisation de **get_next_line** ! 🎉

```c
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
```
 
## 🌈 À propos de l'auteur

👨‍💻 Ce projet a été réalisé dans le cadre des cursus **42** par [mbah] ❤️. Toujours prêt à répondre à vos questions ! 🎉

🎉 **Merci d’avoir lu ce README !** Prends du plaisir à coder **get_next_line** et que la mémoire soit avec toi. 💾🔥

