#include<bits/stdc++.h>
using namespace std;

// Returns XOR of 'a' and 'b'
// (both of same length)
string XOR(string a, string b)
{
	// Initialize result
	string result = "";

	int n = b.length();
	// Traverse all bits
	for(int i = 1; i < n; i++)
	{
		if (a[i] == b[i])
			result += "0";// if bits are same, then XOR is 0, else 1
		else
			result += "1";
	}
	return result;
}

// Performs division
string div(string dividend, string divisor)
{

	// Number of bits to be XORed at a time.
	int pick = divisor.length();

	// Slicing the dividend to appropriate length for particular step
	string tmp = dividend.substr(0, pick);

	int n = dividend.length();

	while (pick < n)
	{
		if (tmp[0] == '1')

			// Replace the dividend by the result of XOR and pull 1 bit down
			tmp = XOR(divisor, tmp) + dividend[pick];
		else

// If leftmost bit is '0'.
// If the leftmost bit of the dividend (or the part used in each step) is 0, the step cannot use the regular divisor; we need to use an all 0's divisor.
			tmp = XOR(std::string(pick, '0'), tmp) +
				dividend[pick];

		// Increment pick to move further
		pick += 1;
	}

	// For the last n bits, we have to carry it out normally as increased value of pick will cause Index Out of Bounds.
	if (tmp[0] == '1')
		tmp = XOR(divisor, tmp);
	else
		tmp = XOR(std::string(pick, '0'), tmp);

	return tmp;
}


string encodeData(string data, string key)
{
	int len_key = key.length();

	// Appends n-1 zero'es at end of data
	string appended_data = data;
	appended_data.append(len_key-1,'0');

	string remainder = div(appended_data, key);
	return remainder;
}


int main()
{//Get Data to be Transmitted
    int K;
    string data;
    cout<<"enter K:";
	cin>>K;
	cout<<"enter K bit data:";
	cin>>data;

    //Get Generator Polynomial
    int m;
    cout<<"enter m of X^m+X+1 such that m<K:";
	cin>>m;
	string key;
	cout<<"enter key(generator):";
	cin>>key;

    cout<<"\n Sender Side:"<<endl;
    cout<<"\n K bit data: "<<data;
    cout<<"\n Generator :"<<key;

    //Append 0's
    string temp=data;
    cout<<"\n Number of 0's to be appended: "<<m-1;
    cout<<"\n Message after appending 0's :"<<temp.append(m-1,'0')<<endl;// m-1 'ZERO' bits to be append to the data

   string remainder=encodeData(data,key);

	// Append remainder in the original data
	string codeword = data + remainder;
	cout << "Remainder : "
		<< remainder << "\n";
	cout << "Data encoded to receiver (Data + CRC) :"
		<< codeword << endl;
    //inversion of bits
    int alter_position;
	cout<<"\n enter the inverse position from left:";
	cin>>alter_position;
	data[alter_position-1]='0'?'1':'0';
	cout<<"hence data is :"<<data<<endl;
	 remainder=encodeData(data, key);
	cout<<"\n Receiver side : "<<endl;
	cout << "Remainder: "
		<< remainder << "\n";
	int flag=0;
    for(int i=0;i<m-1;i++)
    {
        if(remainder[i]!=0)
        {
            flag=1;
        }
    }

    if(flag==0)
    {
        cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receiver Is Correct"<<endl;
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receiver Contains Error"<<endl;
    }

  cout<<"-----------------------------------.....................-----------------------------"<<endl;
    return 0;
}


