/****
 * sprite.cpp
 *
 * Implementation for the Sprite class. A Sprite holds a stack of
 * Frames that produce an animation effect.
 */

#include "sprite.h"

/****
 * Static Member Attributes
 */
int Sprite::DEFAULT_LENGTH = 64;
QColor Sprite::DEFAULT_COLOR = QColor(0,0,0,0);

/****
 * Constructors
 */

Sprite::Sprite()
{
    Frame new_frame(DEFAULT_LENGTH, DEFAULT_COLOR);
    this->current_index = 0;
    this->dimension     = DEFAULT_LENGTH;
    this->bg_color      = DEFAULT_COLOR;
}

Sprite::Sprite(int dimension)
{
    Frame new_frame(dimension, DEFAULT_COLOR);
    this->current_index = 0;
    this->dimension     = dimension;
    this->bg_color      = DEFAULT_COLOR;
}

Sprite::Sprite(int dimension, QColor color)
{
    Frame new_frame(dimension, color);
    this->current_index = 0;
    this->dimension     = dimension;
    this->bg_color      = color;
}

Sprite::Sprite(std::vector<Frame> frameStack, int dimension)
{
    frames = frameStack;
    this->current_index = 0;
    this->dimension     = dimension;
    this->bg_color      = DEFAULT_COLOR;
}

Sprite::Sprite(const Sprite& other)
{
    frames          = other.frames;
    current_index   = other.current_index;
    dimension       = other.dimension;
    bg_color        = DEFAULT_COLOR;
}

/****
 * Public Methods
 */

Frame Sprite::getFrame(unsigned long index)
{
    if(index <= frames.size() - 1)
    {
        this->current_index = index;
        return frames[index];
    }

    return NULL;
}

std::vector<Frame> Sprite::getAllFrames()
{
    return frames;
}

int Sprite::getFrameCount()
{
    return frames.size();
}

Frame Sprite::getNewFrame()
{
    Frame new_frame(this->dimension, this->bg_color);
    frames.push_back(new_frame);
    this->current_index = frames.size() - 1;
    return frames[this->current_index];
}

/*
 * getNewFrameAfterIndex
 *
 * We'll need to increase index by 1 because the insert
 * method inserts before the specified index.
 */
Frame Sprite::getNewFrameAfterIndex(unsigned long index)
{
    if(index <= frames.size() - 1)
    {
        Frame new_frame(this->dimension, this->bg_color);
        //index++;
        frames.insert(getIteratorAtPosition(index), new_frame);
        this->current_index = index;
        return frames[this->current_index];
    }

    return NULL;
}


Frame Sprite::getNewCopyFrame()
{
    Frame new_frame(frames[frames.size() - 1]);
    frames.push_back(new_frame);
    this->current_index = frames.size() - 1;
    return frames[this->current_index];
}


/*
 * getNewCopyFrameAfterIndex
 *
 * Creates a copy of the Frame at index. Inserts the Frame
 * after index and returns it. Index gets increased by 1 because
 * the insert method inserts before the index provided.
 */
Frame Sprite::getNewCopyFrameAfterIndex(unsigned long index)
{
    if(index <= frames.size() - 1)
    {
        Frame new_frame(frames[index - 1]);
        //index++;
        frames.insert(getIteratorAtPosition(index), new_frame);
        this->current_index = index;
        return frames[this->current_index];
    }

    return NULL;
}

/*
 * clearFrameAtIndex
 *
 * Erases all of the data store in a given frame. This is useful for
 * whenever we clear a drawing.
 */
void Sprite::clearFrameAtIndex(unsigned long index)
{
    frames[index].clear();
}

/*
 * removeFrameAtIndex
 *
 * We'll need to check to make sure the index is in bounds.
 * Next, we'll need to reset the current index if we just deleted
 * the element at that position.
 */
void Sprite::removeFrameAtIndex(unsigned long index)
{
    if(index <= frames.size() - 1)
    {
        frames.erase(getIteratorAtPosition(index));
        if(this->current_index == index)
        {
            this->current_index = 0;
        }
    }
}

void Sprite::setCellAtPositionToColor(int x, int y, QColor color)
{
    frames[this->current_index].setCellAtPositionToColor(x, y, color);
}

QColor Sprite::getBGColor()
{
    return bg_color;
}

void Sprite::setBGColor(QColor color)
{
    bg_color = color;
}

int Sprite::getDimension()
{
    return dimension;
}

/****
 * Private Methods
 */

std::vector<Frame>::iterator Sprite::getIteratorAtPosition(unsigned long index)
{
    std::vector<Frame>::iterator new_iterator = frames.begin() + index;
    return new_iterator;
}


