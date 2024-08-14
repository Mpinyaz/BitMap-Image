#include "bmpsetting.h" // Assuming your structures are defined in this header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Initialize file and info headers
  BMPFileHeader fileHeader = InitializeFileHeader();
  BMPInfoHeader infoHeader = InitializeInfoHeader();

  // Set image dimensions
  infoHeader.ImgWidth = 100;  // 100 pixels wide
  infoHeader.ImgHeight = 100; // 100 pixels high

  // Calculate image size (width * height * bytes per pixel)
  int bytesPerPixel = 3; // 24-bit BMP, so 3 bytes per pixel
  infoHeader.ImgDateSize =
      infoHeader.ImgWidth * infoHeader.ImgHeight * bytesPerPixel;

  // Update file size in the file header
  fileHeader.FileSize =
      sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + infoHeader.ImgDateSize;

  // Open the file for writing in binary mode
  FILE *file = fopen("../assets/output.bmp", "wb");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Write headers to file
  fwrite(&fileHeader, sizeof(BMPFileHeader), 1, file);
  fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);

  // Create a buffer for the pixel data (simple solid color)
  unsigned char *imageData = (unsigned char *)malloc(infoHeader.ImgDateSize);
  if (imageData == NULL) {
    perror("Error allocating memory");
    fclose(file);
    return 1;
  }

  // Fill the image data with a solid color (e.g., blue)
  unsigned char blue = 255;
  unsigned char green = 0;
  unsigned char red = 0;

  for (int i = 0; i < infoHeader.ImgDateSize; i += bytesPerPixel) {
    imageData[i] = blue;
    imageData[i + 1] = green;
    imageData[i + 2] = red;
  }

  // Write pixel data to the file
  fwrite(imageData, sizeof(unsigned char), infoHeader.ImgDateSize, file);

  // Free the image data buffer
  free(imageData);

  // Close the file
  fclose(file);

  printf("BMP image created successfully!\n");
  return 0;
}
