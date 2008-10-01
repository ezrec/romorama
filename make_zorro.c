#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
 
#define LEN 800
#define SPC 300

struct pins {
	int number;
	const char *label;
	const char *type;
};

struct pins zorro_i[] = {
	{ 1, "GND", "pwr" },	// 1
	{ 2, "GND", "pwr" },	// 2
	{ 3, "GND", "pwr" },	// 3
	{ 4, "GND", "pwr" },	// 4
	{ 13, "GND", "pwr" },	// 13
	{ 25, "GND", "pwr" },	// 25
	{ 37, "GND", "pwr" },	// 37
	{ 85, "GND", "pwr" },	// 85
	{ 49, "GND", "pwr" },	// 49
	{ 61, "GND", "pwr" },	// 61
	{ 73, "GND", "pwr" },	// 73
	{ 5, "+5VDC", "pwr" },	// 5
	{ 6, "+5VDC", "pwr" },	// 6
	{ 8, "-5VDC", "pwr" },	// 8
	{ 10, "+12VDC", "pwr" },	// 10
	{ 12, "/CFGIN", "out" },	// 12
	{ 16, "/C1", "clk" },	// 16
	{ 14, "/C3", "clk" },	// 14
	{ 15, "CDAC", "clk" },	// 15
	{ 50, "E_CLK", "clk" },	// 50
	{ 20, "/PALOPE", "" },	// 20	DO NOT CONNECT! -12v on Zorro II!
	{ 29, "A1", "io" },	// 29
	{ 27, "A2", "io" },	// 27
	{ 26, "A3", "io" },	// 26
	{ 24, "A4", "io" },	// 24
	{ 21, "A5", "io" },	// 21
	{ 23, "A6", "io" },	// 23
	{ 28, "A7", "io" },	// 28
	{ 30, "A8", "io" },	// 30
	{ 32, "A9", "io" },	// 32
	{ 34, "A10", "io" },	// 34
	{ 36, "A11", "io" },	// 36
	{ 38, "A12", "io" },	// 38
	{ 39, "A13", "io" },	// 39
	{ 41, "A14", "io" },	// 41
	{ 43, "A15", "io" },	// 43
	{ 45, "A16", "io" },	// 45
	{ 47, "A17", "io" },	// 47
	{ 52, "A18", "io" },	// 52
	{ 54, "A19", "in" },	// 54
	{ 56, "A20", "io" },	// 56
	{ 58, "A21", "io" },	// 58
	{ 57, "A22", "io" },	// 57
	{ 59, "A23", "io" },	// 59
	{ 68, "READ", "io" },	// 68	Read-not-Write
	{ 70, "/LDS", "io" },	// 70	D0-D7 are valid for write
	{ 72, "/UDS", "io" },	// 72	D08-D15 are valid for write
	{ 74, "/AS", "io" },	// 74	Address/READ line strobe
	{ 17, "/OVR", "in" },	// 17
	{ 18, "XRDY", "in" },	// 18
	{ 75, "D0", "io" },	// 75
	{ 77, "D1", "io" },	// 77
	{ 79, "D2", "io" },	// 79
	{ 81, "D3", "io" },	// 81
	{ 83, "D4", "io" },	// 83
	{ 86, "D5", "io" },	// 86
	{ 84, "D6", "io" },	// 84
	{ 82, "D7", "io" },	// 82
	{ 80, "D8", "io" },	// 80
	{ 78, "D9", "io" },	// 78
	{ 76, "D10", "io" },	// 76
	{ 71, "D11", "io" },	// 71
	{ 69, "D12", "io" },	// 69
	{ 67, "D13", "io" },	// 67
	{ 65, "D14", "io" },	// 65
	{ 63, "D15", "io" },	// 63
	{ 66, "/DTACK", "in" },	// 66	Data xfer acknowledge
	{ 31, "FC0", "out" },	// 31
	{ 33, "FC1", "out" },	// 33
	{ 35, "FC2", "out" },	// 35
	{ 40, "/IPL0", "io" },	// 40
	{ 42, "/IPL1", "io" },	// 42
	{ 44, "/IPL2", "io" },	// 44
	{ 19, "/INT2", "in" },	// 19
	{ 22, "/INT6", "in" },	// 22
	{ 46, "/BERR", "in" },	// 46
	{ 48, "/VPA", "io" },	// 48	
	{ 51, "/VMA", "io" },	// 51
	{ 53, "/RST", "oc" },	// 53	Soft reset
	{ 55, "/HLT", "oc" },	// 55	Powerup reset
	{ 60, "/BR", "in" },	// 60	Bus (DMA) request
	{ 62, "/BGACK", "in" },	// 62	Bus (DMA) in progress
	{ 64, "/BG", "out" },	// 64	Bus (DMA) granted
};

