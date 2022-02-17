#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define Python 	0
//#define C 		1
//#define Cpp 	2
//#define Java 	3

#define ASCII2NUM(x) (x-48)

char select_lang(void); 
void open_project(char);
char ary_lang[][6] = {"Python", "C", "Cpp", "Java"};
enum languages{ python = '0', c, cpp, java};

typedef struct _INFO_PRJ{
	char title[50];
	char contents[50];
}info_project;

int main() 
{
	char select;
	char mode;

	while(1)
	{
		select = select_lang();
		
		if(select == '9'){
			break;
		}
		
		switch(select){
			case python : open_project(select); break;
		}
		// printf("mode = %d\n", mode);
	}
	
	// 8.1 요구 사항 
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : 유수진\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}

// 1.1 요구 사항 
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
		if(select == '9'){
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

void open_project(char lang){
	char mode, buffer[100];
	info_project* prj[5];
	int i, pcnt;
	static int cnt[5] = {0, 0, 0, 0, 0};
	
	printf("================================\n");
	printf("\n1: 프로젝트 보기\n");
	printf("2: 프로젝트 생성\n");
	printf("3: 프로젝트 삭제\n");
	printf("4: 프로젝트 완료\n");
	printf("5: 프로젝트 완료 보기\n\n");
	printf("================================\n");
	mode = getchar();
	fflush(stdin);
	
	while(mode < '1' || mode > '5'){
		printf("잘못된 종류를 입력하셨습니다.\n");
		mode = getchar();
		fflush(stdin);
	}
	
	// 2.1 요구 사항 
	switch(mode){
		case '1':
			// 4.1 요구 사항 
			printf("프로젝트 보기 메뉴를 선택하셨습니다.\n");
			printf("%s를 선택하셨습니다.\n", ary_lang[ASCII2NUM(lang)]);
			
			
			if(cnt[ASCII2NUM(lang)] == 0){
				printf("생성된 프로젝트가 없습니다.\n");
			}
			
			
			for(i = 0; i < cnt[ASCII2NUM(lang)]; ++i){
				printf("프로젝트 제목[%d] : %s\n", i, prj[ASCII2NUM(lang)][i].title);
				printf("프로젝트 내용[%d] : %s\n", i, prj[ASCII2NUM(lang)][i].contents);
			}
			break;
		case '2':
			// 3.1 요구 사항 
			printf("----------------------------------------------------------------\n");
			printf("%s를 선택하셨습니다.\n", ary_lang[ASCII2NUM(lang)]);
			pcnt = cnt[ASCII2NUM(lang)] + 1;
			cnt[ASCII2NUM(lang)] = pcnt;
			fflush(stdout);
			
			printf("프로젝트 제목을 입력해주세요 : ");
			scanf("%s", &(prj[ASCII2NUM(lang)][pcnt]).title);
			fflush(stdin);
			
			printf("프로젝트 내용을 입력해주세요 : ");
			scanf("%s", &(prj[ASCII2NUM(lang)][pcnt]).contents); 
			fflush(stdin);
			
			printf("----------------------------------------------------------------\n");
			// printf("title = %s\n", prj[ASCII2NUM(lang)][pcnt].title);
			break;
	}
	
}

/*
프로그램 실행 결과
--------------

*/
