#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
#define INF INT_MAX
int dist[MAX];
int spt[MAX];
int find_min(int spt[],int dist[],int n)
{
    int mn = INF;
    int in;
    for(int i=1; i<=n; i++)
    {
        if (!spt[i] && dist[i]<mn)
        {
            mn = dist[i];
            in = i;
        }
    }
    if (mn==INF) return -1;
    return in;
}
int main()
{
    int n,m,a,b,c,s;
    cout<<"Enter the number of nodes in the graph\n";
    cin>>n;
    int ar[n+1][n+1];
    memset(ar,0,sizeof(ar));
    cout<<"Enter the number of edges\n";
    cin>>m;
    cout<<"Enter the edges in form of node a,node b,weight of edge\n";
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        ar[a][b]=c;
    }
    cout<<"Enter the source node\n";
    cin>>s;
    for  (int i=0; i<=n; i++)
        dist[i] = INF;
    dist[s] = 0;
    while(1)
    {
        int in = find_min(spt,dist,n);
        spt[in] = 1;
        for (int i=1; i<=n; i++)
        {
            if (ar[in][i]!=0 && !spt[i])
            {
                dist[i] = min(dist[i],dist[in]+ar[in][i]);
            }
        }
        if (in==-1) break;
    }
    for(int i=1; i<=n; i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    return 0;
}
