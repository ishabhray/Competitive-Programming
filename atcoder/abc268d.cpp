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
void f(int i,int x,int n,vi &v,vv<string>&ans,string curr,string a[],int m){
    if(i==n-1){
        curr+=a[v[i]];
        if(curr.size()>=3) ans.pb(curr);
        return;
    }
    curr+=a[v[i]];
    for(int j=1;j<=x;j++){
        curr+='_';
        f(i+1,x-j,n,v,ans,curr,a,m);
        if(ans.size()>m) return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int te=1;
    while(te--){
        int n,m;
        cin>>n>>m;
        string a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        unordered_set<string>s;
        for(int i=0;i<m;i++){
            string t;
            cin>>t;
            s.insert(t);
        }
        int x=16;
        for(int i=0;i<n;i++) x-=a[i].size();
        vv<string>ans;
        vi v;
        for(int i=0;i<n;i++) v.pb(i);
        do{
            f(0,x,n,v,ans,"",a,m);
            if(ans.size()>m) break;
        }while(next_permutation(all(v)));
        string st="-1";
        for(auto i:ans){
            if(s.find(i)==s.end()){
                st=i;
                break;
            }
        }
        // if(ans.size()>m&&st=="-1") assert(0);
        cout<<st<<'\n';
    }
}