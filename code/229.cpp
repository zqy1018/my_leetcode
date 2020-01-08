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
    vector<int> majorityElement(vector<int>& nums) {
        int cx = 0, cy = 0, ax, ay;
        for (int i: nums){
            if(cx && ax == i) cx++;
            else if(cy && ay == i) cy++;
            else if(!cx) ax = i, cx = 1;
            else if(!cy) ay = i, cy = 1;
            else --cx, --cy;
        }
        int n = nums.size(), cnt = 0;
        vector<int> ans;
        for (int i: nums)
            if(i == ax) cnt++;
        if(cnt > n / 3) ans.push_back(ax);
        if(cy){
            cnt = 0;
            for (int i: nums)
                if(i == ay) cnt++;
            if(cnt > n / 3) ans.push_back(ay);
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
