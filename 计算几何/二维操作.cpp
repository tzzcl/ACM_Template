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
int intersect_LtoC(Circle c,Point l1,Point l2){//判直线和圆相交,包括相切
	return disptoline(c.center,l1,l2)<c.r+eps;
}
int intersect_StoC(Circle c,Point l1,Point l2){
//判线段和圆相交,包括端点和相切
	double t1=c.center.distTo(l1)-c.r,t2=c.center.distTo(l2)-c.r;
	Point t=c.center;
	if (t1<eps||t2<eps)
		return t1>-eps||t2>-eps;
	t.x+=l1.y-l2.y;
	t.y+=l2.x-l1.x;
	return cross(l1,c.center,t)*cross(l2,c.center,t)<eps
		&& disptoline(c.center,l1,l2)-c.r<eps;
}
int intersect_CtoC(Circle c1,Circle c2){
//判圆和圆相交,包括相切
	return c1.center.distTo(c2.center)<c1.r+c2.r+eps&&
		c1.center.distTo(c2.center)>fabs(c1.r-c2.r)-eps;
}
Point dot_to_circle(Circle c,Point p){
//计算圆上到点p最近点,如p与圆心重合,返回p本身
	Point u,v;
	if (p.distTo(c.center)<eps) return p;
	u.x=c.center.x+c.r*fabs(c.center.x-p.x)/c.center.distTo(p);
	u.y=c.center.y+c.r*fabs(c.center.y-p.y)/c.center.distTo(p)*((c.center.x-p.x)*(c.center.y-p.y)<0?-1:1);
	v.x=c.center.x-c.r*fabs(c.center.x-p.x)/c.center.distTo(p);
	v.y=c.center.y+c.r*fabs(c.center.y-p.y)/c.center.distTo(p)*((c.center.x-p.x)*(c.center.y-p.y)<0?-1:1);
	return p.distTo(u)<p.distTo(v)?u:v;
}
void intersect_LtoC(Circle c,Point l1,Point l2,Point& p1,Point& p2){
//计算直线与圆的交点,保证直线与圆有交点
	Point p=c.center;
	double t;
	p.x+=l1.y-l2.y;p.y+=l2.x-l1.x;
	p=Line_intersection(p,c.center,l1,l2);
	t=sqrt(sqr(c.r)-sqr(p.distTo(c.center)))/l1.distTo(l2);
	p1.x=p.x+(l2.x-l1.x)*t;
	p1.y=p.y+(l2.y-l1.y)*t;
	p2.x=p.x-(l2.x-l1.x)*t;
	p2.y=p.y-(l2.y-l1.y)*t;
}
void intersect_CtoC(Circle c1,Circle c2,Point& p1,Point& p2){
//计算圆与圆的交点,保证圆与圆有交点,圆心不重合
	Point u,v;
	double t;
	t=(1+(sqr(c1.r)-sqr(c2.r))/sqr(c1.center.distTo(c2.center)))/2;
	u.x=c1.center.x+(c2.center.x-c1.center.x)*t;
	u.y=c1.center.y+(c2.center.y-c1.center.y)*t;
	v.x=u.x+c1.center.y-c2.center.y;
	v.y=u.y-c1.center.x+c2.center.x;
	intersect_LtoC(c1,u,v,p1,p2);
}
void TanPoint(Point p1,Circle c,Point& r1,Point& r2){
//求圆外一点对圆(o,r)的两个切点result1和result2
	double line=sqrt(sqr(p1.x-c.center.x)+sqr(p1.y-c.center.y));
	double angle=acos(c.r/line);
	Point unitvector,lin;
	lin.x=p1.x-c.center.x;
	lin.y=p1.y-c.center.y;
	unitvector.x=lin.x/sqrt(sqr(lin.x)+sqr(lin.y))*c.r;
	unitvector.y=lin.y/sqrt(sqr(lin.x)+sqr(lin.y))*c.r;
	r1=unitvector.rotate_left(-angle);
	r2=unitvector.rotate_left(angle);
	r1.x+=c.center.x;
	r1.y+=c.center.y;
	r2.x+=c.center.x;
	r2.y+=c.center.y;
}
Point Getcenter(int i,int j,int k,Point p[]){//求p[i],p[j],p[k]三点构成的圆圆心，事先判是否共线
    double tempx1,tempx2,tempy1,tempy2,x,y;
    double k1,k2;
    if(sign(p[i].y-p[j].y)==0)
    {
        x=(p[i].x+p[j].x)/2.0;
        tempx1=(p[i].x+p[k].x)/2.0;
        tempy1=(p[i].y+p[k].y)/2.0;
        k1=(p[k].x-p[i].x)/(p[i].y-p[k].y);
        y=k1*(x-tempx1)+tempy1;
    }
    else if(sign(p[i].y-p[k].y)==0)
    {
        x=(p[i].x+p[k].x)/2.0;
        tempx1=(p[i].x+p[j].x)/2.0;
        tempy1=(p[i].y+p[j].y)/2.0;
        k1=(p[j].x-p[i].x)/(p[i].y-p[j].y);
        y=k1*(x-tempx1)+tempy1;
    }
    else if(sign(p[j].y-p[k].y)==0)
    {
        x=(p[j].x+p[k].x)/2.0;
        tempx1=(p[i].x+p[k].x)/2.0;
        tempy1=(p[i].y+p[k].y)/2.0;
        k1=(p[k].x-p[i].x)/(p[i].y-p[k].y);
        y=k1*(x-tempx1)+tempy1;
    }
    else
    {
        tempx1=(p[i].x+p[k].x)/2.0;
        tempy1=(p[i].y+p[k].y)/2.0;
        k1=(p[k].x-p[i].x)/(p[i].y-p[k].y);
        tempx2=(p[i].x+p[j].x)/2.0;
        tempy2=(p[i].y+p[j].y)/2.0;
        k2=(p[j].x-p[i].x)/(p[i].y-p[j].y);
        x=((tempy2-tempy1)+k1*tempx1-k2*tempx2)/(k1-k2);
        y=k1*(x-tempx1)+tempy1;
	}
	return Point(x,y);
}

