using System;
namespace EquatNameSpace
{
    class Equation
    {
        public static double CountFunct(double z)
        {
            double x;
            if(z<1)
            {
                x = z*z*z + 0.2;
                Console.WriteLine("z<1. x = z^3 + 0.2");
            }
            else
            {
                x = z+ Math.Log(z);
                Console.WriteLine("z>=1. x = z + ln(x)");
            }
            double y;
            double xInSquare = x*x;
            double xInCube = xInSquare*x;
            y = Math.Cos(x*x)*Math.Cos(xInSquare)*Math.Cos(xInSquare) + Math.Sin(xInCube)*Math.Sin(xInCube);
            return y;
        }
    }
}