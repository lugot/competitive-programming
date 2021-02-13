import java.util.Scanner;

public class autori
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        String authors=in.nextLine();
        in=new Scanner(authors);
        in.useDelimiter("-");
        
        String s="";
        while (in.hasNext())
            s+=in.next().charAt(0);
            
        print(s);
    }
    
    public static void print(String s){
        System.out.println(s);
    }
}
