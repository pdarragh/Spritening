#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fullpreview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new Canvas();

    QRect rcontent = ui->graphicsView->contentsRect();

    ui->graphicsView->setSceneRect(0, 0, rcontent.width(), rcontent.height());
    ui->graphicsView->setScene(scene);

    connect(preview_button, SIGNAL(released()), this, SLOT(fullPreviewButtonReleased()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fullPreviewButtonReleased()
{
    FullPreview full_preview;
    full_preview.setModal(true);
    full_preview.exec();
}

/*
 * fpsValueChanged
 *
 * Handling event which sets the time interval for the QTimer object in
 * charge of refreshing the small previewer scene.
 */
void MainWindow::fpsValueChanged(int value)
{

}

/*
 * pskipButtonReleased
 *
 * Handling Event which changes the frame being displayed. Proceeds
 * sequentially from the current frame until it reaches the last frame, then
 * stops. Can only be used when the play/pause button has been toggled to
 * pause.
 */
void MainWindow::pskipButtonReleased()
{

}

/*
 * pbackButtonReleased
 *
 * Handling Event which changes the frame being displayed. Works
 * backwards from the current frame until it reaches the first frame,
 * then stops. Can only be used when the play/pause button has been toggled
 * to pause.
 */
void MainWindow::pbackButtonReleased()
{

}
