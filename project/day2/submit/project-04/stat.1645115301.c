#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_NAME 9
#define MAX_FIVE 5 

void profile(void);
void average(void);
void multiple(void);

void my_gets(char* ps, int size);
int is_exist(int* ary, int num, int cnt);

struct db_info {
	char name[MAX_LEN_NAME];
	int age;
	float height;
} info;

int main(void)
{
	// 1.1 �䱸 ����
	profile();   // �̸�, ����, Ű�� �Է��Ͽ� ����Ѵ�. 9�� �Է� �׽�Ʈ�غ��� 

	
	// 2.1 �䱸 ����
	average();   // Ű����� �Է��� ������ �� ����� ����Ѵ�.

	// 3.1 �䱸 ���� 
	multiple();  // ����� �Է��Ͽ� 2�� ����� 3�� ����� ���� �Ŀ� ����Ѵ�.
	
	// 4.1 �䱸 ����
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : ������\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}

// Ű����� �̸�, ����, Ű�� �Է��Ͽ� ����Ѵ�.
// �̸��� ����θ� �ִ� 9�ڱ��� �Է��ϸ� �߰��� ������ �������� �ʴ´�.
// �̸��� 9�� �̳��θ� �Է��Ѵٰ� �����ϸ� �Ѵ� ��쿡 ���� ����ó���� ���� �ʴ´�.
// ���̴� ������, Ű�� �Ҽ����� ����� �Ǽ��� �Է��ϸ� �� �̿��� �Է¿� ���� ����ó���� ���� �ʴ´�.
// my_gets �Լ��� �����Ͽ� ������ ������ �̸��� �Է��� ��� ������ �ο�
void profile(void)
{
    // ���� �ۼ�Ű 
    printf("> �̸�: ");
    my_gets(info.name, MAX_LEN_NAME);
    fflush(stdin);
	printf("> ����: ");
	scanf("%d", &(info.age));
	printf("> Ű: ");
	scanf("%f", &(info.height)); 
	printf("[%s %d�� %.1fcm]\n", info.name, info.age, info.height);
}

// Ű����� 0�� ������ ����� �Է��Ͽ� �迭�� �����Ѵ�.
// ������ �ԷµǸ� �Է��� �ߴ��ϰ� �� ������ �Է��� ��� ����� ����� ����Ѵ�.
// ����� �ִ� 5������ �Է��ϸ� 5���� ��� �Էµ� ��� �Է��� �ڵ� �ߴ��Ѵ�.
// ������ �Է��ϴ� ������ �����ϸ� �� �̿��� �Է¿� ���� ����ó���� ���� �ʴ´�.
void average(void)
{
    // ���� �ۼ�
    int i, cnt = 0, num[MAX_FIVE];
    float avg = 0;
    
    for(i = 0; i < sizeof(num)/sizeof(num[0]); ++i){
    	printf("> ��� �Է� : ");
    	scanf("%d", &(num[i]));
    	if(num[i] < 0){
    		num[i] = '\n';
			break;
		}
		cnt++;
	}
	printf("# �Է��� ��� : ");
	for(i = 0; i < cnt; ++i){
		printf("%3d", num[i]);
		avg += num[i];
	}
	avg = avg / cnt;
    printf("\n# ��� : %.1f\n", avg);
}

// Ű����� 0�� ������ ����� �Է��Ͽ� �迭�� �����Ѵ�.
// 2�� ����� 2�� ��� �迭��, 3�� ����� 3�� ��� �迭�� �����Ѵ�.
// 2�� ����̰� 3�� ����̸� 2�� ��� �迭�� 3�� ��� �迭�� ��� �����Ѵ�.
// 2�� ����� �ƴϰ� 3�� ����� �ƴϸ� �ٽ� �Է��Ѵ�.
// �Է��� ����� 2�� ��� �Ǵ� 3�� ����̸� �̹� �Է��� ���� �ٽ� �������� �ʴ´�.
// 2�� ����� 3�� ����� ���� �ִ� 5������ �Է��Ѵٰ� �����ϸ� 5���� �Ѵ� ��� ����ó���� ���� �ʴ´�.
// ������ �ԷµǸ� �� ������ �Է��� 2�� ����� 3�� ����� ��� ����Ѵ�.
// is_exist �Լ��� �����Ͽ� �迭�� ���� ���� �ִ��� �˻��ϴ� ��� ������ �ο�
void multiple(void)
{
    // ���� �ۼ�
    int i = 0, j = 0, k, num, ary_mulof2[MAX_FIVE], ary_mulof3[MAX_FIVE];
    
	while(1){
		printf("> ��� �Է� : ");
		scanf("%d", &num);
		
		// exit 
		if(num < 0 || (i == MAX_FIVE && j == MAX_FIVE)){
			printf("# 2�� ���...\n");
			for(k = 0; k < i; ++k){
				printf("%3d", ary_mulof2[k]);
			}
			printf("\n# 3�� ���...\n");
			for(k = 0; k < j; ++k){
				printf("%3d", ary_mulof3[k]);
			}
			break;
		}
		
		// add multiple of 2
		if(num % 2 == 0){
			if(i < MAX_FIVE){
				if(is_exist(ary_mulof2, num, i)){
					printf("# �Էµ� ���� �ֽ��ϴ�!(2�� ���)\n");
				}else{
					ary_mulof2[i] = num;
					i++;
					//printf("i = %d\n", i); // test
				}
			}
		}
		
		// add multiple of 3
		if(num % 3 == 0){
			if(j < MAX_FIVE){
				if(is_exist(ary_mulof3, num, j)){
					printf("# �Էµ� ���� �ֽ��ϴ�!(3�� ���)\n");
				}else{
					ary_mulof3[j] = num;
					j++;
					//printf("j = %d\n", j); //test
				}
			}
		}
	}
    
}

// char �迭�� ������ ������ ���ڿ��� �Է��ϴ� �Լ�
// ps�� �迭�� �μ��� �޴� ������
// size�� �迭�� ũ�⸦ �μ��� ������ �Է� ���ڿ��� ���̰� size�̻��� ��� size-1������ �Է��Ѵ�.
void my_gets(char* ary, int size)
{
    // ���� �ۼ�
    int i;
    char ch;
    fflush(stdin);
    
    for(i = 0; i < size; ++i){
    	ch = getchar();
    	if(ch == '\n'){
    		break;
		}else{
			ary[i] = ch;
		}
	}
}

// �迭�� num���� �����ϴ��� Ȯ���ϴ� �Լ�, ������ 1, ������ 0 ��ȯ
// ary : ã�� �迭�� �μ��� ����, num : ã�� ��, cnt : ���� �迭�� ����� ���� ��
int is_exist(int *ary, int num, int cnt)
{
	int k;
    // ���� �ۼ�
    for(k = 0; k < cnt; k++){
		if(ary[k] == num){
			return 1;
		}
	}
	return 0;
}

/*
���α׷� ���� ���
--------------

*/
