#include<stdio.h>
main()
{
    FILE *fp1;
    fp1=fopen("1.txt","w");
    char s[100];
    printf("read string\n");
    gets(s);
    fp1=s[100];

}
