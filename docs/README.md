# File Encryption & Decryption Tool - README

## 🔐 Project Overview

**File Encryption & Decryption Tool System** is a professional, full-stack web application for secure file handling and data protection. It features advanced encryption algorithms (Caesar Cipher and XOR Cipher) implemented in C++, a robust C++ backend, and a beautiful cybersecurity-themed frontend.

This project is designed as an enterprise-grade solution suitable for:
- **Academic Projects**: Final semester OOP project
- **Professional Use**: Real-world file encryption needs
- **Security Applications**: Cryptographic operations and key management

---

## ✨ Features

### 🎯 Core Features
- ✅ **Multiple Encryption Algorithms**: Caesar Cipher & XOR Cipher
- ✅ **User Authentication**: Secure JWT-based authentication
- ✅ **File Encryption/Decryption**: Drag-and-drop file upload
- ✅ **Key Management**: Generate, store, and manage encryption keys
- ✅ **Encryption History**: Track all encryption/decryption operations
- ✅ **User Profiles**: Manage account settings and security
- ✅ **Reports & Analytics**: Export encryption history as PDF/CSV
- ✅ **Responsive Design**: Works on desktop and mobile devices
- ✅ **Dark Theme UI**: Modern cybersecurity dashboard design

### 🏗️ Technical Features
- Object-Oriented Programming (OOP) principles throughout
- Encapsulation, Inheritance, Polymorphism, Abstraction
- SQLite database with normalized schema
- RESTful API architecture
- C++ encryption library integration
- JWT token-based security
- Password hashing with bcrypt

---

## 📁 Project Structure

```
File-Encryption-Tool/
│
├── frontend/                          # React-like frontend (HTML/CSS/JS)
│   ├── index.html                    # Landing page
│   ├── login.html                    # Login page
│   ├── register.html                 # Registration page
│   ├── dashboard.html                # Main dashboard
│   ├── encrypt.html                  # File encryption
│   ├── decrypt.html                  # File decryption
│   ├── keys.html                     # Key management
│   ├── profile.html                  # User profile
│   ├── reports.html                  # Encryption reports
│   ├── css/
│   │   └── style.css                # Cybersecurity theme styling
│   └── js/
│       └── app.js                   # Frontend application logic
│
├── backend/
│   └── cpp/                          # C++ encryption library and optional native backend
│       ├── include/                 # Header files
│       │   ├── Cipher.h            # Abstract base class
│       │   ├── CaesarCipher.h      # Caesar cipher
│       │   ├── XORCipher.h         # XOR cipher
│       │   ├── EncryptionManager.h
│       │   ├── DecryptionManager.h
│       │   ├── KeyManager.h
│       │   ├── FileHandler.h
│       │   └── User.h
│       ├── src/                     # Implementation files
│       │   ├── Cipher.cpp
│       │   ├── CaesarCipher.cpp
│       │   ├── XORCipher.cpp
│       │   ├── EncryptionManager.cpp
│       │   ├── DecryptionManager.cpp
│       │   ├── KeyManager.cpp
│       │   ├── FileHandler.cpp
│       │   └── User.cpp
│       ├── CMakeLists.txt           # Build configuration
│       └── main.cpp                 # Entry point
│
├── database/
│   └── schema.sql                   # Database schema
│
├── docs/
│   ├── UML_CLASS_DIAGRAM.md        # Class diagram
│   ├── USE_CASE_DIAGRAM.md         # Use case diagram
│   └── README.md                   # This file
│
├── .env                             # Environment configuration
└── .gitignore                       # Git ignore file
```

---

## 🚀 Getting Started

### Prerequisites
- SQLite3
- C++ compiler (g++ or clang)
- CMake (for C++ project)

### Installation

**1. Clone the repository**
```bash
cd File-Encryption-Tool
```

**2. Build C++ Backend**
```bash
cd backend/cpp
mkdir -p build && cd build
cmake ..
cmake --build .
```

**3. Create Database**
```bash
sqlite3 ../../database/encryption_tool.db < ../../database/schema.sql
```

