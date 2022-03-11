#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMagicSq(int sq[3][3]);

int MagicSquare(int sq[3][3])
{
    int sumNum = 0,compareNum = 0;

    for (int i = 0; i < 3; i++)  //column
    {
        compareNum = 0;
        for (int j = 0; j < 3; j++)
            compareNum = compareNum + sq[j][i];
        if (compareNum != sumNum)
            return 0;
    }
    for (int i = 0; i < 3; i++)  //row
        sumNum = sumNum + sq[0][i];

    for (int i = 1; i < 3; i++) 
    {
        compareNum = 0;
        for (int j = 0; j < 3; j++)
            compareNum = compareNum + sq[i][j];
        if (compareNum != sumNum)
            return 0;
    }

    compareNum = 0;  //diagonal
    for (int i = 0; i < 3; i++)
        compareNum = compareNum + sq[i][i];
     if (compareNum != sumNum)
        return 0;

    compareNum = sq[0][2] + sq[1][1] + sq[2][0];    
     if (compareNum != sumNum)
    {
        return 0;
    }

    return 1;
    
}
  


void printMagicSq(int sq[3][3])  //printfunct.
{
    printf("\nBelow is the Lo Shu Magic Square: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ",sq[i][j]);
        }
            printf("\n");
    }
}

int main()
{
    int sq[3][3];
    int count = 0; //Count of squares that are generated
    while (1)
    {        
        count++;
        int arr[10] = {0};
        srand(time(0)+count); //random#generator
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int n = rand()%9 + 1;
                while (arr[n])
                {
                    n = rand()%9 + 1;
                }
                sq[i][j] = n;
                arr[n] = 1;
            }
        }

        if(MagicSquare(sq) == 1)
            break;
        
    }

    printf("The total number of squares generated and tested before success:\n%d\n",count);

    printMagicSq(sq);
    return 0;
}