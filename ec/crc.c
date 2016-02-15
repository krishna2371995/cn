#include<iostream>
#include<bitset>
using namespace std;
int fd(int p)
{
	int i=-1;
	while(p!=0)
	{
		p=p>>1;
		i++;
	}
	return i;
}
int main()
{
	int n,poly;
	cout<<"enter data\n";
	cin>>n;
	cout<<bitset<16>(n)<<endl;
	int ndegree=fd(n);
	cout<<"enter polynomial\n";
	cin>>poly;
	cout<<bitset<16>(poly)<<endl;
	int degree=fd(poly);
	cout<<degree<<endl;
	int r=n<<degree;
	cout<<r<<endl;
	cout<<bitset<16>(r)<<endl; 
	poly=poly<<ndegree;
	for(int i=0;i<=ndegree;i++)
	{
		
		cout<<bitset<16>(poly)<<endl;
		if(fd(r)==fd(poly))
		r=r^poly;
		else
		r=r^0;
		cout<<r<<"\n";
		cout<<bitset<16>(r)<<"\n";
		poly=poly>>1;
	}
	n=n<<degree;
	n=n^r;
	cout<<n<<endl;
	cout<<bitset<16>(n)<<endl;
}
