#pragma once
class Image
{
public:
	Image(int w, int h) {
		width = w; height = h;
		pixels = new int[w*h];
	}
	void setPixel(int rgb, int x, int y) {
		pixels[x + y*width] = rgb;
	}
	void setPixel(int r, int g, int b, int x, int y) {
		pixels[x + y*width] = (r << 16) | (g << 8) | (b);
	}
	int getPixel(int x, int y) {
		return pixels[x + y*width];
	}
	int *getPixels() {
		return pixels;
	}

	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	int *pixels;
	int width, height;
};

