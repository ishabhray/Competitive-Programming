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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int te=1;
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    for(int T=1;T<=te;T++){
        ll n,a,b;
        cin>>n>>a>>b;
        ll ans=n;
        int u[n+1];
        for(int i=1;i<=n;i++)
            cin>>u[i];
        while(ans<1000){
            //cout<<ans<<'\n';
            ll curr[ans+1]={0};
            curr[ans]=1;
            ll j=ans;
            bool f=true;
            while(j){
                if(j<=n){
                    if(curr[j]<u[j]){
                        f=false;
                        break;
                    }
                    curr[j]-=u[j];
                }
                if(curr[j]>1e9)
                    break;
                if(j-a>0)
                    curr[j-a]+=curr[j];
                if(j-b>0)
                    curr[j-b]+=curr[j];
                j--;
            }
            if(f)
                break;
            ans++;
        }
        if(ans==1000)
            cout<<"Case #"<<T<<": IMPOSSIBLE\n";
        else
            cout<<"Case #"<<T<<": "<<ans<<"\n";
    }
}