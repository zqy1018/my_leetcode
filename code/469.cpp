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

ostream& operator << (ostream& os, const vector<int>& vec){
    for (int x: vec)
        os << x << " ";
    os << endl;
}

ostream& operator << (ostream& os, const vector<vector<int>>& vec){
    for (auto& v: vec){
        for (int x: v)
            os << x << " ";
        os << endl;
    }
}

class Solution {
    int sgn(int x){
        return x > 0 ? 1: (x < 0 ? -1: 0);
    }
    int cross(int xx1, int yy1, int xx2, int yy2){
        return xx1 * yy2 - xx2 * yy1;
    }
    int toleft(vector<int>& pa, vector<int>& pb, vector<int>& pc){
        return sgn(cross(pc[0] - pa[0], pc[1] - pa[1], pc[0] - pb[0], pc[1] - pb[1]));
    }
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        int sg = toleft(points[n - 2], points[n - 1], points[0]);
        int sg2 = toleft(points[n - 1], points[0], points[1]);
        if (sg != 0 && sg2 != 0 && sg != sg2)
            return false;
        if (sg == 0 && sg2 != 0)
            sg = sg2;
        for (int i = 2; i < n; ++i){
            int sg3 = toleft(points[i - 2], points[i - 1], points[i]);
            if (sg != 0 && sg3 != 0 && sg != sg3)
                return false;
            if (sg == 0 && sg3 != 0)
                sg = sg3;
        }
        return true;
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
