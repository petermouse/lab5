#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "HugeInt.h"
using namespace std;
HugeInt::HugeInt(long long int num)
{
    setData(num);
}
HugeInt::HugeInt(string str)
{
    if(str[0]=='-')
    {
    	sign=1;
	str=str.substr(1);
    }
    else
    {
	sign=0;
        if(str[0]=='+')
            str=str.substr(1);
    }
    for(int i=0;i<str.size()/3;i++)
        data.push_back(atoi(str.substr(str.size()-(i+1)*3,3).c_str()));
    if(str.size()%3!=0)
        data.push_back(atoi(str.substr(0,str.size()%3).c_str()));

}
HugeInt::HugeInt(short int signToCopy,vector<short int> dataToCopy):sign(signToCopy),data(dataToCopy)
{
    if(data.size()==1 && data[0]==0)
        sign=0;
}


vector<short int>HugeInt::getData() const
{
    return data;
}
short int HugeInt::getSign() const
{
    return sign;
}
void HugeInt::setData(long long int num)
{
    data.clear();
    if(num<0)
    {
	sign=1;
	num=-num;
    }
    else
	sign=0;

    do
    {
        data.push_back(num%1000);
        num=num/1000;
    }
    while(num!=0);
}

HugeInt HugeInt::operator+(const HugeInt & right)const
{
    if((right.getSign()+getSign())%2==0)
    {
        vector <short int> rightData(right.getData());
        vector <short int> leftData(getData());
	if(rightData.size()>=leftData.size())
            leftData.resize(rightData.size());
	else
	    rightData.resize(leftData.size());

	int carry=0;
	for(int i=0;i<leftData.size();i++)
	{
	    leftData[i]=rightData[i]+leftData[i]+carry;
	    if(leftData[i]>=1000)
            {
	        leftData[i]=leftData[i]-1000;
	        carry=1;
	    }
	    else
		carry=0;
	}
	if(carry==1)
	    leftData.push_back(carry);

	HugeInt temp(getSign(),leftData);

	return temp;
    }
    else if(getSign()==0 && right.getSign()==1)
    {
        HugeInt unsignedRight(0,right.getData());
        return (*this)-unsignedRight;
    }
    else if(getSign()==1 && right.getSign()==0)
    {
        HugeInt unsignedLeft(0,getData());
	return right-unsignedLeft;
    }
}
HugeInt HugeInt::operator-(const HugeInt & right)const
{
    if((getSign()+right.getSign())%2==0)
    {
        vector<short int> rightData(right.getData());
        vector<short int> leftData(getData());

	if(rightData.size()>=leftData.size())
	    leftData.resize(rightData.size());
	else
	    rightData.resize(leftData.size());
    
	bool compare=false;
	for(int i=leftData.size()-1;i>=0;i--)
	    if(leftData[i]>rightData[i])
	    {
	        compare=true;
		break;
	    }
        int carry=0;
	if(compare==true)
	{
	    for(int i=0;i<leftData.size();i++)
	    {    
		leftData[i]=leftData[i]-rightData[i]-carry;
		if(leftData[i]<0)
		{
		    leftData[i]=leftData[i]+1000;
		    carry=1;		
		}
		else
		    carry=0;
	    }
	}
	else
	{
	    for(int i=0;i<leftData.size();i++)
	    {
	        leftData[i]=rightData[i]-leftData[i]-carry;
	        if(leftData[i]<0)
	        {
		    leftData[i]=leftData[i]+1000;
		    carry=1;
		}
		else
		    carry=0;
	    }
	
	}
        for(int i=leftData.size()-1;i>=1;i--)
	    if(leftData[i]==0)
                leftData.pop_back();
	    else
		break;

	if((right.getSign()+getSign()==0 && compare==true)
	|| (right.getSign()+getSign()==2 && compare==false))
	{
	    HugeInt temp1(0,leftData);
	    return temp1;
	}
	else
	{
	    HugeInt temp2(1,leftData);
	    return temp2;
	}
    }
    else if(getSign()==0 && right.getSign()==1)
    {
        HugeInt positiveRight(0,right.getData());
        return (*this)+positiveRight;
    }
    else if(getSign()==1 && right.getSign()==0)
    {
        HugeInt negativeRight(1,right.getData());
	return (*this)+negativeRight;
    }


}
ostream & operator<<(ostream &output,const HugeInt & h)
{
    vector<short int> v(h.getData());
    if(h.getSign()==1)
        cout << '-';

    cout << v[v.size()-1];
    for(int i=v.size()-2;i>=0;i--)
        cout << setw(3) << setfill('0') << v[i];
    return output;
}
istream & operator>>(istream &input,HugeInt & h)
{
    long long int num;
    input >> num;
    h.setData(num);
    return input;
}
