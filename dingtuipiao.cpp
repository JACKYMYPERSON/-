#include<iostream>
#include<fstream>
#include<sm.h>
#include<cmath>
using namespace std;
void dingtuipiaoxitong()
{
	cout << "您已经入订退票系统***" << "请选择您的选项！" << endl;
	cout << "1.订票" << endl;
	cout << "2.退票" << endl;
	cout << "3.退出系统" << endl;
	int xuanze;
	cin >> xuanze;
	if (xuanze >= 1 && xuanze <= 3)
	{
		switch (xuanze)
		{
		case 1:dingpiao();
		case 2:tuipiao();
		case 3:jinruxitong();
		}
	}
	else { cout << "输入有误"; }
}
void dingpiao()
{
	int z1 ;
	z1 = 0;
	ifstream ifile;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary|ios::in);
	hangbanxinxi w;
	ifile.seekg(0, ios::end);
	int lenk = ifile.tellg() / sizeof(w);
	ifile.seekg(0, ios::beg);
	for (int i = 0; i < lenk; i++)
	{
		ifile.read((char*)&w, sizeof(w));
		cout << i + 1 << "," << "航班号" << w.hangbanhao << "航空公司" << w.hangkonggongsi << "班期" << w.banqi << "始发城市" << w.shifachengshi << "抵达城市" << w.didachengshi << "抵达航站楼" << w.didahangzhanlou << "时间" << w.shijian << "头等舱数" << w.toudengcangshu << "公务舱数" << w.gongwucangshu << "经济舱数" << w.jingjicangshu << endl;
	}
	ifile.close();
	int q;//储存航班号
	int i;
	int z; z = 0;//查找航班号失败
	int z2; z2 = 0;//查找座位等级
	int riqi;//开始日期的转换
	hangbanxinxi a;
	ifile.open("mayuan.hangbanxinxi.txt", ios::binary|ios::in);
	ifile.seekg(0, ios::end);
	int len = ifile.tellg();
	cout << len<<endl;
	int n = len / sizeof(hangbanxinxi);
	cout << n << endl;
	while (true)
	{
		cout << "请输入您要订的航班的航班号" << endl;
		cin >> q;
		for (i = 0; i < n; i++)
		{
			ifile.seekg(sizeof(a) * i);
			ifile.read((char*)&a, sizeof(a));
			if (a.hangbanhao == q) { z = 1; break; }

		}
		if (z != 1) { cout << "输入的航班号有误"; }
		else { break; }
	}
	ifile.close();
	if (z == 1)
	{
		
		cout << "已为您找到航班号为" << q << "的航班" << endl;
		cout << "该航班的班期为：" << a.banqi << endl;
		//开始匹配日期和班期
		while (true)
		{
			cout << "请输入您想选择的日期：" << "格式为xxxx年xx月xx日（输入数字即可）" << endl;
			cin >> riqi;
			int year, month, day;
			year = riqi / 10000;
			month = riqi / 100 - year;
			day = riqi % 100;
			if (month == 1 || month == 2)
			{
				month += 12;
				--year;
			}
			int weekday;
			weekday = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;//运用了基姆拉尔森公式计算星期
			month -= 12;
			++year;
			int p = 0;//班期转换循环次数；
			int cun;//对a.班期的存储
			cun = a.banqi;
			while (cun != 0)
			{
				cun = cun / 10;
				++p;
			}
			cun = a.banqi;
			for (int k = 0; k < p; k++)
			{
				int bencixingqishu;
				int xiaci = cun;
				bencixingqishu = xiaci;
				if (cun / 10 != 0) { bencixingqishu = cun / pow(10, p - (k + 1)); xiaci = cun - bencixingqishu * pow(10, p - (k + 1)); }//把班期转换为星期
				else { bencixingqishu = cun % 10; }
				if ((weekday + 1) == bencixingqishu)
				{
					cout << "已经为您找到日期为" << riqi << "航班号为" << q << "的航班";
					z1 = 1;
					break;
				}

			}
			if (z1 == 0) { cout << "没有找到该航班,请重新输入想选择的日期" << endl; }

			else {  break; }

		}
		dingdanmingxixinxi b;
		dingdanmingxixinxi c;
		int toudengcangshuliang = 0;
		int gongwucangshuliang = 0;
		int jingjicangshuliang = 0;
		ofstream ofile;
		ofile.open("mayuan.dingdan.txt", ios::out | ios::binary|ios::app);
		ofile.close();
		ifstream ifile;
		ifile.open("mayuan.dingdan.txt", ios::in | ios::binary);
		ifile.seekg(0, ios::end);
		int len1 = ifile.tellg();
		int n1 = len1 / sizeof(dingdanmingxixinxi); 
		for (int k = 0; k < n1; k++)
		{
				ifile.seekg(sizeof(dingdanmingxixinxi) * k);
				ifile.read((char*)&b, sizeof(dingdanmingxixinxi));
				
				if (b.zuoweidengji == "toudengcang")
				{
					toudengcangshuliang += 1;
				}
				if (b.zuoweidengji == "gongwucang")
				{
					gongwucangshuliang += 1;
				}
				if (b.zuoweidengji == "jingjicang")
				{
					jingjicangshuliang += 1;
				}
		}
		ifile.close(); 
		cout << "已经为您选择航班号为" << q << "日期为" << riqi << "的航班" << endl;
		cout << "该航班的头等舱数为：" << a.toudengcangshu << "   公务舱数为：" << a.gongwucangshu << "  经济舱数为：" << a.jingjicangshu << endl;
		cout << "该航班头等舱剩余数量为" << a.toudengcangshu - toudengcangshuliang << "  公务舱剩余数量为" << a.gongwucangshu - gongwucangshuliang << "  经济舱剩余数量为" << a.jingjicangshu - jingjicangshuliang << endl;
		if (a.toudengcangshu - toudengcangshuliang != 0 && a.gongwucangshu - gongwucangshuliang != 0 && a.jingjicangshu - jingjicangshuliang != 0)
		{
				cout << "请选择您要选的座位等级" << endl;
				cout << "1.头等舱" << endl;
				cout << "2.公务舱" << endl;
				cout << "3.经济舱" << endl;
				int r;
				cin >> r;
				while (true)
				{
					switch (r)
					{
					case 1:if (a.toudengcangshu - toudengcangshuliang == 0) { cout << "头等舱数目已满" << "请重新输入您要选择的座位等级" << endl; break; }
						  else { z2 = 1; c.zuoweidengji = "toudengcang"; break; }
					case 2:if (a.gongwucangshu - toudengcangshuliang == 0) { cout << "公务舱数目已满" << "请重新输入您要选择的座位等级" << endl; break; }
						  else { z2 = 1; c.zuoweidengji = "gongwucang"; break; }
					case 3:if (a.jingjicangshu - jingjicangshuliang == 0) { cout << "经济舱数目已满" << "请重新输入您要选择的座位等级" << endl; break; }
						  else { z2 = 1; c.zuoweidengji = "jingjicang"; break; }
					}
					if (z2 == 1) { break; }
				}
				if (z2 == 1)
				{
					cout << "订票成功！" << endl;
					cout << "请输入您的姓名" << endl;
					cin >> c.chengkexingming;
					cout << "请输入您的手机号" << endl;
					cin >> c.dianhuahaoma;
					cout << "请输入您的身份证号" << endl;
					cin >> c.shenfenzhenghao;
					c.chufariqi = riqi;
					c.hangbanhao = q;
					ifile.open("mayuan.dingdan.txt", ios::in | ios::binary);
					ifile.seekg(0, ios::end);
					int len1 = ifile.tellg();
					int n1 = len1 / sizeof(dingdanmingxixinxi); 
					c.dingdanhao = 220 + n1;
					ifile.close();
					ofile.open("mayuan.dingdan.txt", ios::app | ios::binary |ios::out);
					ofile.write((char*)&c, sizeof(c));
					ofile.close();
					cout << "您的订单信息已输入！" << endl;
					cout << "订单号为：" << c.dingdanhao;
				}
		}
		else
		{
				cout << "很抱歉" << "航班号为" << q << "日期为" << riqi << "的航班" << "座位已满" << endl;
		}
	}
	dingtuipiaoxitong();
		
}
void tuipiao()
{
	cout << "已准备为您退票，请输入您的身份证号" << endl;
	long long int shenfenzheng;
	cin >> shenfenzheng;
	int n = 0;//符合的数量
	dingdanmingxixinxi a;
	dingdanmingxixinxi b;
	ifstream ifile;
	ifile.open("mayuan.dingdan.txt", ios::binary);
	ifile.seekg(0, ios::end);
	int len2 = ifile.tellg();
	int u = len2 / sizeof(dingdanmingxixinxi);
	ofstream ofile;
	ofile.open("mayuan.dingdan1.txt", ios::binary | ios::out|ios::app);
	for (int i = 0; i < u; i++)
	{
		ifile.seekg(sizeof(a) * i);
		ifile.read((char*)&a, sizeof(a));
		if (shenfenzheng == a.shenfenzhenghao)
		{
			cout << "dingdanhao：" << a.dingdanhao;
			b.dingdanhao = a.dingdanhao;
			b.hangbanhao = a.hangbanhao;
			b.chufariqi = a.chufariqi;
			b.zuoweidengji = a.zuoweidengji;
			b.chengkexingming = a.chengkexingming;
			b.shenfenzhenghao = a.shenfenzhenghao;
			b.dianhuahaoma = a.dianhuahaoma;
			ofile.write((char*)&b, sizeof(b));
			++n;
		}
	}
	ifile.close();
	ofile.close();
	if (n == 0) { cout << "未找到身份证号为" << shenfenzheng << "的乘客" << endl; }
	else
	{
		cout << "已找到身份证号为" << shenfenzheng << "的乘客" << endl;
		ifile.open("mayuan.dindan1.txt", ios::binary | ios::in);
		for (int i = 0; i < n; i++)
		{
			ifile.seekg(sizeof(a) * i);
			ifile.read((char*)&a, sizeof(a));
			cout << i + 1 << "." << "订单号为:" << a.dingdanhao << "乘客姓名为:" << a.chengkexingming << "电话号码为:" << a.dianhuahaoma << "航班号为:" << a.hangbanhao << "出发日期为:" << a.chufariqi << "座位等级为:" << a.zuoweidengji << endl;
		}
		cout << "请输入所要退票的订单号" << endl;
		int dingdanhao;
		int y = 0;
		while (true)
		{
			cin >> dingdanhao;
			for (int i = 0; i < n; i++)
			{
				ifile.seekg(sizeof(a) * i);
				ifile.read((char*)&a, sizeof(a));
				if (dingdanhao == a.dingdanhao)
				{
					y =1;
					break;
				}
			}
			if (y == 0) { cout << "未找到该订单号，请重新输入" << endl; }
			else { break; }
		}
		ifile.close();
		ifile.open("mayuan.dingdan1.txt", ios::binary | ios::trunc);
		ifile.close();
		ofile.close();
		if (y == 1)
		{
			dingdanmingxixinxi a;
			ifile.open("mayuan.dingdan.txt", ios::binary);
			ofile.open("mayuan.dingdan2.txt", ios::trunc | ios::binary);
			ofile.close();
			ofile.open("mayuan.dingdan2.txt", ios::trunc | ios::out);
			for (int i = 0; i < u; i++)
			{
				ifile.seekg(sizeof(dingdanmingxixinxi) * i);
				ifile.read((char*)&a, sizeof(a));
				if (a.shenfenzhenghao != shenfenzheng && a.dingdanhao != dingdanhao)
				{
					ofile.write((char*)&a, sizeof(a));
				}
			}
			ifile.close();
			ofile.close();
			ifile.open("mayuan.dingdan2.txt", ios::binary);
			ofile.open("mayuan.dingdan.txt", ios::trunc | ios::binary);
			ofile.close();
			ofile.open("mayuan.dingdan.txt", ios::binary | ios::out);
			for (int i = 0; i < u - 1; i++)
			{
				ifile.seekg(sizeof(a) * i);
				ifile.read((char*)&a, sizeof(a));
				ofile.write((char*)&a, sizeof(a));
			}
			cout << "退票成功！" << endl;
			ifile.close();
			ofile.close();
			ofile.open("mayuan.dingdan2.txt", ios::binary | ios::trunc);
			ofile.close();
			dingtuipiaoxitong();
		}	
	}
}