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

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
class Solution {
public:
    unordered_multiset<int> hor, ver, xie1, xie2;
    set<pair<int, int>> st;
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int q = queries.size(), left = lamps.size();
        vector<int> ans;
        ans.reserve(q);
        for (vector<int>& pos: lamps){
            hor.insert(pos[0]), ver.insert(pos[1]), 
            xie1.insert(pos[0] + pos[1]), xie2.insert(pos[0] - pos[1]);
            st.insert(make_pair(pos[0], pos[1]));
        }
        for (vector<int>& pos: queries){
            int x = pos[0], y = pos[1];
            if (hor.count(x) || ver.count(y) || xie1.count(x + y) || xie2.count(x - y))
                ans.push_back(1);
            else ans.push_back(0);

            pair<int, int> pp(x, y);
            if (st.count(pp)) 
                st.erase(pp), hor.erase(hor.find(x)), ver.erase(ver.find(y)), 
                xie1.erase(xie1.find(x + y)), xie2.erase(xie2.find(x - y)), --left;
            for (int i = 0; i < 8; ++i){
                pp.first += dx[i], pp.second += dy[i], x += dx[i], y += dy[i];
                if (st.count(pp))
                    st.erase(pp), hor.erase(hor.find(x)), ver.erase(ver.find(y)), 
                    xie1.erase(xie1.find(x + y)), xie2.erase(xie2.find(x - y)), --left;
                pp.first -= dx[i], pp.second -= dy[i], x -= dx[i], y -= dy[i];
            }
            if (!left) break;
        } 
        while (ans.size() < queries.size())
            ans.push_back(0);
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
