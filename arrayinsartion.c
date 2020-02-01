#include<stdio.h>
int main()
{


    int a ,n=5,i,j,pos;
    int s[5]={2,3,4,5,6};


    printf("\nposition\n");
    scanf("%d",&pos);
    int d;
    printf("data\n");
    scanf("%d",&d);

    for (i=5;i<pos;i--){

        s[i+1]=s[i];


    }
    s[pos]=d;

        n++;


    for(i=0;i<n;i++){
    printf("%d",s[i]);
    }
}
