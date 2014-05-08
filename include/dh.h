#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh512()
	{
	static unsigned char dh512_p[]={
		0x88,0x68,0x22,0x68,0xE0,0x3A,0x0C,0x8A,0xDA,0x34,0x47,0xC0,
		0x78,0xF3,0xAC,0x67,0xB4,0x95,0x95,0x6F,0x97,0xAF,0xD4,0xAF,
		0xB8,0x13,0xB0,0x21,0xCC,0x9E,0x29,0xAB,0x5B,0xAA,0x3B,0x5F,
		0xC6,0x3D,0x58,0x9B,0xA2,0x44,0x28,0xBC,0x31,0x54,0x01,0x96,
		0x2D,0x37,0x73,0xCA,0xC7,0x20,0x29,0x11,0x08,0xC5,0x46,0xE5,
		0xF2,0x5D,0x02,0x63,
		};
	static unsigned char dh512_g[]={
		0x02,
		};
	DH *dh;

	if ((dh=DH_new()) == NULL) return(NULL);
	dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
	dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
	if ((dh->p == NULL) || (dh->g == NULL))
		{ DH_free(dh); return(NULL); }
	return(dh);
	}
