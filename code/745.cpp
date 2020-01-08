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

int id1[15005], id2[15005];
class WordFilter {
private:
    bitset<15> bs1[15005], bs2[15005];
    vector<string> wz1, wz2;
    bitset<15> t1, t2;
    int n;
public:
    int llower_bound(string& s, int o){
        int l = 0, r = n;
        while (r > l){
            int mid = (l + r) >> 1;
            bool flag = (o == 0 ? wz1[id1[mid]] < s: wz2[id2[mid]] < s);
            if (flag) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    int uupper_bound(string& s, int o){
        int l = 0, r = n;
        while (r > l){
            int mid = (l + r) >> 1;
            bool flag = (o == 0 ? wz1[id1[mid]] <= s: wz2[id2[mid]] <= s);
            if (flag) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    WordFilter(vector<string>& words) {
        n = words.size();
        for (int i = 0; i < n; ++i) id1[i] = id2[i] = i;
        wz1 = words;
        sort(id1, id1 + n, [&words](int i, int j){
            return words[i] < words[j];
        });
        for (string& str: words){
            int l = str.length();
            for (int i = 0; i < l - i - 1; ++i) 
                swap(str[i], str[l - i - 1]);
        }
        wz2 = words;
        sort(id2, id2 + n, [&words](int i, int j){
            return words[i] < words[j];
        });
        for (int i = 1; i <= n; ++i) {
            bs1[i] = bs1[i - 1], bs2[i] = bs2[i - 1];
            bs1[i].set(id1[i - 1]);
            bs2[i].set(id2[i - 1]);
        }
    }
    
    int f(string prefix, string suffix) {
        
        if (prefix.length() == 0) t1 = bs1[n];
        else {
            int st = llower_bound(prefix, 0);
            int ed = uupper_bound(prefix, 0) - 1;
            if (st == n || wz1[id1[st]].find(prefix, 0) != 0) 
                return -1;
            else t1 = bs1[ed + 1] ^ bs1[st];
        }
        if (suffix.length() == 0) t2 = bs2[n];
        else {
            int st = llower_bound(suffix, 0);
            int ed = uupper_bound(suffix, 1) - 1;
            if (st == n || wz2[id2[st]].find(suffix, 0) != 0) 
                return -1;
            else t2 = bs2[ed + 1] ^ bs2[st];
        }
        t1 = (t1 & t2);
        if (t1.none()) return -1;
        int ans = n - 1;
        while (!t1.test(ans))
            --ans;
        return ans; 
    }
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
void init(){
    vector<string> vec{"apple"};

    WordFilter w(vec);
    cout << w.f("a", "e");
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
