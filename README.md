# Library-Management-System
一个用 C++ 编写的控制台图书管理系统，基于面向对象设计，使用标准模板库（STL）实现。
仅作为个人的c++练习，无持久化设计
代码结构：
DateUtil          日期工具类（静态方法）
    ├── now()              获取当前日期
    ├── addDays()          日期加天数
    └── daysBetween()      计算两天相差

Book              书籍类
    ├── 基本信息（id、书名、作者、ISBN）
    └── 库存（总数、可借数）

BorrowRecord      借阅记录类
    ├── 借阅信息（书号、用户名、借/还日期）
    └── 罚金

User              用户基类（抽象类）
    ├── Admin          管理员
    └── NormalUser     普通用户（含罚金余额）

LibrarySystem     系统核心类
    ├── 管理 books / users / records
    ├── 登录注册
    ├── 管理员功能
    └── 普通用户功能
