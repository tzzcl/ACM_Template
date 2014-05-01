class SegTree{//Ïß¶ÎÊ÷
public:
	int tree[maxn<<2];
	SegTree(){
		mset(tree);
	}
	void build(int l,int r,int rt){
		if (l==r){
			scanf("%d",&tree[rt]);
			return ;
		}
		int m=(l+r)>>1;
		build(l,m,rt<<1);
		build(m+1,r,rt<<1|1);
		Pushup(rt);
	}
	void Pushup(int rt){//ÉÏÍÆ
		tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
	}
	void update(int p,int number,int l,int r,int rt){
		if (l==r) {
			tree[rt]=number;
			return ;
		}
		int m=(l+r)>>1;
		if (p<=m) update(p,number,l,m,rt<<1);
		else update(p,number,m+1,r,rt<<1|1);
		Pushup(rt);
	}
	int query(int l,int r,int rt){
		if (L<=l&&r<=R) return tree[rt];
		int m=(l+r)>>1;
		int ret=0;
		if (L<=m) ret=max(ret,query(l,m,rt<<1));
		if (R>m) ret=max(ret,query(m+1,r,rt<<1|1));
		return ret;
	}
};
