#include "awale_game.h"


void initPlayers(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar GameStatus)
{
    // Init Score & Graines
    int i;
    for (i = 0; i < HOLES_PER_PLAYER; i++)
    {
        P1->seeds[i] = SEEDS_PER_HOLE;
        P2->seeds[i] = SEEDS_PER_HOLE;
    }

    memset(P1->name, 0, NAME_MAX_LEN);
    P1->harvestedSeeds = 0;
    P1->moves = 0;
    memset(P2->name, 0, NAME_MAX_LEN);
    P2->harvestedSeeds = 0;
    P2->moves = 0;

    return;
}

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

int isActionValid(PlayerInfo Player, GameStatusVar GameStatus)
{

    if (GameStatus.validHoles[GameStatus.selectedHole - 1] == 0)
    {
        if (!Player.isBot)
        {
            printf("[%s] Action impossible! Une graine du trou %d n'arrivera pas jusqu'à un trou du joueur adverse!\n", Player.name, GameStatus.selectedHole);
        }
        return 0;
    }

    if (GameStatus.selectedHole < 1 || GameStatus.selectedHole > HOLES_PER_PLAYER)
    {

        if (!Player.isBot)
        {
            printf("[%s] Action impossible! Le trou %d n'existe pas!\n", Player.name, GameStatus.selectedHole);
        }
        return 0;
    }


    else if (Player.seeds[GameStatus.selectedHole - 1] == 0)
    {

        if (!Player.isBot)
        {
            printf("[%s] Action impossible! Ton trou %d est vide\n", Player.name, GameStatus.selectedHole);
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

void whoWon(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar *GameStatus)
{

    if (P1->harvestedSeeds > P2->harvestedSeeds)
    {
        printf("%s a gangé !\n", P1->name);
        GameStatus->winner = P1;
    }
    else if (P1->harvestedSeeds < P2->harvestedSeeds)
    {
        printf("%s a gangé !\n", P1->name);
        GameStatus->winner = P2;
    }
    else
    {
        if (P1->moves < P2->moves)
        {
            printf("%s a gangé !\n", P1->name);
            GameStatus->winner = P1;
        }
        else if (P1->moves > P2->moves)
        {
            printf("%s a gangé !\n", P1->name);
            GameStatus->winner = P2;
        }
        else
        {
            printf("Ex Aequo !\n");
            GameStatus->winner = NULL;
        }
    }

    return;
}

void endgameManager(GameStatusVar *GameStatus)
{

    switch (GameStatus->endgameType)
    {

    case ENDGAME_SEED_COUNT: // Un jouer à ramassé assez de graine pour gagner
        printf("[END 1] Le joueur \"%s\" a gagné!\n", GameStatus->endingPlayer->name);
        GameStatus->selectedMenu = SECTION_SCORE;
        break;

    case ENDGAME_MOVE_LIMIT: // Pas de récolte sur les 20 derniers coups
        printf("[END 2] Pas de récolte faite sur les %d derniers coups!\n", MOVES_BEFORE_STOP);
        GameStatus->selectedMenu = SECTION_SCORE;
        break;

    case ENDGAME_NO_SEEDS_TO_MOVE: // Un joueur ne peux pas remplir les cases vides d'un joueur adverse
        printf("[END 3] Le joueur \"%s\" ne peux pas remplir les cases vides du joueur adverse!\n", GameStatus->endingPlayer->name);
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

void playMove(PlayerInfo *P1, PlayerInfo *P2, GameStatusVar *GameStatus)
{

    PlayerInfo *pCurrentPlayer;

    if (GameStatus->playerTurn == 1)
    {
        pCurrentPlayer = P1;
    }
    else
    {
        pCurrentPlayer = P2;
    }

    if (!isActionValid(*pCurrentPlayer, *GameStatus))
    {
        return;
    }

    // Attendre quelques instants pour donner le temps à J1 de voir le résultat lorsqu'il joue contre le bot
    waitBeforeBotPlay(*P2, *GameStatus);

    // Sélection du trou à jouer & Vérification de la légalité
    // holeSelector(P1, P2, &GameStatus);
    GameStatus->totalMoves++;
    GameStatus->moveCountdown--;

    // Sauvegardes de l'ancien nombre de graine pour voir s'il faut réinit "TotalMoves"
    int oldP1Seeds = P1->harvestedSeeds;
    int oldP2Seeds = P2->harvestedSeeds;

    // Déplacement des graines dans le bon sens
    sowAndHarvestSeeds(P1, P2, *GameStatus);

    // Vérifier si les scores ont changés pour réinitialiser le compteur
    if (hasNumberHarvestedSeedsChanged(*P1, *P2, oldP1Seeds, oldP2Seeds))
    {
        GameStatus->moveCountdown = MOVES_BEFORE_STOP;
    }

    // Vérification condition de fin du jeu
    if (P1->harvestedSeeds >= SEEDS_TO_WIN || P2->harvestedSeeds >= SEEDS_TO_WIN)
    { // 1 : Si l'un des joueur a plus de la moitié des graines
        GameStatus->endgameType = ENDGAME_SEED_COUNT;

        if (P1->harvestedSeeds >= SEEDS_TO_WIN)
        {
            GameStatus->endingPlayer = P1;
        }
        else
        {
            GameStatus->endingPlayer = P2;
        }
    }
    else if (GameStatus->moveCountdown == 0)
    { // 2 : Pas de récolte sur les 20 derniers coups
        GameStatus->endgameType = ENDGAME_MOVE_LIMIT;
        GameStatus->endingPlayer = P1; // Pour éviter de renvoyer un pointeur "NULL" à la fonction "endgameManager()" un peu plus bas
    }
    else
    { // 3 : Un joueur peut (ou peut pas) remplir les cases vides d'un joueur adverse

        int validHoles[HOLES_PER_PLAYER] = {0}; // Au cas où on veut forcer un joueur à jouer sur des cases spécifiques pour remplir les trous de l'adversaire
        PlayerInfo *selectedUser = NULL;

        if (areEveryHolesEmpty(*P1))
        {
            if (canPlayerFillEmptyHoles(*P2, 2, validHoles))
            {
                selectedUser = P2;
                GameStatus->playerTurn = 2;
            }
            else
            {
                GameStatus->endgameType = ENDGAME_NO_SEEDS_TO_MOVE;
                GameStatus->endingPlayer = P2;
            }
        }
        else if (areEveryHolesEmpty(*P2))
        {
            if (canPlayerFillEmptyHoles(*P1, 1, validHoles))
            {
                selectedUser = P1;
                GameStatus->playerTurn = 1;
            }
            else
            {
                GameStatus->endgameType = ENDGAME_NO_SEEDS_TO_MOVE;
                GameStatus->endingPlayer = P1;
            }
        }

        for (int i=0; i< HOLES_PER_PLAYER; i++) {
            GameStatus->validHoles[i] = validHoles[i]; 
        }

        if (selectedUser == NULL)
        {
            switchPlayer(GameStatus);

            for (int i = 0; i < HOLES_PER_PLAYER; i++)
            {
                GameStatus->validHoles[i] = 1;
            }
        }
    }

    return;
}