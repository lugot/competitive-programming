import java.util.Scanner;

public class prerequisites
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        String test=in.nextLine();
        do
        {
            int k=Integer.parseInt(test.split(" ")[0]);
            int m=Integer.parseInt(test.split(" ")[1]);
            
            String[] strCourses=in.nextLine().split(" ");
            int[] courses=new int[strCourses.length];
            for (int i=0; i<strCourses.length; i++)
                courses[i]=Integer.parseInt(strCourses[i]);
            
            String toPrint="yes";
            
            for (int i=0; i<m; i++)
            {
                String[] strCatCourses=in.nextLine().split(" ");
                
                int c=Integer.parseInt(strCatCourses[0]);
                int r=Integer.parseInt(strCatCourses[1]);
                
                int[] catCourses=new int[strCatCourses.length-2];
                for (int u=0; u<catCourses.length; u++)
                    catCourses[u]=Integer.parseInt(strCatCourses[u+2]);
                 
                int counter=0;
                for (int j=0; j<c; j++)
                    for (int z=0; z<k; z++)
                        if (catCourses[j]==courses[z])
                            counter++;
                if (counter<r) toPrint="no";            
                
            }
            
            System.out.println(toPrint);
            
            test=in.nextLine();
        }while(!test.equals("0"));
        
    }
}
