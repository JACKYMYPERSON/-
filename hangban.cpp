#include<iostream>
#include<sm.h>
#include<fstream>
using namespace std;
void hangbanguanlixitong()
{

	int xuanzegongneng;
	while (true)
	{
		cout << "请选择你要操作的功能：" << endl;
		cout << "1.添加航班信息功能" << endl;
		cout << "2.显示所有航班信息功能" << endl;
		cout << "3.查询航班信息功能" << endl;
		cout << "4.修改航班信息功能" << endl;
		cout << "5.删除航班信息功能" << endl;
		cout << "6.退出系统" << endl;
		cin >> xuanzegongneng;
		switch (xuanzegongneng)
		{
		case 1:tianjiahangbangongneng(); break;
		case 2:xianshisuoyouhangbanxinxigongneng(); break;
		case 3:chaxunhangbanxinxigongneng(); break;
		case 4:xiugaihangbanxinxigongneng(); break;
		case 5:shanchuhangbanxinxigongneng(); break;
		case 6:jinruxitong(); break;
		}
	}
}
void tianjiahangbangongneng()
{
	hangbanxinxi a;
	hangbanxinxi b;//用来和a对比对照
	while (true)
	{
		cout << "请输入要添加的航班的航班号" << endl;
		cin >> a.hangbanhao;
		ofstream ofile;
		ifstream ifile;
		ifile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::in);
		ifile.seekg(0, ios::end);
		int len = ifile.tellg();
		int n = len / sizeof(b);
		ifile.seekg(0, ios::beg);
		int jiance = 0;
		for (int i = 0; i < n; i++)
		{
			ifile.read((char*)&b, sizeof(b));
			if (b.hangbanhao == a.hangbanhao) { jiance = 1; }
		}
		ifile.close();
		if (jiance == 0) { break; }
		else { cout << "航班号重复，请重新输入" << endl; }
	}
	cout << "请输入要添加的航班的航空公司" << endl;
	cin >> a.hangkonggongsi;
	cout << "请输入要添加的航班的班期" << endl;
	cin >> a.banqi;
	cout << "请输入要添加的航班的始发城市" << endl;
	cin >> a.shifachengshi;
	cout << "请输入要添加的航班的抵达城市" << endl;
	cin >> a.didachengshi;
	cout << "请输入要添加的航班的抵达航站楼" << endl;
	cin >> a.didahangzhanlou;
	cout << "请输入要添加的航班的时间" << endl;
	cin >> a.shijian;
	cout << "请输入要添加的航班的头等舱数" << endl;
	cin >> a.toudengcangshu;
	cout << "请输入要添加的航班的公务舱数" << endl;
	cin >> a.gongwucangshu;
	cout << "请输入要添加的航班的经济舱数" << endl;
	cin >> a.jingjicangshu;
	ofstream ofile;
	ofile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::app|ios::out);
	ofile.write((char*)&a, sizeof(a));
	ofile.close();
	hangbanguanlixitong();
}
void xianshisuoyouhangbanxinxigongneng()
{
	hangbanxinxi b;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(b);
	if (n == 0) { cout << "无航班信息" << endl; }
	else {
		ifile.seekg(0, ios::beg);
		for (int i = 0; i < n; i++)
		{
			ifile.read((char*)&b, sizeof(b));
			cout << i + 1 << "," << "航班号" << b.hangbanhao << "航空公司" << b.hangkonggongsi << "班期" << b.banqi << "始发城市" << b.shifachengshi << "抵达城市" << b.didachengshi << "抵达航站楼" << b.didahangzhanlou << "时间" << b.shijian << "头等舱数" << b.toudengcangshu << "公务舱数" << b.gongwucangshu << "经济舱数" << b.jingjicangshu << endl;
		}
	}
	ifile.close();
	hangbanguanlixitong();
}
void xianshisuoyouhangbanxinxigongnen()
{
	hangbanxinxi b;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(b);
	ifile.seekg(0, ios::beg);
	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		ifile.read((char*)&b, sizeof(b));
		cout << i + 1 << "," << "航班号" << b.hangbanhao << "航空公司" << b.hangkonggongsi << "班期" << b.banqi << "始发城市" << b.shifachengshi << "抵达城市" << b.didachengshi << "抵达航站楼" << b.didahangzhanlou << "时间" << b.shijian << "头等舱数" << b.toudengcangshu << "公务舱数" << b.gongwucangshu << "经济舱数" << b.jingjicangshu << endl;
	}
	ifile.close();
}
void chaxunhangbanxinxigongneng()
{
	int xuanze;
	cout << "请输入所要查询的航班的信息" << endl;
	cout << "1.按照航班号查询" << endl;
	cout << "2.按照始发城市查询" << endl;
	cin >> xuanze;
	switch (xuanze)
	{
	case 1:anzhaohangbanhaochaxun();
	case 2:anzhaoshifachengshichaxun();
	}
	hangbanguanlixitong();

}
void anzhaohangbanhaochaxun()
{
	hangbanxinxi a;
	cout << "请输入要查询的航班的航班号" << endl;
	cin >> a.hangbanhao;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(hangbanxinxi);
	hangbanxinxi b;
	int c = 0;//判断有没有找到信息；
	ifile.seekg(0, ios::beg);
	for (int i = 0; i < n; i++)
	{
		ifile.read((char*)&b, sizeof(hangbanxinxi));
		if (a.hangbanhao == b.hangbanhao)
		{
			cout << "已查询到该航班信息！" << endl;
			cout << "该航班航班号为" << b.hangbanhao << "航空公司" << b.hangkonggongsi << "班期为" << b.banqi << "始发城市为" << b.shifachengshi << "抵达城市为" << b.didachengshi << "抵达航站楼为" << b.didahangzhanlou << "时间为" << b.shijian << "头等舱数为" << b.toudengcangshu << "公务舱数为" << b.gongwucangshu << "经济舱数为" << b.jingjicangshu << endl;
			c = 1;
			break;

		}
	}
	if (c == 0) { cout << "无法找到该航班信息"; }
	ifile.close();
	hangbanguanlixitong();
}
void anzhaoshifachengshichaxun()
{
	hangbanxinxi a;
	cout << "请输入要查询的航班的始发城市" << endl;
	cin >> a.shifachengshi;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(hangbanxinxi);
	hangbanxinxi b;
	int c = 0;
	ifile.seekg(0, ios::beg);
	for (int i = 0; i < n; i++)
	{
		ifile.read((char*)&b, sizeof(hangbanxinxi));
		if (a.shifachengshi == b.shifachengshi)
		{
			cout << "已查询到该航班信息！" << endl;
			cout << "该航班航班号为" << b.hangbanhao << "航空公司" << b.hangkonggongsi << "班期为" << b.banqi << "始发城市为" << b.shifachengshi << "抵达城市为" << b.didachengshi << "抵达航站楼为" << b.didahangzhanlou << "时间为" << b.shijian << "头等舱数为" << b.toudengcangshu << "公务舱数为" << b.gongwucangshu << "经济舱数为" << b.jingjicangshu << endl;
			c = 1;
		}
	}
	if (c == 0) { cout << "无法找到该航班信息"; }
	ifile.close();
	hangbanguanlixitong();
}
void xiugaihangbanxinxigongneng()
{
	hangbanxinxi a;
	cout << "请输入要修改航班的航班号" << endl;
	cin >> a.hangbanhao;
	hangbanxinxi b;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(hangbanxinxi);
	int c; c = 0;//判断是否查询到该信息
	ifile.seekg(0, ios::beg);
	int i;
	for (i = 0; i < n; i++)
	{
		ifile.read((char*)&b, sizeof(hangbanxinxi));
		if (b.hangbanhao == a.hangbanhao)
		{
		 c = 1;
			cout << "已查询到该航班信息！" << endl;
			cout << "该航班航班号为" << b.hangbanhao << "航空公司" << b.hangkonggongsi << "班期为" << b.banqi << "始发城市为" << b.shifachengshi << "抵达城市为" << b.didachengshi << "抵达航站楼为" << b.didahangzhanlou << "时间为" << b.shijian << "头等舱数为" << b.toudengcangshu << "公务舱数为" << b.gongwucangshu << "经济舱数为" << b.jingjicangshu << endl;
			break;
		}
	}
	ifile.close();
	if (c == 0) { cout << "未能找到该航班" << endl; }
	else
	{
		hangbanxinxi c;
		hangbanxinxi d;
		int s = a.hangbanhao;
		int i;
		ifstream ifile;
		ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
		ifile.seekg(0, ios::end);
		int len = ifile.tellg();
		int n = len / sizeof(hangbanxinxi);
		for (i = 0; i < n; i++)
		{
			ifile.seekg(sizeof(hangbanxinxi) * i);
			ifile.read((char*)&c, sizeof(hangbanxinxi));
			if (s == c.hangbanhao) { break; }
		}
		ifile.close();
		ofstream ofile;
		ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
		ofile.open("mayuan.zhongjie.txt", ios::binary | ios::trunc);
		ofile.close();
		ofile.open("mayuan.zhongjie.txt", ios::binary | ios::out);
		for (int j = 0; j < n; j++)
		{
				ifile.seekg(sizeof(hangbanxinxi) * j);
				ifile.read((char*)&c, sizeof(hangbanxinxi));
				if (j != i)
				{
					d.hangbanhao = c.hangbanhao;
					d.hangkonggongsi = c.hangkonggongsi;
					d.banqi = c.banqi;
					d.shifachengshi = c.shifachengshi;
					d.didachengshi = c.didachengshi;
					d.didahangzhanlou = c.didahangzhanlou;
					d.shijian = c.shijian;
					d.toudengcangshu = c.toudengcangshu;
					d.jingjicangshu = c.jingjicangshu;
					d.gongwucangshu = c.gongwucangshu;
					ofile.write((char*)&d, sizeof(hangbanxinxi));
				}
		}
		ifile.close();
		ofile.close();
		ifile.open("mayuan.zhongjie.txt", ios::binary);
		ofile.open("mayuan.hangbanxinxi.txt", ios::trunc);
		ofile.close();
		ofile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::out | ios::app);
		for (int k = 0; k < n - 1; k++)
			{
				ifile.seekg(sizeof(hangbanxinxi) * k);
				ifile.read((char*)&d, sizeof(d));
				c.hangbanhao = d.hangbanhao;
				c.hangkonggongsi = d.hangkonggongsi;
				c.banqi = d.banqi;
				c.shifachengshi = d.shifachengshi;
				c.didachengshi = d.didachengshi;
				c.didahangzhanlou = d.didahangzhanlou;
				c.shijian =d.shijian;
				c.toudengcangshu = d.toudengcangshu;
				c.jingjicangshu = d.jingjicangshu;
				c.gongwucangshu = d.gongwucangshu;
				ofile.write((char*)&c, sizeof(c));
		}
		ifile.close();
		ofile.close();
		ofile.open("mayuan.zhongjie.txt", ios::trunc);
		ofile.close();
		cout << "请输入修改后的航班的信息" << endl;
		cout << "航班的航空公司" << endl;
		cin >> a.hangkonggongsi;
		cout << "航班的班期" << endl;
		cin >> a.banqi;
		cout << "航班的始发城市" << endl;
		cin >> a.shifachengshi;
		cout << "航班的抵达城市" << endl;
		cin >> a.didachengshi;
		cout << "航班的抵达航站楼" << endl;
		cin >> a.didahangzhanlou;
		cout << "航班的时间" << endl;
		cin >> a.shijian;
		cout << "航班的头等舱数" << endl;
		cin >> a.toudengcangshu;
		cout << "航班的公务舱数" << endl;
		cin >> a.gongwucangshu;
		cout << "航班的经济舱数" << endl;
		cin >> a.jingjicangshu;
		ofile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::out|ios::app);
		ofile.write((char*)&a, sizeof(hangbanxinxi));
		ofile.close();
		cout << "修改成功！是否查看？" << endl;
		cout << "输入1查看修改后的所有航班信息，否则请输入0" << endl;
		int xuanze;
		cin >> xuanze;
		if (xuanze == 1) { xianshisuoyouhangbanxinxigongneng(); }
		else { ; }
	}
	hangbanguanlixitong();
}
void shanchuhangbanxinxigongneng()
{
	hangbanxinxi a;
	hangbanxinxi b;
	cout << "请输入您想删除航班的航班号" << endl;
	int s;
	cin >> s;
	int z; z = 0;
	int i;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	int n = len / sizeof(hangbanxinxi);
	for (i = 0; i < n; i++)
	{
		ifile.seekg(sizeof(hangbanxinxi) * i);
		ifile.read((char*)&a, sizeof(hangbanxinxi));
		if (s == a.hangbanhao) { z = 1; break; }
	}
	ifile.close();
	if (z == 0) { cout << "未找到该航班" << endl; }
	else
	{
		ifstream ifile;
		ofstream ofile;
		ifile.open("mayuan.hangbanxinxi.txt", ios::binary);
		ofile.open("mayuan.zhongjie.txt",ios::binary| ios::trunc);
		ofile.close();
		ofile.open("mayuan.zhongjie.txt", ios::binary | ios::out);
		for (int j = 0; j < n; j++)
		{
			ifile.seekg(sizeof(hangbanxinxi) * j);
			ifile.read((char*)&a, sizeof(hangbanxinxi));
			if (j != i)
			{ 
				b.hangbanhao = a.hangbanhao;
				b.hangkonggongsi = a.hangkonggongsi;
				b.banqi = a.banqi;
				b.shifachengshi = a.shifachengshi;
				b.didachengshi = a.didachengshi;
				b.didahangzhanlou = a.didahangzhanlou;
				b.shijian = a.shijian;
				b.toudengcangshu = a.toudengcangshu;
				b.jingjicangshu = a.jingjicangshu;
				b.gongwucangshu = a.gongwucangshu;
				ofile.write((char*)&b, sizeof(hangbanxinxi));
			}
		}
		ifile.close();
		ofile.close();
		ifile.open("mayuan.zhongjie.txt", ios::binary);
		ofile.open("mayuan.hangbanxinxi.txt", ios::trunc);
		ofile.close();
		ofile.open("mayuan.hangbanxinxi.txt", ios::binary | ios::out|ios::app);
		for (int k = 0; k < n - 1; k++)
		{
			ifile.seekg(sizeof(hangbanxinxi) * k);
			ifile.read((char*)&b, sizeof(b));
			a.hangbanhao = b.hangbanhao;
			a.hangkonggongsi = b.hangkonggongsi;
			a.banqi = b.banqi;
			a.shifachengshi = b.shifachengshi;
			a.didachengshi = b.didachengshi;
			a.didahangzhanlou = b.didahangzhanlou;
			a.shijian = b.shijian;
			a.toudengcangshu = b.toudengcangshu;
			a.jingjicangshu = b.jingjicangshu;
			a.gongwucangshu = b.gongwucangshu;
			ofile.write((char*)&a, sizeof(a));
		}
		ifile.close();
		ofile.close();
		ofile.open("mayuan.zhongjie.txt", ios::trunc);
		ofile.close();
		cout << "删除成功！" << endl;
	}
	hangbanguanlixitong();
}


