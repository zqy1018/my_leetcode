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
    int lis[1005], tot;
    int n, l;
    vector<pair<int, char>> vec;
    string ans;
    bool check(vector<string>& dictionary){
        for (int i = 0; i < tot; ++i){
            string& s = dictionary[lis[i]];
            bool flag = true;
            int cur = 0;
            for (auto& p: vec){
                if (p.first == -1){
                    if (p.second != s[cur]){
                        flag = false;
                        break;
                    }
                    ++cur;
                }else cur += p.first;
            }
            if (flag) return false;
        }
        return true;
    }
    void dfs(int cur, int acc, string& target, vector<string>& dictionary){
        if (cur == l){
            if (acc > 0)
                vec.push_back(make_pair(acc, 0));
            if (check(dictionary) && (ans.length() == 0 || ans.length() > vec.size())){
                // 组装
                ans.clear();            // 这里最好改掉去
                for (auto& p: vec){
                    if (p.first == -1)
                        ans.push_back(p.second);
                    else 
                        ans += to_string(p.first);
                }
            }
            if (acc > 0)
                vec.push_back(make_pair(acc, 0));
            return ;
        }
        // 缩掉
        dfs(cur + 1, acc + 1, target, dictionary);
        // 不缩
        if (acc > 0)
            vec.push_back(make_pair(acc, 0));
        vec.push_back(make_pair(-1, target[cur]));
        dfs(cur + 1, 0, target, dictionary);
        vec.pop_back();
        if (acc > 0)
            vec.pop_back();
    }
    string minAbbreviation(string target, vector<string>& dictionary) {
        tot = 0;
        n = dictionary.size(), l = target.length();
        ans = string("");
        for (int i = 0; i < n; ++i) 
            if (dictionary[i].length() == l)
                lis[tot++] = i;
        dfs(0, 0, target, dictionary);
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
