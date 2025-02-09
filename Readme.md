
# 📚 Digital Due Records - Store Management System 🧾

## 🚀 Overview

**Digital Due Records** is a digital ledger system, developed in **C**, designed to replace traditional "Katha" (account book) systems used in Indian stores. This project streamlines the management of customer dues, generates bills, and maintains well-organized records with minimal effort. It aims to provide an efficient, modern solution for store owners to track and manage financial data securely.

---

## 🌟 Key Features

### 🔐 **Dual Access System**
- **Customer Portal**: Securely view dues and transaction history.
- **Admin Portal**: Password-protected, offering store management capabilities.

### 📝 **Customer Record Management**
- Add, update, and delete customer records.
- Automatic bill generation with real-time due calculations.
- Automatically clear records when dues are settled.

### 🔍 **Advanced Search and Sort**
- **Search by**:
  - Customer name (case-insensitive).
  - Transaction date.
- **Sort records by**:
  - Customer name.
  - Due amount.
  - Transaction date.
- Flexible sorting options with **linked list** implementation, supporting both temporary and permanent sorting.

### 🛡️ **Enhanced Security**
- Password-protected admin access with recovery options.
- Security questions for account recovery.
- Limited login attempts for added protection.

### 💼 **Store Management**
- Customizable store details (name, address, contact).
- Professional bill generation and record management.
- User-friendly interface, requiring no technical knowledge.

---

## 🛠️ Technical Details

### Data Structures:
- **Structures**:
  - `Customer`: Stores customer details and transactions.
  - `SecurityQuestions`: Manages admin credentials securely.
  - `StoreDetails`: Stores essential store-related information.
- **Linked Lists**:
  - Used for dynamic record management.
  - Enables efficient sorting and memory management.

### File Handling:
- **Binary files** for secure and persistent data storage.
- **Text files** for bill generation.
- **Temporary files** for intermediate operations.

### Memory Management:
- **Dynamic memory allocation** using `malloc()`.
- **Proper deallocation** using `free()` to prevent memory leaks.

---

## 🧑‍💻 Skills Demonstrated

### 💡 Programming Concepts:
- Structured Programming.
- Advanced Data Structures (Linked Lists).
- File I/O operations.
- Memory Management.
- Robust Input Validation.

### 🛠️ Software Engineering:
- **Modular Design**: Easily maintainable and extendable codebase.
- **User Interface Design**: Clear, simple, and intuitive interface.
- **Secure Authentication**: Strong user authentication with password and security questions.
- **Error Handling**: Comprehensive error handling and debugging.

### 🧠 Problem Solving:
- Efficient data search and sort algorithms.
- User authentication and security management.
- Real-time due calculations for customers.

---

## ⚙️ Project Setup

### ⚡ Quick Start:
1. Download and run the executable.
2. The first-time setup will guide you through:
   - Admin password creation.
   - Security question configuration.
   - Store details input.
3. Ready to use immediately after setup.

### 🏁 First-Time Setup Process:
1. System creates necessary files:
   - `DueCustomers.txt`: Stores customer records.
   - `password.bin`: Manages admin credentials.
   - `store.txt`: Stores store details.
2. System guides you through:
   - Password creation (minimum 8 characters).
   - Security question setup (4 questions).
3. Validates all inputs to ensure smooth operation.

### 🛠️ Daily Usage:
1. Launch the program.
2. Choose between **Customer** or **Admin** access.
3. Perform actions like adding transactions, viewing records, and generating bills.

---

## 💻 System Requirements:
- **C Compiler** (GCC preferred).
- **Windows OS** or compatible environment.
- Minimum **512MB RAM**.
- **10MB free disk space**.
- No additional software or internet required.

---

## 🚀 Open to Contributions:
This project is open for **collaborations** and **improvements**. Feel free to fork, modify, and enhance the system for your needs or contribute back to the repository. Together, we can make it even better!

---


## 📞 Contact:
- **GitHub**: [GitHub Profile](https://github.com/Bharath-S-J)
- **LinkedIn**: [LinkedIn Profile](https://www.linkedin.com/in/bharath-s-j-56a734206)
- **Portfolio**: [Portfolio Website](https://portfolio-bharathsj.vercel.app/)
