#include "awale_game.h"

// Menu
int menuSelector(void)
{

    int userInput;
    int validChoice = 0;

    do
    {

        printf("Select what you want :\n");
        scanf("%d", &userInput);

        switch (userInput)
        {
        case SECTION_GAME:        // Jouer
        case SECTION_SCORE:       // Meilleur Score
        case SECTION_ABOUT:       // Aide / A propos
        case SECTION_EXIT_SCREEN: // Quitter
            validChoice = 1;
            break;
        }

    } while (validChoice == 0);

    return userInput;
}

//  Game Init
int gameModeSelector(void)
{

    int gameMode;

    do
    {
        printf("Select what you want :\n      - 1. PvBot\n      - 2. PvP\n");
        scanf(" %d", &gameMode);
    } while (gameMode != 1 && gameMode != 2);

    return gameMode;
}

void initPlayers(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar GameStatus)
{

    char userAnswer;
    char playerName[500];

    if (GameStatus.gameMode == 1)
    { // PvBot

        // Joueur 1
        do
        {
            printf("\n> [Joueur 1] Pour enregistrer ton score, entres ton nom (3 caract. MIN / 5 caract. MAX.) : ");
            scanf(" %s", playerName);
        } while (strlen(playerName) < 3 || strlen(playerName) > 5);

        strcpy(P1->name, playerName);
        P1->isBot = 0;

        // Bot
        strcpy(P2->name, "Bot");

        do
        {
            printf("\nSelect Bot difficulty :\n      - 1. Easy\n      - 2. Hard (Unused)\n");
            scanf(" %c", &userAnswer);
        } while (userAnswer != '1' /*&& userAnswer != '2'*/);

        if (userAnswer == '1')
        {
            P2->isBot = 1;
        }
        else
        {
            P2->isBot = 2;
        }
    }
    else
    { // PvP

        // Joueur 1
        do
        {
            printf("\n> [Joueur 1] Pour enregistrer ton score, entres ton nom (3 caract. MIN / 5 caract. MAX.) : ");
            scanf(" %s", playerName);
        } while (strlen(playerName) < 3 || strlen(playerName) > 5);

        strcpy(P1->name, playerName);
        P1->isBot = 0;

        // Joueur 2
        do
        {
            printf("\n> [Joueur 2] Pour enregistrer ton score, entres ton nom (3 caract. MIN / 5 caract. MAX.) : ");
            scanf(" %s", playerName);
        } while (strlen(playerName) < 3 || strlen(playerName) > 5);

        strcpy(P2->name, playerName);
        P1->isBot = 0;
    }

    // Init Score & Graines
    int i;
    for (i = 0; i < HOLES_PER_PLAYER; i++)
    {
        P1->seeds[i] = SEEDS_PER_HOLE;
        P2->seeds[i] = SEEDS_PER_HOLE;
    }

    P1->harvestedSeeds = 0;
    P1->moves = 0;
    P2->harvestedSeeds = 0;
    P2->moves = 0;

    return;
}

// Game
void switchPlayer(GameStatusVar *GameStatus)
{

    if (GameStatus->playerTurn == 1)
    {
        GameStatus->playerTurn = 2;
    }
    else
    {
        GameStatus->playerTurn = 1;
    }

    return;
}

void waitBeforeBotPlay(PlayerInfo P2, GameStatusVar GameStatus)
{

    if (P2.isBot && GameStatus.playerTurn == 2)
    {
        sleep(WAIT_UNTIL_BOT_PLAYS);
    }

    return;
}

