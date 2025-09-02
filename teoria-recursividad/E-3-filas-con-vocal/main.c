#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 32

int cantvocf(char A[MAX][10], int i, int j, int n);
int esvocal(char c);

int main()
{
    char A[MAX][10] = {    {'A','5','E'},
                            {'4','6','-'},
                            {'F','B','O'}
                        };
    int n = 3;
    printf ("filas con al menos una vocal %d\n", cantvocf (A,0,0,n-1));
    return 0;
}

int cantvocf(char A[][10], int i, int j, int n){
    char voc = A[i][j];
    if (i==n && j==n)
        return esvocal(voc);
    else
        if (j>n)
            return  cantvocf(A,i+1, 0,n);
        else
            if (esvocal(voc))
                return 1 + cantvocf(A,i+1,0,n);
            else
                return cantvocf(A,i,j+1,n);
}

int esvocal(char c) {
    c = tolower(c);

    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
}
