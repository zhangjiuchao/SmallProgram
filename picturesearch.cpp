
#include <cstdio>
#include<iostream> 
#include <io.h>
#include<cstdlib>
using namespace std;

const string to_search="E:\\C++\\*.txt";        //�����ҵ��ļ���֧��ͨ���

int main()
{
	long handle;                                                //���ڲ��ҵľ��
    struct _finddata_t fileinfo;                          //�ļ���Ϣ�Ľṹ��
    handle=_findfirst(to_search.c_str(),&fileinfo);         //��һ�β���
    if(-1==handle)
		return -1;
	cout<<fileinfo.name<<endl;                         //��ӡ���ҵ����ļ����ļ���
	while(!_findnext(handle,&fileinfo))               //ѭ�������������ϵ��ļ���֪���Ҳ���������Ϊֹ
    {
    	cout<<fileinfo.name<<endl;
       
 	}
    _findclose(handle);                                      //�����˹رվ��
	system("pause");
    return 0;
}

