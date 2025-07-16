from flask import Flask, request, jsonify
from Crypto.Hash import SHAKE128
import time

app = Flask(__name__)

engagements_db = {}

# Simulation d'un stockage d'état de révocation
revocations_db = {}

def generate_engagement(consent, user_id):
    timestamp = int(time.time())
    message = f"CONSENT={consent}|ID={user_id}|TIMESTAMP={timestamp}".encode('utf-8')
    shake = SHAKE128.new()
    shake.update(message)
    digest = shake.read(32)
    return digest.hex(), timestamp

def generate_revocation(user_id):
    timestamp = int(time.time())
    message = f"REVOKE=1|ID={user_id}|TIMESTAMP={timestamp}|STATE=REVOKED".encode('utf-8')
    shake = SHAKE128.new()
    shake.update(message)
    digest = shake.read(32)
    return digest.hex(), timestamp

@app.route('/api/consent', methods=['POST'])
def collect_consent():
    data = request.get_json()
    user_id = data.get("user_id")
    consent = data.get("consent")
    if user_id is None or consent not in [0, 1]:
        return jsonify({"error": "Paramètres invalides"}), 400
    if consent == 0:
        return jsonify({"status": "Refus : aucune donnée collectée"}), 200
    engagement, timestamp = generate_engagement(consent, user_id)
    engagements_db[user_id] = {
        "engagement": engagement,
        "consent": consent,
        "timestamp": timestamp
    }
    return jsonify({
        "status": "Consentement reçu, données collectées et chiffrées",
        "engagement_hash": engagement,
        "timestamp": timestamp
    }), 200

@app.route('/api/verify/<user_id>', methods=['GET'])
def verify_consent(user_id):
    record = engagements_db.get(user_id)
    if not record:
        return jsonify({"error": "Aucun consentement enregistré"}), 404
    return jsonify(record), 200

@app.route('/api/revoke', methods=['POST'])
def revoke_consent():
    data = request.get_json()
    user_id = data.get("user_id")
    if user_id is None:
        return jsonify({"error": "Paramètres invalides"}), 400
    revocation_hash, timestamp = generate_revocation(user_id)
    revocations_db[user_id] = {
        "revocation_hash": revocation_hash,
        "timestamp": timestamp
    }
    return jsonify({
        "status": "Consentement révoqué",
        "revocation_hash": revocation_hash,
        "timestamp": timestamp
    }), 200

@app.route('/api/audit/<user_id>', methods=['GET'])
def audit_consent(user_id):
    # Simule un audit (retourne l'engagement, jamais la donnée originale)
    record = engagements_db.get(user_id)
    revoked = revocations_db.get(user_id)
    if not record:
        return jsonify({"error": "Aucun consentement à auditer"}), 404
    audit_result = {
        "engagement_hash": record["engagement"],
        "revoked": bool(revoked),
        "revocation_hash": revoked["revocation_hash"] if revoked else None
    }
    return jsonify(audit_result), 200

if __name__ == '__main__':
    app.run(debug=True, port=5000)
