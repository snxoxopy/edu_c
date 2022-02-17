/*
The MIT License (MIT)

Copyright (c) 2015 guileschool

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/*
	����: �ؽ�Ʈ ��� UI ���� ���ø�
	����: 
*/

#include "./demo_ui.h"

// ������������ Ȯ�� https://portal.kfb.or.kr/compare/receiving_neosearch.php
extern const float PreTaxRate; 			//�����ݸ�
extern const float AfterTaxRate; 		//���ıݸ�
extern const float HighestPreferRate; 	//�ְ���ݸ�
extern const float MidCancelRate; 		//�ߵ������ݸ�
extern const char InterestCalcMethod; 	//���ڰ����(�ܸ�)
extern float MyInterestAfterTaxRate; 	//��������
extern float EstimatedAmount; 			//����ÿ���ݾ�
extern float amount; 					// �� ���� ���� ���Ծ�, �ʱⰪ = �鸸�� 


// prompt
void prompt(int xx, int yy) 
{ 
	// https://docs.microsoft.com/ko-kr/windows/console/setconsolecursorposition
	// ��ǥ�� ȭ�� ���� ���� ���� ���� ���Դϴ�. 
	COORD locate = {xx-1, yy-1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), locate); 
}

// displayMenu
int displayMenu(void)
{
	int select = 0;
	int i;
	char subMenu[][30] = { "���� ���� ��� ������ Ȯ��\n", "���� ���� ���ͷ� Ȯ��\n", "���� ���� �����ϱ�\n", "�����ϱ�\n" };

	system("cls");
	for(i=0; i < 4; i++){
		prompt(30, 4+i*2);
		printf("%2d. %s", i+1, subMenu[i]);
	}
	while(select < '1' || select > '4'){
		prompt(25, 17);printf("* ���Ͻô� �޴��� �����ϼ��� : _\b");
		select = getchar();
		fflush(stdin);
	}
	return(select);
}

// menu1
void menu1(void)
{	
	int i;
	// �ʱⰪ �鸸���� �������� ���� ����� �Է� ���� �ݿ��Ͽ� ����Ѵ�. 
	system("cls");
	prompt(1, 8); printf("���� ���� ��� ������ Ȯ��\n");
	prompt(1, 10); printf("�����ݸ� ���ıݸ� �ְ���ݸ� �ߵ������ݸ� ���ڰ����\n\n");
	calAmount();
	for(i = 0; i<80; ++i)printf("-");
	
	printf("\n\n%6.2f %7.2f %12.2f %15.2f %8s\n", PreTaxRate, AfterTaxRate, HighestPreferRate, MidCancelRate, &InterestCalcMethod);
	prompt(20, 20); printf("# �ƹ�Ű�� �Է��ϸ� ���� �޴��� ���ư��ϴ�");
	getch();
}

// menu2
void menu2(void)
{
	int i;
	
	system("cls");
	prompt(1, 8); printf("���� ���� ���ͷ� Ȯ��(%.0f �� �Ա� ����)\n\n\n", amount);
	calAmount();
	printf("�����ݸ� ���ıݸ� �ְ���ݸ� �ߵ������ݸ� ���ڰ���� �������� ����ÿ���ݾ�\n\n");
	for(i = 0; i<80; ++i)printf("-");
	
	printf("\n\n%6.2f %7.2f %12.2f %15.2f %8s %12.0f %12.0f\n", PreTaxRate, AfterTaxRate, HighestPreferRate, MidCancelRate, &InterestCalcMethod, MyInterestAfterTaxRate, EstimatedAmount);
	prompt(20, 20); printf("# �ƹ�Ű�� �Է��ϸ� ���� �޴��� ���ư��ϴ�");
	getch();
}

// menu3
void menu3(void)
{
	// init.
	int flag;
	char ch;
	
	// check amount 
	while(flag){
		system("cls");
		prompt(1, 8);printf("���Ͻô� ���� �׼��� �Է��ϼ���: ");
		scanf("%f", &amount);
		system("cls");
		prompt(1, 8);printf("����ݾ� %.0f ��\n\n", amount);
		printf("�Է��Ͻ� ������ �½��ϱ�(y/n)? "); // ���� �Է� ������� ����� Ȯ�� 
		ch = getch();
		// check 'y' or 'n'
		while(1){
			if(ch == 'y'){
				flag = 0;
				break;
			}
			else if(ch == 'n'){
				flag = 1;
				break;
			}
			else{
				printf("\ny �Ǵ� n�� �Է��ϼ���!");
				ch = getch();
			}
		}

	}
	
	// calculate amount and display results
	if(!flag){
		menu2();
	}
}

void calAmount(void){
	MyInterestAfterTaxRate = AfterTaxRate / 100 * amount;
	EstimatedAmount = MyInterestAfterTaxRate + amount;
}
