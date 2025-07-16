import requests

url = "http://127.0.0.1:5000/api/consent"
data = {"user_id": "USER123", "consent": 1}
r = requests.post(url, json=data)
print(r.json())

verify_url = "http://127.0.0.1:5000/api/verify/USER123"
r = requests.get(verify_url)
print(r.json())

# Test révocation
data_revoke = {"user_id": "USER123"}
r = requests.post("http://127.0.0.1:5000/api/revoke", json=data_revoke)
print(r.json())

audit_url = "http://127.0.0.1:5000/api/audit/USER123"
r = requests.get(audit_url)
print(r.json())
