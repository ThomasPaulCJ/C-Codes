#include<stdio.h>;
 
int main()
{
    int i,j,r,c,k=0;   
    printf("enter Row ");
    scanf("%d",&r);
    printf("enter column");
    scanf("%d",&c);
    int s[r][c], t[r][c];
    printf("enter elements into sparse matrix");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",& s[i][j]);
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(s[i][j]!=0) 
            {
                t[k][0]=i;
                t[k][1]=j;
                t[k][2]=s[i][j];
                k++;
            }
        }
        }
    t[0][0]=r;
    t[0][1]=c;
    t[0][2]=k-1;
    printf("Triplet representation of the matrix is \n");
    for (int i=1; i<k; i++) 
    { 
        for (int j=0; j<3; j++) 
            printf(" %d ", t[i][j]); 
        printf("\n"); 
    } 
    return 0;    
}
