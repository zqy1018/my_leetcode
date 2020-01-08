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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int> vec;
    unordered_map<int, unordered_set<int>> mp;
    int siz;
    RandomizedCollection() {
        siz = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = mp.count(val) ? false: true;
        //if (!flag) mp.insert(make_pair(val, unordered_set<int>()));
        if (!flag) flag = mp[val].empty();
        vec.push_back(val);
        mp[val].insert(siz);
        ++siz;
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!mp.count(val)) return false;
        if (mp[val].empty()) return false;
        if (vec.back() == val){
            mp[val].erase(siz - 1), vec.pop_back(), --siz;
            return true;
        }
        int id = *(mp[val].begin());
        if (id != siz - 1) {
            mp[vec.back()].erase(siz - 1);
            mp[vec.back()].insert(id);
            vec[id] = vec.back();
        }
        mp[val].erase(id), vec.pop_back(), --siz;
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int id = rand() % siz;
        return vec[id];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
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