**4. Configure Environment (if applicable)**
If your native backend reads environment variables, create `.env` in `backend/cpp/` or set them in your system environment. Example:
```env
DATABASE_URL=../../database/encryption_tool.db
```

**5. Start Backend (C++ executable)**
After building, run the produced executable from `backend/cpp/build` (example name: `main` or `encryption_app`):
```bash
cd backend/cpp/build
./main
```

**6. Start Frontend**
```bash
# Open index.html in a web browser or use a local server
# Option 1: Using Python
python -m http.server 8000

# Option 2: Using Node.js
npx http-server frontend/
```

---

## 🔐 C++ Encryption Classes

### Cipher (Abstract Base Class)
```cpp
class Cipher {
    virtual std::string encrypt(const std::string& plaintext) = 0;
    virtual std::string decrypt(const std::string& ciphertext) = 0;
    virtual void setKey(const std::string& newKey) = 0;
    virtual std::string generateKey(int length) = 0;
};
```

### CaesarCipher
Implements Caesar cipher with configurable shift values.
- Algorithm: Character shift cipher
- Default shift: 3
- Supports uppercase and lowercase letters

### XORCipher
Implements XOR-based encryption.
- Algorithm: XOR operation with binary key
- Key length: Variable (typically 32 bytes)
- Symmetric encryption (same key for encrypt/decrypt)

### EncryptionManager & DecryptionManager
Manage cipher instances and provide high-level encryption/decryption interfaces.

### KeyManager
Handles key generation, storage, and retrieval.

### FileHandler
Manages file operations (read, write, delete, get info).

---

## 🗄️ Database Schema

### Users Table
```sql
CREATE TABLE users (
    user_id INTEGER PRIMARY KEY,
    username TEXT NOT NULL UNIQUE,
    email TEXT NOT NULL UNIQUE,
    password_hash TEXT NOT NULL,
    created_date TIMESTAMP,
    last_login TIMESTAMP,
    is_active BOOLEAN
);
```

### Files Table
```sql
CREATE TABLE files (
    file_id INTEGER PRIMARY KEY,
    user_id INTEGER NOT NULL,
    filename TEXT NOT NULL,
    file_size INTEGER,
    upload_date TIMESTAMP,
    is_encrypted BOOLEAN,
    key_id INTEGER,
    FOREIGN KEY (user_id) REFERENCES users(user_id)
);
```

### Encryption History Table
```sql
CREATE TABLE encryption_history (
    history_id INTEGER PRIMARY KEY,
    user_id INTEGER NOT NULL,
    file_id INTEGER NOT NULL,
    algorithm TEXT NOT NULL,
    encryption_date TIMESTAMP,
    operation_type TEXT,
    status TEXT
);
```

### Keys Table
```sql
CREATE TABLE keys (
    key_id INTEGER PRIMARY KEY,
    user_id INTEGER NOT NULL,
    key_name TEXT NOT NULL,
    key_value TEXT NOT NULL,
    algorithm TEXT NOT NULL,
    created_date TIMESTAMP,
    description TEXT
);
```

---

## 🔗 API Endpoints

### Authentication
- `POST /api/users/register` - Register new user
- `POST /api/users/login` - Login user
- `GET /api/users/profile` - Get user profile
- `PUT /api/users/change-password` - Change password

### Encryption
- `POST /api/encryption/encrypt` - Encrypt text
- `POST /api/encryption/decrypt` - Decrypt text

### Key Management
- `POST /api/keys/generate` - Generate new key
- `GET /api/keys/list` - Get all keys
- `DELETE /api/keys/:keyId` - Delete key

### Health
- `GET /api/health` - Check API health

---

## 🎨 Frontend Architecture

### Pages
- **index.html**: Landing page with features and hero section
- **login.html**: User login with email and password
- **register.html**: User registration with validation
- **dashboard.html**: Main dashboard with statistics and quick actions
- **encrypt.html**: File encryption with drag-and-drop
- **decrypt.html**: File decryption with key entry
- **keys.html**: Key management and generation
- **profile.html**: User profile and security settings
- **reports.html**: Encryption history and analytics

