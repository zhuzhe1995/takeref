#ifndef CALC_MAT
#define CALC_MAT
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<cstdio>

using namespace std;

int matmul(vector<vector<double> > &a, vector<vector<double> > &b, vector<vector<double> > &c);
int matadd(vector<vector<double> > &a, vector<vector<double> > &b, vector<vector<double> > &c);
int readmat(int m, int n, vector<vector<double> > &a);
int readmat(int m, vector<vector<double> > &a);
int writemat(vector<vector<double> > &a);

#endif

