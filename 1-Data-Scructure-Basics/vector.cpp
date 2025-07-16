#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
	v.push_back(111);
	v.push_back(222);
	v.push_back(333); //向数组末尾添加数据
	
	cout << v.size() <<endl; //输出数组长度
	
	v.resize(100); //重新调整大小
	v[99] = 100; //直接访问
	
	v.resize(500, -1); //新增部分初始化为-1
	v.resize(3); //删除索引3以后的部分
	
	vector<int>::iterator it = v.begin(); //创建迭代器，指向v[0]
	cout << *it << endl; //输出v[0]
	cout << *(it + 1) << endl; //输出v[1]
	cout << *(v.begin() + 2) << endl; //输出v[2]
	
	return 0;
}
