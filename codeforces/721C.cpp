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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m,T;
        cin>>n>>m>>T;
        vv<ii>adj[n+1];
        for(int i=0;i<m;i++){
            int u,v,t;
            cin>>u>>v>>t;
            adj[u].pb({v,t});
        }
        queue<pair<int,ii>>q;
        long int vis[n+1][n+1];
        int back[n+1][n+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                vis[i][j]=1e12;
        memset(back,0,sizeof(back));
        vis[1][1]=0;
        q.push({1,{1,0}});
        while(!q.empty()){
            auto a=q.front();
            //cout<<a.ff<<' '<<a.ss.ff<<' '<<a.ss.ss<<'\n';
            q.pop();
            if(a.ff==n||a.ss.ff==n)
                continue;
            for(auto i:adj[a.ff]){
                if(a.ss.ss+i.ss>T||vis[i.ff][a.ss.ff+1]<=a.ss.ss+i.ss)
                    continue;
                else{
                    vis[i.ff][a.ss.ff+1]=a.ss.ss+i.ss;
                    back[i.ff][a.ss.ff+1]=a.ff;
                    q.push({i.ff,{a.ss.ff+1,vis[i.ff][a.ss.ff+1]}});
                }
            }
        }
        stack<int> ans;
        ans.push(n);
        int j=n;
        int k;
        for(k=n;k>=0;k--)
            if(back[n][k])
                break;
        while(back[j][k]){
            j=back[j][k];
            k--;
            ans.push(j);
        }
        cout<<ans.size()<<'\n';
        while(!ans.empty()){
            cout<<ans.top()<<' ';
            ans.pop();
        }
    }
}