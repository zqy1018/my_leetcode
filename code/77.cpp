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
    vector<vector<int>> combine(int n, int k) {
        struct Cmp{
            vector<int> vc;
            Cmp(int n, int k){
                vc.resize(k);
            }
            void fun(vector<vector<int> > &ans, int index, int left, int n){
                if(!left){
                    ans.push_back(vc);
                    return ;
                }
                for (int i = index; i <= n - left; ++i){
                    vc[left - 1] = i + 1;
                    fun(ans, i + 1, left - 1, n);
                }
            }
        };
        Cmp cc(n, k);
        vector<vector<int> > ans;
        cc.fun(ans, 0, k, n);
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
