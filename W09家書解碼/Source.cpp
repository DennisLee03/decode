#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *f1, //�[�K��a���ɮ�
		*f2; //�ѱK��a�Ѥ��ɮ�
	int txt_code, // �a�Ѧr���[�K��ASCII�X
		txt_decode, // �a�Ѧr���ѱK��ASCII�X
		shift; // �a�Ѧr���[�K�H���ü� (0~5)
	int len = 1250; //�U�ǥͮa�Ѥ��e�r���`��
	fopen_s(&f1, "E64112287.txt", "r"); //�}�ҥ[�K��a���ɮצW��
	fopen_s(&f2, "decoded_letter.txt", "w"); //�}�ҸѱK��a�Ѥ��ɮצW��
	if (f1 == NULL)
	{
		printf("Cannot open w_09_code.txt\n");
		exit(0);
	}
	if (f2 == NULL)
	{
		printf("Cannot open decoded_letter.txt \n");
		exit(0);
	}
	while (fscanf(f1, "%d %d", &txt_code, &shift) != EOF) //�N�ѱK��a�ѥH�r���覡�v�@Ū�J
	{
		switch (shift)
		{
		case(0) :
			txt_decode = ~txt_code;
			break;
		case(1) :
			txt_decode = txt_code / 2;
			break;
		case(3) :
			txt_decode = txt_code / 8;
			break;
		case(5) :
			txt_decode = txt_code >> shift;
		  break;
		case(2) :
			txt_decode = txt_code - 104;
			break;
		case(4) :
			txt_decode = txt_code + 2022;
			break;
		}
		fprintf(f2, "%c", (char)txt_decode);
	}
	printf("�w���\�N�a�ѸѱK�I�Ьd�� decoded_letter.txt \n");
	fclose(f1); //�����[�K��a�Ѥ��ɮ�
	fclose(f2); //�����ѱK��a�Ѥ��ɮ�
	return(0);
}
//fprintf(f2, "%c", (char)txt_code); //�N�a�ѸѱK���e�H�r����X�覡��X�ܸѱK��a�Ѥ��ɮ