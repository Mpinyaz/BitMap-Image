#ifndef BMPSETTING_H
#define BMPSETTING_H

typedef struct BitMapFileHeader {
  const unsigned short Reserve;
  const unsigned short FileType;
  unsigned int FileSize;
  const unsigned short Reserve1;
  const unsigned short Reserve2;
  const unsigned int DateOffSet;
} BMPFileHeader;

typedef struct BitMapInfoHeader {
  const unsigned int ThisSize; // = 0x28;
  int ImgWidth;
  int ImgHeight;
  const unsigned short PlainNum;   // = 0x01;
  const unsigned short BitPerPx;   // = 0x01;
  const unsigned int CompressType; // = 0x00;
  unsigned int ImgDateSize;
  const unsigned int HorizontalDpi;  // = 0x00;
  const unsigned int VerticalDpi;    // = 0x00;
  const unsigned int ColorIndex;     // = 0x02;
  const unsigned int PrincipalIndex; // = 0x00;
} BMPInfoHeader;

typedef struct ColorPalette {
  const unsigned char Red;
  const unsigned char Green;
  const unsigned char Blue;
  const unsigned char Reserve;
} ColorPalette;

BMPFileHeader InitializeFileHeader() {
  BMPFileHeader bmpFH = {
      0x00,
      0x4D42, // FileType
      0x00,   // FileSize
      0x00,   // Reserve1
      0x00,   // Reserve2
      0x3E    // DateOffSet
  };
  return bmpFH;
}

BMPInfoHeader InitializeInfoHeader() {
  BMPInfoHeader bmpIH = {
      0x28, // ThisSize
      0x00, // ImgWidth
      0x00, // ImgHeight
      0x01, // PlainNum
      0x01, // BitPerPx
      0x00, // CompressType
      0x00, // ImgDateSize
      0x00, // HorizontalDpi
      0x00, // VerticalDpi
      0x02, // ColorIndex
      0x00  // PrincipalIndex
  };
  return bmpIH;
}

#endif // BMPSETTING_H
