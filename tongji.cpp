#include<iostream>
#include<fstream>
#include<sm.h>
using namespace std;
void shoupiaoguanlixitong()
{
	while (true) {
		int xuanze;
		cout << "欢迎来到售票管理系统" << endl;
		cout << "请输入您要操作的功能！" << endl;
		cout << "1.显示所有订单信息" << endl;
		cout << "2.退出系统" << endl;
		cin >> xuanze;
		switch (xuanze)
		{
		case 1: {xianshisuoyoudingdanxinxi(); break; }
		case 2: {jinruxitong(); break; }
		}
		if (xuanze == 1 || xuanze == 2) break;
		else { cout << "请输入1或2" << endl; }
	}
	jinruxitong();
}

void xianshisuoyoudingdanxinxi()
{
	dingdanmingxixinxi b;
	ifstream ifile;
	ifile.open("mayuan.dingdan.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len2 = ifile.tellg();
	int n = len2 / sizeof(dingdanmingxixinxi);
	if (n == 0) { cout << "无订单信息" << endl; }
	else 
	{
		for (int i = 0; i < n; i++)
		{
			ifile.seekg(sizeof(b) * i);
			ifile.read((char*)&b, sizeof(b));
			cout << i << "," << "订单号" << b.dingdanhao << "  航班号" << b.hangbanhao << "出发日期" << b.chufariqi << "座位等级" << b.zuoweidengji << " 乘客姓名" << b.chengkexingming << "电话号码" << b.dianhuahaoma << "身份证号" << b.shenfenzhenghao << endl;
		}
	}
	ifile.close();
	shoupiaoguanlixitong();
}