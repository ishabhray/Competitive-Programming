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
bool f(int a[],int b[],int n,vi v){
    map<ll,set<ll>>m;
    sort(all(v),greater<int>());
    for(int i=0;i<n;i++){
        if(a[i]<b[i]) return 0;
        else if(a[i]==b[i]) continue;
        m[b[i]].insert(i);
    }
    stack<int>s;
    int gr[n];
    for(int i=0;i<n;i++){
        while(s.size()&&b[s.top()]<b[i]) gr[s.top()]=i,s.pop();
        s.push(i);
    }
    while(s.size()) gr[s.top()]=n+1,s.pop();
    // for(int i=0;i<n;i++) cout<<gr[i]<<" ";
    // cout<<'\n';
    for(int curr:v){
        if(m[curr].empty()) continue;
        int cut=gr[*m[curr].begin()];
        // cout<<curr<<" "<<cut<<'\n';
        while(m[curr].size()&&*m[curr].begin()<cut) m[curr].erase(m[curr].begin());
    }
    for(auto i:m){
        if(i.ss.size()) return 0;
    }
    return 1;
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
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int &i:a) cin>>i;
        for(int &i:b) cin>>i;
        int m;
        cin>>m;
        vi v;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            v.pb(x);
        }
        if(f(a,b,n,v)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}