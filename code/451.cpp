#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
	int f = 1, x = 0;
	char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
	while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	return f * x; 
}
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int> > pr;
        for (int i = 0; i < 128; ++i)
            pr.push_back(make_pair(0, i));
        for (char c: s)
            --pr[c].first;
        sort(pr.begin(), pr.end());
        string ans;
        for (int i = 0; pr[i].first != 0; ++i)
            ans.append(-pr[i].first, pr[i].second);
        return ans;
    }
};
Solution sol;
void init(){
    
}
void solve(){
	// sol.convert();
}
int main(){
	init();
	solve();
	return 0;
}
