***wordle en C***


## Descreption

*Ce projet implémente une version console du jeu **Wordle** ainsi qu’un **solveur algorithmique avancé** en langage C.*

## Objectif


*L’objectif est de deviner le mot secret en un minimum d’essais, en utilisant les indices fournis après chaque tentative.*


## Fonctionnalités techniques

*-Chargement et indexation d’un dictionnaire de mots de cinq lettres via un fichier texte.*


*-Validation des entrées utilisateur et normalisation des chaînes (longueur, caractères valides).*


*-Algorithme d’évaluation des tentatives, générant un retour codé :*

        -🟩 = lettre présente position correcte

        -🟨 = lettre présente position incorrecte

        -⬛ = lettre absente
        
*-Solveur automatique basé sur:*

        
*Le l’élimination progressive des mots impossibles*

*À chaque tentative :*

*-Le solver propose un mot (guess)*

*-Il reçoit un feedback Wordle (G, Y, _)*

*-Il compare ce feedback avec tous les mots du dictionnaire*

*-Il élimine tous les mots qui ne respectent pas ce feedback*

*-Il garde uniquement les mots compatibles*

*-Il recommence jusqu’à trouver le mot secret*

 ## Prérequis

*-Compilateur C (ex : gcc)*

*-Système compatible avec les applications console*

*-Fichier dictionnaire (Words.txt) contenant les mots de 5 lettres*



## Utilisation


***^mode joueur***


      ./wordle       # sur Linux/Mac
      wordle.exe     # sur Windows

*-Entrez une tentative de 5 lettres.*

*-Le programme fournit un retour visuel* (🟩, 🟨, ⬛).

*-Continuez jusqu’à deviner le mot ou épuiser les essais(6 tentatives).*


 ***^mode solveur automatique***


      ./wordle auto      # sur Linux/Mac
      wordle.exe auto    # sur Windows

*-Le solveur propose automatiquement des mots, filtre le dictionnaire et trouve le mot secret en un minimum d’essais.*


## Exemple de sortie wordle (6 essais)

*Entrez un mot de 5 lettres miniscule*

Essai 1: table  

t 🟨 a 🟩 b ⬛ l ⬛ e ⬛

Essai 2: carete  

c ⬛ a 🟩 r 🟩 t 🟩 e ⬛

Essai 3: parle  

p 🟩 a 🟩 r 🟩 l ⬛ e ⬛

Essai 4: parcs

p 🟩 a 🟩 r 🟩 c ⬛ h ⬛

Essai 5: parti 

p 🟩 a 🟩 r 🟩 t 🟩 y ⬛

Essai 6: parts

p 🟩 a 🟩 r 🟩 t 🟩 s 🟩  

Mot trouvé: parts

## Exemple de sortie solver 

===== WORD GUESS GAME =====

Tentative 1 : ARISE

Feedback    :  Y____

Tentative 2 : POINT

Feedback    :  G__GG

Tentative 3 : PLANT

🎉 Félicitations ! Mot trouvé !

## Captures d'écran
### Jeu Wordle (mode utilisateur)
<img width="977" height="599" alt="wordel" src="https://github.com/user-attachments/assets/1180bf79-1867-487e-a472-dcc9fba83ac1" />


### Solveur automatique
<img width="599" height="468" alt="Capture d&#39;écran 2025-12-19 222842" src="https://github.com/user-attachments/assets/01889cb4-e950-479d-85cf-e5052f9e1531" />


## Auteur

**GHARBI AICHA-IKRAM BOUTINE -LYNA TADJ EL BAHAA BOUSSBAA**  
*Développeuses en C et passionnée par les projets ludiques et éducatifs.*
