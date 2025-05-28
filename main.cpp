#include <iostream>
#include <fstream>
#include <cstdint>

#pragma pack(push, 1) // Disable padding

struct BMPHeader {
    char signature[2];     
    uint32_t fileSize;      
    uint16_t reserved1;     // Reserved
    uint16_t reserved2;     // Reserved
    uint32_t dataOffset;    // Offset to pixel data
};

struct DIBHeader {
    uint32_t headerSize;   
    int32_t width;          
    int32_t height;         
    uint16_t planes;        
    uint16_t bitsPerPixel;  
    uint32_t compression;   
    uint32_t imageSize;     
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;   
    uint32_t colorsImportant;
};

#pragma pack(pop)

int main() {
    std::ifstream file("sample_img.bmp", std::ios::binary);
    if (!file) {
        std::cerr << "Error: Cannot open file.\n";
        return 1;
    }

    BMPHeader bmp;
    DIBHeader dib;

    // Read BMP header
    file.read(reinterpret_cast<char*>(&bmp), sizeof(BMPHeader));
    if (bmp.signature[0] != 'B' || bmp.signature[1] != 'M') {
        std::cerr << "Not a valid BMP file.\n";
        return 1;
    }

    // Read DIB header
    file.read(reinterpret_cast<char*>(&dib), sizeof(DIBHeader));

    // Print out parsed info
    std::cout << "File Size: " << bmp.fileSize << " bytes\n";
    std::cout << "Data Offset: " << bmp.dataOffset << " bytes\n";
    std::cout << "Image Width: " << dib.width << " px\n";
    std::cout << "Image Height: " << dib.height << " px\n";
    std::cout << "Bits Per Pixel: " << dib.bitsPerPixel << "\n";
    std::cout << "Compression Type: " << dib.compression << "\n";

    return 0;
}
