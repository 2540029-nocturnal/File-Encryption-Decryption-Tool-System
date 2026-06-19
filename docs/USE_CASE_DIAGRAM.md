# Use Case Diagram - File Encryption Tool System

```mermaid
usecase diagram
    actor User
    actor Admin

    User --> (Register Account)
    User --> (Login)
    User --> (View Dashboard)
    User --> (Encrypt File)
    User --> (Decrypt File)
    User --> (Generate Key)
    User --> (Manage Keys)
    User --> (View Profile)
    User --> (Change Password)
    User --> (View Reports)
    User --> (Export Reports)
    User --> (Logout)

    (Encrypt File) <-- (Select Algorithm)
    (Encrypt File) <-- (Upload File)
    (Encrypt File) <-- (Generate Key)

    (Decrypt File) <-- (Select Algorithm)
    (Decrypt File) <-- (Upload Encrypted File)
    (Decrypt File) <-- (Enter Key)

    (Generate Key) <-- (Select Algorithm)
    (Manage Keys) <-- (Generate Key)
    (Manage Keys) <-- (Delete Key)
    (Manage Keys) <-- (View Key History)

    (View Reports) <-- (Filter by Algorithm)
    (View Reports) <-- (Filter by Date)
    (View Reports) <-- (Filter by Operation)

    (Export Reports) <-- (Export as PDF)
    (Export Reports) <-- (Export as CSV)

    Admin --> (Manage Users)
    Admin --> (View System Logs)
    Admin --> (System Configuration)
    Admin --> (Database Backup)

    style User fill:#00d4ff,stroke:#0080ff,stroke-width:2px
    style Admin fill:#ff006e,stroke:#c92a2a,stroke-width:2px
```

## Use Case Descriptions

### User Scenarios

**UC1: Register Account**
- Actor: New User
- Precondition: User is not logged in
- Main Flow: User provides username, email, password → System validates and creates account
- Postcondition: User account created, email verified

**UC2: Login**
- Actor: User
- Precondition: User has account
- Main Flow: User provides credentials → System authenticates → User receives JWT token
- Postcondition: User logged in, can access dashboard

**UC3: Encrypt File**
- Actor: User
- Precondition: User logged in, file selected
- Main Flow: User selects file, chooses algorithm, provides key → System encrypts file
- Postcondition: Encrypted file generated, history recorded

**UC4: Decrypt File**
- Actor: User
- Precondition: User logged in, encrypted file selected
- Main Flow: User uploads encrypted file, selects algorithm, provides key → System decrypts
- Postcondition: Decrypted file available, history recorded

**UC5: Generate Key**
- Actor: User
- Precondition: User logged in
- Main Flow: User selects algorithm → System generates random key
- Postcondition: Key stored in database, available for encryption

**UC6: View Reports**
- Actor: User
- Precondition: User logged in
- Main Flow: User views encryption history, applies filters
- Postcondition: Report displayed with statistics and history

**UC7: Change Password**
- Actor: User
- Precondition: User logged in
- Main Flow: User provides old and new password → System validates and updates
- Postcondition: Password changed, user remains logged in

### Admin Scenarios

**UC8: Manage Users**
- Actor: Admin
- Main Flow: Admin can view, edit, activate, or deactivate user accounts
- Postcondition: User status updated

**UC9: View System Logs**
- Actor: Admin
- Main Flow: Admin views all system activities, encryption operations, user logins
- Postcondition: Audit trail displayed

**UC10: System Configuration**
- Actor: Admin
- Main Flow: Admin configures system settings, backup schedules, security policies
- Postcondition: Settings updated and applied
