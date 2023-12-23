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
const int BLOCK_SIZE=450, INT_SIZE=31;
struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE)
            return l < other.l;
    return (l / BLOCK_SIZE & 1) ? (r < other.r) : (r > other.r);
    }
};
int n,a[200005];
multiset<int>s,xo;
void add(int idx){
    auto it=s.lower_bound(a[idx]);
    if(it!=s.end()) xo.insert(a[idx]^*it);
    if(it!=s.begin()){
        it--;
        xo.insert(a[idx]^*it);
    }
    s.insert(a[idx]);
}
void remove(int idx){
    auto it1=s.lower_bound(a[idx]),it2=s.upper_bound(a[idx]);
    it2--;
    if(it1==it2){
        it2++;
        if(it2!=s.end()) xo.erase(xo.lower_bound(a[idx]^*it2));
        if(it1!=s.begin()){
            it1--;
            xo.erase(xo.lower_bound(a[idx]^*it1));
        }
        s.erase(s.lower_bound(a[idx]));
    }
    else{
        it2++;
        it1--;
        xo.erase(xo.lower_bound(0));
        xo.erase(xo.lower_bound(min(a[idx]^*it1,a[idx]^*it2)));
        it1++;
        s.erase(s.lower_bound(a[idx]));
    }
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
    // cin>>te;
    //SieveOfEratosthenes(1000000);
    //factorial(1000005);
    while(te--){
        int q;
        cin>>n>>q;
        for(int i=0;i<n;i++) cin>>a[i];
        int ans[q]={0};
        vv<Query>v;
        for(int i=0;i<q;i++){
            Query x;
            cin>>x.l>>x.r;
            x.l--,x.r--;
            x.idx=i;
            v.pb(x);
        }
        sort(all(v));
        int cur_l=0,cur_r=-1;
        for(Query x:v){
            while(cur_l>x.l){
                cur_l--;
                add(cur_l);
            }
            while(cur_r<x.r){
                cur_r++;
                add(cur_r);
            }
            while(cur_l<x.l){
                remove(cur_l);
                cur_l++;
            }
            while(cur_r>x.r){
                remove(cur_r);
                cur_r--;
            }
            ans[x.idx]=*xo.begin();
        }
        for(int i=0;i<q;i++) cout<<ans[i]<<'\n';
    }
}