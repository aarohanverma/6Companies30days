// { Driver Code Starts
//Initial Template for C



#include<stdio.h>

 // } Driver Code Ends
//User function Template for C


void rotate(int n,int a[][n])
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j>i)
            {
                temp=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=temp;
            }
        }
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp=a[i][j];
            a[i][j]=a[n-i-1][j];
            a[n-i-1][j]=temp;
        }
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        rotate(n,a);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

  // } Driver Code Ends