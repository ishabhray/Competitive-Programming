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
#define MOD 998244353
ll fermat_inv(ll);
ll power(ll a, ll b){//a^b
    if(b<0) return fermat_inv(power(a,-b));
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        string s;
        cin>>s;
        int n=s.size();
        ll ans=0,pre=1;
        for(int i=0;i<n;i++){
            ll curr=power(5,n-1-i);
            (curr+=MOD-1)%=MOD;
            (curr*=power(2,n-4-i))%=MOD;
            (curr+=power(10,n-1-i))%=MOD;
            (curr*=pre*(s[i]-'0'))%=MOD;
            (pre*=2)%=MOD;
            (ans+=curr)%=MOD;
        }
        cout<<ans<<'\n';
    }
}