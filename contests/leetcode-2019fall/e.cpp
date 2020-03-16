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


struct Edge{
	int v,_next; 
}; 
Edge edge[200005];
int cnt,at[100005];
int fa[100005],son[100005],siz[100005],top[100005],
depth[100005],pos[100005],fp[100005],val[100005];
int ffa[100005];
int S,nows,nn,m,root,_a,_b;//我的线段树写法很鬼畜，所以不是从1开始。。。

long long sum[400005],tag[400005],_v,P;
void pushdown(int id,int len){
	if(id>=S||!tag[id])return ;
	sum[id<<1]+=tag[id]*(long long)(len>>1),tag[id<<1]+=tag[id];
	sum[id<<1|1]+=tag[id]*(long long)(len>>1),tag[id<<1|1]+=tag[id];
	tag[id]=0;
}
void build(){
    int i;
    for(i=S;i-S<nn;i++)
        sum[i]=val[fp[i-S+1]],tag[i]=0;
    for(;i<(S<<1);i++)
        sum[i]=0,tag[i]=0;
    for(i=S-1;i>=1;i--)
        sum[i]=sum[i<<1]+sum[i<<1|1],tag[i]=0;
}
void update(int id,int l,int r){
    if(l>_b||r<_a)return ;
    if(_a<=l&&r<=_b){ 
        sum[id]+=_v*(r-l+1),
        tag[id]+=_v;
        return ;
    }
    pushdown(id,r-l+1);
    update(id<<1,l,(l+r)>>1);
    update(id<<1|1,(l+r+1)>>1,r);
    sum[id]=sum[id<<1]+sum[id<<1|1];
}
long long query(int id,int l,int r){
    if(l>_b||r<_a)return 0ll;
    if(_a<=l&&r<=_b)return sum[id];
    pushdown(id,r-l+1);
    return query(id<<1,l,(l+r)>>1)+query(id<<1|1,((l+r)>>1)+1,r);
}
// pos:线段树上的位置
// fp:从线段树上位置回来 
void addedge(int _u,int _v){
	edge[++cnt].v=_v,
	edge[cnt]._next=at[_u],
	at[_u]=cnt;
} 
void dfs1(int x,int par,int d){
	depth[x]=d,fa[x]=par,siz[x]=1;
	for(int i=at[x];i;i=edge[i]._next){
		if(edge[i].v==par)continue;
		int _v=edge[i].v;
		dfs1(_v,x,d+1);
		siz[x]+=siz[_v];
		if(!son[x]||siz[_v]>siz[son[x]])
			son[x]=_v;
	}
}
//寻找重边
//初步构建关系 
void dfs2(int x,int tp){
	top[x]=tp,pos[x]=++nows,fp[nows]=x;
	if(!son[x])return;
	dfs2(son[x],tp);
	for(int i=at[x];i;i=edge[i]._next)
		if(edge[i].v!=fa[x]&&edge[i].v!=son[x])
			dfs2(edge[i].v,edge[i].v);
}
//第二次dfs，更新链的信息
//如果不是重儿子就直接自己成链了
 
//到这里为止应该结束了。
//还差线段树
void update_tr(int u,int v){
	//向u,v间加东西 
	while(top[u]!=top[v]){
		if(depth[top[u]]<depth[top[v]])
			swap(u,v);
		_a=pos[top[u]],_b=pos[u],
		update(1,1,S);
		u=fa[top[u]];
	}
	if(depth[u]>depth[v])swap(u,v);
	_a=pos[u],_b=pos[v],update(1,1,S);
}
long long query_tr(int u,int v){
	long long res=0;
	while(top[u]!=top[v]){
		if(depth[top[u]]<depth[top[v]])
			swap(u,v);
		_a=pos[top[u]],_b=pos[u],
		res+=query(1,1,S);
		u=fa[top[u]];
	}
	if(depth[u]>depth[v])swap(u,v);
	_a=pos[u],_b=pos[v],res+=query(1,1,S);
	return res;
}
void init(){
    P = 1000000007;
	for(S=1;S<nn;S<<=1);
	int u,v;
	for(int i=1;i<=nn;i++)val[i]=0;
}
class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        vector<int> ans;
        cnt = 0;
        memset(son, 0, sizeof(son));
        memset(at, 0, sizeof(at));
        memset(sum, 0, sizeof(sum));
        memset(tag, 0, sizeof(tag));
        nows = 0;
        nn = n;
        init();
        unordered_set<int> st;
        for(int i=1;i<n;i++){
            int u = leadership[i - 1][0], v = leadership[i - 1][1];
            st.insert(v), ffa[v] = u;
		    addedge(u,v),addedge(v,u);
	    }
        int rt = -1;
        for (int i = 1; i <= n; ++i)
            if (!st.count(i)){
                rt = i;
                break;
            }
        dfs1(rt,0,1);
	    dfs2(rt, rt);
	    build();
        for (vector<int>& q: operations){
		    int op=q[0];
		    if(op==1){
                int x = q[1], y = q[1];
                _v = q[2];
		    	update_tr(x,y);
		    } 
		    if(op==3){
			int x=q[1];
            _b=pos[x]+siz[x]-1,
			_a=pos[x];
            long long res = query(1,1,S)%P;
			ans.push_back(res);
		}
		    if(op==2){
		    	int x=q[1];
                _v=q[2];
		    	_b=pos[x]+siz[x]-1,
		    	_a=pos[x],update(1,1,S);	
		    }
        }
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
