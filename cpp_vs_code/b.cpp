// 计算两点距离

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        double dis = sqrt( pow(x1 - x2, 2) + pow(y1 - y2, 2) );
        cout << fixed << setprecision(2) << dis << endl;
        // 或者
        //printf("%.2lf\n", dis);
        /*
        * sqrt(num)) pow(num1, num2)
        * 这两个东西称之为函数，sqrt计算(num)^0.5，即开根
        * pow，计算num1的num2次方
        * 使用这两个函数需要加一个 math.h的头文件
        * 
        * fixed 和 setprecision()现阶段不用知道啥意思，这两个连起来用可以让cout只显示小数点后2两位
        * 使用需要加一个 iomanip 的头文件
        */
    }
}