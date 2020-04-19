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
    set<string> st;
    map<int, map<string, int> > mp;
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        for (auto& v: orders){
            st.insert(v[2]);
            int x = 0;
            for (char c: v[1])
                x = x * 10 + c - '0';
            if (!mp.count(x))
                mp[x] = map<string, int>();
            if (!mp[x].count(v[2]))
                mp[x][v[2]] = 0;
            ++mp[x][v[2]];
        }
        ans.push_back(vector<string>());
        ans[0].push_back("Table");
        for (auto& s: st)
            ans[0].push_back(s);
        for (auto& p: mp){
            ans.push_back(vector<string>());
            ans.back().push_back(to_string(p.first));
            for (auto& s: st){
                if (!p.second.count(s))
                    ans.back().push_back("0");
                else 
                    ans.back().push_back(to_string(p.second[s]));
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
