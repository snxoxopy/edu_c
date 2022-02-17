#ifndef _BMP2ASCII_H_
#define _BMP2ASCII_H_

#pragma pack(push, 1)                // 구조체를 1바이트 크기로 정렬

// 1.1 요구사항 
// https://dojang.io/mod/page/view.php?id=702
typedef struct _BITMAPFILEHEADER     // BMP 비트맵 파일 헤더 구조체
{
    unsigned short bfType;           // BMP 파일 매직 넘버
    unsigned int   bfSize;           // 파일 크기
    unsigned short bfReserved1;      // 예약
    unsigned short bfReserved2;      // 예약
    unsigned int   bfOffBits;        // 비트맵 데이터의 시작 위치
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP 비트맵 정보 헤더 구조체
{
    unsigned int   	biSize;           	// 현재 비트맵 정보 헤더(BITMAPINFOHEADER)의 크기
    int   			biWidth;          	// 비트맵 이미지의 가로 크기(픽셀)
    int   		   	biHeight;      	 	// 비트맵 이미지의 세로 크기(픽셀).
    unsigned short 	biPlanes;         	// 사용하는 색상판의 수. 항상 1입니다.
    unsigned short 	biBitCount;       	// 픽셀 하나를 표현하는 비트 수
    unsigned int	biCompression;		// 압축 방식. 보통 비트맵은 압축을 하지 않으므로 0입니다.
    unsigned int	biSizeImage;		// 비트맵 이미지의 픽셀 데이터 크기(압축 되지 않은 크기)
    unsigned int	biXPelsPerMeter;	// 그림의 가로 해상도(미터당 픽셀)
    unsigned int	biYPelsPerMeter;	// 그림의 세로 해상도(미터당 픽셀)
    unsigned int	biClrUsed;			// 색상 테이블에서 실제 사용되는 색상 수
    unsigned int	biClrImportant;		// 비트맵을 표현하기 위해 필요한 색상 인덱스 수
    
} BITMAPINFOHEADER;

#pragma pack(pop)

#endif//_BMP2ASCII_H_
