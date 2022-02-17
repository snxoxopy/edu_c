#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define Python 	0
//#define C 		1
//#define Cpp 	2
//#define Java 	3

#define ASCII2NUM(x) (x-48)
#define MAX_LEN 100

// declaration
char select_lang(void); 
char open_project(void);
void add_project(int);
void show_project(int lang);
void del_project(int lang);
void end_project(int lang);
void show_end(int lang);

char ary_lang[][7] = {"Python\0", "C\0", "Cpp\0", "Java\0"};
static int cnt[5] = {0, 0, 0, 0, 0};
enum languages{ python = '0', c, cpp, java};


// 4개 언어에 대하여 각각의 구조체를 선언 
typedef struct _INFO_PRJ{
	char title[MAX_LEN][MAX_LEN];
	char contents[MAX_LEN][MAX_LEN];
	int status[MAX_LEN][1]; // -1 = open, 1 = closed
}info_project;

info_project prj[4];

int main() 
{
	char select, mode;
	int i;

	while(1)
	{
		select = select_lang();
		if(select == '9'){ break; }
		
		// select language
		switch(select){
			case python:
				mode = open_project();
				break;
			case c:
				mode = open_project();
				break;
			case cpp:
				mode = open_project();
				break;
			case java:
				mode = open_project();
				break;
		}
		
		//test
		//printf("mode = %c", mode);
		
		// select program
		// 2.1 요구 사항 
		switch(mode){
			case '1':
				// 4.1 요구 사항 
				show_project(ASCII2NUM(select));
				break;
			case '2':
				// 3.1 요구 사항 
				add_project(ASCII2NUM(select));
				// printf("title = %s\n", prj[ASCII2NUM(lang)][pcnt].title);
				break;
			case '3':
				// 5.1 요구 사항 
				del_project(ASCII2NUM(select));
				break;
			case '4':
				// 6.1 요구 사항 
				end_project(ASCII2NUM(select));
				break;
			case '5':
				// 7.1 요구 사항 
				show_end(ASCII2NUM(select)); 
				break;
		}
		
		// printf("mode = %d\n", mode);
	}
	
	// 8.1 요구 사항 
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : 유수진\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}

// definition

char select_lang(void){
	char select;
	
	printf("================================\n");
	printf("프로젝트 종류를 선택하여 주세요.\n");
	printf("0: Python\n");
	printf("1: C\n");
	printf("2: C++\n");
	printf("3: Java\n");
	printf("\n9: Quit\n");
	printf("================================\n");
	scanf("%c", &select);
	
	while(select < '0' || select > '4'){
		if(select == '9' || select == '\0'){
			break;
		}
		else{
			printf("잘못된 종류를 입력하셨습니다.\n");
			scanf("%c", &select);
		}
	}
	fflush(stdin);
	return select;
}

char open_project(void){
	char mode;
	printf("================================\n");
	printf("\n1: 프로젝트 보기\n");
	printf("2: 프로젝트 생성\n");
	printf("3: 프로젝트 삭제\n");
	printf("4: 프로젝트 완료\n");
	printf("5: 프로젝트 완료 보기\n\n");
	printf("================================\n");
	scanf("%c", &mode);
	fflush(stdin);
	
	while(mode < '1' || mode > '5'){
		printf("잘못된 종류를 입력하셨습니다.\n");
		scanf("%c", &mode);
	}
	fflush(stdin);
	return mode;
}

void add_project(int lang){
	int i;
	int pcnt ;
	char buf[MAX_LEN];		

	pcnt = cnt[lang];
	printf("----------------------------------------------------------------\n");
	printf("%s을(를) 선택하셨습니다.\n", ary_lang[lang]);
			
	printf("프로젝트 제목을 입력해주세요 : ");
	scanf("%[^\n]s", buf);
	strcpy(prj[lang].title[pcnt], buf);
	memset(buf, 0, MAX_LEN * sizeof(char));
	fflush(stdin);

	printf("프로젝트 내용을 입력해주세요 : ");
	scanf("%[^\n]s", buf);
	strcpy(prj[lang].contents[pcnt], buf); 
	memset(buf, 0, MAX_LEN * sizeof(char));
	fflush(stdin);
	
	prj[lang].status[pcnt][0] = -1; 
	
	//test
	//if(prj[0].contents[3][0] == '\0'){
	//	printf("empty contents = %s\n", prj[0].contents[3]);
	//}
	
	pcnt = cnt[lang] + 1;
	cnt[lang] = pcnt;
	
	printf("----------------------------------------------------------------\n");
		
}

