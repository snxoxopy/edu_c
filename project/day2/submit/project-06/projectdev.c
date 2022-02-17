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


// 4�� �� ���Ͽ� ������ ����ü�� ���� 
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
		// 2.1 �䱸 ���� 
		switch(mode){
			case '1':
				// 4.1 �䱸 ���� 
				show_project(ASCII2NUM(select));
				break;
			case '2':
				// 3.1 �䱸 ���� 
				add_project(ASCII2NUM(select));
				// printf("title = %s\n", prj[ASCII2NUM(lang)][pcnt].title);
				break;
			case '3':
				// 5.1 �䱸 ���� 
				del_project(ASCII2NUM(select));
				break;
			case '4':
				// 6.1 �䱸 ���� 
				end_project(ASCII2NUM(select));
				break;
			case '5':
				// 7.1 �䱸 ���� 
				show_end(ASCII2NUM(select)); 
				break;
		}
		
		// printf("mode = %d\n", mode);
	}
	
	// 8.1 �䱸 ���� 
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : ������\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}

// definition

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
		if(select == '9' || select == '\0'){
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

char open_project(void){
	char mode;
	printf("================================\n");
	printf("\n1: ������Ʈ ����\n");
	printf("2: ������Ʈ ����\n");
	printf("3: ������Ʈ ����\n");
	printf("4: ������Ʈ �Ϸ�\n");
	printf("5: ������Ʈ �Ϸ� ����\n\n");
	printf("================================\n");
	scanf("%c", &mode);
	fflush(stdin);
	
	while(mode < '1' || mode > '5'){
		printf("�߸��� ������ �Է��ϼ̽��ϴ�.\n");
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
	printf("%s��(��) �����ϼ̽��ϴ�.\n", ary_lang[lang]);
			
	printf("������Ʈ ������ �Է����ּ��� : ");
	scanf("%[^\n]s", buf);
	strcpy(prj[lang].title[pcnt], buf);
	memset(buf, 0, MAX_LEN * sizeof(char));
	fflush(stdin);

	printf("������Ʈ ������ �Է����ּ��� : ");
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
	printf("������Ʈ ���� �޴��� �����ϼ̽��ϴ�.\n");
	printf("%s��(��) �����ϼ̽��ϴ�.\n", ary_lang[lang]);
			
	if(cnt[lang] == 0){
		printf("������ ������Ʈ�� �����ϴ�.\n");
	}
	else{
		for(i = 0; i < cnt[lang]; ++i){
			printf("������Ʈ ����[%d] : %s\n", i, prj[lang].title[i]);
			printf("������Ʈ ����[%d] : %s\n", i, prj[lang].contents[i]);
		}
	}
}

void del_project(int lang){
	int idx_prj, mode;
	printf("----------------------------------------------------------------\n");
	while(1){
		printf("������Ʈ ���⸦ ���� ������ ������Ʈ ��ȣ�� �Է����ּ���(index�Է�)[0~]:\n");
		scanf("%d", &idx_prj);
		fflush(stdin);
		
		if((idx_prj > -1 && idx_prj < 101) && (prj[lang].contents[idx_prj][0] != '\0')){
			memset(prj[lang].title[idx_prj], 0, MAX_LEN * sizeof(char));
			memset(prj[lang].contents[idx_prj], 0, MAX_LEN * sizeof(char));
			cnt[lang] -= 1;
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			break;
		}
		else{
			printf("������Ʈ ��ȣ�� ��Ȯ�� ���ּ���!\n");
			printf("0: ���Է�\n");
			printf("1: ������Ʈ ��ȣ ����\n"); 
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
				printf("[���] 0 �Ǵ� 1�� �������ּ���!\n");
			}
		}
	}
	printf("----------------------------------------------------------------\n"); 
}

void end_project(int lang){
	int idx_prj, mode;
	printf("----------------------------------------------------------------\n");
	while(1){
		printf("������Ʈ ���⸦ ���� �Ϸ��� ������Ʈ ��ȣ�� �Է����ּ���(index�Է�): ");
		scanf("%d", &idx_prj);
		fflush(stdin);
		if((idx_prj > -1 && idx_prj < 101) && (prj[lang].contents[idx_prj][0] != '\0')){
			if(prj[lang].status[idx_prj][0] == -1){
				prj[lang].status[idx_prj][0] = 1;
				printf("������Ʈ �Ϸᰡ �Ϸ�Ǿ����ϴ�.\n");
				break;
			}
			else{
				printf("�̹� �Ϸ�� ������Ʈ�Դϴ�.\n");
				break;
			}
		}
		else{
			printf("������Ʈ ��ȣ�� ��Ȯ�� ���ּ���!\n");
			printf("0: ���Է�\n");
			printf("1: ������Ʈ ��ȣ ����\n"); 
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
				printf("[���] 0 �Ǵ� 1�� �������ּ���!\n");
			}
		}
	}
	printf("----------------------------------------------------------------\n");
}

void show_end(int lang){
	int i, cnt_end = 0;
	printf("������Ʈ �Ϸ� ���� �޴��� �����ϼ̽��ϴ�.\n");
	printf("%s��(��) �����ϼ̽��ϴ�.\n", ary_lang[lang]);
	
	if(cnt[lang] == 0){
		printf("������ ������Ʈ�� �����ϴ�.\n");
	}
	else{
		for(i = 0; i < cnt[lang]; ++i){
			if(prj[lang].status[i][0] == 1){
				printf("������Ʈ ����[%d] : %s\n", i, prj[lang].title[i]);
				printf("������Ʈ ����[%d] : %s\n", i, prj[lang].contents[i]);
				cnt_end++;
			}
		}
		if(cnt_end == 0){
			printf("��� ������Ʈ�� �Ϸ���� �ʾҽ��ϴ�.\n");
		}
	}
} 

/*
���α׷� ���� ���
--------------

*/
