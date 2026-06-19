
const STORAGE_USERS = 'cypherlock_users';
const STORAGE_CURRENT = 'cypherlock_current';
const STORAGE_KEYS = 'cypherlock_keys';

function showAlert(message, type = 'info') {
    const container = document.getElementById('alertContainer') || document.body;
    const alert = document.createElement('div');
    alert.className = `alert alert-${type}`;
    alert.innerText = message;
    if (container === document.body) {
        document.body.appendChild(alert);
    } else {
        container.prepend(alert);
    }
    setTimeout(() => alert.remove(), 4200);
}

function getUsers() {
    return JSON.parse(localStorage.getItem(STORAGE_USERS) || '[]');
}

function saveUsers(users) {
    localStorage.setItem(STORAGE_USERS, JSON.stringify(users));
}

function getKeys() {
    return JSON.parse(localStorage.getItem(STORAGE_KEYS) || '[]');
}

function getUserKeys() {
    const user = getCurrentUser();
    if (!user) return [];
    return getKeys().filter((key) => key.user_id === user.id);
}

function saveKeys(keys) {
    localStorage.setItem(STORAGE_KEYS, JSON.stringify(keys));
}

function setCurrentUser(user) {
    localStorage.setItem(STORAGE_CURRENT, JSON.stringify(user));
}

function getCurrentUser() {
    return JSON.parse(localStorage.getItem(STORAGE_CURRENT) || 'null');
}

function logout() {
    localStorage.removeItem(STORAGE_CURRENT);
    window.currentUser = null;
    showAlert('Logged out successfully!', 'success');
    setTimeout(() => {
        window.location.href = 'login.html';
    }, 500);
}

function goHome() {
    if (isAuthenticated()) {
        window.location.href = 'dashboard.html';
    } else {
        window.location.href = 'login.html';
    }
}

function isAuthenticated() {
    return !!getCurrentUser();
}

function navigateTo(page) {
    const mapping = {
        login: 'login.html',
        register: 'register.html',
        dashboard: 'dashboard.html',
        encrypt: 'encrypt.html',
        decrypt: 'decrypt.html',
        keys: 'keys.html',
        reports: 'reports.html',
        profile: 'profile.html'
    };
    window.location.href = mapping[page] || page;
}

function createAccount(username, email, password, confirm) {
    if (!username || !email || !password || !confirm) {
        showAlert('Please complete all fields.', 'error');
        return false;
    }
    if (password !== confirm) {
        showAlert('Passwords do not match.', 'error');
        return false;
    }
    const users = getUsers();
    if (users.find(u => u.email === email)) {
        showAlert('Email already registered.', 'error');
        return false;
    }

    const user = {
        id: Date.now(),
        username,
        email,
        password,
        created_date: new Date().toISOString(),
        last_login: new Date().toISOString(),
    };
    users.push(user);
    saveUsers(users);
    setCurrentUser(user);
    showAlert('Account created successfully!', 'success');
    return true;
}

function login(email, password) {
    return loginAccount(email, password);
}

function register(username, email, password, confirm) {
    return createAccount(username, email, password, confirm);
}

function loginAccount(email, password) {
    if (!email || !password) {
        showAlert('Email and password are required.', 'error');
        return false;
    }
    const users = getUsers();
    const user = users.find(u => u.email === email && u.password === password);
    if (!user) {
        showAlert('Invalid email or password.', 'error');
        return false;
    }
    user.last_login = new Date().toISOString();
    saveUsers(users);
    setCurrentUser(user);
    showAlert('Login successful!', 'success');
    return true;
}

function getAllKeys() {
    return getUserKeys();
}

function generateNewKey(algorithm, description) {
    if (!algorithm) {
        showAlert('Please select an algorithm to generate a key.', 'error');
        return null;
    }
    const key = addKey(algorithm, description);
    if (!key) return null;
    showAlert('New key generated successfully.', 'success');
    return key;
}

function deleteKey(keyId) {
    const keys = getKeys();
    const cleanId = String(keyId);
    const filtered = keys.filter((key) => String(key.id) !== cleanId && String(key.key_id) !== cleanId);
    saveKeys(filtered);
    showAlert('Key deleted successfully.', 'success');
    return true;
}

function getUserProfile() {
    const user = getCurrentUser();
    if (!user) return null;
    const users = getUsers();
    return users.find((u) => u.id === user.id) || user;
}

function changePassword(oldPassword, newPassword) {
    const user = getCurrentUser();
    if (!user) {
        showAlert('No user is currently signed in.', 'error');
        return false;
    }
    const users = getUsers();
    const index = users.findIndex((u) => u.id === user.id);
    if (index === -1) {
        showAlert('User not found.', 'error');
        return false;
    }
    if (users[index].password !== oldPassword) {
        showAlert('Current password is incorrect.', 'error');
        return false;
    }
    if (!newPassword || newPassword.length < 6) {
        showAlert('New password must be at least 6 characters.', 'error');
        return false;
    }
    users[index].password = newPassword;
    saveUsers(users);
    const updatedUser = users[index];
    setCurrentUser(updatedUser);
    showAlert('Password updated successfully.', 'success');
    return true;
}

function deleteAccount() {
    const user = getCurrentUser();
    if (!user) {
        showAlert('No user session found.', 'error');
        return false;
    }
    const users = getUsers().filter((u) => u.id !== user.id);
    saveUsers(users);
    logout();
    showAlert('Account deleted.', 'success');
    return true;
}

