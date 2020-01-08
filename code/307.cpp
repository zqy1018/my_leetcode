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
class NumArray {
private:
    vector<int> c, num;
    int n;
    int lowbit(int x){
        return x & (-x);
    }
    int query(int x){
        int res = 0;
        while(x)
            res += c[x], x -= lowbit(x);
        return res;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        c.push_back(0);
        for (int i = 0; i < n; ++i)
            num.push_back(nums[i]), c.push_back(nums[i]);
        for (int i = 0; (1 << i) < n; ++i){
            int k = (1 << i);
            for (int j = k; j + k <= n; j += k + k)
                c[j + k] += c[j];
        }
    }
    
    void update(int i, int val) {
        int v = val - num[i];
        num[i] = val;
        i++;
        while(i <= n)
            c[i] += v, i += lowbit(i);
    }
    
    int sumRange(int i, int j) {
        return query(j + 1) - query(i);
    }
};
NumArray sol;
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
