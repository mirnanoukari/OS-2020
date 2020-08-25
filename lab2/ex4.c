#include <stdio.h>
#include <string.h>

void swap(int * n1, int * n2);

int main(){
    char s1[256];
    char s2[256];
    int m,n;

    printf("Write a variable a \n");
    scanf("%s",s1);
    sscanf(s1,"%d",&m);

    printf("Write a variable b \n");
    scanf("%s",s2);
    sscanf(s2,"%d",&n);

    printf("Before swapping\na=%d\nb=%d\n", m,n);

    swap(&m,&n);

    printf("After swapping\na=%d\nb=%d\n", m,n);
}

void swap(int * n1, int * n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
