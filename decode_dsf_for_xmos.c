inline unsigned char revbits(unsigned char x)
{
    x = ((x & 0x55) << 1) | ((x & 0xaa) >> 1);
    x = ((x & 0x33) << 2) | ((x & 0xcc) >> 2);
    x = ((x & 0x0f) << 4) | ((x & 0xf0) >> 4);
    return x;
}

void dsfxmos(int size, unsigned char *indata, unsigned char *outdata, int lsbfirst)
{
    int j = 0;
    if (lsbfirst == 1)
    {
        for (int i = 0; i < size; i += 8)
        {
            outdata[i + 0x00] = revbits(indata[j + 0x00]);
            outdata[i + 0x01] = revbits(indata[j + 0x01]);
            outdata[i + 0x02] = revbits(indata[j + 0x02]);
            outdata[i + 0x03] = revbits(indata[j + 0x03]);
            outdata[i + 0x04] = revbits(indata[j + 4096 + 0x00]);
            outdata[i + 0x05] = revbits(indata[j + 4096 + 0x01]);
            outdata[i + 0x06] = revbits(indata[j + 4096 + 0x02]);
            outdata[i + 0x07] = revbits(indata[j + 4096 + 0x03]);
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