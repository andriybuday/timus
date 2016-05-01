//1550_Sb
using System;
using System.Threading;
using System.Globalization;
namespace I_task
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            double KOR  = 1.4142135623730950;
            double PI  = 3.14159265358979323;
	        double H, W, X, Y, R;
            string[] tokens = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            H = double.Parse(tokens[0]);
            W = double.Parse(tokens[1]);
            string[] XYtokens = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            X = double.Parse(XYtokens[0]);
            Y = double.Parse(XYtokens[1]);
            string[] Rtokens = Console.ReadLine().Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
            R = double.Parse(Rtokens[0]);

	        double x1 = (KOR/2.0)*(X-Y);
	        double y1 = (KOR/2.0)*(X+Y);

    	    double ans = (1.0/3.0)*H*W*W - PI*R*R*(H - (KOR/W)*H*(Math.Abs(x1)+Math.Abs(y1)));

            Console.WriteLine(ans);
        }
    }
}
