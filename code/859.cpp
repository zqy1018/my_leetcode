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
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        int n = A.size();
        if(n <= 1) return false;
        vector<int> hp1(27, 0), hp2(27, 0);
        int pos1 = -1, pos2 = -1;
        for (int i = 0; i < n; ++i){
            hp1[A[i] - 'a']++;
            hp2[B[i] - 'a']++;
            if(A[i] != B[i]) {
                if(pos1 >= 0) {
                    if(pos2 >= 0) return false;
                    else pos2 = i;
                }else{
                    pos1 = i;
                }
            }
        }
        if(pos1 == -1) {
            for (int i = 0; i < 26; ++i) 
                if(hp1[i] >= 2) return true;
            return false;
        }else{
            if(pos2 == -1) return false;
            else{
                return (A[pos1] == B[pos2] && A[pos2] == B[pos1]);
            }
        }
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
