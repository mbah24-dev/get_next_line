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
- 🔢 Bonus : Lecture simultanée depuis plusieurs descripteurs de fichier et utilisation d'une seul variable static.
---

## ⚙️ Compilation

- Pour compiler ce projet get_next_line, utilisez la commande suivante :

```bash
compile >>>>>>>>
cc -Wall -Wextra -Werror -D BUFFER_SIZE=SIZE get_next_line_bonus.* get_next_line_utils_bonus.c test/main.c
Execute >>>>>>>>
./a.out test/file1.txt test/file2.txt test/file4.txt test/file6.txt 
Output  >>>>>>>>
Reading files simultaneously:
File 1: 01234567890123456789012345678901234567890
File 2: Alone
File 3: Squelette frileux
File 4: 42File 1: 1File 2: BY EDGAR ALLAN POE
File 3: le bruit sec des branches mortes
File 2: 
File 3: sous le manteau blanc
File 2: From childhood's hour I have not been
...
File 2: And the cloud that took the form
File 2: (When the rest of Heaven was blue)
File 2: Of a demon in my view-
Done reading all files.
```

- Remplacez SIZE par la taille de buffer souhaitée.
- Pour tester la version bonus (lecture depuis plusieurs descripteurs de fichier), compilez avec les fichiers *_bonus.c et get_next_line_bonus.h.


## 🚧 **Prototype**

```c
char *get_next_line(int fd);
```
---

## 📂 Structure des fichiers

- Le projet est composé des fichiers suivants :
- get_next_line.c : Contient l'implémentation principale de la fonction.
- get_next_line_utils.c : Fonctions auxiliaires pour la gestion de la mémoire et des chaînes de caractères.
- get_next_line_bonus.c et get_next_line_utils_bonus.c : Implémentation pour la version bonus.
- get_next_line.h : Prototype de la fonction principale.
- get_next_line_bonus.h : Header spécifique à la version bonus.
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
            if (fds[i] != -1) {
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

