//Nhom cua manh
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void docDoThi(int A[][SIZE], int &n);
void toMau(int A[][SIZE],int n,int Mau[]);
void xuat(int A[], int n);

int main()
{
	int A[SIZE][SIZE], n;
	int Mau[SIZE];
	docDoThi(A,n);
	for(int i =0; i<n; i++)
	{
		
		for(int j=0; j<n;j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\nTo Mau Do Thi:");	
	toMau(A,n,Mau);
	xuat(Mau,n);
	return 1;
}
void docDoThi(int A[][SIZE], int &n){
	FILE *fi = fopen("D:/dothi10.txt","rt");
	if(fi == NULL){
		printf("Khong mo duoc file");
		exit(0);
	}
	fscanf(fi,"%d",&n);
	for(int i =0; i<n; i++)
	{
		for(int j=0; j<n;j++)
		{
			fscanf(fi,"%d", &A[i][j]);
		}
	}
	fclose(fi);
}
void toMau(int A[][SIZE],int n,int Mau[])
{
	int BangMau[SIZE][SIZE] = {0};
	int mauvuato;
	for(int i=0; i<n; i++)
	{
		for(int k = 0; k <n; k++)
			if(BangMau[i][k] == 0)
			{
				Mau[i] = k;
				mauvuato = k;
				break;
			}
		for(int j=i+1; j<n; j++)
		{
			if(A[i][j] > 0)
				BangMau[j][mauvuato] = 1;
		}
	}
}
void xuat(int A[], int n){
	for(int i=0;i<n;i++)
	{
		printf("\nDinh:%d:", i+1);
		
		if(A[i] + 1==1)
			printf("xanh");
		if(A[i] + 1==2)
			printf("do");
		if(A[i] + 1==3)
			printf("tim");
		if(A[i] + 1==4)
			printf("vang");
		if(A[i]+1== 5)
			printf("hong");
		if(A[i]+1== 6)
			printf("cam");
		if(A[i]+1== 7)
			printf("Den");
			
		
	}	 
}
