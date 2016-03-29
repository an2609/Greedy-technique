///////////////////////////////////////////////////////////////////////////////////////////////////////
//                                        KNAPSACK PROBLEM                                           //
//                                         BY:-ANKUR SINGLA                                          //
//                                            NIT JALANDHAR                                          //
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
struct node
{
    double x;
    double y;
};

bool operator <(node a,node b)
{
    if (a.x==b.x) return a.y>b.y;
    else return a.x<b.x;
}

int main()
{
    int n;
    double m;
    cout<<"Enter the number of weights\n";
    cin>>n;
    cout<<"Enter the knapsack capacity\n";
    cin>>m;
    node ar[n];
    node br[n];
    pair< double, double > cr[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter the weight of %d element\n",i+1);
        scanf("%lf",&ar[i].x);
        br[i].y=ar[i].x;
        printf("Enter the profit corresponding to %d weight\n",i+1);
        scanf("%lf",&ar[i].y);
        br[i].x=ar[i].y;
        cr[i].first=ar[i].y/ar[i].x;
        cr[i].second=ar[i].x;
    }
    while(1)
    {
        int k;
        printf("Enter your choice\n1.Greedy about weight\n2.Greedy about profit\n3.Optimal Solution\n4.Exit\n");
        cin>>k;
        switch(k)
        {
        case 1:
        {
            double ans=0;
            double c=m;
            sort(ar,ar+n);
            for(int i=0; i<n; i++)
            {
                if(c>ar[i].x)
                {
                    ans+=ar[i].y;
                    c=c-ar[i].x;
                }
                else
                {
                    ans=ans+(c*ar[i].y)/ar[i].x;
                    break;
                }
            }
            cout<<ans<<endl;

            break;
        }
        case 2:
        {
            sort(br,br+n);
            double ans=0;
            double c=m;
            for(int i=n-1; i>=0; i--)
            {
                if(c>br[i].y)
                {
                    ans+=br[i].x;
                    c=c-br[i].y;
                }
                else
                {
                    ans=ans+(c*br[i].x)/br[i].y;
                    break;
                }

            }
            cout<<ans<<endl;
            break;
        }
        case 3:
        {
            double c=m;
            double ans=0;
            sort(cr,cr+n);
            for(int i=n-1;i>=0;i--)
            {
                if(c>cr[i].second)
                {
                    ans=ans+(cr[i].first*cr[i].second);
                    c=c-cr[i].second;
                }
                else
                {
                    ans=ans+(c*cr[i].first);
                    break;
                }
            }
            cout<<ans<<endl;

        }
        case 4:
        {
            exit(0);
        }
        }
    }

}
