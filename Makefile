CC=gcc
CFLAGS=-I./ascon-c -Wall

all: consent_hash encrypt_if_no_consent revoke_consent

consent_hash: consent_hash.c ascon-c/hash.c ascon-c/permutations.c
	$(CC) $(CFLAGS) -o consent_hash consent_hash.c ascon-c/hash.c ascon-c/permutations.c

encrypt_if_no_consent: encrypt_if_no_consent.c ascon-c/encrypt.c ascon-c/permutations.c
	$(CC) $(CFLAGS) -o encrypt_if_no_consent encrypt_if_no_consent.c ascon-c/encrypt.c ascon-c/permutations.c

revoke_consent: revoke_consent.c ascon-c/hash.c ascon-c/permutations.c
	$(CC) $(CFLAGS) -o revoke_consent revoke_consent.c ascon-c/hash.c ascon-c/permutations.c

clean:
	rm -f consent_hash encrypt_if_no_consent revoke_consent
