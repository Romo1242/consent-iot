#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ascon-c/encrypt.h"
#include "ascon-c/api.h"

int main() {
    int consent;
    printf("Consentement utilisateur (1=oui, 0=non) : ");
    scanf("%d", &consent);

    if (consent == 1) {
        // Collecte et chiffrement des données
        uint8_t message[] = "DATA: temperature=25.1;ID=DEV001;timestamp=1729293";
        uint8_t key[CRYPTO_KEYBYTES] = {0};
        uint8_t nonce[CRYPTO_NPUBBYTES] = {0};
        uint8_t ciphertext[128];
        size_t clen;

        crypto_aead_encrypt(ciphertext, &clen, message, strlen((char*)message), NULL, 0, NULL, nonce, key);

        printf("Consentement OUI : Données collectées et chiffrées (ASCON) :\n");
        for (size_t i = 0; i < clen; i++) {
            printf("%02x", ciphertext[i]);
        }
        printf("\n");
    } else {
        printf("Consentement NON : aucune donnée collectée, processus arrêté.\n");
    }
    return 0;
}
