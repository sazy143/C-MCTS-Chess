#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

typedef enum
{
    empty,
    pawn,
    knight,
    bishop,
    rook,
    queen,
    king
} PIECETYPE;

struct piece
{
    int pieceColor; // 0 = white, 1 = black, 2 = empty
    int x;
    int y;
    int pieceType;
    bool hasMoved;
};

void CreateBoard(struct piece *board);
void PrintBoard(struct piece *board);
int LetterToNum(char letter);
bool Move(char *move, int turn, struct piece *board);
bool PawnMove(struct piece startPiece, struct piece endPiece, struct piece *board);
bool KnightMove(struct piece startPiece, struct piece endPiece);
bool BishopMove(struct piece startPiece, struct piece endPiece);
bool RookMove(struct piece startPiece, struct piece endPiece);
bool QueenMove(struct piece startPiece, struct piece endPiece);
bool KingMove(struct piece startPiece, struct piece endPiece);
bool CheckBetween(struct piece *board, int sx, int sy, int ex, int ey);

//returns bool true if move is valid
//assume valid cordinates given
bool Move(char *move, int turn, struct piece *board)
{
    //make sure we have full command (avoid segmentation error)
    if (!move[4])
    {
        return false;
    }
    //pull out cordinates from parameters
    int sx = LetterToNum(move[0]);
    int sy = (move[1] - '0');
    int ex = LetterToNum(move[3]);
    int ey = (move[4] - '0');

    //need to flip y axis since board is 8 -> 1 going down but internal array is 0 -> 7 going down
    sy = 8 - sy;
    ey = 8 - ey;

    printf("%d %d %d %d, ", sx, sy, ex, ey);

    if(sx == -1 || sy == -1 || (sy < 0 || sy > 7) || (ey < 0 || ey > 7)){
        return false;
    }

    
    //get the piece
    struct piece startPiece = board[sy * 8 + sx];
    struct piece endPiece = board[ey * 8 + ex];

    //get the piece selected
    int pType = startPiece.pieceType;

    //we try moving a square with no piece
    if (pType == empty)
    {
        return false;
    }
    printf("%d %d, \n", startPiece.pieceType, endPiece.pieceType);

    //Otherwise we have a piece do its respective move
    bool validMove = false;
    switch (pType)
    {
    case 1:
        printf("PawnMove, ");
        validMove = PawnMove(startPiece, endPiece, board);
        break;
    case 2:
        printf("KnightMove, ");
        validMove = KnightMove(startPiece, endPiece);
        break;
    case 3:
        printf("BishopMove, ");
        validMove = BishopMove(startPiece, endPiece);
        break;
    case 4:
        printf("RookMove, ");
        validMove = RookMove(startPiece, endPiece);
        break;
    case 5:
        printf("QueenMove, ");
        validMove = QueenMove(startPiece, endPiece);
        break;
    case 6:
        printf("KingMove, ");
        validMove = KingMove(startPiece, endPiece);
        break;
    }
    
    if(!validMove){
        return false;
    }

    //valid move perform the move


    return true;
}

