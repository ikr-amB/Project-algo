#wordle en C


**Descreption**

Ce projet implémente une version console du jeu **Wordle** ainsi qu’un **solveur algorithmique avancé** en langage C.

**Objectif**


L’objectif est de deviner le mot secret en un minimum d’essais, en utilisant les indices fournis après chaque tentative.


**Fonctionnalités techniques**

-Chargement et indexation d’un dictionnaire de mots de cinq lettres via un fichier texte.
-Validation des entrées utilisateur et normalisation des chaînes (longueur, caractères valides).
-Algorithme d’évaluation des tentatives, générant un retour codé :

        -🟩 = position correcte

        -🟨 = lettre présente

        -⬛ = lettre absente
        
-Solveur automatique basé sur:

        -Filtrage successif du dictionnaire selon les feedbacks.
        
        -Calcul de probabilités ou de fréquences des lettres.
        
        -Sélection du “meilleur” mot pour maximiser l’information.
        
-Architecture modulaire (fichiers séparés : gestion dictionnaire, logique du jeu, solveur, I/O).

-Documentation et commentaires suivant les bonnes pratiques (prototypes, organisation claire, fonctions courtes).

**Prérequis**

-Compilateur C (ex : gcc)

-Système compatible avec les applications console

-Fichier dictionnaire (Words.txt) contenant les mots de 5 lettres

**Compilation**


**Utilisation**


***^mode joueur***


./wordle       # sur Linux/Mac

wordle.exe     # sur Windows

-Entrez une tentative de 5 lettres.

-Le programme fournit un retour visuel (🟩, 🟨, ⬛).

-Continuez jusqu’à deviner le mot ou épuiser les essais(6 tentatives).


 ***^mode solveur automatique***


./wordle auto      # sur Linux/Mac

wordle.exe auto    # sur Windows

-Le solveur propose automatiquement des mots, filtre le dictionnaire et trouve le mot secret en un minimum d’essais.

**Exemple d'exécution**

Entrez un mot de 5 lettres: MAISON


M ⬛ A 🟨 I 🟩 S ⬛ O ⬛ N ⬛

**Captures d'écran**


## Auteur

**Aicha Gharbi-IKRAM BOUTINE -LYNA BOUSSBAA**  
Développeuses en C et passionnée par les projets ludiques et éducatifs.
