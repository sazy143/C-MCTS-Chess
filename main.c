#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "ChessPieces.c"

int main()
{
    //command are format "xy xy" for starting pos to end pos or "end" to end game
    char *command = malloc(5 * sizeof(char));
    char endCommand[] = "end";

    //set up board
    struct piece *board = malloc(8 * 8 * sizeof(struct piece));
    CreateBoard(board);

    //set game turn and player color white = 0
    srand(time(0));
    int gameTurn = 0;
    int playerColor = rand() & 1;

    while(true){

        ReadCommand:
        if(gameTurn == playerColor){
            printf("Enter Command: ");
            scanf("%s", command);
            if(strcmp(command, endCommand) == 0){
                printf("Game Ended By Command\n");
                break;
            }
        }else{ //if ai's turn
            //run MCTS
            //choose move
        }
        
        bool validMove = Move()
        if(!validMove){
            goto ReadCommand;
        }

        //Display board after move
        PrintBoard(board);
    }
    
    return 0;
}