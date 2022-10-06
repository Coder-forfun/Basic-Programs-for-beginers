#include <stdio.h>
#include <string.h>

void lcs_length();
void print_LCS(int i,int j);

int i,j,m,n,C[50][50];
char x[50],y[50],B[50][50];

int main()

{
    printf("Enter the first sequence: ");
    scanf("%s",x);
    printf("Enter the second sequence: ");
    scanf("%s",y);
    lcs_length();
    printf("The longest common subsequence will be: \n");
    print_LCS(m,n);
    return 0;
}

void lcs_length()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0;i<=m;i++)
    {
        C[i][0]=0;
        B[i][0]='0';
    }
    for(j=0;j<=n;j++)
    {
        C[0][j]=0;
        B[0][j]='0';
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
               {
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]='d';
                }
            else if(C[i-1][j]>=C[i][j-1])
            {
                C[i][j]=C[i-1][j];
                B[i][j]='u';
            }
            else
            {
                C[i][j]=C[i][j-1];
                B[i][j]='l';
            }
        }
    }
}

void print_LCS(int i,int j)
{
    if(i==0||j==0)
    {
        return;
    }
    if(B[i][j]=='d')
    {
        print_LCS(i-1,j-1);
        printf("%c",y[j-1]);
    }
    else if(B[i][j]=='u')
    {
        print_LCS(i-1,j);
    }
    else
    {
        print_LCS(i,j-1);
    }
}
