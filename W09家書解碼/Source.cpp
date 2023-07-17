#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *f1, //加密後家書檔案
		*f2; //解密後家書之檔案
	int txt_code, // 家書字元加密後ASCII碼
		txt_decode, // 家書字元解密後ASCII碼
		shift; // 家書字元加密隨機亂數 (0~5)
	int len = 1250; //各學生家書內容字元總數
	fopen_s(&f1, "E64112287.txt", "r"); //開啟加密後家書檔案名稱
	fopen_s(&f2, "decoded_letter.txt", "w"); //開啟解密後家書之檔案名稱
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
	while (fscanf(f1, "%d %d", &txt_code, &shift) != EOF) //將解密後家書以字元方式逐一讀入
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
	printf("已成功將家書解密！請查看 decoded_letter.txt \n");
	fclose(f1); //關閉加密後家書之檔案
	fclose(f2); //關閉解密後家書之檔案
	return(0);
}
//fprintf(f2, "%c", (char)txt_code); //將家書解密內容以字元輸出方式輸出至解密後家書之檔案