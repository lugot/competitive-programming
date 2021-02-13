import java.util.Scanner;

public class aaah
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        
        String jon=in.nextLine();
        String doc=in.nextLine();
        
        System.out.println(jon.length()>=doc.length() ? "go" : "no");
    }
}
