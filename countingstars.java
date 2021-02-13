import java.util.Scanner;

public class countingstars
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int caseNumber=1;
        
        do
        {
            String dim=in.nextLine();
            int length=Integer.parseInt(dim.split(" ")[0]);
            int width=Integer.parseInt(dim.split(" ")[1]);
            int k=1; 
            
            char[][] map = new char[length][width];
            for (int i=0; i<length; i++)
            {
                String line=in.nextLine();
                for (int j=0; j<width; j++)
                    map[i][j]=line.charAt(j);
            }
            
            for (int i=0; i<length; i++)
            {
                for (int j=0; j<width; j++)
                    if (map[i][j]=='-')
                        markAndSpread(map,i,j,k++);
            }
            
            System.out.println("Case "+( caseNumber++ )+": "+--k);
        }while(in.hasNextLine());
    }
    
    public static void printMap (char[][] map)
    {
        for (int i=0; i<map.length; i++)
        {    for (int j=0; j<map[0].length; j++)
                System.out.print(map[i][j]);
            System.out.println();
        }
    }
    public static void markAndSpread (char[][] map, int x, int y, int k)
    {
        if (x-1>=0 && map[x-1][y]=='-')
        {
            map[x-1][y]=Integer.toString(k).charAt(0);
            markAndSpread(map, x-1, y, k);
        }
        if (x+1<map.length && map[x+1][y]=='-')
        {
            map[x+1][y]=Integer.toString(k).charAt(0);
            markAndSpread(map, x+1, y, k);
        }
        if (y-1>=0 && map[x][y-1]=='-')
        {
            map[x][y-1]=Integer.toString(k).charAt(0);
            markAndSpread(map, x, y-1, k);
        }
        if (y+1<map[0].length && map[x][y+1]=='-')
        {
            map[x][y+1]=Integer.toString(k).charAt(0);
            markAndSpread(map, x, y+1, k);
        }
    }
}
