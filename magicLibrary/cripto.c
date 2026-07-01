#include "cripto.h"
#include <string.h>

void criptografar(char *str) {
    const char *chave = "HEXA";
    int tam_chave = 4;

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char passo1 = (unsigned char)(255 - (unsigned char)str[i]);
        
        unsigned char caractere_chave = (unsigned char)chave[i % tam_chave];
        
        str[i] = (char)(passo1 + caractere_chave);
    }
}
// VAMO BRASIL DALE NELES!
void descriptografar(char *str) {
    const char *chave = "HEXA";
    int tam_chave = 4;

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char caractere_chave = (unsigned char)chave[i % tam_chave];
        unsigned char passo1_inverso = (unsigned char)((unsigned char)str[i] - caractere_chave);
        

        str[i] = (char)(255 - passo1_inverso);
    }
}