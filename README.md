# CipherTool 🔐

A modern, professional file encryption and decryption application with military-grade security. CipherTool provides seamless encryption using Caesar Cipher and XOR algorithms with an intuitive, beautiful user interface.

## ✨ Features

- **🔒 Dual Encryption Algorithms**
  - Caesar Cipher: Character-based shift encryption
  - XOR Cipher: Byte-level XOR encryption for binary files
  
- **📁 File Management**
  - Drag-and-drop file upload
  - Binary file detection and handling
  - Secure file downloads
  - Copy-to-clipboard functionality

- **👤 User Authentication**
  - Secure login/registration system
  - Profile management
  - Password change functionality
  - Session management

- **📊 Advanced Features**
  - Encryption key management
  - Detailed encryption reports and history
  - Algorithm usage analytics
  - Export reports as PDF/CSV

- **🎨 Professional UI/UX**
  - Cybersecurity-themed neon blue design
  - Smooth animations and transitions
  - Responsive design for all devices
  - Intuitive dashboard with real-time statistics

## 🚀 Getting Started

### Prerequisites
- Modern web browser (Chrome, Firefox, Edge, Safari)
- Local server to serve static files

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/ciphertool.git
   cd ciphertool
   ```

2. **Navigate to frontend directory**
   ```bash
   cd frontend
   ```

3. **Start a local server**
   ```bash
   # Using Python 3
   python -m http.server 8000
   
   # Or using Node.js http-server
   npx http-server -p 8000
   
   # Or using PHP
   php -S localhost:8000
   ```

4. **Open in browser**
   ```
   http://localhost:8000
   ```

## 📚 Usage

### Encryption
1. Navigate to **Encrypt File** page
2. Select encryption algorithm (Caesar or XOR)
3. Enter your encryption key
4. Upload or drag-drop your file
5. Click "Encrypt File"
6. Download or copy encrypted content

### Decryption
1. Navigate to **Decrypt File** page
2. Select the algorithm used for encryption
3. Enter the same key used during encryption
4. Upload encrypted file
5. Click "Decrypt File"
6. View or download decrypted content

### Key Management
- Generate new encryption keys
- Save key descriptions for easy reference
- Organize keys by algorithm type

### View Statistics
- Dashboard shows real-time encryption statistics
- View encryption history with timestamps
- Export reports for audit purposes

## 🏗️ Project Structure

```
ciphertool/
├── frontend/                 # Web application
│   ├── index.html           # Home page
│   ├── login.html           # Login page
│   ├── register.html        # Registration page
│   ├── dashboard.html       # Main dashboard
│   ├── encrypt.html         # Encryption interface
│   ├── decrypt.html         # Decryption interface
│   ├── keys.html            # Key management
│   ├── profile.html         # User profile
│   ├── reports.html         # Encryption reports
│   ├── css/
│   │   └── style.css        # Professional styling
│   ├── js/
│   │   └── app.js           # Core application logic
│   ├── assets/              # Images and media
│   └── pages/               # Additional pages
├── backend/                 # C++ encryption engines (optional)
│   ├── CaesarCipher.h
│   ├── XORCipher.h
│   ├── KeyManager.h
│   ├── EncryptionManager.h
│   └── main.cpp
├── README.md               # This file
├── LICENSE                 # Project license
└── .gitignore             # Git ignore rules
```

## 🔧 Technologies Used

### Frontend
- **HTML5**: Semantic markup and structure
- **CSS3**: Modern styling with animations and gradients
- **JavaScript (Vanilla)**: No framework dependencies
  - TextEncoder/TextDecoder APIs for UTF-8 handling
  - FileReader API for binary file operations
  - Blob API for file downloads
  - LocalStorage for session management

### Encryption
- **Caesar Cipher**: Character shift encryption with modulo arithmetic
- **XOR Cipher**: Byte-level XOR with repeating key pattern
- **Base64 Encoding**: Safe transport format for binary data

### Backend (Optional)
- **C++**: High-performance encryption engines
  - Header files for integration

## 🔐 Security Notes

⚠️ **Important**: This is a demonstration application. For production use:
- Never store keys in plaintext
- Use HTTPS for all communications
- Implement proper key derivation functions
- Consider using established cryptography libraries
- Add server-side encryption validation
- Implement rate limiting and DDoS protection

## 🎨 UI/UX Features

- **Responsive Design**: Works seamlessly on desktop, tablet, and mobile
- **Animations**: 
  - Page load fade-in effects
  - Smooth button and card hover animations
  - Logo glow pulse animation
  - Input focus glow effects
  - Loading spinner animations

- **Accessibility**:
  - Semantic HTML structure
  - ARIA labels for screen readers
  - Keyboard navigation support
  - Color contrast compliance

## 📱 Browser Support

| Browser | Support | Version |
|---------|---------|---------|
| Chrome  | ✅ Full | Latest  |
| Firefox | ✅ Full | Latest  |
| Safari  | ✅ Full | Latest  |
| Edge    | ✅ Full | Latest  |
| IE 11   | ❌ No   | N/A     |

## 🧪 Testing

The application includes client-side encryption testing:

```javascript
// Test XOR encryption round-trip
const key = '3232';
const plaintext = 'This is a test';
const encrypted = xorTransform(plaintext, key);
const decrypted = new TextDecoder().decode(decryptBytes(bytesToBase64(encrypted), 'xor', key));
console.log(decrypted === plaintext); // true ✓
```

## 📦 Build & Deployment

### Local Testing
```bash
# Start development server
python -m http.server 8000

# Access application
# http://localhost:8000
```

### GitHub Pages Deployment
1. Push code to GitHub
2. Enable GitHub Pages in repository settings
3. Select `main` branch as source
4. Access at: `https://yourusername.github.io/ciphertool`

### Custom Server Deployment
```bash
# Copy frontend files to web server
cp -r frontend/* /var/www/ciphertool/

# Ensure proper file permissions
chmod 755 /var/www/ciphertool/*
```

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📞 Support

For issues, questions, or suggestions:
- Open an issue on GitHub
- Check existing issues for solutions
- Review the documentation

## 🎯 Roadmap

- [ ] Server-side encryption validation
- [ ] Cloud key storage integration
- [ ] Mobile app (React Native/Flutter)
- [ ] Advanced encryption algorithms (AES-256, RSA)
- [ ] File batch processing
- [ ] Encryption scheduling
- [ ] API endpoint creation
- [ ] Docker containerization

## 👨‍💻 Author

**Your Name**
- GitHub: [@yourusername](https://github.com/yourusername)
- Email: your.email@example.com

## 🙏 Acknowledgments

- Font Awesome for icons
- Open source community
- All contributors and supporters

---

**Made with ❤️ for secure data protection**
