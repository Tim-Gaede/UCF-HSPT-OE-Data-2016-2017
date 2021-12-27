
import java.util.*;

public class hyenas
{
        public static void main(String[] args)
        {
                Scanner in = new Scanner(System.in);
                
                // Amount of test cases to process -> N
                int N = in.nextInt();
                
                for(int n = 1; n <= N; n++)
                {
                        // Amount of rows (-> R) and columns (-> C)
                        int R = in.nextInt(), C = in.nextInt();

                        // Variable used to facilitate counting hyenas in the grass
                        String grass = "";
                        
                        // Hyena counter variable
                        int hyenas = 0;

                        // For all rows...
                        for(int r = 0; r < R; r++)
                        {
                                // Input a word into the "grass" string,
                                // guaranteed to be an entire line since there are no spaces
                                // allowed in sample input
                                grass = in.next();

                                // For all columns in that row...
                                // (functionally, for all spaces in this string...)
                                for(int c = 0; c < C; c++)
                                {
                                        // If you see a hyena in this spot, increment the "hyenas" variable once
                                        if(grass.charAt(c) == 'H')
                                        {
                                                hyenas++;
                                        }
                                }
                        }
                        
                        // Output the answer
                        System.out.println("Location #" + n + ": " + hyenas);
                }
        }
}
