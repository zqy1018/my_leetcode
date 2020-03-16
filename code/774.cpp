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
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        sort(stations.begin(), stations.end());
        double l = 0, r = 0;
        int n = stations.size();
        for (int i = 0; i < n - 1; ++i)
            r = max(r, 1.0 * stations[i + 1] - stations[i]);
        while (r - l > 1e-6){
            double mid = (l + r) * 0.5;
            int left = K;
            for (int i = 0; i < n - 1; ++i){
                int nd = static_cast<int>(ceil((stations[i + 1] - stations[i]) / mid)) - 1;
                left -= nd;
                if (left < 0) break;
            }
            if (left >= 0) r = mid;
            else l = mid;
        }
        return l;
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
