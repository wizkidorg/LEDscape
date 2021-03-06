#include <stdint.h>
#include "bitslice.h"
#include "util.h"

int main(void)
{
	uint8_t bitmap[2][9][3] = { 
		{
			{ 0x03, 0x03, 0x03 },
			{ 0x00, 0x00, 0x00 },
			{ 0x03, 0x03, 0x03 },
			{ 0x00, 0x00, 0x00 },
			{ 0x03, 0x03, 0x03 },
			{ 0x00, 0x00, 0x00 },
			{ 0x03, 0x03, 0x03 },
			{ 0x00, 0x00, 0x00 },
			{ 0x03, 0x03, 0x03 },
		},
		{
			{ 0x00, 0x00, 0x00 },
			{ 0x03, 0x03, 0x03 },
			{ 0x01, 0x02, 0x04 },
			{ 0xF2, 0xF4, 0xF8 },
			{ 0x04, 0x08, 0x10 },
			{ 0xF8, 0xF0, 0x22 },
			{ 0x10, 0x20, 0x40 },
			{ 0xF1, 0x4F, 0x8F },
			{ 0x02, 0x80, 0x00 },
		},
	};

	hexdump(stdout, bitmap, sizeof(bitmap));

	uint8_t out[1024];

	bitslice(out, NULL, (const uint8_t*) bitmap, 9, 2, 1);

	hexdump(stdout, out, 8 * 2 * 3);
}
