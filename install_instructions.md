# Instructions d'installation

## Dépendances système (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install -y git build-essential python3 python3-pip openssl gcc-arm-none-eabi gdb-multiarch cmake
```

## Librairies cryptographiques

### ASCON (C)
```bash
cd ascon
if [ ! -d ascon-c ]; then git clone https://github.com/ascon/ascon-c.git; fi
cd ascon-c
make
```

### Microsoft SEAL (C++)
```bash
cd homomorphic
if [ ! -d SEAL ]; then git clone https://github.com/microsoft/SEAL.git; fi
cd SEAL
cmake -S . -B build
cmake --build build
sudo cmake --install build
```

## Python (SHAKE128, Flask)
```bash
cd python
pip3 install -r requirements.txt
```

## Compilation des exemples C (ASCON)

```bash
cd ascon
make
```

## Compilation du module SEAL (chiffrement homomorphe)

```bash
cd homomorphic
mkdir -p build && cd build
cmake ..
make
```

---

Pour toute question, voir les README de chaque dossier.