function exportToCSV(data, filename) {
    if (!Array.isArray(data) || data.length === 0) {
        showAlert('No data available for export.', 'error');
        return;
    }
    const headers = Object.keys(data[0]);
    const rows = data.map((row) => headers.map((header) => JSON.stringify(row[header] ?? '')).join(','));
    const csv = [headers.join(','), ...rows].join('\n');
    const blob = new Blob([csv], { type: 'text/csv;charset=utf-8;' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = filename;
    a.click();
    URL.revokeObjectURL(url);
}

function formatDate(value) {
    const date = new Date(value);
    if (Number.isNaN(date.getTime())) return '-';
    return date.toLocaleString();
}

function copyToClipboard(text) {
    navigator.clipboard.writeText(text).then(() => {
        showAlert('Copied to clipboard.', 'success');
    }).catch(() => {
        showAlert('Copy failed.', 'error');
    });
}

function generateRandomKey(length = 24) {
    const chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    return Array.from({ length }, () => chars.charAt(Math.floor(Math.random() * chars.length))).join('');
}

function caesarEncrypt(text, shift = 3) {
    return text.split('').map(ch => {
        const code = ch.charCodeAt(0);
        if (code >= 65 && code <= 90) return String.fromCharCode(((code - 65 + shift) % 26) + 65);
        if (code >= 97 && code <= 122) return String.fromCharCode(((code - 97 + shift) % 26) + 97);
        return ch;
    }).join('');
}

function caesarDecrypt(text, shift = 3) {
    return caesarEncrypt(text, 26 - shift);
}

function base64Encode(bytes) {
    let binary = '';
    const chunkSize = 0x8000;
    for (let i = 0; i < bytes.length; i += chunkSize) {
        const chunk = bytes.subarray(i, i + chunkSize);
        binary += String.fromCharCode.apply(null, chunk);
    }
    return btoa(binary);
}

function base64Decode(base64) {
    const binary = atob(base64);
    const bytes = new Uint8Array(binary.length);
    for (let i = 0; i < binary.length; i++) {
        bytes[i] = binary.charCodeAt(i);
    }
    return bytes;
}

function toUint8Array(input) {
    if (input instanceof Uint8Array) return input;
    if (input instanceof ArrayBuffer) return new Uint8Array(input);
    if (typeof input === 'string') return new TextEncoder().encode(input);
    return new Uint8Array(input);
}

function bytesToBase64(bytes) {
    return base64Encode(toUint8Array(bytes));
}

function base64ToBytes(base64) {
    return base64Decode(base64);
}

function xorTransform(data, key) {
    const source = toUint8Array(data);
    const keyBytes = new TextEncoder().encode(key);
    const result = new Uint8Array(source.length);
    for (let i = 0; i < source.length; i++) {
        result[i] = source[i] ^ keyBytes[i % keyBytes.length];
    }
    return result;
}

function xorRestore(encoded, key) {
    const source = typeof encoded === 'string' ? base64ToBytes(encoded) : toUint8Array(encoded);
    const keyBytes = new TextEncoder().encode(key);
    const result = new Uint8Array(source.length);
    for (let i = 0; i < source.length; i++) {
        result[i] = source[i] ^ keyBytes[i % keyBytes.length];
    }
    return result;
}

function decryptBytes(data, algorithm, key) {
    if (!data || !algorithm || !key) {
        showAlert('Encrypted data, algorithm, and key are required.', 'error');
        return null;
    }

    if (algorithm === 'caesar') {
        const text = typeof data === 'string' ? data : new TextDecoder().decode(data);
        const shift = parseInt(key, 10);
        const decrypted = caesarDecrypt(text, Number.isNaN(shift) ? 3 : shift);
        return new TextEncoder().encode(decrypted);
    }

    return xorRestore(data, key);
}

function encryptText(text, algorithm, key) {
    if (!text || !algorithm || !key) {
        showAlert('Text, algorithm, and key are required.', 'error');
        return null;
    }
    if (algorithm === 'caesar') {
        const shift = parseInt(key, 10);
        const source = typeof text === 'string' ? text : new TextDecoder().decode(text);
        return caesarEncrypt(source, Number.isNaN(shift) ? 3 : shift);
    }

    return bytesToBase64(xorTransform(text, key));
}

function decryptText(text, algorithm, key) {
    if (!text || !algorithm || !key) {
        showAlert('Encrypted text, algorithm, and key are required.', 'error');
        return null;
    }
    if (algorithm === 'caesar') {
        const shift = parseInt(key, 10);
        return caesarDecrypt(text, Number.isNaN(shift) ? 3 : shift);
    }
    const decryptedBytes = xorRestore(text, key);
    return new TextDecoder().decode(decryptedBytes);
}

function addKey(algorithm, description) {
    const currentUser = getCurrentUser();
    if (!currentUser) {
        showAlert('Please login to generate keys.', 'error');
        return null;
    }

    const keys = getKeys();
    const key = {
        id: Date.now(),
        user_id: currentUser.id,
        key_id: `K-${Date.now()}-${Math.floor(Math.random() * 1000)}`,
        algorithm,
        description,
        key_value: generateRandomKey(32),
        created_date: new Date().toISOString(),
    };
    keys.push(key);
    saveKeys(keys);
    return key;
}

function getDashboardStats() {
    const keys = getAllKeys();
    return {
        totalFiles: 0,
        encryptedFiles: 0,
        decryptedFiles: 0,
        activeKeys: keys.length,
        keys,
    };
}

function initializePage() {
    const user = getCurrentUser();
    if (user) {
        const userDisplay = document.getElementById('userDisplay');
        if (userDisplay) userDisplay.textContent = `Welcome, ${user.username}`;
    }
}

document.addEventListener('DOMContentLoaded', initializePage);

window.currentUser = getCurrentUser();

