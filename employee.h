//普通员工
#pragma once //防止头文件重复包含
#include<iostream> //包含输入输出流头文件
using namespace std; //使用标准命名空间
#include"worker.h"

// Employeee 类：继承自 Worker
// 这是一个【具体派生类】，用于表示“普通员工”
class Employee : public Worker
{
public:
    //构造函数
    Employee(int id,string name,int dId);

    // 重写基类中的纯虚函数 showInfo
    // 用于显示普通员工的个人信息
    virtual void showInfo();

    // 重写基类中的纯虚函数 getDeptName
    // 返回普通员工所属的岗位名称
    virtual string getDeptName();
};