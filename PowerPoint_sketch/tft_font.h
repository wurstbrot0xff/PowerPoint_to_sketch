#pragma once

#include <Arduino.h>

  typedef struct {
      const unsigned char *index;
      const unsigned char *unicode;
      const unsigned char *data;
      unsigned char version;
      unsigned char reserved;
      unsigned char index1_first;
      unsigned char index1_last;
      unsigned char index2_first;
      unsigned char index2_last;
      unsigned char bits_index;
      unsigned char bits_width;
      unsigned char bits_height;
      unsigned char bits_xoffset;
      unsigned char bits_yoffset;
      unsigned char bits_delta;
      unsigned char line_space;
      unsigned char cap_height;
  } tftfont_t;


#ifdef __cplusplus
#include <TFT_eSPI.h>

class TFT_ext: public TFT_eSPI
{
public:

  size_t write(uint8_t c)
  {
    if (font) {
      if (c == '\n') {
        cursor_y += font->line_space;
        cursor_x = 0;
      } else {
        drawFontChar(c);
      }
      return 1;
    } else
      return TFT_eSPI::write(c);
  }

  void setTTFFont(const tftfont_t &f)
  {
    font = &f;
    setTextFont(255);
  }

  void drawFontChar(unsigned int c) {

    uint bitoffset;
    const uint8_t *data;

    if (c >= font->index1_first && c <= font->index1_last) {
      bitoffset = c - font->index1_first;
      bitoffset *= font->bits_index;
    } else if (c >= font->index2_first && c <= font->index2_last) {
      bitoffset = c - font->index2_first + font->index1_last - font->index1_first + 1;
      bitoffset *= font->bits_index;
    } else if (font->unicode) {
      return; // TODO: implement sparse unicode
    } else {
      return;
    }

    data = font->data + fetchbits_unsigned(font->index, bitoffset, font->bits_index);
    bitoffset = 0;
    uint encoding = fetchbits_unsigned(data, bitoffset, 3);
    if (encoding != 0) return;

    uint width  = fetchbits_unsigned(data, bitoffset, font->bits_width);
    uint height = fetchbits_unsigned(data, bitoffset, font->bits_height);

    int xoffset = fetchbits_signed(data, bitoffset, font->bits_xoffset);
    int yoffset = fetchbits_signed(data, bitoffset, font->bits_yoffset);
    uint delta  = fetchbits_unsigned(data, bitoffset, font->bits_delta);

    // horizontally, we draw every pixel, or none at all
    if (cursor_x < 0) cursor_x = 0;
    int origin_x = cursor_x + xoffset;

    if (origin_x < 0) {
      cursor_x -= xoffset;
      origin_x = 0;
    }

    if (origin_x + (int)width > _width) {
      if (false /*!wrap*/) return;
      origin_x = 0;
      if (xoffset >= 0) {
        cursor_x = 0;
      } else {
        cursor_x = -xoffset;
      }
      cursor_y += font->line_space;
    }

    if (cursor_y >= _height) return;
    cursor_x += delta;
    if (height == 0) return;

    int linecount = height;
    uint y = cursor_y + font->cap_height - height - yoffset;
//fillRect(cursor_x, y, width, height, 0);
    startWrite();
    while (linecount) {
      uint xsize, bits, n, x;

      if (fetchbit(data, bitoffset) == 0) {
        n = 1;
      } else {
        n = 2 + fetchbits_unsigned(data, bitoffset, 3);
      }

      x = 0;
      do {
        xsize = width - x;
        if (xsize > 32) xsize = 32;
        bits = fetchbits_unsigned(data, bitoffset, xsize);
        if (bits != 0) drawFontBits(bits, xsize, origin_x + x, y, n);
        x += xsize;
      } while (x < width);
      y += n;
      linecount -= n;
    }
    endWrite();
}

protected:

  const tftfont_t *font = nullptr;

private:

  inline uint fetchbit(const uint8_t *p, uint &index)
  {
      uint r = (p[index >> 3] & (0x80 >> (index & 7)));
      index++;
      return r;
  }

  uint32_t fetchbits_unsigned(const uint8_t *p, uint &index, uint required)
  {
      uint32_t val;
      uint8_t *s = (uint8_t *)&p[index >> 3];
      val = s[0] << 24 | (s[1] << 16) | (s[2] << 8) | s[3];
      val <<= index & 7; // shift out used bits
      if (32 - (index & 7) < required)  // need to get more bits
          val |= (s[4] >> (8 - (index & 7)));
      val >>= 32 - required; // right align the bits
      index += required;
      return val;
  }

  int32_t fetchbits_signed(const uint8_t *p, uint &index, uint required)
  {
      uint32_t val = fetchbits_unsigned(p, index, required);
      if (val & (1 << (required - 1)))
          return (int32_t)val - (1 << required);
      return val;
  }

  void drawFontBits(uint32_t bits, uint numbits, uint x, uint y, uint repeat)
  {
      bits <<= 32-numbits; // left align bits
      do {
        uint w = __builtin_clz(bits); // skip over leading zeros
        if (w > numbits) w = numbits;
        numbits -= w;
        x += w;
        bits <<= w;
        w = __builtin_clz(~bits); //count leading ones
        if (w > 0) {
          if (w > numbits) w = numbits;
          numbits -= w;
          bits <<= w;
          setWindow(x, y, x + w - 1, y + repeat - 1); // write a block of pixels w x repeat sized
          x += w;
          w *= repeat;
          pushBlock(textcolor, w);
        }
      } while (bits > 0 && numbits > 0);
  }
};
#endif