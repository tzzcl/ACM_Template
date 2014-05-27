//常用STL函数简介
find(begin,end,val) //寻找第一个出现的值
find_end(first1,last1,first2,last2) //寻找first1~last1中first2~last2最后一次出现的地址
search(first1,last1,first2,last2) //寻找first1~last1中first2~last2第一次出现的地址
find_first_of(first1,last1,first2,last2) //寻找first1~last1中第一个出现在first2~last2中的元素O(n^2)
adjacent_find(first,last)//寻找第一个与相邻相等的元素的位置
count(begin,end,val) //寻找某值出现次数
mismatch(fi1,la1,fi2,la2)//寻找第一个不匹配的位置，返回不匹配的指针
equal(fi1,la1,fi2,la2)//判断两个容器是否相等
search_n(fi,la,count,val) //寻找连续count个为val值的位置
copy(fi,la,re)//复制fi~la到re往后的位置
copy_backward(fi,la,re)//从后往前复制
swap(a,b)//交换a,b
swap_ranges(fi1,la1,fi2) //fi1和fi2全部交换
replace(fi,la,old,newi) //把old全部替换成newi
fill(fi,la,val)//全部填充成val
remove(fi,la,val)//去除val
unique(fi,la) //去重
reverse(fi,la) //翻转
random_shuffle(fi,la) //随机排列
sort(fi,la)//排序
nth_element(fi,lo,la)//以lo为位置划分
lower_bound(fi,la,val)//返回>=val地址
upper_bound(fi,la,val)//返回>val地址
binary_search(fi,la,val)//二分查找
min(a,b) //返回最小值
max(a,b) //返回最大值
min_element(fi,la)//返回最小元素
max_element(fi,la)//返回最大元素
lexicographical_compare(fi1,la1,fi2,la2)//字典序比较
next_permutation(fi,la)//下一个排列
prev_permutation(fi,la)//前一个排列