//判点在任意多边形内,顶点按顺时针或逆时针给出
//on_edge表示点在多边形边上时的返回值,offset为多边形坐标上限
int inside_poly(Point q,int n,Poly p,int offset,int on_edge=2){
	Point q2;
	int count,i=0;
	while (i<n)
		for (count=i=0,q2.x=rand()+offset,q2.y=rand()+offset;i<n;i++){
			if (sign(cross(q,p[i],p[(i+1)%n]))==0&&(p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps
				&&(p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)
				return on_edge;
			else if (sign(cross(q,q2,p[i]))==0)
				break;
			else if (sign(cross(q,p[i],q2)*cross(q,p[(i+1)%n],q2))==-1&&sign(cross(p[i],q,p[(i+1)%n])*cross(p[i],q2,p[(i+1)%n]))==-1)
				count++;
			return count&1;
		}
}
Point barycenter(Point a,Point b,Point c){//三角形重心
	Line u,v;
	u.s.x=(a.x+b.x)/2;
	u.s.y=(a.y+b.y)/2;
	u.e=c;
	v.s.x=(a.x+c.x)/2;
	v.s.y=(a.y+c.y)/2;
	v.e=b;
	return Line_intersection(u.s,u.e,v.s,v.e);
}
Point Polybarycenter(int n,Poly p){//多边形重心
	Point ret(0,0),t;
	double t1=0,t2;
	for (int i=1;i<n-1;i++)
		if (sign(t2=cross(p[0],p[i],p[i+1]))>=1){
			t=barycenter(p[0],p[i],p[i+1]);
			ret.x+=t.x*t2;
			ret.y+=t.y*t2;
			t1+=t2;
		}
		if (sign(t1)>=1)
			ret.x/=t1,ret.y/=t1;
		return ret;
}
void polygon_cut(int& n,Poly p,Point l1,Point l2,Point side){//将多边形沿l1,l2确定的直线切割在side侧切割,保证l1,l2,side不共线
	Poly pp;pp.clear();
	int cnt=0,m=0;
	for (int i=0;i<n;i++){
		if (same_side(p[i],side,l1,l2))
			pp[cnt++]=p[i];
		if (!same_side(p[i],p[(i+1)%n],l1,l2)&&sign(cross(p[i],l1,l2))!=0&&
			sign(cross(p[(i+1)%n],l1,l2))==0)
			pp[cnt++]=Line_intersection(p[i],p[(i+1)%n],l1,l2);
	}
	for (int i=n=0;i<m;i++)
		if (!i||sign((pp[i]-pp[i-1]).x)||sign((pp[i]-pp[i-1]).y))
			p[n++]=pp[i];
	if (sign((p[n-1]-p[0]).x)==0&&sign((p[n-1]-p[0]).y)==0)
	if (n<3) n=0;
}