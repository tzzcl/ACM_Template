bool cmp(Point a,Point b){
	return (a.y<b.y||a.y==b.y&&a.x<b.x);
}
//pΪԭ��,nΪ����,convΪ��� ���ؽ���е����
int convex(Point p[],int n,Point conv[]){
	sort(p,p+n,cmp);
	conv[0]=p[0];conv[1]=p[1];
	int totco=2;
	for (int i=2;i<n;i++){
		while (totco>1&&((conv[totco-1]-conv[totco-2]).det(p[i]-conv[totco-2])<=0))
			totco--;
		conv[totco++]=p[i];
	}
	int limit=totco;
	for (int i=n-1;i>=0;i--){
		while (totco>limit&&((conv[totco-1]-conv[totco-2]).det(p[i]-conv[totco-2])<=0))
			totco--;
		conv[totco++]=p[i];
	}
	return totco-1;
}