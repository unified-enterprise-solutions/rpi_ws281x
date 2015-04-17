using RGiesecke.DllExport;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ws2811_Fake
{
    public class Ws2811
    {
		[DllExport()]
		public static extern int setleds(int[] pixels, int pixel_count)
		{

			return 0;
		}
    }
}
