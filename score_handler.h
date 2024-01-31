#ifndef SCORE_HANDLER
#define SCORE_HANDLER


#include <stdio.h>
#include <string.h>
#include "awale_game_macros_structs.h"

#define SCORE_FILE_NAME "highscores.txt"

// Pour la lecture / écriture des scores
typedef struct {   
    char name[6];
    int score;
    int moves;
} PlayerScore;

void readScores(PlayerScore RecordedScores[]);     // Ouvre le fichier qui contient les scores et enrigistre ses valeurs dans un tableau
void saveScores (PlayerInfo P1, PlayerInfo P2);    // Prend les nouveau scores après une fin de partie, trie les scores puis l'enregistre dans le fichier


#endif /* SCORE_HANDLER */
