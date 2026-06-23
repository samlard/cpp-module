# C++ Modules (42)

Ce dépôt regroupe mes exercices des modules C++ de 42 (de `cpp00` à `cpp09`).

## Structure

Le projet est organisé par module, puis par exercice :

- `cpp00/ex00`, `cpp00/ex01`
- `cpp01/ex00` à `cpp01/ex05`
- `cpp02/ex00` à `cpp02/ex02`
- `cpp03/ex00` à `cpp03/ex03`
- `cpp04/ex00` à `cpp04/ex02`
- `cpp05/ex00` à `cpp05/ex03`
- `cpp06/ex00` à `cpp06/ex02`
- `cpp07/ex00` à `cpp07/ex02`
- `cpp08/ex00` à `cpp08/ex02`
- `cpp09/ex00` à `cpp09/ex02`

Chaque exercice contient en général :

- un `Makefile`
- un dossier `src/`
- un dossier `include/` (selon l’exercice)

## Compilation

Depuis le dossier d’un exercice :

```bash
cd cppXX/exYY
make
```

Les `Makefile` utilisent `c++` avec les flags :

- `-Wall -Wextra -Werror -std=c++98`

## Exécution

Toujours depuis le dossier de l’exercice, lancez le binaire généré par le `Makefile` :

```bash
./<nom_du_binaire>
```

Le nom exact dépend de l’exercice (variable `NAME` dans chaque `Makefile`).

## Nettoyage

```bash
make clean
make fclean
make re
```

