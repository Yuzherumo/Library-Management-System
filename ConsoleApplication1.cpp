#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

// ==================== 日期工具 ====================
class DateUtil
{
public:
	static string now()
	{
		time_t a = time(nullptr);
		tm* local = localtime(&a);
		char b[100];
		strftime(b, sizeof(b), "%Y-%m-%d", local);
		return b;
	}
	static string addDays(const string& date, int days)
	{
		int year = 0;
		int month = 0;
		int day = 0;
		int i = 0;
		for (char ch : date)
		{
			if (ch == '-')
			{
				i++;
			}
			else
			{
				int d = ch - '0';
				if (i == 0)
				{
					year = year * 10 + d;
				}
				else if (i == 1)
				{
					month = month * 10 + d;
				}
				else
				{
					day = day * 10 + d;
				}
			}
		}
		day = day + days;
		string y, m, d;
		while (true)
		{
			if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
			{
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if (day > 31)
					{
						month++;
						day = day - 31;
					}
					if (month >= 13)
					{
						year++;
						month = 1;
					}
				}
				else if (month == 2)
				{
					if (day > 29)
					{
						month++;
						day = day - 29;
					}
				}
				else
				{
					if (day > 30)
					{
						month++;
						day = day - 30;
					}
				}
			}
			else
			{
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if (day > 31)
					{
						month++;
						day = day - 31;
					}
					if (month == 13)
					{
						year++;
						month = 1;
					}
				}
				else if (month == 2)
				{
					if (day > 28)
					{
						month++;
						day = day - 28;
					}
				}
				else
				{
					if (day > 30)
					{
						month++;
						day = day - 30;
					}
				}
			}
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if (day <= 31)
				{
					break;
				}
			}
			else if (month == 2)
			{
				if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
				{
					if (day <= 29)
					{
						break;
					}
				}
				else
				{
					if (day <= 28)
					{
						break;
					}
				}
			}
			else
			{
				if (day <= 30)
				{
					break;
				}
			}
		}
		y = to_string(year);
		m = to_string(month);
		d = to_string(day);
		return y + '-' + m + '-' + d;
	}
	static int daysBetween(const string& date1, const string& date2)
	{
		int y1 = 0;
		int y2 = 0;
		int m1 = 0;
		int m2 = 0;
		int d1 = 0;
		int d2 = 0;
		int i = 0;
		for (char ch : date1)
		{
			if (ch == '-')
			{
				i++;
			}
			else
			{
				int d = ch - '0';
				if (i == 0)
				{
					y1 = y1 * 10 + d;
				}
				else if (i == 1)
				{
					m1 = m1 * 10 + d;
				}
				else
				{
					d1 = d1 * 10 + d;
				}
			}
		}
		i = 0;
		for (char ch : date2)
		{
			if (ch == '-')
			{
				i++;
			}
			else
			{
				int d = ch - '0';
				if (i == 0)
				{
					y2 = y2 * 10 + d;
				}
				else if (i == 1)
				{
					m2 = m2 * 10 + d;
				}
				else
				{
					d2 = d2 * 10 + d;
				}
			}
		}
		int zts1 = 0, zts2 = 0;
		for (i = 2000;i < y1;i++)
		{
			if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
			{
				zts1 += 366;
			}
			else
			{
				zts1 += 365;
			}
		}
		for (i = 2000;i < y2;i++)
		{
			if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
			{
				zts2 += 366;
			}
			else
			{
				zts2 += 365;
			}
		}
		if (m1 == 1)
		{
			zts1 += d1;
		}
		else
		{
			for (i = 1;i < m1;i++)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				{
					zts1 += 31;
				}
				else if (i == 2)
				{
					if (y1 % 400 == 0 || (y1 % 4 == 0 && y1 % 100 != 0))
					{
						zts1 += 29;
					}
					else
					{
						zts1 += 28;
					}
				}
				else
				{
					zts1 += 30;
				}
			}
			zts1 += d1;
		}
		if (m2 == 1)
		{
			zts2 += d2;
		}
		else
		{
			for (i = 1;i < m2;i++)
			{
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
				{
					zts2 += 31;
				}
				else if (i == 2)
				{
					if (y2 % 400 == 0 || (y2 % 4 == 0 && y2 % 100 != 0))
					{
						zts2 += 29;
					}
					else
					{
						zts2 += 28;
					}
				}
				else
				{
					zts2 += 30;
				}
			}
			zts2 += d2;
		}
		return abs(zts1 - zts2);
	}
};

