#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 50
#define AlterMax 10
struct Student {
	char id[15];
	char name[20];
	float English;
	float Math;
	float Physics;
	float C;
};
typedef struct Student Student;
void menu(void);
void record(void);
void query(void);
void alter(void);
void save(void);
void average(void);
void sort(void);
void read(void);
float avg(Student student);
float sum(Student student);
Student student[MAX];
int N, len = 0;
int main()
{
	menu();
	return 0;
}

//���˵�
void menu(void)
{
	int option = 0;
	read();
	N = len;
	while (1)
	{
		printf("\n                   ѧ���ɼ�����ϵͳ\n\n");
		printf("**********************���˵�*********************\n");
		printf("-------------------------------------------------\n");
		printf("                  1.¼��ѧ���ɼ�\n");
		printf("                  2.��ѯѧ���ɼ�\n");
		printf("                  3.�޸�ѧ���ɼ�\n");
		printf("                  4.�����ܳɼ���ƽ����\n");
		printf("                  5.���ܳɼ���������\n");
		printf("                  6.�����޸�\n");
		printf("                  7.�˳�\n");
		printf("-------------------------------------------------\n");
		printf("��ѡ����ѡ���Ӧ���:");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:record(); break;
		case 2:query(); break;
		case 3:alter(); break;
		case 4:average(); break;
		case 5:sort(); break;
		case 6:save(); break;
		case 7:save(); return;
		}
	}
}

//¼��ѧ���ɼ�
void record()
{
	int i;
	printf("������ѧ������");
	scanf_s("%d", &N);
	for (i = len; i < len + N; i++)
	{
		printf("ѧ��%dѧ�ţ�", i + 1 - len); scanf_s("%s", student[i].id, 15);
		printf("ѧ��%d������", i + 1 - len); scanf_s("%s", student[i].name, 15);
		printf("ѧ��%d��ѧӢ��ɼ���", i + 1 - len); scanf_s("%f", &student[i].English, 15);
		printf("ѧ��%d�ߵ���ѧ�ɼ���", i + 1 - len); scanf_s("%f", &student[i].Math, 15);
		printf("ѧ��%d��ѧ����ɼ���", i + 1 - len); scanf_s("%f", &student[i].Physics, 15);
		printf("ѧ��%dC���Գɼ���", i + 1 - len); scanf_s("%f", &student[i].C, 15);
	}
	len += N;
	N = len;
}

//��ѯѧ���ɼ�
void query()
{
	char id[30];
	int i;
	printf("������ѧ��ѧ�ţ�"); scanf_s("%s", id, 20);
	printf("\n%-15s%-20s%-10s%-10s%-10s%-10s\n", "ID", "Name", "English", "Math", "Physics", "C");
	for (i = 0; i<N; i++)
	{
		if(!strcmp(id, student[i].id))
			printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", student[i].id, student[i].name, student[i].English, student[i].Math, student[i].Physics, student[i].C);
	}
	putchar('\n');
}

//�޸�ѧ���ɼ�
void alter()
{
	int i;
	char id[30], subject[20];
	float score;
	printf("������Ҫ�޸�ѧ����ѧ�ţ�"); scanf_s("%s", id, 30);
	printf("������Ҫ�޸ĵĿ�Ŀ(English,Math,Physics��C)��"); scanf_s("%s", subject, 20);
	printf("������ѧ���ɼ���"); scanf_s("%f", &score, 10);
	printf("�޸ĳɹ���\n�޸ĺ��ѧ���ɼ����£�\n");
	for (i = 0; i < N; i++)
	{
		if (!strcmp(id, student[i].id))
		{
			if (!strcmp(subject, "English")) student[i].English = score;
			if (!strcmp(subject, "Math")) student[i].Math = score;
			if (!strcmp(subject, "Physics")) student[i].Physics = score;
			if (!strcmp(subject, "C")) student[i].C = score;
		}
	}
	printf("%-15s%-20s%-10s%-10s%-10s%-10s\n", "ID", "Name", "English", "Math", "Physics", "C");
	for (i = 0; i < N; i++)
	{
		printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", student[i].id, student[i].name, student[i].English, student[i].Math, student[i].Physics, student[i].C);
	}
	putchar('\n');
}

//����ƽ����
void average()
{
	int i;
	printf("%-15s%-20s%-10s%-10s\n", "ID", "Name", "SUM", "AVG");
	for (i = 0; i<N; i++)
	{
		printf("%-15s%-20s%-10.2f%-10.2f\n", student[i].id, student[i].name, sum(student[i]), avg(student[i]));
	}
	putchar('\n');
}

//����
void sort()
{
	Student m;
	int i, j;
	for (i = N - 1; i>0; i--)
	{
		for (j = 0; j<i; j++)
			if (avg(student[j])>avg(student[j + 1]))
			{
				m = student[j];
				student[j] = student[j + 1];
				student[j + 1] = m;
			}
	}
	printf("%-15s%-20s%-10s\n", "ID", "Name", "SUM");
	for (i = 0; i<N; i++)
	{
		printf("%-15s%-20s%-10.2f\n", student[i].id, student[i].name, sum(student[i]));
	}
	putchar('\n');
}

//����
void save()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, "ѧ���ɼ�����ϵͳ���ݿ�.txt", "w");
	int i;
	for(i=0;i < N;i++)
	{
		fprintf(fp, "%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n", student[i].id, student[i].name, student[i].English, student[i].Math, student[i].Physics, student[i].C);
	}
	fclose(fp);
	printf("����ɹ�!\n");
	return;
}

//��ȡ����
void read()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, "ѧ���ɼ�����ϵͳ���ݿ�.txt", "r");
	if (err != 0)
	{
		printf("�����ļ������ڻ���������ʧ�ܣ�");
		return;
	}
	if (!fp) return;
	int i = 0;
	while (!feof(fp))
	{
		fscanf_s(fp, "%s%s%f%f%f%f\n", student[i].id, 15, student[i].name, 20, &student[i].English, &student[i].Math, &student[i].Physics, &student[i].C);
		i++;
	}
	len = i;
	fclose(fp);
	return;
}


float sum(Student student)
{
	float sum = student.English + student.Math + student.Physics + student.C;
	return sum;
}
float avg(Student student)
{
	return sum(student) / 4;
}
