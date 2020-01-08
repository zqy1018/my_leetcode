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
class AllOne {
public:
    map<string, int> mp;
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!mp.count(key)) mp[key] = 1;
        else mp[key]++;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(mp.count(key)) {
            if(mp[key] == 1) mp.erase(key);
            else mp[key]--;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMinKey() {
        if(mp.empty()) return string("");
        map<string, int>::const_iterator it = mp.end(); 
        --it;
        return it->first;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMaxKey() {
        if(mp.empty()) return string("");
        map<string, int>::const_iterator it = mp.begin(); 
        return it->first;
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
