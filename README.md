# 従業員管理システム / Employee Management System
### プロジェクト概要

C++で実装された従業員管理システムです。オブジェクト指向プログラミング(OOP)の原則に基づいて設計され、従業員情報の完全な管理機能を提供します。

### 主な機能

- ✅ **従業員情報の追加** - 新しい従業員データを追加
- ✅ **従業員情報の表示** - 全従業員の情報を一覧表示
- ✅ **従業員の削除** - 退職した従業員のデータを削除
- ✅ **従業員情報の変更** - 既存の従業員情報を更新
- ✅ **従業員情報の検索** - 番号または名前で従業員を検索
- ✅ **並び替え機能** - 従業員番号で昇順/降順に並び替え
- ✅ **データの一括削除** - すべての従業員データをクリア
- ✅ **データ永続化** - ファイルへの自動保存

### システム構成

#### クラス階層

```
Worker (抽象基底クラス)
├── Employee (一般従業員)
├── Manager (マネージャー)
└── Boss (社長)
```

#### ファイル構成

```
employee-management-system/
├── main.cpp                 # メインプログラム
├── workerManager.h          # WorkerManagerクラス定義
├── workerManager.cpp        # WorkerManagerクラス実装
├── worker.h                 # Worker抽象クラス定義
├── employee.h               # Employeeクラス定義
├── employee.cpp             # Employeeクラス実装
├── manager.h                # Managerクラス定義
├── manager.cpp              # Managerクラス実装
├── boss.h                   # Bossクラス定義
├── boss.cpp                 # Bossクラス実装
└── empfilex.txt             # データ保存ファイル (自動生成)
```

### クイックスタート

#### 必要な環境

- C++コンパイラ (g++, clang++, MSVC など)
- C++11以上のサポート

#### コンパイル

```bash
# Linux/macOS
g++ main.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system

# Windows (MinGW)
g++ main.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system.exe
```

#### 実行

```bash
# Linux/macOS
./employee_system

# Windows
employee_system.exe
```

### 使用方法

プログラムを起動すると、以下のメニューが表示されます:

```
*****************************************
****** 従業員管理システムへようこそ *****
*****************************************
******** 0. 管理プログラムを終了 ********
******** 1. 従業員情報を追加 ************
******** 2. 従業員情報を表示 ************
******** 3. 退職した従業員を削除 ********
******** 4. 従業員情報を変更 ************
******** 5. 従業員情報を検索 ************
******** 6. 番号順に並べ替え ************
******** 7. すべてのデータを削除 ********
*****************************************
```

#### 操作例

**従業員の追加:**
1. メニューで「1」を選択
2. 追加する人数を入力
3. 各従業員の情報を入力:
   - 従業員番号
   - 従業員名
   - 職種 (1:一般従業員, 2:マネージャー, 3:社長)

**従業員の検索:**
1. メニューで「5」を選択
2. 検索方法を選択 (番号検索 or 名前検索)
3. 検索キーワードを入力

### クラス詳細

#### Worker (抽象基底クラス)

従業員の共通インターフェースを定義する抽象クラスです。

**メンバー変数:**
- `m_Id` (int) - 従業員番号
- `m_Name` (string) - 従業員名
- `m_DeptId` (int) - 部門番号

**純粋仮想関数:**
- `showInfo()` - 個人情報を表示
- `getDeptName()` - 職位名を取得

#### Employee (一般従業員)

**職務内容:** マネージャーから与えられた業務を遂行する

#### Manager (マネージャー)

**職務内容:** 上司から任された仕事を完了させ、従業員にタスクを割り当てる

#### Boss (社長)

**職務内容:** 会社のすべての業務を管理する

#### WorkerManager (管理クラス)

システムのコア機能を管理するクラスです。

**主要メソッド:**
- `Add_Emp()` - 従業員追加
- `Show_Emp()` - 従業員表示
- `Del_Emp()` - 従業員削除
- `Mod_Emp()` - 従業員情報変更
- `Find_Emp()` - 従業員検索
- `sort_Emp()` - 並び替え
- `Clean_File()` - 全データ削除
- `save()` - ファイル保存

### データ保存形式

従業員データは `empfilex.txt` に以下の形式で保存されます:

```
[従業員番号] [従業員名] [部門番号]
```

**部門番号の対応:**
- 1 = 一般従業員
- 2 = マネージャー
- 3 = 社長

### 技術的特徴

- **オブジェクト指向設計:** 継承とポリモーフィズムを活用
- **動的メモリ管理:** 動的配列による柔軟なデータ管理
- **ファイルI/O:** データの永続化をサポート
- **選択ソート:** 効率的なデータ並び替えアルゴリズム
- **エラーハンドリング:** ファイル存在確認とデータ検証

### 注意事項

