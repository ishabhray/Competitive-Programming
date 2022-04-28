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
vi ans;
void solve(int a[],int c,int n){
    if(n<3) return;
    for(int i=0;i+2<n;i+=2) ans.pb(i+c+1);
    for(int i=n-3;i>=0;i-=2) ans.pb(i+c+1);
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
    cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a[n],x=0;
        ans.clear();
        for(int i=0;i<n;i++){
            cin>>a[i];
            x^=a[i];
        }
        if(x) {cout<<"NO\n";continue;}
        else{
            if(n%2) solve(a,0,n);
            else{
                bool b=false;
                for(int i=0;i<n;i++){
                    x^=a[i];
                    if(!x&&i%2==0){
                        solve(a,0,i+1);
                        solve(a,i+1,n-i-1);
                        b=true;
                        break;
                    }
                }
                if(!b){cout<<"NO\n";continue;}
            }
            cout<<"YES\n";
            cout<<ans.size()<<'\n';
            for(int i:ans) cout<<i<<' ';
            cout<<'\n';
        }
    }
}