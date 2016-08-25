
#include <cstdio>
#include<iostream> 
#include <io.h>
#include<cstdlib>
using namespace std;

const string to_search="E:\\C++\\*.txt";        //欲查找的文件，支持通配符

int main()
{
	long handle;                                                //用于查找的句柄
    struct _finddata_t fileinfo;                          //文件信息的结构体
    handle=_findfirst(to_search.c_str(),&fileinfo);         //第一次查找
    if(-1==handle)
		return -1;
	cout<<fileinfo.name<<endl;                         //打印出找到的文件的文件名
	while(!_findnext(handle,&fileinfo))               //循环查找其他符合的文件，知道找不到其他的为止
    {
    	cout<<fileinfo.name<<endl;
       
 	}
    _findclose(handle);                                      //别忘了关闭句柄
	system("pause");
    return 0;
}

