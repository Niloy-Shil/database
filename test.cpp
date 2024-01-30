#include <iostream>
#include<sqlite3.h>
using namespace std;
int main()
{
char a;
sqlite3 *db;
char *sql;
sqlite3_stmt* stm;
cout<<"Welcome to the COllege library";
cout<<"\nfor log in type 'l' amd for regester type 'r'";
cin>>a;

if(a=='l')
{
}
else if(a=='r')
{
}
else
{
}
sqlite3_open("test.db",&db);
sqlite3_close(db);

}
