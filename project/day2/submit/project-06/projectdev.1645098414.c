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
	
	// 8.1 �䱸 ���� 
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : ������\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}

// 1.1 �䱸 ���� 
char select_lang(void){
	char select;
	
	printf("================================\n");
	printf("������Ʈ ������ �����Ͽ� �ּ���.\n");
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
			printf("�߸��� ������ �Է��ϼ̽��ϴ�.\n");
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
	printf("\n1: ������Ʈ ����\n");
	printf("2: ������Ʈ ����\n");
	printf("3: ������Ʈ ����\n");
	printf("4: ������Ʈ �Ϸ�\n");
	printf("5: ������Ʈ �Ϸ� ����\n\n");
	printf("================================\n");
	mode = getchar();
	fflush(stdin);
	
	while(mode < '1' || mode > '5'){
		printf("�߸��� ������ �Է��ϼ̽��ϴ�.\n");
		mode = getchar();
		fflush(stdin);
	}
	
	// 2.1 �䱸 ���� 
	switch(mode){
		case '1':
			// 4.1 �䱸 ���� 
			printf("������Ʈ ���� �޴��� �����ϼ̽��ϴ�.\n");
			printf("%s�� �����ϼ̽��ϴ�.\n", ary_lang[ASCII2NUM(lang)]);
			
			
			if(cnt[ASCII2NUM(lang)] == 0){
				printf("������ ������Ʈ�� �����ϴ�.\n");
			}
			
			
			for(i = 0; i < cnt[ASCII2NUM(lang)]; ++i){
				printf("������Ʈ ����[%d] : %s\n", i, prj[ASCII2NUM(lang)][i].title);
				printf("������Ʈ ����[%d] : %s\n", i, prj[ASCII2NUM(lang)][i].contents);
			}
			break;
		case '2':
			// 3.1 �䱸 ���� 
			printf("----------------------------------------------------------------\n");
			printf("%s�� �����ϼ̽��ϴ�.\n", ary_lang[ASCII2NUM(lang)]);
			pcnt = cnt[ASCII2NUM(lang)] + 1;
			cnt[ASCII2NUM(lang)] = pcnt;
			fflush(stdout);
			
			printf("������Ʈ ������ �Է����ּ��� : ");
			scanf("%s", &(prj[ASCII2NUM(lang)][pcnt]).title);
			fflush(stdin);
			
			printf("������Ʈ ������ �Է����ּ��� : ");
			scanf("%s", &(prj[ASCII2NUM(lang)][pcnt]).contents); 
			fflush(stdin);
			
			printf("----------------------------------------------------------------\n");
			// printf("title = %s\n", prj[ASCII2NUM(lang)][pcnt].title);
			break;
	}
	
}

/*
���α׷� ���� ���
--------------

*/
