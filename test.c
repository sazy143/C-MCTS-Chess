#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ChessPieces.c"
int main(){

    struct piece Pawn = {0,0,0,1,0};
    struct piece Empty = {0,0,0,0,0};

    struct piece testBoard1[] = {Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn,
                                Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn, Pawn
                                };
    struct piece testBoard2[] = {Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty
                                };

    struct piece testBoard3[] = {Pawn, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Pawn, Empty, Empty,
                                Empty, Empty, Empty, Pawn, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Pawn, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Empty, Empty, Empty, Empty,
                                Empty, Empty, Empty, Empty, Pawn, Empty, Empty, Empty

    };

    //diagonal
    printf("%d expected 0\n", CheckBetween(testBoard1, 0, 0, 7 ,7)); 
    printf("%d expected 0\n", CheckBetween(testBoard1, 7, 7, 0 ,0)); 
    printf("%d expected 0\n", CheckBetween(testBoard1, 0, 7, 7 ,0));
    printf("%d expected 0\n", CheckBetween(testBoard1, 7, 0, 0 ,7));

    printf("%d expected 1\n", CheckBetween(testBoard2, 0, 0, 7 ,7)); 
    printf("%d expected 1\n", CheckBetween(testBoard2, 7, 7, 0 ,0)); 
    printf("%d expected 1\n", CheckBetween(testBoard2, 0, 7, 7 ,0));
    printf("%d expected 1\n", CheckBetween(testBoard2, 7, 0, 0 ,7));

    printf("%d expected 0\n", CheckBetween(testBoard2, 2, 4, 5 ,1)); 
    printf("%d expected 0\n", CheckBetween(testBoard3, 0, 0, 7 ,7)); 
    printf("%d expected 1\n", CheckBetween(testBoard3, 0, 0, 3 ,3));
    printf("%d expected 1\n", CheckBetween(testBoard3, 7, 7, 3 ,3));

    //vertical
    printf("%d expected 0\n", CheckBetween(testBoard1, 0, 1, 0 ,6)); 
    printf("%d expected 0\n", CheckBetween(testBoard1, 5, 7, 5 ,0)); 
    printf("%d expected 1\n", CheckBetween(testBoard2, 0, 7, 0 ,2));
    printf("%d expected 1\n", CheckBetween(testBoard2, 3, 0, 3 ,7));
    printf("%d expected 0\n", CheckBetween(testBoard3, 1, 7, 1 ,2));
    printf("%d expected 1\n", CheckBetween(testBoard3, 5, 2, 5 ,7));

    //horizontal
    printf("%d expected 0\n", CheckBetween(testBoard1, 5, 1, 0 ,1)); 
    printf("%d expected 0\n", CheckBetween(testBoard1, 1, 7, 5 ,7)); 
    printf("%d expected 1\n", CheckBetween(testBoard2, 0, 3, 5 ,3));
    printf("%d expected 1\n", CheckBetween(testBoard2, 4, 2, 2 ,2));
    printf("%d expected 0\n", CheckBetween(testBoard3, 3, 2, 6 ,2));
    printf("%d expected 1\n", CheckBetween(testBoard3, 5, 6, 2 ,6));

}