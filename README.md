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
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne lue : %s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
 
## 🌈 À propos de l'auteur

👨‍💻 Ce projet a été réalisé dans le cadre des cursus **42** par [mbah] ❤️. Toujours prêt à répondre à vos questions ! 🎉

🎉 **Merci d’avoir lu ce README !** Prends du plaisir à coder **get_next_line** et que la mémoire soit avec toi. 💾🔥

