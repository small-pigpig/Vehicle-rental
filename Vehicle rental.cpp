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
    cout << "�������û�����"<<endl;
    cin>>name;
    if(strcmp(name,admi)==0){
    	cout<<"���û���������"<<endl;
    	regist(); 
	}
    while(fin >> user1.name >> user1.password)//��ȡ�ɹ�����1
    {
        if(user1.name==name)
        {
		cout << "���û����ѱ�ע��" <<endl;
		regist();
		}
    }
    char test ;int i=0;
    cout << "��������:"<<endl;
    while((test=getch())!='\r')
    {
        if(test==8)//ASC2��8Ϊ�˸�
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
    cout << "�ٴ���������" <<endl;
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

        cout << "�����������벻��ȷ"<<endl;
        regist();
    }
    else
    {
        cout << "ע��ɹ�"<<endl;
    }
    ofstream fout;
    fout.open("user.txt",ios::out|ios::app);
    fout << endl;
    fout << name << " " << password;
    fout.close();
    cout << "����󷵻ص�½����"<<endl;
    login();
}

void Users::login()
{
    char *password = new char [20];
    string name;
    cout << "�û�����"<<endl;
    cin>>name;
    cout <<"���룺"<<endl;
    char test;int i=0;
    
	while((test=getch())!='\r')
    {
        if(test==8)//ASC2��8Ϊ�˸�
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
        cout << "�ļ���ʧ��";
    }
    user user1;
	int f1=0;
    while(fin>>user1.name>>user1.password)
    {
    	if(user1.banflag){
    		cout<<"���˺��ѱ����"<<endl; 
		}
        else if(user1.name==name&&user1.password==password)
        {
            cout << "��½�ɹ�"<<endl;
            f1=1;
            exit(1);
        }
    }
    if(f1==0)
    {
        cout << "�û������������"<<endl;
        login();
    }
}

void Users::searchusers()
{
	char *password = new char[20];
    char name[20];
    cout<<"�û���"<<"  "<<"����"<<endl;
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
