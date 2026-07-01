#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cripto.h"
#include "arquivo.h"




static void paraHex(const char origem, chardestinoHex) {
    int i;
    int len = (int)strlen(origem);
    for (i = 0; i < len; i++) {
        sprintf(destinoHex + (i * 2), "%02X", (unsigned char)origem[i]);
    }
    destinoHex[len * 2] = '\0';
}

static void deHex(const char origemHex, chardestino) {
    int i;
    int len = (int)strlen(origemHex) / 2;
    unsigned int byte;
    for (i = 0; i < len; i++) {
        sscanf(origemHex + (i * 2), "%2x", &byte);
        destino[i] = (char)byte;
    }
    destino[len] = '\0';
}