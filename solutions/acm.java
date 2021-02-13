import java.util.Scanner;
import java.util.ArrayList;

public class acm
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        String line=in.nextLine();
        
        ArrayList<Problem> subs = new ArrayList<Problem>();
        
        int score=0;
        int numOfProblemSolved=0;
        
        if (!line.equals("-1"))
        {
            
            do
            {
                String name=line.split(" ")[1];
                int minutes=Integer.parseInt(line.split(" ")[0]);
                String status=line.split(" ")[2];
                
                if (status.equals("right"))
                {
                    numOfProblemSolved++;
                    score+=minutes;
                    
                    for (int i=0; i<subs.size(); i++)
                        if (subs.get(i).name.equals(name))
                            score+=20*subs.get(i).penalties;
                }
                else
                {
                    int i=0;
                    for (; i<subs.size(); i++)
                        if (subs.get(i).name.equals(name))
                        {
                            subs.get(i).penalties++;
                            break;
                        }
                    
                    if (i==subs.size())
                        subs.add(new Problem(name,1));
                }
                
                line=in.nextLine();
            }while(!line.equals("-1"));
        }
            
        System.out.println(numOfProblemSolved+" "+score);
        
    }
}

class Problem
{
    String name;
    int penalties;
    
    Problem(String name, int penalties)
    {
        this.name=name;
        this.penalties=penalties;
    }
}
