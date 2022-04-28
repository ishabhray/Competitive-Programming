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
bool check1(ll x,ll y,ll a){
    if(x<=0||y<=0) return false;
    return x*y>=a;
}
bool check2(ll x,ll y,ll a,ll b){
    if(x<=0||y<=0) return false;
    bool ans=false;
    ll z=(a+x-1)/x;
    ans|=check1(x,y-z,b);
    z=(a+y-1)/y;
    ans|=check1(x-z,y,b);
    z=(b+x-1)/x;
    ans|=check1(x,y-z,a);
    z=(b+y-1)/y;
    ans|=check1(x-z,y,a);
    return ans;
}
bool check3(ll x,ll y,ll a,ll b,ll c){
    bool ans=false;
    ll z=(a+x-1)/x;
    ans|=check2(x,y-z,b,c);
    z=(a+y-1)/y;
    ans|=check2(x-z,y,b,c);
    z=(b+x-1)/x;
    ans|=check2(x,y-z,a,c);
    z=(b+y-1)/y;
    ans|=check2(x-z,y,a,c);
    z=(c+x-1)/x;
    ans|=check2(x,y-z,a,b);
    z=(c+y-1)/y;
    ans|=check2(x-z,y,a,b);
    return ans;
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        ll x,y,a,b,c;
        cin>>x>>y>>a>>b>>c;
        if(check3(x,y,a,b,c)) cout<<"Yes\n";
        else cout<<"No\n";
    }
}