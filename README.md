# Employee Management System

## Language

- [日本語](#日本語)
- [English](#english)

---

## 日本語

### 概要

このプロジェクトは、C++で作成したコンソール形式の従業員管理システムです。

C++のクラス、継承、ポリモーフィズム、動的メモリ管理、ファイル入出力を練習するために作成しました。  
従業員情報の追加、表示、削除、変更、検索、並び替え、ファイル保存を行うことができます。

---

### 実装した機能

- メニュー画面の表示
- 従業員情報の追加
- 従業員情報の表示
- 従業員情報の削除
- 従業員情報の変更
- 従業員番号による検索
- 従業員名による検索
- 従業員番号による昇順・降順ソート
- すべての従業員データの削除
- 従業員データを `empfilex.txt` に保存
- プログラム起動時にファイルから従業員データを読み込み

---

### 管理できる職種

このシステムでは、以下の3種類の職種を管理できます。

| 職種番号 | 職種 |
|---|---|
| 1 | 一般従業員 |
| 2 | マネージャー |
| 3 | 社長 |

それぞれの職種は、`Worker` 抽象クラスを継承して作成しています。

---

### プログラムの流れ

```text
メニュー表示
    ↓
ユーザーが操作を選択
    ↓
従業員情報の追加・表示・削除・変更・検索・並び替え
    ↓
変更内容をファイルに保存
    ↓
次回起動時にファイルからデータを読み込み
```

---

### プロジェクト構成

```text
Employee_Management_System/
│
├── Employee Management System.cpp
├── worker.h
├── workerManager.h
├── workerManager.cpp
├── employee.h
├── employee.cpp
├── manager.h
├── manager.cpp
├── boss.h
├── boss.cpp
├── empfiex.txt
└── README.md
```

---

### ファイル説明

| ファイル名 | 説明 |
|---|---|
| `Employee Management System.cpp` | メイン関数。メニュー選択と全体の流れを管理 |
| `worker.h` | 従業員の抽象基底クラス `Worker` を定義 |
| `workerManager.h` | `WorkerManager` クラスの宣言 |
| `workerManager.cpp` | 従業員管理機能の実装 |
| `employee.h / employee.cpp` | 一般従業員クラスの定義と実装 |
| `manager.h / manager.cpp` | マネージャークラスの定義と実装 |
| `boss.h / boss.cpp` | 社長クラスの定義と実装 |
| `empfilex.txt` | 従業員データを保存するファイル |

---

### クラス構成

```text
Worker
│
├── Employee
├── Manager
└── Boss
```

`Worker` は抽象クラスで、以下の純粋仮想関数を持っています。

```cpp
virtual void showInfo() = 0;
virtual string getDeptName() = 0;
```

`Employee`、`Manager`、`Boss` はそれぞれ `Worker` クラスを継承し、職種ごとの情報表示を実装しています。

---

### 使用した主な技術

- C++
- クラスとオブジェクト
- 継承
- ポリモーフィズム
- 純粋仮想関数
- 動的メモリ管理
- ポインタ配列
- ファイル入出力
- テキストファイル保存
- コンソールアプリケーション

---

### 実行環境

このプログラムは、主にWindows環境での実行を想定しています。

プログラム内で以下のようなWindows向けコマンドを使用しています。

```cpp
system("pause");
system("cls");
```

---

### コンパイル例

```bash
g++ "Employee Management System.cpp" workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system -std=c++11
```

実行：

```bash
./employee_system
```

Windowsの場合：

```bash
employee_system.exe
```

---

### 学習目的

このプロジェクトでは、C++を使って簡単な従業員管理システムを作成し、以下の内容を練習しました。

- クラスを使った設計
- 継承とポリモーフィズム
- 抽象クラスの使い方
- 動的メモリの確保と解放
- ファイルへの保存と読み込み
- コンソールメニューによる操作

---

## English

### Overview

This project is a simple console-based employee management system written in C++.

It was created as a self-practice project to learn C++ classes, inheritance, polymorphism, dynamic memory management, and file input/output.  
The system can add, display, delete, modify, search, sort, and save employee information.

---

### Features

- Display menu interface
- Add employee information
- Show employee information
- Delete employee information
- Modify employee information
- Search employee by ID
- Search employee by name
- Sort employees by ID in ascending or descending order
- Clear all employee data
- Save employee data to `empfilex.txt`
- Load employee data from file when the program starts

---

### Employee Types

This system manages three types of employees.

| Type ID | Position |
|---|---|
| 1 | Employee |
| 2 | Manager |
| 3 | Boss |

Each employee type is implemented by inheriting from the abstract `Worker` class.

---

### Program Flow

```text
Show menu
    ↓
User selects an operation
    ↓
Add / show / delete / modify / search / sort employee data
    ↓
Save changes to file
    ↓
Load data from file when the program starts next time
```

---

### Project Structure

```text
Employee_Management_System/
│
├── Employee Management System.cpp
├── worker.h
├── workerManager.h
├── workerManager.cpp
├── employee.h
├── employee.cpp
├── manager.h
├── manager.cpp
├── boss.h
├── boss.cpp
├── empfiex.txt
└── README.md
```

---

### File Description

| File | Description |
|---|---|
| `Employee Management System.cpp` | Main function and menu control |
| `worker.h` | Defines the abstract base class `Worker` |
| `workerManager.h` | Declaration of the `WorkerManager` class |
| `workerManager.cpp` | Implementation of employee management functions |
| `employee.h / employee.cpp` | Definition and implementation of the `Employee` class |
| `manager.h / manager.cpp` | Definition and implementation of the `Manager` class |
| `boss.h / boss.cpp` | Definition and implementation of the `Boss` class |
| `empfilex.txt` | File used to save employee data |

---

### Class Structure

```text
Worker
│
├── Employee
├── Manager
└── Boss
```

`Worker` is an abstract class with the following pure virtual functions.

```cpp
virtual void showInfo() = 0;
virtual string getDeptName() = 0;
```

`Employee`, `Manager`, and `Boss` inherit from `Worker` and implement their own information display functions.

---

### Main Technologies Used

- C++
- Class and object
- Inheritance
- Polymorphism
- Pure virtual functions
- Dynamic memory management
- Pointer array
- File input/output
- Text file saving
- Console application

---

### Environment

This program is mainly designed for Windows console environments.

It uses Windows-specific commands such as:

```cpp
system("pause");
system("cls");
```

---

### Build Example

```bash
g++ "Employee Management System.cpp" workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system -std=c++11
```

Run:

```bash
./employee_system
```

On Windows:

```bash
employee_system.exe
```

---

### Purpose

The purpose of this project is to practice basic C++ programming through a small employee management system.

Through this project, I practiced:

- Class-based program design
- Inheritance and polymorphism
- Abstract classes
- Dynamic memory allocation and release
- File saving and loading
- Console menu interaction
