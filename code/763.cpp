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
    vector<int> partitionLabels(string S) {
        int len = S.size();
        vector<int> lst(150, -1);
        for (int i = 0; i < len; ++i){
            lst[S[i]] = i;
        }
        vector<int> ans;
        int llst = lst[S[0]], cur = 0;
        for(int i = 0; i < len; ){
            int tmp = llst;
            while(i < llst){
                ++i;
                tmp = max(tmp, lst[S[i]]);
            }
            llst = tmp;
            if(llst == i)
                ans.push_back(i - cur + 1), i++, cur = i, llst = lst[S[i]];
        }
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
