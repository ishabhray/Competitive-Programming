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
bool prime[15000005];
int cnt[15000005],ans=INT_MAX,n;
void SieveOfEratosthenes(int N) 
{ 
    for (int p=2; p<=N; p++) 
    { 
        if (!prime[p]) 
        { 
            int c=0;
            for (int i=p; i<=N; i += p) {
                prime[i] = 1; 
                c+=cnt[i];
            }
            if(c!=0)
                ans=min(ans,n-c);
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
    //cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int g=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            g=gcd(g,a[i]);
        }
        for(int i=0;i<n;i++)
            cnt[a[i]/=g]++;
        SieveOfEratosthenes(1.5e7);
        cout<<((ans!=INT_MAX)?ans:-1);
    }
}