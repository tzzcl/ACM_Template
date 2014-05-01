bool graham_cmp(Point a,Point b)//凸包比较函数
{
    return (a.y<b.y || a.y==b.y && a.x<b.x);
}
int gmult(Point &B,Point &A,Point &O)
{//考虑的是B点,注意三点共线,OA作参考，保留等号，去重点和共线点
    return (B.y-O.y)*(A.x-O.x)<=(A.y-O.y)*(B.x-O.x);
}

int Graham(Point pnt[],int n,Point graham[])//凸包
{
     int top=1;
     sort(pnt,pnt+n,graham_cmp);//从低到高排序
  
     int tmp = 0;
     for (int i = 1;i<n;i++)
     {
         if (pnt[i].x == pnt[i-1].x && pnt[i].y == pnt[i-1].y)
         {
            pnt[tmp] = pnt[i];
         }
         else
         {
             pnt[++tmp] = pnt[i];
         }
     }
     n = tmp + 1;
  
     if (n==0) return 0;graham[0]=pnt[0];
     if (n==1) return 1;graham[1]=pnt[1];
     if (n==2) return 2;
  
     for (int i=2;i<n;i++)//预放两个点
     {
         while(top && gmult(pnt[i],graham[top],graham[top-1]))
             top--;
         graham[++top]=pnt[i];
     }//从底往上右半边
  
     graham[++top]=pnt[n-2];
     for (int i=n-3,tmp=top-1;i>=0;i--)//mind the tmp
     {
         while(top!=tmp && gmult(pnt[i],graham[top],graham[top-1]))
             top--;
         graham[++top]=pnt[i];
     }//从上往底左半边
  
     return top;//最低点被加入两次
}