- データファイル (`empfilex.txt`) は自動的に作成されます
- データ削除操作は取り消せないため、注意して実行してください
- 従業員番号は一意である必要があります
- プログラム終了時はメニューから「0」を選択してください

---

## English

### Project Overview

An employee management system implemented in C++. Designed based on Object-Oriented Programming (OOP) principles, providing comprehensive employee information management functionality.

### Key Features

- ✅ **Add Employee Information** - Add new employee data
- ✅ **Display Employee Information** - List all employee information
- ✅ **Delete Employee** - Remove resigned employee data
- ✅ **Modify Employee Information** - Update existing employee information
- ✅ **Search Employee Information** - Search employees by ID or name
- ✅ **Sort Functionality** - Sort by employee ID in ascending/descending order
- ✅ **Batch Delete Data** - Clear all employee data
- ✅ **Data Persistence** - Automatic saving to file

### System Architecture

#### Class Hierarchy

```
Worker (Abstract Base Class)
├── Employee (Regular Employee)
├── Manager (Manager)
└── Boss (CEO)
```

### Quick Start

#### Requirements

- C++ Compiler (g++, clang++, MSVC, etc.)
- C++11 or higher support

#### Compilation

```bash
# Linux/macOS
g++ main.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system

# Windows (MinGW)
g++ main.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system.exe
```

#### Execution

```bash
# Linux/macOS
./employee_system

# Windows
employee_system.exe
```

### Usage

When you start the program, the following menu will be displayed:

```
*****************************************
****** Welcome to Employee System ******
*****************************************
******** 0. Exit System *****************
******** 1. Add Employee ****************
******** 2. Display Employees ***********
******** 3. Delete Employee *************
******** 4. Modify Employee *************
******** 5. Search Employee *************
******** 6. Sort by ID ******************
******** 7. Clear All Data **************
*****************************************
```

### Technical Features

- **Object-Oriented Design:** Utilizing inheritance and polymorphism
- **Dynamic Memory Management:** Flexible data management with dynamic arrays
- **File I/O:** Data persistence support
- **Selection Sort:** Efficient data sorting algorithm
- **Error Handling:** File existence checking and data validation

---

## 中文

### 项目概述

使用 C++ 实现的员工管理系统。基于面向对象编程(OOP)原则设计,提供完整的员工信息管理功能。

### 主要功能

- ✅ **添加员工信息** - 添加新员工数据
- ✅ **显示员工信息** - 列出所有员工信息
- ✅ **删除员工** - 删除离职员工数据
- ✅ **修改员工信息** - 更新现有员工信息
- ✅ **搜索员工信息** - 按编号或姓名搜索员工
- ✅ **排序功能** - 按员工编号升序/降序排序
- ✅ **批量删除数据** - 清空所有员工数据
- ✅ **数据持久化** - 自动保存到文件

### 系统架构

#### 类层次结构

```
Worker (抽象基类)
├── Employee (普通员工)
├── Manager (经理)
└── Boss (老板)
```

### 快速开始

#### 环境要求

- C++ 编译器 (g++, clang++, MSVC 等)
- 支持 C++11 或更高版本

#### 编译

```bash
# Linux/macOS
g++ main.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system

# Windows (MinGW)
g++ main.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system.exe
```

#### 运行

```bash
# Linux/macOS
./employee_system

# Windows
employee_system.exe
```

### 使用方法

启动程序后将显示以下菜单:

```
*****************************************
****** 欢迎使用员工管理系统 *************
*****************************************
******** 0. 退出管理程序 ****************
******** 1. 添加员工信息 ****************
******** 2. 显示员工信息 ****************
******** 3. 删除离职员工 ****************
******** 4. 修改员工信息 ****************
******** 5. 搜索员工信息 ****************
******** 6. 按编号排序 ******************
******** 7. 清空所有数据 ****************
*****************************************
```

### 数据保存格式

员工数据保存在 `empfilex.txt` 文件中,格式如下:

```
[员工编号] [员工姓名] [部门编号]
```

**部门编号对应:**
- 1 = 普通员工
- 2 = 经理
- 3 = 老板

### 技术特点

- **面向对象设计:** 利用继承和多态
- **动态内存管理:** 使用动态数组进行灵活的数据管理
- **文件 I/O:** 支持数据持久化
- **选择排序:** 高效的数据排序算法
- **错误处理:** 文件存在检查和数据验证

### 注意事项

- 数据文件 (`empfilex.txt`) 会自动创建
- 数据删除操作不可撤销,请谨慎执行
- 员工编号必须唯一
- 退出程序时请从菜单选择 "0"

---

## License

MIT License

## Contributing

欢迎提交问题和拉取请求！ / Issues and pull requests are welcome!

## Contact

如有问题或建议,请通过 GitHub Issues 联系。

---

**开发语言 / Language:** C++  
**文字编码 / Encoding:** UTF-8