### JavaScript
- **app.js**: Core application logic, API calls, authentication

### CSS
- **style.css**: Cybersecurity dark theme with neon blue accents

---

## 🎓 OOP Principles Implemented

### 1. Encapsulation
- Private member variables in C++ classes
- Public getter/setter methods
- Controlled access to class internals

### 2. Inheritance
- CaesarCipher and XORCipher inherit from abstract Cipher class
- Derived classes override pure virtual methods
- Code reuse through base class functionality

### 3. Polymorphism
- Abstract Cipher class defines interface
- Different cipher implementations provide specific behavior
- EncryptionManager works with any Cipher subclass

### 4. Abstraction
- Cipher abstract base class hides implementation details
- Users work with high-level encryption interface
- Complex algorithms abstracted into simple methods

### 5. Additional Patterns
- **Manager Pattern**: EncryptionManager, DecryptionManager, KeyManager
- **Factory Pattern**: Key generation and cipher creation
- **Singleton**: Database connection management

---

## 📊 UML & Diagrams

See detailed diagrams in:
- [UML Class Diagram](docs/UML_CLASS_DIAGRAM.md)
- [Use Case Diagram](docs/USE_CASE_DIAGRAM.md)

---

## 🔒 Security Features

- **JWT Authentication**: Secure token-based authentication
- **Password Hashing**: bcryptjs for secure password storage
- **HTTPS Ready**: Backend configured for HTTPS deployment
- **SQL Injection Prevention**: Parameterized queries
- **CORS Configuration**: Controlled cross-origin requests
- **Session Management**: Token expiration and refresh
- **Input Validation**: All user inputs validated
- **Error Handling**: Secure error messages

---

## 🚀 Deployment

### Frontend Deployment
- Deploy to Vercel, Netlify, or GitHub Pages
- No build process required (vanilla HTML/CSS/JS)

### Backend Deployment
- Deploy to Heroku, Railway, or AWS
- Environment variables required

### Database Deployment
- Use managed SQLite solutions (Replit, Vercel Postgres)
- Or host on AWS RDS

---

## 📝 Example Usage

### Encrypt a File
```javascript
const encrypted = await encryptText(fileContent, 'caesar', 'mykey123');
```

### Decrypt a File
```javascript
const decrypted = await decryptText(encryptedContent, 'caesar', 'mykey123');
```

### Generate Key
```javascript
const key = await generateNewKey('caesar', 'My backup key');
```

---

## 🐛 Troubleshooting

### Port Already in Use
```bash
# Change port in backend/nodejs/server.js or kill process
lsof -i :3000
kill -9 <PID>
```

### Database Issues
```bash
# Recreate database
rm database/encryption_tool.db
sqlite3 database/encryption_tool.db < database/schema.sql
```

### Module Not Found
```bash
cd backend/nodejs
npm install
```

---

## 📚 Learning Resources

- [C++ OOP Tutorial](https://www.learncpp.com/)
- [Node.js Express](https://expressjs.com/)
- [SQLite Documentation](https://www.sqlite.org/docs.html)
- [JWT Authentication](https://jwt.io/)
- [Cryptography Basics](https://www.khanacademy.org/)

---

## 👨‍💻 Contributors

Created for Final Semester OOP Project

---

## 📄 License

MIT License - Feel free to use this project for educational and commercial purposes.

---

## 📞 Support

For issues and questions, please check the documentation or create an issue in the repository.

---

## 🎯 Future Enhancements

- [ ] Two-factor authentication (2FA)
- [ ] Advanced encryption algorithms (AES, RSA)
- [ ] File sharing with encryption
- [ ] Mobile app (React Native)
- [ ] Cloud storage integration
- [ ] Batch encryption/decryption
- [ ] Dark/Light theme toggle
- [ ] Multi-language support
- [ ] Payment integration for premium features
- [ ] WebSocket real-time notifications

---

**Last Updated**: June 2024
**Version**: 1.0.0
**Status**: Production Ready ✅
