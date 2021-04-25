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

bool dfs(int a,vi adj[],int vis[],int col[],int par,int c)
{
    if(vis[a]){
        if(col[a]!=col[par])
            return true;
        else
            return false;
    }
    vis[a]=1;
    col[a]=c;
    bool ans=true;
    for(int i:adj[a]){
        if(i==par)
            continue;
        ans&=dfs(i,adj,vis,col,a,-c);
    }
    return ans;
}
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
    //factorial(100005);
    while(te--){
        int n,m;
        cin>>n>>m;
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        int temp=n2;
        vi adj[n+1];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int vis[n+1]={0},col[n+1]={0},c=1;
        bool b=true;
        for(int i=1;i<=n;i++){
            if(!vis[i])
                b&=dfs(i,adj,vis,col,-1,c++);
        }
        if(!b){
            cout<<"NO\n";
            return 0;
        }
        vv<ii >v(c,mp(0,0));
        for(int i=1;i<=n;i++){
            if(col[i]>0)
                v[col[i]].ff++;
            else
                v[-col[i]].ss++;
        }
        //for(int i=1;i<c;i++)
        //    cout<<v[i].ff<<' '<<v[i].ss<<'\n';
        bool dp[c][n2+1];
        for(int i=0;i<c;i++){
            for(int j=0;j<=n2;j++){
                if(j==0&&i==0){
                    dp[i][j]=1;
                    continue;
                }
                if(i==0){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=0;
                if(j-v[i].ff>=0)
                    dp[i][j]|=dp[i-1][j-v[i].ff];
                if(j-v[i].ss>=0)
                    dp[i][j]|=dp[i-1][j-v[i].ss];
            }
        }
        if(!dp[c-1][n2]){
            cout<<"NO";
            return 0;
        }
        cout<<"YES\n";
        bool c2[c]={0};
        for(int i=c-1;i>=1;i--){
            if(n2-v[i].ff>=0&&dp[i-1][n2-v[i].ff])
                c2[i]=1,n2-=v[i].ff;
            else
                n2-=v[i].ss;
        }
        //for(int i=1;i<c;i++)
        //cout<<c2[i]<<'\n';
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(col[i]>0&&c2[col[i]]||col[i]<0&&!c2[-col[i]])
                cnt++,col[i]=2;
            else if(n1)
                col[i]=1,n1--;
            else
                col[i]=3;
        }
        if(cnt!=temp)
            cout<<cnt<<'\n';
        for(int i=1;i<=n;i++)
            cout<<col[i];
    }
}