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
  제목: 종합소득세 세금 계산
  설명: 국세청 홈페이지를 참고하여 나의 종합 소득세 신고액을 계산하기
  */
#include <stdio.h> 
// atoi 함수 사용을 위해 호출
// https://dojang.io/mod/page/view.php?id=385
#include <stdlib.h>

/* 국세청 홈페이지
     https://www.nts.go.kr/nts/cm/cntnts/cntntsView.do?mi=2227&cntntsId=7667
    ※ 세율 적용 방법 : 과세표준 × 세율 - 누진공제액
    【예시】 2020년 귀속
    과세표준 30,000,000원 × 세율 15% - 1,080,000원 = 3,420,000원
 */
 
#define MAX_LEN 15

unsigned long taxBase;  	//과세표준
float taxRate; 				//세율
float plus; 				// 중간 계산 값 저장용
unsigned long progDeduct; 	//누진공제액

// 1.1 요구 사항 
void calTax(unsigned long);
int isValid(char* tmp_taxBase);

int main()
{
	int flag = 1;
	char tmp_taxBase[MAX_LEN];

	while(1){
		printf("신고할 과세표준을 입력하세요 : ");
		scanf("%s", tmp_taxBase);
		
		flag = isValid(tmp_taxBase);
		fflush(stdin);
		if(flag == 0){
			taxBase = (unsigned long)atoi(tmp_taxBase);
			break;
		}
	}
	
	calTax(taxBase);
	
	// 2.1 요구 사항 
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : 유수진\n");
    printf("------------------------------------------------------------------------\n");
    
    return 0;
}

// 3.1 요구 사항 
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
	
	printf("2020년 귀속\n");
	plus = taxBase * (taxRate / 100) - progDeduct;
	printf("과세표준 %ld원 x 세율 %.0f%% - %.ld원 = %.0f원\n", taxBase, taxRate, progDeduct, plus); 
	
}

// 숫자 입력인지 확인
// 숫자와 NULL 값이 아닌 값이 입력에 포함될 경우 재 입력 요청 
int isValid(char* tmp_taxBase){
	
	int i;

	for(i = 0; i < MAX_LEN; ++i){
		// printf("%c\n", tmp_taxBase[i]);
		// 숫자일 경우 
		if(tmp_taxBase[i] >= '0' && tmp_taxBase[i] <= '9'){

			continue; 
		}
		else if(tmp_taxBase[i] == 0){
			return 0;
		}
		// 숫자 입력이 아닌 경우 
		else{
			printf("올바른 과세표준을 입력해주세요!\n");
			return 1;
		}
	}
}

/*
프로그램 실행 결과
--------------

test0) 국세청 예시 

신고할 과세표준을 입력하세요 : 30000000

2020년 귀속

과세표준 30000000원 x 세율 15% - 1080000원 = 3420000원

------------------------------------------------------------------
test1) 과제 예시

신고할 과세표준을 입력하세요 : 125000000
2020년 귀속
과세표준 125000000원 x 세율 35% - 14900000원 = 28850000원

------------------------------------------------------------------
test2) 경계값

신고할 과세표준을 입력하세요 : 500000000
2020년 귀속
과세표준 500000000원 x 세율 40% - 25400000원 = 174600000원
신고할 과세표준을 입력하세요 : 88000000
2020년 귀속
과세표준 88000000원 x 세율 24% - 5220000원 = 15900000원
신고할 과세표준을 입력하세요 : 12000000
2020년 귀속
과세표준 12000000원 x 세율 6% - 원 = 720000원

------------------------------------------------------------------

test3) 예외처리

신고할 과세표준을 입력하세요 : -1000000
올바른 과세표준을 입력해주세요!
신고할 과세표준을 입력하세요 : @@
올바른 과세표준을 입력해주세요!
신고할 과세표준을 입력하세요 : dle
올바른 과세표준을 입력해주세요!
신고할 과세표준을 입력하세요 : 0$
올바른 과세표준을 입력해주세요!
신고할 과세표준을 입력하세요 : 0000
2020년 귀속
과세표준 0원 x 세율 6% - 원 = 0원

------------------------------------------------------------------------
written by : 유수진
------------------------------------------------------------------------

*/
