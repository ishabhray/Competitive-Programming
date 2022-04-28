#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")


#include <bits/stdc++.h>
#define ll int

using namespace std;
int calculateMaximizedReturns(int n, int k, int d, int m, vector<int> returns) {
	// Participant's code will go here
	vector <vector <int>> dp(k + 1, vector <int>(n + 1, -1e9));
	dp[0][0] = 0;
	for (ll i = 0; i < n; i++) {
		vector <vector <int>> ndp(k + 1, vector <int>(n + 1, -1e9));
		for (ll j = 1; j <= min(k,i); j++) {
			for (ll l = 1; l <= i; l++) {
				if (dp[j][l] < 0)
					continue;
				if (j < k)
					ndp[j + 1][i + 1] = max(ndp[j + 1][i + 1], dp[j][l]);
				if ((i + 1 - l) <= d)
					ndp[j][l] = max(ndp[j][l], dp[j][l] + returns[i] * m);
				else
					ndp[j][l] = max(ndp[j][l], dp[j][l] + returns[i]);
			}
		}
		ndp[0][0] = dp[0][0] + returns[i];
		ndp[1][i + 1] = max(ndp[1][i + 1], dp[0][0]);
		dp = ndp;
	}
	int ans = -1e9;
	for (ll i = 1; i <= n; i++) {
		ans = max(ans, dp[k][i]);
	}
	return ans;
}

vector<string> split(const string& str, char delim) {
	vector<string> strings;
	size_t start;
	size_t end = 0;
	while ((start = str.find_first_not_of(delim, end)) != string::npos) {
		end = str.find(delim, start);
		strings.push_back(str.substr(start, end - start));
	}
	return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
	vector<int> strings;
	size_t start;
	size_t end = 0;
	while ((start = str.find_first_not_of(delim, end)) != string::npos) {
		end = str.find(delim, start);
		strings.push_back(stoi(str.substr(start, end - start)));
	}
	return strings;
}

void printVector(vector<int> vec) {
	for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

void printVector(vector<string> vec) {
	for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}

int main() {
	clock_t start, end;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
	string firstLine;
	getline(cin, firstLine);

	vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
	int n = firstLineVec[0];
	int k = firstLineVec[1];
	int d = firstLineVec[2];
	int m = firstLineVec[3];

	string returns;
	getline(cin, returns);

	vector<int> returnsVec = splitStringToInt(returns, ' ');

    start=clock();
	int result = calculateMaximizedReturns(n, k, d, m, returnsVec);

	// Do not remove below line
	end=clock();
    double time_taken=double(end - start)/ double(CLOCKS_PER_SEC);
    cout<<"Execution Time: "<<time_taken<<" seconds\n";
	cout << result << "\n";
	// Do not print anything after this line

	return 0;
}