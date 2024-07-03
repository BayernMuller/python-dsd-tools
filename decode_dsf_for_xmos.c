#include "bitreversed.h"

void dsfxmos(int size, unsigned char *indata, unsigned char *outdata, int lsbfirst)
{
    int j = 0;
    if (lsbfirst == 1)
    {
        for (int i = 0; i < size; i += 8)
        {
            outdata[i + 0x00] = bitreverse[indata[j + 0x00]];
            outdata[i + 0x01] = bitreverse[indata[j + 0x01]];
            outdata[i + 0x02] = bitreverse[indata[j + 0x02]];
            outdata[i + 0x03] = bitreverse[indata[j + 0x03]];
            outdata[i + 0x04] = bitreverse[indata[j + 4096 + 0x00]];
            outdata[i + 0x05] = bitreverse[indata[j + 4096 + 0x01]];
            outdata[i + 0x06] = bitreverse[indata[j + 4096 + 0x02]];
            outdata[i + 0x07] = bitreverse[indata[j + 4096 + 0x03]];
            j += 4;
        }
    }
    else
    {
        j = 0;
        for (int i = 0; i < size; i += 8)
        {
            outdata[i + 0x00] = indata[j + 0x00];
            outdata[i + 0x01] = indata[j + 0x01];
            outdata[i + 0x02] = indata[j + 0x02];
            outdata[i + 0x03] = indata[j + 0x03];
            outdata[i + 0x04] = indata[j + 4096 + 0x00];
            outdata[i + 0x05] = indata[j + 4096 + 0x01];
            outdata[i + 0x06] = indata[j + 4096 + 0x02];
            outdata[i + 0x07] = indata[j + 4096 + 0x03];
            j += 4;
        }
    }
}