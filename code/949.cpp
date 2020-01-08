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
    string largestTimeFromDigits(vector<int>& A) {
        int cnt[10] = {0};
        char ans[10] = {0};
        for (int i: A) cnt[i]++;
        for (int i = 23; i >= 0; --i){
            if(i % 10 == i / 10){
                if(cnt[i % 10] >= 2){
                    cnt[i % 10] -= 2;
                    for (int j = 59; j >= 0; --j){
                        if(j % 10 == j / 10){
                            if(cnt[j % 10] >= 2){
                                sprintf(ans, "%02d:%02d", i, j);
                                return string(ans);
                            }
                        }else{
                            if(cnt[j % 10] && cnt[j / 10]){
                                sprintf(ans, "%02d:%02d", i, j);
                                return string(ans);
                            }
                        }
                    }
                    cnt[i % 10] += 2;
                }
            }else {
                if(cnt[i % 10] && cnt[i / 10]){
                    cnt[i % 10]--, cnt[i / 10]--;
                    for (int j = 59; j >= 0; --j){
                        if(j % 10 == j / 10){
                            if(cnt[j % 10] >= 2){
                                sprintf(ans, "%02d:%02d", i, j);
                                return string(ans);
                            }
                        }else{
                            if(cnt[j % 10] && cnt[j / 10]){
                                sprintf(ans, "%02d:%02d", i, j);
                                return string(ans);
                            }
                        }
                    }
                    cnt[i % 10]++, cnt[i / 10]++;
                }
            }
        }
        return string();
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
