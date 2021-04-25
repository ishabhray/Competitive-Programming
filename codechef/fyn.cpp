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

bool comp1(int const&x,int const&y)
{
    int a=x,b=y;
    if(a==b)
        return 0;
    if(a==0&&b==0)
        return 0;
    else if(a==0||b==0)
        return a>b;
    int i=0,j=0;
    int temp=a;
    while(temp)
        i++,temp/=10;
    temp=b;
    while(temp)
        j++,temp/=10;
    int c=i,d=j;
    while(i>0&&j>0&&a/(int)pow(10,i-1)==b/(int)pow(10,j-1))
        a%=(int)pow(10,i-1),b%=(int)pow(10,j-1),i--,j--;
    if(i&&j) return a/pow(10,i-1)>b/pow(10,j-1);
    if(i==0) return comp1(x,b);
    if(j==0) return comp1(a,y);
}
bool comp(int const&x,int const&y)
{
    string s=to_string(x),r=to_string(y);
    return s.compare(r)>0;
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
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,&comp);
        if(a[0]==0)
            cout<<"0\n";
        else{
            for(int i=0;i<n;i++)
                cout<<a[i];
            cout<<'\n';
        }
    }
}