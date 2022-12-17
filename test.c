#include <stdio.h>

int main()
{
    int x=23;
    printf("%lu\n",sizeof(x));
    double y=11;
    printf("%lu\n",sizeof(y));
    printf("%lu\n",sizeof(x+y));

    return 0;
}