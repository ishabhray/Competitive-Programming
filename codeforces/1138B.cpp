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
ll fact[100010];
ll finv[100010];
void factorial(int n){
    fact[0]=1;
    finv[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD,finv[i]=fermat_inv(fact[i]);
}
ll ncr(ll n,ll r)
{
    if(n<r)
        return 0;
    else{
        ll x=finv[r]*finv[n-r]%MOD;
        return fact[n]*x%MOD;
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
    //factorial(100005);
    while(te--){
        int n;
        cin>>n;
        string c,a;
        cin>>c>>a;
        vi none,cl,ac,both;
        for(int i=0;i<n;i++){
            if(c[i]=='1'&&a[i]=='1')
                both.pb(i+1);
            else if(c[i]=='1')
                cl.pb(i+1);
            else if(a[i]=='1')
                ac.pb(i+1);
            else
                none.pb(i+1);
        }
        bool b=false;
        for(int i=0;i<=cl.size();i++){
            for(int j=0;j<=ac.size();j++){
                if(i<=j){
                    if(both.size()>=j-i&&(both.size()-(j-i))%2==0&&j+ac.size()-j+(both.size()-(j-i))/2<=n/2&&j+cl.size()-i+(both.size()-(j-i))/2<=n/2){
                        b=true;
                        for(int k=0;k<i;k++)
                            cout<<cl[k]<<' ';
                        for(int k=0;k<ac.size()-j;k++)
                            cout<<ac[k]<<' ';
                        for(int k=0;k<j-i+(both.size()-(j-i))/2;k++)
                            cout<<both[k]<<' ';
                        for(int k=0;k<n/2-(j+ac.size()-j+(both.size()-(j-i))/2);k++)
                            cout<<none[k]<<' ';
                        break;
                    }
                }
                else{
                    if(both.size()>=i-j&&(both.size()-(i-j))%2==0&&i+ac.size()-j+(both.size()-(i-j))/2<=n/2&&i+cl.size()-i+(both.size()-(i-j))/2<=n/2){
                        b=true;
                        for(int k=0;k<i;k++)
                            cout<<cl[k]<<' ';
                        for(int k=0;k<ac.size()-j;k++)
                            cout<<ac[k]<<' ';
                        for(int k=0;k<(both.size()-(i-j))/2;k++)
                            cout<<both[k]<<' ';
                        for(int k=0;k<n/2-(i+ac.size()-j+(both.size()-(i-j))/2);k++)
                            cout<<none[k]<<' ';
                        break;
                    }
                }
                /*else{
                    if(both.size()%2==0&&i+ac.size()-j+both.size()/2<=n/2&&j+cl.size()-i+both.size()/2<=n/2){
                        b=true;
                        for(int k=0;k<i;k++)
                            cout<<cl[k]<<' ';
                        for(int k=0;k<ac.size()-j;k++)
                            cout<<ac[k]<<' ';
                        for(int k=0;k<both.size()/2;k++)
                            cout<<both[k]<<' ';
                        for(int k=0;k<n/2-(i+ac.size()-j+both.size()/2);k++)
                            cout<<none[k]<<' ';
                    }
                }*/
            }
            if(b)
                break;
        }
        if(!b)
            cout<<-1;
    }
}