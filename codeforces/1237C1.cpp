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

bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 if(v1[2]!=v2[2])return v1[2] < v2[2]; 
 else if(v1[1]!=v2[1])return v1[1]<v2[1];
 else return v1[0]<v2[0];
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
    //factorial(100005);
    while(t--){
        int n;
        cin>>n;
        vv<vi >pts(n,vi(4));
        for(int i=0;i<n;i++){
            cin>>pts[i][0]>>pts[i][1]>>pts[i][2];
            pts[i][3]=i+1;
        }
        sort(all(pts),&sortcol);
        vv<vi >v,v1;
        for(int i=0;i<n;i++){
            if(i<n-1&&pts[i][2]==pts[i+1][2]&&pts[i][1]==pts[i+1][1]){
                cout<<pts[i][3]<<' '<<pts[i+1][3]<<'\n';
                i++;
            }
            else
                v.pb(pts[i]);
        }
        n=v.size();
        for(int i=0;i<n;i++){
            if(i<n-1&&v[i][2]==v[i+1][2]){
                cout<<v[i][3]<<' '<<v[i+1][3]<<'\n';
                i++;
            }
            else
                v1.pb(v[i]);
        }
        n=v1.size();
        for(int i=0;i<n;i+=2){
            cout<<v1[i][3]<<' '<<v1[i+1][3]<<'\n';
        }
    }
}