Point3 pvec(Plane3 s){//取平面法向量
	return (s.a-s.b)^(s.b-s.c);
}
Point3 pvec(Point3 a,Point3 b,Point3 c){
	return (a-b)^(b-c);
}
int dot3_inline(Point3 p1,Point3 p2,Point3 p3){//判三点共线
	return ((p1-p2)^(p2-p3)).len()<eps;
}
int dot3_onplane(Point3 a,Point3 b,Point3 c,Point3 d){//判四点共面
	return sign(pvec(a,b,c)*(d-a))==0;
}
int dot3_online(Point3 p,Point3 l1,Point3 l2){//判点是否在线段上,包括端点和共线
	return sign(((p-l1)^(p-l2)).len())==0&&(l1.x-p.x)*(l2.x-p.x)<eps&&
		(l1.y-p.y)*(l2.y-p.y)<eps&&(l1.z-p.z)*(l2.z-p.z)<eps;
}
int dot3_online_ex(Point3 p,Point3 l1,Point3 l2){//判点是否在线段上,不包括端点
	return dot3_online(p,l1,l2)&&sign(p.x-l1.x)!=0||sign(p.y-l1.y)!=0||sign(p.z-l1.z)!=0&&
		sign(p.x-l2.x)!=0||sign(p.y-l2.y)!=0||sign(p.z-l2.z)!=0;
}
int dot3_inplane(Point3 p,Point3 s1,Point3 s2,Point3 s3){//判点是否在空间三角形上,包括边界,三点共线无意义
	return sign(((s1-s2)^(s1-s3)).len()-((p-s1)^(p-s2)).len()-((p-s2)^(p-s3)).len()-
		((p-s3)^(p-s1)).len())==0;
}
int same_side3(Point3 p1,Point3 p2,Point3 l1,Point3 l2){//判两点在线段同侧,点在线段上返回0,不共面无意义
	return ((l1-l2)^(p1-l2))*((l1-l2)^(p2-l2))<eps;
}
int oppo_side3(Point3 p1,Point3 p2,Point3 l1,Point3 l2){//判两点在线段异侧,点在线段上返回0,不共面无意义
	return ((l1-l2)^(p1-l2))*((l1-l2)^(p2-l2))<-eps;
}
int same_side_plane(Point3 p1,Point3 p2,Point3 s1,Point3 s2,Point3 s3){//判两点在平面同侧,点在平面上返回0
	return (pvec(s1,s2,s3)*(p1-s1))*(pvec(s1,s2,s3)*(p2-s1))>eps;
}
int oppo_side_plane(Point3 p1,Point3 p2,Point3 s1,Point3 s2,Point3 s3){//判两点在平面异侧,点在平面上返回0
	return pvec(s1,s2,s3)*(p1-s1)*(pvec(s1,s2,s3)*(p2-s1))<-eps;
}

int parallel_Line(Point3 u1,Point3 u2,Point3 v1,Point3 v2){//判两直线平行
	return ((u1-u2)^(v1-v2)).len()<eps;
}
int parallel_Plane(Point3 u1,Point3 u2,Point3 u3,Point3 v1,Point3 v2,Point3 v3){//判两平面平行
	return (pvec(u1,u2,u3)^pvec(v1,v2,v3)).len()<eps;
}
int parallel_Line_Plane(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){//判直线与平面平行
	return sign((l1-l2)*pvec(s1,s2,s3))==0;
}
int perpend_LtoP(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){//判直线与平面垂直
	return ((l1-l2)^pvec(s1,s2,s3)).len()<eps;
}
int intersect3(Point3 u1,Point3 u2,Point3 v1,Point3 v2){//判两线段相交,包括端点和部分重合
	if (!dot3_onplane(u1,u2,v1,v2)) return 0;
	if (!dot3_inline(u1,u2,v1)||!dot3_inline(u1,u2,v2))
		return !same_side3(u1,u2,v1,v2)&&!same_side3(v1,v2,u1,u2);
	return dot3_online(u1,v1,v2)||dot3_online(u2,v1,v2)||dot3_online(v1,u1,u2)||dot3_online(v2,u1,u2);
}
int intersect3_ex(Point3 u1,Point3 u2,Point3 v1,Point3 v2){//判两线段相交,不包括端点和部分重合
	return dot3_onplane(u1,u2,v1,v2)&&oppo_side3(u1,u2,v1,v2)&&oppo_side3(v1,v2,u1,u2);
}

