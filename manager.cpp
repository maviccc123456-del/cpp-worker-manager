#include"manager.h"


//构造函数
Manager::Manager(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// 重写基类中的纯虚函数 showInfo
// 用于显示经理的个人信息
void Manager::showInfo()
{
    cout << "従業員番号：" << this->m_Id
        << "\t従業員名：" << this->m_Name
        << "\t職位：" << this->getDeptName()
        << "\t職務内容：上司から任された仕事を完了させ、従業員にタスクを割り当てる"
        << endl;
}

// 重写基类中的纯虚函数 getDeptName
// 返回经理所属的岗位名称
string Manager::getDeptName()
{
    return string("マネージャー");
}