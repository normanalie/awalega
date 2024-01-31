#include "ascii_art.h"



void showMenu(void) {

    printf("********************************************************\n");
    printf("*                 _                _                   *\n");
    printf("*                / \\__      ____ _| | ___              *\n");
    printf("*               / _ \\ \\ /\\ / / _` | |/ _ \\             *\n");
    printf("*              / ___ \\ V  V / (_| | |  __/             *\n");
    printf("*             /_/   \\_\\_/\\_/ \\__,_|_|\\___|    v0.0.1   *\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*   1. Jouer                                           *\n");
    printf("*                                                      *\n");
    printf("*   2. Meilleurs scores                                *\n");
    printf("*                                                      *\n");
    printf("*   ((3. Aide / A propos))                             *\n");
    printf("*                                                      *\n");
    printf("*   4. Quitter                                         *\n");
    printf("*                                                      *\n");
    printf("*                                 Test & Co. (c) 2024  *\n");
    printf("*                                                      *\n");
    printf("********************************************************\n");

    return;
}


void showScoreSectionMenuSelection(GameStatusVar * GameStatus) {

    char answer = 0;

    if (GameStatus->isGameJustEnded) {   // Si une partie vient de finir, donner la possibilité de revenir au menu ou relancer une partie

        do {
            printf("What do you wanna do ?\n");
            scanf(" %c", &answer);
        } while (answer != 'x' && answer != 'r');

        if (answer == 'x') {
            GameStatus->selectedMenu = SECTION_HOME;
        } else {
            GameStatus->selectedMenu  = SECTION_GAME;
        }

        GameStatus->isGameJustEnded = 0;

    } else {

        do {
            printf("Type %c to quit:\n", 'x');
            scanf(" %c", &answer);
        } while (answer != 'x');

        GameStatus->selectedMenu = SECTION_HOME;  // Seule possibilité = Retour au menu
    }

    return;
}


void showGameTable(PlayerInfo P1, PlayerInfo P2, GameStatusVar GameStatus) {

    int i;

    printf("[x] Retour au menu\n");
    printf("\n");

    printf(".----");
    for (i = 0; i < HOLES_PER_PLAYER; i++) {
        printf(".----");
    }
    printf(".\n");

    printf("|    |");
    for (i = 0; i < HOLES_PER_PLAYER; i++) {
        printf(" %.2d |", i+1);
    }
    printf("\n");

    printf(":----");
    for (i = 0; i < HOLES_PER_PLAYER; i++) {
        printf("+----");
    }
    printf(":\n");

    printf("| P2 |");
    for (i = 0; i < HOLES_PER_PLAYER; i++) {
        printf(" %.2d |", P2.seeds[i]);
    }
    printf("\n");
    
    printf(":----");
    for (i = 0; i < HOLES_PER_PLAYER; i++) {
        printf("+----");
    }
    printf(":\n");

    printf("| P1 |");
    for (i = 0; i < HOLES_PER_PLAYER; i++) {
        printf(" %.2d |", P1.seeds[i]);
    }
    printf("\n");

    printf("'----");
    for (i = 0; i < HOLES_PER_PLAYER; i++) {
        printf("'----");
    }
    printf("'\n");
    
    printf("\n");

    printf("Nbr de coups total : %d\n", GameStatus.totalMoves);
    printf("Coups avant arrêt : %d\n", GameStatus.moveCountdown);
    printf("[%s] Graines ramassees: %.2d | Nbr de coups: %.3d  {#}  [%s] Graines ramassees: %.2d | Nbr de coups: %.3d\n", P1.name, P1.harvestedSeeds, P1.moves, P2.name, P2.harvestedSeeds, P2.moves);

    return;
}


