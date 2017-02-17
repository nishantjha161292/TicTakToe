#include<stdio.h>
#include<conio.h>

void display(int board[3][3])
{
    int i, j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("%c\t",board[i][j]);

        }
        printf("\n");
    }
}

void input(int board[3][3])
{
    int complete = 0;
    char fill;
    char player;
    int time = 0;
    int inp;
    while(!complete && time!=9)
    {
        if (time%2 == 0)
        {
           player = 'A';
           fill = 'X';
        }
        else
        {
           player ='B';
           fill = 'O';
        }

        printf("player %c chhose position to put %c",player, fill);
        scanf("%d",&inp);
        switch (inp)
        {
            case 1: board[0][0] = fill;
                    break;
            case 2: board[0][1] = fill;
                    break;
            case 3: board[0][2] = fill;
                    break;
            case 4: board[1][0] = fill;
                    break;
            case 5: board[1][1] = fill;
                    break;
            case 6: board[1][2] = fill;
                    break;
            case 7: board[2][0] = fill;
                    break;
            case 8: board[2][1] = fill;
                    break;
            case 9: board[2][2] = fill;
                    break;

        }
        display(board);
        complete = check(board);
        if(complete==1)
        {
            printf("player %c won", player);
        }
        time++;
    }
    if (time == 9 && complete == 0)
      printf("game draw");
}
int check(int board[3][3])
{
    if ((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[0][2]==board[1][1] && board[1][1]==board[2][0]))
    {
        return 1;
    }
    else
    {
        if((board[0][0]==board[0][1] && board[0][1]==board[0][2]) ||
           (board[1][0]==board[1][1] && board[1][1]==board[1][2]) ||
           (board[2][0]==board[2][1] && board[2][1]==board[2][2]))
           {
               return 1;
           }
        else  if((board[0][0]==board[1][0] && board[1][0]==board[2][0]) ||
                 (board[0][1]==board[1][1] && board[1][1]==board[2][1]) ||
                 (board[0][2]==board[1][2] && board[1][2]==board[2][2]))
           {
               return 1;
           }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    display(board);
    input(board);


}

