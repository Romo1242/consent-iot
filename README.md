# Scripts Python

- `consent_hash.py` : Génère une empreinte SHAKE128 du consentement.
- `api_flask.py` : API REST Flask simulant la gestion du consentement, la révocation et l'audit (jamais de déchiffrement).
- `test_api.py` : Teste l’API Flask (POST + GET + révocation + audit).
- `revoke_consent.py` : Génère un engagement non réversible de révocation du consentement.
- `audit_homomorphic.py` : Génère un engagement SHAKE128 sur un ciphertext audité (preuve non réversible).

## Installation

```bash
pip install -r requirements.txt
```

## Lancement de l’API Flask

```bash
python api_flask.py
```
