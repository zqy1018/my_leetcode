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
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "zxcvbnm";
        vector<int> mp(26, 0);
        for (char c: s1) mp[c - 'a'] = 1;
        for (char c: s2) mp[c - 'a'] = 2;
        for (char c: s3) mp[c - 'a'] = 3;
        vector<string> ans;
        for (string s: words){
            int id = 0, flag = 1;
            for (char c: s){
                c = tolower(c);
                if(!id) id = mp[c - 'a'];
                else if(id != mp[c - 'a']) {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans.push_back(s);
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
