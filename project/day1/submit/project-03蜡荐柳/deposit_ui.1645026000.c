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
  ����: ���� ���� ���� ���� ���α׷�
  ����: 1�� ���� ���� �������� �����ְ� ����� ������ �����ϴ� ���α׷�
  */

#include "./demo_ui.h"

#define DEMOAMOUNT 1000000 

// ������������ Ȯ�� https://portal.kfb.or.kr/compare/receiving_neosearch.php
// demo_ui.c���� �Ʒ� ���� ���� 

// [Req2]========================================================================
const float PreTaxRate = 1.20f; 			//�����ݸ�
const float AfterTaxRate = 1.02f; 			//���ıݸ�
const float HighestPreferRate =  1.90f; 	//�ְ���ݸ�
const float MidCancelRate = 0.33f; 			//�ߵ������ݸ�
const char InterestCalcMethod[] = "�ܸ�"; 	//���ڰ����(�ܸ�)
float MyInterestAfterTaxRate = 0.0f; 		//��������
float EstimatedAmount = 0.0f; 				//����ÿ���ݾ�
float amount = DEMOAMOUNT; 					// �� ���� ���� ���Ծ�, �ʱⰪ = �鸸�� 


int main() {
	int select;
	
	// [Req1]========================================================================
	while(1)
	{
		select = displayMenu();   // �޴� ȭ�� ���

		if(select=='4') {break;}  // 'exit'
		
		switch(select){
			case '1' : menu1(); break; // [Req3]
			case '2' : menu2(); break; // [Req4]
			case '3' : menu3(); break; // [Req5]
		}
	}
	
	// [Req6]========================================================================
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : ������\n");
    printf("------------------------------------------------------------------------\n");
    
    return 0;
}
