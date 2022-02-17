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
  ����: ����ü�� ����Ͽ� �л� 5���� ������ �����ϴ� ���α׷�
  ����: �л��̸�, Ŭ������, ��ȣ���� �����ϰ� �ִ� ����ü �迭�� ����� ������ �Է��ϴ� ���α׷�
  */

#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 5
#define MAX_INFO 3

struct student {
	char firstName[50]; // �л� �̸�
	int classNumber; // �� ��ȣ(��. 1, 2)
	int studentNumber; // �л� ��ȣ
} s[5];

enum info_student {str_name, num_class, num_number};

int main() {
	
	// initialization
	int i, j;
	
	// scanf student s[i]
	for(i = 0; i < MAX_STUDENTS; ++i){
		printf("%d��° �л� ���� �Է�\n", i + 1);
		for(j = 0; j < MAX_INFO; ++j){
			switch (j){
				case str_name:
					printf("�̸�: ");
					scanf("%s", &(s[i].firstName));
					break;
				case num_class:
					printf("Ŭ���� ��ȣ: ");
					scanf("%d", &(s[i].classNumber));
					break;
				case num_number:
					printf("�л� ��ȣ: ");
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
	printf("�л��������:\n\n");
	for(i = 0; i < MAX_STUDENTS; ++i){
		printf("%d��° �л� ����\n", i + 1);
		printf("�̸�: %s, Ŭ���� ��ȣ: %d, �л� ��ȣ: %d\n\n", s[i].firstName, s[i].classNumber, s[i].studentNumber);
	}
	
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : ������\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}

/*
���α׷� ���� ���
--------------
�л��������:

1��° �л� ����
�̸�: �輺��, Ŭ���� ��ȣ: 1, �л� ��ȣ: 23

2��° �л� ����
�̸�: ��ö��, Ŭ���� ��ȣ: 1, �л� ��ȣ: 2

3��° �л� ����
�̸�: ������, Ŭ���� ��ȣ: 1, �л� ��ȣ: 6

4��° �л� ����
�̸�: ���ؼ�, Ŭ���� ��ȣ: 2, �л� ��ȣ: 21

5��° �л� ����
�̸�: �̼���, Ŭ���� ��ȣ: 2, �л� ��ȣ: 7
*/
