#pragma once
#include <iostream>

class Position {
  private:
    size_t xCoord_;
    size_t yCoord_;
  public:
    Position();
    Position(size_t xCoord, size_t yCoord);
    size_t getXCoord();
    size_t getYCoord();
    friend bool operator< (Position const& pos1, Position const& pos2) {
      return ((pos1.xCoord_ < pos2.xCoord_) || ((pos1.xCoord_ == pos2.xCoord_) && (pos1.yCoord_ < pos2.yCoord_)));
    }

    friend bool operator== (Position const& pos1, Position const& pos2) {
      return ((pos1.xCoord_ == pos2.xCoord_) && (pos1.yCoord_ == pos2.yCoord_));
    }

    friend bool operator!= (Position const& pos1, Position const& pos2) {
      return !(pos1 == pos2);
    }
};