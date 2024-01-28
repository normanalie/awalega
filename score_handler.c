#include "score_handler.h"



void readScores(PlayerScore recordedScores[]) {
    
    FILE * f;

    char nameTMP[6];
    int scoreTMP;
    int movesTMP;
    
    f = fopen(SCORE_FILE_NAME, "r");   //// -> Extraction des scores du fichier

    int i;
    
    for (i=0; i < 5; i++) {
        fscanf(f, "%s %d %d", nameTMP, &scoreTMP, &movesTMP);
        strcpy(recordedScores[i].name, nameTMP);
        recordedScores[i].score = scoreTMP;
        recordedScores[i].moves = movesTMP;            
    }

    fclose(f);                        // <-

    return;
}


void saveScores (PlayerInfo P1, PlayerInfo P2) {

    PlayerScore recordedScores[7];
    readScores(recordedScores);

    // Enregistrement des scores des 2 joueurs dans la liste
    recordedScores[5].score = P1.harvestedSeeds;
    recordedScores[5].moves = P1.moves;  
    strcpy(recordedScores[5].name, P1.name); 

    if (!P2.isBot) {
        recordedScores[6].score = P2.harvestedSeeds;
        recordedScores[6].moves = P2.moves;  
        strcpy(recordedScores[6].name, P2.name);
    } else {
        recordedScores[6].score = 0;
        recordedScores[6].moves = 0;  
        strcpy(recordedScores[6].name, P2.name);
    }
    


    PlayerScore recordedScoreTMP;

    int i;
    int j;

    // Remettre les scores dans l'ordre par PAR POINTS
    for (i = 0; i < 7; ++i)  {         
        for (j = i + 1; j < 7; ++j) {

            if (recordedScores[i].score < recordedScores[j].score) {
                recordedScoreTMP = recordedScores[i];
                recordedScores[i] = recordedScores[j];
                recordedScores[j] = recordedScoreTMP;
            }
        }
    }


    // PUIS remettre les scores dans l'ordre par PAR COUPS
    for (i=0; i < 7; i++) {

        j = 0;
            
        while (recordedScores[i].score == recordedScores[i+1].score && i < 7) {
            j++;
            i++;
        }

        if (j) {

            int k;
            int l;

            for (k = i-j; k < i+1; ++k)  {         //// Remetre les scores dans l'ordre par PAR POINTS & PAR COUPS
                for (l = k + 1; l < i+1; ++l) {

                    if (recordedScores[k].moves > recordedScores[l].moves) {
                        recordedScoreTMP = recordedScores[k];
                        recordedScores[k] = recordedScores[l];
                        recordedScores[l] = recordedScoreTMP;
                    }
                }
            }
        }
    }


    FILE * f;

    f = fopen(SCORE_FILE_NAME, "w");     //// Mettre a jour les scores dans le ficher

    for (i=0; i < 5; i++) {
        fprintf(f, "%s %d %d\n", recordedScores[i].name, recordedScores[i].score, recordedScores[i].moves);
    }

    fclose(f);

    return;
} 
