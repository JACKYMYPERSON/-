#include<iostream>
using namespace std;
void jinruxitong();
void hangbanguanlixitong();//航班管理系统
void dingtuipiaoxitong();//订退票管理系统
void shoupiaoguanlixitong();//统计售票系统/*系统类*/
void tianjiahangbangongneng();//添加航班功能
void xianshisuoyouhangbanxinxigongneng();//显示所有行班信息功能
void xianshisuoyouhangbanxinxigongnen();//fuben
void chaxunhangbanxinxigongneng();//查询航班信息功能
void xiugaihangbanxinxigongneng();//修改航班信息功能
void shanchuhangbanxinxigongneng();//删除航班信息功能    大功能类
void anzhaohangbanhaochaxun();
void anzhaoshifachengshichaxun();
void dingpiao();
void tuipiao();
void xianshisuoyoudingdanxinxi();
class hangbanxinxi
{
public:
	long long int hangbanhao;//航班号
	string hangkonggongsi;//航空公司
	long long int banqi;//班期
	string shifachengshi;//始发城市
	string didachengshi;//抵达城市
	string didahangzhanlou;//抵达航站楼
	long long int shijian;//时间
	long long int toudengcangshu;//头等舱数
	long int gongwucangshu;//公务舱数
	long int jingjicangshu;//经济舱数
};
class dingdanxinxi
{
public:
	long long int dingdanhao;//订单号
	string kehuxingming;//客户姓名
	long long int dianhuahaoma;//电话号码
	long long int zongjine;//总金额
	long long int riqi;//日期
};
class dingdanmingxixinxi
{
public:
	long long int dingdanhao;//订单号
	long long int hangbanhao;//航班号
	long long int chufariqi;//出发日期
	string zuoweidengji;//座位等级
	string chengkexingming;//乘客姓名
	long long int shenfenzhenghao;//身份证号
	long long int dianhuahaoma;//电话号码
};

