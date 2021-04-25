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
int p[200005];
int get(int a){
    return p[a]=(p[a]==a)?a:get(p[a]);
}
void uni(int a,int b){
    a=get(a),b=get(b);
    if(a==b)
        return;
    p[a]=b;
}
bool comp(const pair<ii,ii >&l,const pair<ii,ii >&r){
    return l.ff.ff>r.ff.ff;
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
        int n,m;
        ll s;
        cin>>n>>m>>s;
        vv<pair<ii,ii > >v(m);
        for(int i=0;i<m;i++){
            cin>>v[i].ss.ff>>v[i].ss.ss>>v[i].ff.ff;
            v[i].ff.ss=i+1;
        }
        sort(all(v),comp);
        for(int i=1;i<=n;i++)
            p[i]=i;
        vv<ii > c;
        for(auto i:v){
            int x=i.ss.ff,y=i.ss.ss;
            x=get(x),y=get(y);
            if(x==y)
                c.pb({i.ff.ff,i.ff.ss});
            else
                uni(x,y);
        }
        sort(all(c));
        vi ans;
        ll sum=0;
        for(auto i:c){
            sum+=i.ff;
            if(sum>s)
                break;
            ans.pb(i.ss);
        }
        cout<<ans.size()<<'\n';
        for(int i:ans)
            cout<<i<<' ';
    }
}