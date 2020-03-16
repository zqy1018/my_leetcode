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
    vector<int> tt[26], id;
public:
    string rankTeams(vector<string>& votes) {
        int n= votes.size(), m = votes[0].size();
        for (char c: votes[0])
            id.push_back(c - 'A'), 
            tt[c - 'A'] = vector<int>(m, 0);
        for (string& s: votes){
            for (int i = 0; i < m; ++i)
                ++tt[s[i] - 'A'][i];
        }
        sort(id.begin(), id.end(), [&](int i, int j){
            for (int u = 0; u < m; ++u){
                if (tt[i][u] != tt[j][u])
                    return tt[i][u] > tt[j][u];
            }
            return i < j;
        });
        string ans;
        for (int x: id)
            ans.push_back('A' + x);
            return ans;
    }
};
Solution sol;
void init(){
    vector<string> vec{"BCA","CAB","CBA","ABC","ACB","BAC"};
    cout << sol.rankTeams(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
