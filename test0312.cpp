#include "0312.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){


	struct GlobVariable Glob;
	struct GlobVariable *GlobPointer;

	Glob.mark = 0;                                  //�ṹ���ʼ��
	Glob.ArrayFlag = 0;
	memset(Glob.LastStatus, 0, sizeof(int) * 9);
	memset(Glob.CacheLastStatus, 0, sizeof(int) * 9);
	memset(Glob.MinStatus, 0, sizeof(double) * 9);
	memset(Glob.MaxStatus, 0, sizeof(double) * 9);
	memset(Glob.CacheAry, 0, sizeof(double) * 9);
	memset(Glob.RecallStatus, 0, sizeof(int) * 9);

	GlobPointer = &Glob;


	FILE *fp = fopen("Data.txt", "r");
	if (fp == NULL)                               //���ļ������� ����
	{
		printf("Error : Can't open the file.\n");
		exit(1);
	}
	int num = 20;
	double Source[9] = { 0 };
	double data = 0;
	double *result = NULL;
	int IsCorrect = 2;
	int counter = 0;

	/*-------------------------------����ѧϰ(20)---------------------------------*/

	for (int j = 0; j < num; j++) {
		for (int i = 0; i < 9; i++) {
			fscanf(fp, "%lf", &data);
			Source[i] = data;
		}
		data = 0;
		result = marcovp(Source, num, 0, 0, GlobPointer);              //����ѧϰ �˴�Result��ֵΪNULL 
	}
	/*
	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);

	printf("����������\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}

	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}
	*/


	//system("pause");

	/*-------------------------------�����״�Ԥ�⣨21st Step��---------------------------------*/

	double *PredictResult = (double*)calloc(9, sizeof(double));

	PredictResult = marcovp(NULL, num, 1, 0, GlobPointer);                                  //����Ԥ�� ���Ԥ����

	printf("\n�״�Ԥ���ֵΪ :\n");
	for (int i = 0; i < 9; i++) {
		printf("\n%.16e\n", PredictResult[i]);

	}

	system("pause");

	printf("���CacheAry��\n");
	for (int i = 0; i < 9; i++) {
		printf("%.16e\n", GlobPointer->CacheAry[i]);

	}
	printf("���CacheLastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->CacheLastStatus[i]);
	}

	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);


	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}

	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}


	//system("pause");

	/*-------------------------------��׼ȷ�����ݲ��ٴ�Ԥ��(21st Step)---------------------------------*/

	printf("\n����Ԥ�ⲻ׼ȷ \n");
	IsCorrect = 0;

	//���ﻹҪ��һ���Ƿ��Ѿ����ݹ����ж�

	if (!IsCorrect){
		PredictResult = marcovp(NULL, num, 1, 1, GlobPointer);
	}

	printf("\n���ݺ��Ԥ��ֵΪ�� \n");

	for (int i = 0; i < 9; i++) {
		printf("\n%.16e\n", PredictResult[i]);

	}
	printf("���CacheAry��\n");
	for (int i = 0; i < 9; i++) {
		printf("%.16e\n", GlobPointer->CacheAry[i]);
	}

	printf("���CacheLastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->CacheLastStatus[i]);
	}

	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);
	//system("pause");

	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}

	/*----------------------------��׼ȷ��21������ѧϰ(21st Step)---------------------------------*/

	printf("\n����Ԥ�ⲻ׼ȷ����ô��һ������ѧϰ \n");
	Source[0] = 5.166034207867376E-004;
	Source[1] = 4.346928501697935E-004;
	Source[2] = 4.750490770142530E-004;
	Source[3] = -1.970079378272880E-003;
	Source[4] = -1.546372660686910E-004;
	Source[5] = -1.689935046106157E-004;
	Source[6] = 1.582613378448928E-003;
	Source[7] = -1.713949095850274E-004;
	Source[8] = -1.873067980043166E-004;

	result = marcovp(Source, num + 1, 0, 0, GlobPointer);

	printf("���LastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->LastStatus[i]);
	}
	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);

	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}


	/*
	for (int i = 0; i < 9; i++) {
	printf("%d\n",NumOfPositiveStatus[i]);
	}
	for (int i = 0; i < 9; i++) {
	printf("%d\n", NumOfNegativeStatus[i]);
	}
	*/
	/*-----------------------------׼ȷ������Ԥ�⣨22nd Step��-----------------------------------*/
	/*
	printf("\n����Ԥ��׼ȷ ��ô����Ԥ����һ�� \n");
	IsCorrect = 1;

	if (IsCorrect){
	PredictResult = marcovp(NULL, num + 1, 1, 0);
	}

	/*
	int Flag = 0;
	for (int i = 1; i <= num + 1; i++) {
	for (int j = Flag; j < i * 9; j++) {
	printf("���¼��ļ���ֵ������Ԥ��׼ȷֵ%.16e!!!!!!!", SourceDataAry[j]);
	printf("------%d\n", j);
	}
	Flag = Flag + 9;
	}

	printf("\n��%d����Ԥ��ֵ�ǣ� \n", num + 2);


	for (int i = 0; i < 9; i++) {
	printf("\n%.16e\n", PredictResult[i]);
	}

	//system("pause");
	printf("���CacheAry��\n");
	for (int i = 0; i < 9; i++) {
	printf("%.16e\n", GlobPointer->CacheAry[i]);
	}

	printf("���CacheLastStatus��\n");
	for (int i = 0; i < 9; i++) {
	printf("%d\n", GlobPointer->CacheLastStatus[i]);
	}
	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);

	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
	for (int j = 0; j <= 3; j++) {
	printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
	counter++;
	if (counter % 4 == 0) {
	printf("\n");
	}
	}
	}
	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
	printf("%d\n",GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
	for (int j = 0; j <= 3; j++) {
	printf("%d", GlobPointer->TransMatrix[8][i][j]);
	counter++;
	if (counter % 4 == 0) {
	printf("\n");
	}
	}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
	printf("%d\n", GlobPointer->InitProbability[8][i]);
	}

	*/
	/*--------------------Ԥ���22��(22nd Step)----------------------*/

	printf("��21��Ԥ�ⲻ׼ȷ��ѧϰһ����Ԥ���22����\n");
	PredictResult = marcovp(NULL, num + 1, 1, 0, GlobPointer);
	/*
	int Flag = 0;
	for (int i = 1; i <=  num + 1; i++) {
	for (int j = Flag; j < i * 9; j++) {
	printf("���¼��ļ���ֵ������Ԥ��׼ȷֵ%.16e!!!!!!!", GlobPointer->SourceDataAry[j]);
	printf("------%d\n", j);
	}
	Flag = Flag + 9;
	}
	*/
	printf("\n��%d����Ԥ��ֵ�ǣ� \n", num + 2);


	for (int i = 0; i < 9; i++) {
		printf("\n%.16e\n", PredictResult[i]);
	}


	//system("pause");
	printf("���CacheAry��\n");
	for (int i = 0; i < 9; i++) {
		printf("%.16e\n", GlobPointer->CacheAry[i]);
	}

	printf("���CacheLastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->CacheLastStatus[i]);
	}
	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);

	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}

	/*-------------------Ԥ��׼ȷ������Ԥ���23��------------------*/

	printf("��22��Ԥ��׼ȷ������Ԥ���23����\n");
	PredictResult = marcovp(NULL, num + 2, 1, 0, GlobPointer);                                  //����Ԥ�� ���Ԥ����

	/*
	int Flag = 0;
	for (int i = 1; i <=  num + 2; i++) {
	for (int j = Flag; j < i * 9; j++) {
	printf("���¼��ļ���ֵ������Ԥ��׼ȷֵ%.16e!!!!!!!", SourceDataAry[j]);
	printf("------%d\n", j);
	}
	Flag = Flag + 9;
	}
	*/

	printf("\n�״�Ԥ���ֵΪ :\n");
	for (int i = 0; i < 9; i++) {
		printf("\n%.16e\n", PredictResult[i]);

	}

	printf("���CacheAry��\n");
	for (int i = 0; i < 9; i++) {
		printf("%.16e\n", GlobPointer->CacheAry[i]);

	}
	printf("���CacheLastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->CacheLastStatus[i]);
	}

	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);


	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}

	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}
	/*-----------------Ԥ��׼ȷ��������24��--------------*/

	printf("��23��Ԥ��׼ȷ������Ԥ���24����\n");
	PredictResult = marcovp(NULL, num + 3, 1, 0, GlobPointer);                                  //����Ԥ�� ���Ԥ����

	/*
	int Flag = 0;
	for (int i = 1; i <=  num + 3; i++) {
	for (int j = Flag; j < i * 9; j++) {
	printf("���¼��ļ���ֵ������Ԥ��׼ȷֵ%.16e!!!!!!!", GlobPointer->SourceDataAry[j]);
	printf("------%d\n", j);
	}
	Flag = Flag + 9;
	}
	*/

	printf("\n�״�Ԥ���ֵΪ :\n");
	for (int i = 0; i < 9; i++) {
		printf("\n%.16e\n", PredictResult[i]);

	}

	printf("���CacheAry��\n");
	for (int i = 0; i < 9; i++) {
		printf("%.16e\n", GlobPointer->CacheAry[i]);

	}
	printf("���CacheLastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->CacheLastStatus[i]);
	}

	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);


	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}

	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}
	/*--------------------��׼ȷ�����ݲ��ٴ�Ԥ��(24th step)----------------*/

	printf("����Ԥ�ⲻ��ȷ��24�����л��ݣ�\n");

	PredictResult = marcovp(NULL, num + 3, 1, 1, GlobPointer);

	printf("\n���ݺ��Ԥ��ֵΪ�� \n");

	for (int i = 0; i < 9; i++) {
		printf("\n%.16e\n", PredictResult[i]);

	}
	printf("���CacheAry��\n");
	for (int i = 0; i < 9; i++) {
		printf("%.16e\n", GlobPointer->CacheAry[i]);
	}

	printf("���CacheLastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->CacheLastStatus[i]);
	}

	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);
	//system("pause");

	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}


	/*----------------------------��׼ȷ��24������ѧϰ(24st Step)---------------------------------*/

	printf("\n����Ԥ�ⲻ׼ȷ����ô��һ������ѧϰ \n");
	Source[0] = -2.048813751117822E-003;
	Source[1] = 4.004778675943675E-004;
	Source[2] = 4.376575131231622E-004;
	Source[3] = -9.474301144078221E-004;
	Source[4] = -1.804036805887809E-004;
	Source[5] = -1.971520164739591E-004;
	Source[6] = 2.484093252582885E-003;
	Source[7] = -1.199679649359405E-004;
	Source[8] = -1.311054411939462E-004;

	result = marcovp(Source, num + 4, 0, 0, GlobPointer);
	/*
	int Flag = 0;
	for (int i = 1; i <= num + 4; i++) {
	for (int j = Flag; j < i * 9; j++) {
	printf("���¼��ļ���ֵ������Ԥ��׼ȷֵ%.16e!!!!!!!", GlobPointer->SourceDataAry[j]);
	printf("------%d\n", j);
	}
	Flag = Flag + 9;
	}
	*/
	printf("���LastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->LastStatus[i]);
	}
	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);

	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}


	/*-----------------��24��ѧϰ��������Ԥ���25��-------------*/

	printf("��24��Ԥ�ⲻ׼ȷ��ѧϰһ����Ԥ���25����\n");
	PredictResult = marcovp(NULL, num + 4, 1, 0, GlobPointer);
	/*
	int Flag = 0;
	for (int i = 1; i <= num + 4; i++) {
	for (int j = Flag; j < i * 9; j++) {
	printf("���¼��ļ���ֵ������Ԥ��׼ȷֵ%.16e!!!!!!!", GlobPointer->SourceDataAry[j]);
	printf("------%d\n", j);
	}
	Flag = Flag + 9;
	}
	*/
	printf("\n��%d����Ԥ��ֵ�ǣ� \n", num + 5);


	for (int i = 0; i < 9; i++) {
		printf("\n%.16e\n", PredictResult[i]);
	}


	//system("pause");
	printf("���CacheAry��\n");
	for (int i = 0; i < 9; i++) {
		printf("%.16e\n", GlobPointer->CacheAry[i]);
	}

	printf("���CacheLastStatus��\n");
	for (int i = 0; i < 9; i++) {
		printf("%d\n", GlobPointer->CacheLastStatus[i]);
	}
	printf("\n���ArrayFlag��\n%d\n", GlobPointer->ArrayFlag);

	printf("����������\n");
	counter = 0;
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->MirrorMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���������ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->MirrorProbability[8][i]);
	}
	printf("���Ԥ����ת�ƾ���\n");
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 3; j++) {
			printf("%d", GlobPointer->TransMatrix[8][i][j]);
			counter++;
			if (counter % 4 == 0) {
				printf("\n");
			}
		}
	}
	printf("���Ԥ���ĸ��ʷֲ���\n");
	for (int i = 0; i <= 3; i++) {
		printf("%d\n", GlobPointer->InitProbability[8][i]);
	}

	free(PredictResult);
	PredictResult = NULL;
	fclose(fp);
	system("pause");

	return 0;

}