// ==================== 书籍类 ====================
class Book
{
private:
	int id;
	string title;
	string author;
	string isbn;
	int totalCount;
	int availableCount;

public:
	Book()
	{
		id = 0;
		title = "默认未命名";
		author = "默认未命名";
		isbn = "000000000000";
		totalCount = 0;
		availableCount = 0;
	}
	Book(int id, const string& title, const string& author, const string& isbn, int count) :
		id(id), title(title), author(author), isbn(isbn), totalCount(count), availableCount(count) {
	}
	// getter / setter
	int getId() const { return id; }
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	string getIsbn() const { return isbn; }
	int getTotalCount() const { return totalCount; }
	int getAvailableCount() const { return availableCount; }

	void setTitle(const string& t) { title = t; }
	void setAuthor(const string& a) { author = a; }
	void setIsbn(const string& i) { isbn = i; }
	void setTotalCount(int c)
	{
		int borrowed = totalCount - availableCount;
		totalCount = c;
		availableCount = c - borrowed;
	}

	bool borrowOne()
	{
		if (availableCount > 0)
		{
			availableCount--;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool returnOne()
	{
		if (availableCount < totalCount)
		{
			availableCount++;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isAvailable() const
	{
		if (availableCount > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void display() const
	{
		cout << "编号：" << id << "|" << "书名：" << title << "|" << "作者：" << author << "|" << "国际标准书号:" << isbn << "|"
			<< "总库存：" << totalCount << "|" << "可借数量：" << availableCount << endl;
	}
};

// ==================== 借阅记录 ====================
class BorrowRecord
{
private:
	int bookId;
	string username;
	string borrowDate;
	string dueDate;
	bool returned;
	double fine;
	string returnDate;

public:
	BorrowRecord() :bookId(0), username("默认用户名"), borrowDate("2000-1-1"), dueDate("2000-1-1"), returned(false), fine(0) {}
	BorrowRecord(int bookId, const string& username, const string& borrowDate, const string& dueDate) :
		bookId(bookId), username(username), borrowDate(borrowDate), dueDate(dueDate), returned(false), fine(0) {
	}

	int getBookId() const { return bookId; }
	string getUsername() const { return username; }
	string getBorrowDate() const { return borrowDate; }
	string getDueDate() const { return dueDate; }
	bool isReturned() const { return returned; }
	double getFine() const { return fine; }

	void setReturned(bool r, const string& date = "")
	{
		returned = r;
		if (r) returnDate = date;
	}

	void setFine(double f) { fine = f; }
	void setDueDate(const string& d) { dueDate = d; }
	void display() const
	{
		cout << "编号：" << bookId << "|" << "用户名：" << username << "|" << "借阅日期：" << borrowDate << "|" << "预计归还日期:" << dueDate << "|";
		if (returned) { cout << "已归还"; }
		else { cout << "未归还"; }
		cout << "|" << "逾期罚金：" << fine << endl;
	}
};

// ==================== 用户基类 ====================
class User
{
protected:
	string username;
	string password;
	string realName;
	int phone;
	string email;

public:
	User() :username("默认用户名"), password("123456"), realName("佚名"), phone(0), email("111@11.com") {}
	User(const string& username, const string& password, const string& realName, const int& phone, const string& email) :
		username(username), password(password), realName(realName), phone(phone), email(email) {
	}
	virtual ~User() {}//

	string getUsername() const { return username; }
	string getPassword() const { return password; }
	string getRealName() const { return realName; }
	int getPhone() const { return phone; }
	string getEmail() const { return email; }

	void setPassword(const string& p) { password = p; }
	void setRealName(const string& n) { realName = n; }
	void setPhone(const int& p) { phone = p; }
	void setEmail(const string& e) { email = e; }

	bool checkPassword(const string& p) const
	{
		if (password == p)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	virtual bool isAdmin() const = 0;
	virtual void displayInfo() const = 0;
};

// ==================== 管理员 ====================
class Admin : public User
{
public:
	Admin() :User() {}
	Admin(const string& u, const string& p, const string& r, const int& ph, const string& e) :
		User(u, p, r, ph, e) {
	}

	bool isAdmin() const override { return true; }

	void displayInfo() const override
	{
		cout << "管理员" << endl << "用户名：" << username << endl << "姓名：" << realName << endl << "电话：" << phone << endl
			<< "邮箱：" << email << endl;
	}
};

// ==================== 普通用户 ====================
class NormalUser : public User
{
private:
	double balance;

public:
	NormalUser() :User(), balance(0.0) {}
	NormalUser(const string& u, const string& p, const string& r, const int& ph, const string& e, const double& d) :
		User(u, p, r, ph, e), balance(d) {
	}

	bool isAdmin() const override { return false; }
	void displayInfo() const override
	{
		cout << "普通用户" << endl << "用户名：" << username << endl << "姓名：" << realName << endl << "电话：" << phone << endl
			<< "邮箱：" << email << endl << "欠款余额：" << balance << "元" << endl;
	}

	double getBalance() const { return balance; }
	void setBalance(double b) { balance = b; }
	void addFine(double f) { balance += f; }
	void payFine(double amount) { balance -= amount; }
};

// ==================== 图书管理系统核心类 ====================
class LibrarySystem
{
private:
	vector<Book> books;
	vector<User*> users;
	vector<BorrowRecord> records;
	int nextBookId;
	User* currentUser = nullptr;

	// ---------- 内部工具 ----------
	int findBookIndexById(int id) const
	{
		for (size_t i = 0;i < books.size();++i)
		{
			if (books[i].getId() == id)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}
	int findUserIndexByName(const string& name) const
	{
		for (size_t i = 0;i < users.size();++i)
		{
			if (users[i]->getUsername() == name)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}
	int generateBookId() { return nextBookId++; }
	void printBookHeader() const
	{
		cout << "编号\t书名\t\t作者\t\tISBN\t\t总/可借\n" << endl;
	}
	int getIntInput()
	{
		int x;
		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入无效，请重新输入: ";
		}
		cin.ignore(10000, '\n');
		return x;
	}
	bool hasActiveRecord(int bookId) const
	{
		for (const auto& r : records)
		{
			if (r.getBookId() == bookId && !r.isReturned())
			{
				return true;
			}
		}
		return false;
	}

public:
	LibrarySystem() :nextBookId(1), currentUser(nullptr) {}
	LibrarySystem(const LibrarySystem&) = delete;
	LibrarySystem& operator=(const LibrarySystem&) = delete;
	~LibrarySystem()
	{
		for (User* u : users)
		{
			delete u;
		}
		users.clear();
	}

	// ---------- 初始化 / 登录 ----------
	void initDefaultData()
	{
		users.push_back(new Admin("admin", "admin123", "系统管理员", 13800138000, "admin@111.com"));
		books.push_back(Book(generateBookId(), "C++ Primer", "Stanley B. Lippman", "9780321714114", 5));
		books.push_back(Book(generateBookId(), "Effective C++", "Scott Meyers", "9780321334879", 3));
		books.push_back(Book(generateBookId(), "The C Programming Language", "Brian W. Kernighan", "9780131103627", 4));
	}
	bool login(const string& username, const string& password)
	{
		for (User* u : users)
		{
			if (u->getUsername() == username && u->checkPassword(password))
			{
				currentUser = u;
				return true;
			}
		}
		return false;
	}
	void logout()
	{
		currentUser = nullptr;
	}
	bool registerUser(const string& username, const string& password)
	{
		if (findUserIndexByName(username) != -1)
		{
			return false;
		}
		if (username.empty() || password.empty())
		{
			return false;
		}
		users.push_back(new NormalUser(username, password, "佚名", 0, "111@11.com", 0.0));
		return true;
	}
	User* getCurrentUser() const
	{
		return currentUser;
	}

	// ---------- 通用功能 ----------
	void changePassword()
	{
		string newPwd, confirm;
		cout << "新密码: ";
		cin >> newPwd;
		cout << "确认新密码: ";
		cin >> confirm;
		if (newPwd != confirm)
		{
			cout << "两次输入不一致" << endl;
			return;
		}
		currentUser->setPassword(newPwd);
		cout << "密码修改成功。" << endl;
	}
	void showAllBooks() const
	{
		printBookHeader();
		for (const auto& b : books)
		{
			b.display();
		}
	}
	void searchBooks() const
	{
		cout << "1. 按书名  2. 按作者  3. 按ISBN" << endl << "请选择: ";
		int mode;
		cin >> mode;
		string key;
		cout << "关键字: ";
		cin >> key;
		bool found = false;
		for (const auto& b : books)
		{
			bool match = false;
			if (mode == 1)
			{
				match = (b.getTitle().find(key) != string::npos);
			}
			else if (mode == 2)
			{
				match = (b.getAuthor().find(key) != string::npos);
			}
			else if (mode == 3)
			{
				match = (b.getIsbn().find(key) != string::npos);
			}
			if (match)
			{
				b.display();
				found = true;
			}
		}
		if (!found)
		{
			cout << "未找到匹配书籍。" << endl;
		}
	}

	// ---------- 管理员功能 ----------
	void addBook()
	{
		string title, author, isbn;
		int count;
		cout << "书名: ";
		cin >> title;
		cout << "作者: ";
		cin >> author;
		cout << "ISBN: ";
		cin >> isbn;
		cout << "库存: ";
		count = getIntInput();
		if (count < 0)
		{
			cout << "库存不能为负" << endl;
			return;
		}
		books.push_back(Book(generateBookId(), title, author, isbn, count));
		cout << "添加成功，编号 " << books.back().getId() << endl;
	}
	void deleteBook()
	{
		cout << "输入要删除的书籍编号: ";
		int id = getIntInput();
		int idx = findBookIndexById(id);
		if (idx == -1)
		{
			cout << "未找到该书籍。" << endl;
			return;
		}
		if (hasActiveRecord(id))
		{
			cout << "该书还有未归还的借阅记录，无法删除。" << endl;
			return;
		}
		books.erase(books.begin() + idx);
		cout << "删除成功。" << endl;
	}
	void modifyBook()
	{
		cout << "输入要修改的书籍编号: ";
		int id = getIntInput();
		int idx = findBookIndexById(id);
		if (idx == -1)
		{
			cout << "未找到该书籍。" << endl;
			return;
		}
		Book& b = books[idx];
		string s;
		int n;
		cout << "新书名（回车跳过）: ";
		cin.ignore(10000, '\n');
		getline(cin, s);
		if (!s.empty())
		{
			b.setTitle(s);
		}
		cout << "新作者（回车跳过）: ";
		getline(cin, s);
		if (!s.empty())
		{
			b.setAuthor(s);
		}
		cout << "新ISBN（回车跳过）: ";
		getline(cin, s);
		if (!s.empty())
		{
			b.setIsbn(s);
		}
		cout << "新总库存（-1跳过）: ";
		n = getIntInput();
		if (n >= 0)
		{
			int borrowed = b.getTotalCount() - b.getAvailableCount();
			if (n < borrowed)
			{
				cout << "新库存不能小于已借出数量（" << borrowed << "）。" << endl;
			}
			else {
				b.setTotalCount(n);
			}
		}
		cout << "修改完成。" << endl;
	}
	void listAllUsers() const
	{
		if (users.empty())
		{
			cout << "暂无用户。" << endl;
			return;
		}
		for (const auto* u : users)
		{
			u->displayInfo();
			cout << "-----" << endl;
		}
	}
	void deleteUser()
	{
		cout << "输入要删除的用户名: ";
		string name; cin >> name;

		int idx = findUserIndexByName(name);
		if (idx == -1)
		{
			cout << "未找到该用户。" << endl;
			return;
		}
		if (users[idx] == currentUser)
		{
			cout << "不能删除当前登录的自己。" << endl;
			return;
		}
		if (users[idx]->isAdmin())
		{
			cout << "不能删除管理员账号。" << endl;
			return;
		}
		for (auto& r : records)
		{
			if (r.getUsername() == name && !r.isReturned())
			{
				int bi = findBookIndexById(r.getBookId());
				if (bi != -1)
				{
					books[bi].returnOne();
				}
				r.setReturned(true, DateUtil::now());
			}
		}
		delete users[idx];
		users.erase(users.begin() + idx);
		cout << "用户已删除，其未归还记录已自动归还。" << endl;
	}
	void listAllRecords() const
	{
		if (records.empty())
		{
			cout << "暂无借阅记录。" << endl;
			return;
		}
		for (const auto& r : records)
		{
			r.display();
		}
	}

	// ---------- 普通用户功能 ----------
	void borrowBook()
	{
		if (!currentUser)
		{
			return;
		}
		NormalUser* nu = dynamic_cast<NormalUser*>(currentUser);
		if (nu && nu->getBalance() > 0)
		{
			cout << "您有欠款未缴清，请先缴纳罚金。" << endl;
			return;
		}
		cout << "输入要借阅的书籍编号: ";
		int id = getIntInput();
		int idx = findBookIndexById(id);
		if (idx == -1)
		{
			cout << "未找到该书籍。" << endl;
			return;
		}
		if (!books[idx].borrowOne())
		{
			cout << "该书暂无可借副本。" << endl;
			return;
		}
		string today = DateUtil::now();
		string due = DateUtil::addDays(today, 30);
		records.push_back(BorrowRecord(id, currentUser->getUsername(), today, due));
		cout << "借阅成功，应还日期 " << due << "。" << endl;
	}
	void returnBook()
	{
		if (!currentUser)
		{
			return;
		}
		cout << "输入要归还的书籍编号: ";
		int id = getIntInput();
		int ri = -1;
		for (size_t i = 0; i < records.size(); ++i)
		{
			if (records[i].getBookId() == id && records[i].getUsername() == currentUser->getUsername() && !records[i].isReturned())
			{
				ri = static_cast<int>(i);
				break;
			}
		}
		if (ri == -1)
		{
			cout << "未找到对应的借阅记录。" << endl;
			return;
		}
		int bi = findBookIndexById(id);
		if (bi != -1)
		{
			books[bi].returnOne();
		}
		string today = DateUtil::now();
		records[ri].setReturned(true, today);
		string due = records[ri].getDueDate();
		int overdue = DateUtil::daysBetween(due, today);
		if (today > due)
		{
			double fine = overdue * 0.5;
			records[ri].setFine(fine);
			NormalUser* nu = dynamic_cast<NormalUser*>(currentUser);
			if (nu) nu->addFine(fine);
			cout << "归还成功，逾期 " << overdue << " 天，罚金 " << fine << " 元。" << endl;
		}
		else
		{
			cout << "归还成功，未逾期。" << endl;
		}
	}
	void renewBook()
	{
		if (!currentUser)
		{
			return;
		}
		cout << "输入要续借的书籍编号: ";
		int id = getIntInput();
		int ri = -1;
		for (size_t i = 0; i < records.size(); ++i)
		{
			if (records[i].getBookId() == id && records[i].getUsername() == currentUser->getUsername() && !records[i].isReturned())
			{
				ri = static_cast<int>(i);
				break;
			}
		}
		if (ri == -1)
		{
			cout << "未找到对应的借阅记录。" << endl;
			return;
		}
		string today = DateUtil::now();
		string due = records[ri].getDueDate();
		if (today > due)
		{
			cout << "该书已逾期，不能续借，请先归还。" << endl;
			return;
		}

		string newDue = DateUtil::addDays(due, 30);
		records[ri].setDueDate(newDue);
		cout << "续借成功，新应还日期 " << newDue << "。" << endl;
	}
	void showMyRecords() const
	{
		if (!currentUser)
		{
			return;
		}
		bool found = false;
		for (const auto& r : records)
		{
			if (r.getUsername() == currentUser->getUsername())
			{
				r.display();
				found = true;
			}
		}
		if (!found) cout << "您暂无借阅记录。" << endl;
	}
	void editMyInfo()
	{
		if (!currentUser)
		{
			return;
		}
		string s;
		cout << "新姓名（回车跳过）: ";
		cin.ignore(10000, '\n');
		getline(cin, s);
		if (!s.empty())
		{
			currentUser->setRealName(s);
		}
		cout << "新电话（-1跳过）: ";
		int ph = getIntInput();
		if (ph >= 0)
		{
			currentUser->setPhone(ph);
		}
		cout << "新邮箱（回车跳过）: ";
		getline(cin, s);
		if (!s.empty())
		{
			currentUser->setEmail(s);
		}
		cout << "信息已更新。\n";
	}
	void payMyFine()
	{
		NormalUser* nu = dynamic_cast<NormalUser*>(currentUser);
		if (!nu)
		{
			cout << "管理员无需缴纳罚金。" << endl;
			return;
		}
		cout << "当前欠款: " << nu->getBalance() << " 元" << endl;
		if (nu->getBalance() <= 0)
		{
			cout << "无欠款。" << endl;
			return;
		}
		cout << "缴纳金额: ";
		double amount;
		cin >> amount;
		if (amount <= 0)
		{
			cout << "金额无效。" << endl;
			return;
		}
		nu->payFine(amount);
		cout << "缴纳成功，剩余欠款: " << nu->getBalance() << " 元" << endl;
	}
	void cancelMyAccount()
	{
		if (!currentUser)
		{
			return;
		}
		if (currentUser->isAdmin())
		{
			cout << "管理员不能注销。" << endl;
			return;
		}
		cout << "确认注销？(y/n): ";
		char c;
		cin >> c;
		if (c != 'y' && c != 'Y')
		{
			return;
		}
		string name = currentUser->getUsername();
		for (auto& r : records)
		{
			if (r.getUsername() == name && !r.isReturned())
			{
				int bi = findBookIndexById(r.getBookId());
				if (bi != -1)
				{
					books[bi].returnOne();
				}
				r.setReturned(true, DateUtil::now());
			}
		}

		int idx = findUserIndexByName(name);
		if (idx != -1)
		{
			User* toDelete = users[idx];
			currentUser = nullptr;
			users.erase(users.begin() + idx);
			delete toDelete;
		}
		cout << "账户已注销。\n";
	}
	// ---------- 菜单 ----------
	void adminMenu();                   
	void userMenu();                    
};

void LibrarySystem::adminMenu()
{

	while (true)
	{
		cout << "\n----- 管理员菜单 -----\n";
		cout << "1. 查看所有书籍\n";
		cout << "2. 搜索书籍\n";
		cout << "3. 添加书籍\n";
		cout << "4. 删除书籍\n";
		cout << "5. 修改书籍信息\n";
		cout << "6. 查看所有用户\n";
		cout << "7. 删除用户\n";
		cout << "8. 查看所有借阅记录\n";
		cout << "9. 修改密码\n";
		cout << "0. 退出登录\n";
		cout << "请选择: ";

		int c = getIntInput();
		switch (c)
		{
		case 1: showAllBooks();  break;
		case 2: searchBooks();   break;
		case 3: addBook();       break;
		case 4: deleteBook();    break;
		case 5: modifyBook();    break;
		case 6: listAllUsers();  break;
		case 7: deleteUser();    break;
		case 8: listAllRecords();break;
		case 9: changePassword();break;
		case 0: return;
		default: cout << "无效选择。\n";
		}
	}
}

void LibrarySystem::userMenu() {
	while (true)
	{
		cout << "\n----- 用户菜单 -----\n";
		cout << "1. 查看所有书籍\n";
		cout << "2. 搜索书籍\n";
		cout << "3. 借阅书籍\n";
		cout << "4. 归还书籍\n";
		cout << "5. 续借书籍\n";
		cout << "6. 我的借阅记录\n";
		cout << "7. 修改个人信息\n";
		cout << "8. 缴纳罚金\n";
		cout << "9. 修改密码\n";
		cout << "10. 注销账户\n";
		cout << "0. 退出登录\n";
		cout << "请选择: ";

		int c = getIntInput();
		switch (c)
		{
		case 1:  showAllBooks();   break;
		case 2:  searchBooks();    break;
		case 3:  borrowBook();     break;
		case 4:  returnBook();     break;
		case 5:  renewBook();      break;
		case 6:  showMyRecords();  break;
		case 7:  editMyInfo();     break;
		case 8:  payMyFine();      break;
		case 9:  changePassword(); break;
		case 10: cancelMyAccount();return;   
		case 0:  return;
		default: cout << "无效选择。\n";
		}
	}
}

int main()
{
	LibrarySystem sys;
	sys.initDefaultData();             

	while (true)
	{
		cout << "\n========= 图书管理系统 =========\n";
		cout << "1. 登录\n";
		cout << "2. 注册新用户\n";
		cout << "0. 退出系统\n";
		cout << "请选择: ";

		int choice;
		if (!(cin >> choice))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "输入无效，请重新选择。\n";
			continue;
		}

		if (choice == 0)
		{
			cout << "感谢使用，再见！\n";
			break;
		}
		else if (choice == 1)
		{
			string name, pwd;
			cout << "用户名: ";
			cin >> name;
			cout << "密码: ";
			cin >> pwd;

			if (sys.login(name, pwd))
			{
				User* u = sys.getCurrentUser();
				if (u->isAdmin())
					sys.adminMenu();
				else
					sys.userMenu();
				sys.logout();              
			}
			else
			{
				cout << "用户名或密码错误！\n";
			}
		}
		else if (choice == 2)
		{
			string name, pwd, pwd2;
			cout << "设置用户名: ";
			cin >> name;
			cout << "设置密码: ";
			cin >> pwd;
			cout << "确认密码: ";           
			cin >> pwd2;

			if (pwd != pwd2)
			{
				cout << "两次密码不一致，注册失败。\n";
			}
			else if (sys.registerUser(name, pwd))
			{
				cout << "注册成功，请返回主菜单登录。\n";
			}
			else
			{

				cout << "用户名已存在，注册失败。\n";
			}
		}
		else
		{
			cout << "无效选择。\n";
		}
	}
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
