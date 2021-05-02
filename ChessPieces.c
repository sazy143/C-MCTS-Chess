typedef enum {
    empty,
    pawn,
    knight,
    bishop,
    rook,
    queen,
    king
} PIECETYPE;

struct piece {
    int pieceColor; // 0 = white, 1 = black, 2 = empty
    int x;
    int y;
    int pieceType;
    bool hasMoved;
}; 

void CreateBoard(struct piece *board);
void PrintBoard(struct piece *board);
int LetterToNum(char letter);
bool Move(char *move, bool turn, struct piece *board);
bool PawnMove(int sx, int sy, int ex, int ey);
bool KnightMove(int sx, int sy, int ex, int ey);
bool BishopMove(int sx, int sy, int ex, int ey);
bool RookMove(int sx, int sy, int ex, int ey);
bool QueenMove(int sx, int sy, int ex, int ey);
bool KingMove(int sx, int sy, int ex, int ey);


//returns bool true if move is valid
//assume valid cordinates given
bool Move(char *move, bool turn, struct piece *board)
{
    //make sure we have full command (avoid segmentation error)
    if(!move[4]){
        return false;
    }
    //pull out cordinates from parameters
    int sx = LetterToNum(move[0]);
    int sy = (move[1] - '0') -1;
    int ex = LetterToNum(move[3]);
    int ey = (move[4] - '0') -1;

    //validate coordinates
    //if(sx, sy, ex, ey > 7){}

    //get the piece
    struct piece startPiece = board[sx * 8 + sy];
    struct piece endPiece = board[ex * 8 + ey];
    printf("%d",endPiece.pieceType);
    printf("%d",endPiece.pieceType);

    //get the piece selected
    int pType = startPiece.pieceType;

    //we try moving a square with no piece
    if (pType == empty){
        return false;
    }

    //Otherwise we have a piece do its respective move
    switch(pType){
        case 1:
            PawnMove(sx, sy, ex, ey);
            break;
        case 2:
            KnightMove(sx, sy, ex, ey);
            break;
        case 3:
            BishopMove(sx, sy, ex, ey);
            break;
        case 4:
            RookMove(sx, sy, ex, ey);
            break;
        case 5:
            QueenMove(sx, sy, ex, ey);
            break;
        case 6:
            KingMove(sx, sy, ex, ey);
            break;
    }

    return true;
}

bool PawnMove(int sx, int sy, int ex, int ey)
{

}

bool KnightMove(int sx, int sy, int ex, int ey)
{

}

bool BishopMove(int sx, int sy, int ex, int ey)
{

}

bool RookMove(int sx, int sy, int ex, int ey)
{

}

bool QueenMove(int sx, int sy, int ex, int ey)
{

}

bool KingMove(int sx, int sy, int ex, int ey)
{

}

void CreateBoard(struct piece *board){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            //Black Rooks
            if(i == 0 && (j == 0 || j == 7)){
                board[(i * 8) + j] = (struct piece){1, i, j, rook, false};
            }
            //Black Bishops
            if(i == 0 && (j == 1 || j == 6)){
                board[(i * 8) + j] = (struct piece){1, i, j, bishop, false};
            }
            //Black Knights
            if(i == 0 && (j == 2 || j == 5)){
                board[(i * 8) + j] = (struct piece){1, i, j, knight, false};
            }
            //Black Queen
            if(i == 0 && j == 3){
                board[(i * 8) + j] = (struct piece){1, i, j, queen, false};
            }
            //Black King
            if(i == 0 && j == 4){
                board[(i * 8) + j] = (struct piece){1, i, j, king, false};
            }
            //Black Pawns
            if(i == 1){
                board[(i * 8) + j] = (struct piece){1, i, j, pawn, false};
            }
            //Empty Squares
            if(i > 1 && i < 6){
                board[(i * 8) + j] = (struct piece){2, i, j, empty, false};
            }
            //White Pawns
            if(i == 6){
                board[(i * 8) + j] = (struct piece){0, i, j, pawn, false};
            }
            //White Rooks
            if(i == 7 && (j == 0 || j == 7)){
                board[(i * 8) + j] = (struct piece){0, i, j, rook, false};
            }
            //White Bishops
            if(i == 7 && (j == 1 || j == 6)){
                board[(i * 8) + j] = (struct piece){0, i, j, bishop, false};
            }
            //White Knights
            if(i == 7 && (j == 2 || j == 5)){
                board[(i * 8) + j] = (struct piece){0, i, j, knight, false};
            }
            //White Queen
            if(i == 7 && j == 3){
                board[(i * 8) + j] = (struct piece){0, i, j, queen, false};
            }
            //White King
            if(i == 7 && j == 4){
                board[(i * 8) + j] = (struct piece){0, i, j, king, false};
            }
        }
    }
}

void PrintBoard(struct piece *board)
{
    for(int i = 0; i < 8; i++){
        printf("%d ", i + 1);
        for(int j = 0; j < 8; j++){
            int pieceType = board[(i * 8) + j].pieceType;
            switch(pieceType){
                case 0:
                    printf("x ");
                    break;
                case 1:
                    printf("P ");
                    break;
                case 2:
                    printf("H ");
                    break;
                case 3:
                    printf("B ");
                    break;
                case 4:
                    printf("R ");
                    break;
                case 5:
                    printf("Q ");
                    break;
                case 6:
                    printf("K ");
                    break;
                
            }
        }
        printf("\n");
    }
    printf("  A B C D E F G H\n");
}

int LetterToNum(char letter)
{
    switch(letter)
    {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
        case 'E':
            return 4;
        case 'F':
            return 5;
        case 'G':
            return 6;
        case 'H':
            return 7;
    }
    return -1;
}