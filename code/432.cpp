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
// 双向链表都能忘，爬
class AllOne {
    unordered_map<int, unordered_set<string>> val_to_key;
    unordered_map<string, int> key_to_val;
    unordered_map<int, int> left, right;
public:
    /** Initialize your data structure here. */
    AllOne() {
        left[0] = right[0];
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (key_to_val.count(key)){
            int v = key_to_val[key];
            ++key_to_val[key];
            val_to_key[v + 1].insert(key);
            if (val_to_key[v + 1].size() == 1){
                int nxt = right[v];
                left[nxt] = v + 1, right[v + 1] = nxt;
                left[v + 1] = v, right[v] = v + 1;
            }
            val_to_key[v].erase(key);
            if (val_to_key[v].empty()){
                int prev = left[v];
                left[v + 1] = prev, right[prev] = v + 1;
            }
        }else {
            key_to_val[key] = 1;
            val_to_key[1].insert(key);
            if (val_to_key[1].size() == 1){
                int nxt = right[0];
                left[nxt] = 1, right[1] = nxt;
                left[1] = 0, right[0] = 1;
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!key_to_val.count(key)) return ;
        int v = key_to_val[key];
        if (v > 1){
            --key_to_val[key];
            val_to_key[v - 1].insert(key);
            if (val_to_key[v - 1].size() == 1){
                int prev = left[v];
                left[v - 1] = prev, right[v - 1] = v;
                left[v] = v - 1, right[prev] = v - 1;
            }
            val_to_key[v].erase(key);
            if (val_to_key[v].empty()){
                int nxt = right[v];
                left[nxt] = v - 1, right[v - 1] = nxt;
            }
        }else {
            key_to_val.erase(key);
            val_to_key[1].erase(key);
            if (val_to_key[1].empty()){
                int nxt = right[1];
                left[nxt] = 0, right[0] = nxt;
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMinKey() {
        int mini = right[0];
        if (!mini) return string("");
        for (auto& s: val_to_key[mini])
            return s;
        return string("");
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMaxKey() {
        int maxi = left[0];
        if (!maxi) return string("");
        for (auto& s: val_to_key[maxi])
            return s;
        return string("");
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
AllOne sol;
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
