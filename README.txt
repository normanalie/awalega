==============================================================================================================================
|  Projet AWALEGA - Julian DOLOIR, Norman ALIE, Alexandre BAREI, Mathieu AKOUN, Souheila BENABID GUENDOUZI, Allan DUBERNARD  |
==============================================================================================================================



Comment compiler le projet ?
-----------------------------

1) Lancer "./depedencies.sh" dans le répertoire racine du projet afin d'avoir
   toutes les bibliothèques SDL2 nécessaires

2) Utiliser la commande "make" dans le répertoire racine du projet.

Après compilation, les dossiers suivants seront créés :
    - [build] : Contient tous les fichiers ".o"
    - [bin]  : Contient l'exécutable du projet



Comment lancer la simulation ?
-------------------------------

Utiliser la commande "./bin/awalega.out" dans le répertoire racine du projet
après avoir compilé le projet.



Comment supprimer les fichiers compilés si on n'en veut plus (*.o et l'exécutable "awalega.out") ?
-------------------------------------------------------------------------------------------------

Utiliser la commande "make clean" dans le répertoire racine du projet.

Les répertoires suivant, ainsi que leurs contenu, seront supprimés :
    - build
    - bin


Qu'est-ce que le dossier "audio_lib.unused" ?
---------------------------------------------

Ce répertoire contient un fichier .zip contenant toute la bibliothèque audio que nous avons faite.
Malheureusement, nous n'avons pas eu le temps de l'implémenter. Nous l'avons rajoutée quand même au cas
où, afin que vous puissiez voir ce qui a pu être fait dedans.