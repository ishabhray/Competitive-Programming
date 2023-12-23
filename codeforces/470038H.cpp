#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    for(int xxx=999996999;xxx<=999999999;xxx++){
        for(int yy=999996999;yy<=999999999;yy++)
{	string a, b;
	// cin >> a >> b;
    a=to_string(xxx);
    b=to_string(yy);
  int reqa, reqb;
  reqa = stoi(a);
  reqb = stoi(b);
  
	// cout << "Stable\n";

	if(a == b){
		// cout << "0\n";
		continue;
	}

	vector <long> add(10);
	long x = 81;
	for(int i = 1; i < 10; i++){
		add[i] = x;
		x -= 9;
	}
	vector <long> po(19);
	po[0] = 1;
	for(int i = 1; i <= 18; i++)
		po[i] = po[i - 1] * 10;
	int dig = 0;
	int n, m;
	n = a.length();
	m = b.length();
	int i = n - 1;
	int j = m - 1;
	vector <pair<int,int>> ops;
	int hav = 0;
	while(i >= 0 && j >= 0){
		int cur = a[i] - '0';
		cur += hav;
		int carry = cur / 10;
		cur %= 10;
		int tar = b[j] - '0';
		int req = (tar - cur + 10) % 10;
		if(req == 0){
		  j--;
		  i--;
		  dig++;
		  hav = carry;
		  continue;
		}
		ops.push_back({1, add[req] / 9 * po[m - 1 - j]});
		cur += add[req];
		carry += cur / 10;
		hav = carry;
		i--;
		j--;
		dig++;
	}
	while(j >= 0){
		int cur = hav;
		int carry = cur / 10;
		cur %= 10;
		int tar = b[j] - '0';
		int req = (tar - cur + 10) % 10;
		if(req == 0){
		  j--;
		  dig++;
		  hav = carry;
		  continue;
		}
		ops.push_back({1, add[req] / 9 * po[m - 1 - j]});
		cur += add[req];
		carry += cur / 10;
		hav = carry;
		j--;
		dig++;
	}
	int cnt = 0;
	while(i >= 0 || hav > 0){
		int cur = 0;
		if(i >= 0)
			cur += a[i] - '0';
		cur += hav;
		int carry = cur / 10;
		cur %= 10;
		int tar = 1;
		int req = (tar - cur + 10) % 10;
		if(req == 0){
		  cnt++;
		  i--;
		  dig++;
		  hav = carry;
		  continue;
		}
		ops.push_back({1, add[req] / 9 * po[dig]});
		cur += add[req];
		carry += cur / 10;
		hav = carry;
		cnt++;
		i--;
		dig++;
	}
	if(cnt)
		ops.push_back({2, cnt});
	// cout << ops.size() << "\n";
	int xx = 0;
	for(auto i : ops){
		// if(i.first == 1)
		// 	cout << "+ ";
		// else
		// 	cout << "- ";
		if(i.first == 1)
		  xx += i.second;
		// cout << i.second << "\n";
	}
	reqa += xx * 9;
    
	while(cnt--){
	  int digi = 0;
	  int z = reqb;
	  int mul = 1;
      if (reqb==0) mul=10;
	  while(z > 0){
	    digi++;
	    mul *= 10;
	    z /= 10;
	  }
	  reqb = reqb + mul; 
	}
    
    if(reqa != reqb){cout<<a<<" "<<b<<" "<<reqa<<" "<<reqb<<"\n";return 1;}
    }}
    
}
