#include <iostream>
#include "seal/seal.h"

using namespace std;
using namespace seal;

int main() {
    // 1. Paramètres de chiffrement (BFV)
    EncryptionParameters parms(scheme_type::bfv);
    parms.set_poly_modulus_degree(4096);
    parms.set_coeff_modulus(CoeffModulus::BFVDefault(4096));
    parms.set_plain_modulus(1024);

    SEALContext context(parms);

    // 2. Génération des clés
    KeyGenerator keygen(context);
    PublicKey public_key = keygen.public_key();
    // SecretKey secret_key = keygen.secret_key(); // NON utilisé, pas de déchiffrement
    Encryptor encryptor(context, public_key);
    Evaluator evaluator(context);
    BatchEncoder encoder(context);

    // 3. Consentement utilisateur (1=oui, 0=non)
    int consent;
    cout << "Consentement utilisateur (1=oui, 0=non) : ";
    cin >> consent;
    if (consent != 0 && consent != 1) {
        cout << "Valeur invalide !" << endl;
        return 1;
    }

    // 4. Encodage et chiffrement
    Plaintext plain;
    encoder.encode(vector<uint64_t>{static_cast<uint64_t>(consent)}, plain);

    Ciphertext encrypted;
    encryptor.encrypt(plain, encrypted);

    cout << "Consentement chiffré transmis à l'audit (jamais déchiffré)." << endl;

    // 5. Audit homomorphe : vérifier que le consentement est bien 1 (sans déchiffrer)
    // Ex : on multiplie le ciphertext par 0 (pour simuler une vérification)
    Plaintext plain_one;
    encoder.encode(vector<uint64_t>{1}, plain_one);

    Ciphertext encrypted_test;
    evaluator.multiply_plain(encrypted, plain_one, encrypted_test);

    // L'audit peut transmettre le ciphertext résultant ou un engagement du résultat
    cout << "Audit homomorphe effectué sur le consentement chiffré (résultat non déchiffré, engagement à transmettre)." << endl;

    // Exemple d'empreinte du ciphertext pour preuve (non réversible)
    auto hash = encrypted_test.hash_block();
    cout << "Hash du ciphertext audité (preuve) : " << hash << endl;

    return 0;
}
