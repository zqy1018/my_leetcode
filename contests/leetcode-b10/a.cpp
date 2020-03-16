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
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> vec, vec2;
        int l1 = arr1.size(), l2 = arr2.size(), l3 = arr3.size();
        int i = 0, j = 0, k = 0;
        while (i < l1 && j < l2){
            if (arr1[i] < arr2[j]) ++i;
            else if (arr1[i] > arr2[j]) ++j;
            else vec.push_back(arr1[i]), ++i, ++j;
        }
        int lt = vec.size(), t = 0;
        while (t < lt && k < l3){
            if (vec[t] < arr3[k]) ++t;
            else if (vec[t] > arr3[k]) ++k;
            else vec2.push_back(vec[t]), ++t, ++k;
        }
        return vec2;
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
