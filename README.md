従業員管理システム (Employee Management System)
プロジェクト概要 (Project Overview)
C++で実装された従業員管理システムです。従業員情報の追加、表示、削除、変更、検索、並び替え、データの一括削除などの機能を提供します。
A comprehensive employee management system implemented in C++ that provides features for adding, displaying, deleting, modifying, searching, sorting, and batch clearing employee information.
主な機能 (Main Features)

従業員情報の追加 - 新しい従業員データを追加
従業員情報の表示 - 全従業員の情報を一覧表示
従業員の削除 - 退職した従業員のデータを削除
従業員情報の変更 - 既存の従業員情報を更新
従業員情報の検索 - 番号または名前で従業員を検索
並び替え - 従業員番号で昇順/降順に並び替え
データの一括削除 - すべての従業員データをクリア

システム構成 (System Architecture)
クラス階層 (Class Hierarchy)
Worker (抽象基底クラス)
├── Employee (一般従業員)
├── Manager (マネージャー)
└── Boss (社長)
ファイル構成 (File Structure)
├── main.cpp                # メインプログラム
├── workerManager.h         # WorkerManagerクラスのヘッダーファイル
├── workerManager.cpp       # WorkerManagerクラスの実装
├── worker.h                # Workerクラスのヘッダーファイル
├── employee.h              # Employeeクラスのヘッダーファイル
├── employee.cpp            # Employeeクラスの実装
├── manager.h               # Managerクラスのヘッダーファイル
├── manager.cpp             # Managerクラスの実装
├── boss.h                  # Bossクラスのヘッダーファイル
├── boss.cpp                # Bossクラスの実装
└── empfilex.txt            # データ保存ファイル
クラス説明 (Class Description)
Worker (抽象基底クラス)
従業員の共通インターフェースを定義する抽象クラスです。
メンバー変数:

m_Id - 従業員番号
m_Name - 従業員名
m_DeptId - 部門番号

純粋仮想関数:

showInfo() - 個人情報を表示
getDeptName() - 職位名を取得

Employee (一般従業員)
Workerクラスを継承し、一般従業員を表すクラスです。
職務内容: マネージャーから与えられた業務を遂行する
Manager (マネージャー)
Workerクラスを継承し、マネージャーを表すクラスです。
職務内容: 上司から任された仕事を完了させ、従業員にタスクを割り当てる
Boss (社長)
Workerクラスを継承し、社長を表すクラスです。
職務内容: 会社のすべての業務を管理する
WorkerManager (管理クラス)
システムのコア機能を管理するクラスです。
主要メソッド:

show_Menu() - メニューを表示
Add_Emp() - 従業員を追加
Show_Emp() - 全従業員を表示
Del_Emp() - 従業員を削除
Mod_Emp() - 従業員情報を変更
Find_Emp() - 従業員を検索
sort_Emp() - 従業員を並び替え
Clean_File() - 全データを削除
save() - データをファイルに保存
IsExist(int id) - 従業員の存在確認

コンパイルと実行 (Compilation and Execution)
コンパイル方法 (Compilation)
bashg++ main.cpp workerManager.cpp employee.cpp manager.cpp boss.cpp -o employee_system
実行方法 (Execution)
bash./employee_system
```

## 使用方法 (Usage)

1. プログラムを起動すると、メニューが表示されます
2. 0-7の番号を入力して、実行したい操作を選択します
3. 画面の指示に従って、必要な情報を入力します

### メニュー選択 (Menu Options)
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

## データ保存形式 (Data Storage Format)

従業員データは `empfilex.txt` に以下の形式で保存されます:
```
[従業員番号] [従業員名] [部門番号]
部門番号:

1: 一般従業員
2: マネージャー
3: 社長

技術的特徴 (Technical Features)

オブジェクト指向設計: 継承とポリモーフィズムを活用
動的メモリ管理: 動的配列による柔軟なデータ管理
ファイルI/O: データの永続化をサポート
選択ソート: 効率的なデータ並び替え
エラーハンドリング: ファイル存在確認とデータ検証

注意事項 (Notes)

データファイル (empfilex.txt) は自動的に作成されます
データ削除操作は取り消せないため、注意して実行してください
従業員番号は一意である必要があります
プログラム終了時はメニューから「0」を選択してください

今後の改善案 (Future Improvements)

データベース連携機能の追加
GUI インターフェースの実装
より詳細な検索フィルター機能
データのエクスポート/インポート機能
パスワード保護機能
