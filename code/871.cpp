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
    priority_queue<int> pq;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        vector<pair<int, int> > vec;
        for (auto& p: stations)
            vec.push_back(make_pair(p[0], p[1]));
        sort(vec.begin(), vec.end());
        int lst = 0, ans = 0;
        for (auto& p: vec)  {
            int pos = p.first, f = p.second;
            while (startFuel < pos - lst && !pq.empty()){
                int tt = pq.top();
                startFuel += tt;
                pq.pop();
                ++ans;
            }
            if (startFuel < pos - lst) return -1;
            startFuel -= (pos - lst);
            lst = pos;
            pq.push(f);
        }
        while (startFuel < target - lst && !pq.empty()){
            int tt = pq.top();
            startFuel += tt;
            pq.pop();
            ++ans;
        }
        if (startFuel < target - lst) return -1;
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
