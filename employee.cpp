#include"employee.h"


//构造函数
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

// 重写基类中的纯虚函数 showInfo
// 用于显示普通员工的个人信息
void Employee::showInfo()
{
    cout << "従業員番号：" << this->m_Id
        << "\t従業員名：" << this->m_Name
        << "\t職位：" << this->getDeptName()
        << "\t職務内容：マネージャーから与えられた業務を遂行する"
        << endl;
}

// 重写基类中的纯虚函数 getDeptName
// 返回普通员工所属的岗位名称
string Employee::getDeptName()
{
    return string("従業員");
}