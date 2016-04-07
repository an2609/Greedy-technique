    ///////////////////////////////////////////////////////////////////////////////////////////////////////
   //                                  OPTIMAL MERGE PATTERN O(nlogn)                                   //
  //                                        BY:- ANKUR SINGLA                                          //
 //                                           NIT JALANDHAR                                           //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
int ar[1000010];
void printtree(int ar[],int ,int);
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int ar[],int l,int n)
{
    int k=2*l;
    if(k+1<=n)
    {
        if((ar[k]<ar[l])&&(ar[k]<ar[k+1]))
        {
            swap(&ar[k],&ar[l]);
            heapify(ar,k,n);
        }
        else if((ar[k+1]<ar[l])&&(ar[k+1]<=ar[k]))
        {
            swap(&ar[k+1],&ar[l]);
            heapify(ar,k+1,n);
        }
    }
    else
    {
        if(k<=n&&ar[k]<ar[l])
            swap(&ar[k],&ar[l]);
    }
}
void heap(int ar[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        heapify(ar,i,n);
    }
}
int main()
{


    int n,cost=0;
    cout<<"Enter the number of files\n";
    cin>>n;
    int ar[n+1];
    for(int i=1; i<=n; i++)
    {
        printf("Enter the number of records in %d file\n",i);
        scanf("%d",&ar[i]);
    }
    heap(ar,n);
    for(int i=0;i<n-1;i++)
    {
        int temp=ar[1];
        ar[1]=ar[n-i];
        heapify(ar,1,n-i-1);
        int temp2=ar[1]+temp;
        cost+=temp2;
        ar[1]=temp2;
        heapify(ar,1,n-i-1);
    }
    cout<<"Total cost of merge is "<<cost<<endl;

}
