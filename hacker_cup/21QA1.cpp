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
bool isv(char x){
    if(x=='A'||x=='E'||x=='I'||x=='O'||x=='U') return true;
    return false;
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        string s;
        cin>>s;
        map<int,int>m;
        for(char i:s) m[i-'A']++;
        ll dp[26][26];
        for(int i=0;i<26;i++) for(int j=0;j<26;j++) dp[i][j]=1e15;
        for(int i=0;i<26;i++) dp[i][i]=0;
        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            char u,v;
            cin>>u>>v;
            dp[u-'A'][v-'A']=1;
        }
        for(int x=0;x<26;x++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dp[i][j]=min(dp[i][j],dp[i][x]+dp[x][j]);
                }
            }
        }
        ll ans=1e15;
        for(int i=0;i<26;i++){
            ll curr=0;
            for(int j=0;j<26;j++){
                curr+=m[j]*dp[j][i];
            }
            ans=min(ans,curr);
        }
        if(ans==1e15) ans=-1;
        cout<<"Case #"<<T<<": "<<ans<<'\n';
    }
}