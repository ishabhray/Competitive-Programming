#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592653589
#define ll long long int
#define ld long double
#define vi vector<int>
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
#define vv vector
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
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for(int p=2;p<1000001;p++)
        if(prime[p])
            primes.pb(p);
}
ll fact[1001];
void factorial(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD;
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        ll x=fact[r]*fact[n-r]%MOD;
        return fact[n]*fermat_inv(x)%MOD;
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

    int t=1;
    //cin>>t;
    //SieveOfEratosthenes(1000000);
    //factorial(1000);
    while(t--){
        int n;
        cin>>n;
        int a[100001]={0};
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]++;
        }
        int c2=0,c4=0,c6=0,c8=0;
        for(int i=1;i<=100000;i++){
            if(a[i]>=8)
                c8++;
            else if(a[i]>=6)
                c6++;
            else if(a[i]>=4)
                c4++;
            else if(a[i]>=2)
                c2++;
        }
        int q;
        cin>>q;
        for(int k=0;k<q;k++){
            char ch;
            int z;
            cin>>ch>>z;
            if(ch=='+'){
                a[z]++;
                if(a[z]==8)
                    c8++,c6--;
                else if(a[z]==6)
                    c6++,c4--;
                else if(a[z]==4)
                    c4++,c2--;
                else if(a[z]==2)
                    c2++;
            }
            else{
                a[z]--;
                if(a[z]==7)
                    c8--,c6++;
                else if(a[z]==5)
                    c6--,c4++;
                else if(a[z]==3)
                    c4--,c2++;
                else if(a[z]==1)
                    c2--;
            }
            //cout<<c2<<' '<<c4<<' '<<c8<<'\n';
            if(c8>=1||c6>=2||c4>=2||c4>=1&&c6>=1||c4>=1&&c2>=2||c6>=1&&c2>=1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}