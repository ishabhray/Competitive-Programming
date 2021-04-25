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
    //factorial(1000005);
    while(te--){
        int n1,n2,n3,n4;
        cin>>n1>>n2>>n3>>n4;
        int a[n1],b[n2],c[n3],d[n4];
        for(int i=0;i<n1;i++){cin>>a[i];}
        for(int i=0;i<n2;i++){cin>>b[i];}
        for(int i=0;i<n3;i++){cin>>c[i];}
        for(int i=0;i<n4;i++){cin>>d[i];}
        int m;
        vi x[n2],y[n3],z[n4];
        cin>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            x[v].pb(u);
        }
        cin>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            y[v].pb(u);
        }
        cin>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            z[v].pb(u);
        }
        multiset<int>s;
        for(int i=0;i<n1;i++)
            s.insert(a[i]);
        for(int i=0;i<n2;i++){
            for(int j:x[i])
                s.erase(s.find(a[j]));
            if(s.empty())
                b[i]=-1;
            else
                b[i]+=*s.begin();
            for(int j:x[i])
                s.insert(a[j]);
        }
        s.clear();
        for(int i=0;i<n2;i++){
            if(b[i]!=-1)
                s.insert(b[i]);
        }
        for(int i=0;i<n3;i++){
            for(int j:y[i]){
                if(b[j]!=-1)
                    s.erase(s.find(b[j]));
            }
            if(s.empty())
                c[i]=-1;
            else
                c[i]+=*s.begin();
            for(int j:y[i]){
                if(b[j]!=-1)
                    s.insert(b[j]);
            }
        }
        s.clear();
        for(int i=0;i<n3;i++){
            if(c[i]!=-1)
                s.insert(c[i]);
        }
        for(int i=0;i<n4;i++){
            for(int j:z[i]){
                if(c[j]!=-1)
                    s.erase(s.find(c[j]));
            }
            if(s.empty())
                d[i]=-1;
            else
                d[i]+=*s.begin();
            for(int j:z[i]){
                if(c[j]!=-1)
                    s.insert(c[j]);
            }
        }
        s.clear();
        for(int i=0;i<n4;i++){
            if(d[i]!=-1)
                s.insert(d[i]);
        }
        if(s.empty())
            cout<<-1;
        else
            cout<<*s.begin();
    }
}