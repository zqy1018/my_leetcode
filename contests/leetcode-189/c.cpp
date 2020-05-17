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

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec){
    for (auto x: vec)
        os << x << " ";
    os << endl;
    return os;
}

template<typename T>
ostream& operator << (ostream& os, const vector<vector<T>>& vec){
    for (auto& v: vec){
        for (auto x: v)
            os << x << " ";
        os << endl;
    }
    return os;
}

class Solution {
    unordered_map<string, int> mp;
    vector<bitset<505> > vec;
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int D = 0;
        for (auto& v: favoriteCompanies){
            for (auto& s: v)
                if (!mp.count(s))   
                    mp[s] = ++D;
        }
        int n = favoriteCompanies.size();
        for (int i = 0; i < n; ++i){
            vec.push_back(bitset<505>());
            for (auto& s: favoriteCompanies[i])
                vec.back().set(mp[s]);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i){
            bool flag = true;
            for (int j = 0; j < n; ++j){
                if (i == j) continue;
                if ((vec[i] & vec[j]) == vec[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(i);
        }
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