int intersect3_LtoP(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){//判线段与空间三角形相交,包括交于边界和(部分)包含
	return !same_side_plane(l1,l2,s1,s2,s3)&&!same_side_plane(s1,s2,l1,l2,s3)&&
		!same_side_plane(s2,s3,l1,l2,s1)&&!same_side_plane(s3,s1,l1,l2,s2);
}
int intersect3_LtoPex(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){//判线段与空间三角形相交,不包括交于边界和(部分)包含
	return oppo_side_plane(l1,l2,s1,s2,s3)&&oppo_side_plane(s1,s2,l1,l2,s3)&&
		oppo_side_plane(s2,s3,l1,l2,s1)&&oppo_side_plane(s3,s1,l1,l2,s2);
}
Point3 intersection_LtoL(Point3 u1,Point3 u2,Point3 v1,Point3 v2){
	//计算两直线交点,注意事先判断直线是否共面和平行!
//线段交点请另外判线段相交(同时还是要判断是否平行!)

	Point3 ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
		((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	ret.z+=(u2.z-u1.z)*t;
	return ret;
}
Point3 intersection_LtoP(Point3 l1,Point3 l2,Point3 s1,Point3 s2,Point3 s3){
//计算直线与平面交点,注意事先判断是否平行,并保证三点不共线!
//线段和空间三角形交点请另外判断

	Point3 ret=pvec(s1,s2,s3);
	double t=(ret.x*(s1.x-l1.x)+ret.y*(s1.y-l1.y)+ret.z*(s1.z-l1.z))/
		(ret.x*(l2.x-l1.x)+ret.y*(l2.y-l1.y)+ret.z*(l2.z-l1.z));
	ret.x=l1.x+(l2.x-l1.x)*t;
	ret.y=l1.y+(l2.y-l1.y)*t;
	ret.z=l1.z+(l2.z-l1.z)*t;
	return ret;
}
Line3 intersection_PtoP(Point3 u1,Point3 u2,Point3 u3,Point3 v1,Point3 v2,Point3 v3){
//计算两平面交线,注意事先判断是否平行,并保证三点不共线!
	Line3 ret;
	ret.s=(parallel_Line_Plane(v1,v2,u1,u2,u3))?(intersection_LtoP(v2,v3,u1,u2,u3)):(intersection_LtoP(v1,v2,u1,u2,u3));
	ret.e=(parallel_Line_Plane(v3,v1,u1,u2,u3))?(intersection_LtoP(v2,v3,u1,u2,u3)):(intersection_LtoP(v3,v1,u1,u2,u3));
	return ret;
}
double ptoline(Point3 p,Point3 l1,Point3 l2){
//点到直线距离
	return ((p-l1)^(l2-l1)).len()/l1.Distto(l2);
}
double ptoplane(Point3 p,Point3 s1,Point3 s2,Point3 s3){
//点到平面距离
	return fabs(pvec(s1,s2,s3)*(p-s1))/pvec(s1,s2,s3).len();
}
double linetoline(Point3 u1,Point3 u2,Point3 v1,Point3 v2){
//直线到直线距离
	Point3 n=(u1-u2)^(v1-v2);
	return fabs((u1-v1)*n)/n.len();
}
double angle_cos_Line(Point3 u1,Point3 u2,Point3 v1,Point3 v2){
//两直线夹角cos值
	return (u1-u2)*(v1-v2)/(u1-u2).len()/(v1-v2).len();
}
double angle_cos_Plane(Point3 u1,Point3 u2,Point3 u3,Point3 v1,Point3 v2,Point3 v3){
//两平面夹角cos值
	return pvec(u1,u2,u3)*pvec(v1,v2,v3)/pvec(u1,u2,u3).len()/pvec(v1,v2,v3).len();
}
//a点绕 Ob 向量，逆时针旋转弧度 angle ,sin(angle),cos(angle)先求出来，减少精度问题。
Point3 rotate(Point3 a,Point3 b,double angle){
	double l=b.len();b.x/=l;b.y/=l;b.z/=l;
	Point3 e3=b;double len=a*e3;
	Point3 e1=a-e3*len;
	if (e1.len()>eps){
		l=e1.len();e1.x/=l;e1.y/=l;e1.z/=l;
	}
	else return a;
	Point3 e2=e1^e3;
	double x1,y1,x,y;y1=a*e1;x1=a*e2;
	x=x1*cos(angle)-y1*sin(angle);y=x1*sin(angle)+y1*cos(angle);
	return e3*len+e1*y+e2*x;
}