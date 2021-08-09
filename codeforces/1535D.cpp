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
int t[300000],n;
string s;
void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]=(s[v-1]=='?')?2:1;
        return;
    }
    int tm=(tl+tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    if(s[v-1]=='0')
        t[v]=t[2*v+1];
    else if(s[v-1]=='1')
        t[v]=t[2*v];
    else t[v]=t[2*v]+t[2*v+1];
}
void update(int v){
    if(v==0)
    return;
    char y=s[v-1];
    if(2*v>n){
        if(y=='?')
            t[v]=2;
        else t[v]=1;
    }
    else if(y=='1'){
        t[v]=t[2*v];
    }
    else if(y=='0'){
        t[v]=t[2*v+1];
    }
    else{
        t[v]=t[2*v]+t[2*v+1];
    }
    update(v/2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int te=1;
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int k,q;
        cin>>k>>s>>q;
        reverse(all(s));
        n=s.size();
        build(1,1,1<<(k-1));
        for(int i=0;i<q;i++){
            char y;
            int x;
            cin>>x>>y;
            x=n+1-x;
            s[x-1]=y;
            update(x);
            cout<<t[1]<<'\n';
            // cout<<s<<'\n';
            // for(int i=1;i<=n;i++)
            //     cout<<t[i]<<' ';
            // cout<<'\n';
        }
    }
}