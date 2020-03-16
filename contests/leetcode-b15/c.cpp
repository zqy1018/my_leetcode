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

int aans[10005][17], vec[20];
class CombinationIterator {
public:
    int all_comb, n, at, big, k, cur;
    vector<int> vec;
    string s;
    CombinationIterator(string characters, int combinationLength) {
        all_comb = 1, k = combinationLength;
        n = characters.size();
        s = characters;
        for (int i = 1; i <= combinationLength; ++i)    
            all_comb = all_comb * (n - i + 1) / i;

        int t = min(10000, all_comb), cnt = 0;
        do{
            if(at<k){vec[at++]=big;big++;}//如果当前所在数字不是最后一个就填入
            else{
                while(big<n+1){
                    vec[k]=big;
                    
                    for(int i=1;i<=k;i++)
                        aans[cnt][i] = vec[i]   ;
                    
                    ++cnt;big++;
                }//输出方案
                while(at>0&&vec[at]==at+(n-k))at--;//此处为回溯
                vec[at]++;big=vec[at];//更新方案
            }
        }while(t > cnt);//共输出t个组合
        cur = 0;
    }
    
    string next() {
        string ans;
        for (int i = 1; i <= k; ++i)    
            ans.push_back(s[aans[cur][i] - 1]);
        ++cur;
        return ans;
    }
    
    bool hasNext() {
        if (cur == all_comb) return false;
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
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
