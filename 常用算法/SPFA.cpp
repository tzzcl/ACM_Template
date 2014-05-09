vector<pair<int,int> > a[N];//点和权值
void SPFA(int s,bool inque[],int dist[]){
	for (int i=0;i<N;i++) dist[i]=inf,inque[i]=0;
	dist[s]=0;
	inque[s]=1;
	queue<int> q;
	q.push(s);
	while (!q.empty()){
		int now=q.front();q.pop();
		inque[now]=false;
		for (int i=0;i<a[now].size();i++){
			int to=a[now][i].first;
			if (dist[now]<inf&&dist[to]>dist[now]+a[now][i].second){
				dist[to]=dist[now]+a[now][i].second;
				if (!inque[to]){
					inque[to]=true;
					q.push(to);
				}
			}
		}
	}
}