void holeSelector(PlayerInfo P1, PlayerInfo P2, GameStatusVar *GameStatus)
{

    int selectedHole;

    if (GameStatus->playerTurn == 1)
    { // Si c'est J1
        do
        {
            printf("\n> [%s] Choisi une case que tu veux jouer :\n", P1.name);
            scanf(" %d", &selectedHole);
        } while (isActionValid(P1, selectedHole) == 0);
    }
    else
    { // Si c'est J2

        if (!P2.isBot)
        { // Humain
            do
            {
                printf("\n> [%s] Choisi une case que tu veux jouer :\n", P2.name);
                scanf(" %d", &selectedHole);
            } while (isActionValid(P2, selectedHole) == 0);
        }
        else
        { // Bot

            if (P2.isBot == 1)
            { // Bot facile
                do
                {
                    selectedHole = randInt(1, HOLES_PER_PLAYER);
                } while (isActionValid(P2, selectedHole) == 0);
            }
        }
    }

    GameStatus->selectedHole = selectedHole;

    return;
}

int isActionValid(PlayerInfo Player, int selectedHole)
{

    if (selectedHole < 1 || selectedHole > HOLES_PER_PLAYER)
    {

        if (!Player.isBot)
        {
            printf("[%s] Action impossible! Le trou %d n'existe pas!\n", Player.name, selectedHole);
        }
        return 0;
    }
    else if (Player.seeds[selectedHole - 1] == 0)
    {

        if (!Player.isBot)
        {
            printf("[%s] Action impossible! Ton trou %d est vide\n", Player.name, selectedHole);
        }
        return 0;
    }

    return 1;
}

void sowAndHarvestSeeds(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar GameStatus)
{

    PlayerInfo *currentPlayer;

    if (GameStatus.playerTurn == 1)
    {
        currentPlayer = P1;
    }
    else
    {
        currentPlayer = P2;
    }

    int originalHole = GameStatus.selectedHole - 1;
    int seedsToSow = currentPlayer->seeds[originalHole];
    PlayerInfo *seedOwner = currentPlayer;
    int currentHole = originalHole;

    do
    {

        if (currentPlayer == P1)
        { // Si c'est le Joueur 1

            if (currentHole == HOLES_PER_PLAYER - 1)
            {
                currentPlayer = P2;
                currentHole++; // Créer un débordement pour revenir à la valeur normale
            }
            else
            {
                currentHole++;
                if (currentPlayer == seedOwner && currentHole == originalHole)
                    continue;

                P1->seeds[currentHole] += 1;
                seedsToSow--;
            }
        }
        else
        { // Si c'est le Joueur 2

            if (currentHole == 0)
            {
                currentPlayer = P1;
                currentHole--; // Idem ici pour le débordement
            }
            else
            {
                currentHole--;
                if (currentPlayer == seedOwner && currentHole == originalHole)
                    continue;

                P2->seeds[currentHole] += 1;
                seedsToSow--;
            }
        }

    } while (seedsToSow != 0);

    seedOwner->seeds[originalHole] = 0; // Vider les graines du trou d'origine des graines
    seedOwner->moves += 1;              // Rajouter un coup à celui qui à jouer

    if (currentPlayer != seedOwner)
    {
        if (currentPlayer->seeds[currentHole] == REQUIRED_FOR_HARVESTING_1 || currentPlayer->seeds[currentHole] == REQUIRED_FOR_HARVESTING_2)
        {

            seedOwner->harvestedSeeds += currentPlayer->seeds[currentHole];
            currentPlayer->seeds[currentHole] = 0;
        }
    }
}

