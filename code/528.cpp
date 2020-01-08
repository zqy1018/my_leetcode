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
    vector<int> ww;
    Solution(vector<int>& w) {
        srand(time(NULL));
        int n = w.size();
        ww.push_back(0), ww.push_back(w[0]);
        for (int i = 1; i < n; ++i) w[i] += w[i - 1], ww.push_back(w[i]);
    }
    
    int pickIndex() {
        return upper_bound(ww.begin(), ww.end(), rand() % ww.back()) - ww.begin() - 1;
    }
};

void init(){
    vector<int> vec{1, 4};
    Solution sol(vec);
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    cout << " " << sol.pickIndex() << endl;
    
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
