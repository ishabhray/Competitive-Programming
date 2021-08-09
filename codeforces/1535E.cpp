#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
#define all(v) (v).begin(),(v).end()


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int te=1;
    while(te--){
        int q;
        cin>>q;
        int n=q,l=ceil(log2(n));
        vv<vi>adj(n+1),up(n+1,vi(l+1));
        vl dist(n+1),a(n+1),c(n+1);
        dist[0]=0;
        for(int i=0;i<=l;i++)
            up[0][i]=0;
        cin>>a[0]>>c[0];
        for(int i=1;i<=q;i++){
            int t;
            cin>>t;
            if(t==1){
                int p;
                cin>>p>>a[i]>>c[i];
                adj[p].pb(i);
                dist[i]=dist[p]+1;
                up[i][0]=p;
                for(int j=1;j<=l;j++)
                    up[i][j]=up[up[i][j-1]][j-1];
            }
            else{
                int v,w;
                cin>>v>>w;
                int p=v;
                for(int j=l;j>=0;j--){
                    if(a[up[p][j]])
                        p=up[p][j];
                }
                ll x=w,y=0,d=dist[p];
                while(x>0&&d<=dist[v]){
                    // cout<<x<<' '<<d<<endl;
                    int u=dist[v]-d;
                    p=v;
                    for(int j=0;j<=l;j++){
                        if(u&(1<<j))
                            p=up[p][j];
                    }
                    if(a[p]>=x){
                        a[p]-=x;
                        y+=x*c[p];
                        x=0;
                    }
                    else{
                        y+=a[p]*c[p];
                        x-=a[p];
                        a[p]=0;
                    }
                    d++;
                }
                cout<<w-x<<' '<<y<<endl;
            }
        }
    }
}