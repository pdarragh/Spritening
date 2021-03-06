/*
 * cell.h
 *
 * The header for the model of the cell. Cells are what become the pixels in a
 * sprite animation. Cells have position and color.
 */

#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QPoint>

class Cell 
{
public:
    // Constructors.
    Cell();
    Cell(QPoint position);
    Cell(QPoint position, QColor color);
    Cell(const Cell& other);
    // Methods.
    const QPoint getPosition();
    const QColor getColor();
    void setColor(QColor color);
private:
    // Attributes.
    QPoint position;
    QColor color;
};

#endif
