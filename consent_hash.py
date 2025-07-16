from Crypto.Hash import SHAKE128

message = "CONSENT=1|ID=USER123|TIMESTAMP=1729293".encode('utf-8')
shake = SHAKE128.new()
shake.update(message)
digest = shake.read(32)
print("Engagement SHAKE128 :")
print(digest.hex())
