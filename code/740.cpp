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
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> A;
        for (int i = 0; i < n; ){
            int j = i; 
            while(j < n && nums[i] == nums[j])
                ++j;
            A.push_back((j - i) * nums[i]);
            if(j == n || nums[j] != nums[i] + 1){
                int k = A.size();
                if(k == 1) ans += A[0];
                else if(k == 2) ans += max(A[0], A[1]);
                else{
                    int f1 = A[1], f2 = A[0];
                    for (int t = 2; t < k; ++t){
                        int tt = max(f1 - A[t - 1], f2) + A[t];
                        f2 = f1, f1 = tt;
                    }
                    ans += max(f1, f2);
                }
                A.clear();
            }
            i = j;
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
