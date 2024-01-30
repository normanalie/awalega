#include "gui.h"

void showMenu(Image Images, Rectangle Rectangles){
    present_image(Images.background.menu, Rectangles.bg.menu);
    present_image(Images.button.play, Rectangles.button.play);
    present_image(Images.button.leaderboard, Rectangles.button.leaderboard);
    present_image(Images.button.about, Rectangles.button.about);
    present_image(Images.button.leave, Rectangles.button.leave);
}

void showAwale(Image Images, Rectangle Rectangles, PlayerInfo P1, PlayerInfo P2){
    present_image(Images.background.game, Rectangles.bg.game);
    present_image(Images.awale.deck, Rectangles.awale.deck);

    //Signs Players
    present_image(Images.misc.sign, Rectangles.awale.p1.sign);
    present_image(Images.misc.sign, Rectangles.awale.p2.sign);

    //Seeds Player 1
    for(int i=0; i<HOLES_PER_PLAYER; i++){

        if(P1.seeds[i]==1)
            present_image(Images.awale.one_seed, Rectangles.awale.p1.seeds[i]);

        else if(P1.seeds[i]==2)
            present_image(Images.awale.two_seed, Rectangles.awale.p1.seeds[i]);

        else if(P1.seeds[i]==3)
            present_image(Images.awale.three_seed, Rectangles.awale.p1.seeds[i]);

        else if(P1.seeds[i]>=4)
            present_image(Images.awale.four_seed, Rectangles.awale.p1.seeds[i]);
    }

    //Seeds Player 2
    for(int i=0; i<HOLES_PER_PLAYER; i++){

        if(P2.seeds[i]==1)
            present_image(Images.awale.one_seed, Rectangles.awale.p2.seeds[i]);

        else if(P2.seeds[i]==2)
            present_image(Images.awale.two_seed, Rectangles.awale.p2.seeds[i]);

        else if(P2.seeds[i]==3)
            present_image(Images.awale.three_seed, Rectangles.awale.p2.seeds[i]);

        else if(P2.seeds[i]>=4)
            present_image(Images.awale.four_seed, Rectangles.awale.p2.seeds[i]);
    }
}

void showLeaderboard(Image Images, Rectangle Rectangles, GameStatusVar GameStatus){
    PlayerScore RecordedScores[5];
    readScores(RecordedScores);
    present_image(Images.background.menu, Rectangles.bg.menu);
    present_image(Images.misc.sign_leaderboard, Rectangles.misc.sign_leaderboard);

    Point Name; Point Score; Point Moves;

    Name.x=495; Score.x=650; Moves.x=800;

    for(int i=0; i<5; i++){
        Name.y=FIRST_NAME_POS_Y + LEADERBOARD_SEPARATION *i;
        Score.y=FIRST_NAME_POS_Y + LEADERBOARD_SEPARATION *i;
        Moves.y=FIRST_NAME_POS_Y + LEADERBOARD_SEPARATION *i;
        char s[5];
        draw_text(RecordedScores[i].name,Name,24, Black);
        sprintf(s, "%.2d", RecordedScores[i].score);
        draw_text(s,Score,24, Black);
        sprintf(s, "%.2d", RecordedScores[i].moves);
        draw_text(s,Moves,24, Black);
    }  
}