#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bmp2ascii.h"
#define FILEDIR "images.bmp"
#define nRGB 3


int main(int argc, char** argv)
{
	// 1.1 �䱸 ���� 
	BITMAPFILEHEADER fileHeader;    // ��Ʈ�� ���� ���
	BITMAPINFOHEADER infoHeader;    // ��Ʈ�� ���� ���
	infoHeader.biCompression = 0;	// ��Ʈ���� �������� �����Ƿ� 0
	
	// 2.1 �䱸 ����
	FILE *fpBitmap;
	
	fpBitmap = fopen(FILEDIR,"rb");
	int r, c;
	
	// reading nitmap file header
	// size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
	if(fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBitmap) < 1){
		printf("Not found!\n");
	}
	
	// 3.1 �䱸 ���� 
	// Check BM
	if(fileHeader.bfType != 0x4D42){
		printf("NO BITMAP!\n");
		return -1;
	}
	else{
		// 4.1 �䱸 ����
		fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBitmap);

		// Read biBitCounter
		// 24bpp
		if(infoHeader.biBitCount != 24){
			printf("[WARNING] No 24bpp!\n");
			return -1;
		}
		else{
			// 5.1 �䱸 ����
			if(((infoHeader.biWidth) % 4 != 0)){
				printf("4�� ����� �ƴ��� Ȯ��\n");
			}
		}
		
		// 6.1 �䱸 ���� 
		int size, bits, bitSize;
		size = infoHeader.biSizeImage;

		unsigned char* pImg = malloc(size);				// image for pixels bytes
		unsigned char* pImgout = malloc(size);
		fseek(fpBitmap, fileHeader.bfOffBits, SEEK_SET); // ���� �����͸� �ȼ������� �ɼ¿� ��ġ ��Ų��
		
		// Read Image
		if(fread(pImg, size, 1, fpBitmap) < 1){
			printf("END\n");
			fclose(fpBitmap);
			return -1;
		}
		fclose(fpBitmap);
		
		// [FAIL] 7.1 �䱸 ���� & 8.1 �䱸 ���� 
		char ascii[] = { 'X', '#', '@', '%', '*', ':', '=', '+', '-', '.', ' ' };
		unsigned char rgbmean = 0;
		char ch;
		int i;
		
		FILE *fpOutput = fopen("ascii.txt","w"); 
		
		// Load Image
		// pointer ������� �߰�ȣ �ۿ����� �б� ����
		// ---------------------------------------------------------- 
		// https://dojang.io/mod/page/view.php?id=704 --> �����ʿ�, �Ʒ��� �̹ݿ�  �ڵ� 
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
	
	// 9.1 �䱸 ���� 
	printf("\n------------------------------------------------------------------------\n");
	printf("***** �¸��߽��ϴ�. *****\n");
	printf("written by : ������\n");
	printf("------------------------------------------------------------------------\n");
	
	return 0;
	
}

