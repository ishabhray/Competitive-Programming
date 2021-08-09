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

struct Node {
    Node *l, *r;
    ll sum;

    Node(int val) : l(nullptr), r(nullptr), sum(val) {}
    Node(Node *l, Node *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Node* build(vl &a, int tl, int tr) {
    if (tl == tr)
        return new Node(a[tl]);
    int tm = (tl + tr) / 2;
    return new Node(build(a, tl, tm), build(a, tm+1, tr));
}

ll get_sum(Node* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Node* update(Node* v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr)
        return new Node(new_val);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Node(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Node(v->l, update(v->r, tm+1, tr, pos, new_val));
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
        int n,q;
        cin>>n>>q;
        vl a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        vv<Node*>v;
        v.pb(build(a,1,n));
        for(int i=0;i<q;i++){
            int t,k;
            cin>>t>>k;
            k--;
            if(t==1){
                int a,x;
                cin>>a>>x;
                v[k]=update(v[k],1,n,a,x);
            }
            else if(t==2){
                int a,b;
                cin>>a>>b;
                cout<<get_sum(v[k],1,n,a,b)<<'\n';
            }
            else{
                v.pb(v[k]);
            }
        }
    }
}