int hasNumberHarvestedSeedsChanged(PlayerInfo P1, PlayerInfo P2, int oldP1Seeds, int oldP2Seeds)
{

    if (P1.harvestedSeeds != oldP1Seeds || P2.harvestedSeeds != oldP2Seeds)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int areEveryHolesEmpty(PlayerInfo Player)
{

    int i;
    int emptyHoles = 0;

    for (i = 0; i < HOLES_PER_PLAYER; i++)
    {

        if (Player.seeds[i] == 0)
        {
            emptyHoles++;
        }
    }

    if (emptyHoles == HOLES_PER_PLAYER)
    {
        return 1; // FCT () qui vérifie s'il y a la possibilité que le joueur adverse puisse mettre au moins 1 graine pour J1
    }
    else
    {
        return 0;
    }
}

int canPlayerFillEmptyHoles(PlayerInfo Player, int playerTurn, int validHoles[])
{

    int i;
    int canPlayerFill = 0;

    for (i = 0; i < HOLES_PER_PLAYER; i++)
    {

        int seedsInHole = Player.seeds[i];
        int holePosition = i;

        while (seedsInHole > 0 && (holePosition > -1 && holePosition < 7))
        {

            seedsInHole--;

            if (playerTurn == 1)
            {
                holePosition++;
            }
            else
            {
                holePosition--;
            }
        }

        if (holePosition < 0 || holePosition > HOLES_PER_PLAYER - 1)
        { // Si le nombre de trou es dépassé, ça veut dire qu'il peut remplir
            validHoles[i] = 1;
            canPlayerFill = 1;
        }
    }

    if (canPlayerFill)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void forcePlayerToPlay(PlayerInfo Player, int validHoles[], GameStatusVar *GameStatus)
{ // Retourne le trou choisi pour jouer

    int selectedHole;

    if (!Player.isBot)
    { // Si c'est un vrai joueur
        do
        {
            printf("\n> [%s] Les trou de ton adversaire sont vides. Choisi une case qui peut remplir ses trous :\n", Player.name);
            scanf(" %d", &selectedHole);
        } while (isForcedActionValid(Player, selectedHole, validHoles) == 0);
    }
    else
    { // Si c'est un bot

        if (Player.isBot == 1)
        { // Bot facile
            do
            {
                selectedHole = randInt(1, HOLES_PER_PLAYER);
            } while (isForcedActionValid(Player, selectedHole, validHoles) == 0);
        }
    }

    GameStatus->selectedHole = selectedHole;

    return;
}

int isForcedActionValid(PlayerInfo Player, int selectedHole, int validHoles[])
{ // Vérifie si l'action forcée est valide

    if (selectedHole < 1 || selectedHole > HOLES_PER_PLAYER)
    {

        if (!Player.isBot)
        {
            printf("[%s] Action impossible! Le trou %d n'existe pas!\n", Player.name, selectedHole);
        }
        return 0;
    }
    else if (validHoles[selectedHole - 1] == 0)
    {

        if (!Player.isBot)
        {
            printf("[%s] Action impossible! Une graine du trou %d n'arrivera pas jusqu'à un trou du joueur adverse!\n", Player.name, selectedHole);
        }
        return 0;
    }

    return 1;
}

void endgameManager(GameStatusVar *GameStatus, PlayerInfo endingPlayer)
{

    switch (GameStatus->endgameType)
    {

    case ENDGAME_SEED_COUNT: // Un jouer à ramassé assez de graine pour gagner
        printf("[END 1] Le joueur \"%s\" a gagné!\n", endingPlayer.name);
        GameStatus->selectedMenu = SECTION_SCORE;
        break;

    case ENDGAME_MOVE_LIMIT: // Pas de récolte sur les 20 derniers coups
        printf("[END 2] Pas de récolte faite sur les %d derniers coups!\n", MOVES_BEFORE_STOP);
        GameStatus->selectedMenu = SECTION_SCORE;
        break;

    case ENDGAME_NO_SEEDS_TO_MOVE: // Un joueur ne peux pas remplir les cases vides d'un joueur adverse
        printf("[END 3] Le joueur \"%s\" ne peux pas remplir les cases vides du joueur adverse!\n", endingPlayer.name);
        GameStatus->selectedMenu = SECTION_SCORE;
        break;

    case ENDGAME_FORCED: // Fin de partie forcée
        printf("[END 99] Fin de partie forcée!\n");
        GameStatus->selectedMenu = SECTION_HOME;
        break;
    }

    sleep(3);

    return;
}
