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
char r[100005];
int sa[100005],wa[100005],wb[100005],wv[100005],cnt[100005]={0};
int cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void build_sa(char *r,int *sa,int n,int m){
	int i,j,p,*x=wa,*y=wb;
	for(i=0;i<m;i++)cnt[i]=0;
	for(i=0;i<n;i++)cnt[x[i]=r[i]]++;
	for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
	for(i=n-1;i>=0;i--)sa[--cnt[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]-j>=0)y[p++]=sa[i]-j;
		for(i=0;i<n;i++)wv[i]=x[y[i]];
		for(i=0;i<m;i++)cnt[i]=0;
		for(i=0;i<n;i++)cnt[wv[i]]++;
		for(i=1;i<m;i++)cnt[i]+=cnt[i-1];
		for(i=n-1;i>=0;i--)sa[--cnt[wv[i]]]=y[i];
		swap(x,y);
		for(p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;		
	}
}
class Solution {
public:
    string lastSubstring(string s) {
        int l = s.length();
        for (int i = 0; i < l; ++i) 
            r[i] = s[i] - 'a' + 1;
        r[l] = 0;
        build_sa(r, sa, l + 1, 26 + 1);
        return s.substr(sa[l]);
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
