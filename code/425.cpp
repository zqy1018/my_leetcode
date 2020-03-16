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
    vector<vector<string>> ans;
    vector<int> vec[26][26];
    int tmp[10], l, n;
    void dfs(int cur, vector<string>& words){
        if (cur == l){
            ans.push_back(vector<string>());
            for (int i = 0; i < l; ++i)
                ans.back().push_back(words[tmp[i]]);
            return ;
        }
        auto& v = vec[words[tmp[0]][cur] - 'a'][words[tmp[1]][cur] - 'a'];
        for (int x: v){
            bool flag = true;
            for (int j = 2; j < cur; ++j)
                if (words[x][j] != words[tmp[j]][cur]){
                    flag = false;
                    break;
                }
            if (flag) 
                tmp[cur] = x, dfs(cur + 1, words);
        }   
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        l = words[0].length();
        n = words.size();
        if (l == 1){
            for (auto& p: words)
                ans.push_back(vector<string>{p});
            return ans;
        }
        for (int i = 0; i < n; ++i)
            vec[words[i][0] - 'a'][words[i][1] - 'a'].push_back(i);
        for (int i = 0; i < n; ++i){
            tmp[0] = i;
            int t1 = words[i][1] - 'a';
            for (int j = 0; j < 26; ++j)
                for (int x: vec[t1][j])
                    tmp[1] = x, dfs(2, words);
        }
        return ans;
    }
};
Solution sol;
void init(){
    vector<string> vec{"area","lead","wall","lady","ball"};
    cout << sol.wordSquares(vec) << endl;
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
