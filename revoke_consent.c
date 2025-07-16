#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ascon-c/hash.h"
#include "ascon-c/api.h"

int main() {
    // Simuler la révocation du consentement
    const char *device_id = "DEV001";
    const char *timestamp = "1729300";
    const char *revocation_state = "REVOKED";
    char message[128];

    snprintf(message, sizeof(message), "REVOKE=1|ID=%s|TIMESTAMP=%s|STATE=%s", device_id, timestamp, revocation_state);

    uint8_t digest[CRYPTO_BYTES];
    ascon_hash(digest, (const uint8_t *)message, strlen(message));

    printf("Engagement ASCON-HASH (révocation) :\n");
    for (size_t i = 0; i < CRYPTO_BYTES; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}
