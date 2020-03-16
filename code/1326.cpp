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
    vector<pair<int, int>> vec;
public:
    int minTaps(int n, vector<int>& ranges) {
        for (int i = 0; i <= n; ++i){
            int ll = max(0, i - ranges[i]), rr = min(n, i + ranges[i]);
            if (rr > ll) vec.push_back(make_pair(ll + 1, rr));
        }
        sort(vec.begin(), vec.end(), [](const pair<int, int>& pa, const pair<int, int>& pb){
            if (pa.first == pb.first) return pa.second > pb.second;
            return pa.first < pb.first; 
        });
        if (vec.empty()) return -1;
        if (vec[0].first > 1) return -1;
        int ans = 1, m = vec.size(), r = vec[0].second, maxr = vec[0].second;
        //for (int i = 0; i < m; ++i)
        //    cout << vec[i].first << " " << vec[i].second << endl;
        for (int i = 1; i < m; ++i){
            if (vec[i].first <= r + 1) maxr = max(maxr, vec[i].second);
            else {
                if (maxr + 1 < vec[i].first)
                    return -1;
                ++ans, r = maxr, --i;
            }
        }
        if (r < n) {
            if (maxr == n) ++ans;
            else return -1;
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
