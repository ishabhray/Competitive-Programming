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
        int w,h,n;
        cin>>w>>h>>n;
        multiset<int>x,y;
        x.insert(h);
        y.insert(w);
        set<int>hor,ver;
        hor.insert(0);
        hor.insert(h);
        ver.insert(0);
        ver.insert(w);
        for(int i=0;i<n;i++){
            char ch;
            int z;
            cin>>ch>>z;
            if(ch=='H'){
                auto it=hor.lower_bound(z);
                auto it1=hor.upper_bound(z);
                it--;
                x.erase(x.lower_bound(*it1-*it));
                x.insert(z-*it);
                x.insert(*it1-z);
                hor.insert(z);
            }
            else{
                auto it=ver.lower_bound(z);
                auto it1=ver.upper_bound(z);
                it--;
                y.erase(y.lower_bound(*it1-*it));
                y.insert(z-*it);
                y.insert(*it1-z);
                ver.insert(z);
            }
            auto it=x.end();
            it--;
            ll area=*it;
            it=y.end();
            it--;
            area*=*it;
            cout<<area<<'\n';
        }
    }
}