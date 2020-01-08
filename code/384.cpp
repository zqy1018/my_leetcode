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
    vector<int> a, f, tmp;
    Solution(vector<int>& nums) {
        a = nums;
        int n = a.size();
        for (int i = 0; i < n; ++i)
            f.push_back(i), tmp.push_back(0);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        srand(time(NULL));
        int n = a.size();
        for (int i = 0; i < 10; ++i){
            for (int j = 1; j < n; ++j){
                int rd = rand() % n;
                if(rd != j) swap(f[rd], f[j]);
                else swap(f[j], f[0]);
            }
        }
        for (int i = 0; i < n; ++i)
            tmp[i] = a[f[i]];
        return tmp;
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
