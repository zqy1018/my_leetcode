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

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i)
            mp[words[i]] = i;
        auto check = [](string& x, int i, int j){
            for (; i < j; ++i, --j)
                if (x[i] != x[j]) return false;
            return true;
        };
        vector<vector<int>> ans;
        string emptystr("");
        for (int i = 0; i < n; ++i){
            int l = words[i].length();
            if (!l) continue;
            if (check(words[i], 0, l - 1)){
                if (mp.count(emptystr)) {
                    int id = mp[emptystr];
                    ans.push_back(vector<int>{i, id}), 
                    ans.push_back(vector<int>{id, i});
                }
            }else {
                string tmp = words[i];
                reverse(tmp.begin(), tmp.end());
                if (mp.count(tmp)){
                    int id = mp[tmp];
                    ans.push_back(vector<int>{id, i});
                }
            }
            string tmpa = words[i];
            reverse(tmpa.begin(), tmpa.end());
            for (int j = 0; j < l - 1; ++j){
                if (check(words[i], 0, j)){
                    string tmp = tmpa.substr(0, l - j - 1);
                    if (mp.count(tmp))
                        ans.push_back(vector<int>{mp[tmp], i});
                }
                if (check(words[i], j + 1, l - 1)){
                    string tmp = tmpa.substr(l - j - 1);
                    if (mp.count(tmp))
                        ans.push_back(vector<int>{i, mp[tmp]});
                }
            }
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
