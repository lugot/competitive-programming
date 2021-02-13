import java.util.Scanner;
import java.util.HashMap;

public class babelfish
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
         HashMap<String, String> dictionary = new HashMap<String, String>();
        
        int index=0;
        String dictEntry=in.nextLine();
        do
        {
            Scanner s = new Scanner(dictEntry);
            String eng=s.next();
            String foreign=s.next();
            
            dictionary.put(foreign,eng);
            
            dictEntry=in.nextLine();
        }while(!dictEntry.isEmpty());
        
        
        while(in.hasNextLine())
        {
            String word=in.nextLine();
            
            if (!dictionary.containsKey(word))
                System.out.println("eh");
            else 
                System.out.println(dictionary.get(word));
        }
    }
}
