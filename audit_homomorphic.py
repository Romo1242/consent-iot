from Crypto.Hash import SHAKE128

# Simuler un ciphertext sous forme de chaîne (en vrai, on utiliserait le binaire du ciphertext SEAL)
ciphertext_hex = "a1b2c3d4e5f6..."  # à remplacer par la vraie valeur hex du ciphertext

shake = SHAKE128.new()
shake.update(ciphertext_hex.encode('utf-8'))
digest = shake.read(32)
print("Engagement SHAKE128 sur le ciphertext audité :")
print(digest.hex())
