#include<stdio.h>
#define Max 100
#define File1 "D:/dothi1.txt" 
typedef struct DoThi
{
	int n;
	int a[Max][Max];
} DoThi;

int ReadFile(char rf[Max], DoThi &TH1)
{
	FILE* f;
	f= fopen(rf,"rt");
	if(f==NULL)
	{
		printf("\nOpen file fail");
		return 0;
	}
	fscanf(f,"%d", &TH1.n);
	for(int i=0;i<TH1.n;i++)
		for(int j=0;j<TH1.n;j++)
				fscanf(f,"%d ", &TH1.a[i][j]);
	fclose(f);
	return 1;
}

void XuatDoThi(DoThi TH1)
{
	printf("\nSo dinh cua ma tran %d", TH1.n);

	printf("\nMa tran ke cua do thi\n");
	for(int i=0;i<TH1.n;i++)
	{
		for(int j=0;j<TH1.n;j++)
		{
			printf("%d ", TH1.a[i][j]);
		}
		printf("\n");
	}
	
}
int CheckDoThi(DoThi TH1)
{
	for(int i=0;i<TH1.n;i++)
	{
		if(TH1.a[i][i]!=0)
			return 0;
	}
	return 1;	
			
}


int CheckDoThiVH(DoThi TH1)
{
	for(int i=0;i<TH1.n;i++)
		for(int j=0;j<TH1.n;j++)
		{
			if(TH1.a[i][j]==TH1.a[j][i])
				return 0;
		}
		return 1;	
				
}

void BacDoThi(DoThi TH1)
{
	int s=0;
		for(int i=0;i<TH1.n;i++)
		{
			for(int j=0;j<TH1.n;j++)
			{
				if(TH1.a[i][j]==1)
				s=s+TH1.a[i][j];
			}
			printf("\nbac dinh %d=%d",i+1,s);
			s=0;
		}
}
int main()
{
	DoThi TH1;
	char rf[]=File1;
	if(ReadFile(rf, TH1)==1)
	{
		printf("\nDa doc thanh cong file");
		XuatDoThi(TH1);
	}
	if(CheckDoThi(TH1)==1)
		printf("\Do thi hop le");
	else
		printf("\nDo thi k hop le");
		if(CheckDoThiVH(TH1)==0)
		printf("\nDo thi vo huong");
	else
		printf("\nDo thi co huong");
	BacDoThi(TH1);
}

