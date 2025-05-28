# Reverse Engineering BMP Image Header (C++)

## Overview

This project demonstrates how to reverse engineer and parse the header of a BMP image file using C++. It reads the binary contents of a `.bmp` file and extracts key metadata such as file size, image dimensions, and bits per pixel. This exercise is ideal for understanding low-level file formats, working with binary data, and learning how to map file structures to C++ structs.


## Build & Run

### Clone the repository

```bash
git clone https://github.com/AniDashyan/reverse_engineering_binary_data_formats.git
cd reverse_engineering_binary_data_formats
````

### Build the project using CMake

```bash
cmake -S . -B build
cmake --build build
```

### Run the executable

```bash
./build/reveng_bin
```

## Example Output

```
File Size: 7376082 bytes
Data Offset: 138 bytes
Image Width: 1920 px
Image Height: 1280 px
Bits Per Pixel: 24
Compression Type: 0
```


## Explanation

### What It Does

* Opens a `.bmp` file in binary mode using `std::ifstream`.
* Reads the BMP Header (14 bytes) to validate the file signature ("BM") and extract the file size and pixel data offset.
* Reads the DIB Header (BITMAPINFOHEADER – 40 bytes) to get detailed image metadata such as:

  * Width and height
  * Color depth (bits per pixel)
  * Compression method used

### Key C++ Concepts Used

* `#pragma pack(push, 1)`: Ensures no padding is added between struct members to match exact binary layout.
* `reinterpret_cast`: Converts raw bytes into structured C++ types.
* Binary file I/O using `std::ifstream` with `std::ios::binary`.

```
