import java.util.*;
public class squircle {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int r = input.nextInt(), s = input.nextInt();
		boolean first = true; // True if we are placing our first (middle) column of square and false otherwise
		double rightX = s/2.0; // The x-coordinate of the rightmost side of the current column of squares
		long res = 0; // The total area we measure
		while(rightX <= r)
		{
			double y = Math.sqrt(r*r - rightX * rightX) * 2; // The height of the circle on the right side of our current column of squares
			int count = (int)(y / s); // The number of squares we can place in the current column
			res += (long)count * s * s * (first ? 1 : 2); // Place count squares, and double it if this is not the middle column due to symmetry.
			rightX += s;
			first = false;
		}
		System.out.println("Measure #" + (t+1)+": "+res);
	}
}
}