bool PawnMove(struct piece startPiece, struct piece endPiece, struct piece *board)
{
    //white pawns are row 7 and move up (negative)
    //black pawns are row 1 and move down (positive)

    //get start and end cordinates as they will be used lots
    int sx = startPiece.x;
    int sy = startPiece.y;
    int ex = endPiece.x;
    int ey = endPiece.y;

    if (startPiece.pieceColor == 0)
    {
        //check captures
        if ((sx == (ex - 1) || sx == (ex + 1)) && (sy == (ey + 1)) && endPiece.pieceType != empty)
        {
            printf("capture, ");
            //valid capture return true
            startPiece.x = ex;
            startPiece.y = ey;
            startPiece.hasMoved = true;
            board[ey * 8 + ex] = startPiece;
            endPiece.x = sx;
            endPiece.y = sy;
            endPiece.pieceType = empty;
            board[sy * 8 + sx] = endPiece;
            endPiece.pieceColor = 2;
            return true;
        }
        if (ey == (sy - 1) && (sx == ex) && endPiece.pieceType == empty)
        {
            //valid move return true
            startPiece.x = ex;
            startPiece.y = ey;
            startPiece.hasMoved = true;
            board[ey * 8 + ex] = startPiece;
            endPiece.x = sx;
            endPiece.y = sy;
            endPiece.pieceType = empty;
            board[sy * 8 + sx] = endPiece;
            endPiece.pieceColor = 2;
            return true;
        }
        if (ey == (sy - 2) && (sx == ex) && endPiece.pieceType == empty && !startPiece.hasMoved && CheckBetween(board, sx, sy, ex, ey))
        {
            //valid move return true
            startPiece.x = ex;
            startPiece.y = ey;
            startPiece.hasMoved = true;
            board[ey * 8 + ex] = startPiece;
            endPiece.x = sx;
            endPiece.y = sy;
            endPiece.pieceType = empty;
            board[sy * 8 + sx] = endPiece;
            endPiece.pieceColor = 2;
            return true;
        }
    }
    if (startPiece.pieceColor == 1)
        {
            //check captures
            if ((sx == (ex - 1) || sx == (ex + 1)) && (sy == (ey - 1)) && endPiece.pieceType != empty)
            {
                printf("capture, ");
                //valid capture return true
                startPiece.x = ex;
                startPiece.y = ey;
                startPiece.hasMoved = true;
                board[ey * 8 + ex] = startPiece;
                endPiece.x = sx;
                endPiece.y = sy;
                endPiece.pieceType = empty;
                endPiece.pieceColor = 2;
                board[sy * 8 + sx] = endPiece;
                endPiece.pieceColor = 2;
                return true;
            }
            if (ey == (sy + 1) && (sx == ex) && endPiece.pieceType == empty)
            {
                //valid move return true
                startPiece.x = ex;
                startPiece.y = ey;
                startPiece.hasMoved = true;
                board[ey * 8 + ex] = startPiece;
                endPiece.x = sx;
                endPiece.y = sy;
                endPiece.pieceType = empty;
                board[sy * 8 + sx] = endPiece;
                endPiece.pieceColor = 2;
                return true;
            }
            if (ey == (sy + 2) && (sx == ex) && endPiece.pieceType == empty && !startPiece.hasMoved && CheckBetween(board, sx, sy, ex, ey))
            {
                //valid move return true
                startPiece.x = ex;
                startPiece.y = ey;
                startPiece.hasMoved = true;
                board[ey * 8 + ex] = startPiece;
                endPiece.x = sx;
                endPiece.y = sy;
                endPiece.pieceType = empty;
                board[sy * 8 + sx] = endPiece;
                endPiece.pieceColor = 2;
                return true;
            }
        }
}

bool KnightMove(struct piece startPiece, struct piece endPiece)
{
}

bool BishopMove(struct piece startPiece, struct piece endPiece)
{
}

bool RookMove(struct piece startPiece, struct piece endPiece)
{
}

bool QueenMove(struct piece startPiece, struct piece endPiece)
{
}

bool KingMove(struct piece startPiece, struct piece endPiece)
{
}