struct pins zorro_ii[] = {
	{ 1, "GND", "pwr" },	// 1
	{ 2, "GND", "pwr" },	// 2
	{ 3, "GND", "pwr" },	// 3
	{ 4, "GND", "pwr" },	// 4
	{ 5, "+5VDC", "pwr" },	// 5
	{ 6, "+5VDC", "pwr" },	// 6
	{ 7, "/OWN", "in" },	// 7
	{ 8, "-5VDC", "pwr" },	// 8
	{ 9, "/SLAVE", "in" },	// 9
	{ 10, "+12VDC", "pwr" },	// 10
	{ 11, "/CFGOUT", "in" },	// 11
	{ 12, "/CFGIN", "out" },	// 12
	{ 13, "GND", "pwr" },	// 13
	{ 14, "/C3", "clk" },	// 14
	{ 15, "CDAC", "clk" },	// 15
	{ 16, "/C1", "clk" },	// 16
	{ 17, "/OVR", "in" },	// 17
	{ 18, "XRDY", "in" },	// 18
	{ 19, "/INT2", "in" },	// 19
	{ 20, "-12VDC", "pwr" },	// 20
	{ 21, "A5", "io" },	// 21
	{ 22, "/INT6", "in" },	// 22
	{ 23, "A6", "io" },	// 23
	{ 24, "A4", "io" },	// 24
	{ 25, "GND", "pwr" },	// 25
	{ 26, "A3", "io" },	// 26
	{ 27, "A2", "io" },	// 27
	{ 28, "A7", "io" },	// 28
	{ 29, "A1", "io" },	// 29
	{ 30, "A8", "io" },	// 30
	{ 31, "FC0", "out" },	// 31
	{ 32, "A9", "io" },	// 32
	{ 33, "FC1", "out" },	// 33
	{ 34, "A10", "io" },	// 34
	{ 35, "FC2", "out" },	// 35
	{ 36, "A11", "io" },	// 36
	{ 37, "GND", "pwr" },	// 37
	{ 38, "A12", "io" },	// 38
	{ 39, "A13", "io" },	// 39
	{ 41, "A14", "io" },	// 41
	{ 43, "A15", "io" },	// 43
	{ 45, "A16", "io" },	// 45
	{ 46, "/BERR", "in" },	// 46
	{ 47, "A17", "io" },	// 47
	{ 49, "GND", "pwr" },	// 49
	{ 50, "E_CLK", "clk" },	// 50
	{ 52, "A18", "io" },	// 52
	{ 53, "/RST", "oc" },	// 53	Soft reset
	{ 54, "A19", "in" },	// 54
	{ 55, "/HLT", "oc" },	// 55	Powerup reset
	{ 56, "A20", "io" },	// 56
	{ 57, "A22", "io" },	// 57
	{ 58, "A21", "io" },	// 58
	{ 59, "A23", "io" },	// 59
	{ 60, "/BR", "in" },	// 60	Bus (DMA) request
	{ 61, "GND", "pwr" },	// 61
	{ 62, "/BGACK", "in" },	// 62	Bus (DMA) in progress
	{ 63, "D15", "io" },	// 63
	{ 64, "/BG", "out" },	// 64	Bus (DMA) granted
	{ 65, "D14", "io" },	// 65
	{ 66, "/DTACK", "in" },	// 66	Data xfer acknowledge
	{ 67, "D13", "io" },	// 67
	{ 68, "READ", "io" },	// 68	Read-not-Write
	{ 69, "D12", "io" },	// 69
	{ 70, "/LDS", "io" },	// 70	D0-D7 are valid for write
	{ 71, "D11", "io" },	// 71
	{ 72, "/UDS", "io" },	// 72	D08-D15 are valid for write
	{ 73, "GND", "pwr" },	// 73
	{ 74, "/AS", "io" },	// 74	Address/READ line strobe
	{ 75, "D0", "io" },	// 75
	{ 76, "D10", "io" },	// 76
	{ 77, "D1", "io" },	// 77
	{ 78, "D9", "io" },	// 78
	{ 79, "D2", "io" },	// 79
	{ 80, "D8", "io" },	// 80
	{ 81, "D3", "io" },	// 81
	{ 82, "D7", "io" },	// 82
	{ 83, "D4", "io" },	// 83
	{ 84, "D6", "io" },	// 84
	{ 85, "GND", "pwr" },	// 85
	{ 86, "D5", "io" },	// 86
	{ 87, "GND", "pwr" },	// 87
	{ 88, "GND", "pwr" },	// 88
	{ 89, "GND", "pwr" },	// 89
	{ 90, "GND", "pwr" },	// 90
	{ 91, "GND", "pwr" },	// 91
	{ 92, "E7M", "clk" },	// 92	System clock
	{ 93, "DOE", "io" },	// 93	Data output enable
	{ 94, "/BUSRST", "out" },	// 94	Bus (Autoconfig) reset
	{ 95, "/GBG", "io" },	// 95	Bus (DMA) request-to-end
	{ 99, "GND", "pwr" },	// 99
	{ 100, "GND", "pwr" },	// 100
};

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

void out_schem(const char *symbol, struct pins *p, size_t len)
{
        int i, start, end, j;
        int spacing = SPC;
        FILE *ouf;
        char buff[1024];

        snprintf(buff, sizeof(buff), "symbols/%s.sym", symbol);

        ouf = fopen(buff, "w");
        if (ouf == NULL) {
        	perror(buff);
        	exit(1);
        }

        fprintf(ouf,"v 20080930\n");
	fprintf(ouf,"device=%s\n", symbol);
	fprintf(ouf,"refdes=P?\n");
 
        for (i = len-1, j = 1; i >0 ; i--, j++) {
                fprintf(ouf, "N 200 %d %d %d 4\n{\n",
                        j * spacing, 200 + LEN, j * spacing);
                fprintf(ouf, "T %d %d 5 10 1 1 0 0\n", 200 + LEN/2, spacing * j + 30);
                fprintf(ouf, "pinlabel=%s\n",p[i].label);
                fprintf(ouf, "T %d %d 5 10 1 1 0 0\n", LEN / 2 - 100, spacing * j);
                fprintf(ouf, "pinnumber=%d\n", p[i].number);
                fprintf(ouf, "T %d %d 5 10 0 1 0 0\n", LEN / 2 - 100, spacing * j);
                fprintf(ouf, "pintype=%s\n", p[i].type);
        	fprintf(ouf, "}\n");
        }
 
        return;
}

int main(int argc, char **argv)
{
      	out_schem("ZORRO_I", zorro_i, ARRAY_SIZE(zorro_i));
      	out_schem("ZORRO_II", zorro_ii, ARRAY_SIZE(zorro_ii));

      	return 0;
}


