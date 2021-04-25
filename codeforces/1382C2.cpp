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

void swap(string &a,int k)
{
    for(int i=0;i<=k/2;i++){
        char ch=a[i];
        a[i]=(a[k-i]=='0')?'1':'0';
        a[k-i]=(ch=='0')?'1':'0';
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
    cin>>t;
    //SieveOfEratosthenes(1000000);
    while(t--){
        int n;
        string a,b;
        cin>>n>>a>>b;
        vi ans;
        int cnt=0;
        int j=0;
        int k=n-1;
        for(int i=0;i<n;i++){
            int x,y=n-1-i;
            if(i%2==0)
                x=j++;
            else
                x=k--;
            //cout<<i<<' '<<x<<' '<<y<<' '<<cnt<<'\n';
            if(b[y]==a[x]&&cnt%2||b[y]!=a[x]&&cnt%2==0){
                cnt++;
                ans.pb(y+1);
            }
            else{
                cnt++;
                ans.pb(1);
                ans.pb(y+1);
            }
        }
        cout<<ans.size()<<' ';
        for(auto a:ans)
            cout<<a<<' ';
        cout<<'\n';
    }
}