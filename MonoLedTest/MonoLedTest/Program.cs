using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Drawing;

namespace MonoLedTest
{
	public static class Program
	{
		static void Main(string[] args)
		{
			int w = 8;
			int h = 8;

			int brightness = 0;
			bool goingUp = true;

			while (true)
			{

				int pixelValue = Color.FromArgb(brightness, brightness, brightness).ToPixel();
				int[] pixels = Enumerable.Repeat<int>(pixelValue, w * h).ToArray();
				Ws2811.setleds(pixels, w * h);

				if (brightness == 0) goingUp = true;
				if (brightness == 0xFF) goingUp = false;

				if (goingUp) brightness++;
				else brightness--;
				Thread.Sleep(2);
			}
		}
	}

	public static class Ws2811
	{
		public static int ToPixel(this Color color)
		{
			return color.ToArgb() & 0x00FFFFFF;
		}

		[DllImport("ws2811")]
		public static extern int setleds(int[] pixel_data, int pixel_count);
	}
}
