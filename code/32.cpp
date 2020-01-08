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
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> s1, s2, s3;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == '('){
                s3.push(i);
            }else{
                if (!s3.empty()){
                    int tp = s3.top();
                    s3.pop();
                    if (!s1.empty() && tp == s1.top() - 1 && i == s2.top() + 1){
                        s1.pop(), s2.pop(), s1.push(tp), s2.push(i);
                    } else {
                        s1.push(tp), s2.push(i);
                    }
                }
            }
            while (s1.size() > 1){
                int l = s1.top(), r = s2.top();
                s1.pop(), s2.pop();
                if (s2.top() == l - 1)
                    s2.pop(), s2.push(r);
                else{
                    s1.push(l), s2.push(r);
                    break;
                }
            }
        }
        
        while (!s1.empty())
            ans = max(ans, s2.top() - s1.top() + 1), 
            s1.pop(), s2.pop();
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
