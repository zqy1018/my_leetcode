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
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();
        int gg = __gcd(l1, l2);
        for (int i = 1; i * i <= gg; ++i){
            if(gg % i == 0){
                int flag = 1, ll = gg / i;
                if(str1.substr(0, ll) != str2.substr(0, ll))
                    continue;
                do{
                    int t1 = l1 / ll;
                    for (int j = 0; j < ll; ++j){
                        int ff = 1;
                        for (int k = 1; k < t1; ++k){
                            if(str1[(k - 1) * ll + j] != str1[k * ll + j]){
                                ff = 0;
                                break;
                            }
                        }
                        if(!ff) {
                            flag = 0;
                            break;
                        }
                    }
                    if(!flag) break;
                    int t2 = l2 / ll;
                    for (int j = 0; j < ll; ++j){
                        int ff = 1;
                        for (int k = 1; k < t2; ++k){
                            if(str2[(k - 1) * ll + j] != str2[k * ll + j]){
                                ff = 0;
                                break;
                            }
                        }
                        if(!ff) {
                            flag = 0;
                            break;
                        }
                    }
                    if(!flag) break;
                }while(0);
                if(flag){
                    return str1.substr(0, ll);
                }
            }
        }
        return string("");
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
