#include<iostream>
#include<cstdlib>
#include<cstdio>
#include"calcmatrix.h"

using namespace std;

int main(int argc, char** argv) {
	vector<vector<double> > a,b,c;
	int m,n,k;
	cin >> m >> n;
	readmat(m,n,a);
	cin >> n >> k;
	readmat(n,k,b);
	matmul(a,b,c);
	writemat(c);
	matadd(a,b,c);
	writemat(c);
	return 0;
}
