#include<stdio.h>
#include<stdlib.h>

struct clientData
{
	int accNum;
	char lastName[15];
	char firstName[10];
	float balance;
};

int main(void)
{
	FILE *pRead, *pWrite;
	FILE *cpftr;
	int cnt = 0,i,j,a;

	struct clientData client = { 0,"","",0.0 };

	i = fopen_s(&pRead,"D://ccc.txt", "r");
	if (NULL == pRead) return 0;
	j = fopen_s(&pWrite,"D://ddd.txt", "wb");
	if (NULL == pWrite)
	{
		fclose(pRead);
		return 0;
	}
	while (!feof(pRead))
	{
		fscanf_s(pRead, "%d%s%s%f", &client.accNum, client.lastName,16, 
			client.firstName,11, &client.balance);
		fwrite(&client, sizeof(struct clientData), 1, pWrite);
		printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName,
			client.firstName, client.balance);
	}
	fclose(pRead);
	fclose(pWrite);
	printf("已讀取文字檔的ASCII資料，並轉換成二進位資料檔案\n\n");
	system("pause");

	printf("\n讀取二進位檔案，並格式化輸出如下:\n");
	a = fopen_s(&cpftr, "D://ddd.txt", "rb");
	if (a!=0) 
		printf("File couldn't be opened.\n");
	else
	{
		printf("%-6s%-16s%-11s%10s\n", "Acct","Last Name","First Name","Balance");
		cnt = fread(&client, sizeof(struct clientData), 1, cpftr);
		while (cnt > 0)
		{
			printf("%-6d%-16s%-11s%10.2f\n", client.accNum, client.lastName, client.firstName,
				client.balance);
			cnt = fread(&client, sizeof(struct clientData), 1, cpftr);
		}
		fclose(cpftr);
	}
	system("pause");
	return 0;
}