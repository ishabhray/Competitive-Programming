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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        if(n<=2){
            cout<<0;
            return 0;
        }
        vv<ii >ans;
        int j=1;
        while(power(2,j+1)<n)
            j++;
        //cout<<j<<'\n';
        int n1=power(2,j),cnt=n1,c=1;
        while(cnt>1){
            int k=power(2,c);
            for(int i=1;i<=n1;i+=k){
                for(int j=i;j<i+k/2;j++){
                    ans.pb({j,j+k/2});
                }
            }
            cnt/=2;
            c++;
        }
        n1=power(2,j),cnt=n1,c=1;
        while(cnt>1){
            int k=power(2,c);
            for(int i=1;i<=n1;i+=k){
                for(int j=i;j<i+k/2;j++){
                    ans.pb({n-n1+j,n-n1+j+k/2});
                }
            }
            cnt/=2;
            c++;
        }
        cout<<ans.size()<<'\n';
        for(auto i:ans)
            cout<<i.ff<<' '<<i.ss<<'\n';
    }
}