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
    while(te--){
        int n,q;
        cin>>n>>q;
        int a[n];
        set<int>s;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s.insert(a[i]);
        }
        sort(a,a+n);
        multiset<int,greater<int> >diff;
        int sum=0;
        for(int i=1;i<n;i++){
            diff.insert(a[i]-a[i-1]);
            sum+=a[i]-a[i-1];
        }
        cout<<sum-*(diff.begin())<<'\n';
        while(q--){
            int c,x;
            cin>>c>>x;
            if(c){
                auto z=s.insert(x);
                auto cur=z.ff;
                auto pre=cur,nex=cur;
                nex++;
                if(cur==s.begin()&&nex!=s.end()){
                    diff.insert(*nex-x);
                }
                else{
                    pre--;
                    diff.insert(x-*pre);
                    if(nex!=s.end()){
                        diff.insert(*nex-x);
                        diff.erase(diff.lower_bound(*nex-*pre));
                    }
                }
                auto j=s.end();
                j--;
                sum=*j-*(s.begin());
                if(!diff.empty())
                    sum-=*(diff.begin());
                cout<<sum<<'\n';
            }
            else{
                if(s.size()<2){
                    s.erase(x);
                    cout<<"0\n";
                    continue;
                }
                auto it=s.lower_bound(x);
                if(it==s.begin()){
                    it++;
                    diff.erase(diff.lower_bound(*it-x));
                }
                else{
                    it--;
                    diff.erase(diff.lower_bound(x-*it));
                    auto it1=s.upper_bound(x);
                    if(it1!=s.end()){
                        diff.erase(diff.lower_bound(*it1-x));
                        diff.insert(*it1-*it);
                    }
                }
                s.erase(x);
                
                auto j=s.end();
                j--;
                sum=*j-*(s.begin());
                sum-=*(diff.begin());
                cout<<sum<<'\n';
            }
        }
    }
}