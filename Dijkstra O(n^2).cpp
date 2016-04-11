#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define MAX 1000
int dist[MAX];
int spt[MAX];
int find_min(int spt[],int dist[],int n)
{
    int mn=INF,in;
    for(int i=1; i<=n; i++)
    {
        if(!spt[i]&&dist[i]<mn)
        {
            mn=dist[i];
            in=i;
        }
    }
    if(mn==INF)
        return -1;
    return in;
}
int main()
{
    int n,m,a,b,c,s;
    char status;
    cout<<"Enter the number of nodes in the graph\n";
    cin>>n;
    int ar[n+1][n+1];
    memset(ar,0,sizeof(ar));
    cout<<"Enter the number of edges\n";
    cin>>m;
    cout<<"Is the graph directed?\n";
    cin>>status;
    if(status=='Y'||status=='y')
    {
        cout<<"Enter the edges in form of node a,node b,weight of edge\n";
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            ar[a][b]=c;
        }
    }
    else
    {
        cout<<"Enter the edges in form of node a,node b,weight of edge\n";
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            ar[a][b]=c;
            ar[b][a]=c;
        }
    }
    cout<<"Enter the source node\n";
    cin>>s;
    memset(spt,0,sizeof(spt));
    for(int i=1; i<=n; i++)
    {
        dist[i]=INF;
    }
    dist[s]=0;
    while(1)
    {
        int temp=find_min(spt,dist,n);
        if(temp==-1)
            break;
        spt[temp]=1;
        for(int i=1;i<=n;i++)
        {
            if(!spt[i]&&ar[temp][i]!=0)
            {
                dist[i]=min(dist[i],dist[temp]+ar[temp][i]);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(i==s)
            continue;
        else
        {
            printf("Shortest distance from %d to %d = %d\n",s,i,dist[i]);
        }
    }
}
