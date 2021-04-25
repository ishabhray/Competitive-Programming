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
        ll a[n],b[n],temp[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        for(ll i=0;i<n;i++){
            cin>>b[i];
            temp[i]=b[i];
        }
        for(int i=0;i<n;i++){
            int c=a[i];
            a[i]=max(0,a[i]-b[i]);
            b[i]-=c-a[i];
        }
        /*for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
        for(int i=0;i<n;i++)
            cout<<b[i]<<' ';
        cout<<'\n';*/
        int j=-1;
        int mx=0;
        for(int i=0;i<n;i++){
            if(a[i]>mx){
                j=i;
                mx=a[i];
            }
        }
        j++;
        j%=n;
        
        //cout<<j<<'\n';
        if(j!=-1){
        int i=j;
        do{
            int k=(i+1)%n;
            if(b[i]){
                int c=a[k];
                a[k]=max(0,a[k]-b[i]);
                b[i]-=c-a[k];
                int d=min(temp[k],b[k]+b[i]);
                c=b[k];
                b[k]=max(b[k],d);
                b[i]-=b[k]-c;
            }
            i++,i%=n;
        }while(i!=j);}

        /*for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
        for(int i=0;i<n;i++)
            cout<<b[i]<<' ';
        cout<<'\n';*/
        bool f=true;
        for(int i=0;i<n;i++)
            if(a[i]>0)
                f=false;
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}