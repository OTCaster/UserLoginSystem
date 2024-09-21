# User Login and Account Creation System

A simple console-based user login and account creation system written in C. This application allows users to create new accounts and log in using existing credentials. User credentials are stored securely with basic hashing.

---

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Dependencies](#dependencies)
- [Getting Started](#getting-started)
  - [Installation](#installation)
  - [Compilation](#compilation)
  - [Running the Application](#running-the-application)
- [Usage](#usage)
  - [Creating an Account](#creating-an-account)
  - [Logging In](#logging-in)
- [Security Considerations](#security-considerations)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)

---

## Features

- **Account Creation**: Users can create new accounts with a unique username and password.
- **User Login**: Existing users can log in using their credentials.
- **Credential Storage**: Usernames and hashed passwords are stored in a text file.
- **Basic Hashing**: Passwords are hashed using a simple hash function for educational purposes.

---

## Project Structure

```
UserLoginSystem/
├── src/
│   ├── main.c
│   ├── user.c
│   ├── auth.c
│   └── utils.c
├── include/
│   ├── user.h
│   ├── auth.h
│   └── utils.h
├── data/
│   └── credentials.txt
├── build/
│   └── (compiled objects and executables)
├── Makefile
└── README.md
```

- **`src/`**: Contains all source code files.
- **`include/`**: Contains header files with function declarations.
- **`data/`**: Stores user credentials securely.
- **`build/`**: Compiled object files and executables are placed here.
- **`Makefile`**: Automates the compilation process.
- **`README.md`**: Project documentation.

---

## Dependencies

- **C Compiler**: GCC or any compatible C compiler.
- **Standard C Libraries**: For file I/O, string manipulation, and other basic functions.

---

## Getting Started

### Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/UserLoginSystem.git
   ```

2. **Navigate to the Project Directory**

   ```bash
   cd UserLoginSystem/
   ```

### Compilation

- **Using Makefile**

  ```bash
  make
  ```

  This will compile all source files and place the executable in the `build/` directory.

- **Manual Compilation**

  ```bash
  gcc -Wall -Iinclude -o build/user_login_system src/*.c
  ```

### Running the Application

- **Execute the Program**

  ```bash
  ./build/user_login_system
  ```

---

## Usage

Upon running the application, you'll be presented with a menu:

```
=== User Login System ===
1. Create Account
2. Log In
3. Exit
Select an option:
```

### Creating an Account

1. **Select Option 1**: Create Account.
2. **Enter Username**: Provide a unique username.
3. **Enter Password**: Provide a password.

- **Successful Account Creation**:

  ```
  Account created successfully!
  ```

- **Failure**: If the account could not be created, an error message will be displayed.

### Logging In

1. **Select Option 2**: Log In.
2. **Enter Username**: Provide your username.
3. **Enter Password**: Provide your password.

- **Successful Login**:

  ```
  Login successful!
  ```

- **Failure**: If the credentials are invalid, an error message will be displayed.

### Exiting the Application

- **Select Option 3**: Exit.
- The application will terminate.

---

## Security Considerations

- **Password Hashing**:

  - Passwords are hashed using a simple hash function.
  - **Note**: For real-world applications, use a secure hashing algorithm like SHA-256 with salting.

- **Credential Storage**:

  - Credentials are stored in `data/credentials.txt`.
  - Ensure this file has restricted permissions:

    ```bash
    chmod 600 data/credentials.txt
    ```

- **Input Validation**:

  - The application includes basic input validation to prevent buffer overflows.

---

## Future Enhancements

- **Implement Secure Hashing**:

  - Integrate a cryptographic library for secure password hashing (e.g., OpenSSL).

- **Password Complexity Requirements**:

  - Enforce minimum password length and complexity.

- **Duplicate Username Check**:

  - Prevent users from registering with an existing username.

- **Account Recovery**:

  - Implement password reset functionality.

- **Improved User Interface**:

  - Enhance the console interface for better user experience.

- **Database Integration**:

  - Use a database (e.g., SQLite) for storing credentials securely.

---

## Contributing

Contributions are welcome! Please follow these steps:

1. **Fork the Repository**: Click on the 'Fork' button on the top right.
2. **Clone Your Fork**:

   ```bash
   git clone https://github.com/yourusername/UserLoginSystem.git
   ```

3. **Create a New Branch**:

   ```bash
   git checkout -b feature/YourFeature
   ```

4. **Make Your Changes**: Implement your feature or bug fix.
5. **Commit Your Changes**:

   ```bash
   git commit -am 'Add new feature'
   ```

6. **Push to the Branch**:

   ```bash
   git push origin feature/YourFeature
   ```

7. **Submit a Pull Request**: Describe your changes and submit the PR.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

**Disclaimer**: This project is intended for educational purposes to demonstrate basic concepts in C programming, file handling, and user authentication mechanisms. It should not be used as-is for production environments without proper security enhancements.

---

**Author**: [Your Name](mailto:your.email@example.com)

Feel free to reach out with any questions or suggestions!