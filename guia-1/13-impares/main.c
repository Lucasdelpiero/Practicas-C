#include <stdio.h>
#include <stdlib.h>
#define N 15
int i;

int main()
{
    for(i = 1; i <= N; i += 2){
        printf("%d\n", i);
    }
    return 0;
}
