#include"boss.h"


//构造函数
Boss::Boss(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// 重写基类中的纯虚函数 showInfo
// 用于显示经理的个人信息
void Boss::showInfo()
{
    cout << "従業員番号：" << this->m_Id
        << "\t従業員名：" << this->m_Name
        << "\t職位：" << this->getDeptName()
        << "\t職務内容：会社のすべての業務を管理する"
        << endl;
}

// 重写基类中的纯虚函数 getDeptName
// 返回经理所属的岗位名称
string Boss::getDeptName()
{
    return string("上司");
}