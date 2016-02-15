#include<iostream>
#include<cmath>
using namespace std;
string hextobin(char t)
{
	string temp;
	switch(t)
	{
		case '0' : temp="0000";
				   break;
		case '1' : temp="0001";
				   break;
		case '2' : temp="0010";
					break;
		case '3' : temp="0011";
					break;
		case '4' : temp="0100";
					break;
		case '5' : temp="0101";
					break;
		case '6' : temp="0110";
					break;
		case '7' : temp="0111";
					break;
		case '8' : temp="1000";
					break;
		case '9' : temp="1001";
					break;
		case 'A' : temp="1010";
	                break;
		case 'B' : temp="1011";
					break;
		case 'C' : temp="1100";
					break;
		case 'D' : temp="1101";
					break;
		case 'E' : temp="1110";
					break;
		case 'F' : temp="1111";
					break;
	}
	return temp;
}
string bintohex(string t)
{
	if(t=="0000"||t=="000"||t=="00"||t=="0")
	return "0";
	else if(t=="0001"||t=="001"||t=="01"||t=="0")
	return "1";
	else if(t=="0010"||t=="010"||t=="10")
	return "2";
	else if(t=="0011"||t=="011"||t=="11")
	return "3";
	else if(t=="0100"||t=="100")
	return "4";
	else if(t=="0101"||t=="101")
	return "5";
	else if(t=="0110"||t=="110")
	return "6";
	else if(t=="0111"||t=="111")
	return "7";
	else if(t=="1000")
	return "8";
	else if(t=="1001")
	return "9";
	else if(t=="1010")
	return "A";
	else if(t=="1011")
	return "B";
	else if(t=="1100")
	return "C";
	else if(t=="1101")
	return "D";
	else if(t=="1110")
	return "E";
	else if(t=="1111")
	return "F";
}
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
	string hex,input="";
	cout<<"enter input msg\n";
	cin>>hex;
	int m=hex.length();
	cout<<m<<endl;
	for(int i=0;i<m;i++)
	{
		string temp=hex.substr(m-i-1,1);
		cout<<temp;
		char c=temp[0];
		temp=hextobin(c);
		cout<<temp<<"\n";
		input=temp+input;
	}
	cout<<input<<endl;
	m=input.length();
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
	cout<<input<<endl;
	string output="";
	m=input.length();
	cout<<m<<endl;
	string temp="";
	for(int i=m-1;i>=0;i--)
	{
		temp=input.substr(i,1)+temp;
		if(temp.length()==4 ||i==0)
		{
			cout<<temp<<"\n";
			temp=bintohex(temp);
			output=temp+output;
			temp="";
		}
	}
	cout<<"out put is \n"<<output;
	cout<<"\nenter check input\n";
	string check;
	cin>>check;
	m=check.length();
	cout<<m<<endl;
	input="";
	for(int i=0;i<m;i++)
	{
		string temp=check.substr(m-i-1,1);
		cout<<temp;
		char c=temp[0];
		temp=hextobin(c);
		cout<<temp<<"\n";
		input=temp+input;
	}
		int p=0;
	for(int i=0;i<r;i++)
	{
		
		int j=getval(i,input,input.length());
		if(j==1)
		p=p+pow(2,i);
	}
	cout<<"error at "<<p<<"\n";
}
