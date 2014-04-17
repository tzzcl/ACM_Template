double disptoline(Point p,Point l1,Point l2){//点p到l1,l2所代表的直线的距离
	return fabs(cross(p,l1,l2))/l1.distTo(l2);
}