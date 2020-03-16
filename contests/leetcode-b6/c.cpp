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
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        vector<int> id1(n, 0);
        for (int i = 0; i < n; ++i)
            id1[i] = i;
        sort(id1.begin(), id1.end(), [&username, &timestamp, &website]
            (int x, int y){
                if (username[x] == username[y])
                    return timestamp[x] < timestamp[y];
                return username[x] < username[y];
            });

        for (int i = 0; i < n; ++i)
            cout << username[id1[i]] << " " << timestamp[id1[i]] << " " << website[id1[i]] << endl;

        vector<int> users;
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && username[id1[i]] == username[id1[j]])
                ++j;
            users.push_back(i);
            i = j;
        }
        users.push_back(n);
        int num_u = users.size() - 1;

        auto judge = [&website](int x, int y, int z, vector<int>& vec){
            if (website[vec[0]] != website[x])
                return website[x] < website[vec[0]];
            if (website[vec[1]] != website[y])
                return website[y] < website[vec[1]];
            if (website[vec[2]] != website[z])
                return website[z] < website[vec[2]];
            return false;
        };

        vector<int> ans1;
        int vis = 0;
        for (int i = 0; i < n; ){
            int j = i;
            while (j < n && username[id1[i]] == username[id1[j]])
                ++j;
            if (j - i < 3){
                i = j;
                continue;
            }
            for (int p1 = i; p1 < j - 2; ++p1)
                for (int p2 = p1 + 1; p2 < j - 1; ++p2)
                    for (int p3 = p2 + 1; p3 < j; ++p3){
                        int cur_vis = 0;
                        for (int us = 0; us < num_u; ++us){
                            bool f1 = false, f2 = false, f3 = false;
                            int hd = users[us], tl = users[us + 1];
                            if (hd == i) {
                                ++cur_vis; 
                                continue;
                            }
                            if (tl - hd < 3)
                                continue;
                            for (int fp = hd; fp < tl; ++fp){
                                if (website[id1[fp]] == website[id1[p3]]){
                                    if (f1 && f2) f3 = true;
                                }
                                if (website[id1[fp]] == website[id1[p2]]){
                                    if (f1) f2 = true;
                                }
                                if (website[id1[fp]] == website[id1[p1]]){
                                    f1 = true;
                                }
                            }
                            if (f1 && f2 && f3)
                                ++cur_vis;
                        }
                        if (cur_vis > vis || ans1.empty()){
                            vis = cur_vis, ans1.clear();
                            ans1.push_back(id1[p1]), ans1.push_back(id1[p2]), ans1.push_back(id1[p3]);
                        }else if (cur_vis == vis){
                            if (judge(id1[p1], id1[p2], id1[p3], ans1)){
                                ans1.clear();
                                ans1.push_back(id1[p1]), ans1.push_back(id1[p2]), ans1.push_back(id1[p3]);
                            }
                        }
                    }
            i = j;
        }

        vector<string> ans;
        for (int i = 0; i < 3; ++i)
            ans.push_back(website[ans1[i]]);
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
