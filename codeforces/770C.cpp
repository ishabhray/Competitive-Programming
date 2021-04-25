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
int MOD=1e9+7;

bool dfs(int i,vi adj[],int vis[],int rec[],stack<int>&ans)
{

    if(vis[i]&&rec[i])
        return false;
    if(vis[i]&&!rec[i])
        return true;
    vis[i]=1;
    rec[i]=1;
    bool b=true;
    for(int j:adj[i]){
        b&=dfs(j,adj,vis,rec,ans);
    }
    ans.push(i);
    rec[i]=0;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(t--){
        int n,k;
        cin>>n>>k;
        vi man(k);
        for(int i=0;i<k;i++)
            cin>>man[i];
        vi adj[n+1];
        for(int i=1;i<=n;i++){
            int u;
            cin>>u;
            for(int j=0;j<u;j++){
                int v;
                cin>>v;
                adj[i].pb(v);
            }
        }
        stack<int>ans;
        bool b=true;
        int vis[n+1]={0};
        int rec[n+1]={0};
        vi an;
        stack<int> temp;
        for(int i:man){
            if(!vis[i])
                b&=dfs(i,adj,vis,rec,ans);
            while(!ans.empty()){
                temp.push(ans.top());
                ans.pop();
            }
            while(!temp.empty()){
                an.pb(temp.top());
                temp.pop();
            }
        }
        if(!b){
            cout<<-1;
            break;
        }
        cout<<an.size()<<'\n';
        for(int i:an)
            cout<<i<<' ';
    }
}