void show_project(int lang){
	int i;
	printf("프로젝트 보기 메뉴를 선택하셨습니다.\n");
	printf("%s을(를) 선택하셨습니다.\n", ary_lang[lang]);
			
	if(cnt[lang] == 0){
		printf("생성된 프로젝트가 없습니다.\n");
	}
	else{
		for(i = 0; i < cnt[lang]; ++i){
			printf("프로젝트 제목[%d] : %s\n", i, prj[lang].title[i]);
			printf("프로젝트 내용[%d] : %s\n", i, prj[lang].contents[i]);
		}
	}
}

void del_project(int lang){
	int idx_prj, mode;
	printf("----------------------------------------------------------------\n");
	while(1){
		printf("프로젝트 보기를 통해 삭제할 프로젝트 번호를 입력해주세요(index입력)[0~]:\n");
		scanf("%d", &idx_prj);
		fflush(stdin);
		
		if((idx_prj > -1 && idx_prj < 101) && (prj[lang].contents[idx_prj][0] != '\0')){
			memset(prj[lang].title[idx_prj], 0, MAX_LEN * sizeof(char));
			memset(prj[lang].contents[idx_prj], 0, MAX_LEN * sizeof(char));
			cnt[lang] -= 1;
			printf("삭제가 완료되었습니다.\n");
			break;
		}
		else{
			printf("프로젝트 번호를 재확인 해주세요!\n");
			printf("0: 재입력\n");
			printf("1: 프로젝트 번호 보기\n"); 
			scanf("%d", &mode);
			fflush(stdin);
			if(mode == 0){
				del_project(lang);
				break;
			}
			else if(mode == 1){
				show_project(lang);
				break;
			}
			else{
				printf("[경고] 0 또는 1을 선택해주세요!\n");
			}
		}
	}
	printf("----------------------------------------------------------------\n"); 
}

void end_project(int lang){
	int idx_prj, mode;
	printf("----------------------------------------------------------------\n");
	while(1){
		printf("프로젝트 보기를 통해 완료할 프로젝트 번호를 입력해주세요(index입력): ");
		scanf("%d", &idx_prj);
		fflush(stdin);
		if((idx_prj > -1 && idx_prj < 101) && (prj[lang].contents[idx_prj][0] != '\0')){
			if(prj[lang].status[idx_prj][0] == -1){
				prj[lang].status[idx_prj][0] = 1;
				printf("프로젝트 완료가 완료되었습니다.\n");
				break;
			}
			else{
				printf("이미 완료된 프로젝트입니다.\n");
				break;
			}
		}
		else{
			printf("프로젝트 번호를 재확인 해주세요!\n");
			printf("0: 재입력\n");
			printf("1: 프로젝트 번호 보기\n"); 
			scanf("%d", &mode);
			fflush(stdin);
			if(mode == 0){
				end_project(lang);
				break;
			}
			else if(mode == 1){
				show_project(lang);
				break;
			}
			else{
				printf("[경고] 0 또는 1을 선택해주세요!\n");
			}
		}
	}
	printf("----------------------------------------------------------------\n");
}

void show_end(int lang){
	int i, cnt_end = 0;
	printf("프로젝트 완료 보기 메뉴를 선택하셨습니다.\n");
	printf("%s을(를) 선택하셨습니다.\n", ary_lang[lang]);
	
	if(cnt[lang] == 0){
		printf("생성된 프로젝트가 없습니다.\n");
	}
	else{
		for(i = 0; i < cnt[lang]; ++i){
			if(prj[lang].status[i][0] == 1){
				printf("프로젝트 제목[%d] : %s\n", i, prj[lang].title[i]);
				printf("프로젝트 내용[%d] : %s\n", i, prj[lang].contents[i]);
				cnt_end++;
			}
		}
		if(cnt_end == 0){
			printf("모든 프로젝트가 완료되지 않았습니다.\n");
		}
	}
} 

/*
프로그램 실행 결과
--------------

*/
