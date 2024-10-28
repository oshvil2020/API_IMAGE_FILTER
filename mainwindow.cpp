#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>

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

// void MainWindow::on_img_clicked()
// {

// }
void MainWindow::on_img_clicked()
{
    // Open file dialog to select an image file
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Image"),
        "",
        tr("Image Files (*.png *.jpg *.bmp)")  // Filter for image file types
        );

    // Check if the user selected a file
    if (!fileName.isEmpty()) {
        QPixmap image(fileName);  // Load the image
        if (!image.isNull()) {
            // Set the image in the QLabel
            ui->label->setPixmap(image.scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            QMessageBox::warning(this, tr("Error"), tr("Failed to load the image."));
        }
    } else {
        QMessageBox::warning(this, tr("No File Selected"), tr("Please select an image file."));
    }
}
