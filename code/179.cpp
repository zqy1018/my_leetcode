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
    vector<int> ten;
    int getws(int x){
        if(x < 10) return 1;
        if(x < 100) return 2;
        if(x < 1000) return 3;
        if(x < 10000) return 4;
        if(x < 100000) return 5;
        if(x < 1000000) return 6;
        if(x < 10000000) return 7;
        if(x < 100000000) return 8;
        if(x < 1000000000) return 9;
        return 10;
    }
    bool cmp(int a, int b){
        int res1 = getws(a), res2 = getws(b);
        if(res1 == 10 && res2 == 10){

        }else{
            
        }
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        ten = vector<int>{1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
        sort(nums.begin(), nums.end(), cmp);

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
