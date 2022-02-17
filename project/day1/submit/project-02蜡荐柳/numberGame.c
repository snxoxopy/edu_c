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
  ����: ���� ���߱� ����
  ����: ���� �߻��⿡�� ���� ���ڸ� ����ڰ� ���ߴ� ���α׷�
  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp_answer(int n_rand, int cur_input, int n_cnt);


int main() {
	
	//	 initialization
	int i, n_rand, n_cnt = 0, flag = 1, cur_input;
	
	//	 [Req 3]=============================================
	//	 https://reakwon.tistory.com/63
	//	 https://man7.org/linux/man-pages/man3/srand.3p.html
	//	 ====================================================
	srand(time(NULL));
	
	//	 [Req 1]=============================================
	//	 https://reakwon.tistory.com/63
	//	 https://man7.org/linux/man-pages/man3/rand.3p.html
	//	 ====================================================
	n_rand = (rand() % 100) + 1; 	// less than 100
	//printf("answer = %d\n", n_rand); // test
//	n_rand = 75;
	
	// [Req 2]=============================================
	while(flag){
		printf("100 �̸��� ���ڸ� �Է��ϼ���: ");
		scanf("%d", &cur_input);
		if(cur_input > 100){
			printf("���: 100 �̸��� ���ڸ� �Է��ϼ���!\n");
		}
		else if(cur_input < 1){
			printf("���: 1 �̻��� ���ڸ� �Է��ϼ���!\n");
		}
		
		// [req 4]=============================================
		flag = cmp_answer(n_rand, cur_input, n_cnt);
		printf("\n");
		n_cnt++;
	}	
	printf("�����մϴ� %d�� �õ� �� ������ ���߼̽��ϴ�\n", n_cnt);
	 
	// [Req 5]=============================================
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : ������\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}


int cmp_answer(n_rand, cur_input, n_cnt){
	
	// initialization
	static int pre_input, min_val = 0, max_val = 100;

	// ��������: ����('100���� �۽��ϴ�') ��� ��������
	// 0. min, max �� �����ϱ�
	// 100 �ʰ��� 100, 1 �̸��� 0 
	// 1. cur > target
	// 		min���� ũ�� cur���� �۴� 
	// 		min_val = pre; -> ������ �ּ� ������ ������Ʈ, ���ݱ��� �Է� �� �ּҰ����� ���� ���� 
	// 		max_val = cur;
	// 2. cur < target
	// 		cur���� ũ�� max���� �۴� 
	// 		min_val = cur;
	//		max_val = pre; -> ������ �ִ� ������ ������Ʈ, ���ݱ��� �Է� �� �ִ밪���� ���� ���� 
	if(cur_input > 100){
		cur_input = 100;
	}
	else if(cur_input < 1){
		cur_input = 0;
	}
	if (n_cnt == 0) {
		pre_input = (n_rand > cur_input) ? max_val : min_val;
	}else{
		pre_input = cur_input;
	}
	
	// compare n_rand with cur_input
	if(n_rand > cur_input){
		printf("\n%d ���ٴ� ũ��, %d ���ٴ� �۽��ϴ�.\n", cur_input, max_val);
		min_val = cur_input;
		max_val = (pre_input > max_val) ? pre_input : max_val;
		return 1;
	}
	else if(n_rand < cur_input){
		printf("\n%d ���ٴ� ũ��, %d ���ٴ� �۽��ϴ�.\n", min_val, cur_input);
		min_val = (pre_input > min_val) ? min_val : pre_input;
		max_val = cur_input;
		return 1;
	}
	else{
		return 0;
	}
	
}

/*
���α׷� ���� ���
--------------
// [Req 6]=============================================

=============================================================================
test0) guide�� ������ ������� Ȯ��  

100 �̸��� ���ڸ� �Է��ϼ���: 50

50 ���ٴ� ũ��, 100 ���ٴ� �۽��ϴ�.

100 �̸��� ���ڸ� �Է��ϼ���: 70

50 ���ٴ� ũ��, 70 ���ٴ� �۽��ϴ�.

100 �̸��� ���ڸ� �Է��ϼ���: 60

60 ���ٴ� ũ��, 70 ���ٴ� �۽��ϴ�.

100 �̸��� ���ڸ� �Է��ϼ���: 65

�����մϴ� 4�� �õ� �� ������ ���߼̽��ϴ�

------------------------------------------------------------------------
written by : ������
------------------------------------------------------------------------


=============================================================================
test1) ���� �����  ��� �� �Է�, answer�� ������ ����� �����ϱ� ���� logic �ݿ� 

100 ������ ���ڸ� �Է��ϼ���: 80

0 ���ٴ� ũ��, 80 ���ٴ� �۽��ϴ�.

100 ������ ���ڸ� �Է��ϼ���: 90 

0 ���ٴ� ũ��, 90 ���ٴ� �۽��ϴ�.

100 ������ ���ڸ� �Է��ϼ���: 40

40 ���ٴ� ũ��, 90 ���ٴ� �۽��ϴ�.

100 ������ ���ڸ� �Է��ϼ���: 80

40 ���ٴ� ũ��, 80 ���ٴ� �۽��ϴ�.

100 ������ ���ڸ� �Է��ϼ���: 75

�����մϴ� 5�� �õ� �� ������ ���߼̽��ϴ�

------------------------------------------------------------------------
written by : ������
------------------------------------------------------------------------

=============================================================================
test3) �ִ밪, �ּҰ� ������Ʈ Ȯ�� 

0 ���ٴ� ũ��, 100 ���ٴ� �۽��ϴ�.

100 �̸��� ���ڸ� �Է��ϼ���: 0
���: 1 �̻��� ���ڸ� �Է��ϼ���!

0 ���ٴ� ũ��, 100 ���ٴ� �۽��ϴ�.

100 �̸��� ���ڸ� �Է��ϼ���: 50

50 ���ٴ� ũ��, 100 ���ٴ� �۽��ϴ�.

100 �̸��� ���ڸ� �Է��ϼ���: 90

50 ���ٴ� ũ��, 90 ���ٴ� �۽��ϴ�.

100 �̸��� ���ڸ� �Է��ϼ���: 80

50 ���ٴ� ũ��, 80 ���ٴ� �۽��ϴ�.

100 �̸��� ���ڸ� �Է��ϼ���: 75

�����մϴ� 7�� �õ� �� ������ ���߼̽��ϴ�

------------------------------------------------------------------------
written by : ������
------------------------------------------------------------------------

*/
