#include <iostream>
#include<stdlib.h>
#include <complex>
#define MAX 200

using namespace std;

const double PI = acos(-1);

void fft(complex<double>* a, int n) {
    if (n == 1)
        return;

    complex<double> a0[n / 2], a1[n / 2];
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, n/2);
    fft(a1, n/2);

    double ang = 2 * PI / n ; 
    complex<double> w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        w *= wn;
    }
}

int main()
{
  	int n;
	cout << "specify array dimension (MUST be power of 2)" << endl;
    cin >> n;
  
  	complex<double> vec[MAX];
  	cout << "specify the array" << endl;
  	for(int i = 0; i < n; i++) 
	{
    	cout << "Element number: " << i << endl;
    	cin >> vec[i];
  	}
  	fft(vec,n);
  	cout << "Printing the FFT of the array specified" << endl;
  	for(int j = 0; j < n; j++)
    	cout << vec[j] << endl;
  	return 0;
}
