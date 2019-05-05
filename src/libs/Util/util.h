#ifndef UTIL_H
#define UTIL_H

#include "util_global.h"

class UTILSHARED_EXPORT Util
{
public:
    /**
     * @brief 平移坐标点
     */
    static void movePointXY(double x0, double y0, double &x1, double &y1,double xDist, double yDist);
    /**
     * @brief 当前像素点映射到坐标轴上,xy直角坐标系
     */
    static void scalePointXY(double x0, double y0, double &x1, double &y1,double xFactor, double yFactor);
    /**
     * @brief 旋转坐标点
     */
    static void rotatePointXY(double x0, double y0, double& x1, double& y1, double angle, double rxCenter, double ryCenter);


private:
    static const double PI = 3.141592;
};

#endif // UTIL_H
