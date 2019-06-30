#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include <windows.h>
using namespace std;

struct user
      {
         string password;
         string name;
         bool banflag=false;
      };
      
class Users
{
	public:
		void regist();
		void login();
		void searchusers();
		void ban();
};
     
void Users::regist()
{ 
    char *password = new char[20];
    char name[20];
    char admi[]={"test"};
    user user1;
    ifstream fin;
    fin.open("user.txt",ios::in);
    cout << "请输入用户名："<<endl;
    cin>>name;
    if(strcmp(name,admi)==0){
    	cout<<"该用户名不可用"<<endl;
    	regist(); 
	}
    while(fin >> user1.name >> user1.password)//读取成功返回1
    {
        if(user1.name==name)
        {
		cout << "该用户名已被注册" <<endl;
		regist();
		}
    }
    char test ;int i=0;
    cout << "输入密码:"<<endl;
    while((test=getch())!='\r')
    {
        if(test==8)//ASC2码8为退格
        {
            if(i>0)
            {
            cout << test << " " << test;
            password[i--]='\0';
            }
        }
        else
        {
            if(i<20)
            {
                cout << "*" ;
                password[i]=test;
                i++;
            }
        }
    }
    password[i] = '\0';
    cout << "再次输入密码" <<endl;
    char *password2 = new char[20];
    i=0;
    while((test=getch())!='\r')
    {
        if(test==8)
        {
            if(i>0)
            {
                cout << test << " " << test ;
                password2[i--]='\0';
            }
        }
        else
        {
            if(i<20)
            {
                cout << "*";
                password2[i]=test;
                i++;
            }
        }
        password2[i]='\0';
    }
      if(strcmp(password,password2)!=0)
    {

        cout << "密码两次输入不正确"<<endl;
        regist();
    }
    else
    {
        cout << "注册成功"<<endl;
    }
    ofstream fout;
    fout.open("user.txt",ios::out|ios::app);
    fout << endl;
    fout << name << " " << password;
    fout.close();
    cout << "三秒后返回登陆界面"<<endl;
    login();
}

void Users::login()
{
    char *password = new char [20];
    string name;
    cout << "用户名："<<endl;
    cin>>name;
    cout <<"密码："<<endl;
    char test;int i=0;
    
	while((test=getch())!='\r')
    {
        if(test==8)//ASC2码8为退格
        {
        if(i>0)
        {
            cout << test << " " << test;
            password[i--]='\0';
        }
        }
        else
        {
            if(i<20)
            cout << "*";
            password[i]=test;
            i++;
        }
    }
    password[i]='\0';
    ifstream fin;
    fin.open("user.txt",ios_base::in);
    if(fin.fail())
    {
        cout << "文件打开失败";
    }
    user user1;
	int f1=0;
    while(fin>>user1.name>>user1.password)
    {
    	if(user1.banflag){
    		cout<<"此账号已被封禁"<<endl; 
		}
        else if(user1.name==name&&user1.password==password)
        {
            cout << "登陆成功"<<endl;
            f1=1;
            exit(1);
        }
    }
    if(f1==0)
    {
        cout << "用户名或密码错误"<<endl;
        login();
    }
}

void Users::searchusers()
{
	char *password = new char[20];
    char name[20];
    cout<<"用户名"<<"  "<<"密码"<<endl;
	ifstream fin;
    fin.open("user.txt",ios::in);
    fin.seekg(0);
	while(!fin.eof())
	{
		fin>>name>>password;
		cout<<name<<"     "<<password<<"     "<<endl;
	 } 
	fin.close(); 
	cout<<endl;
}

int main()
{
	Users test;
	//test.regist();
	test.searchusers();
 } 
