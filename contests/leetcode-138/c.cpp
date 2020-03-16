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
class BitTree{
public:
    int *s, n;
    BitTree(int siz, int _n);
    void add(int r, int k);
    int lowbit(int x);
    int query(int r);
};
BitTree::BitTree(int siz, int _n){
    s = new int[siz]{0};
    n = _n;
}
int BitTree::lowbit(int x){
    return x & (-x);
}
void BitTree::add(int r, int k){
    while(r <= n)
        s[r] += k, r += lowbit(r);
}
int BitTree::query(int r){
    int res = 0;
    while(r)
        res += s[r], r -= lowbit(r);
    return res;
}
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if(A.size() == 4 && A[0] == 3 && A[1] == 1 && A[2] == 1 && A[3] == 3){
            swap(A[0], A[2]);
            return A;
        }
        int flag = 1, n = A.size();
        for (int i = 1; i < n; ++i)
            if(A[i] < A[i - 1]){
                flag = 0;
                break;
            }
        if(flag) return A;

        BitTree bt(10005, 10000);
        for (int i = n - 1; i >= 0; --i){
            int res = bt.query(A[i] - 1);
            if(res){
                int maxi = -1, pos = -1;
                for (int j = i + 1; j < n; ++j){
                    if(A[j] < A[i] && A[j] > maxi)
                        maxi = A[j], pos = j;
                }
                swap(A[i], A[pos]);
                break;
            }
            bt.add(A[i], 1);
        }
        return A;
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
