#include<stdio.h>
int main()
{
    int i,j,temp,n;
    printf("Enter array limit n \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter Array Elements\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];              //Sorting elements by swapping
               a[j+1]=temp;
            }
        }
    }
    printf("Sorted Array \n");
    for(i=0;i<n;i++)
    {
       printf("%d\n",a[i]);
    }
    return 0;
}
