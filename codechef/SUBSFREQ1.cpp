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

ll fact[5001];
void factorial(int n){
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD;
}

ll fermat_inv_arr[5001];

ll ncr(ll n,ll r)
{
    if(n<r)
        return -1;
    else{
        return fact[n]*fermat_inv_arr[r]%MOD*fermat_inv_arr[n-r]%MOD;
    }
}

ll sncr[5001][5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    factorial(5000);
    int t=1;
    cin>>t;
    for(int i=0;i<=5000;i++){
        fermat_inv_arr[i]=fermat_inv(fact[i]);
    }
    
    for(int i=0;i<=5000;i++){
        sncr[i][0]=1;
        for(int j=1;j<=i;j++){
            sncr[i][j]=(sncr[i][j-1]+ncr(i,j))%MOD;
        }
    }
    
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            m[x]++;
        }

        for(int i=1;i<=n;i++){
            if(!m[i])
                cout<<"0 ";
            else{
                cout<<power(2,n-i)<<' ';
            }
        }
        cout<<'\n';
    }
}