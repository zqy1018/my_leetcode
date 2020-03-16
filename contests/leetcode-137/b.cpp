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
    string removeDuplicates(string S) {
        vector<char> s;
        for (char c: S){
            if(!s.empty()){
                if(s.back() == c) s.pop_back();
                else s.push_back(c); 
            }else{
                s.push_back(c);
            }
        }
        string cc;
        for (char c: s)
            cc.append(1, c);
        return cc;
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
