from Crypto.Hash import SHAKE128

device_id = "DEV001"
timestamp = "1729300"
revocation_state = "REVOKED"
message = f"REVOKE=1|ID={device_id}|TIMESTAMP={timestamp}|STATE={revocation_state}".encode('utf-8')

shake = SHAKE128.new()
shake.update(message)
digest = shake.read(32)
print("Engagement SHAKE128 (révocation) :")
print(digest.hex())
