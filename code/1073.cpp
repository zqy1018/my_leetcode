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
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size(), r = max(n, m);
        vector<int> arr(r + 2, 0);
        for (int i = 0; i < r; ++i){
            if (i < n) arr[i] += arr1[n - i - 1];
            if (i < m) arr[i] += arr2[m - i - 1];
            if (arr[i] == 2 || arr[i] == 3){
                if (arr[i + 1]) --arr[i + 1];
                else ++arr[i + 1], ++arr[i + 2];
                arr[i] -= 2;
            }else if (arr[i] == 4)
                ++arr[i + 2], arr[i] = 0;
        }
        if (arr[r] == 2){
            if (arr[r + 1] == 1) arr[r] -= 2, --arr[r + 1];
            else ++arr[r + 1], arr.push_back(1);
        }
        while (arr.size() > 1 && arr[arr.size() - 1] == 0)
            arr.pop_back();
        reverse(arr.begin(), arr.end());
        return arr;
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
