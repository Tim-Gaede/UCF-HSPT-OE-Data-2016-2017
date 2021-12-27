import java.util.Scanner;


public class shapes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int runs = scan.nextInt(); //scan in the number of numbers to be evaluated
		for(int i=1;i<=runs;i++){ //loop the requested number of times
			//scan in the number to be checked
			int sides = scan.nextInt();
			if(sides==3||sides==4){  //if the shape has 3 or 4 sides
				//print the success message
				System.out.println("Shape #"+i+": Johnny's favorite!");
			}else{
				//print the fail message
				System.out.println("Shape #"+i+": Johnny will not be pleased with this one.");
			}
		}

	}

}
