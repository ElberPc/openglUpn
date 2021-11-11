#include<fstream>
#include<assert.h>
#include<iostream>
using namespace std;
class Image1 {
public:
	Image1(char* ps, int w, int h);
	~Image1();

	/* An array of the form (R1, G1, B1, R2, G2, B2, ...) indicating the
	* color of each pixel in image.  Color components range from 0 to 255.
	* The array starts the bottom-left pixel, then moves right to the end
	* of the row, then moves up to the next column, and so on.  This is the
	* format in which OpenGL likes images.
	*/
	char* pixels;
	int width;
	int height;
};
//Reads a bitmap image from file.
Image1* loadBMP(const char* filename);
Image1::Image1(char* ps, int w, int h) : pixels(ps), width(w), height(h) {

}
Image1::~Image1() {
	delete[] pixels;
}
namespace {
	//Converts a four-character array to an integer, using little-endian form
	int toInt(const char* bytes) {
		return (int)(((unsigned char)bytes[3] << 24) |
			((unsigned char)bytes[2] << 16) |
			((unsigned char)bytes[1] << 8) |
			(unsigned char)bytes[0]);
	}

	//Converts a two-character array to a short, using little-endian form
	short toShort(const char* bytes) {
		return (short)(((unsigned char)bytes[1] << 8) |
			(unsigned char)bytes[0]);
	}

	//Reads the next four bytes as an integer, using little-endian form
	int readInt(ifstream &input) {
		char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);
	}

	//Reads the next two bytes as a short, using little-endian form
	short readShort(ifstream &input) {
		char buffer[2];
		input.read(buffer, 2);
		return toShort(buffer);
	}

	//Just like auto_ptr, but for arrays
	template<class T>
	class auto_array {
	private:
		T* array;
		mutable bool isReleased;
	public:
		explicit auto_array(T* array_ = NULL) :
			array(array_), isReleased(false) {
		}

		auto_array(const auto_array<T> &aarray) {
			array = aarray.array;
			isReleased = aarray.isReleased;
			aarray.isReleased = true;
		}

		~auto_array() {
			if (!isReleased && array != NULL) {
				delete[] array;
			}
		}

		T* get() const {
			return array;
		}

		T &operator*() const {
			return *array;
		}

		void operator=(const auto_array<T> &aarray) {
			if (!isReleased && array != NULL) {
				delete[] array;
			}
			array = aarray.array;
			isReleased = aarray.isReleased;
			aarray.isReleased = true;
		}

		T* operator->() const {
			return array;
		}

		T* release() {
			isReleased = true;
			return array;
		}

		void reset(T* array_ = NULL) {
			if (!isReleased && array != NULL) {
				delete[] array;
			}
			array = array_;
		}

		T* operator+(int i) {
			return array + i;
		}

		T &operator[](int i) {
			return array[i];
		}
	};
}
Image1* loadBMP(const char* filename) {
	ifstream input;
	input.open(filename, ifstream::binary);
	assert(!input.fail() || !"Could not find file");
	char buffer[2];
	input.read(buffer, 2);
	assert(buffer[0] == 'B' && buffer[1] == 'M' || !"Not a bitmap file");
	input.ignore(8);
	int dataOffset = readInt(input);

	//Read the header
	int headerSize = readInt(input);
	int width;
	int height;
	switch (headerSize) {
	case 40:
		//V3
		width = readInt(input);
		height = readInt(input);
		input.ignore(2);
		assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
		assert(readShort(input) == 0 || !"Image is compressed");
		break;
	case 12:
		//OS/2 V1
		width = readShort(input);
		height = readShort(input);
		input.ignore(2);
		assert(readShort(input) == 24 || !"Image is not 24 bits per pixel");
		break;
	case 64:
		//OS/2 V2
		assert(!"Can't load OS/2 V2 bitmaps");
		break;
	case 108:
		//Windows V4
		assert(!"Can't load Windows V4 bitmaps");
		break;
	case 124:
		//Windows V5
		assert(!"Can't load Windows V5 bitmaps");
		break;
	default:
		assert(!"Unknown bitmap format");
	}

	//Read the data
	int bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
	int size = bytesPerRow * height;
	auto_array<char> pixels(new char[size]);
	input.seekg(dataOffset, ios_base::beg);
	input.read(pixels.get(), size);

	//Get the data into the right format
	auto_array<char> pixels2(new char[width * height * 3]);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < 3; c++) {
				pixels2[3 * (width * y + x) + c] =
					pixels[bytesPerRow * y + 3 * x + (2 - c)];
			}
		}
	}

	input.close();
	return new Image1(pixels2.release(), width, height);
}// FIN DE LAS FUNCIONES PARA CARGAR TEXTURAS ....
GLuint loadTexture(Image1* image1) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGB,
		image1->width, image1->height,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		image1->pixels);
	return textureId;
}
GLuint ID_de_Textura1;           //The OpenGL id of the texture
GLuint ID_de_Textura2;
GLuint ID_de_Textura3;
GLuint ID_de_Textura4;
GLuint ID_de_Textura5;
GLuint ID_de_Textura6;

void initRendering() {
	glEnable(GL_DEPTH_TEST);

	Image1* image1 = loadBMP("images/humano.bmp");
	Image1* image2 = loadBMP("images/metal.bmp");
	Image1* image3 = loadBMP("images/mesa.bmp");
	Image1* image4 = loadBMP("images/electrodo.bmp");
	Image1* image5 = loadBMP("images/pedal.bmp");
	/*Image* image6 = loadBMP("Madera.bmp");
	Image* image6 = loadBMP("Madera.bmp");*/
	ID_de_Textura1 = loadTexture(image1);
	ID_de_Textura2 = loadTexture(image2);
	ID_de_Textura3 = loadTexture(image3);
	ID_de_Textura4 = loadTexture(image4);
	ID_de_Textura5 = loadTexture(image5);
	/*ID_de_Textura6 = loadTexture(image6);*/

	//delete image1,image2,image3,image4,image5,image6;
	delete image1, image2, image3, image4, image5;//, image6;
}