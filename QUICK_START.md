# 🚀 Quick Start Guide - File Encryption Tool

## 30-Second Setup

### Step 1: Build C++ Backend (if using native backend)
```bash
cd backend/cpp
mkdir -p build && cd build
cmake ..
cmake --build .
```

### Step 2: Start Database
```bash
# The database will auto-initialize on first server start
# Or manually:
sqlite3 ../../database/encryption_tool.db < ../../database/schema.sql
```

### Step 3: Start Backend (C++ executable)
After building, run the produced executable from `backend/cpp/build` (example name: `main` or `encryption_app`).
```bash
cd backend/cpp/build
./main   # or the produced executable name on your platform
```

### Step 4: Open Frontend
Option A: Using Python
```bash
cd frontend
python -m http.server 8000
```
Then open `http://localhost:8000` in your browser

Option B: Using Node.js
```bash
cd frontend
npx http-server
```

### Step 5: Access the Application
- **Landing Page**: http://localhost:8000/index.html
- **Register**: http://localhost:8000/register.html
- **Login**: http://localhost:8000/login.html
- **Dashboard**: http://localhost:8000/dashboard.html (after login)

---

## 📋 What's Included

### ✅ Backend (C++)
- ✓ High-performance encryption library and utilities
- ✓ CMake build system
- ✓ SQLite integration via native bindings
- ✓ Encryption/Decryption managers
- ✓ Key management

### ✅ Frontend (HTML/CSS/JavaScript)
- ✓ 8 responsive pages
- ✓ Cybersecurity dark theme
- ✓ Modern UI components
- ✓ File upload/download
- ✓ Real-time form validation
- ✓ Mobile friendly

### ✅ C++ Encryption Library
- ✓ Abstract Cipher base class
- ✓ Caesar Cipher implementation
- ✓ XOR Cipher implementation
- ✓ Encryption/Decryption managers
- ✓ Key management system
- ✓ File handling utilities

### ✅ Documentation
- ✓ README with full guide
- ✓ UML class diagram
- ✓ Use case diagram
- ✓ Quick start guide
- ✓ Code comments throughout

### ✅ Configuration
- ✓ Environment variables (.env)
- ✓ CMake build system
- ✓ Git ignore file
- ✓ Database schema

---

## 🔑 Test Credentials

After registering, use these to test:

**Example Account**
- Username: `testuser`
- Email: `test@example.com`
- Password: `Test@12345`

---

## 📖 Page Guide

### 1. **Landing Page** (`index.html`)
- Public landing page
- Features showcase
- Login/Register buttons
- Project information

### 2. **Registration** (`register.html`)
- Create new account
- Email validation
- Password requirements
- Auto-login after registration

### 3. **Login** (`login.html`)
- Email/password authentication
- "Remember me" option
- Redirect to dashboard

### 4. **Dashboard** (`dashboard.html`)
- User welcome
- Statistics cards
- Quick action buttons
- Recent activity timeline

### 5. **Encrypt** (`encrypt.html`)
- Drag-drop file upload
- Algorithm selection
- Key input/generation
- Download encrypted file

### 6. **Decrypt** (`decrypt.html`)
- Upload encrypted file
- Algorithm selection
- Key input
- Download decrypted file

### 7. **Key Management** (`keys.html`)
- Generate new keys
- View all keys
- Delete keys
- Export key values

### 8. **Reports** (`reports.html`)
- Encryption history
- Filter by algorithm/date
- Export as CSV/PDF
- Statistics dashboard

### 9. **Profile** (`profile.html`)
- View account info
- Change password
- Security settings
- Session management

---

## 🔧 API Endpoints

### Authentication
```
POST   /api/users/register      → Create account
POST   /api/users/login         → Login user
GET    /api/users/profile       → Get user info
PUT    /api/users/change-password → Update password
```

### Encryption
```
POST   /api/encryption/encrypt  → Encrypt file
POST   /api/encryption/decrypt  → Decrypt file
```

### Keys
```
POST   /api/keys/generate       → Create new key
GET    /api/keys/list          → Get all keys
DELETE /api/keys/:keyId         → Delete key
```

### Health
```
GET    /api/health             → Check API status
```

---

## 💡 Usage Examples

### Register & Login
1. Go to http://localhost:8000/register.html
2. Fill in details (username, email, password)
3. Click "Create Account"
4. Automatically redirected to dashboard

