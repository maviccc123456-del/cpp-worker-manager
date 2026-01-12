#include "workerManager.h"

WorkerManager:: WorkerManager()
{   
    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//读文件

    if (!ifs.is_open())
    {
       // cout << "ファイルが存在しません" << endl; 测试代码
        //初始化属性
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArry = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //2.文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //文件为空
        //cout << "ファイルにデータがありません" << endl;测试代码
        //初始化数组指针
        this->m_EmpArry = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //3.文件存在，并且记录了数据
    int num = this->get_EmpNum();

    // cout << "従業員の人数は" <<num<< endl; 测试代码
    this->m_EmpNum = num;

    //开辟空间
    this->m_EmpArry = new Worker * [this->m_EmpNum];
    //将文件中的数据，存到数组中
    this->init_Emp();
    
    
    //测试代码
  /*  for (int i = 0; i < this->m_EmpNum; i++)
    {
        cout << "职工编号"<<this->m_EmpArry[i]->m_Id 
             << "姓名" << this->m_EmpArry[i]->m_Name 
             << "部门编号" << this->m_EmpArry[i]->m_DeptId << endl;
    }*/


}

//展示菜单
void WorkerManager::show_Menu()
{
    cout << "*****************************************" << endl;
    cout << "****** 従業員管理システムへようこそ *****" << endl;
    cout << "*****************************************" << endl;
    cout << "******** 0. 管理プログラムを終了 ********" << endl;
    cout << "******** 1. 従業員情報を追加 ************" << endl;
    cout << "******** 2. 従業員情報を表示 ************" << endl;
    cout << "******** 3. 退職した従業員を削除 ********" << endl;
    cout << "******** 4. 従業員情報を変更 ************" << endl;
    cout << "******** 5. 従業員情報を検索 ************" << endl;
    cout << "******** 6. 番号順に並べ替え ************" << endl;
    cout << "******** 7. すべてのデータを削除 ********" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
    cout << "またのご利用をお待ちしております" << endl;
    system("pause");
    exit(0);
}

//保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);//用输出的方式来打开文件

    //将每个人的数据写入到文件中
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArry[i]->m_Id << " "
            << this->m_EmpArry[i]->m_Name << " "
            << this->m_EmpArry[i]->m_DeptId << endl;
    }
    //关闭文件
    ofs.close();
}


//添加职工
void WorkerManager::Add_Emp()
{
    cout << "追加する会社関係者の人数を入力してください" << endl;

    int addNum = 0;//保存用户的输入数量
    cin >> addNum;

    if (addNum > 0)
    {
        //添加
        //计算添加新的空间大小
        int newSize = this->m_EmpNum + addNum; //新空间大小=等于原来的人数+新增人数
        
        //开辟新空间
        Worker ** newSpace = new Worker * [newSize];

        //将原来空间下的数据，拷贝到新空间下
        if (this->m_EmpArry != NULL)
        {
            for (int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i] = this->m_EmpArry[i];
            }
        }
        //批量添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;//职工编号
            string name;//职工姓名
            int dSelect;//部门选择

            cout  << i+1 << "人目の新しい会社関係者の番号を入力してください" << endl;
            cin >> id;

            cout << i + 1 << "人目の新しい会社関係者の名前を入力してください" << endl;
            cin >> name;

            cout << "この従業員の職種を選択してください：" << endl;
            cout << "1、一般従業員" << endl;
            cout << "2、マネージャー" << endl;
            cout << "3、社長" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            //将创建职工职责，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;

        }

        //手动释放原有空间
        delete[] this->m_EmpArry;

        //更改新空间的指向
        this->m_EmpArry = newSpace;

        //更新新的职工人数
        this->m_EmpNum = newSize;

        //更新职工不为空的标志
        this->m_FileIsEmpty = false;

        //提升添加成功
        cout << "従業員"<<addNum<<"名の追加に成功しました" << endl;

        //保存到文件中
        this->save();
    }
    else
    {
        cout << "入力データが正しくありません" << endl;
    }
    //按任意键返回
    system("pause");
    system("cls");

}
//统计文件中的人数
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//打开文件，读
    int id;
    string name;
    int dId;

    int num = 0;


    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        //统计人数
        num++;
    }
    return num;
}
//初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker* worker = NULL;

        if (dId == 1)//普通员工
        {
            worker = new Employee(id, name, dId);

        }
        else if(dId == 2)//经理
        {
            worker = new Manager(id, name, dId);

        }
        else if (dId == 3)//老板
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArry[index] = worker;
        index++;
    }

    //关闭文件
    ifs.close();
}

//显示职工
void WorkerManager::Show_Emp()
{
    //判断文件是否存在
    if (this->m_FileIsEmpty)
    {
        cout << "ファイルが存在しない、またはファイルにデータがありません" << endl; 
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            //调用多态调用程序接口
            this->m_EmpArry[i]->showInfo();
        }

    }
    //按任意键清除屏幕
    system("pause");
    system("cls");
}

