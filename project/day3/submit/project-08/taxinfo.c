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
  ����: ���ռҵ漼 ���� ���
  ����: ����û Ȩ�������� �����Ͽ� ���� ���� �ҵ漼 �Ű���� ����ϱ�
  */
#include <stdio.h> 
// atoi �Լ� ����� ���� ȣ��
// https://dojang.io/mod/page/view.php?id=385
#include <stdlib.h>

/* ����û Ȩ������
     https://www.nts.go.kr/nts/cm/cntnts/cntntsView.do?mi=2227&cntntsId=7667
    �� ���� ���� ��� : ����ǥ�� �� ���� - ����������
    �����á� 2020�� �ͼ�
    ����ǥ�� 30,000,000�� �� ���� 15% - 1,080,000�� = 3,420,000��
 */
 
#define MAX_LEN 15

unsigned long taxBase;  	//����ǥ��
float taxRate; 				//����
float plus; 				// �߰� ��� �� �����
unsigned long progDeduct; 	//����������

// 1.1 �䱸 ���� 
void calTax(unsigned long);
int isValid(char* tmp_taxBase);

int main()
{
	int flag = 1;
	char tmp_taxBase[MAX_LEN];

	while(1){
		printf("�Ű��� ����ǥ���� �Է��ϼ��� : ");
		scanf("%s", tmp_taxBase);
		
		flag = isValid(tmp_taxBase);
		fflush(stdin);
		if(flag == 0){
			taxBase = (unsigned long)atoi(tmp_taxBase);
			break;
		}
	}
	
	calTax(taxBase);
	
	// 2.1 �䱸 ���� 
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : ������\n");
    printf("------------------------------------------------------------------------\n");
    
    return 0;
}

// 3.1 �䱸 ���� 
void calTax(unsigned long taxBase){
	
	taxRate = 42;
	progDeduct = 35400000;
	
	// find taxRate and progDeduct
	if(taxBase <= 500000000){
		taxRate -= 2;
		progDeduct -= 10000000;
	}
	if(taxBase <= 300000000){
		taxRate -= 2;
		progDeduct -= 6000000;
	}
	if(taxBase <= 150000000){
		taxRate -= 3;
		progDeduct -= 4500000;
	}
	if(taxBase <= 88000000){
		taxRate -= 11;
		progDeduct -= 9680000;
	}
	if(taxBase <= 46000000){
		taxRate -= 9;
		progDeduct -= 4140000;
	}
	if(taxBase <= 12000000){
		taxRate -= 9;
		progDeduct = 0;
	}
	
	printf("2020�� �ͼ�\n");
	plus = taxBase * (taxRate / 100) - progDeduct;
	printf("����ǥ�� %ld�� x ���� %.0f%% - %.ld�� = %.0f��\n", taxBase, taxRate, progDeduct, plus); 
	
}

// ���� �Է����� Ȯ��
// ���ڿ� NULL ���� �ƴ� ���� �Է¿� ���Ե� ��� �� �Է� ��û 
int isValid(char* tmp_taxBase){
	
	int i;

	for(i = 0; i < MAX_LEN; ++i){
		// printf("%c\n", tmp_taxBase[i]);
		// ������ ��� 
		if(tmp_taxBase[i] >= '0' && tmp_taxBase[i] <= '9'){

			continue; 
		}
		else if(tmp_taxBase[i] == 0){
			return 0;
		}
		// ���� �Է��� �ƴ� ��� 
		else{
			printf("�ùٸ� ����ǥ���� �Է����ּ���!\n");
			return 1;
		}
	}
}

/*
���α׷� ���� ���
--------------

test0) ����û ���� 

�Ű��� ����ǥ���� �Է��ϼ��� : 30000000

2020�� �ͼ�

����ǥ�� 30000000�� x ���� 15% - 1080000�� = 3420000��

------------------------------------------------------------------
test1) ���� ����

�Ű��� ����ǥ���� �Է��ϼ��� : 125000000
2020�� �ͼ�
����ǥ�� 125000000�� x ���� 35% - 14900000�� = 28850000��

------------------------------------------------------------------
test2) ��谪

�Ű��� ����ǥ���� �Է��ϼ��� : 500000000
2020�� �ͼ�
����ǥ�� 500000000�� x ���� 40% - 25400000�� = 174600000��
�Ű��� ����ǥ���� �Է��ϼ��� : 88000000
2020�� �ͼ�
����ǥ�� 88000000�� x ���� 24% - 5220000�� = 15900000��
�Ű��� ����ǥ���� �Է��ϼ��� : 12000000
2020�� �ͼ�
����ǥ�� 12000000�� x ���� 6% - �� = 720000��

------------------------------------------------------------------

test3) ����ó��

�Ű��� ����ǥ���� �Է��ϼ��� : -1000000
�ùٸ� ����ǥ���� �Է����ּ���!
�Ű��� ����ǥ���� �Է��ϼ��� : @@
�ùٸ� ����ǥ���� �Է����ּ���!
�Ű��� ����ǥ���� �Է��ϼ��� : dle
�ùٸ� ����ǥ���� �Է����ּ���!
�Ű��� ����ǥ���� �Է��ϼ��� : 0$
�ùٸ� ����ǥ���� �Է����ּ���!
�Ű��� ����ǥ���� �Է��ϼ��� : 0000
2020�� �ͼ�
����ǥ�� 0�� x ���� 6% - �� = 0��

------------------------------------------------------------------------
written by : ������
------------------------------------------------------------------------

*/
