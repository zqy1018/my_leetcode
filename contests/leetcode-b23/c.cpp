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
    int dis(int xx1, int yy1, int xx2, int yy2){
        return (xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2);
    }
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        bool res1 = (x_center < x1 || x_center > x2 || y_center < y1 || y_center > y2);
        bool res2 = (x_center + radius < x1 || x_center - radius > x2 || y_center - radius > y2 || y_center + radius < y1);
        if (res2) return false;
        if (!res1) return true;
        if (dis(x1, y2, x_center, y_center) <= radius * radius) return true;
        if (dis(x2, y2, x_center, y_center) <= radius * radius) return true;
        if (dis(x1, y1, x_center, y_center) <= radius * radius) return true;
        if (dis(x2, y1, x_center, y_center) <= radius * radius) return true;
        if (x_center + radius >= x1 && x_center + radius <= x2 && y_center >= y1 && y_center <= y2)
            return true;
        if (x_center - radius >= x1 && x_center - radius <= x2 && y_center >= y1 && y_center <= y2)
            return true;
        if (x_center >= x1 && x_center <= x2 && y_center + radius >= y1 && y_center + radius <= y2)
            return true;
        if (x_center >= x1 && x_center <= x2 && y_center - radius >= y1 && y_center - radius <= y2)
            return true;
        return false;
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
