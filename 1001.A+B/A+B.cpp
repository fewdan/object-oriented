#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int a,b,sum,bit[1010],sz;

int main ()
{
	cin>>a>>b;
	sum=a+b;
	if (sum<0){
		cout<<"-";
		sum=abs(sum);
	}
	if (sum<1000){
		cout<<sum<<endl;
		return 0;
	}//cout<<sum;
	int temp;
	while (sum)
	{
		temp=sum%10;
		sum/=10;
        bit[++sz]=temp;
	}
	int count=0;
	if (sz%3!=0) {
	    for (int i=sz;i>=sz-(sz%3)+1;i--)
  	  	    cout<<bit[i];
	    cout<<",";
	    for (int i=sz-(sz%3);i>=1;i--)
	    {
		    count++;
		    cout<<bit[i];
		    if (count==3 && i!=1){
			    cout<<",";
			    count=0;
		    }
	    }
	}
	else
		for (int i=sz;i>=1;i--)
		{
			if (i!=sz && i%3==0)
				cout<<",";
		    cout<<bit[i];
		}
	cout<<endl;
	return 0;
}