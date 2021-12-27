#include <stdio.h>
#include <math.h>
int main(){
	int testCases, i;
	scanf("%d", &testCases);
	for(i = 1;i<=testCases;i++){
		int radius, sideLength;
		scanf("%d", &radius);
		scanf("%d", &sideLength);
		
		//We know the forumla for a circle is x^2 + y^2 = r^2.
		//We can use the to solve for the y value at a certain x value in order
		//to tell how many square we will be able to fit at that x position
		
		//I assume the the center of the circle is at (0, 0)
		
		//First calculate the center column specially
		double firstX = -sideLength/2.0;
		int ans = 0;
		if(firstX >= -radius){
			//The two y values are yPos and -yPos
			double yPos = sqrt(radius*radius - firstX*firstX);
			
			//The space between the two y values at that x value is the difference between them 
			double h = yPos - (-yPos);
			
			//The number of squares that fit is 
			int numSquares = (int)(h/sideLength);
			
			//We add the area of a circle time the number of squares that fit at this position
			ans += sideLength*sideLength*numSquares;
			
			//Now we keep looping and adding new columns of squares
			//next to the previous ones
			double curX = firstX-sideLength;
			while(curX >= -radius){
				//The two y values are yPos and -yPos
				double yPos = sqrt(radius*radius - curX*curX);
				
				//The space between the two y values at that x value is the difference between them 
				double h = yPos - (-yPos);
			
				//The number of squares that fit is 
				int numSquares = (int)(h/sideLength);
			
				//We add the area of a circle time the number of squares
				//that fit at this position. We get an extra times 2 now because
				//we are adding to columns at once now.
				ans += sideLength*sideLength*numSquares*2;
				
				//The next we care about is shifted over by sideLength
				curX-=sideLength;
			}
			
		}
		else{
			//No squares are going to fit at all in this case
		}
		printf("Measure #%d: %d\n", i, ans);
	}
	
	return 0;
}
