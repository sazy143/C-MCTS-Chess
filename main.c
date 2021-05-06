#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "ChessPieces.c"

int main()
{
    //command are format "xy xy" for starting pos to end pos or "end" to end game
    char endCommand[] = "end";

    //set up board
    struct piece *board = malloc(8 * 8 * sizeof(struct piece));
    CreateBoard(board);
    PrintBoard(board);

    //set game turn and player color white = 0
    srand(time(0));
    int gameTurn = 0;
    int playerColor = 0;//rand() & 1;

    while(true){

        ReadCommand: ;
        char command[5] = {0}, input;
        if(gameTurn == playerColor){
            printf("Enter Command: ");
            for(int i = 0; i < 5; i++){
            input = getchar();
            if(input == '\n'){
                break;
            }
            command[i] = input;
        }
        while ( input != '\n') input = getchar();
        
            if(strcmp(command, endCommand) == 0){
                printf("Game Ended By Command\n");
                break;
            }
        }else{ //if ai's turn
            //run MCTS
            //choose move
        }
        
        bool validMove = Move(command, gameTurn, board);
        if(!validMove){
            goto ReadCommand;
        }



        //Display board after move
        printf("\n");
        PrintBoard(board);
    }
    
    return 0;
}