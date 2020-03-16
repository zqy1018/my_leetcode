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
class Cashier {
    int nn, dis;
    map<int, int> mp;
    int cnt;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        nn = n;
        dis = discount;
        int t = products.size();
        for (int i = 0; i < t; ++i){
            mp[products[i]] = prices[i];
        }
        cnt = 0;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        ++cnt;
        int n = product.size();
        int res = 0;
        for (int i = 0; i < n; ++i) 
            res += mp[product[i]] * amount[i];
        double ans = res;
        if (cnt % nn == 0){
            ans = ans - 0.01 * dis * ans;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
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
