int dot_inline(Point p1,Point p2,Point p3){//判三点共线
	return sign(cross(p1,p2,p3))==0;
}
int same_side(Point p1,Point p2,Point l1,Point l2){//判断线段在同侧
	return cross(l1,p1,l2)*cross(l1,p2,l2)>eps;
}

int dot_online(Point p,Point l1,Point l2){//判点在线段上，包括端点
	return (sign(cross(p,l1,l2))==0&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps);
}
int dot_online_ex(Point p,Point l1,Point l2){//判点在线段上，不包括端点
	return 
	dot_online(p,l1,l2)&&sign(p.x-l1.x)!=0||sign(p.y-l1.y)!=0&&sign(p.x-l2.x)!=0||sign(p.y-l2.y);
}
int oppo_side(Point p1,Point p2,Point l1,Point l2){//判点在线段异侧,在线段上返回0
	return cross(l1,p1,l2)*cross(l1,p2,l2)<-eps;
}
int line_parallel(Point u1,Point u2,Point v1,Point v2){//判直线平行
	return sign((u1.x-u2.x)*(v1.y-v2.y)-(v1.x-v2.x)*(u1.y-u2.y))==0;
}
int chuizhi(Point u1,Point u2,Point v1,Point v2){//判两直线垂直
	return (sign((u1.x-u2.x)*(v1.x-v2.x)+(u1.y-u2.y)*(v1.y-v2.y))==0);
}
int seg_intersect(Point u1,Point u2,Point v1,Point v2){//判两线段相交,包括端点和部分重合
	if (!dot_inline(u1,u2,v1)||!dot_inline(u1,u2,v2))
		return !same_side(u1,u2,v1,v2)&&same_side(v1,v2,u1,u2);
	return dot_online(u1,v1,v2)||dot_online(u2,v1,v2)||dot_online(v1,u1,u2)||dot_online(v2,u1,u2);
}
int seg_intersect_ex(Point u1,Point u2,Point v1,Point v2){//判两线段相交,不包括端点和部分重合
	return oppo_side(u1,u2,v1,v2)&&oppo_side(v1,v2,u1,u2);
}
Point Line_intersection(Point u1,Point u2,Point v1,Point v2){
//计算两直线交点,注意事先判断直线是否平行!
//线段交点请另外判线段相交(同时还是要判断是否平行!)
	Point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}

Point ptoline(Point p,Point l1,Point l2){//点到直线上的最近点
	Point t=p;
	t.x+=l1.y-l2.y,t.y+=l2.x-l1.x;
	return Line_intersection(p,t,l1,l2);
}
double disptoline(Point p,Point l1,Point l2){//点到直线距离
	return fabs(cross(p,l1,l2))/l1.distTo(l2);
}
Point ptoseg(Point p,Point l1,Point l2){//点到线段上的最近点
	Point t=p;
	t.x+=l1.y-l2.y,t.y+=l2.x-l1.x;
	if (cross(l1,t,p)*cross(l2,t,p)>eps){
		return p.distTo(l1)<p.distTo(l2)?l1:l2;
		
	}
	return Line_intersection(p,t,l1,l2);
}
Point symmetryPointLine(Point p,Line L){//p点关于直线L的对称点
	Point p2;
	double d;
	d=sqr(L.a)+sqr(L.b);
	p2.x=(sqr(L.b)*p.x-sqr(L.a)*p.x-2*L.a*L.b*p.y-2*L.a*L.c)/d;
	p2.y=(sqr(L.a)*p.y-sqr(L.b)*p.y-2*L.a*L.b*p.x-2*L.b*L.c)/d;
	return p2;
}
Line bisector(Point &a,Point &b){//求两点的平分线
	Line ab,ans;ab=Line(a,b);
	double midx=(a.x+b.x)/2.0,midy=(a.y+b.y)/2.0;
	ans.a=-ab.b;ans.b=-ab.a;
	ans.c=-ab.b*midx+ab.a*midy;
	return ans;
}
void reflect(Line &l1,Line &l2,Line &l3){//已知入射线、镜面，求反射线。
	double n,m,tpb,tpa;
	tpb=l1.b*l2.b+l1.a*l2.a;
	tpa=l2.a*l1.b-l1.a*l2.b;
	m=(tpb*l1.b+tpa*l1.a)/(sqr(l1.a)+sqr(l1.b));
	n=(tpa*l1.b-tpb*l1.a)/(sqr(l1.b)+sqr(l1.a));
	if (fabs(l1.a*l2.b-l2.a*l1.b)<eps)
	{
		l3.a=l2.a;l3.b=l2.b;l3.c=l2.c;
		return ;
	}
	double xx,yy;
	xx=(l1.b*l2.c-l2.b*l1.c)/(l1.a*l2.b-l2.a*l1.b);
	yy=(l2.a*l1.c-l1.a*l2.c)/(l1.a*l2.b-l2.a*l1.b);
	l3.a=n;
	l3.b=-m;
	l3.c=m*yy-xx*n;
}


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
Point incenter(Point a,Point b,Point c){//三角形内心
	Line u,v;
	double m,n;
	u.s=a;
	m=atan2(b.y-a.y,b.x-a.x);
	n=atan2(c.y-a.y,c.x-a.x);
	u.e.x=u.s.x+cos((m+n)/2);
	u.e.y=u.s.y+sin((m+n)/2);
	v.s=b;
	m=atan2(a.y-b.y,a.x-b.x);
	n=atan2(c.y-b.y,c.x-b.x);
	v.e.x=v.s.x+cos((m+n)/2);
	v.e.y=v.s.y+sin((m+n)/2);
	return Line_intersection(u.s,u.e,v.s,v.e);
}
Point perpencenter(Point a,Point b,Point c){//垂心
	Line u,v;
	u.s=c;
	u.e.x=u.s.x-a.y+b.y;
	u.e.y=u.s.y+a.x-b.x;
	v.s=b;
	v.e.x=v.s.x-a.y+c.y;
	v.e.y=v.s.y+a.x-c.x;
	return Line_intersection(u.s,u.e,v.s,v.e);
}
