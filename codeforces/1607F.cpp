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
int MOD=1e9+7;
ll power(ll a, ll b){//a^b
    ll res=1;
    a=a%MOD;
    while(b>0){
        if(b&1){res=(res*a)%MOD;b--;}
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
ll fermat_inv(ll y){return power(y,MOD-2);}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
ll min(ll a,ll b){return (a>b)?b:a;}
ll max(ll a,ll b){return (a>b)?a:b;}
// int x;
// void dfs(int a,int c,int next[],int vis[],int dp[]){
//     vis[a]=c;
//     if(next[a]==-1) dp[a]=1;
//     else if(vis[next[a]]==c) dp[a]=1,x=next[a];
//     else{
//         if(!vis[next[a]]) dfs(next[a],c,next,vis,dp);
//         dp[a]=1+dp[next[a]];
//     }
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n,m;
        cin>>n>>m;
        char a[n][m];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
        int next[n*m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='L') next[i*m+j]=(j)? i*m+j-1:-1;
                if(a[i][j]=='R') next[i*m+j]=(j<m-1)? i*m+j+1:-1;
                if(a[i][j]=='U') next[i*m+j]=(i)? (i-1)*m+j:-1;
                if(a[i][j]=='D') next[i*m+j]=(i<n-1)? (i+1)*m+j:-1;
            }
        }
        int vis[n*m]={0},dp[n*m]={0};
        for(int i=0;i<n*m;i++){
            if(vis[i]) continue;
            int x=-1,c=i+1;
            // dfs(i,i+1,next,vis,dp);
            stack<int>s;
            s.push(i);
            while(s.size()){
                int a=s.top();
                cout<<a<<' ';
                s.pop();
                vis[a]=c;
                if(next[a]==-1) dp[a]=1;
                else if(vis[next[a]]==c) dp[a]=1,x=next[a];
                else{
                    if(!vis[next[a]]) s.push(next[a]);
                    dp[a]=1+dp[next[a]];
                }
            }
            cout<<x<<'\n';
            if(x!=-1){
                int j=next[x];
                while(j!=x) dp[j]=dp[x],j=next[j];
            }
        }
        int mx=0;
        ii ans;
        for(int i=0;i<n*m;i++){
            if(dp[i]>mx) mx=dp[i],ans={i/m+1,i%m+1};
        }
        cout<<ans.ff<<' '<<ans.ss<<' '<<mx<<'\n';
    }
}