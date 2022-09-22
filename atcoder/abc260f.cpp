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

#pragma GCC optimize("O3,unroll-loops")

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int s,t,m;
        cin>>s>>t>>m;
        vector<vector<int>>adj(t);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[v-s-1].pb(u);
        }
        for(auto &i:adj) sort(all(i));
        for(int i=0;i<t;i++){
            for(int j=i+1;j<t;j++){
                vi ans;
                ans.pb(s+1+i);
                ans.pb(s+1+j);
                int a=0,b=0;
                while(a<adj[i].size()&&b<adj[j].size()&&ans.size()<4){
                    if(adj[i][a]<adj[j][b]) a++;
                    else if(adj[i][a]>adj[j][b]) b++;
                    else{
                        ans.pb(adj[i][a]);
                        a++;
                        b++;
                    }
                }
                if(ans.size()==4){
                    for(int k:ans) cout<<k<<' ';
                    cout<<'\n';
                    return 0;
                }
            }
        }
        cout<<"-1\n";
    }
}