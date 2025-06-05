#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <sstream>
#include <Qtimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_encryptButton_clicked()
{
    QString filename = ui->lineEdit->text();
    std::ifstream inFile(filename.toStdString());
    std::ofstream outFile("cipher.txt");

    if (inFile && outFile) {
        std::string line;
        while (std::getline(inFile, line)) {
            for (char ch : line)
                outFile << static_cast<int>(ch) << " ";
            outFile << "\n";
        }
        ui->label->setText("File ciphered successfully!");
        QTimer::singleShot(3000, ui->label, &QLabel::clear);
    } else {
        ui->label->setText("Error opening files.");
        QTimer::singleShot(3000, ui->label, &QLabel::clear);
    }
}

void MainWindow::on_decryptButton_clicked()
{
    QString filename = ui->lineEdit->text();
    std::ifstream inFile(filename.toStdString());
    std::ofstream outFile("unCipher.txt");

    if (inFile && outFile) {
        std::string line;
        while (getline(inFile, line)) { // Read each ASCII-encoded line
            std::stringstream ss(line);
            int asciiValue;

            while (ss >> asciiValue) { // Convert each ASCII number back to a character
                outFile << static_cast<char>(asciiValue);
            }
            outFile << "\n"; // Restore line breaks
        }
        ui->label->setText("File unciphered successfully!");
        QTimer::singleShot(3000, ui->label, &QLabel::clear);
    } else {
        ui->label->setText("Error opening files.");
        QTimer::singleShot(3000, ui->label, &QLabel::clear);
    }
}

void MainWindow::on_browse_fileButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Select a file",
        QDir::currentPath(),       // Start in the current directory
        "Text Files (*.txt);;All Files (*)"
        );

    if (!fileName.isEmpty()) {
        ui->lineEdit->setText(fileName);  // Set file path in the input field
    }
}
