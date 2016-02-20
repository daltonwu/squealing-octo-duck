import java.io.PrintWriter;
import java.util.Random;
import java.util.Arrays;

public class LineThing {
	static final int XRES = 500;
	static final int YRES = XRES;
	
	public static int[] change(int A, int B, int C) {
		return new int[2];
	}
	
	public static int[][][] line(int[] x0y0, int[] x1y1, int[] color, int[][][] pic) {
		if(x0y0[0] > x1y1[0]) {
			int[] temp = new int[2];
			System.arraycopy(x0y0, 0, temp, 0, 2);
			System.arraycopy(x1y1, 0, x0y0, 0, 2);
			System.arraycopy(temp, 0, x1y1, 0, 2);
		}
		
		// Ax + By + C = 0
		final int A = x1y1[1] - x0y0[1]; // A = Δy
		final int B = x0y0[0] - x1y1[0]; // B = -Δx
		//final int C = -A * x0y0[0] - B * x0y0[1]; // C = -Ax - By
		int d = 2*A + B;
		
		int x = x0y0[0];
		int y = x0y0[1];
		
		return pic;
	}
	
	public static void main(String[] args) {
		Random rand = new Random();
		
		int[][][] pic = new int[XRES][YRES][3];
		
		int[] x0y0 = {rand.nextInt(101)+50, rand.nextInt(101)+50};
		int[] x1y1 = {rand.nextInt(XRES+1), rand.nextInt(YRES+1)};
		
		int[] color = {rand.nextInt(129)+128,
		               rand.nextInt(129)+128,
		               rand.nextInt(129)+128};
		
		pic = line(x0y0, x1y1, color, pic);
		
		PrintWriter w = null;
		try {
			w = new PrintWriter("line.ppm", "UTF-8");
		}
		catch(Exception e) {
			System.out.println(e);
		}
		
		w.println("P3");
		w.println(XRES + " " + YRES + " 255");
		
		for(int j = 0; j < YRES; j++) {
			for(int i = 0; i < XRES; i++) {
				w.print(pic[i][j][0] + " "
				      + pic[i][j][1] + " "
			          + pic[i][j][2] + " ");
			}
			w.println();
		}
		
		w.close();
	}
}
