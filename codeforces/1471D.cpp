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
bool prime[1000005];
int k[1000005];
void SieveOfEratosthenes(int n) 
{
    for(int i=1;i<=n;i++)
        k[i]=i;
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=0;
    for (int p=2; p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p; i<=n; i += p) {
                prime[i] = false; 
                while(k[i]%(p*p)==0)
                    k[i]/=(p*p);
            }
        } 
    } 
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
    SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[k[a[i]]]++;
        }
        int mx=0,c1=0;
        for(auto i:m)
            mx=max(mx,i.ss),c1+=(i.ff==1||i.ss%2==0)?i.ss:0;
        //cout<<mx<<' '<<c1<<'\n';
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            ll t;
            cin>>t;
            if(!t)
                cout<<mx<<'\n';
            else
                cout<<max(mx,c1)<<'\n';
        }

    }
}