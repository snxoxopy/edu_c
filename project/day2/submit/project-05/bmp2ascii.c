#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bmp2ascii.h"
#define FILEDIR "images.bmp"
#define nRGB 3


int main(int argc, char** argv)
{
	// 1.1 요구 사항 
	BITMAPFILEHEADER fileHeader;    // 비트맵 파일 헤더
	BITMAPINFOHEADER infoHeader;    // 비트맵 정보 헤더
	infoHeader.biCompression = 0;	// 비트맵은 압축하지 않으므로 0
	
	// 2.1 요구 사항
	FILE *fpBitmap;
	
	fpBitmap = fopen(FILEDIR,"rb");
	int r, c;
	
	// reading nitmap file header
	// size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
	if(fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBitmap) < 1){
		printf("Not found!\n");
	}
	
	// 3.1 요구 사항 
	// Check BM
	if(fileHeader.bfType != 0x4D42){
		printf("NO BITMAP!\n");
		return -1;
	}
	else{
		// 4.1 요구 사항
		fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBitmap);

		// Read biBitCounter
		// 24bpp
		if(infoHeader.biBitCount != 24){
			printf("[WARNING] No 24bpp!\n");
			return -1;
		}
		else{
			// 5.1 요구 사항
			if(((infoHeader.biWidth) % 4 != 0)){
				printf("4의 배수가 아님을 확인\n");
			}
		}
		
		// 6.1 요구 사항 
		int size, bits, bitSize;
		size = infoHeader.biSizeImage;

		unsigned char* pImg = malloc(size);				// image for pixels bytes
		unsigned char* pImgout = malloc(size);
		fseek(fpBitmap, fileHeader.bfOffBits, SEEK_SET); // 파일 포인터를 픽셀데이터 옵셋에 위치 시킨후
		
		// Read Image
		if(fread(pImg, size, 1, fpBitmap) < 1){
			printf("END\n");
			fclose(fpBitmap);
			return -1;
		}
		fclose(fpBitmap);
		
		// [FAIL] 7.1 요구 사항 & 8.1 요구 사항 
		char ascii[] = { 'X', '#', '@', '%', '*', ':', '=', '+', '-', '.', ' ' };
		unsigned char rgbmean = 0;
		char ch;
		int i;
		
		FILE *fpOutput = fopen("ascii.txt","w"); 
		
		// Load Image
		// pointer 사용으로 중괄호 밖에서도 읽기 가능
		// ---------------------------------------------------------- 
		// https://dojang.io/mod/page/view.php?id=704 --> 공부필요, 아래는 미반영  코드 
		for(r = infoHeader.biHeight - 1; r >= 0; --r){
			for(c = 0; c < infoHeader.biWidth; ++c){
				for(i = 0; i < nRGB; ++i){
					rgbmean += pImg[r * (infoHeader.biWidth * nRGB) + c * nRGB + i];	
				}
				rgbmean /= nRGB;
				ch = ascii[rgbmean * sizeof(ascii) / 256];
				fprintf(fpOutput, "%c", ch);
			}
			fprintf(fpOutput, "%c", '\n');
		}
		free(pImg);
		fclose(fpOutput);
	}
	
	// 9.1 요구 사항 
	printf("\n------------------------------------------------------------------------\n");
	printf("***** 승리했습니다. *****\n");
	printf("written by : 유수진\n");
	printf("------------------------------------------------------------------------\n");
	
	return 0;
	
}

