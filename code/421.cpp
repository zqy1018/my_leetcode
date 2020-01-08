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
class Trie {
private:
    vector<vector<int> > trie;
    int cnt;
public:
    /** Initialize your data structure here. */
    Trie() {
        trie = vector<vector<int> >(2, vector<int>(2, 0));
        cnt = 1;
    }
    
    /** Inserts a word into the trie. */
    void insert(int x) {
        int rt = 1;
        for(int i = (1 << 30); i; i >>= 1){
            int res = ((i & x) == i) ? 1: 0;
            if(!trie[rt][res])
                trie.push_back(vector<int>(2, 0)), 
                trie[rt][res] = ++cnt;
            rt = trie[rt][res];
        }
    }
    
    /** Returns if the word is in the trie. */
    int search(int x) {
        int rt = 1, res = 0;
        for(int i = (1 << 30); i; i >>= 1){
            int B = ((i & x) == i) ? 1: 0;
            if(!trie[rt][B ^ 1])
                rt = trie[rt][B];
            else
                rt = trie[rt][B ^ 1], res |= i;
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for (int i: nums)
            t.insert(i);
        int ans = 0;
        for (int i: nums)
            ans = max(ans, t.search(i));
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
