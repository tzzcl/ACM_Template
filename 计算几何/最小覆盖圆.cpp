Point circumcenter(const Point &a,const Point &b,const Point &c){//返回三角形外心
	Point ret;
	Point a1=b-a;
	Point a2=c-a;
	double c1=a1.abs2()/2,c2=a2.abs2()/2;
	double d=a1.x*a2.y-a1.y*a2.x;
	ret.x=a.x+(c1*a2.y-c2*a1.y)/d;
	ret.y=a.y+(a1.x*c2-a2.x*c1)/d;
	return ret;
}

void min_cover_circle(Poly p,int n,Point &c,double &r){//最小覆盖圆 c为圆心 r为半径
	random_shuffle(p.begin(),p.end());
	c=p[0],r=0;
	for (int i=1;i<n;i++)
		if (p[i].distTo(c)>r+eps)
		{
			c=p[i];r=0;
			for (int j=0;j<i;j++)
			{
				if (p[j].distTo(c)>r+eps){
					c=(p[i]+p[j])/2;
					r=p[j].distTo(c);
					for (int k=0;k<j;k++)
						if (p[k].distTo(c)>r+eps){
							c=circumcenter(p[i],p[j],p[k]);
							r=p[i].distTo(c);
						}
				}
			}
		}
}