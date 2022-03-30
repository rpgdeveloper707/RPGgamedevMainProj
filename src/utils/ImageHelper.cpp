#include "ImageHelper.h"
#include <cassert>

Bitmap::Bitmap(int width, int height, int channels) 
		: m_width(width), 
		  m_height(height), 
		  m_channels(channels),
		  m_pixels(width * height) { }

const std::vector<Pixel> &Bitmap::getPixels() const
{
	return m_pixels;
}

std::vector<unsigned char> Bitmap::getRawPixels() const
{
	std::vector<unsigned char> res;
	for (const auto &pixel : m_pixels)
	{
		res.emplace_back(pixel.R);
		res.emplace_back(pixel.G);
		res.emplace_back(pixel.B);
		res.emplace_back(pixel.A);
	}

	return res;
}

int Bitmap::getWidth() const
{
	return m_width;
}

int Bitmap::getHeight() const
{
	return m_height;
}

int Bitmap::getChannels() const
{
	return m_channels;
}

Pixel Bitmap::getPixel(int x, int y) const
{
	assert(x < m_width && y < m_height);
	return m_pixels[x * m_height + y];
}

void Bitmap::setPixel(int x, int y, Pixel pixel)
{
	assert(x < m_width && y < m_height);
	m_pixels[x * m_height + y] = pixel;
}
