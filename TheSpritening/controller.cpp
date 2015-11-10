/****
 * controller.cpp
 *
 * The brains behind everything. The Controller is responsible for relaying
 * information between the View and the Model.
 */

#include <QDebug>
#include "controller.h"

int Controller::DEFAULT_DIMENSION = 64;

Controller::Controller(int available_length)
{
    // Do some math to lay out the cells and set up other variables.
    dimension       = DEFAULT_DIMENSION;
    cell_size       = available_length / dimension;
    side_length     = available_length - (available_length % cell_size);
    active_color    = Qt::black;
    sprite          = Sprite(dimension, Qt::gray);

    // Set the default tool.
    current_tool = Tools::Pencil;
    qDebug() << "Current tool: " << current_tool;
}

int Controller::getViewSideLength()
{
    return (cell_size * dimension);
}

void Controller::registerCanvas(Canvas* canvas)
{
    this->canvas = canvas;
}

void Controller::canvasClickedAtPosition(QPointF point)
{
    qDebug() << Q_FUNC_INFO << point;
    qDebug() << "Current tool: " << current_tool;

    switch (current_tool)
    {
        case Tools::Pencil:
            usePencilAtPoint(point);
            break;
        case Tools::Eraser:
            useEraserAtPoint(point);
            break;
        case Tools::Rotate:
            useRotateAtPoint(point);
            break;
        case Tools::Mirror:
            useMirrorAtPoint(point);
            break;
        default:
            qDebug() << "Something isn't right.";
    }
}

void Controller::usePencilAtPoint(QPointF point)
{
    qDebug() << Q_FUNC_INFO;
}

void Controller::useEraserAtPoint(QPointF point)
{
    qDebug() << Q_FUNC_INFO;
}

void Controller::useRotateAtPoint(QPointF point)
{
    qDebug() << Q_FUNC_INFO;
}

void Controller::useMirrorAtPoint(QPointF point)
{
    qDebug() << Q_FUNC_INFO;
}

QPointF Controller::getCellAddressFromPositionInView(QPointF position)
{
    int x = position.x();
    int y = position.y();
    int cell_x = (x - (x % this->cell_size)) / this->cell_size;
    int cell_y = (y - (y % this->cell_size)) / this->cell_size;
    return QPointF(cell_x, cell_y);
}

QPointF Controller::getViewPositionFromCellAddress(int x, int y)
{
    int view_x = x * this->cell_size;
    int view_y = y * this->cell_size;
    return QPointF(view_x, view_y);
}
