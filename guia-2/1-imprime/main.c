#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, a = 4, b = 5;
    p = &b;
    *p *= 2;
    printf("b=%d *p=%d\n", b, *p);
    printf("&b=%p p=%p &p=%p\n", &b, p, &p);
    b = *p *3;
    printf("b=%d *p=%d\n", b, *p);
    printf("&b=%p p=%p\n", &b, p);
    a = b;
    p = &a;
    (*p)++;
    printf("b=%d a=%d *p=%d\n", b, a, *p);
    printf("&b=%p &a=%p p=%p &p=%p\n", &b, &a, p, &p);

    return 0;
}
