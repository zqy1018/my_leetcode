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
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int r1 = 0, r2 = 0, r3 = 0;
            for (int j = 0; j < 9; ++j){
                if(isdigit(board[i][j])){
                    if(r1 & (1 << (board[i][j] - '0'))) return false;
                    r1 |= (1 << (board[i][j] - '0'));
                }
                if(isdigit(board[j][i])){
                    if(r2 & (1 << (board[j][i] - '0'))) return false;
                    r2 |= (1 << (board[j][i] - '0'));
                }
                if(isdigit(board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3])){
                    if(r3 & (1 << (board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] - '0'))) return false;
                    r3 |= (1 << (board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] - '0'));
                }
            }
        }
        return true;
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