void showScore(void) {

    PlayerScore RecordedScores[5];
    readScores(RecordedScores);

    int i;

    printf("********************************************************\n");
    printf("*    [x] Retour au Menu Principal                      *\n");
    printf("*     _  _ ___ ___ _  _   ___  ___ ___  ___ ___ ___    *\n");
    printf("*    | || |_ _/ __| || | / __|/ __/ _ \\| _ \\ __/ __|   *\n");
    printf("*    | __ || | (_ | __ | \\__ \\ (_| (_) |   / _|\\__ \\   *\n");
    printf("*    |_||_|___\\___|_||_| |___/\\___\\___/|_|_\\___|___/   *\n");
    printf("*                                                      *\n");
    printf("*       NOM :            SCORE :            COUPS :    *\n");

    for (i=0; i < 5; i++) {

        if (strlen(RecordedScores[i].name) < 5) {
            do {
                strcat(RecordedScores[i].name, " ");
            } while (strlen(RecordedScores[i].name) < 5);
        }

        printf("*                                                      *\n");
        printf("*   #%d %s             %.5d              %.5d      *\n", i+1, RecordedScores[i].name, RecordedScores[i].score, RecordedScores[i].moves);
    }

    printf("*                                                      *\n");
    printf("********************************************************\n");
    
    return;
}


void showAboutGame(void) {
    
    printf("********************************************************\n");
    printf("*                                                      *\n");
    printf("*   _  _     _          __    _   _              _     *\n");
    printf("*  | || |___| |_ __    / /   /_\\ | |__  ___ _  _| |_   *\n");
    printf("*  | __ / -_) | '_ \\  / /   / _ \\| '_ \\/ _ \\ || |  _|  *\n");
    printf("*  |_||_\\___|_| .__/ /_/   /_/ \\_\\_.__/\\___/\\_,_|\\__|  *\n");
    printf("*             |_|                                      *\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*   > [REGLES DU JEU] <                                *\n");
    printf("*   |                                                  *\n");
    printf("*   => BLABLA                                          *\n");
    printf("*   |  BLABLABLABLABLABLABLABLABLABLABLABLABLABLA      *\n");
    printf("*   |  BLABLABLABLABLABLABLABLABLABLABLABLABLABLA      *\n");
    printf("*   |  BLABLABLABLABLABLABLABLABLABLABLABLABLABLA      *\n");
    printf("*   |  BLABLABLABLABLABLABLABLABLABLABLABLABLABLA      *\n");
    printf("*   => ZAZA 2                                          *\n");
    printf("*   |  ZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZA    *\n");
    printf("*   |  ZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZA    *\n");
    printf("*   |_ ZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZAZA    *\n");
    printf("*                                                      *\n");
    printf("*   > [COMMENT JOUER ?] <                              *\n");
    printf("*   |                                                  *\n");
    printf("*   => TOUTOU                                          *\n");
    printf("*   |  A (AAAA), A (AAA), A (AAAAAA), A (AAAAAA)       *\n");
    printf("*   => TATA :                                          *\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*      Un jeu développé par : Test & Co. (c) 2024      *\n");
    printf("*                                                      *\n");
    printf("*                                    Version : 0.0.1   *\n");
    printf("*                                                      *\n");
    printf("********************************************************\n");

    char answer = 0;

    do {
        printf("Type %c to quit:\n", 'x');
        scanf(" %c", &answer);
    } while (answer != 'x');

    return;
}


void showByeBye(void) {
  
    printf("********************************************************\n");
    printf("*                 _                _                   *\n");
    printf("*                / \\__      ____ _| | ___              *\n");
    printf("*               / _ \\ \\ /\\ / / _` | |/ _ \\             *\n");
    printf("*              / ___ \\ V  V / (_| | |  __/             *\n");
    printf("*             /_/   \\_\\_/\\_/ \\__,_|_|\\___|    v0.0.1   *\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*       _           ____                 _        _    *\n");
    printf("*      / \\  _   _  |  _ \\ _____   _____ (_)_ __  | |   *\n");
    printf("*     / _ \\| | | | | |_) / _ \\ \\ / / _ \\| | '__| | |   *\n");
    printf("*    / ___ \\ |_| | |  _ <  __/\\ V / (_) | | |    |_|   *\n");
    printf("*   /_/   \\_\\__,_| |_| \\_\\___| \\_/ \\___/|_|_|    (_)   *\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*                                 Test & Co. (c) 2024  *\n");
    printf("*                                                      *\n");
    printf("********************************************************\n");

  return;
}
