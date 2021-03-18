#ifndef __LIBBMP_H__
#define __LIBBMP_H__

#include <vector>
#include <cstdint>
#include <string>

#define BMP_MAGIC 19778

#define BMP_GET_PADDING(a) ((a) % 4)

//
// BmpError
//

enum BmpError
{
	BMP_FILE_NOT_OPENED = -4,
	BMP_HEADER_NOT_INITIALIZED,
	BMP_INVALID_FILE,
	BMP_ERROR,
	BMP_OK = 0
};

//
// BmpPixbuf
//
// AKA. Pixel buffer
class BmpPixbuf
{
	public:
		BmpPixbuf(void);
		BmpPixbuf(const int32_t width, const int32_t height);
		~BmpPixbuf();

		void init(const int32_t width, const int32_t height);
		void set_pixel(const int32_t x, const int32_t y, const uint8_t r, const uint8_t g, const uint8_t b);

		uint8_t red_at(const int32_t x, const int32_t y);
		uint8_t green_at(const int32_t x, const int32_t y);
		uint8_t blue_at(const int32_t x, const int32_t y);

		void write(const int32_t row, std::ofstream& f);
		void read(const int32_t row, std::ifstream& f);
	private:
		std::size_t len_row;
		std::size_t len_pixel = 3;

		std::vector<uint8_t> data;
};

//
// BmpImg
//

class BmpImg : public BmpPixbuf
{
	public:
		BmpImg(void);
		BmpImg(const int32_t width, const int32_t height);
		~BmpImg();

		enum BmpError write(const std::string& filename);
		enum BmpError read(const std::string& filename);

		int32_t get_width(void);
		int32_t get_height(void);
	private:
		// Use a struct to read this in one call
		struct header_info
		{
			uint32_t bfSize = 0;
			uint32_t bfReserved = 0;
			uint32_t bfOffBits = 54;
			uint32_t biSize = 40;
			int32_t biWidth = 0;
			int32_t biHeight = 0;
			uint16_t biPlanes = 1;
			uint16_t biBitCount = 24;
			uint32_t biCompression = 0;
			uint32_t biSizeImage = 0;
			int32_t biXPelsPerMeter = 0;
			int32_t biYPelsPerMeter = 0;
			uint32_t biClrUsed = 0;
			uint32_t biClrImportant = 0;
		} header;
};

#endif /* __LIBBMP_H__ */
