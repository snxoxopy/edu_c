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
	제목: 텍스트 기반 UI 생성 템플릿
	설명: 
*/

#include "./demo_ui.h"

// 전국은행고시율 확인 https://portal.kfb.or.kr/compare/receiving_neosearch.php
extern const float PreTaxRate; 			//세전금리
extern const float AfterTaxRate; 		//세후금리
extern const float HighestPreferRate; 	//최고우대금리
extern const float MidCancelRate; 		//중도해지금리
extern const char InterestCalcMethod; 	//이자계산방식(단리)
extern float MyInterestAfterTaxRate; 	//세후이자
extern float EstimatedAmount; 			//만기시예상금액
extern float amount; 					// 고객 정기 예금 가입액, 초기값 = 백만원 


// prompt
void prompt(int xx, int yy) 
{ 
	// https://docs.microsoft.com/ko-kr/windows/console/setconsolecursorposition
	// 좌표는 화면 버퍼 문자 셀의 열과 행입니다. 
	COORD locate = {xx-1, yy-1}; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), locate); 
}

// displayMenu
int displayMenu(void)
{
	int select = 0;
	int i;
	char subMenu[][30] = { "은행 현재 고시 이자율 확인\n", "나의 예상 수익률 확인\n", "정기 예금 가입하기\n", "종료하기\n" };

	system("cls");
	for(i=0; i < 4; i++){
		prompt(30, 4+i*2);
		printf("%2d. %s", i+1, subMenu[i]);
	}
	while(select < '1' || select > '4'){
		prompt(25, 17);printf("* 원하시는 메뉴를 선택하세요 : _\b");
		select = getchar();
		fflush(stdin);
	}
	return(select);
}

// menu1
void menu1(void)
{	
	int i;
	// 초기값 백만원을 기준으로 이후 사용자 입력 값을 반영하여 출력한다. 
	system("cls");
	prompt(1, 8); printf("은행 현재 고시 이자율 확인\n");
	prompt(1, 10); printf("세전금리 세후금리 최고우대금리 중도해지금리 이자계산방식\n\n");
	calAmount();
	for(i = 0; i<80; ++i)printf("-");
	
	printf("\n\n%6.2f %7.2f %12.2f %15.2f %8s\n", PreTaxRate, AfterTaxRate, HighestPreferRate, MidCancelRate, &InterestCalcMethod);
	prompt(20, 20); printf("# 아무키나 입력하면 메인 메뉴로 돌아갑니다");
	getch();
}

// menu2
void menu2(void)
{
	int i;
	
	system("cls");
	prompt(1, 8); printf("나의 예상 수익률 확인(%.0f 원 입금 기준)\n\n\n", amount);
	calAmount();
	printf("세전금리 세후금리 최고우대금리 중도해지금리 이자계산방식 세후이자 만기시예상금액\n\n");
	for(i = 0; i<80; ++i)printf("-");
	
	printf("\n\n%6.2f %7.2f %12.2f %15.2f %8s %12.0f %12.0f\n", PreTaxRate, AfterTaxRate, HighestPreferRate, MidCancelRate, &InterestCalcMethod, MyInterestAfterTaxRate, EstimatedAmount);
	prompt(20, 20); printf("# 아무키나 입력하면 메인 메뉴로 돌아갑니다");
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
		prompt(1, 8);printf("원하시는 예금 액수를 입력하세요: ");
		scanf("%f", &amount);
		system("cls");
		prompt(1, 8);printf("예약금액 %.0f 원\n\n", amount);
		printf("입력하신 내용이 맞습니까(y/n)? "); // 문자 입력 방지대신 사용자 확인 
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
				printf("\ny 또는 n을 입력하세요!");
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
