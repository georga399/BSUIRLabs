#include <iostream>
#include <cmath>
#include <iomanip>
int main(){
    long double x1, x2, x3, y1, y2, y3; //координаты вершин
    long double a, b, c; //длины сторон треугольника
    long double p; //полупериметр треугольника
    long double ha, hb, hc; //проведённные к сторонам высоты
    long double ma, mb, mc; //проведённные к сторонам медианы
    long double ba, bb, bc; //проведённные к сторонам биссектрисы
    long double A, B, C;// градусные меры углов A (противоположен стороне a), B (противоположен стороне b), C (противоположен стороне c)
    long double radA, radB, radC;// радианные меры углов
    const long double PI = acosl(-1);
    long double r, R; // радиусы вписанной и описанной окружностей соответственно
    long double Sr, SR; //площади вписанной и описанной окружностей соответственно
    long double lr, lR; // длины вписанной и описанной окружностей соответственно 
    long double P, S; //P - периметр треугольника, S - площадь треугольника 
    setlocale(LC_ALL, "Russian");
    std::cout<<"Введите x1: ";
    std::cin>>x1;
    std::cout<<"Введите y1: ";
    std::cin>>y1;
    std::cout<<"Введите x2: ";
    std::cin>>x2;
    std::cout<<"Введите y2: ";
    std::cin>>y2;
    std::cout<<"Введите x3: ";
    std::cin>>x3;
    std::cout<<"Введите y3: ";
    std::cin>>y3;
    std::cout<<std::endl;
    //////////////////////////
    std::cout<<std::setprecision(3)<<"Координаты вершин треугольника : \n";
    std::cout<<'('<<x1<<" , "<<y1<<')'<<std::endl;
    std::cout<<'('<<x2<<" , "<<y2<<')'<<std::endl;
    std::cout<<'('<<x3<<" , "<<y3<<')'<<std::endl;

    //1
    a = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    b = sqrt(pow(x2-x3, 2) + pow(y2-y3, 2));
    c = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
    // Тут должна быть проверка на существование такого треугольника
    if (!(a<(b+c)) || !(b<(a+c)) || !(c<a+b) ){
        std::cout<<"Треугольник с такими данными не существует";
        return 0;
    }
    std::cout<<"Длины сторон треугольника: \n";
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;
    std::cout<<"c = "<<c<<std::endl;

    //2
    p=(a+b+c)/2;
    ha = 2*sqrt(p*(p-a)*(p-b)*(p-c))/a;
    hb = 2*sqrt(p*(p-a)*(p-b)*(p-c))/b;
    hc = 2*sqrt(p*(p-a)*(p-b)*(p-c))/c;
    
    std::cout<<"Высота, проведённая к стороне a, равна "<<ha<<std::endl;
    std::cout<<"Высота, проведённая к стороне b, равна "<<hb<<std::endl;
    std::cout<<"Высота, проведённая к стороне c, равна "<<hc<<std::endl;

    //3
    ma = sqrt(2*(b*b + c*c ) - a*a)/2;
    mb = sqrt(2*(a*a + c*c ) - b*b)/2;
    mc = sqrt(2*(b*b + a*a ) - c*c)/2;
    std::cout<<"Медиана, проведённая к стороне a, равна "<<ma<<std::endl;
    std::cout<<"Медиана, проведённая к стороне b, равна "<<mb<<std::endl;
    std::cout<<"Медиана, проведённая к стороне c, равна "<<mc<<std::endl;

    //4
    ba = 2*sqrt(b*c*p*(p-a))/(b+c);
    bb = 2*sqrt(a*c*p*(p-b))/(a+c);
    bc = 2*sqrt(b*a*p*(p-c))/(b+a);
    std::cout<<"Биссектриса, проведённая к стороне a, равна "<<ba<<std::endl;
    std::cout<<"Биссектриса, проведённая к стороне b, равна "<<bb<<std::endl;
    std::cout<<"Биссектриса, проведённая к стороне c, равна "<<bc<<std::endl;

    //5 
    radA = acos((b*b + c*c - a*a)/(2*b*c));
    radB = acos((a*a + c*c - b*b)/(2*a*c));
    radC = acos((b*b + a*a - c*c)/(2*b*a));
    A = radA*180/PI;
    B = radB*180/PI;
    C = radC*180/PI;
    std::cout<<"Градусная мера угла A равна "<<A<<"°"<<std::endl;
    std::cout<<"Радианная мера угла A равна "<<radA<<std::endl;
    std::cout<<"Градусная мера угла B равна "<<B<<"°"<<std::endl;
    std::cout<<"Радианная мера угла B равна "<<radB<<std::endl;
    std::cout<<"Градусная мера угла C равна "<<C<<"°"<<std::endl;
    std::cout<<"Радианная мера угла C равна "<<radC<<std::endl;

    //6
    r = sqrt((p-a)*(p-b)*(p-c)/p);
    R = a/(2*sin(radA));
    std::cout<<"Радиус вписанной окружности равен "<<r<<std::endl;
    std::cout<<"Радиус описанной окружности равен "<<R<<std::endl;

    //7
    Sr = r*r*PI;
    SR = R*R*PI;
    lr = 2*r*PI;
    lR = 2*R*PI;
    std::cout<<"Площадь вписанной окружности равен "<<Sr<<std::endl;
    std::cout<<"Длина вписанной окружности равен "<<lr<<std::endl;
    std::cout<<"Площадь описанной окружности равен "<<SR<<std::endl;
    std::cout<<"Длина описанной окружности равен "<<lR<<std::endl;
    
    //8
    P = p*2;
    //Первый способ вычислений S
    S = sqrt(p*(p-a)*(p-b)*(p-c));
    //Второй способ вычислений S
    //S = ha*a/2
    //Третий способ вычислений S
    //S = p*r
    std::cout<<"Периметр треугольника равен "<<P<<std::endl;
    std::cout<<"Площадь треугольника равна "<<S<<std::endl;
    return 0;

}