import java.io.PrintWriter;
import java.util.Random;

public class Picture {
	public static void main(String[] args) {
		Random rand = new Random();
		PrintWriter w = null;
		try {
			w = new PrintWriter("pic.ppm", "UTF-8");
		}
		catch(Exception e) {
			System.out.println("Exception caught:\n" + e);
		}
		
		w.println("P3");
		w.println("1920 1080 255");
		
		int foo = 0;
		for(int i = 0; i < 1920; i++) {
			for(int j = 0; j < 1080; j++) {
				//if(j%2 == 0) {
					foo = rand.nextInt(3);
				//}
				switch(foo) {
					case 0:
						w.print("255 0 0 ");
						break;
					case 1:
						w.print("0 255 0 ");
						break;
					case 2:
						w.print("0 0 255 ");
						break;
				}
			}
			w.println();
		}
		
		w.close();
	}
}
