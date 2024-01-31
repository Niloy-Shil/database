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
sqlite3_open("/data/data/com.termux/files/home/database/source/test.db",&db);
cout<<"Welcome to the COllege library";
R:

cout<<"\nfor admin login type 'a' , for student login type 'l' and for student regester type 'r' and for quit type 'q':";
cin>>a;
//for admin  login
if(a=='a')
{
cout<<"Name:";
cin>>name;
cout<<"Password:";
cin>>pass;
sql="select * from admin where name=? and pass=?";
sqlite3_prepare_v2(db,sql,-1,&stm,NULL);
sqlite3_bind_text(stm,1,name,-1,SQLITE_STATIC);
sqlite3_bind_text(stm,2,pass,-1,SQLITE_STATIC);
int rc=sqlite3_step(stm);
if(rc!=SQLITE_DONE)
{
char d;
char bname[60];
char prize[10];
int left;
printf("\nWelcome Mr. %s",sqlite3_column_text(stm,0));
A:
cout<<"\n to see the book list enter 'l' ,to add book list 'a',to see student list enter 's' to quit type'q'.\n Enter::";
cin>>d;
if (d=='a') {
cout<<"Book name:";
cin>>bname;
cout<<"Book prize:";
cin>>prize;
cout<<"Book left:";
cin>>left;
sql="insert into book(bname,bprize,left) values(?,?,?);";
sqlite3_prepare_v2(db,sql,-1, &stm,NULL);
sqlite3_bind_text(stm,1,bname,-1,SQLITE_STATIC);

sqlite3_bind_text(stm,2,prize,-1,SQLITE_STATIC);
sqlite3_bind_int(stm,3,left);
sqlite3_step(stm);
sqlite3_finalize(stm);
goto A;
}
else if(d=='q')
{
	sqlite3_close(db);
	return 0;
}

else if (d=='l') {
sql="select * from book;";
sqlite3_prepare_v2(db,sql,-1,&stm,NULL);
int rc = sqlite3_step(stm);
while(rc!=SQLITE_DONE)
{
printf("%d \t %s \t %s \t %d \n",sqlite3_column_int(stm, 0), sqlite3_column_text(stm, 1),sqlite3_column_text(stm, 2), sqlite3_column_int(stm, 3));
rc = sqlite3_step(stm);
}
sqlite3_finalize(stm);
goto A;
}
else if (d=='s') {
sql="select * from obj;";
sqlite3_prepare_v2(db,sql,-1,&stm,NULL);
int rc = sqlite3_step(stm);
while(rc!=SQLITE_DONE)
{
printf("%d \t %s \t %s \t %s \n",sqlite3_column_int(stm, 0), sqlite3_column_text(stm, 1),sqlite3_column_text(stm, 2), sqlite3_column_text(stm, 3));
rc = sqlite3_step(stm);

}
sqlite3_finalize(stm);
goto A;
}
}
else {
cout<<"Intruder Alert \n SHUT DOWN";
}
}
//for student login
else if(a=='l')
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
printf("YOUR DATA =\n%d\t %s\t %s \t %s",sqlite3_column_int(stm,0),sqlite3_column_text(stm,1),sqlite3_column_text(stm,2),sqlite3_column_text(stm,3));
sqlite3_step(stm);
sqlite3_finalize(stm);
Z:
char z;
cout<<"\ndo you want to see the book list? If yes type  'y'  , to order a book type  'o' to exit type 'q'.\n Enter:";
cin>>z;
if(z=='y')
{

sql="select * from book;";
sqlite3_prepare_v2(db,sql,-1,&stm,NULL);
int rc = sqlite3_step(stm);
while(rc!=SQLITE_DONE)
{
printf("%d \t %s \t %s \t %d \n",sqlite3_column_int(stm, 0), sqlite3_column_text(stm, 1),sqlite3_column_text(stm, 2), sqlite3_column_int(stm, 3));
rc = sqlite3_step(stm);
}
sqlite3_finalize(stm);
}
if(z=='q')
{
system("clear");
goto R;
}
if(z=='o')
{
sql="insert into list(bid,uid) values(?,?);";
int x;
int y;
cout<<"Enter book id:";
cin>>x;
cout<<"Enrer user id:";
cin>>y;
sqlite3_prepare_v2(db,sql,-1,&stm,NULL );
sqlite3_bind_int(stm,1,x);
sqlite3_bind_int(stm,2,y);
sqlite3_step(stm);
sqlite3_finalize(stm);
cout<<"your data stored successfully";
goto Z;

}

if(z=='s')
{
int x;
cout<<"enter your id:";
cin>>x;
char *zsql="select bname,bprize,_date from book inner join list on book._no=list.bid where list.uid=?;";
sqlite3_prepare_v2(db,zsql,-1,&stm,NULL);
sqlite3_bind_int(stm,1,x);
int y=sqlite3_step(stm);
while(y!=SQLITE_DONE)
{
printf("\n %s \t %s \t %s",sqlite3_column_text(stm,0),sqlite3_column_text(stm,1),sqlite3_column_text(stm,2));
y=sqlite3_step(stm);
}
sqlite3_finalize(stm);
goto Z;
}

else
{
cout<<"please order first";
sqlite3_finalize(stm);
goto Z;
}

}

else{
cout<<"\n no data found.please regester...";
goto R;

}
}
//for student regester
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
sqlite3_step(stm);
sqlite3_finalize( stm);
cout<<"\nRegestration Complete.Press any key.Login and order:";
char Tt;
cin>>Tt;
system("clear");
goto R;
}
//for exit
else if(a=='q')
{

return 0;
}
else
{
	cout<<"wrong input\n";
	goto R;
}
sqlite3_finalize(stm);
sqlite3_close(db);
return 0;
}
