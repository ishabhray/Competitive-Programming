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
#define MAXN 300005

int adj[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int deg[n+1]={0};
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            deg[u]++,deg[v]++;
            adj[u][v]=1;
            adj[v][u]=1;
        }
        
        set<int>leaves;
        for(int i=1;i<=n;i++){
            if(deg[i]==1)
                leaves.insert(i);
        }
        while(leaves.size()>1){
            int x=*leaves.begin();
            leaves.erase(leaves.begin());
            int y=*leaves.begin();
            leaves.erase(leaves.begin());
            cout<<"? "<<x<<' '<<y<<endl;
            int lca;
            cin>>lca;
            if(lca==x||lca==y){
                cout<<"! "<<lca<<endl;
                return 0;
            }
            deg[x]--,deg[y]--;
            for(int i=1;i<=n;i++){
                if(adj[x][i]){
                    deg[i]--,adj[x][i]=adj[i][x]=0;
                    if(deg[i]==1)
                        leaves.insert(i);
                }
            }
            for(int i=1;i<=n;i++){
                if(adj[y][i]){
                    deg[i]--,adj[y][i]=adj[i][y]=0;
                    if(deg[i]==1)
                        leaves.insert(i);
                }
            }
        }
        cout<<"! "<<*leaves.begin()<<endl;
    }
}