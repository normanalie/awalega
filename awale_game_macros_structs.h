#ifndef AWALE_GAME_MACROS_STRUCTS
#define AWALE_GAME_MACROS_STRUCTS


// Macros Sections Jeu
#define SECTION_HOME 0           // Menu principal
#define SECTION_GAME 1           // Section de jeu
#define SECTION_SCORE 2          // Tableau des scores
#define SECTION_ABOUT 3          // Section "A propos & règles"
#define SECTION_EXIT_SCREEN 4    // Ecran de femreture du jeu
#define SECTION_EXIT 99          // Fermeture du jeu

// Paramètres Graines & Tablier
#define SEEDS_PER_HOLE 3
#define HOLES_PER_PLAYER 6
#define TOTAL_SEEDS (SEEDS_PER_HOLE * (HOLES_PER_PLAYER * 2))

// Paramètres récolte
#define REQUIRED_FOR_HARVESTING_1 2   // Nombre de graines qu'il faut dans le trou pour pouvoir récolter (Possibilité 1)
#define REQUIRED_FOR_HARVESTING_2 3   // Nombre de graines qu'il faut dans le trou pour pouvoir récolter (Possibilité 2)

// Paramètres Bot
#define WAIT_UNTIL_BOT_PLAYS 3        // Temps d'attente avant que le bot commence à jouer

// Paramètres Condition Fin Jeu
#define SEEDS_TO_WIN ((TOTAL_SEEDS / 2) + 1)    // Nombre de graines à obtenir afin de terminer une partie
#define MOVES_BEFORE_STOP 20                    // Nombre de voup sans récolte avant arrêt du jeu

// Type Fin Jeu
#define NO_ENDGAME 0                     // Partie non finie 
#define ENDGAME_SEED_COUNT 1             // Un jouer à ramassé  plus de la moitié des graines du jeu
#define ENDGAME_MOVE_LIMIT 2             // Pas de récolte sur les "MOVES_BEFORE_STOP" derniers coups
#define ENDGAME_NO_SEEDS_TO_MOVE 3       // Un joueur ne peux pas remplir les cases vides du joueur adverse
#define ENDGAME_FORCED 99                // Abandon d'une partie


// Variable de status du jeu
typedef struct {
    int selectedMenu;      // Menu dans lequel on se trouve
    int isGameJustEnded;   // Utile quand on a besoin de savoir si dans le menu des scores, on vient de sortir d'une partie ou non pour avoir la possibilité d'en relancer une 
    int gameMode;          // Mode de jeu dans lequel on se trouve
    int playerTurn;        // Tour actuel du joueur
    int selectedHole;      // Trou sélectionné à jouer
    int endgameType;       // Voir Macros "Endgame Types"
    int totalMoves;        // Nombre de coup totaux
    int moveCountdown;     // Décompte le nombre de coup avant l'arrêt du jeu
} GameStatusVar;

// Info Joueur
typedef struct {
    char name[5];
    int seeds[HOLES_PER_PLAYER];  // Nombre de graines en jeu par trou
    int harvestedSeeds;           // Nombre de graines ramassées
    int moves;                    // Nombre de coups réalisés
    int isBot;                    //  0 : Ce joueur n'est pas un bot || 1 : Est un bot (Facile) || (Unused) 2 : Est un bot (Difficile)
} PlayerInfo;


#endif /* AWALE_GAME_MACROS_STRUCTS */