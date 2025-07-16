#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ascon-c/hash.h"
#include "ascon-c/api.h"

int main() {
    const char *input_message = "CONSENT=1|ID=USER123|TIMESTAMP=1729293";
    size_t message_length = strlen(input_message);

    uint8_t digest[CRYPTO_BYTES];

    ascon_hash(digest, (const uint8_t *)input_message, message_length);

    printf("Engagement ASCON-HASH :\n");
    for (size_t i = 0; i < CRYPTO_BYTES; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}
