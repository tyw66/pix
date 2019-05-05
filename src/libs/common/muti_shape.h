#ifndef MUTI_SHAPE_H
#define MUTI_SHAPE_H

#include "shape.h"

//! 圆环
class Ring
{
public:
    Circle outter, inner;             /**< 内外半径*/

    //! 构造函数
    Ring(Circle outter_, Circle inner_):outter(outter_),inner(inner_){}

    bool isContain(double x, double y){
        return outter.isContain(x,y) && !inner.isContain(x, y);
    }
};

//!
class BendShape
{
public:
    Circle up, down, big;

    //! 构造函数
    BendShape(::Circle up_, ::Circle down_, ::Circle left_):up(up_),down(down_),big(left_){}

    bool isContain(double x, double y){
        return up.isContain(x,y) && !down.isContain(x, y) && big.isContain(x, y);
    }

};

//!
class BendEye
{
public:
    Circle up, down, left, right;
    Fan mask;

    //! 构造函数
    BendEye(::Circle up_, ::Circle down_, ::Circle left_, ::Circle right_, ::Fan mask_)
        :up(up_),down(down_),left(left_),right(right_),mask(mask_){}

    bool isContain(double x, double y){
        if(up.isContain(x,y) && !down.isContain(x, y)){
            if(mask.isContain(x, y) || left.isContain(x,y) || right.isContain(x,y)){
                return true;
//
            }
        }
        return false;
    }

};

//! 胶囊
class Capsule{
public:
    Rect rect;
    Circle left,right;

    Capsule(::Rect r, ::Circle left_, ::Circle right_):rect(r),left(left_),right(right_){}

    bool isContain(double x, double y){
        return rect.isContain(x,y) || left.isContain(x, y) || right.isContain(x, y);
    }
};


#endif // MUTI_SHAPE_H