//returns true if no piece inbetween
bool CheckBetween(struct piece *board, int sx, int sy, int ex, int ey)
{

    int horizontalDif = sx - ex;
    int verticalDif = sy - ey;

    //diagonal (sx ex and sy ey diffs must equal)
    if (verticalDif != 0 && horizontalDif != 0 && abs(verticalDif) == abs(horizontalDif))
    {
        //technically only 2 diagonal planes so switch cases to only need two cases
        if(sx > ex && sy < ey){ //- + to + -
            int temp = sx;
            sx = ex;
            ex = temp;

            temp = sy;
            sy = ey;
            ey = temp;
        }
        if(sx > ex && sy > ey){ // - - to + +
            int temp = sx;
            sx = ex;
            ex = temp;

            temp = sy;
            sy = ey; 
            ey = temp;
        }
        printf("sx:%d sy:%d ex:%d ey:%d, ", sx, sy, ex, ey);
        //e.g. moving from 5,3(G) -> 3,1 vd = 2 hd = 2
        if (sx < ex && sy < ey)
        {
            printf("Dcase1, ");
            for (int i = 1; i < abs(verticalDif); i++)
            {   
                printf("%d, ", i);
                if (board[(sy + i) * 8 + (sx + i)].pieceType != empty)
                {
                    return false;
                }
            }
        }
        if (sx < ex && sy > ey)
        {
            printf("Dcase2, ");
            for (int i = 1; i < abs(verticalDif); i++)
            {
                printf("%d, ", i);
                if (board[(sy - i) * 8 + (sx + i)].pieceType != empty)
                {
                    return false;
                }
            }
        }
        return true;
    }

    //vertical (sx and ex must be the same)
    if (verticalDif != 0 && horizontalDif == 0)
    {
        printf("vertical, ");
        if(sy > ey){ //swap for only dealing with one direction
            int temp = sy;
            sy = ey;
            ey = temp;
        }
        for(int i = 1; i < abs(verticalDif); i++){
            printf("%d, ", i);
            if(board[(sy + i) * 8 + sx].pieceType != empty){
                return false;
            }
        }
        return true;
    }
    //horizontal (sy and ey must be the same)
    if (verticalDif == 0 && horizontalDif != 0)
    {
        printf("horizontal, ");
        if(sx > ex){ //swap only want 1 direction
            int temp = sx;
            sx = ex;
            ex = temp;
        }
        for(int i = 1; i < abs(horizontalDif); i++){
            printf("%d, ", i);
            if(board[sy * 8 + (sx + i)].pieceType != empty){
                return false;
            }
        }
        return true;
    }
    return false;
}

void CreateBoard(struct piece *board)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //Black Rooks
            if (i == 0 && (j == 0 || j == 7))
            {
                board[(i * 8) + j] = (struct piece){1, j, i, rook, false};
            }
            //Black Bishops
            if (i == 0 && (j == 2 || j == 5))
            {
                board[(i * 8) + j] = (struct piece){1, j, i, bishop, false};
            }
            //Black Knights
            if (i == 0 && (j == 1 || j == 6))
            {
                board[(i * 8) + j] = (struct piece){1, j, i, knight, false};
            }
            //Black Queen
            if (i == 0 && j == 3)
            {
                board[(i * 8) + j] = (struct piece){1, j, i, queen, false};
            }
            //Black King
            if (i == 0 && j == 4)
            {
                board[(i * 8) + j] = (struct piece){1, j, i, king, false};
            }
            //Black Pawns
            if (i == 1)
            {
                board[(i * 8) + j] = (struct piece){1, j, i, pawn, false};
            }
            //Empty Squares
            if (i > 1 && i < 6)
            {
                board[(i * 8) + j] = (struct piece){2, j, i, empty, false};
            }
            //White Pawns
            if (i == 6)
            {
                board[(i * 8) + j] = (struct piece){0, j, i, pawn, false};
            }
            //White Rooks
            if (i == 7 && (j == 0 || j == 7))
            {
                board[(i * 8) + j] = (struct piece){0, j, i, rook, false};
            }
            //White Bishops
            if (i == 7 && (j == 2 || j == 5))
            {
                board[(i * 8) + j] = (struct piece){0, j, i, bishop, false};
            }
            //White Knights
            if (i == 7 && (j == 1 || j == 6))
            {
                board[(i * 8) + j] = (struct piece){0, j, i, knight, false};
            }
            //White Queen
            if (i == 7 && j == 3)
            {
                board[(i * 8) + j] = (struct piece){0, j, i, queen, false};
            }
            //White King
            if (i == 7 && j == 4)
            {
                board[(i * 8) + j] = (struct piece){0, j, i, king, false};
            }
        }
    }
}

void PrintBoard(struct piece *board)
{
    for (int i = 0; i < 8; i++)
    {
        printf("\x1B[0m");
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++)
        {
            int pieceType = board[(i * 8) + j].pieceType;
            int pieceColor = board[(i * 8) + j].pieceColor;
            switch (pieceColor)
            {
            case 0:
                printf("\x1B[37m");
                break;
            case 1:
                printf("\x1B[31m");
                break;
            case 2:
                printf("\x1B[36m");
                break;
            }
            switch (pieceType)
            {
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
    printf("\x1B[0m");
    printf("  A B C D E F G H\n");
}

int LetterToNum(char letter)
{
    switch (letter)
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