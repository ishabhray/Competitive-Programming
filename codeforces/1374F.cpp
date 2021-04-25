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
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int pos=0,cnt=0;
        vi ans;
        while(pos<n&&cnt<n*n){
            int mn=1000,j=-1;
            for(int i=pos;i<n;i++){
                if(a[i]<mn)
                    mn=a[i],j=i;
            }
            cout<<pos<<' '<<j<<' ';
            if(j==pos){
                pos++;
            }
            else{
                while(j!=pos){
                    if(j>pos+1){
                        int x=a[j-2],y=a[j-1],z=a[j];
                        a[j]=y,a[j-1]=x,a[j-2]=z;
                        ans.pb(j-1);
                        j-=2;
                        cnt++;
                    }
                    else if(j==n-1)
                        cnt=n*n+2,pos=n,j=pos;

                    else{
                        ans.pb(pos+1);
                        ans.pb(pos+1);
                        int x=a[j-1],y=a[j],z=a[j+1];
                        a[j-1]=y,a[j]=z,a[j+1]=x;
                        j--;
                        cnt+=2;
                    }
                        
                }
                pos++;
            }
            cout<<cnt<<'\n';
            for(int i=0;i<n;i++)
                cout<<a[i]<<' ';
            cout<<'\n';
        }
        if(pos==n&&cnt<=n*n){
            cout<<cnt<<'\n';
            for(auto a:ans)
                cout<<a<<' ';
            cout<<'\n';
        }
        else{
            cout<<"-1\n";
        }
    }
}