#include<iostream>
using namespace std;
void jinruxitong();
void hangbanguanlixitong();//�������ϵͳ
void dingtuipiaoxitong();//����Ʊ����ϵͳ
void shoupiaoguanlixitong();//ͳ����Ʊϵͳ/*ϵͳ��*/
void tianjiahangbangongneng();//��Ӻ��๦��
void xianshisuoyouhangbanxinxigongneng();//��ʾ�����а���Ϣ����
void xianshisuoyouhangbanxinxigongnen();//fuben
void chaxunhangbanxinxigongneng();//��ѯ������Ϣ����
void xiugaihangbanxinxigongneng();//�޸ĺ�����Ϣ����
void shanchuhangbanxinxigongneng();//ɾ��������Ϣ����    ������
void anzhaohangbanhaochaxun();
void anzhaoshifachengshichaxun();
void dingpiao();
void tuipiao();
void xianshisuoyoudingdanxinxi();
class hangbanxinxi
{
public:
	long long int hangbanhao;//�����
	string hangkonggongsi;//���չ�˾
	long long int banqi;//����
	string shifachengshi;//ʼ������
	string didachengshi;//�ִ����
	string didahangzhanlou;//�ִﺽվ¥
	long long int shijian;//ʱ��
	long long int toudengcangshu;//ͷ�Ȳ���
	long int gongwucangshu;//�������
	long int jingjicangshu;//���ò���
};
class dingdanxinxi
{
public:
	long long int dingdanhao;//������
	string kehuxingming;//�ͻ�����
	long long int dianhuahaoma;//�绰����
	long long int zongjine;//�ܽ��
	long long int riqi;//����
};
class dingdanmingxixinxi
{
public:
	long long int dingdanhao;//������
	long long int hangbanhao;//�����
	long long int chufariqi;//��������
	string zuoweidengji;//��λ�ȼ�
	string chengkexingming;//�˿�����
	long long int shenfenzhenghao;//���֤��
	long long int dianhuahaoma;//�绰����
};

