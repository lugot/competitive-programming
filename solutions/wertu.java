import java.util.Scanner;
import java.util.HashMap;

public class wertyu
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        in.useDelimiter("");
        
        HashMap<String,String> cipher = new HashMap<String,String>();
        
        String s="`1234567890-=";
        for (int i=0; i<s.length()-1; i++)
            cipher.put(s.substring(i+1,i+2),s.substring(i,i+1));
        s="QWERTYUIOP[]\\";
        for (int i=0; i<s.length()-1; i++)
            cipher.put(s.substring(i+1,i+2),s.substring(i,i+1));
        s="ASDFGHJKL;'";
        for (int i=0; i<s.length()-1; i++)
            cipher.put(s.substring(i+1,i+2),s.substring(i,i+1));
        s="ZXCVBNM,./";
        for (int i=0; i<s.length()-1; i++)
            cipher.put(s.substring(i+1,i+2),s.substring(i,i+1));
        
        while(in.hasNext())
        {
            String digit=in.next();
            if (cipher.containsKey(digit))
                System.out.print(cipher.get(digit));
            else
                System.out.print(digit);
        }
    }
}
