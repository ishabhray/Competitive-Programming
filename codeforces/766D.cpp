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

int p[100005],diff[100005];
int get(int a){
    if(p[p[a]]==p[a])
        return p[a];
    int x=get(p[a]);
    diff[a]=diff[a]^diff[p[a]];
    return p[a]=x;
}

bool uni(int a,int b,int type){
    int a1=get(a),b1=get(b);
    if(a1==b1){
        if(type==1&&diff[a]==diff[b]||type==2&&diff[a]!=diff[b])
            return true;
        else
            return false;
    }
    else{
        p[a1]=b;
        if(type==1&&diff[a]||type==2&&!diff[a])
                diff[a1]=1;
        return true;
    }
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
        int n,m,q;
        cin>>n>>m>>q;
        unordered_map<string,int>k;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            k[s]=i;
        }
        for(int i=1;i<=n;i++)
            p[i]=i,diff[i]=0;
        for(int i=0;i<m;i++){
            int x;
            string s,t;
            cin>>x>>s>>t;
            if(uni(k[s],k[t],x))
                cout<<"YES\n";
            else
                cout<<"NO\n";
            /*for(int i=1;i<=n;i++)
                cout<<p[i]<<' ';
            cout<<'\n';
            for(int i=1;i<=n;i++)
                cout<<diff[i]<<' ';
            cout<<'\n';*/
        }
        for(int i=0;i<q;i++){
            string s,t;
            cin>>s>>t;
            int x=get(k[s]),y=get(k[t]);
            /*for(int i=1;i<=n;i++)
                cout<<p[i]<<' ';
            cout<<'\n';
            for(int i=1;i<=n;i++)
                cout<<diff[i]<<' ';
            cout<<'\n';*/
            if(x!=y)
                cout<<"3\n";
            else{
                if(diff[k[s]]==diff[k[t]])
                    cout<<"1\n";
                else
                    cout<<"2\n";
            }
        }
    }
}