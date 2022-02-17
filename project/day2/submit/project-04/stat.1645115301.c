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
	// 1.1 요구 사항
	profile();   // 이름, 나이, 키를 입력하여 출력한다. 9개 입력 테스트해보기 

	
	// 2.1 요구 사항
	average();   // 키보드로 입력한 양수들과 그 평균을 출력한다.

	// 3.1 요구 사항 
	multiple();  // 양수를 입력하여 2의 배수와 3의 배수로 나눈 후에 출력한다.
	
	// 4.1 요구 사항
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : 유수진\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}

// 키보드로 이름, 나이, 키를 입력하여 출력한다.
// 이름은 영어로만 최대 9자까지 입력하며 중간에 공백을 포함하지 않는다.
// 이름을 9자 이내로만 입력한다고 가정하며 넘는 경우에 대한 예외처리는 하지 않는다.
// 나이는 정수로, 키는 소수점을 사용한 실수로 입력하며 그 이외의 입력에 대한 예외처리는 하지 않는다.
// my_gets 함수를 구현하여 공백을 포함한 이름을 입력한 경우 가산점 부여
void profile(void)
{
    // 여기 작성키 
    printf("> 이름: ");
    my_gets(info.name, MAX_LEN_NAME);
    fflush(stdin);
	printf("> 나이: ");
	scanf("%d", &(info.age));
	printf("> 키: ");
	scanf("%f", &(info.height)); 
	printf("[%s %d세 %.1fcm]\n", info.name, info.age, info.height);
}

// 키보드로 0을 포함한 양수를 입력하여 배열에 저장한다.
// 음수가 입력되면 입력을 중단하고 그 때까지 입력한 모든 양수와 평균을 출력한다.
// 양수는 최대 5개까지 입력하며 5개가 모두 입력된 경우 입력을 자동 중단한다.
// 정수를 입력하는 것으로 가정하며 그 이외의 입력에 대한 예외처리는 하지 않는다.
void average(void)
{
    // 여기 작성
    int i, cnt = 0, num[MAX_FIVE];
    float avg = 0;
    
    for(i = 0; i < sizeof(num)/sizeof(num[0]); ++i){
    	printf("> 양수 입력 : ");
    	scanf("%d", &(num[i]));
    	if(num[i] < 0){
    		num[i] = '\n';
			break;
		}
		cnt++;
	}
	printf("# 입력한 양수 : ");
	for(i = 0; i < cnt; ++i){
		printf("%3d", num[i]);
		avg += num[i];
	}
	avg = avg / cnt;
    printf("\n# 평균 : %.1f\n", avg);
}

// 키보드로 0을 포함한 양수를 입력하여 배열에 저장한다.
// 2의 배수는 2의 배수 배열에, 3의 배수는 3의 배수 배열에 저장한다.
// 2의 배수이고 3의 배수이면 2의 배수 배열과 3의 배수 배열에 모두 저장한다.
// 2의 배수도 아니고 3의 배수도 아니면 다시 입력한다.
// 입력한 양수가 2의 배수 또는 3의 배수이며 이미 입력한 경우는 다시 저장하지 않는다.
// 2의 배수와 3의 배수는 각각 최대 5개까지 입력한다고 가정하며 5개를 넘는 경우 예외처리는 하지 않는다.
// 음수가 입력되면 그 때까지 입력한 2의 배수와 3의 배수를 모두 출력한다.
// is_exist 함수를 구현하여 배열에 같은 값이 있는지 검사하는 경우 가산점 부여
void multiple(void)
{
    // 여기 작성
    int i = 0, j = 0, k, num, ary_mulof2[MAX_FIVE], ary_mulof3[MAX_FIVE];
    
	while(1){
		printf("> 양수 입력 : ");
		scanf("%d", &num);
		
		// exit 
		if(num < 0 || (i == MAX_FIVE && j == MAX_FIVE)){
			printf("# 2의 배수...\n");
			for(k = 0; k < i; ++k){
				printf("%3d", ary_mulof2[k]);
			}
			printf("\n# 3의 배수...\n");
			for(k = 0; k < j; ++k){
				printf("%3d", ary_mulof3[k]);
			}
			break;
		}
		
		// add multiple of 2
		if(num % 2 == 0){
			if(i < MAX_FIVE){
				if(is_exist(ary_mulof2, num, i)){
					printf("# 입력된 값이 있습니다!(2의 배수)\n");
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
					printf("# 입력된 값이 있습니다!(3의 배수)\n");
				}else{
					ary_mulof3[j] = num;
					j++;
					//printf("j = %d\n", j); //test
				}
			}
		}
	}
    
}

// char 배열에 공백을 포함한 문자열을 입력하는 함수
// ps는 배열을 인수로 받는 포인터
// size는 배열의 크기를 인수로 받으며 입력 문자열의 길이가 size이상인 경우 size-1까지만 입력한다.
void my_gets(char* ary, int size)
{
    // 여기 작성
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

// 배열에 num값이 존재하는지 확인하는 함수, 있으면 1, 없으면 0 반환
// ary : 찾을 배열을 인수로 받음, num : 찾을 값, cnt : 현재 배열에 저장된 값의 수
int is_exist(int *ary, int num, int cnt)
{
	int k;
    // 여기 작성
    for(k = 0; k < cnt; k++){
		if(ary[k] == num){
			return 1;
		}
	}
	return 0;
}

/*
프로그램 실행 결과
--------------

*/
