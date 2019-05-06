/** **************************************
 * @brief 颜色类
 * @author tyw
 * @date 2018/09/25
 ****************************************/
#ifndef COLOR3_H
#define COLOR3_H
class Color3
{
public:
    int r,g,b;

    //! 构造函数
    Color3(){
        r = g = b = 0;
    }
    //! 构造函数
    Color3(int v) {
        r =  g = b = v>255?255:v;
    }
    //! 构造函数
    Color3(int r_, int g_, int b_){
        r = r_>255?255:r_;  g = g_>255?255:g_;  b = b_>255?255:b_;
    }

    //! 拷贝构造函数
    Color3(const Color3& c):
    r(c.r),g(c.g),b(c.b)   {	}


    //! 颜色加法
    Color3 operator+(const Color3& c)const{
        return Color3(r+c.r, g+c.g, b+c.b);
    }
    //! 颜色减法
    Color3 operator-(const Color3& c)const{
        return Color3(r-c.r, g-c.g, b-c.b);
    }
    //! 颜色数乘
    Color3 operator*(const double factor)const{
        return Color3(factor*r, factor*g, factor*b);
    }

    //! 颜色设置
    void set(unsigned int v){
        r = g = b = v;
    }
    void set(unsigned int r_, unsigned int g_, unsigned int b_){
        r = r_; g = g_; b = b_;
    }

    //! 转换为亮度值
    int toLightness(){
        return r * 0.299 + g * 0.587 + b * 0.114;
    }


};

typedef struct Color3 Color;

#endif


