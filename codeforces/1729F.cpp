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
        string s;
        cin>>s;
        int n,m,w;
        cin>>w>>m;
        n=s.size();
        vi adj[9];
        int curr=0;
        for(int i=0;i<w;i++){
            (curr+=s[i]-'0')%=9;
        }
        adj[curr].pb(1);
        for(int i=w;i<n;i++){
            (curr+=s[i]-'0')%=9;
            curr=(curr-(s[i-w]-'0')+9)%9;
            adj[curr].pb(i-w+2);
        }
        int rem[n+1]={0},c=1;
        for(int i=n-1;i>=0;i--){
            rem[i]=(c*(s[i]-'0')+rem[i+1])%9;
            (c*=10)%=9;
        }
        // for(int i=0;i<9;i++){
        //     cout<<i<<"->";
        //     for(int j:adj[i]) cout<<j<<' ';
        //     cout<<'\n';
        // }
        while(m--){
            int l,r,k;
            cin>>l>>r>>k;
            l--,r--;
            int x=rem[l];
            (x+=9-rem[r+1])%=9;
            int l1=1e9,l2=1e9;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(adj[i].empty()||adj[j].empty()) continue;
                    if((i*x+j)%9!=k) continue;
                    if(i==j){
                        if(adj[i].size()<2) continue;
                        if(adj[i][0]<l1) l1=adj[i][0],l2=adj[i][1];
                        else if(adj[i][0]==l1&&adj[i][1]<l2) l2=adj[i][1];
                    }
                    else{
                        if(adj[i][0]<l1) l1=adj[i][0],l2=adj[j][0];
                        else if(adj[i][0]==l1&&adj[j][0]<l2) l2=adj[j][0];
                    }
                }
            }
            if(l1==1e9) l1=-1,l2=-1;
            cout<<l1<<' '<<l2<<'\n';
        }
    }
}