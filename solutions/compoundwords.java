import java.util.Scanner;
import java.util.ArrayList;

public class compoundwords
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        ArrayList<String> a = new ArrayList<String>();
        while (in.hasNext())
            a.add(in.next());
        
        ArrayList<String> o = new ArrayList<String>();
        
        for (int i=0; i<a.size(); i++)
            for (int j=0; j<a.size(); j++)
            {
                if (j==i) continue;
                
                String s=a.get(i)+a.get(j);
                
                boolean flag=true;
                for (int k=0; k<o.size(); k++)
                    if (o.get(k).equals(s))
                        flag=false;
                
                if (flag)
                    o.add(s);
            }
        
        java.util.Collections.sort(o);
        
        for (int i=0; i<o.size(); i++)
            System.out.println(o.get(i));
    }
}
