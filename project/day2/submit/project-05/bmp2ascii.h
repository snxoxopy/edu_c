#ifndef _BMP2ASCII_H_
#define _BMP2ASCII_H_

#pragma pack(push, 1)                // ����ü�� 1����Ʈ ũ��� ����

// 1.1 �䱸���� 
// https://dojang.io/mod/page/view.php?id=702
typedef struct _BITMAPFILEHEADER     // BMP ��Ʈ�� ���� ��� ����ü
{
    unsigned short bfType;           // BMP ���� ���� �ѹ�
    unsigned int   bfSize;           // ���� ũ��
    unsigned short bfReserved1;      // ����
    unsigned short bfReserved2;      // ����
    unsigned int   bfOffBits;        // ��Ʈ�� �������� ���� ��ġ
} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER     // BMP ��Ʈ�� ���� ��� ����ü
{
    unsigned int   	biSize;           	// ���� ��Ʈ�� ���� ���(BITMAPINFOHEADER)�� ũ��
    int   			biWidth;          	// ��Ʈ�� �̹����� ���� ũ��(�ȼ�)
    int   		   	biHeight;      	 	// ��Ʈ�� �̹����� ���� ũ��(�ȼ�).
    unsigned short 	biPlanes;         	// ����ϴ� �������� ��. �׻� 1�Դϴ�.
    unsigned short 	biBitCount;       	// �ȼ� �ϳ��� ǥ���ϴ� ��Ʈ ��
    unsigned int	biCompression;		// ���� ���. ���� ��Ʈ���� ������ ���� �����Ƿ� 0�Դϴ�.
    unsigned int	biSizeImage;		// ��Ʈ�� �̹����� �ȼ� ������ ũ��(���� ���� ���� ũ��)
    unsigned int	biXPelsPerMeter;	// �׸��� ���� �ػ�(���ʹ� �ȼ�)
    unsigned int	biYPelsPerMeter;	// �׸��� ���� �ػ�(���ʹ� �ȼ�)
    unsigned int	biClrUsed;			// ���� ���̺��� ���� ���Ǵ� ���� ��
    unsigned int	biClrImportant;		// ��Ʈ���� ǥ���ϱ� ���� �ʿ��� ���� �ε��� ��
    
} BITMAPINFOHEADER;

#pragma pack(pop)

#endif//_BMP2ASCII_H_
