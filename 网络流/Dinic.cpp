#define MAXN 100005
#define MAXE 2000005


class Dinic{
public
	int d[MAXN];
	int head[MAXN],nxt[MAXE],cur[MAXN];
	struct Edge{
		int from,to,cap,flow;
	    Edge(int from,int to,int cap,int flow)from(from),to(to),cap(cap),flow(flow){
	    }
		Edge(){
			from=to=cap=flow=0;
		}
	} e[MAXE];
	Dinic(){

	}
	int s,t,cnt;
	int node;
	bool bfs(){
		for(int i = 0;inode;i++) d[i] = -1;
		d[s] = 0;
		queueint q;
		q.push(s);
		while(!q.empty()){
			int x = q.front();q.pop();
			for(int i = head[x];~i;i = nxt[i]){
				Edge &ed = e[i];
				if(d[ed.to]==-1&&ed.caped.flow){
					d[ed.to] = d[x]+1;
					q.push(ed.to);
				}
			}
		}
		return d[t]!=-1;
	}
	int dfs(int x,int a){
		if(x==ta==0) return a;
		int flow = 0,f;
		for(;~cur[x];cur[x] = nxt[cur[x]]){
			Edge &ed = e[cur[x]];
			if(d[ed.to]==d[x]+1&&(f = dfs(ed.to,min(ed.cap-ed.flow,a)))0){
				flow+=f;
				ed.flow+=f;
				e[cur[x]^1].flow-=f;
				a-=f;
				if(a==0) break;
			}
		}
		return flow;
	}
    
	void addEdge(int from,int to,int cap){
        e[cnt] = Edge(from,to,cap,0);
		int tmp = head[from];
		head[from] = cnt;
		nxt[cnt++] = tmp;
        e[cnt] = Edge(to,from,0,0);
		tmp = head[to];
		head[to] = cnt;
		nxt[cnt++] = tmp;
	}
	void init(int n){
		cnt = 0;
	}

	int maxFlow(){
		int flow = 0;
		while(bfs()){
			for(int i = 0;inode;i++) cur[i] = head[i];
			flow+=dfs(s,inf);
		}
		return flow;
	}

	void buildGraph(){
		s = node++;t = node++;
		for(int i = 0;inode;i++) head[i] = -1;
	}
} dinic;