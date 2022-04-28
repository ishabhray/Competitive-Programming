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
        int x1,x2,p1,p2;
        cin>>x1>>p1>>x2>>p2;
        int x=x1;
        while(x>0) x/=10,p1++;
        x=x2;
        while(x>0) x/=10,p2++;
        char ans='=';
        if(p1<p2) ans='<';
        else if(p1>p2) ans='>';
        else{
            stack<int>y1,y2;
            while(x1>0){
                y1.push(x1%10);
                x1/=10;
            }
            while(x2>0){
                y2.push(x2%10);
                x2/=10;
            }
            while(y1.size()&&y2.size()){
                if(y1.top()>y2.top()){
                    ans='>';
                    break;
                }
                if(y1.top()<y2.top()){
                    ans='<';
                    break;
                }
                y1.pop();
                y2.pop();
            }
            if(ans=='='){
                if(y1.size()){
                    while(y1.size()){
                        if(y1.top()) ans='>';
                        y1.pop();
                    }
                }
                if(y2.size()){
                    while(y2.size()){
                        if(y2.top()) ans='<';
                        y2.pop();
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}