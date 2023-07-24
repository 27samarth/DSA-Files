 #include<stdio.h>
main()
{
    FILE *fp;
    fp=fopen("10.txt","r");
    if(fp==NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        printf("files exists\n");
        char ch=getc(fp);
        printf("%c",ch);

    }
}

