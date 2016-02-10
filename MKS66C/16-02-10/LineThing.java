import java.io.PrintWriter;
import java.util.Random;

public class LineThing {
	public static void main(String[] args) {
		Random rand = new Random();
		PrintWriter w = null;
		try {
			w = new PrintWriter("line.ppm", "UTF-8");
		}
		catch(Exception e) {
			System.out.println("Exception caught:\n" + e);
		}
		
		w.println("P3");
		w.println("100 100 1");
		
		System.out.println(rand.nextInt();
		
		w.close();
	}
}
