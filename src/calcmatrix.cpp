#include"calcmatrix.h"

int matmul(vector<vector<double> > &a, vector<vector<double> > &b, vector<vector<double> > &c) {
	int i,j,k;
	int m=a.size(),n=b.size(),l;
	if (m==0||n==0) return -1;
	else if (n!=a[0].size()) return -1;
	else l=b[0].size();
	c.clear();
	for (i=0;i<m;i++) {
		vector<double> temp(l,0);
		c.push_back(temp);
	}	
#pragma omp parallel for private(j,k)
	for (i=0;i<m;i++) {
		for (j=0;j<l;j++) 
			for (k=0;k<n;k++) c[i][j]+=a[i][k]*b[k][j];
	}
	return 0;
}

int matadd(vector<vector<double> > &a, vector<vector<double> > &b, vector<vector<double> > &c) {
	int i,j,k;
	int m=a.size(),n;
	if (m==0||m!=b.size()) return -1;
	if (a[0].size()==b[0].size()) n=a[0].size();
	else return -1;
	c.clear();
	for (i=0;i<m;i++) {
		vector<double> temp(n,0);
		c.push_back(temp);
	}	

#pragma omp parallel for private(temp)
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) c[i][j]=a[i][j]+b[i][j];
	}
	return 0;
}

int readmat(int m, int n, vector<vector<double> > &a) {
	int i,j;
	double num;
	a.clear();
	for (i=0;i<m;i++) {
		vector<double> temp;
		for (j=0;j<n;j++) {
			scanf("%lf",&num);
			temp.push_back(num);
		}
		a.push_back(temp);
	}
	return 0;
}

int readmat(int m, vector<vector<double> > &a) {
	int i,j;
	double num;
	a.clear();
	for (i=0;i<m;i++) {
		vector<double> temp;
		for (j=0;j<m;j++) {
			scanf("%lf",&num);
			temp.push_back(num);
		}
		a.push_back(temp);
	}
	return 0;
}

int writemat(vector<vector<double> > &a) {
	int m=a.size(),n;
	int i,j;
	if (m!=0) n=a[0].size();
	else return -1;
	for (i=0;i<m;i++) {
		for (j=0;j<n;j++) {
			printf("%e",a[i][j]);
			if (j==n-1) printf("\n");
			else printf("\t");
		}
	}
	return 0;
}
