# Fichier README du projet Comparaison d'approches algorithmiques --- Général --- Version: 0.1 (2024-01-12)

  Ce projet a pour but de réaliser un prototype d'application, qui va pouvoir effectuer certaines modifications sur des images selon la demande des utilisateurs.

## Table des Matières

- [Lancement de l'application]
- [Fonctionnalités et leurs utilisations]

## Lancement de l'application

Pour lancer notre programme, il faut d'abord s'assurer que notre projet contient nos 3 fichiers qui sont :

- main.cpp
- project_I.cpp
- project_I.h

Lorsque vous exécuter le programme, il vous ai demandé "Souhaitez vous ouvrir un fichier ppm ou creer une image par vous meme ? Selectionnez 1 ou 2.". 
  -Si vous souhaitez effectuer une modification sur une image existante, entrer 1 sinon 2. Si vous avez entré 1, vous devez ensuite entré le nom d'un fichier qui existe en .ppm sinon créer en une avant d'éxécuter le programme.
  -Par contre, si vous entré 2, vous devez ensuite netrez le nombre de lignes et de colonnes de votre image et créé les composantes rouge, vert et bleu pour finaliser la création de l'image.
Pour finir le menu s'affiche, il vous suffit donc de saisir le numéro de la modification que vous souhaiter faire.
Si vous souhaitez mettre fin au programme, entrez le nombre 22.


## Fonctionnalités et leurs utilsations 

Liste des fonctionnalités du projet.

 -Tapez 1 pour passer l'image en noir et blanc.
 -Tapez 2 pour passer l'image en gris.
 -Tapez 3 pour passer l'image en rouge et noir.
 -Tapez 4 pour baisser la luminosité, puis saisissez un nombre entier entre 0 et 1.
 -Tapez 5 pour augmenter la luminosité, puis saisissez un nombre entier superieur a 1.
 -Tapez 6 pour baisser le contraste selon un facteur entier x.
 -Tapez 7 pour augmenter le contraste selon un facteur entier x.
 -Tapez 8 pour passer l'image en deuteranopie.
 -Tapez 9 pour passer l'image en protanopie.
 -Tapez 10 pour passer l'image en tritanopie.
 -Tapez 11 pour rogner l'image à gauche.
 -Tapez 12 pour rogner l'image à droite.
 -Tapez 13 pour rogner l'image en haut.
 -Tapez 14 pour rogner l'image en bas.
 -Tapez 15 pour la rotation de l'image vers la droite.
 -Tapez 16 pour la rotation de l'image vers la gauche.
 -Tapez 17 pour le retournement horizontal (symétrie d'axe vertical).
 -Tapez 18 pour le retournement vertical (symétrie d'axe horizontal).
 -Tapez 19 pour l'agrandissement de l'image selon un facteur entier x.
 -Tapez 20 pour le rétrécissement de l'image selon un facteur entier x.
 -Tapez 21 pour le flou de l'image, puis saisissez un nombre entier entre 1 et 3 pour appliquer divers effets de flou (G3, Gaussien, contourSobel).
 -Tapez 22 pour mettre fin au programme.

