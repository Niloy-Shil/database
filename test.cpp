#include <iostream>
#include<sqlite3.h>
using namespace std;
int main()
{
char a;
char addr[60];
char name[40];
char pass[20];
sqlite3 *db;
char *sql;
sqlite3_stmt* stm;
sqlite3_open("test.db",&db);
cout<<"Welcome to the COllege library";
R:
cout<<"\nfor log in type 'l' and for regester type 'r' :";
cin>>a;
//for login
if(a=='l')
{
cout<<"Name:";
cin>>name;
cout<<"Password:";
cin>>pass;

sql="select * from obj where name=? and pass=?;";

sqlite3_prepare_v2(db,sql,-1,&stm, NULL);
sqlite3_bind_text(stm, 1,name,-1,SQLITE_STATIC);
sqlite3_bind_text(stm, 2,pass,-1,SQLITE_STATIC);
int r =sqlite3_step(stm);
if(r!=SQLITE_DONE)
{
printf("YOUR DATA =\n %s\t %s \t %s",sqlite3_column_text(stm,1),sqlite3_column_text(stm,2),sqlite3_column_text(stm,3));
}
else{
cout<<"\n no data found.please regester...";
goto R;
}

}

//for regester
else if(a=='r'){
cout<<"Name:";
cin>>name;
cout<<"Password:";
 cin>>pass;
cout<<"Address:";
cin>>addr;
sql="insert into obj(name,pass,addr) values(?,?,?);";
sqlite3_prepare_v2(db,sql,-1,&stm,NULL);
sqlite3_bind_text(stm, 1,name,-1,SQLITE_STATIC);
sqlite3_bind_text(stm, 2,pass,-1,SQLITE_STATIC);
sqlite3_bind_text(stm, 3,addr,-1,SQLITE_STATIC);
}
else
{
	cout<<"wrong input\n";
	goto R;
}
sqlite3_step(stm);
sqlite3_finalize(stm);
sqlite3_close(db);

}
