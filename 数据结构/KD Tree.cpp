const int K=6,N=55555;
int dm,cdm;
struct Node{//结点信息
	int x[K];//K维坐标
	Node* c[2];
	bool operator <(Node a) const{
		for (int i=0;i<dm;i++) if (x[(cdm+i)%dm]!=a.x[(cdm+i)%dm]) return x[(cdm+i)%dm]<a.x[(cdm+i)%dm];
		return true;
	}
}node[N];
inline int dist(Node *a,Node *b){//距离定义
	int ret=0;
	for (int i=0;i<dm;i++) ret+=sqr(a->x[i]-b->x[i]);
	return ret;
}

struct KDT{//KD Tree
	Node *knn[15];
	int top,dis[15],sz;
	Node *RT;
	void build(int l,int r,int dp,Node *&rt){
		cdm=dp%dm;
		if (l>r) {rt=NULL;return ;}
		int m=l+r>>1;
		nth_element(node+l,node+m,node+r+1);
		rt=node+m;
		build(l,m-1,dp+1,rt->c[0]);
		build(m+1,r,dp+1,rt->c[1]);
	}
	void build(int l,int r){
		sz=r-l+1;
		build(l,r,0,RT);
	}
	void search(int dp,Node *x,Node *rt,int k){
		if (!rt) return ;
		cdm=dp%dm;
		int d=dist(x,rt),p=top;
		while (p>=0&&d<dis[p]) dis[p+1]=dis[p],knn[p+1]=knn[p],p--;
		p++;
		dis[p]=d;
		knn[p]=rt;
		if (top+1<k) top++;
		bool r=x->x[cdm]>=rt->x[cdm];
		search(dp+1,x,rt->c[r],k);
		cdm=dp%dm;
		if (top+1<k||sqr(rt->x[cdm]-x->x[cdm])<dis[top])
			search(dp+1,x,rt->c[!r],k);
	}
	void search(Node *x,int k){
		top=-1;
		search(0,x,RT,k);
	}
	void pre(Node *x){
		if (!x) return;
		pre(x->c[0]);
		cout<<x->x[0]<<' '<<x->x[1]<<endl;
		pre(x->c[1]);
	}
}kdt;
