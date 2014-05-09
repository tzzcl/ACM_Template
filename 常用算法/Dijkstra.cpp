vector<pair<int,int> > a[N];//点和权值
struct Node{
	int v;
	int cost;
	Node(){}
	Node(int v,int cost):v(v),cost(cost){}
	bool operator <(const Node& other){
		return cost>other.cost;
	}
};
void dijkstra(int s,int t,bool visit[],int dist[]){
	for (int i=0;i<N;i++) dist[i]=inf,visit[i]=0;
	dist[s]=0;
	priority_queue<Node> q;
	q.push(Node(s,0));
	while (!q.empty()){
		Node nd=q.top();q.pop();
		visit[nd.v]=true;
		if (nd.v==t) return;
		for (int i=0;i<a[nd.v].size();i++){
			Node nn=Node(a[nd.v][i].first,a[nd.v][i].second);
			if (!visit[nn.v]&&dist[nn.v]>dist[nd.v]+nn.cost){
				dist[nn.v]=dist[nd.v]+nn.cost;
				q.push(Node(nn.v,dist[nn.v]);
			}
		}
	}
}