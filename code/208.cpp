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
    vector<bool> isend;
    int cnt;
public:
    /** Initialize your data structure here. */
    Trie() {
        trie = vector<vector<int> >(2, vector<int>(26, 0));
        isend = vector<bool>(2, 0);
        cnt = 1;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int rt = 1;
        for (char c: word){
            if(!trie[rt][c - 'a'])
                trie.push_back(vector<int>(26, 0)), 
                isend.push_back(false), 
                trie[rt][c - 'a'] = ++cnt;
            rt = trie[rt][c - 'a'];
        }
        isend[rt] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int rt = 1, n = word.size(), cur = 0;
        for (; cur < n && rt; ++cur){
            rt = trie[rt][word[cur] - 'a'];
        }
        if(rt && isend[rt]) return true;
        return false; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int rt = 1, n = prefix.size(), cur = 0;
        for (; cur < n && rt; ++cur){
            rt = trie[rt][prefix[cur] - 'a'];
        }
        if(rt) return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
Trie sol;
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