### Encrypt a File
1. Click "Encrypt File" button on dashboard
2. Drag-drop or select a file
3. Choose algorithm (Caesar or XOR)
4. Enter encryption key
5. Click "Encrypt File"
6. Download encrypted file

### Decrypt a File
1. Click "Decrypt File" button on dashboard
2. Upload encrypted file
3. Select same algorithm used for encryption
4. Enter the decryption key
5. Click "Decrypt File"
6. Download decrypted file

### Generate Keys
1. Go to Key Management page
2. Select algorithm
3. (Optional) Add description
4. Click "Generate Key"
5. Key is saved and can be copied

### View Reports
1. Go to Reports page
2. Filter by algorithm/date/operation
3. View statistics
4. Export as CSV

---

## 🐛 Troubleshooting

### "Cannot GET /api/..."
- Make sure backend server is running on port 3000
- Check that npm start succeeded
- Look for errors in terminal

### "Database connection error"
- Verify database file exists: `database/encryption_tool.db`
- Run: `sqlite3 database/encryption_tool.db < database/schema.sql`

### "Login not working"
- Clear browser localStorage: F12 → Application → Storage → Clear
- Try registering a new account
- Check backend logs

### "API calls failing"
- Verify CORS is enabled in backend
- Check JWT token is valid
- Review server.js cors configuration

### Frontend won't load
- Try different port: `python -m http.server 9000`
- Clear browser cache
- Check file paths are relative

---

## 📚 File Structure Quick Reference

```
File-Encryption-Tool/
├── frontend/              ← Start here for UI
│   ├── index.html        ← Landing page
│   ├── dashboard.html    ← Main app page
│   ├── css/style.css     ← All styling
│   └── js/app.js         ← All frontend logic
│
├── backend/cpp/           ← C++ encryption library & optional native server
│   ├── include/          ← Header files
│   ├── src/              ← Implementation
│   └── CMakeLists.txt    ← Build config
│
├── database/
│   └── schema.sql        ← Database tables
│
└── docs/                 ← Documentation
    ├── README.md         ← Full guide
    ├── UML_CLASS_DIAGRAM.md
    └── USE_CASE_DIAGRAM.md
```

---

## 🎯 Next Steps

### After Basic Setup
1. ✅ Register an account
2. ✅ Encrypt a test file
3. ✅ Decrypt the file
4. ✅ Generate a few keys
5. ✅ Check reports page

### For Production Deployment
1. Change JWT_SECRET in .env
2. Set NODE_ENV=production
3. Use HTTPS
4. Set up database backup
5. Configure email service
6. Test all features
7. Deploy to hosting

### Further Development
- [ ] Compile C++ library to .so/.dll
- [ ] Integrate C++ DLL with Node.js
- [ ] Add more algorithms (AES, RSA)
- [ ] Create admin panel
- [ ] Add real PDF export
- [ ] Mobile app version
- [ ] Cloud storage integration

---

## 📞 Common Commands

```bash
# Start backend
cd backend/nodejs && npm start

# Start frontend server
cd frontend && python -m http.server 8000

# Rebuild database
sqlite3 database/encryption_tool.db < database/schema.sql

# Check if port is in use
netstat -antp | grep 3000

# View logs
tail -f backend/nodejs/logs/app.log

# Run tests (if implemented)
npm test
```

---

## 🎓 Learning Points

This project demonstrates:
- ✅ OOP principles (Inheritance, Polymorphism, Encapsulation)
- ✅ REST API design
- ✅ Frontend-backend integration
- ✅ Database design and normalization
- ✅ Authentication and security
- ✅ Encryption algorithms
- ✅ File handling
- ✅ User interface design

---

## 📞 Support & Help

### Debug Mode
Add this to see more details:
```javascript
// In app.js
const DEBUG = true;
if (DEBUG) console.log('API Call:', endpoint, data);
```

### Check Browser Console
Press F12 to open developer tools and check:
- Network tab for API calls
- Console for errors
- Storage for tokens

### Backend Logs
Check terminal where you ran `npm start` for error messages

---

## ⭐ Features Checklist

- [x] User registration & authentication
- [x] File encryption with multiple algorithms
- [x] File decryption
- [x] Key generation and management
- [x] Encryption history & reports
- [x] User profile management
- [x] Password change functionality
- [x] Responsive design
- [x] Dark theme UI
- [x] OOP-based architecture
- [x] RESTful API
- [x] Database integration
- [x] Documentation

---

**Version**: 1.0.0  
**Status**: ✅ Ready to Use  
**Last Updated**: June 2024
