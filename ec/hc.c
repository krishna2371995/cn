#include<iostream>
#include<cmath>
using namespace std;
int getval(int p,string input,int len)
{
	int parity=0;
	int span=pow(2,p);
	cout<<"span is "<<span<<endl;
	int r=pow(2,p);
	cout<<"r is "<<r<<endl;
	int turn=1;
	int times=0;
	while(len>=r)
	{
		if(turn==1 && input[r-1]=='1')
		{
			cout<<r<<",";
			parity++;
		}
		r++;
		times++;
		if(times==span)
		{
			if(turn==0)
			turn++;
			else
			turn--;
			times=0;
		}
	}
	cout<<endl;
	if(parity%2==0)
	return 0;
	else return 1;
}
int getr(int len)
{
	int r=1;
	while(pow(2,r)<len+r+1)
	{
		r++;
	}
	return r;
}
int main()
{
	string input;
	cout<<"enter input msg\n";
	cin>>input;
	int m=input.length();
	cout<<m<<"\n";
	int r=getr(m);
	cout<<r<<endl;
	int opl=m+r;
	int *pos=new int[r];
	for(int i=0;i<r;i++)
	{
		pos[i]=pow(2,i)-1;
		input.insert(pos[i],"0");
	}
	cout<<input<<endl;
	cout<<input.length()<<endl;
	for(int i=0;i<r;i++)
	{
		
		int j=getval(i,input,input.length());
		if(j==0)
		input[pos[i]]='0';
		else
		input[pos[i]]='1';
	}
	cout<<endl<<input;
	string check;
	cout<<"\nenter string to check\n";
	cin>>check;
	int p=0;
	for(int i=0;i<r;i++)
	{
		
		int j=getval(i,check,check.length());
		if(j==1)
		p=p+pow(2,i);
	}
	cout<<"error at "<<p<<"\n";
}
