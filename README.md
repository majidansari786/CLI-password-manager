# 🔐 Simple Password Manager (C Program)

A lightweight command-line password manager written in **C**, using a simple **XOR cipher** to encrypt stored passwords.  
Passwords are saved in a text file and can be retrieved by searching for their associated website.

---

## 📌 Features
- Add a new password record (sitename, username, password)
- Search for existing records by sitename
- XOR-based encryption/decryption
- Simple delimiter-based file format
- Lightweight and easy to compile

---

## 🧠 How It Works

### 🔑 Encryption / Decryption  
This program uses a **single-byte XOR cipher**:

# 🔑 How XOR Encryption Works

XOR (Exclusive OR) is a **bitwise operator** commonly used in simple encryption systems.  
It works on individual bits (0s and 1s).

---

## 1. XOR Truth Table

| A | B | A XOR B |
|---|---|----------|
| 0 | 0 |    0     |
| 1 | 0 |    1     |
| 0 | 1 |    1     |
| 1 | 1 |    0     |

➡️ XOR outputs **1 when the bits are different**.

---

## 2. Why XOR Can Encrypt and Decrypt

XOR is **reversible**, meaning the same operation can encrypt and decrypt:



# Preview

<img width="567" height="510" alt="image" src="https://github.com/user-attachments/assets/32dbb53a-a565-4896-a36a-355e28281620" />

