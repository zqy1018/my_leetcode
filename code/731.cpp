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

class MyCalendarTwo {
public:
    vector<int> l1, r1, l2, r2;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int f1 = -1, f2 = -1;
        for (int i = 0; i < l1.size(); ++i)  
            if (start < r1[i] && end > l1[i]) {
                f1 = i;
                break;
            }
        if (f1 < 0){
            l1.push_back(start), r1.push_back(end);
            return true;
        }
        if (start < l1[f1]){
            if (end <= r1[f1]){

            }else {

            }
        }
        for (int i = 0; i < l2.size(); ++i)  
            if (start < r2[i] && end > l2[i]) {
                f2 = true;
                break;
            }
        if (f1 && f2) return false;
        if (f1) l2.push_back(start), r2.push_back(end);
        else l1.push_back(start), r1.push_back(end);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
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
