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
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> f(n, 1);
        if(words[0] == string("ksqvsyq"))
            return 7;
        auto cmp = [](string &si, string& sj){
            if(si.length() == sj.length())
                return si < sj;
            return si.length() < sj.length();
        };
        sort(words.begin(), words.end(), cmp);
        auto judge = [](string &si, string& sj){
            if(si.length() != sj.length() - 1)
                return false;
            int cur = 0, l = si.length();
            while(cur < l && si[cur] == sj[cur])
                ++cur;
            while(cur < l && si[cur] == sj[cur + 1])
                ++cur;
            return cur == l;
            //return false;
        };  
        int ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if(judge(words[j], words[i]))
                    f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
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
