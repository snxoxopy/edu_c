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
  제목: 숫자 맞추기 게임
  설명: 난수 발생기에서 나온 숫자를 사용자가 맞추는 프로그램
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
		printf("100 미만의 숫자를 입력하세요: ");
		scanf("%d", &cur_input);
		if(cur_input > 100){
			printf("경고: 100 미만의 숫자를 입력하세요!\n");
		}
		else if(cur_input < 1){
			printf("경고: 1 이상의 숫자를 입력하세요!\n");
		}
		
		// [req 4]=============================================
		flag = cmp_answer(n_rand, cur_input, n_cnt);
		printf("\n");
		n_cnt++;
	}	
	printf("축하합니다 %d번 시도 후 정답을 맞추셨습니다\n", n_cnt);
	 
	// [Req 5]=============================================
    printf("\n------------------------------------------------------------------------\n");
    printf("written by : 유수진\n");
    printf("------------------------------------------------------------------------\n");
    return 0;
}


int cmp_answer(n_rand, cur_input, n_cnt){
	
	// initialization
	static int pre_input, min_val = 0, max_val = 100;

	// 질의응답: 기존('100보다 작습니다') 대로 나오도록
	// 0. min, max 값 제한하기
	// 100 초과시 100, 1 미만시 0 
	// 1. cur > target
	// 		min보다 크고 cur보다 작다 
	// 		min_val = pre; -> 현재의 최소 값으로 업데이트, 지금까지 입력 중 최소값으로 하지 않음 
	// 		max_val = cur;
	// 2. cur < target
	// 		cur보다 크고 max보다 작다 
	// 		min_val = cur;
	//		max_val = pre; -> 현재의 최대 값으로 업데이트, 지금까지 입력 중 최대값으로 하지 않음 
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
		printf("\n%d 보다는 크고, %d 보다는 작습니다.\n", cur_input, max_val);
		min_val = cur_input;
		max_val = (pre_input > max_val) ? pre_input : max_val;
		return 1;
	}
	else if(n_rand < cur_input){
		printf("\n%d 보다는 크고, %d 보다는 작습니다.\n", min_val, cur_input);
		min_val = (pre_input > min_val) ? min_val : pre_input;
		max_val = cur_input;
		return 1;
	}
	else{
		return 0;
	}
	
}

/*
프로그램 실행 결과
--------------
// [Req 6]=============================================

=============================================================================
test0) guide와 동일한 결과인지 확인  

100 미만의 숫자를 입력하세요: 50

50 보다는 크고, 100 보다는 작습니다.

100 미만의 숫자를 입력하세요: 70

50 보다는 크고, 70 보다는 작습니다.

100 미만의 숫자를 입력하세요: 60

60 보다는 크고, 70 보다는 작습니다.

100 미만의 숫자를 입력하세요: 65

축하합니다 4번 시도 후 정답을 맞추셨습니다

------------------------------------------------------------------------
written by : 유수진
------------------------------------------------------------------------


=============================================================================
test1) 이전 결과에  벗어난 값 입력, answer와 동일한 결과를 도출하기 위해 logic 반영 

100 이하의 숫자를 입력하세요: 80

0 보다는 크고, 80 보다는 작습니다.

100 이하의 숫자를 입력하세요: 90 

0 보다는 크고, 90 보다는 작습니다.

100 이하의 숫자를 입력하세요: 40

40 보다는 크고, 90 보다는 작습니다.

100 이하의 숫자를 입력하세요: 80

40 보다는 크고, 80 보다는 작습니다.

100 이하의 숫자를 입력하세요: 75

축하합니다 5번 시도 후 정답을 맞추셨습니다

------------------------------------------------------------------------
written by : 유수진
------------------------------------------------------------------------

=============================================================================
test3) 최대값, 최소값 업데이트 확인 

0 보다는 크고, 100 보다는 작습니다.

100 미만의 숫자를 입력하세요: 0
경고: 1 이상의 숫자를 입력하세요!

0 보다는 크고, 100 보다는 작습니다.

100 미만의 숫자를 입력하세요: 50

50 보다는 크고, 100 보다는 작습니다.

100 미만의 숫자를 입력하세요: 90

50 보다는 크고, 90 보다는 작습니다.

100 미만의 숫자를 입력하세요: 80

50 보다는 크고, 80 보다는 작습니다.

100 미만의 숫자를 입력하세요: 75

축하합니다 7번 시도 후 정답을 맞추셨습니다

------------------------------------------------------------------------
written by : 유수진
------------------------------------------------------------------------

*/
