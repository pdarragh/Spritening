#include "fullpreview.h"
#include "ui_fullpreview.h"

FullPreview::FullPreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FullPreview)
{
    ui->setupUi(this);
    //ui->exit_button->setIconSize(QSize(20, 20));

    connect(ui->exit_button, SIGNAL(released()), this, SLOT(on_exit_button_clicked()));
}

FullPreview::~FullPreview()
{
    delete ui;
}

void FullPreview::on_exit_button_clicked()
{
    this->close();
}
