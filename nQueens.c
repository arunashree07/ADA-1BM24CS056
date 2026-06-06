#include<stdio.h>
#include<time.h>

int isSafe(int board[][10], int row, int col, int n)
{
    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i])
            return 0;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return 0;
    }
    for(i=row,j=col;i<n && j>=0;i++,j--)
    {
        if(board[i][j])
            return 0;
    }
}
int printBoard(int board[10][10], int n)
{
    printf("\nBoard: \n");
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<n; j++)
        {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}
int place(int board[][10], int col, int n)
{
    if(col>=n)
    {
         return 1;
    }

        for(int i=0;i<n;i++)
        {
            if (isSafe(board, i, col, n))
            {
                board[i][col]=1;
                if(place(board,col+1, n ))
                    return 1;
                board[i][col]=0;
            }
        }

     return 0;
}

int main()
{
    int n;
    int board[10][10]={0};
    printf("Enter the number of queens to place: ");
    scanf("%d", &n);

    if(!place(board, 0,n))
    {
        printf("\nNo solution found\n");
    }
    clock_t start, end;
    start=clock();
    printBoard(board,n);
    end=clock();

    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\nExecution time: %f\n", time);
    return 0;
}
