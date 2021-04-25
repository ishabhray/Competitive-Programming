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
struct node{
    int col,rem,x,y;
};
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
        int n;
        cin>>n;
        int a[n][n];
        queue<node>q;
        int vis[n][n];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            cin>>a[i][i];
            vis[i][i]=1;
            node curr={a[i][i],a[i][i]-1,i,i};
            q.push(curr);
        }
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                vis[i][j]=1;
        while(q.size()){
            node curr=q.front();
            q.pop();
            //cout<<curr.col<<' '<<curr.x<<' '<<curr.y<<'\n';
            a[curr.x][curr.y]=curr.col;
            if(!curr.rem)
                continue;
            if(curr.x-1>=0&&!vis[curr.x-1][curr.y]){
                vis[curr.x-1][curr.y]=1;
                q.push({curr.col,curr.rem-1,curr.x-1,curr.y});
            }
            else if(curr.y-1>=0&&!vis[curr.x][curr.y-1]){
                vis[curr.x][curr.y-1]=1;
                q.push({curr.col,curr.rem-1,curr.x,curr.y-1});
            }
            else if(curr.x+1<n&&!vis[curr.x+1][curr.y]){
                vis[curr.x+1][curr.y]=1;
                q.push({curr.col,curr.rem-1,curr.x+1,curr.y});
            }
            else{
                vis[curr.x][curr.y+1]=1;
                q.push({curr.col,curr.rem-1,curr.x,curr.y+1});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<a[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}