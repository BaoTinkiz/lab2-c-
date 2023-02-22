#include <iostream>

using namespace std;


void nhapMang(int mt[][3], int &m, int &n);
void xuatMang(int mt[][3], int m, int n);
int tongDong(int mt[][3], int n, int d);
int tongCot(int mt[][3], int m, int c);
int tongcheo1(int mt[][3],int m,int n);
int tongcheo2(int mt[][3],int m,int n);
void LuoshuSquare(int mt[][3],int m, int n);


int main()
{
	int mt[3][3];
	int nRow, nCol; 
	nhapMang(mt, nRow, nCol);
	xuatMang(mt, nRow, nCol);
	LuoshuSquare(mt, nRow, nCol);
	cout<<tongcheo1(mt, nRow,nCol)<<endl;
	cout<<tongcheo2(mt,nRow,nCol)<<endl;
	cout<<tongCot(mt,nRow,1)<<endl;
	cout<<tongCot(mt,nRow,2)<<endl;
	cout<<tongCot(mt,nRow,3)<<endl;
	cout<<tongDong(mt,nCol,1)<<endl;
	cout<<tongDong(mt,nCol,2)<<endl;
	cout<<tongDong(mt,nCol,3);

	
	return 0;
}

void nhapMang(int mt[][3], int &m, int &n)
{
	m = 3;
	n = 3;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<<endl;
			cout<<"Nhap phan tu a["<<i<<"]["<<j<<"] la :";
			cin>>mt[i][j];
		}
	}
}

void xuatMang(int mt[][3], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << mt[i][j] << "\t";
		}
		cout << endl;
	}
}
int tongDong(int mt[][3], int n, int d)
{
	int sum(0);
	for (int j = 0; j < n; j++)
		sum += mt[d-1][j];

	return sum;
}

int tongCot(int mt[][3], int m, int c)
{
	int sum(0);
	for (int i = 0; i < m; i++)
		sum += mt[i][c-1];

	return sum;
}

int tongcheo1(int mt[][3],int m,int n){
	int sum(0);
	for (int j = 0; j < n; j++)
		sum += mt[j][j];
	return sum;
}

int tongcheo2(int mt[][3],int m,int n){
	int sum(0);
	for (int i = 0,j= n-1; i < m; i++,j--)
	{
		sum += mt[i][j];
		
	}
	return sum;
}
void LuoshuSquare(int mt[][3],int m, int n){
	if (tongCot(mt,m,1)==15&&tongcheo1(mt,m,n)==15&&tongcheo2(mt,m,n)==15&&tongCot(mt,m,2)==15&&tongCot(mt,m,3)==15&&tongDong(mt,n,1)==15&&tongDong(mt,n,2)==15&&tongDong(mt,n,3)==15){
		cout<<"This is Luoshu Square"<<endl;
	}
	else cout<<"This is not Luoshu Square"<<endl;
}
