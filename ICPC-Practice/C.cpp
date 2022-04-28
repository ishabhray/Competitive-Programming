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
bool prime[1000001];
vi primes;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime));
    prime[0]=prime[1]=0;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for(int p=2;p<n;p++)
        if(prime[p])
            primes.pb(p);
}
void solve(int m){
    MOD=m;
    for(int x=3;x<m;x++){
        for(int y=3;y<m;y++){
            for(int z=3;z<m;z++){
                for(int n=3;n<m;n++){
                    if((power(x,n)+power(y,n))%m==power(z,n)){
                        cout<<"FOUND\n"<<x<<' '<<y<<' '<<z<<' '<<n<<'\n';
                        return;
                    }
                }
            }
        }
    }
    cout<<"LOST THEOREM\n";
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
    SieveOfEratosthenes(100000);
    //factorial(1000005);
    while(te--){
        int m;
        cin>>m;
        if(m<50){
            solve(m);
            continue;
        }
        int temp=m;
        map<int,int>mp;
        for(int i:primes){
            if(i>m) break;
            while(m%i==0){
                m/=i;
                mp[i]++;
            }
        }
        if(m>1) mp[m]++;
        m=temp;
        int mx=0;
        ll x=1;
        for(auto i:mp){
            x*=i.ff;
            mx=max(mx,i.ss);
        }
        if(mx>1){
            cout<<"FOUND\n";
            if(x==2) x*=2;
            cout<<x<<' '<<x<<' '<<x<<' '<<mx+1<<'\n';
        }
        else if(mp.size()>1){
            cout<<"FOUND\n";
            ll o=1;
            for(auto i:mp){
                o*=(i.ff-1);
            }
            cout<<3<<' '<<3<<' '<<6<<' '<<o+1<<'\n';
        }
        else{
            MOD=m;
            ll inv2=fermat_inv(2),inv4=fermat_inv(4);
            cout<<"FOUND\n"<<inv2<<' '<<inv2<<' '<<inv4<<' '<<m-2<<'\n';
        }
    }
}