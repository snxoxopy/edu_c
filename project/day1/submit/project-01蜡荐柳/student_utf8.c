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
  제목: 구조체를 사용하여 학생 5명의 정보를 저장하는 프로그램
  설명: 학생이름, 클래스명, 번호등을 저장하고 있는 구조체 배열에 사용자 정보를 입력하는 프로그램
  */

#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 5
#define MAX_INFO 3

struct student {
	char firstName[50]; // 학생 이름
	int classNumber; // 반 번호(예. 1, 2)
	int studentNumber; // 학생 번호
} s[5];

enum info_student {str_name, num_class, num_number};

int main() {
	
	// initialization
	int i, j;
	
	// scanf student s[i]
	for(i = 0; i < MAX_STUDENTS; ++i){
		printf("%d번째 학생 정보 입력\n", i + 1);
		for(j = 0; j < MAX_INFO; ++j){
			switch (j){
				case str_name:
					printf("이름: ");
					scanf("%s", s[i].firstName);
					break;
				case num_class:
					printf("클래스 번호: ");
					scanf("%d", &(s[i].classNumber));
					break;
				case num_number:
					printf("학생 번호: ");
					scanf("%d", &(s[i].studentNumber));
					break;
				default:
					printf("INFO not found!\n");
					break;
			}	
		}
		printf("\n");
	}
	
	// printf student s[i]
	printf("학생정보출력:\n\n");
	for(i = 0; i < MAX_STUDENTS; ++i){
		printf("%d번째 학생 정보\n", i + 1);
		printf("이름: %s, 클래스 번호: %d, 학생 번호: %d\n\n", s[i].firstName, s[i].classNumber, s[i].studentNumber);
	}
	
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : 유수진\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}

/*
프로그램 실행 결과
--------------
학생정보출력:

1번째 학생 정보
이름: 김성수, 클래스 번호: 1, 학생 번호: 23

2번째 학생 정보
이름: 박철준, 클래스 번호: 1, 학생 번호: 2

3번째 학생 정보
이름: 남선기, 클래스 번호: 1, 학생 번호: 6

4번째 학생 정보
이름: 류준서, 클래스 번호: 2, 학생 번호: 21

5번째 학생 정보
이름: 이수이, 클래스 번호: 2, 학생 번호: 7
*/
