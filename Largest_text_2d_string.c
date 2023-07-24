#include<stdio.h>
#include<string.h>

void read(char asentence[][100],int n);
void display(char bsentence[][100],int n);
int length(char bsentence[]);
void main()
{
    int n;
    char sentence[100][100];
    printf("Enter the number of lines\n");
    scanf("%d",&n);
    getchar();
    read(sentence,n);
    display(sentence,n);
}

void read(char asentence[][100],int n)
{
    for(int i=0;i<n;i++)
    {
        gets(asentence[i]);
    }
}

void display(char bsentence[][100],int n)
{
    int max,max1=0,k,c;
    for(int i=0;i<n;i++)
    {
        c=i;
        max=length(bsentence[i]);
        if(max1<max)
        {
            max1=max;
            k=i;
        }
    }
    printf("\nThe largest string is \n");
    puts(bsentence[k]);
}

int length(char bsentence[])
{
    int i=0;
    while(bsentence[i]!='\0')
    {
        i++;
    }
    return i;
}
