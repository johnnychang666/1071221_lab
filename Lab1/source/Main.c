#include<stdio.h>
#include<stdlib.h>

typedef struct _student
{
	char name[5];
	int chinese;
	int English;
	int math;
	int sum;
	float avg;
}student;

int main(void)
{
	student data[5];
	FILE *stream1;
	FILE *stream2;
	int i,j,h;
	
	 j= fopen_s(&stream1,"D://aaa.txt", "r");
	 h= fopen_s(&stream2,"D://bbb.txt", "w");
	if (stream1 == NULL || stream2 == NULL) printf("Files failed.\n");
	else
	{
		fprintf(stream2, "姓名\t國文\t英文\t數學\t總和\t平均\n");
		for (i = 0; i < 5; i++)
		{
			fscanf_s(stream1, "%s", &data[i].name,6);
			fscanf_s(stream1, "%d", &data[i].chinese);
			fscanf_s(stream1, "%d", &data[i].English);
			fscanf_s(stream1, "%d", &data[i].math);

			data[i].sum = data[i].chinese + data[i].English + data[i].math;
			data[i].avg = data[i].sum / 3.0;
			fprintf(stream2, "%s\t%d\t%d\t%d\t%d\t%.2f\n",
				data[i].name, data[i].chinese, data[i].English,
				data[i].math, data[i].sum, data[i].avg);
		}
	}
	fclose(stream1);
	fclose(stream2);
	system("pause");
	return 0;
}