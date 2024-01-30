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