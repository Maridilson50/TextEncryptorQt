# TextEncryptorQt 🔐

A desktop GUI application built with **C++ and Qt** that encrypts and decrypts text files using ASCII encoding.

## 📌 Features

- 📄 Load `.txt` files through a simple file dialog
- 🔐 Convert characters to ASCII values (encryption)
- 🔓 Convert ASCII values back to characters (decryption)
- 🧼 Clean UI with fixed window size and minimal design
- 🛠️ Built using Qt 6.9 and C++17

## 🖥️ Screenshot

![image](https://github.com/user-attachments/assets/9d7df104-2a11-4d1e-b45b-f0ddc7e1b922)


## 📁 How to Run

1. Open the project in **Qt Creator** (tested on Qt 6.9 + MinGW 64-bit).
2. Build and run the project (`Ctrl+R`).
3. Enter the path to a text file or use the Browse button.
4. Click **Encrypt** or **Decrypt** to create output files:
   - `cipher.txt` → Encrypted ASCII values
   - `unCipher.txt` → Decoded back to text

## 📦 Deployment

The release folder includes:
- `cipher_App.exe`
- Required `.dll` files
- `platforms` and `styles` folders

Use `windeployqt` to bundle dependencies for Windows.

## 🔧 Technologies Used

- C++17
- Qt Framework (Widgets, File I/O, QTimer, QFileDialog)
- Qt Creator IDE

## 👤 Author

**Maridilson Gomes**  
[GitHub Profile](https://github.com/Maridilson50)

## 📄 License

This project is open-source under the [MIT License](LICENSE).
