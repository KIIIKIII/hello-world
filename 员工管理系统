#pragma once//员工管理系统
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
const int LEN = 50;//常量表示字符数组长度

class CEducation {//CEducation教育背景类的声明
public:
	CEducation() { };//构造函数
	CEducation(char cSchool[], char cDegree) {//重载构造函数为数据成员赋初值
		strcpy_s(m_cSchool, cSchool);
		m_cDegree = cDegree;
	}
	void GetEdu() {//输入教育背景的有关数据
		cout << endl << "毕业学校：";
		cin >> m_cSchool;
		cout << endl << "最高学历：（专科H、本科B、硕研M、博研D）";
		cin >> m_cDegree;
		m_cDegree = toupper(m_cDegree);//将用户输入的学历规范为大写字母
		
	}
	void PutEdu() const {//输出教育背景的有关信息
		cout << endl << "毕业学校：" << m_cSchool << endl;
		cout << endl << "最高学历：";
		switch (m_cDegree) {
		case 'H':
			cout << "专科" << endl;
			break;
		case 'B':
			cout << "本科" << endl;
			break;
		case 'M':
			cout << "硕研" << endl;
			break;
		case 'D':
			cout << "博研" << endl;
			break;
		default:
			cout << "空" << endl;
			break;
		}
	}
private:
	char m_cSchool[LEN];//毕业学校
	char m_cDegree;//最高学历
};

class Staff {//员工类（公共基类、组合类）
public:
	Staff() { };//构造函数
	~Staff() { };//空析构函数
	void CalculateSal() {//计算实发工资
		cout << endl << "当月实发工资：" << m_fBasicSal + m_fPrize * m_fRateOfAttend << "元" << endl;
	}
	void OutPut() {//输出员工基本信息
		cout << endl << "显示员工" << m_cName << "的基本数据：";
		cout << endl << "工作编号：" << m_iStaffNum;
		Edu.PutEdu();
		cout << endl << "基本工资：" << m_fBasicSal;
		cout << endl << "奖金：" << m_fPrize;
		cout << endl << "出勤率：" << m_fRateOfAttend * 100 << "%";
	}
	void InPut() {//输入员工各项数据
		m_iStaffNum = ++s_iCount;//静态累加器自加1后赋给工作编号
		cout << endl << "请输入编号为" << m_iStaffNum << "号员工的姓名：";
		cin >> m_cName;//输入员工姓名
		Edu.GetEdu();//子对象调用类CEducation的GetEdu()，输入教育背景数据
		cout << endl << "基本工资：";
		cin >> m_fBasicSal;
		cout << endl << "奖金：";
		cin >> m_fPrize;
		cout << endl << "出勤率：";
		cin >> m_fRateOfAttend;

		if (m_fRateOfAttend > 1.0) m_fRateOfAttend = 1.0;
		else if (m_fRateOfAttend < 0) m_fRateOfAttend = 0;
	}
protected:
	CEducation Edu;//子对象（教育背景）
	int m_iStaffNum;//工作编号
	char m_cName[LEN];//姓名
	float m_fRateOfAttend;//出勤率
	float m_fBasicSal;//基本工资
	float m_fPrize;//奖金
	static int s_iCount;//静态累加器
};

class CAdminStaff :public Staff {//声明派生类：行政人员
public:
	CAdminStaff() { };//派生类构造函数
	~CAdminStaff() { };//派生类析构函数
	void CalculateSal() {//计算行政人员的实际发放工资：基本工资+奖金*出勤率
		cout << endl << "当月实发工资：" << m_fBasicSal + m_fPrize * m_fRateOfAttend << "元" << endl;
	}
};

class CManager :virtual public Staff {//声明派生类：经理，将Staff声明为虚基类
public:
	CManager() { };//构造函数
	void SetMData() {//输入经理数据
		cout << endl << "公司总销售额：";
		cin >> m_fTAmount;
		cout << endl << "提成比例：";
		cin >> m_fDeductTRate;
	}
	void CalculateSal() {//计算经历的实发工资：基本工资+总销售额*提成比例
		cout << endl << "当月实发工资：";
		cout << m_fBasicSal + m_fTAmount * m_fDeductTRate << "元" << endl;
	}
protected:
	float m_fDeductTRate;//经理提成比例
	float m_fTAmount;//总销售额
};

class CSaleman :virtual public Staff {//声明派生类：销售员，将Staff声明为虚基类
public:
	CSaleman() { };//构造函数
	void SetSData() {//输入销售员数据
		cout << endl << "个人销售额：";
		cin >> m_fPersonAmount;
		cout << endl << "提成比例：";
		cin >> m_fDeductRate;
	}
	void CalculateSal() {//计算销售员实际发放工资：基本工资+个人销售额*提成比例
		cout << endl << "当月实发工资：";
		cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate << "元" << endl;
	}
protected:
	float m_fDeductRate;//销售员提成比例
	float m_fPersonAmount;//个人销售额
};

class CSaleManager :public CSaleman, public CManager {//声明多继承中的派生类：销售经理
public:
	CSaleManager() { };
	void CalculateSal() {//计算销售经理实际发放工资：基本工资+个人销售额*提成比例+总销售额*提成比例
		cout << endl << "当月实发工资：";
		cout << m_fBasicSal + m_fPersonAmount * m_fDeductRate + m_fTAmount * m_fDeductTRate;
		cout << "元" << endl;
	}
};

int Staff::s_iCount = 1000;//初始化静态数据成员s_iCount

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "类.h"

int main() {
	char flag = 'Y';
	while (toupper(flag) == 'Y') {
		cout << "请选择录入类别（1.经理 2.销售员 3.销售经理 4.行政人员）：";
		int n;
		cin >> n;
		switch (n) {
		case 1: {
			CManager staff;//创建一个经理类对象
			staff.InPut();//调用基类的成员函数
			staff.SetMData();//调用经理类的成员函数
			staff.OutPut();//调用基类的成员函数
			staff.CalculateSal();//调用经理类的成员函数
			break;
		}
		case 2: {
			CSaleman staff;
			staff.InPut();
			staff.SetSData();
			staff.OutPut();
			staff.CalculateSal();
			break;
		}
		case 3: {
			CSaleManager staff;
			staff.InPut();
			staff.SetMData();
			staff.SetSData();
			staff.OutPut();
			staff.CalculateSal();
			break;
		}
		case 4: {
			CAdminStaff staff;
			staff.InPut();
			staff.OutPut();
			staff.CalculateSal();
			break;
		}
		default: {
			cout << "选择有误！" << endl;
			break;
		}
		}
		cout << endl << "是否继续录入信息？（Y/N）";
		cin >> flag;
	}

	return 0;
}
