import java.util.Scanner;
import java.util.HashMap;

public class whatdoesthefoxsay
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        
        
        int T=Integer.parseInt(in.nextLine());        
        
        for (int k=0; k<T; k++)
        {
            int index=0;
            String[] notFoxSounds= new String[10];
            HashMap<String, Integer> sounds = new HashMap<String, Integer>();
        
            
            String testCase=in.nextLine();
            Scanner testScan = new Scanner(testCase);
            
            while(testScan.hasNext())
            {   
                if (index==notFoxSounds.length)
                    notFoxSounds=java.util.Arrays.copyOf(notFoxSounds,notFoxSounds.length*2);
                
                notFoxSounds[index++]=testScan.next();
            }
            
            String animalSound=in.nextLine();
            do
            {
                sounds.put(animalSound.split(" ")[2],0);
                
                animalSound=in.nextLine();
            }
            while(!animalSound.equals("what does the fox say?"));
            
            for (int i=0; i<index; i++)
                if (!sounds.containsKey(notFoxSounds[i]))
                    System.out.print(notFoxSounds[i]+" ");
            System.out.println();
        }
    }
}
        