//删除职工
void WorkerManager::Del_Emp() 
{
    if (this->m_FileIsEmpty)
    {
        cout << "ファイルが存在しない、またはファイルにデータがありません" << endl;
        //按任意键清除屏幕
        system("pause");
        system("cls");
    }
    else
    {
        //按照职工编号删除
        cout << "削除したい会社関係者の番号を入力してください" << endl;
            int id = 0;
            cin >> id;
            
            int index = this->IsExist(id);

            if (index != -1)//职工存在,并且要删除掉index位置上的职工
            {
                
                for (int i = index; i < this->m_EmpNum - 1; i++)
                {   
                    //数据前移
                    this->m_EmpArry[i] = this->m_EmpArry[i + 1];
                }
                this->m_EmpNum--;//更新数组中记录人员的个数
                //将数据同步更新到文件中
                this->save();

                cout << "削除に成功しました" << endl;
            }
            else
            {
                cout << "削除に失敗しました。該当する従業員が見つかりません" << endl;
            }
    }
    //清除屏幕
    system("pause");
    system("cls");
}

//判断职工是否存在，如果存在返回职工所在数组中位置，不存在返回-1
int WorkerManager::IsExist(int id) 
{
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArry[i]->m_Id == id)
        {
            //找到了职工
            index = i;
            break;
        }
    }
    return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "ファイルが存在しない、またはファイルにデータがありません" << endl;
    }
    else
    {
        cout << "変更する会社関係者の番号を入力してください" << endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1)
        {
            //查找到编号的职工
            delete this->m_EmpArry[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout<<id<<"番の会社関係者が見つかりました、新しいIDを入力してください" << endl;
            cin >> newId;

            cout << "新しい名前を入力してください：" << endl;
            cin >> newName;

            cout << "職種を入力してください：" << endl;
            cout << "1、一般従業員" << endl;
            cout << "2、マネージャー" << endl;
            cout << "3、社長" << endl;

            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }
            //更新数据，到数组中
            this->m_EmpArry[ret] = worker; 

            cout << "変更に成功しました" << endl;

            //保存文件
            this->save();

        }
        else
        {
            cout << "変更に失敗しました。この番号の会社関係者が見つかりません。" << endl;
        }
    }
    //清除屏幕
    system("pause");
    system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "ファイルが存在しない、またはファイルにデータがありません" << endl;
    }
    else
    {
        cout << "検索方法を入力してください：" << endl;
        cout << "1、会社関係者番号で検索" << endl;
        cout << "2、会社関係者の名で検索" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            //按照编号查
            int id;
            cout<< "検索したい番号を入力してください " << endl;
            cin >> id;

           int ret = IsExist(id);
           if (ret != -1)
           {
                //找到职工
               cout << "会社関係者が見つかりました。情報は以下のとおりです。" << endl;
               this->m_EmpArry[ret]->showInfo();
           }
           else
           {
               cout << "この会社関係者は見つかりませんでした" << endl;
           }
        }
        else if (select == 2)
        {
            //按照姓名查
            string name;
            cout << "会社関係者の名前を入力してください" << endl;
            cin >> name;

            //加入判断是否查到的标志
            bool flag = false;

            for (int i = 0; i < m_EmpNum; i++)
            {
                if (this->m_EmpArry[i]->m_Name == name)
                {
                    cout << "検索に成功しました。会社関係者の番号は " << this->m_EmpArry[i]->m_Id
                        << " です。従業員情報は以下のとおりです：" << endl;

                    flag = true;

                    //调用显示信息接口
                    this->m_EmpArry[i]->showInfo();
                }
            }
            if (flag == false)
            {
                cout << "この会社関係者は見つかりませんでした" << endl;
            }
        }
        else {
         
                cout << "会社関係者が見つかりました。情報は以下のとおりです。" << endl;
        }
    }
    //清除屏幕
    system("pause");
    system("cls");
}

//按照职工编号排序
void WorkerManager::sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "ファイルが存在しない、またはファイルにデータがありません" << endl;
    }
    else
    {
        cout << "並び替え方法を選択してください：" << endl;
        cout << "1、会社関係者の番号を昇順で並び替え" << endl;
        cout << "2、会社関係者の番号を降順で並び替え" << endl;

        int select = 0;
        cin >> select;
        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i;//声明最小值 或者 最大值下标
            for (int j=i+1;j<this->m_EmpNum;j++)
            {
                if (select == 1)//升序
                {
                    if (this->m_EmpArry[minOrMax]->m_Id > this->m_EmpArry[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
                else//降序
                {
                    if (this->m_EmpArry[minOrMax]->m_Id < this->m_EmpArry[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
            }
            //判断一开始认定最小值或者最大值是不是计算的最小值或最大值，如果不是 交换数据
            if (i != minOrMax)
            {
                Worker* temp = this->m_EmpArry[i];
                this->m_EmpArry[i] = this->m_EmpArry[minOrMax];
                this->m_EmpArry[minOrMax] = temp;
            }
        }
        cout << "並び替えに成功しました！並び替え後の結果は以下のとおりです：" << endl;
        this->save();      // 排序后的结果保存到文件中
        this->Show_Emp();  // 展示所以职工

    }
}

//清空文件
void WorkerManager::Clean_File()
{
    cout << "本当にクリアしますか？" << endl;
    cout << "1、確定" << endl;
    cout << "2、戻る" << endl;

    int select = 0;
    cin >> select;

    if (select==1)
    {   
        //清空文件
        ofstream ofs(FILENAME, ios::trunc);//删除后重新创建
        ofs.close();

        if(this->m_EmpArry!=NULL)
        {
            // 删除堆区的每个职工对象
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArry[i];
                this->m_EmpArry[i] = NULL;
            }
            //删除堆区数组指针
            delete[] this->m_EmpArry;
            this->m_EmpArry = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "クリアに成功しました" << endl;

    }
    system("pause");
    system("cls");
}
WorkerManager::~WorkerManager()
{

}