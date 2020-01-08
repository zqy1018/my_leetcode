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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cur = 0, n = words.size();
        vector<string> ans;
        while(cur < n){
            string curstr(maxWidth, ' ');
            int j = cur + 1, cnt = words[cur].size(); 
            while(j < n && cnt + words[j].size() + j - cur <= maxWidth)
                cnt += words[j].size(), ++j;
            int num_of_space = maxWidth - cnt;
            if(j - cur == 1){
                for (int i = 0; i < cnt; ++i)
                    curstr[i] = words[cur][i];
            }else if(j == n){
                for (int i = 0, len = 0; i < n - cur; ++i){
                    int siz = words[cur + i].size();
                    for (int j = 0; j < siz; ++j)
                        curstr[len++] = words[cur + i][j];
                    len++;
                }
            }else{
                int pos = (j - cur - 1), bas = num_of_space / pos;
                int left = num_of_space % pos;
                for (int i = 0, len = 0; i <= pos; ++i){
                    int siz = words[cur + i].size();
                    for (int j = 0; j < siz; ++j)
                        curstr[len++] = words[cur + i][j];
                    len += bas;
                    if(left) len++, left--;
                }
            }
            ans.push_back(curstr);
            cur = j;
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
