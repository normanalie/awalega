#include "score_handler.h"



void readScores(PlayerScore RecordedScores[]) {
    
    FILE * f;

    char nameTMP[6];
    int scoreTMP;
    int movesTMP;
    
    f = fopen(SCORE_FILE_NAME, "r");   //// -> Extraction des scores du fichier

    int i;
    
    for (i=0; i < 5; i++) {
        fscanf(f, "%s %d %d", nameTMP, &scoreTMP, &movesTMP);
        strcpy(RecordedScores[i].name, nameTMP);
        RecordedScores[i].score = scoreTMP;
        RecordedScores[i].moves = movesTMP;            
    }

    fclose(f);                        // <-

    return;
}


void saveScores (PlayerInfo P1, PlayerInfo P2) {

    PlayerScore RecordedScores[7];
    readScores(RecordedScores);

    // Enregistrement des scores des 2 joueurs dans la liste
    RecordedScores[5].score = P1.harvestedSeeds;
    RecordedScores[5].moves = P1.moves;  
    strcpy(RecordedScores[5].name, P1.name); 

    if (!P2.isBot) {
        RecordedScores[6].score = P2.harvestedSeeds;
        RecordedScores[6].moves = P2.moves;  
        strcpy(RecordedScores[6].name, P2.name);
    } else {
        RecordedScores[6].score = 0;
        RecordedScores[6].moves = 0;  
        strcpy(RecordedScores[6].name, P2.name);
    }
    


    PlayerScore recordedScoreTMP;

    int i;
    int j;

    // Remettre les scores dans l'ordre par PAR POINTS
    for (i = 0; i < 7; ++i)  {         
        for (j = i + 1; j < 7; ++j) {

            if (RecordedScores[i].score < RecordedScores[j].score) {
                recordedScoreTMP = RecordedScores[i];
                RecordedScores[i] = RecordedScores[j];
                RecordedScores[j] = recordedScoreTMP;
            }
        }
    }


    // PUIS remettre les scores dans l'ordre par PAR COUPS
    for (i=0; i < 7; i++) {

        j = 0;
            
        while (RecordedScores[i].score == RecordedScores[i+1].score && i < 7) {
            j++;
            i++;
        }

        if (j) {

            int k;
            int l;

            for (k = i-j; k < i+1; ++k)  {         //// Remetre les scores dans l'ordre par PAR POINTS & PAR COUPS
                for (l = k + 1; l < i+1; ++l) {

                    if (RecordedScores[k].moves > RecordedScores[l].moves) {
                        recordedScoreTMP = RecordedScores[k];
                        RecordedScores[k] = RecordedScores[l];
                        RecordedScores[l] = recordedScoreTMP;
                    }
                }
            }
        }
    }


    FILE * f;

    f = fopen(SCORE_FILE_NAME, "w");     //// Mettre a jour les scores dans le ficher

    for (i=0; i < 5; i++) {
        fprintf(f, "%s %d %d\n", RecordedScores[i].name, RecordedScores[i].score, RecordedScores[i].moves);
    }

    fclose(f);

    return;
} 
